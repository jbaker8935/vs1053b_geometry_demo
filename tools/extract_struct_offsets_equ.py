#!/usr/bin/env python3

import re
import sys


def main() -> int:
    if len(sys.argv) != 2:
        print(f"usage: {sys.argv[0]} <mos -S output file>", file=sys.stderr)
        return 2

    in_path = sys.argv[1]

    # mos-f256-clang `-S` emits LLVM IR. Inline-asm lines look like:
    #   tail call void asm sideeffect ".equ NAME, ${0:c}", "i"(i16 123)
    pat = re.compile(r'"\.equ\s+([^,]+),\s+\$\{0:c\}".*\(i\d+\s+(\d+)\)')

    items: dict[str, int] = {}

    with open(in_path, "r", encoding="utf-8", errors="ignore") as f:
        for line in f:
            m = pat.search(line)
            if m:
                items[m.group(1)] = int(m.group(2))

    for name in sorted(items.keys()):
        print(f".equ {name}, {items[name]}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
