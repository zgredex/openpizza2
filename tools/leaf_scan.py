#!/usr/bin/env python3
"""Rank remaining leaf functions for the ongoing reversal pass.

A leaf is a game-code function with no calls to another local function (imports
and CRT calls do not count in callgraph.json). Names from leaf_symbols.csv and
the decompile index are treated as already identified.
"""

from __future__ import annotations

import argparse
import csv
import json
from pathlib import Path


def load_symbols(path: str | None) -> dict[str, str]:
    if not path:
        return {}
    with open(path, newline="", encoding="utf-8") as fh:
        return {r["address"]: r["name"] for r in csv.DictReader(fh)}


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("callgraph", help="callgraph.json from the REA export")
    ap.add_argument("index", help="decompile-index.json")
    ap.add_argument("--symbols", help="leaf_symbols.csv with already-chosen names")
    ap.add_argument("--extra-index", action="append", help="additional decompile-index.json")
    ap.add_argument("--limit", type=int, default=40)
    ap.add_argument("--min-bytes", type=int, default=40)
    ap.add_argument("--all", action="store_true", help="include already named leaves")
    args = ap.parse_args()

    graph = json.loads(Path(args.callgraph).read_text(encoding="utf-8"))["nodes"]
    index = {
        f["address"]: f["name"]
        for f in json.loads(Path(args.index).read_text(encoding="utf-8"))["functions"]
    }
    for path in args.extra_index or []:
        for f in json.loads(Path(path).read_text(encoding="utf-8"))["functions"]:
            if not f["name"].startswith(("FUN_", "thunk_", "Unwind")):
                index[f["address"]] = f["name"]
    extra = load_symbols(args.symbols)
    rows = []
    for addr, node in graph.items():
        value = int(addr, 16)
        if node["calls"] or not (0x401000 <= value < 0x555590):
            continue
        if node["bytes"] < args.min_bytes:
            continue
        name = extra.get(addr) or index.get(addr) or node.get("name") or ""
        known = name and not name.startswith(("FUN_", "thunk_", "Unwind"))
        if known and not args.all:
            continue
        rows.append((node.get("indegree", 0), node["bytes"], addr, name or "?"))
    rows.sort(key=lambda r: (-r[0], -r[1]))
    print(f"{'in':>4} {'bytes':>6}  address    name")
    for indeg, size, addr, name in rows[: args.limit]:
        print(f"{indeg:4d} {size:6d}  {addr:10s} {name}")
    print(f"\n{len(rows)} remaining leaves (limit {args.limit})")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
