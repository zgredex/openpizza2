#!/usr/bin/env python3
"""Summarize recovered object-layout coverage and remaining gaps."""

from __future__ import annotations

import collections
import glob
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BASE = ROOT / "decompiled_fastfood2_named_v2"
STRUCTS = BASE / "game_structs.h"
CLASSES = BASE / "class_skeletons.json"
SAVE = BASE / "save_schema.json"


def main() -> int:
    text = STRUCTS.read_text(encoding="utf-8")
    structs = re.findall(r"typedef struct (\w+) \{(.*?)\} \1;", text, re.S)
    fields = 0
    save_fields = 0
    observed_only = 0
    for _, body in structs:
        for line in body.splitlines():
            if ";" not in line or "/*" not in line:
                continue
            fields += 1
            if "save#" in line:
                save_fields += 1
            if "observed-only" in line:
                observed_only += 1

    classes = json.loads(CLASSES.read_text(encoding="utf-8"))
    class_fields = sum(len(item.get("fields", {})) for item in classes)
    corroborated = sum(
        1 for item in classes for field in item.get("fields", {}).values()
        if field.get("hits", 0) >= 2)
    no_fields = sum(1 for item in classes if not item.get("fields"))

    save = json.loads(SAVE.read_text(encoding="utf-8"))
    counts = save.get("counts", {})

    asserts = collections.Counter()
    for path in glob.glob(str(ROOT / "reconstructed/**/*.[ch]"), recursive=True):
        count = Path(path).read_text(encoding="utf-8", errors="replace").count(
            "_Static_assert")
        if count:
            asserts[str(Path(path).relative_to(ROOT))] = count

    allocations = []
    for path in glob.glob(str(BASE / "functions_readable/*.c")):
        data = Path(path).read_text(encoding="utf-8", errors="replace")
        for match in re.finditer(r"operator_new\((0x[0-9a-fA-F]+|\d+)\)", data):
            allocations.append(int(match.group(1), 0))

    print("# Object-layout coverage")
    print()
    print("## What is recovered")
    print()
    print(f"- Class skeletons with vtables: {len(classes)}")
    print(f"- Observed field offsets in class skeletons: {class_fields}")
    print(f"- Field offsets corroborated by at least two functions: {corroborated}")
    print(f"- Skeleton classes without field records: {no_fields}")
    print(f"- Typed offset structs in game_structs.h: {len(structs)}")
    print(f"- Fields in game_structs.h: {fields} "
          f"({save_fields} serialized, {observed_only} observed-only)")
    print(f"- Save functions: {counts.get('save_functions', 0)}")
    print(f"- Serialized fields: {counts.get('serialized_fields', 0)}")
    print(f"- Exact save/load pairs: {counts.get('exact_save_load_pairs', 0)}")
    print(f"- Allocation sites: {len(allocations)} "
          f"({len(set(allocations))} distinct sizes)")
    print()
    print("## Static layout checks")
    print()
    print("| File | Asserts |")
    print("|---|---:|")
    for path, count in sorted(asserts.items()):
        print(f"| `{path}` | {count} |")
    print(f"| **Total** | **{sum(asserts.values())}** |")
    print()
    print("## Remaining gaps")
    print()
    print("- `game_structs.h` is still a structural skeleton: every field is "
          "`field_0xNN` or padding, and 743 of 1083 are observed-only.")
    print("- The large gameplay objects (Game 194704 bytes, City, Company, "
          "Branch, Player, Character 0x828, Window, Dialog) do not yet have "
          "C structs with complete static asserts.")
    print("- 1001 class-skeleton field offsets have fewer than two observing "
          "functions; vtable slot semantics are not fully named.")
    print("- 63 distinct allocation sizes exist; only a small subset is tied "
          "to a reconstructed struct and constructor.")
    print("- The save schema pairs 31 owners exactly, but 7 other save owners "
          "have a different or missing load path.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
