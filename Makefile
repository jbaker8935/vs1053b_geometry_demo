# Makefile for arcade
# Build artifacts go into `build/`

ROOT := $(CURDIR)
BUILD_DIR := build
NAME = k2_geom_demo

# Tool locations (use the user's tool locations by default)
CC := /opt/llvm-mos/bin/mos-f256-clang
LD := /opt/llvm-mos/bin/ld.lld
MOS_LIB_DIR ?= /opt/llvm-mos/mos-platform/f256/lib
OVERLAY := /opt/llvm-mos/bin/overlay
PGZ_THUNK := /opt/llvm-mos/bin/pgz-thunk.py

# Common tool helpers (override if needed)
NM ?= llvm-nm
OBJDUMP ?= llvm-objdump
OBJCOPY ?= llvm-objcopy
PYTHON ?= python3

LDSCRIPT ?= f256.ld
CFLAGS ?= -I$(ROOT) -I$(ROOT)/src -I$(ROOT)/include -Os -Wall -D__llvm_mos__

LDFLAGS ?=

# Collect sources from src/ only. Explicitly exclude libfixmath and other dirs.
SRCS_C := $(wildcard src/*.c)
SRCS_S := $(wildcard src/*.s)

SRC_ORDERED := $(wildcard src/*.c src/*.s)
OBJS := $(patsubst src/%.c,build/%.o,$(filter %.c,$(SRC_ORDERED))) \
	$(patsubst src/%.s,build/%.o,$(filter %.s,$(SRC_ORDERED)))

.PHONY: all clean pgz dist run info dirs overlay
all: pgz

# Ensure build dir exists
dirs:
	@mkdir -p $(BUILD_DIR)

COMPILE = $(CC) -c $(CFLAGS) -o $@ $<

# Host C compiler for build-time tools (used to compile the offsets generator)
CC_HOST ?= cc

# Build an offsets generator binary using the host compiler
tools/gen_offsets: tools/generate_offsets.c | dirs
	$(CC_HOST) -Iinclude -DGENERATE_OFFSETS $< -o $@

# Target-derived struct offsets (authoritative): compile with llvm-mos and extract `.equ` lines.
build/struct_offsets_emit.s: tools/struct_offsets_emit.c include/draw_line.h include/3d_object.h include/3d_math.h | dirs
	$(CC) -S $(CFLAGS) -o $@ $<

# Generated assembler offsets (single shared file)
build/struct_offsets.inc: build/struct_offsets_emit.s | dirs
	$(PYTHON) tools/extract_struct_offsets_equ.py $< > $@

# Compile both C and assembly with the same command (mos-f256-clang)
$(BUILD_DIR)/%.o: src/%.c | dirs
	$(COMPILE)

$(BUILD_DIR)/%.o: src/%.s build/struct_offsets.inc | dirs
	$(COMPILE)

# Link (produces an output binary named '$(NAME)')
$(BUILD_DIR)/$(NAME): $(OBJS) | dirs
	@mkdir -p $(BUILD_DIR)
	(cd $(BUILD_DIR) && \
	$(CC) \
		-D__llvm_mos__ \
		-T ../$(LDSCRIPT) \
		-Wl,-Map=$(NAME).map \
		-o $(NAME) \
		-I.. \
		-Os -Wall -lm \
		$(notdir $(OBJS)) \
		$(LDFLAGS))

# Prepare overlayed build directory from project sources.
overlay: dirs
	@if command -v $(OVERLAY) >/dev/null 2>&1; then \
		$(OVERLAY) 5 $(BUILD_DIR) $(ROOT)/src || { echo "overlay failed" >&2; exit 1; }; \
	else \
		echo "overlay not found; skipping overlay step"; \
	fi
	@# Always ensure assets required by `.incbin` are present in build/assets.
	@mkdir -p $(BUILD_DIR)/assets
	@cp -a $(ROOT)/src/assets/* $(BUILD_DIR)/assets/ 2>/dev/null || true
	@cp -a $(ROOT)/assets/* $(BUILD_DIR)/assets/ 2>/dev/null || true

# Ensure overlay runs before linking so linker sees overlayed files
$(BUILD_DIR)/$(NAME): overlay $(OBJS) | dirs


# Post-link: symbol and listing, then overlay/pgz creation
.SILENT: $(BUILD_DIR)/$(NAME).pgz
$(BUILD_DIR)/$(NAME).pgz: $(BUILD_DIR)/$(NAME)
	@# If linker produced an ELF variant, use it for symbol/listing; otherwise skip.
	@if [ -f $(BUILD_DIR)/$(NAME).elf ]; then \
		ELF_FILE=$(BUILD_DIR)/$(NAME).elf; \
	elif [ -f $(BUILD_DIR)/$(NAME).elf.elf ]; then \
		ELF_FILE=$(BUILD_DIR)/$(NAME).elf.elf; \
	else \
		ELF_FILE=; \
	fi; \
	if [ -n "$$ELF_FILE" ]; then \
		$(NM) "$$ELF_FILE" > $(BUILD_DIR)/$(NAME).sym || true; \
		$(OBJDUMP) --syms -d --print-imm-hex "$$ELF_FILE" > $(BUILD_DIR)/$(NAME).lst || true; \
	fi

	# If linker produced a raw binary named '$(NAME)', promote it to .pgz as f256build.sh did
	if [ -f $(BUILD_DIR)/$(NAME) ]; then \
		mv $(BUILD_DIR)/$(NAME) $(BUILD_DIR)/$(NAME).pgz; \
	fi

	# If a .pgz was created by overlay or the linker, run pgz-thunk to inspect it
	if [ -f $(BUILD_DIR)/$(NAME).pgz ]; then \
		SCRIPT=""; \
		if [ -f "$(PGZ_THUNK)" ]; then \
			SCRIPT="$(PGZ_THUNK)"; \
		elif command -v $(PGZ_THUNK) >/dev/null 2>&1; then \
			SCRIPT="$$(command -v $(PGZ_THUNK))"; \
		fi; \
		if [ -n "$$SCRIPT" ]; then \
			$(PYTHON) "$$SCRIPT" $(BUILD_DIR)/$(NAME).pgz || echo "pgz-thunk did not process $(BUILD_DIR)/$(NAME).pgz"; \
		fi; \
	fi

	# Ensure a PGZ artifact was produced by overlay/pgz-thunk.
	if [ ! -f $(BUILD_DIR)/$(NAME).pgz ]; then \
		echo "ERROR: pgz-thunk did not produce $(BUILD_DIR)/$(NAME).pgz" >&2; \
		exit 1; \
	fi

	cp $(BUILD_DIR)/$(NAME).pgz bin/

pgz: $(BUILD_DIR)/$(NAME).pgz

dist: pgz
	@echo "dist produced: bin/$(NAME).pgz"

run: pgz
	@echo "run target is a no-op by default. Override to flash or emulate."

info:
	@echo "ROOT = $(ROOT)"
	@echo "BUILD_DIR = $(BUILD_DIR)"
	@echo "NAME = $(NAME)"
	@echo "CC = $(CC)"
	@echo "LD = $(LD)"
	@echo "OVERLAY = $(OVERLAY)"
	@echo "PGZ_THUNK = $(PGZ_THUNK)"
	@echo "LDSCRIPT = $(LDSCRIPT)"
	@echo "CFLAGS = $(CFLAGS)"
	@echo "LDFLAGS = $(LDFLAGS)"
	@echo "SRCS_C = $(SRCS_C)"
	@echo "SRCS_S = $(SRCS_S)"

clean:
	# Remove all files inside the build directory and the generated pgz in bin.
	# Use patterns that avoid removing '.' or '..'
	rm -rf $(BUILD_DIR)/* $(BUILD_DIR)/.[!.]* $(BUILD_DIR)/..?* || true
	rm -f bin/$(NAME).pgz || true

