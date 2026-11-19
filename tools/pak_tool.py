#!/usr/bin/env python3
"""Reader/extractor for Pizza Connection 2 "ResourceFile-ID-7654" .pak archives.

Format (reverse engineered from game/fastfood2.exe, functions 0x401af0,
0x401f30, 0x402060 and 0x402290):

  Header (0x6c bytes):
    0x00  char[20]  magic "ResourceFile-ID-7654\n\r\x1a" (NUL padded to 0x20)
    0x20  char[0x40] "Created:<date>" text, NUL padded
    0x60  u32       index_size
    0x64  u32       value 100 in all shipped paks (limit checked by loader)
    0x68  u32       1 when the index is obfuscated (all shipped paks)
    0x6c  byte[]    index, index_size bytes

  Index:
    Decode each byte i with: decoded[i] = ((encoded[i] - (i & 0xff)) & 0xff) ^ 0xaa
    u32             entry_count
    entry_count * 0x14 bytes:
        +0x00 u32   meta0 (unknown; not needed for extraction)
        +0x04 u32   meta1 (unknown)
        +0x08 u32   data_size
        +0x0c u32   data_offset_relative_to_0x6c
        +0x10 u32   name_offset_relative_to_name_table
    char[]          name table; NUL-terminated names

  Data:
    file offset = 0x6c + data_offset_relative_to_0x6c
    file size   = data_size

The loader sorts the in-memory entries by name and binary-searches them; the
on-disk order can differ. Names use the German code page; cp1252 is used for
display and latin-1 as a fallback.
"""

from __future__ import annotations

import argparse
import csv
import os
import re
import struct
import sys
from dataclasses import dataclass
from typing import Iterable

MAGIC = b"ResourceFile-ID-7654\n\r\x1a"
HEADER_SIZE = 0x6C
ENTRY_SIZE = 0x14


def decode_name(raw: bytes) -> str:
    try:
        return raw.decode("cp1252")
    except UnicodeDecodeError:
        return raw.decode("latin-1")


@dataclass(frozen=True)
class PakEntry:
    index: int
    name: str
    size: int
    rel_offset: int
    meta0: int
    meta1: int

    @property
    def offset(self) -> int:
        return HEADER_SIZE + self.rel_offset


class Pak:
    def __init__(self, path: str):
        self.path = os.path.abspath(path)
        with open(self.path, "rb") as fh:
            self.data = fh.read()
        if len(self.data) < HEADER_SIZE or not self.data.startswith(MAGIC):
            raise ValueError(f"{path}: not a ResourceFile-ID-7654 archive")
        self.index_size, self.header64, self.obfuscated = struct.unpack_from(
            "<III", self.data, 0x60
        )
        if HEADER_SIZE + self.index_size > len(self.data):
            raise ValueError(f"{path}: index extends past end of file")
        encoded = self.data[HEADER_SIZE : HEADER_SIZE + self.index_size]
        if self.obfuscated:
            decoded = bytes(
                (((b - (i & 0xFF)) & 0xFF) ^ 0xAA) for i, b in enumerate(encoded)
            )
        else:
            decoded = encoded
        self.index = decoded
        if len(decoded) < 4:
            raise ValueError(f"{path}: truncated index")
        count = struct.unpack_from("<I", decoded, 0)[0]
        self.names_base = 4 + count * ENTRY_SIZE
        if self.names_base > len(decoded):
            raise ValueError(f"{path}: entry table extends past index")
        entries = []
        for i in range(count):
            off = 4 + i * ENTRY_SIZE
            meta0, meta1, size, rel, name_rel = struct.unpack_from(
                "<IIIII", decoded, off
            )
            start = self.names_base + name_rel
            end = decoded.find(b"\0", start)
            if start >= len(decoded) or end < 0:
                raise ValueError(f"{path}: entry {i} has an invalid name offset")
            name = decode_name(decoded[start:end])
            if HEADER_SIZE + rel + size > len(self.data):
                raise ValueError(f"{path}: entry {i} ({name!r}) extends past EOF")
            entries.append(PakEntry(i, name, size, rel, meta0, meta1))
        self.entries = entries

    def find(self, name: str) -> PakEntry | None:
        needle = name.replace("/", "\\").lower()
        for entry in self.entries:
            if entry.name.replace("/", "\\").lower() == needle:
                return entry
        return None

    def read(self, entry: PakEntry) -> bytes:
        return self.data[entry.offset : entry.offset + entry.size]

    def filtered(self, pattern: str | None) -> Iterable[PakEntry]:
        if not pattern:
            return self.entries
        rx = re.compile(pattern, re.IGNORECASE)
        return (e for e in self.entries if rx.search(e.name))


