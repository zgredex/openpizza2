#!/usr/bin/env python3
"""Reader for Pizza Connection 2 .piz save headers.

Reverse engineered from fastfood2.exe:
  SaveGame_Write          0x487520  builds the 0xF0-byte header and calls the serializer
  SaveGame_Serialize      0x487b50  writes the payload sections
  SaveGame_ReadHeaderEntry 0x4a1570 reads 0xF0 bytes and validates magic 0x13738317
  SaveGame_CompareTime    0x4a14c0  sorts entries by their SYSTEMTIME

Header (0xF0 bytes, little-endian):
  0x00  char[64]  save title / user label ("auto_<date> <time>" for autosaves)
  0x40  char[64]  company or player name
  0x80  char[64]  city name
  0xC0  u8        active company count (writer loops 0..5)
  0xC1  u8[7]     company flags: 0 empty, 1 current player, 2 other
  0xC8  u32       game calendar field 1
  0xCC  u32       game calendar field 2
  0xD0  u32       game calendar field 3
  0xD4  u32       game calendar field 4
  0xD8  SYSTEMTIME (8 x u16): year, month, day-of-week, day, hour, minute, second, ms
  0xE8  u32       version = 0x11
  0xEC  u32       magic   = 0x13738317

After the header SaveGame_Serialize writes:
  0xF0  u32[8]    section directory (written last; not a zero block)
  0x110 u32       start marker 0x2E
  0x114 byte[0x5B8] global game block
  ...            0x20 + 0x20 bytes, 20 u32 scalars, subsystem serializers
  ...            u32 end marker 0x2A
  32-byte trailer is rewritten at the reserved block position

The full payload is a graph of game-state serializers and is not decoded by this
tool. This tool reads and validates the header and the start marker, which is what
the save-list UI uses (0x4a1570).
"""

from __future__ import annotations

import argparse
import json
import os
import struct
import sys
from dataclasses import asdict, dataclass, field

HEADER_SIZE = 0xF0
MAGIC = 0x13738317
VERSION = 0x11
RESERVED_SIZE = 0x20
START_MARKER = 0x2E
END_MARKER = 0x2A


def decode_text(raw: bytes) -> str:
    raw = raw.split(b"\0", 1)[0]
    try:
        return raw.decode("cp1252")
    except UnicodeDecodeError:
        return raw.decode("latin-1")


def encode_text(text: str, size: int = 64) -> bytes:
    raw = text.encode("cp1252", "replace")[: size - 1]
    return raw + b"\0" * (size - len(raw))


@dataclass
class SaveHeader:
    path: str
    title: str
    company: str
    city: str
    player_count: int
    player_flags: list[int]
    game_calendar: list[int]
    system_time: dict[str, int]
    version: int
    magic: int
    magic_ok: bool
    payload_size: int
    reserved_hex: str | None = None
    directory_hex: str | None = None
    start_marker: int | None = None

    def to_dict(self) -> dict:
        return asdict(self)


def read_header(path: str) -> SaveHeader:
    with open(path, "rb") as fh:
        data = fh.read()
    if len(data) < HEADER_SIZE:
        raise ValueError(f"{path}: file is shorter than the 0xF0 header")
    title = decode_text(data[0x00:0x40])
    company = decode_text(data[0x40:0x80])
    city = decode_text(data[0x80:0xC0])
    player_count = data[0xC0]
    player_flags = list(data[0xC1:0xC8])
    game_calendar = list(struct.unpack_from("<IIII", data, 0xC8))
    st = struct.unpack_from("<8H", data, 0xD8)
    system_time = dict(
        zip(
            [
                "year",
                "month",
                "day_of_week",
                "day",
                "hour",
                "minute",
                "second",
                "millisecond",
            ],
            st,
        )
    )
    version, magic = struct.unpack_from("<II", data, 0xE8)
    reserved = data[HEADER_SIZE : HEADER_SIZE + RESERVED_SIZE]
    marker = None
    if len(data) >= HEADER_SIZE + RESERVED_SIZE + 4:
        marker = struct.unpack_from("<I", data, HEADER_SIZE + RESERVED_SIZE)[0]
    return SaveHeader(
        path=os.path.abspath(path),
        title=title,
        company=company,
        city=city,
        player_count=player_count,
        player_flags=player_flags,
        game_calendar=game_calendar,
        system_time=system_time,
        version=version,
        magic=magic,
        magic_ok=magic == MAGIC,
        payload_size=max(0, len(data) - HEADER_SIZE - RESERVED_SIZE - 4),
        reserved_hex=reserved.hex() if reserved else None,
        directory_hex=reserved.hex() if reserved else None,
        start_marker=marker,
    )


