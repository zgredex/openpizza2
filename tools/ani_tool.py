#!/usr/bin/env python3
"""Reference decoder for Pizza Connection 2 `.ani` animation frames.

This mirrors the Rust `crates/assets/src/ani.rs` decoder. It is intentionally
small and covers the opaque 8bpp run streams used by the isometric tree-sway
animations (`b_allee_*`).
"""

from __future__ import annotations

import argparse
import struct
from pathlib import Path

HEADER_SIZE = 0x30
RECORD_SIZE = 0x98
PALETTE_SIZE = 0x300


def decode_ani(data: bytes):
    if len(data) < HEADER_SIZE:
        raise ValueError("file shorter than the 0x30-byte header")
    record_count, frame_count, _, magic = struct.unpack_from("<IIII", data, 0)
    if not 0 < frame_count <= 500:
        raise ValueError(f"invalid frame count {frame_count}")
    flags, bpp = data[0x14], data[0x15]
    if bpp != 8 or flags & 0x10:
        raise ValueError(f"unsupported animation flags={flags:#x} bpp={bpp}")
    data_offset = HEADER_SIZE + record_count * RECORD_SIZE
    if data_offset + 4 > len(data):
        raise ValueError("frame block size past EOF")
    stored_size = struct.unpack_from("<I", data, data_offset)[0]
    block_size = stored_size - 4
    block_start = data_offset + 4
    block = data[block_start : block_start + block_size]
    table = 8 * frame_count
    size_bytes = 2 if magic & 0xFFFF < 2 else 4
    if table + size_bytes * frame_count + PALETTE_SIZE > len(block):
        raise ValueError("frame table past EOF")
    widths = struct.unpack_from("<" + "H" * frame_count, block, 0)
    heights = struct.unpack_from("<" + "H" * frame_count, block, 2 * frame_count)
    cursor = table
    sizes = []
    for _ in range(frame_count):
        if size_bytes == 4:
            sizes.append(struct.unpack_from("<I", block, cursor)[0])
        else:
            sizes.append(struct.unpack_from("<H", block, cursor)[0])
        cursor += size_bytes
    palette = block[-PALETTE_SIZE:]
    frames = []
    for width, height, size in zip(widths, heights, sizes):
        body = block[cursor : cursor + size]
        cursor += size
        if width == 0 or height == 0:
            frames.append((width, height, b""))
            continue
        pixels = bytearray(width * height * 4)
        x = y = i = 0
        while i < len(body) and y < height:
            value = body[i]
            i += 1
            if value == 0xFF and i < len(body):
                x += body[i]
                i += 1
            else:
                if x < width:
                    offset = (y * width + x) * 4
                    base = value * 3
                    pixels[offset : offset + 4] = bytes(
                        (palette[base + 2], palette[base + 1], palette[base], 255)
                    )
                x += 1
            while x >= width:
                x -= width
                y += 1
        frames.append((width, height, bytes(pixels)))
    return frame_count, frames


def fnv1a(data: bytes) -> int:
    value = 0xCBF29CE484222325
    for byte in data:
        value ^= byte
        value = (value * 0x100000001B3) & 0xFFFFFFFFFFFFFFFF
    return value


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("path")
    parser.add_argument("--json", action="store_true")
    args = parser.parse_args()
    count, frames = decode_ani(Path(args.path).read_bytes())
    print(f"frames: {count}")
    for index, (width, height, pixels) in enumerate(frames):
        print(f"{index:3d} {width}x{height} fnv={fnv1a(pixels):016x}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
