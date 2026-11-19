#!/usr/bin/env python3
"""Measure how much of the shipped executable has human-readable names.

The metric is deliberately mechanical so it can be tracked over time:

* function coverage: decompiled function files whose header name is not FUN_*;
* data coverage: unique DAT_*/UNK_* addresses referenced by the decompiled
  pseudocode that have an evidence-backed entry in data_symbols.csv;
* reference coverage: the share of DAT_* references that resolve to a name.

This says nothing about behavioral correctness.  A symbol only counts when it
has an entry in data_symbols.csv with evidence, so guessing names cannot raise
the score.
"""

from __future__ import annotations

import argparse
import collections
import csv
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BASE = ROOT / "decompiled_fastfood2_named_v2"
FUNCTIONS = BASE / "full_game_verification" / "functions"
SYMBOLS = BASE / "symbols.csv"
DATA_SYMBOLS = BASE / "data_symbols.csv"

NAME_RE = re.compile(r"^// name: (.+)$", re.MULTILINE)
DAT_RE = re.compile(r"\bDAT_([0-9A-Fa-f]{8})\b")
UNK_RE = re.compile(r"\bUNK_([0-9A-Fa-f]{8})\b")
FUN_RE = re.compile(r"\bFUN_([0-9A-Fa-f]{8})\b")


def load_function_names() -> dict[str, str]:
    names: dict[str, str] = {}
    if not SYMBOLS.exists():
        return names
    with SYMBOLS.open(newline="", encoding="utf-8") as fh:
        for row in csv.DictReader(fh):
            address = (row.get("address") or "").strip().lower()
            name = (row.get("name") or "").strip()
            if address and name:
                names[address] = name
    return names


def normalize_address(value: str) -> str:
    value = value.strip().lower()
    if value.startswith("0x"):
        value = value[2:]
    return value.zfill(8)


def load_data_names() -> dict[str, dict[str, str]]:
    names: dict[str, dict[str, str]] = {}
    if not DATA_SYMBOLS.exists():
        return names
    with DATA_SYMBOLS.open(newline="", encoding="utf-8") as fh:
        for row in csv.DictReader(fh):
            address = normalize_address(row.get("address") or "")
            name = (row.get("name") or "").strip()
            if address and name:
                names[address] = row
    return names


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--json", action="store_true", help="emit machine-readable JSON")
    parser.add_argument("--top", type=int, default=25, help="largest unnamed globals to show")
    args = parser.parse_args()

    function_names = load_function_names()
    data_names = load_data_names()

    data_refs: collections.Counter[str] = collections.Counter()
    fun_refs: collections.Counter[str] = collections.Counter()
    function_files = 0
    named_functions = 0
    unnamed_examples: list[str] = []

    for path in sorted(FUNCTIONS.glob("*.c")):
        function_files += 1
        text = path.read_text(encoding="utf-8", errors="replace")
        match = NAME_RE.search(text)
        header_name = match.group(1).strip() if match else ""
        stem = path.stem.lower()
        symbol_name = function_names.get(stem, "")
        name = header_name or symbol_name
        if name and not name.startswith("FUN_"):
            named_functions += 1
        elif len(unnamed_examples) < 10:
            unnamed_examples.append(f"{stem} {name or '<missing>'}")

        for address in DAT_RE.findall(text):
            data_refs[address.lower()] += 1
        for address in UNK_RE.findall(text):
            data_refs[address.lower()] += 1
        for address in FUN_RE.findall(text):
            fun_refs[address.lower()] += 1

    total_data_refs = sum(data_refs.values())
    named_data_refs = sum(count for address, count in data_refs.items() if address in data_names)
    named_data_addresses = sum(1 for address in data_refs if address in data_names)
    unresolved = [
        (address, count)
        for address, count in data_refs.most_common()
        if address not in data_names
    ]

    result = {
        "function_files": function_files,
        "named_functions": named_functions,
        "function_coverage_percent": round(100 * named_functions / max(function_files, 1), 2),
        "unique_data_addresses": len(data_refs),
        "named_data_addresses": named_data_addresses,
        "data_address_coverage_percent": round(
            100 * named_data_addresses / max(len(data_refs), 1), 2
        ),
        "total_data_references": total_data_refs,
        "named_data_references": named_data_refs,
        "data_reference_coverage_percent": round(
            100 * named_data_refs / max(total_data_refs, 1), 2
        ),
        "unique_unresolved_function_targets": len(
            [address for address in fun_refs if address not in function_names]
        ),
        "unnamed_examples": unnamed_examples,
        "top_unresolved_data": [
            {"address": f"0x{address}", "references": count}
            for address, count in unresolved[: args.top]
        ],
    }

    if args.json:
        print(json.dumps(result, indent=2))
        return 0

    print("# Symbol coverage")
    print()
    print(f"- Function files: {result['function_files']}")
    print(
        f"- Named functions: {result['named_functions']} "
        f"({result['function_coverage_percent']}%)"
    )
    print(f"- Unique data addresses referenced: {result['unique_data_addresses']}")
    print(
        f"- Named data addresses: {result['named_data_addresses']} "
        f"({result['data_address_coverage_percent']}%)"
    )
    print(
        f"- Data references resolved: {result['named_data_references']}/"
        f"{result['total_data_references']} "
        f"({result['data_reference_coverage_percent']}%)"
    )
    print()
    print("## Largest unnamed globals")
    print()
    print("| Address | References |")
    print("|---|---:|")
    for item in result["top_unresolved_data"]:
        print(f"| `{item['address']}` | {item['references']} |")
    return 0


if __name__ == "__main__":
    sys.exit(main())
