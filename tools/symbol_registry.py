"""Shared exact COFF symbols with independent PE and inventory evidence."""

from functools import cache
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REGISTRY = ROOT / "reconstructed/match/symbol_registry.json"
CLASSES = ROOT / "decompiled_fastfood2_named_v2/class_skeletons.json"


@cache
def load_registry(executable_sha256):
    payload = json.loads(REGISTRY.read_text())
    if payload.get("schema") != "pc2.symbol_registry.v1":
        raise ValueError(f"unsupported symbol registry schema in {REGISTRY}")
    if payload["executable_sha256"] != executable_sha256:
        return {}
    entries = {}
    for entry in payload["entries"]:
        symbol = entry["symbol"]
        if symbol in entries:
            raise ValueError(f"duplicate exact symbol in registry: {symbol}")
        if (entry["kind"] not in {"function", "vtable", "global", "import"}
                or not symbol or any(char.isspace() for char in symbol)
                or not 0 < int(entry["address"], 16) <= 0xffffffff or not entry["evidence"]):
            raise ValueError(f"invalid symbol registry entry: {symbol}")
        entries[symbol] = entry
    return entries


@cache
def registry_classes(executable_sha256):
    tables = {entry["address"]: entry for entry in load_registry(executable_sha256).values()
              if entry["kind"] == "vtable"}
    if not tables:
        return []
    return [row for row in json.loads(CLASSES.read_text())
            if row["vtable"] in tables and row["class"] == tables[row["vtable"]]["class"]]
