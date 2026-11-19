#!/usr/bin/env python3
"""Decoder/PNG exporter for Pizza Connection 2 .spr sprites.

Reverse engineered from Sprite_Load (0x53c7f0) and the compressed blitter
FUN_0053a780. Header (0x21 bytes):

  0x00 u32  pixel-stream size (8bpp: excludes the 0x300-byte palette)
  0x04 u8   format byte
  0x05 u8   flags; bit 0x10 selects the alpha/RLE token format
  0x06 u8   bits per pixel (8 or 16)
  0x07 u16  row stride in bytes
  0x09 u16  height
  0x13 u16  canvas width
  0x15 u16  canvas height
  0x19 u32  pixel-stream size
  0x1D u32  transparent color key (16bpp raw)
  0x21 byte[] payload

Width is stride / (bpp/8). For 8bpp the pixel stream comes first and the
0x300-byte BGR palette follows it at `0x21 + data_size`. Raw 16bpp is RGB555.
Raw 8bpp is one byte per pixel with `0xff <run>` transparent runs; the
alpha/RLE flag instead selects two-byte (alpha, index) tokens.

Token formats when flags & 0x10:
  8bpp:  u16 (alpha:u8, palette_index:u8)
  16bpp: u32 (alpha_word:u16, rgb555:u16)
  alpha == 0 -> skip `index/color` pixels (transparent run)
  alpha 0x3c -> fully opaque; other alpha values are 0..60 and blended.

This tool exports RGBA PNGs. It is a static-format decoder, not a runtime hook.
"""

from __future__ import annotations

import argparse
import os
import struct
import sys
import zlib
from dataclasses import dataclass
from pathlib import Path

HEADER_SIZE = 0x21
PALETTE_SIZE = 0x300


def png_bytes(width: int, height: int, rgba: bytes) -> bytes:
    raw = b"".join(
        b"\x00" + rgba[y * width * 4 : (y + 1) * width * 4] for y in range(height)
    )

    def chunk(tag: bytes, data: bytes) -> bytes:
        body = tag + data
        return (
            struct.pack(">I", len(data))
            + body
            + struct.pack(">I", zlib.crc32(body) & 0xFFFFFFFF)
        )

    return (
        b"\x89PNG\r\n\x1a\n"
        + chunk(b"IHDR", struct.pack(">IIBBBBB", width, height, 8, 6, 0, 0, 0))
        + chunk(b"IDAT", zlib.compress(raw, 9))
        + chunk(b"IEND", b"")
    )


@dataclass
class SprHeader:
    bpp: int
    flags: int
    stride: int
    height: int
    canvas_width: int
    canvas_height: int
    data_size: int
    color_key: int
    compressed: bool
    width: int


def read_header(data: bytes) -> SprHeader:
    if len(data) < HEADER_SIZE:
        raise ValueError("file is shorter than the 0x21-byte header")
    bpp = data[6]
    if bpp not in (8, 16):
        raise ValueError(f"unsupported bpp {bpp}")
    flags = data[5]
    stride, height = struct.unpack_from("<HH", data, 7)
    canvas_width, canvas_height = struct.unpack_from("<HH", data, 19)
    data_size = struct.unpack_from("<I", data, 0x19)[0]
    color_key = struct.unpack_from("<I", data, 0x1D)[0]
    width = stride // (bpp // 8)
    return SprHeader(
        bpp=bpp,
        flags=flags,
        stride=stride,
        height=height,
        canvas_width=canvas_width,
        canvas_height=canvas_height,
        data_size=data_size,
        color_key=color_key,
        compressed=bool(flags & 0x10),
        width=width,
    )


