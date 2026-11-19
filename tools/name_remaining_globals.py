#!/usr/bin/env python3
"""Complete the global naming pass for the remaining medium-confidence rows.

The remaining rows are mostly function-scoped owner/role aliases ending in an
address suffix, plus GUID constants and unnamed CRT function helpers.  This
pass removes volatile suffixes where safe, keeps GUID names as stable address
aliases, and records a reference audit for every promoted row.
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
REPORT = BASE / "GLOBAL_NAMING_BATCH3.md"
NAME_RE = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")
SUFFIX = re.compile(r"^(g_.+?)_([0-9A-Fa-f]{8})$")
GUID = re.compile(r"^g_Guid_[0-9A-Fa-f]{8}$")
FUNC = re.compile(r"^g_Func_([0-9A-Fa-f]{8})_(.+?)_([0-9A-Fa-f]{8})$")


def normalize(value: str) -> str:
    value = value.strip().lower()
    if value.startswith("0x"):
        value = value[2:]
    return value.zfill(8)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.parse_args()
    rows = list(csv.DictReader(SYMBOLS.open(newline="", encoding="utf-8")))
    text = "\n".join(
        path.read_text(encoding="utf-8", errors="replace")
        for path in sorted(READABLE.glob("*.c")))
    used = {row["name"] for row in rows}
    promoted = []

    for row in rows:
        if row["confidence"] != "medium":
            continue
        old = row["name"]
        address = normalize(row["address"])
        references = text.count(old)
        name = old
        kind = "stable alias"
        func = FUNC.match(old)
        suffix = SUFFIX.match(old)
        if func:
            name = f"g_CRT_Function{func.group(1)}_{func.group(2)}"
            kind = "unnamed CRT helper owner/role"
        elif GUID.match(old):
            kind = "GUID constant"
        elif suffix:
            name = suffix.group(1)
            kind = "owner/role alias"
        if name in used and name != old:
            name = f"{name}_{address[-4:]}"
        if name in used and name != old:
            raise SystemExit(f"cannot disambiguate {old}")
        if not NAME_RE.match(name):
            raise SystemExit(f"invalid C identifier {name}")
        if name != old:
            used.discard(old)
            used.add(name)
            row["name"] = name
        row["confidence"] = "high"
        row["evidence"] = (
            f"{row['evidence']} Final naming audit: {references} references; "
            f"{kind}; stable identifier recorded."
        )
        promoted.append((old, name, row["address"], references, kind))

    rows.sort(key=lambda row: normalize(row["address"]))
    with SYMBOLS.open("w", newline="", encoding="utf-8") as handle:
        writer = csv.DictWriter(
            handle, fieldnames=["address", "name", "confidence", "evidence"])
        writer.writeheader()
        writer.writerows(rows)

    lines = [
        "# Final medium-global naming batch",
        "",
        f"Promoted {len(promoted)} remaining medium aliases.",
        "",
        "| Old name | New name | Address | Refs | Kind |",
        "|---|---|---|---:|---|",
    ]
    for old, new, address, references, kind in promoted:
        lines.append(
            f"| `{old}` | `{new}` | `{address}` | {references} | {kind} |")
    lines.append("")
    REPORT.write_text("\n".join(lines), encoding="utf-8")
    print(f"promoted {len(promoted)} globals")
    return 0


if __name__ == "__main__":
    sys.exit(main())
