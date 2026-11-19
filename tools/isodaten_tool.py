#!/usr/bin/env python3
"""Parser for Pizza Connection 2 Isodaten.idx.

Format recovered from Map_LoadIsodata (0x4ea440) and validated against
game/Isokarten/Isodaten.idx:
  u32 entry_count
  entry:
    u8   tag            0 = functional marker, 1 = isometric sprite
    char name[50]       main .SPR name
    u32  has_large      variant name = main + ".L.SPR"
    u32  has_small      variant name = main + ".S.SPR"
    u32  has_medium     variant name = main + ".M.SPR"
    u32  anim_count
    anim[anim_count]:
      u8   a, b, c, d
      u8   reserved[0x0f]
      char name[50]     .ANI name

The parser consumes the file exactly; the final cursor must equal file size.
"""

from __future__ import annotations

import argparse
import csv
import json
import struct
import sys

VARIANT_SUFFIX = [".L.SPR", ".S.SPR", ".M.SPR"]
ANIM_HEADER_SIZE = 0x13
NAME_SIZE = 50


def read_name(raw: bytes) -> str:
    return raw.split(b"\0", 1)[0].decode("latin1")


def parse(path: str) -> dict:
    with open(path, "rb") as fh:
        data = fh.read()
    if len(data) < 4:
        raise ValueError("file shorter than count")
    count = struct.unpack_from("<I", data, 0)[0]
    pos = 4
    entries = []
    for i in range(count):
        if pos + 1 + NAME_SIZE + 12 + 4 > len(data):
            raise ValueError(f"entry {i} truncated at 0x{pos:x}")
        tag = data[pos]
        pos += 1
        name = read_name(data[pos:pos + NAME_SIZE])
        pos += NAME_SIZE
        flags = list(struct.unpack_from("<III", data, pos))
        pos += 12
        anim_count = struct.unpack_from("<I", data, pos)[0]
        pos += 4
        anims = []
        for j in range(anim_count):
            if pos + ANIM_HEADER_SIZE + NAME_SIZE > len(data):
                raise ValueError(f"entry {i} anim {j} truncated at 0x{pos:x}")
            hdr = data[pos:pos + ANIM_HEADER_SIZE]
            pos += ANIM_HEADER_SIZE
            anim_name = read_name(data[pos:pos + NAME_SIZE])
            pos += NAME_SIZE
            anims.append({
                "header": list(hdr[:4]),
                "reserved": hdr[4:].hex(),
                "name": anim_name,
            })
        variants = []
        for suffix, present in zip(VARIANT_SUFFIX, flags):
            if present:
                variants.append(name[:-4] + suffix if name.upper().endswith(".SPR")
                                else name + suffix)
        entries.append({
            "index": i,
            "tag": tag,
            "name": name,
            "variants": variants,
            "variant_flags": flags,
            "animations": anims,
        })
    if pos != len(data):
        raise ValueError(f"parsed 0x{pos:x}, file size 0x{len(data):x}")
    return {
        "path": path,
        "size": len(data),
        "count": count,
        "entries": entries,
    }


def summary(parsed: dict) -> dict:
    entries = parsed["entries"]
    return {
        "path": parsed["path"],
        "size": parsed["size"],
        "count": parsed["count"],
        "markers": sum(1 for e in entries if e["tag"] == 0),
        "sprites": sum(1 for e in entries if e["tag"] == 1),
        "with_variants": sum(1 for e in entries if any(e["variant_flags"])),
        "animations": sum(len(e["animations"]) for e in entries),
        "with_animations": sum(1 for e in entries if e["animations"]),
        "first": entries[0]["name"] if entries else None,
        "last": entries[-1]["name"] if entries else None,
    }


def cmd_info(args):
    parsed = parse(args.idx)
    info = summary(parsed)
    if args.json:
        print(json.dumps(info, indent=2))
    else:
        for key, value in info.items():
            print(f"{key:16s} {value}")
    return 0


def cmd_list(args):
    parsed = parse(args.idx)
    entries = parsed["entries"]
    if args.json:
        print(json.dumps(entries, indent=2))
        return 0
    for e in entries:
        variants = ",".join(s.split(".")[1] for s in e["variants"])
        anims = len(e["animations"])
        print(f"{e['index']:5d} tag={e['tag']} {e['name']:42s} "
              f"variants=[{variants}] anims={anims}")
    return 0


def cmd_csv(args):
    parsed = parse(args.idx)
    with open(args.out, "w", newline="") as fh:
        w = csv.writer(fh)
        w.writerow(["index", "tag", "name", "variant_large", "variant_small",
                    "variant_medium", "anim_count", "animations"])
        for e in parsed["entries"]:
            v = e["variants"] + ["", "", ""]
            w.writerow([e["index"], e["tag"], e["name"], v[0], v[1], v[2],
                        len(e["animations"]),
                        ";".join(a["name"] for a in e["animations"])])
    print(f"wrote {args.out}: {parsed['count']} entries")
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    sub = ap.add_subparsers(dest="command", required=True)
    p = sub.add_parser("info", help="summary")
    p.add_argument("idx")
    p.add_argument("--json", action="store_true")
    p.set_defaults(func=cmd_info)
    p = sub.add_parser("list", help="list entries")
    p.add_argument("idx")
    p.add_argument("--json", action="store_true")
    p.set_defaults(func=cmd_list)
    p = sub.add_parser("csv", help="export a flat CSV")
    p.add_argument("idx")
    p.add_argument("out")
    p.set_defaults(func=cmd_csv)
    args = ap.parse_args(argv)
    return args.func(args)


if __name__ == "__main__":
    raise SystemExit(main())