def decode_spr(data: bytes) -> tuple[SprHeader, bytes]:
    h = read_header(data)
    payload = data[HEADER_SIZE:]
    palette = None
    if h.bpp == 8:
        if len(payload) < h.data_size + PALETTE_SIZE:
            raise ValueError("8bpp sprite is missing its 0x300-byte palette")
        palette = payload[h.data_size : h.data_size + PALETTE_SIZE]
        payload = payload[: h.data_size]
    else:
        payload = payload[: h.data_size]

    w, hgt = h.width, h.height
    if w <= 0 or hgt <= 0:
        # `isodaten/sprites/blinki.spr` is a valid blank 0x0 sprite with a
        # 64x64 canvas; return an empty image rather than rejecting the map.
        return h, b""
    rgba = bytearray(w * hgt * 4)

    def put(x: int, y: int, r: int, g: int, b: int, a: int) -> None:
        if 0 <= x < w and 0 <= y < hgt:
            off = (y * w + x) * 4
            rgba[off : off + 4] = bytes((r, g, b, a))

    def alpha8(a: int) -> int:
        if a >= 0x3C:
            return 255
        return max(0, min(255, a * 255 // 0x3C))

    if h.bpp == 16:
        if h.compressed:
            x = y = 0
            i = 0
            while i + 4 <= len(payload) and y < hgt:
                tok = struct.unpack_from("<I", payload, i)[0]
                i += 4
                aw = tok & 0xFFFF
                color = tok >> 16
                if aw == 0:
                    x += color
                else:
                    a = (aw >> 8) & 0xFF
                    r = ((color >> 10) & 31) * 255 // 31
                    g = ((color >> 5) & 31) * 255 // 31
                    b = (color & 31) * 255 // 31
                    put(x, y, r, g, b, alpha8(a))
                    x += 1
                while x >= w:
                    x -= w
                    y += 1
        else:
            x = y = 0
            for i in range(0, len(payload) - 1, 2):
                color = struct.unpack_from("<H", payload, i)[0]
                if color != h.color_key:
                    r = ((color >> 10) & 31) * 255 // 31
                    g = ((color >> 5) & 31) * 255 // 31
                    b = (color & 31) * 255 // 31
                    put(x, y, r, g, b, 255)
                x += 1
                if x >= w:
                    x = 0
                    y += 1
    else:
        if h.compressed:
            x = y = 0
            i = 0
            while i + 2 <= len(payload) and y < hgt:
                tok = struct.unpack_from("<H", payload, i)[0]
                i += 2
                a = tok & 0xFF
                idx = tok >> 8
                if a == 0:
                    x += idx
                else:
                    r, g, b = palette[idx * 3 + 2], palette[idx * 3 + 1], palette[idx * 3]
                    put(x, y, r, g, b, alpha8(a))
                    x += 1
                while x >= w:
                    x -= w
                    y += 1
        else:
            key = h.color_key & 0xFF
            x = y = 0
            if len(payload) >= w * hgt:
                for i in range(w * hgt):
                    value = payload[i]
                    if value != key:
                        r, g, b = palette[value * 3 + 2], palette[value * 3 + 1], palette[value * 3]
                        put(i % w, i // w, r, g, b, 255)
            else:
                i = 0
                while i < len(payload) and y < hgt:
                    byte = payload[i]
                    i += 1
                    if byte == key and i < len(payload):
                        x += payload[i]
                        i += 1
                    else:
                        r, g, b = palette[byte * 3 + 2], palette[byte * 3 + 1], palette[byte * 3]
                        put(x, y, r, g, b, 255)
                        x += 1
                    while x >= w:
                        x -= w
                        y += 1
    return h, bytes(rgba)


def info_text(path: str) -> str:
    data = Path(path).read_bytes()
    h = read_header(data)
    return (
        f"path:        {path}\n"
        f"bpp:         {h.bpp}\n"
        f"flags:       0x{h.flags:02x} ({'alpha/RLE' if h.compressed else 'raw'})\n"
        f"stride:      {h.stride} bytes\n"
        f"image:       {h.width}x{h.height}\n"
        f"canvas:      {h.canvas_width}x{h.canvas_height}\n"
        f"data size:   {h.data_size:,} bytes\n"
        f"color key:   0x{h.color_key:04x}\n"
        f"file size:   {len(data):,} bytes"
    )


def collect(path: str, pattern: str | None) -> list[str]:
    p = Path(path)
    if p.is_file():
        return [str(p)]
    out = []
    for root, _dirs, files in os.walk(p):
        for name in files:
            if name.lower().endswith(".spr"):
                if pattern and pattern.lower() not in name.lower():
                    continue
                out.append(os.path.join(root, name))
    out.sort()
    return out


def cmd_info(args: argparse.Namespace) -> int:
    print(info_text(args.spr))
    return 0


def cmd_export(args: argparse.Namespace) -> int:
    files = collect(args.input, args.filter)
    if not files:
        print("no .spr files found", file=sys.stderr)
        return 1
    if args.limit:
        files = files[: args.limit]
    os.makedirs(args.out, exist_ok=True)
    input_is_dir = os.path.isdir(args.input)
    count = 0
    for path in files:
        try:
            h, rgba = decode_spr(Path(path).read_bytes())
        except ValueError as exc:
            print(f"skip {path}: {exc}", file=sys.stderr)
            continue
        if input_is_dir:
            rel = os.path.relpath(path, args.input)
        else:
            rel = os.path.basename(path)
        rel = os.path.splitext(rel)[0] + ".png"
        dest = os.path.join(args.out, rel)
        os.makedirs(os.path.dirname(dest) or args.out, exist_ok=True)
        Path(dest).write_bytes(png_bytes(h.width, h.height, rgba))
        count += 1
        if args.verbose:
            print(f"{path} -> {dest} ({h.width}x{h.height})")
    print(f"exported {count} PNGs to {args.out}")
    return 0


def cmd_list(args: argparse.Namespace) -> int:
    for path in collect(args.path, args.filter):
        try:
            h = read_header(Path(path).read_bytes())
            print(
                f"{h.width:4d}x{h.height:<4d} {h.bpp:2d}bpp "
                f"{'RLE' if h.compressed else 'raw':3s} {path}"
            )
        except ValueError as exc:
            print(f"bad  {path}: {exc}")
    return 0


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    sub = ap.add_subparsers(dest="command", required=True)

    p = sub.add_parser("info", help="show sprite header")
    p.add_argument("spr")
    p.set_defaults(func=cmd_info)

    p = sub.add_parser("list", help="list .spr files")
    p.add_argument("path")
    p.add_argument("--filter", help="case-insensitive filename substring")
    p.set_defaults(func=cmd_list)

    p = sub.add_parser("export", help="export .spr file(s) to PNG")
    p.add_argument("input", help=".spr file or directory")
    p.add_argument("out", help="output directory")
    p.add_argument("--filter", help="case-insensitive filename substring")
    p.add_argument("--limit", type=int, help="export only the first N files")
    p.add_argument("--verbose", action="store_true")
    p.set_defaults(func=cmd_export)

    args = ap.parse_args(argv)
    return args.func(args)


if __name__ == "__main__":
    raise SystemExit(main())
