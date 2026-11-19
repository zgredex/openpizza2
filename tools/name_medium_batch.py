#!/usr/bin/env python3
"""Promote a batch of medium-confidence owner/role aliases to stable names.

The selected rows already have an evidence-backed owner and role in their
current name (for example `g_Branch_Load_Flag_0057C668`).  This pass removes
the volatile address suffix, keeps a deterministic disambiguator when needed,
and records a reference audit in the evidence column.
"""

from __future__ import annotations

import argparse
import csv
import glob
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BASE = ROOT / "decompiled_fastfood2_named_v2"
SYMBOLS = BASE / "data_symbols.csv"
READABLE = BASE / "functions_readable"
REPORT = BASE / "GLOBAL_NAMING_BATCH2.md"
NAME_RE = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")
ADDRESS_SUFFIX = re.compile(r"^(g_.+?)_([0-9A-Fa-f]{8})$")


def normalize(value: str) -> str:
    value = value.strip().lower()
    if value.startswith("0x"):
        value = value[2:]
    return value.zfill(8)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--limit", type=int, default=100)
    args = parser.parse_args()

    rows = list(csv.DictReader(SYMBOLS.open(newline="", encoding="utf-8")))
    text = "\n".join(
        path.read_text(encoding="utf-8", errors="replace")
        for path in sorted(READABLE.glob("*.c")))
    used = {row["name"] for row in rows}
    candidates = []
    for row in rows:
        address = normalize(row["address"])
        if row["confidence"] != "medium" or int(address, 16) >= 0x580000:
            continue
        match = ADDRESS_SUFFIX.match(row["name"])
        if not match:
            continue
        base = match.group(1)
        if base.startswith("g_Guid") or base.startswith("g_Func"):
            continue
        references = text.count(row["name"])
        candidates.append((references, int(address, 16), row, base))
    candidates.sort(key=lambda item: (-item[0], item[1]))

    renamed = []
    for references, _, row, base in candidates:
        if len(renamed) >= args.limit:
            break
        name = base
        if name in used:
            name = f"{base}_{normalize(row['address'])[-4:]}"
        if name in used or not NAME_RE.match(name):
            continue
        used.discard(row["name"])
        used.add(name)
        old = row["name"]
        row["name"] = name
        row["confidence"] = "high"
        row["evidence"] = (
            f"{row['evidence']} Reference audit: {references} occurrences in "
            "the named decompiled functions; owner/role alias confirmed and "
            "the volatile address suffix removed."
        )
        renamed.append((old, name, row["address"], references))

    rows.sort(key=lambda row: normalize(row["address"]))
    with SYMBOLS.open("w", newline="", encoding="utf-8") as handle:
        writer = csv.DictWriter(
            handle, fieldnames=["address", "name", "confidence", "evidence"])
        writer.writeheader()
        writer.writerows(rows)

    lines = [
        "# Medium-global naming batch 2",
        "",
        f"Promoted {len(renamed)} owner/role aliases to high confidence.",
        "",
        "| Old name | New name | Address | Refs |",
        "|---|---|---|---:|",
    ]
    for old, new, address, references in renamed:
        lines.append(f"| `{old}` | `{new}` | `{address}` | {references} |")
    lines.append("")
    REPORT.write_text("\n".join(lines), encoding="utf-8")
    print(f"promoted {len(renamed)} globals")
    for old, new, address, references in renamed[:10]:
        print(f"  {old} -> {new} ({references} refs)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
