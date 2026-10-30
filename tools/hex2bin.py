#!/usr/bin/env python3
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
BUILD = ROOT / "build"


def read_ihx(path):
    mem = {}
    for line in Path(path).read_text().splitlines():
        line = line.strip()
        if not line.startswith(":"):
            continue
        b = bytes.fromhex(line[1:])
        n = b[0]
        addr = (b[1] << 8) | b[2]
        if b[3] != 0:
            continue
        for i, v in enumerate(b[4:4 + n]):
            mem[addr + i] = v
    return mem


def main():
    image = bytearray(b"\xff" * 0x20000)
    main64 = read_ihx(BUILD / "main64.ihx")
    bank1 = read_ihx(BUILD / "bank1.ihx")
    bank2 = read_ihx(BUILD / "bank2.ihx")
    for a, v in main64.items():
        if a < 0x10000:
            image[a] = v
    for a, v in bank1.items():
        off = 0x10000 + (a - 0x8000)
        if 0x10000 <= off < 0x18000:
            image[off] = v
    for a, v in bank2.items():
        off = 0x18000 + (a - 0x8000)
        if 0x18000 <= off < 0x20000:
            image[off] = v
    (BUILD / "rebuilt_128k.bin").write_bytes(bytes(image))

    orig = (ROOT / "firmware" / "eFlashBK.bin").read_bytes()
    mism = [i for i in range(min(len(image), len(orig))) if image[i] != orig[i]]
    print(f"rebuilt {len(image)} bytes, mismatches {len(mism)}")
    for i in mism[:10]:
        print(f"0x{i:05X} want {orig[i]:02X} got {image[i]:02X}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
