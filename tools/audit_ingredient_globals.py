#!/usr/bin/env python3
"""Audit the ingredient name-pointer table and panel page index.

Language_CopyStringIds(&DAT_00583544, DAT_00582000, 0x56) copies 86 consecutive
language strings into 0x583544..0x58369c.  Ingredient_LoadMarketTable walks the
same 86-entry array and passes entry i to Game_SetBuildingDesc for ingredient
object i.  The first entry is language index 487 (Tomatoes), so the table maps
linearly to indices 487..572.
"""

from __future__ import annotations

import csv
import json
import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BASE = ROOT / "decompiled_fastfood2_named_v2"
SYMBOLS = BASE / "data_symbols.csv"
LDF = ROOT / "game" / "language.ldf"
START = 0x583544
COUNT = 0x56
FIRST_INDEX = 487
SLUG_RE = re.compile(r"[^A-Za-z0-9]+")


def normalize(value: str) -> str:
    value = value.strip().lower()
    if value.startswith("0x"):
        value = value[2:]
    return value.zfill(8)


def main() -> int:
    with tempfile.TemporaryDirectory() as directory:
        output = Path(directory) / "language.json"
        result = subprocess.run(
            [sys.executable, str(ROOT / "tools" / "ldf_tool.py"), "dump", str(LDF), str(output)],
            cwd=ROOT,
            text=True,
            capture_output=True,
        )
        if result.returncode != 0:
            print(result.stdout + result.stderr, file=sys.stderr)
            return 2
        language = json.load(output.open(encoding="utf-8"))

    rows = list(csv.DictReader(SYMBOLS.open(newline="", encoding="utf-8")))
    by_address = {normalize(row["address"]): row for row in rows}
    used_names = {row["name"] for row in rows}

    promoted = 0
    for offset in range(COUNT):
        address = START + offset * 4
        index = FIRST_INDEX + offset
        text = language[index] if index < len(language) else ""
        slug = SLUG_RE.sub("_", text).strip("_")[:26] or "unknown"
        name = f"g_IngredientName_{index:04d}_{slug}"
        if name in used_names:
            name = f"{name}_{address:08x}"
        used_names.add(name)
        row = by_address.get(f"{address:08x}")
        if row is None:
            row = {"address": f"0x{address:08x}"}
            rows.append(row)
        else:
            used_names.discard(row["name"])
        row["name"] = name
        row["confidence"] = "high"
        row["evidence"] = (
            f"Language_CopyStringIds(&DAT_00583544, DAT_00582000, 0x56) fills "
            f"0x583544..0x58369c from language.ldf indices 487..572; entry {offset} "
            f"is index {index} ({text!r}) and Ingredient_LoadMarketTable passes it "
            f"to Game_SetBuildingDesc for ingredient object {offset}."
        )
        promoted += 1

    page = by_address.get("0057ca24")
    if page:
        used_names.discard(page["name"])
        page["name"] = "g_IngredientPanelPageIndex"
        page["confidence"] = "high"
        page["evidence"] = (
            "IngredientPanel_UpdatePage writes iVar3/3 here, uses it as the slider "
            "page value (x100) and passes it to RecipeEditor_InitRecipeRows; two "
            "writers and all reads are in that function."
        )
        promoted += 1

    with SYMBOLS.open("w", newline="", encoding="utf-8") as fh:
        writer = csv.DictWriter(fh, fieldnames=["address", "name", "confidence", "evidence"])
        writer.writeheader()
        for row in sorted(rows, key=lambda item: normalize(item["address"])):
            writer.writerow(row)
    print(f"promoted {promoted} ingredient globals")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
