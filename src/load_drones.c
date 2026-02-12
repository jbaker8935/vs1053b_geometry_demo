#include "f256lib.h"
#include "../include/drone_show.h"
EMBED(drone_data,"assets/drone_anim.bin",0x20000lu);

static uint16_t frame = 0;
static uint16_t frame_count = 0;
static uint32_t data_bytes = 0;

static inline uint16_t drone_frame_size_bytes(void) {
    return (uint16_t)(DRONE_COUNT * (2u + 2u + 2u + 1u + 1u + 1u));
}

// likely unnecessary word peek to handle case for last byte in 8k boundry.
static inline uint16_t far_peekw_safe(uint32_t address) {
    if ((address & 0x1FFFu) == 0x1FFFu) {
        uint8_t lo = (uint8_t)FAR_PEEK(address);
        uint8_t hi = (uint8_t)FAR_PEEK(address + 1u);
        return (uint16_t)lo | ((uint16_t)hi << 8);
    }
    return FAR_PEEKW(address);
}

static inline int16_t far_peek_i16_safe(uint32_t address) {
    return (int16_t)far_peekw_safe(address);
}

static void ensure_frame_count_initialized(void) {
    if (frame_count != 0) return;
    frame_count = FRAME_COUNT;
}

DronePose frame_drones[DRONE_COUNT];

void loadNextDroneFrame() {
    ensure_frame_count_initialized();
    uint16_t frame_size = drone_frame_size_bytes();


    // Defensive: never read beyond the embedded data, even if constants mismatch.
    if (frame_count == 0) {
        frame_count = 1;

    }
    if (frame >= frame_count) {
        frame = 0;
    }

    // Compute the frame's base offset from the frame index (prevents drift / wrap bugs).
    uint32_t base = (uint32_t)frame * (uint32_t)frame_size;
    if (data_bytes != 0 && (base + (uint32_t)frame_size) > data_bytes) {
        frame = 0;
        base = 0;
    }

    for (uint16_t i = 0; i < DRONE_COUNT; i++) {
        uint32_t addr = 0x20000lu + base + (uint32_t)i * 9u;

        frame_drones[i].x = far_peek_i16_safe(addr + 0u);
        frame_drones[i].y = far_peek_i16_safe(addr + 2u);
        frame_drones[i].z = far_peek_i16_safe(addr + 4u);
        frame_drones[i].yaw = (uint8_t)FAR_PEEK(addr + 6u);
        frame_drones[i].pitch = (uint8_t)FAR_PEEK(addr + 7u);
        frame_drones[i].roll = (uint8_t)FAR_PEEK(addr + 8u);
    }

    frame++;
    if (frame >= frame_count) {
        frame = 0;
    }
}
void resetDroneAnimation() {
    frame = 0;
}
