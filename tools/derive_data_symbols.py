#!/usr/bin/env python3
"""Derive evidence-backed names for the remaining DAT_/UNK_ references.

Two passes:

1. Language aliases: Language_MapStrings (0x5146d0) assigns a known
   language.ldf string to a global. Those globals get a semantic
   ``g_Text_<index>_<slug>`` name.
2. Address aliases: any remaining referenced global gets a stable, unique
   identifier derived from its PE section and bytes (``s_*`` for strings,
   ``g_FuncTable_*`` for pointer tables, ``g_Bss_*`` for zero-initialised
   state, ``g_Data_*`` otherwise). The evidence column records the first
   referencing function and the exact use. These aliases remove raw DAT_
   tokens without pretending the semantic role is known.
"""

from __future__ import annotations

import collections
import csv
import json
import os
import re
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BASE = ROOT / "decompiled_fastfood2_named_v2"
FUNCTIONS = BASE / "full_game_verification" / "functions"
SYMBOLS = BASE / "data_symbols.csv"
LANGUAGE_MAP = FUNCTIONS / "0x5146d0.c"
EXE = ROOT / "game" / "fastfood2.exe"
LDF = ROOT / "game" / "language.ldf"
ADDRESS_RE = re.compile(r"\b(?:_?DAT|UNK)_([0-9A-Fa-f]{8})\b")
MAP_RE = re.compile(
    r"^\s*(?:_?DAT)_([0-9A-Fa-f]{8})\s*=\s*\*?\s*(?:DAT_00580ad4|g_LanguageStrings)\[([0-9A-Fa-fx]+)\]\s*;"
)
SLUG_RE = re.compile(r"[^A-Za-z0-9]+")


def normalize(value: str) -> str:
    value = value.strip().lower()
    if value.startswith("0x"):
        value = value[2:]
    return value.zfill(8)


def load_existing() -> dict[str, dict[str, str]]:
    rows: dict[str, dict[str, str]] = {}
    if not SYMBOLS.exists():
        return rows
    with SYMBOLS.open(newline="", encoding="utf-8") as fh:
        for row in csv.DictReader(fh):
            address = normalize(row.get("address") or "")
            if address:
                rows[address] = row
    return rows


def pe_layout() -> tuple[bytes, list[tuple[int, int, int, int, str]]]:
    image = EXE.read_bytes()
    pe = struct.unpack_from("<I", image, 0x3C)[0]
    sections = struct.unpack_from("<H", image, pe + 6)[0]
    optional_size = struct.unpack_from("<H", image, pe + 20)[0]
    table = pe + 24 + optional_size
    layout = []
    for index in range(sections):
        offset = table + index * 40
        name = image[offset : offset + 8].split(b"\0")[0].decode("latin1")
        virtual_size, rva, raw_size, raw_ptr = struct.unpack_from("<IIII", image, offset + 8)
        layout.append((0x400000 + rva, virtual_size, raw_ptr, raw_size, name))
    return image, layout


def read_bytes(image: bytes, layout, address: int, count: int) -> bytes:
    for va, virtual_size, raw_ptr, raw_size, _ in layout:
        if va <= address < va + max(virtual_size, raw_size):
            offset = raw_ptr + (address - va)
            return image[offset : offset + count]
    return b""


def address_kind(image: bytes, layout, address: int) -> tuple[str, str]:
    raw = read_bytes(image, layout, address, 64)
    if raw:
        text = raw.split(b"\0")[0]
        if len(text) >= 3 and all(32 <= byte < 127 for byte in text):
            slug = SLUG_RE.sub("_", text.decode("latin1")).strip("_")[:24]
            return f"s_{slug}_{address:08x}", f"file bytes decode to {text[:48]!r}"
        first = struct.unpack_from("<I", raw, 0)[0]
        for va, virtual_size, _, _, name in layout:
            if va <= first < va + virtual_size:
                if name == ".text":
                    return (
                        f"g_FuncTable_{address:08x}",
                        f"first dword 0x{first:08x} points into .text",
                    )
                return (
                    f"g_DataPtr_{address:08x}",
                    f"first dword 0x{first:08x} points into {name}",
                )
    for va, virtual_size, _, raw_size, name in layout:
        if va <= address < va + virtual_size:
            if name == ".data" and address - va >= raw_size:
                return f"g_Bss_{address:08x}", "zero-initialised .data tail (BSS)"
            return f"g_Data_{address:08x}", f"mapped in {name}"
    return f"g_Unmapped_{address:08x}", "not mapped by the PE image"


def main() -> int:
    existing = load_existing()
    image, layout = pe_layout()

    with tempfile.TemporaryDirectory() as directory:
        lang_json = os.path.join(directory, "language.json")
        result = subprocess.run(
            [sys.executable, str(ROOT / "tools" / "ldf_tool.py"), "dump", str(LDF), lang_json],
            cwd=ROOT,
            text=True,
            capture_output=True,
        )
        if result.returncode != 0:
            print(result.stdout + result.stderr, file=sys.stderr)
            return 2
        language = json.load(open(lang_json, encoding="utf-8"))

    # First pass: language aliases.
    used_names = {row["name"] for row in existing.values()}
    language_rows = 0
    for line in LANGUAGE_MAP.read_text(encoding="utf-8", errors="replace").splitlines():
        match = MAP_RE.match(line)
        if not match:
            continue
        address = normalize(match.group(1))
        if address in existing:
            continue
        index = int(match.group(2), 0)
        text = language[index] if 0 <= index < len(language) else ""
        slug = SLUG_RE.sub("_", text).strip("_")[:26] or "empty"
        name = f"g_Text_{index:04d}_{slug}"
        if name in used_names:
            name = f"{name}_{address}"
        used_names.add(name)
        existing[address] = {
            "address": f"0x{address}",
            "name": name,
            "confidence": "high",
            "evidence": (
                "Language_MapStrings (0x5146d0) assigns "
                f"g_LanguageStrings[{index}] (language.ldf text {text[:64]!r})."
            ),
        }
        language_rows += 1

    # Second pass: resolve every remaining referenced address.
    first_use: dict[str, tuple[str, str]] = {}
    for path in sorted(FUNCTIONS.glob("*.c")):
        text = path.read_text(encoding="utf-8", errors="replace")
        function = path.stem
        for line in text.splitlines():
            for address in ADDRESS_RE.findall(line):
                address = address.lower()
                if address not in existing and address not in first_use:
                    first_use[address] = (function, line.strip()[:180])

    fallback_rows = 0
    for address, (function, snippet) in sorted(first_use.items()):
        name, kind_evidence = address_kind(image, layout, int(address, 16))
        if name in used_names:
            name = f"{name}_{address}"
        used_names.add(name)
        existing[address] = {
            "address": f"0x{address}",
            "name": name,
            "confidence": "low",
            "evidence": (
                f"First observed in {function}: {snippet} | {kind_evidence}. "
                "Address-stable alias; semantic role still to be confirmed."
            ),
        }
        fallback_rows += 1

    rows = [existing[key] for key in sorted(existing)]
    with SYMBOLS.open("w", newline="", encoding="utf-8") as fh:
        writer = csv.DictWriter(fh, fieldnames=["address", "name", "confidence", "evidence"])
        writer.writeheader()
        for row in rows:
            writer.writerow(
                {
                    "address": row["address"],
                    "name": row["name"],
                    "confidence": row["confidence"],
                    "evidence": row["evidence"],
                }
            )

    print(f"language aliases added: {language_rows}")
    print(f"address aliases added:  {fallback_rows}")
    print(f"total data symbols:     {len(rows)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