def encode_index(decoded: bytes) -> bytes:
    """Inverse of the archive index transform."""
    return bytes(
        (((b ^ 0xAA) + (i & 0xFF)) & 0xFF) for i, b in enumerate(decoded)
    )


def safe_relative(name: str) -> str:
    name = name.replace("\\", "/")
    parts = [p for p in name.split("/") if p not in ("", ".")]
    if any(p == ".." for p in parts):
        raise ValueError(f"unsafe archive path: {name!r}")
    return "/".join(parts)


def cmd_info(args: argparse.Namespace) -> int:
    pak = Pak(args.pak)
    print(f"path:        {pak.path}")
    print(f"size:        {len(pak.data):,} bytes")
    print(f"index_size:  {pak.index_size:,} bytes")
    print(f"header64:    {pak.header64}")
    print(f"obfuscated:  {pak.obfuscated}")
    print(f"entries:     {len(pak.entries):,}")
    total = sum(e.size for e in pak.entries)
    print(f"data bytes:  {total:,}")
    print(f"data start:  0x{HEADER_SIZE + pak.index_size:x}")
    return 0


def cmd_list(args: argparse.Namespace) -> int:
    pak = Pak(args.pak)
    rows = list(pak.filtered(args.filter))
    if args.sort:
        rows.sort(key=lambda e: e.name.lower())
    writer = csv.writer(sys.stdout, delimiter="\t") if args.tsv else None
    if args.csv:
        fh = open(args.csv, "w", newline="", encoding="utf-8")
        writer = csv.writer(fh)
        writer.writerow(["archive", "name", "size", "offset", "meta0", "meta1"])
    elif writer:
        writer.writerow(["name", "size", "offset", "meta0", "meta1"])
    for e in rows:
        row = [e.name, e.size, e.offset, e.meta0, e.meta1]
        if writer:
            writer.writerow([os.path.basename(pak.path)] + row if args.csv else row)
        else:
            print(f"{e.size:9d}  {e.offset:10d}  {e.name}")
    if args.csv:
        fh.close()
    print(f"{len(rows)} entries", file=sys.stderr)
    return 0


def cmd_extract(args: argparse.Namespace) -> int:
    pak = Pak(args.pak)
    rows = list(pak.filtered(args.filter))
    os.makedirs(args.out, exist_ok=True)
    written = 0
    for e in rows:
        rel = safe_relative(e.name)
        dest = os.path.join(args.out, rel)
        os.makedirs(os.path.dirname(dest) or args.out, exist_ok=True)
        with open(dest, "wb") as fh:
            fh.write(pak.read(e))
        written += 1
    print(f"extracted {written} files from {pak.path} to {args.out}")
    return 0


