#!/usr/bin/env python3
"""Report semantic-naming progress for the recovered global symbol table.

symbol_coverage.py answers whether every address has an identifier.  This
report answers the harder question: how many identifiers are still generic
owner/role aliases (medium confidence) and which subsystems they belong to.
"""

from __future__ import annotations

import argparse
import collections
import csv
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BASE = ROOT / "decompiled_fastfood2_named_v2"
SYMBOLS = BASE / "data_symbols.csv"


def normalize(value: str) -> str:
    value = value.strip().lower()
    if value.startswith("0x"):
        value = value[2:]
    return value.zfill(8)


def owner(name: str) -> str:
    if name.startswith("g_Func_"):
        return "g_Func"
    match = re.match(r"g_([A-Za-z0-9]+?)(?:_[A-Z][A-Za-z0-9]*)?_[0-9A-Fa-f]{8}$", name)
    if match:
        return match.group(1)
    return name.split("_")[1] if "_" in name else name


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--json", action="store_true")
    args = parser.parse_args()

    rows = list(csv.DictReader(SYMBOLS.open(newline="", encoding="utf-8")))
    counts = collections.Counter(row["confidence"] for row in rows)
    medium = [row for row in rows if row["confidence"] == "medium"]
    game = [row for row in medium if int(row["address"], 16) < 0x580000]
    crt = [row for row in medium if int(row["address"], 16) >= 0x580000]
    groups = collections.Counter(owner(row["name"]) for row in medium)

    result = {
        "total_symbols": len(rows),
        "high_confidence": counts.get("high", 0),
        "medium_confidence": counts.get("medium", 0),
        "medium_game_globals": len(game),
        "medium_crt_globals": len(crt),
        "top_medium_owners": groups.most_common(20),
        "medium_addresses": [row["address"] for row in medium],
    }
    if args.json:
        print(json.dumps(result, indent=2))
        return 0

    print("# Global naming progress")
    print()
    print(f"- Total data symbols: {result['total_symbols']}")
    print(f"- High confidence: {result['high_confidence']}")
    print(f"- Medium confidence (generic owner/role aliases): "
          f"{result['medium_confidence']}")
    print(f"- Medium game globals: {result['medium_game_globals']}")
    print(f"- Medium CRT globals: {result['medium_crt_globals']}")
    print()
    print("## Top remaining owners")
    print()
    print("| Owner prefix | Remaining |")
    print("|---|---:|")
    for name, count in groups.most_common(25):
        print(f"| `{name}` | {count} |")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
