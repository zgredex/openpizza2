#!/usr/bin/env python3
"""Reader/rebuilder for Pizza Connection 2 language.ldf string tables.

Format (verified on game/language.ldf):
  u32      string count
  char[]   count NUL-terminated strings, ANSI/cp1252
  EOF immediately after the last terminator

The game's Language_LoadLDF (0x5145a0) reads the count, then uses the strings as
a fixed ID table; Language_MapStrings (0x5146d0) copies the pointers into globals.
"""

from __future__ import annotations

import argparse
import json
import struct
import sys
from pathlib import Path


def decode(raw: bytes) -> str:
    try:
        return raw.decode("cp1252")
    except UnicodeDecodeError:
        return raw.decode("latin-1")


def read_ldf(path: str) -> list[str]:
    data = Path(path).read_bytes()
    if len(data) < 4:
        raise ValueError(f"{path}: shorter than the 4-byte count")
    count = struct.unpack_from("<I", data, 0)[0]
    pos = 4
    strings = []
    for i in range(count):
        end = data.find(b"\0", pos)
        if end < 0:
            raise ValueError(f"{path}: string {i} is not terminated")
        strings.append(decode(data[pos:end]))
        pos = end + 1
    if pos != len(data):
        raise ValueError(f"{path}: {len(data) - pos} trailing bytes after {count} strings")
    return strings


def write_ldf(path: str, strings: list[str]) -> None:
    out = bytearray(struct.pack("<I", len(strings)))
    for s in strings:
        out += s.encode("cp1252", "replace") + b"\0"
    Path(path).write_bytes(out)


def cmd_info(args: argparse.Namespace) -> int:
    strings = read_ldf(args.ldf)
    size = Path(args.ldf).stat().st_size
    print(f"path:    {args.ldf}")
    print(f"strings: {len(strings)}")
    print(f"bytes:   {size:,}")
    print(f"first:   {strings[:5]}")
    print(f"last:    {strings[-5:]}")
    return 0


def cmd_list(args: argparse.Namespace) -> int:
    strings = read_ldf(args.ldf)
    for i, s in enumerate(strings):
        if args.filter and args.filter.lower() not in s.lower():
            continue
        print(f"{i:5d}  {s}")
    return 0


def cmd_dump(args: argparse.Namespace) -> int:
    strings = read_ldf(args.ldf)
    Path(args.out).write_text(
        json.dumps(strings, ensure_ascii=False, indent=2), encoding="utf-8"
    )
    print(f"wrote {len(strings)} strings to {args.out}")
    return 0


def cmd_pack(args: argparse.Namespace) -> int:
    strings = json.loads(Path(args.json).read_text(encoding="utf-8"))
    if not isinstance(strings, list) or not all(isinstance(s, str) for s in strings):
        raise ValueError("JSON must be an array of strings")
    write_ldf(args.out, strings)
    print(f"wrote {len(strings)} strings to {args.out}")
    return 0


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    sub = ap.add_subparsers(dest="command", required=True)

    p = sub.add_parser("info", help="show table count and samples")
    p.add_argument("ldf")
    p.set_defaults(func=cmd_info)

    p = sub.add_parser("list", help="list strings by index")
    p.add_argument("ldf")
    p.add_argument("--filter", help="case-insensitive substring filter")
    p.set_defaults(func=cmd_list)

    p = sub.add_parser("dump", help="dump strings to JSON")
    p.add_argument("ldf")
    p.add_argument("out")
    p.set_defaults(func=cmd_dump)

    p = sub.add_parser("pack", help="build an LDF from a JSON string array")
    p.add_argument("json")
    p.add_argument("out")
    p.set_defaults(func=cmd_pack)

    args = ap.parse_args(argv)
    return args.func(args)


if __name__ == "__main__":
    raise SystemExit(main())