def cmd_pack(args: argparse.Namespace) -> int:
    """Rebuild a .pak from a directory, optionally preserving manifest metadata."""
    root = os.path.abspath(args.directory)
    files = {}
    for dirpath, _dirs, names in os.walk(root):
        for name in names:
            full = os.path.join(dirpath, name)
            rel = os.path.relpath(full, root).replace(os.sep, "\\")
            files[rel.lower()] = (rel, full)

    manifest = {}
    order = []
    if args.manifest:
        with open(args.manifest, newline="", encoding="utf-8") as fh:
            rows = list(csv.DictReader(fh))
        if args.header_from and rows and "archive" in rows[0]:
            archive = os.path.basename(args.header_from)
            rows = [r for r in rows if r["archive"] == archive]
        for row in rows:
            key = row["name"].replace("/", "\\").lower()
            manifest[key] = row
            order.append(key)

    selected = []
    for key in order:
        if key in files:
            rel, full = files.pop(key)
            selected.append((rel, full, manifest.get(key)))
    if not (args.only_manifest and args.manifest):
        for key in sorted(files):
            rel, full = files[key]
            selected.append((rel, full, manifest.get(key)))

    names_blob = b"".join(
        name.encode("cp1252", "replace") + b"\0" for name, _full, _row in selected
    )
    count = len(selected)
    index_size = 4 + count * ENTRY_SIZE + len(names_blob)

    decoded = bytearray(struct.pack("<I", count))
    entries = bytearray()
    payload = bytearray()
    name_offset = 0
    data_offset = 0
    for name, full, row in selected:
        with open(full, "rb") as fh:
            data = fh.read()
        meta0 = int(row["meta0"]) if row and row.get("meta0") else 0
        meta1 = int(row["meta1"]) if row and row.get("meta1") else 0
        entries += struct.pack(
            "<IIIII",
            meta0,
            meta1,
            len(data),
            index_size + data_offset,
            name_offset,
        )
        name_offset += len(name.encode("cp1252", "replace")) + 1
        payload += data
        data_offset += len(data)
    decoded += entries + names_blob

    if args.header_from:
        with open(args.header_from, "rb") as fh:
            header = bytearray(fh.read(HEADER_SIZE))
        if not header.startswith(MAGIC):
            raise ValueError(f"{args.header_from}: not a ResourceFile-ID-7654 archive")
    else:
        header = bytearray(HEADER_SIZE)
        header[0 : len(MAGIC)] = MAGIC
        header[0x20 : 0x28] = b"Created:"
    struct.pack_into("<III", header, 0x60, index_size, 100, 1)

    with open(args.out, "wb") as fh:
        fh.write(header)
        fh.write(encode_index(decoded))
        fh.write(payload)
    print(
        f"wrote {args.out}: {count} entries, index {index_size:,} bytes, "
        f"payload {len(payload):,} bytes"
    )
    return 0


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    sub = ap.add_subparsers(dest="command", required=True)

    p = sub.add_parser("info", help="show archive header and entry count")
    p.add_argument("pak")
    p.set_defaults(func=cmd_info)

    p = sub.add_parser("list", help="list archive entries")
    p.add_argument("pak")
    p.add_argument("--filter", help="regex matched against entry names")
    p.add_argument("--sort", action="store_true", help="sort by name")
    p.add_argument("--tsv", action="store_true", help="tab-separated output")
    p.add_argument("--csv", help="write CSV to this path")
    p.set_defaults(func=cmd_list)

    p = sub.add_parser("extract", help="extract entries to a directory")
    p.add_argument("pak")
    p.add_argument("out")
    p.add_argument("--filter", help="regex matched against entry names")
    p.set_defaults(func=cmd_extract)

    p = sub.add_parser("pack", help="rebuild a .pak from a directory")
    p.add_argument("directory")
    p.add_argument("out")
    p.add_argument("--manifest", help="CSV from `list --csv` with name/meta/order")
    p.add_argument(
        "--only-manifest",
        action="store_true",
        help="pack only files listed in the manifest (ignore other files in the directory)",
    )
    p.add_argument("--header-from", help="copy the 0x6c header from this archive")
    p.set_defaults(func=cmd_pack)

    args = ap.parse_args(argv)
    return args.func(args)


if __name__ == "__main__":
    raise SystemExit(main())
