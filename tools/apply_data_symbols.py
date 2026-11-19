#!/usr/bin/env python3
"""Apply evidence-backed data names to a readable copy of the pseudocode.

The canonical decompiled files stay untouched.  Output goes to
decompiled_fastfood2_named_v2/functions_readable/ so the replacement is
reproducible and reviewable.
"""

from __future__ import annotations

import argparse
import collections
import csv
import re
import shutil
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BASE = ROOT / "decompiled_fastfood2_named_v2"
SOURCE = BASE / "full_game_verification" / "functions"
DEST = BASE / "functions_readable"
SYMBOLS = BASE / "data_symbols.csv"
FUNCTION_SYMBOLS = BASE / "symbols.csv"
ADDRESS_RE = re.compile(r"\b(?:_?DAT|UNK)_([0-9A-Fa-f]{8})\b")
FUNCTION_RE = re.compile(r"\bFUN_([0-9A-Fa-f]{8})\b")
NAME_RE = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")


def normalize_address(value: str) -> str:
    value = value.strip().lower()
    if value.startswith("0x"):
        value = value[2:]
    return value.zfill(8)


def load_symbols() -> dict[str, str]:
    mapping: dict[str, str] = {}
    seen_names: dict[str, str] = {}
    with SYMBOLS.open(newline="", encoding="utf-8") as fh:
        for line_number, row in enumerate(csv.DictReader(fh), start=2):
            address = normalize_address(row.get("address") or "")
            name = (row.get("name") or "").strip()
            if not address or not name:
                raise SystemExit(f"{SYMBOLS}:{line_number}: missing address or name")
            if not NAME_RE.match(name):
                raise SystemExit(f"{SYMBOLS}:{line_number}: invalid C identifier {name!r}")
            if address in mapping:
                raise SystemExit(f"{SYMBOLS}:{line_number}: duplicate address {address}")
            if name in seen_names:
                raise SystemExit(
                    f"{SYMBOLS}:{line_number}: duplicate name {name!r} "
                    f"already used by {seen_names[name]}"
                )
            mapping[address] = name
            seen_names[name] = address
    return mapping


def load_function_symbols() -> dict[str, str]:
    mapping: dict[str, str] = {}
    if not FUNCTION_SYMBOLS.exists():
        return mapping
    with FUNCTION_SYMBOLS.open(newline="", encoding="utf-8") as fh:
        for row in csv.DictReader(fh):
            address = normalize_address(row.get("address") or "")
            name = (row.get("name") or "").strip()
            if address and name and not name.startswith("FUN_"):
                mapping[address] = name
    return mapping


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true", help="validate the map only")
    args = parser.parse_args()

    mapping = load_symbols()
    function_mapping = load_function_symbols()
    if args.check:
        print(f"{len(mapping)} data symbols validated")
        print(f"{len(function_mapping)} function symbols loaded")
        return 0

    if DEST.exists():
        shutil.rmtree(DEST)
    DEST.mkdir(parents=True)

    replaced_by_name: collections.Counter[str] = collections.Counter()
    replaced_functions: collections.Counter[str] = collections.Counter()
    files = 0
    remaining = 0
    remaining_functions = 0
    for path in sorted(SOURCE.glob("*.c")):
        text = path.read_text(encoding="utf-8", errors="replace")

        def replace(match: re.Match[str]) -> str:
            address = match.group(1).lower()
            name = mapping.get(address)
            if name is None:
                return match.group(0)
            replaced_by_name[name] += 1
            return name

        def replace_function(match: re.Match[str]) -> str:
            address = match.group(1).lower()
            name = function_mapping.get(address)
            if name is None:
                return match.group(0)
            replaced_functions[name] += 1
            return name

        rendered = ADDRESS_RE.sub(replace, text)
        rendered = FUNCTION_RE.sub(replace_function, rendered)
        remaining += len(ADDRESS_RE.findall(rendered))
        remaining_functions += len(FUNCTION_RE.findall(rendered))
        (DEST / path.name).write_text(rendered, encoding="utf-8")
        files += 1

    total = sum(replaced_by_name.values())
    total_functions = sum(replaced_functions.values())
    print(f"wrote {files} files to {DEST}")
    print(f"replaced {total} data references using {len(mapping)} symbols")
    print(f"replaced {total_functions} function references using {len(function_mapping)} symbols")
    print(f"unnamed DAT_/UNK_ references remaining: {remaining}")
    print(f"unnamed FUN_ references remaining: {remaining_functions}")
    print()
    print("Top applied symbols:")
    for name, count in replaced_by_name.most_common(15):
        print(f"  {name}: {count}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