def format_header(h: SaveHeader) -> str:
    st = h.system_time
    stamp = (
        f"{st['year']:04d}-{st['month']:02d}-{st['day']:02d} "
        f"{st['hour']:02d}:{st['minute']:02d}:{st['second']:02d}"
    )
    flags = " ".join(str(x) for x in h.player_flags)
    return (
        f"path:        {h.path}\n"
        f"title:       {h.title}\n"
        f"company:     {h.company}\n"
        f"city:        {h.city}\n"
        f"companies:   {h.player_count}  flags=[{flags}]\n"
        f"game date:   {h.game_calendar}\n"
        f"system time: {stamp}\n"
        f"version:     0x{h.version:x}\n"
        f"magic:       0x{h.magic:08x} {'OK' if h.magic_ok else 'MISMATCH'}\n"
        f"start marker: {('0x%x' % h.start_marker) if h.start_marker is not None else 'absent'}\n"
        f"payload size:{h.payload_size:,} bytes"
    )


def cmd_info(args: argparse.Namespace) -> int:
    h = read_header(args.piz)
    if args.json:
        print(json.dumps(h.to_dict(), indent=2))
    else:
        print(format_header(h))
    return 0 if h.magic_ok else 2


def cmd_list(args: argparse.Namespace) -> int:
    paths = []
    for root, _dirs, files in os.walk(args.directory):
        for name in files:
            if name.lower().endswith(".piz"):
                paths.append(os.path.join(root, name))
    paths.sort()
    if not paths:
        print(f"no .piz files under {args.directory}", file=sys.stderr)
        return 1
    for p in paths:
        try:
            h = read_header(p)
        except ValueError as exc:
            print(f"{p}: {exc}")
            continue
        st = h.system_time
        stamp = (
            f"{st['year']:04d}-{st['month']:02d}-{st['day']:02d} "
            f"{st['hour']:02d}:{st['minute']:02d}"
        )
        print(
            f"{stamp}  {h.title[:32]:32s}  {h.company[:24]:24s}  "
            f"{h.city[:20]:20s}  {h.payload_size:9d} B  {'OK' if h.magic_ok else 'BAD'}"
        )
    return 0


def cmd_synth(args: argparse.Namespace) -> int:
    """Write a structurally valid full-payload .piz for parser testing."""
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    from piz_payload import build_synthetic
    raw = build_synthetic(args.title, args.company, args.city)
    with open(args.out, "wb") as fh:
        fh.write(raw)
    print(f"wrote synthetic full-payload save: {args.out} ({len(raw):,} bytes)")
    return 0


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    sub = ap.add_subparsers(dest="command", required=True)

    p = sub.add_parser("info", help="show a .piz header")
    p.add_argument("piz")
    p.add_argument("--json", action="store_true")
    p.set_defaults(func=cmd_info)

    p = sub.add_parser("list", help="scan a directory for .piz files")
    p.add_argument("directory")
    p.set_defaults(func=cmd_list)

    p = sub.add_parser("synth", help="write a synthetic header-only .piz for testing")
    p.add_argument("out")
    p.add_argument("--title", default="Synthetic save")
    p.add_argument("--company", default="Test Pizza Inc.")
    p.add_argument("--city", default="London")
    p.set_defaults(func=cmd_synth)

    args = ap.parse_args(argv)
    return args.func(args)


if __name__ == "__main__":
    raise SystemExit(main())
