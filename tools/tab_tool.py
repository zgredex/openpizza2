#!/usr/bin/env python3
"""Decoder for Pizza Connection 2 `.tab` tables.

Recovered from ``Ingredient_LoadMarketTable`` (0x4E4930) and
``Recipe_StreamConstruct`` (0x511BE0).

``Size.tab``
    86 ingredient records, 128 bytes each: four layers of eight u16 pairs
    (sprite width/height for the four size tiers).

``Ingredients.tab``
    128-byte blocks: 32 u16 coordinate pairs.  ``Recipe_StreamConstruct``
    indexes a block with::

        base(0..12)
        + (variant(0..3) + (quality + category*4)*8) * 13

    and then reads the ``position`` pair (0..31) inside the block.

Usage::

    python3 tools/tab_tool.py info extracted/daten/size.tab
    python3 tools/tab_tool.py size-json extracted/daten/size.tab size.json
    python3 tools/tab_tool.py block extracted/daten/ingredients.tab --index 0
"""

from __future__ import annotations

import argparse
import csv
import json
import struct
import sys

SIZE_RECORD = 128
SIZE_LAYERS = 4
SIZE_SLOTS = 8
SIZE_COUNT = 86
INGREDIENT_BLOCK = 128
INGREDIENT_SLOTS = 32
INGREDIENT_BASES = 13
INGREDIENT_LAYER_STRIDE = INGREDIENT_BASES


def u16_pairs(data: bytes):
    return [struct.unpack_from("<HH", data, i * 4)
            for i in range(len(data) // 4)]


def decode_size(path: str):
    with open(path, "rb") as fh:
        data = fh.read()
    if len(data) % SIZE_RECORD:
        raise ValueError(f"size {len(data)} is not a multiple of {SIZE_RECORD}")
    count = len(data) // SIZE_RECORD
    records = []
    for index in range(count):
        chunk = data[index * SIZE_RECORD:(index + 1) * SIZE_RECORD]
        pairs = u16_pairs(chunk)
        layers = [pairs[i * SIZE_SLOTS:(i + 1) * SIZE_SLOTS]
                  for i in range(SIZE_LAYERS)]
        records.append({
            "index": index,
            "id": index + 1,
            "sizes": [[{"w": w, "h": h} for w, h in layer]
                      for layer in layers],
        })
    return {"path": path, "size": len(data), "count": count,
            "records": records}


def decode_ingredients(path: str):
    with open(path, "rb") as fh:
        data = fh.read()
    if len(data) % INGREDIENT_BLOCK:
        raise ValueError(
            f"size {len(data)} is not a multiple of {INGREDIENT_BLOCK}")
    blocks = len(data) // INGREDIENT_BLOCK
    return {"path": path, "size": len(data), "block_size": INGREDIENT_BLOCK,
            "blocks": blocks}


def ingredient_block(path: str, index: int):
    with open(path, "rb") as fh:
        data = fh.read()
    blocks = len(data) // INGREDIENT_BLOCK
    if not 0 <= index < blocks:
        raise IndexError(f"block {index} outside 0..{blocks - 1}")
    chunk = data[index * INGREDIENT_BLOCK:(index + 1) * INGREDIENT_BLOCK]
    pairs = u16_pairs(chunk)
    base = index % INGREDIENT_BASES
    layer = index // INGREDIENT_BASES
    return {
        "index": index,
        "base": base,
        "layer": layer,
        "pairs": [{"x": x, "y": y} for x, y in pairs],
    }


def cmd_info(args):
    if args.kind == "size":
        table = decode_size(args.tab)
        info = {"kind": "size", "count": table["count"],
                "size": table["size"], "record_size": SIZE_RECORD}
    else:
        table = decode_ingredients(args.tab)
        info = {"kind": "ingredients", "blocks": table["blocks"],
                "size": table["size"], "block_size": INGREDIENT_BLOCK,
                "bases": INGREDIENT_BASES, "positions": INGREDIENT_SLOTS}
    print(json.dumps(info, indent=2))
    return 0


def cmd_size_json(args):
    table = decode_size(args.tab)
    with open(args.out, "w") as fh:
        json.dump(table, fh, indent=1)
    print(f"wrote {args.out}: {table['count']} records")
    return 0


def cmd_size_csv(args):
    table = decode_size(args.tab)
    with open(args.out, "w", newline="") as fh:
        w = csv.writer(fh)
        w.writerow(["index", "layer", "slot", "width", "height"])
        for rec in table["records"]:
            for li, layer in enumerate(rec["sizes"]):
                for si, entry in enumerate(layer):
                    w.writerow([rec["index"], li, si,
                                entry["w"], entry["h"]])
    print(f"wrote {args.out}: {table['count']} records")
    return 0


def cmd_block(args):
    block = ingredient_block(args.tab, args.index)
    if args.json:
        print(json.dumps(block, indent=1))
    else:
        print(f"block {block['index']} base={block['base']} "
              f"layer={block['layer']}")
        for i, pair in enumerate(block["pairs"]):
            print(f"  {i:2d}: ({pair['x']}, {pair['y']})")
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    sub = ap.add_subparsers(dest="command", required=True)

    p = sub.add_parser("info", help="table summary")
    p.add_argument("tab")
    p.add_argument("--kind", choices=("size", "ingredients"), required=True)
    p.set_defaults(func=cmd_info)

    p = sub.add_parser("size-json", help="decode Size.tab to JSON")
    p.add_argument("tab")
    p.add_argument("out")
    p.set_defaults(func=cmd_size_json)

    p = sub.add_parser("size-csv", help="decode Size.tab to CSV")
    p.add_argument("tab")
    p.add_argument("out")
    p.set_defaults(func=cmd_size_csv)

    p = sub.add_parser("block", help="inspect an Ingredients.tab block")
    p.add_argument("tab")
    p.add_argument("--index", type=int, default=0)
    p.add_argument("--json", action="store_true")
    p.set_defaults(func=cmd_block)

    args = ap.parse_args(argv)
    return args.func(args)


if __name__ == "__main__":
    raise SystemExit(main())
