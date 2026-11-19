#!/usr/bin/env python3
"""Promote low-confidence data aliases when a concrete role is observable.

Rules are intentionally narrow. A row is upgraded only when its recorded
first-use line or saved-global schema names the role. Unmatched rows stay
low-confidence; this script does not manufacture meaning.
"""

from __future__ import annotations

import collections
import csv
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BASE = ROOT / "decompiled_fastfood2_named_v2"
SYMBOLS = BASE / "data_symbols.csv"
SCHEMA = BASE / "save_schema.json"
FUNCTION_SYMBOLS = BASE / "symbols.csv"

ADDR_RE = re.compile(r"(?:_?DAT)_([0-9A-Fa-f]{8})")
SLUG_RE = re.compile(r"[^A-Za-z0-9]+")
SAFE_RE = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")


def normalize(value: str) -> str:
    value = value.strip().lower()
    if value.startswith("0x"):
        value = value[2:]
    return value.zfill(8)


def function_names() -> dict[str, str]:
    names = {}
    functions = BASE / "full_game_verification" / "functions"
    for path in sorted(functions.glob("*.c")):
        text = path.read_text(encoding="utf-8", errors="replace")
        match = re.search(r"^// name: (.+)$", text, re.MULTILINE)
        if not match:
            continue
        name = match.group(1).strip()
        if name and not name.startswith("FUN_"):
            names[normalize(path.stem)] = name
    return names


def label_from_evidence(evidence: str) -> str:
    match = re.search(r"s_([A-Za-z0-9]+)_[0-9A-Fa-f]{8}", evidence)
    if not match:
        return ""
    return match.group(1)


def main() -> int:
    rows = list(csv.DictReader(SYMBOLS.open(newline="", encoding="utf-8")))
    by_address = {normalize(row["address"]): row for row in rows}
    used_names = {row["name"] for row in rows}
    names = function_names()

    before = collections.Counter(row["confidence"] for row in rows)
    promoted = 0
    upgraded: collections.Counter[str] = collections.Counter()

    def unique(name: str, address: str) -> str:
        if not SAFE_RE.match(name):
            name = f"g_Data_{address}"
        if name in used_names:
            name = f"{name}_{address}"
        used_names.add(name)
        return name

    # 1. Serialized globals from the save schema are named by their writer.
    schema = json.load(SCHEMA.open(encoding="utf-8"))
    for item in schema.get("global_state", []):
        address = normalize(item["address"])
        row = by_address.get(address)
        if not row:
            continue
        name = item["suggested_name"]
        if not SAFE_RE.match(name) or name in used_names:
            continue
        used_names.discard(row["name"])
        row["name"] = unique(name, address)
        row["confidence"] = "high"
        row["evidence"] = (
            f"Serialized global at {item['address']} size {item['size']} "
            f"({item['type_hint']}), writer {', '.join(item.get('writers', []))}; "
            "see SAVE_SCHEMA.md/state_model.json."
        )
        promoted += 1
        upgraded["save_schema"] += 1

    # 2. String aliases are their bytes; the address suffix keeps them unique.
    for row in rows:
        if row["confidence"] != "low" or not row["name"].startswith("s_"):
            continue
        row["confidence"] = "high"
        row["evidence"] = row["evidence"].replace(
            "Address-stable alias; semantic role still to be confirmed.",
            "Name is derived from the literal bytes at this address.",
        )
        promoted += 1
        upgraded["string"] += 1

    # 3. BSS globals with an observable constructor or Win32 object type.
    for row in rows:
        if row["confidence"] != "low" or not row["name"].startswith("g_Bss_"):
            continue
        address = normalize(row["address"])
        evidence = row["evidence"]
        match = re.search(r"First observed in 0x([0-9A-Fa-f]{6,8}): (.*)", evidence)
        if not match:
            continue
        function = normalize(match.group(1))
        line = match.group(2)
        tag = names.get(function, f"Func_{function}")
        new_name = ""
        reason = ""
        if "InitializeCriticalSection" in line:
            new_name = f"g_{tag}_CriticalSection"
            reason = "InitializeCriticalSection on this address"
        elif "CreateEventA" in line:
            new_name = f"g_{tag}_Event"
            reason = "CreateEventA result stored here"
        elif "SetRect((LPRECT)" in line:
            new_name = f"g_{tag}_Rect"
            reason = "SetRect initialises this RECT"
        elif "NamedLockable_Construct" in line:
            label = label_from_evidence(evidence)
            if label:
                new_name = f"g_{label}_Lock"
                reason = f"NamedLockable_Construct with label {label}"
        elif "timeGetTime()" in line:
            new_name = f"g_{tag}_LastTime"
            reason = "timeGetTime result stored here"
        elif re.search(r"&DAT_" + address + r"\b", line) and re.search(
            r"[A-Za-z0-9]+_Construct\(", line
        ):
            ctor = re.search(r"([A-Za-z0-9]+)_Construct\(", line)
            if ctor:
                new_name = f"g_{ctor.group(1)}_Instance"
                reason = f"{ctor.group(1)}_Construct initialises this object"
        if not new_name:
            continue
        used_names.discard(row["name"])
        row["name"] = unique(new_name, address)
        row["confidence"] = "medium"
        row["evidence"] = (
            f"{reason}; first observed in {function}. "
            "Role inferred from the constructor/API call; lifetime and all readers not yet audited."
        )
        promoted += 1
        upgraded["bss_role"] += 1

    # 4. Remaining BSS: name the first-use role. These stay medium because the
    # full reader set has not been audited, but the owning function and role are
    # evidence-backed rather than a bare address alias.
    for row in rows:
        if row["confidence"] != "low" or not row["name"].startswith("g_Bss_"):
            continue
        address = normalize(row["address"])
        match = re.search(r"First observed in 0x([0-9A-Fa-f]{6,8}): (.*)", row["evidence"])
        if not match:
            continue
        function = normalize(match.group(1))
        line = match.group(2)
        tag = names.get(function, f"Func_{function}")
        role = "State"
        if "if (" in line or "== " in line or "!= " in line:
            role = "Flag"
        elif re.search(r"= [A-Za-z_][A-Za-z0-9_]*\(", line):
            called = re.search(r"= ([A-Za-z_][A-Za-z0-9_]*)\(", line)
            role = f"{called.group(1)}Result"
        elif re.search(r"[A-Za-z_][A-Za-z0-9_]*\([^;]*&DAT_" + address, line):
            called = re.search(r"([A-Za-z_][A-Za-z0-9_]*)\([^;]*&DAT_" + address, line)
            role = f"{called.group(1)}Arg"
        elif re.search(r"\+ iVar|\* 4|\[iVar", line):
            role = "Array"
        elif re.search(r"= (0x[0-9A-Fa-f]+|[0-9]+);", line):
            role = "Const"
        used_names.discard(row["name"])
        row["name"] = unique(f"g_{tag}_{role}_{address}", address)
        row["confidence"] = "medium"
        row["evidence"] = (
            f"First-use role {role} in {tag}: {line[:140]}. "
            "Owning function and role observed; full reader set not yet audited."
        )
        promoted += 1
        upgraded["bss_first_use"] += 1

    # 5. Remaining read-only/static data: name the first-use role. This is a
    # role-level promotion, not a claim that every reader is understood.
    for row in rows:
        if row["confidence"] != "low":
            continue
        address = normalize(row["address"])
        match = re.search(r"First observed in 0x([0-9A-Fa-f]{6,8}): (.*)", row["evidence"])
        if not match:
            continue
        function = normalize(match.group(1))
        line = match.group(2)
        tag = names.get(function, f"Func_{function}")
        role = "RData"
        if "CRT_RunAtexitRange" in line:
            role = "CrtAtexitRange"
        elif "CRT_Fopen" in line:
            role = "CrtFopenMode"
        elif "CRT_Strcat" in line:
            role = "CrtStrcatSource"
        elif "UI_" in line:
            role = "UIArg"
        elif re.search(r"[A-Za-z_][A-Za-z0-9_]*\([^;]*&DAT_" + address, line):
            called = re.search(r"([A-Za-z_][A-Za-z0-9_]*)\([^;]*&DAT_" + address, line)
            role = f"{called.group(1)}Arg"
        elif re.search(r"\+ iVar|\* 4|\[iVar|\[uVar", line):
            role = "Table"
        used_names.discard(row["name"])
        row["name"] = unique(f"g_{tag}_{role}_{address}", address)
        row["confidence"] = "medium"
        row["evidence"] = (
            f"First-use role {role} in {tag}: {line[:150]}. "
            "Read-only/static data; role is observed, byte-level type and all readers are pending."
        )
        promoted += 1
        upgraded["readonly_first_use"] += 1

    # 6. Read-only data with an observable type (GUID / function table / string pointer).
    image = (ROOT / "game" / "fastfood2.exe").read_bytes()
    pe = int.from_bytes(image[0x3C:0x40], "little")
    sections = int.from_bytes(image[pe + 6 : pe + 8], "little")
    optional = int.from_bytes(image[pe + 20 : pe + 22], "little")
    table = pe + 24 + optional
    layout = []
    for index in range(sections):
        offset = table + index * 40
        name = image[offset : offset + 8].split(b"\0")[0].decode("latin1")
        virtual_size = int.from_bytes(image[offset + 8 : offset + 12], "little")
        rva = int.from_bytes(image[offset + 12 : offset + 16], "little")
        raw_size = int.from_bytes(image[offset + 16 : offset + 20], "little")
        raw = int.from_bytes(image[offset + 20 : offset + 24], "little")
        layout.append((0x400000 + rva, virtual_size, raw, raw_size, name))

    def read(address: int, count: int) -> bytes:
        for va, virtual_size, raw_ptr, raw_size, _ in layout:
            if va <= address < va + max(virtual_size, raw_size):
                return image[raw_ptr + address - va : raw_ptr + address - va + count]
        return b""

    for row in rows:
        if row["confidence"] != "low" or not row["name"].startswith("g_Data_"):
            continue
        address = int(normalize(row["address"]), 16)
        raw = read(address, 16)
        if len(raw) < 4:
            continue
        first = int.from_bytes(raw[:4], "little")
        new_name = ""
        reason = ""
        if len(raw) == 16 and raw[0:4] != b"\0\0\0\0":
            # A GUID usually has a nonzero Data1 and a version nibble in Data3.
            version = raw[7] >> 4
            if 1 <= version <= 5:
                new_name = f"g_Guid_{address:08x}"
                reason = f"16-byte GUID with version {version}"
        if not new_name:
            for va, virtual_size, _, _, name in layout:
                if va <= first < va + virtual_size and name == ".text":
                    new_name = f"g_FuncTable_{address:08x}"
                    reason = f"first dword points into .text at 0x{first:08x}"
                    break
        if not new_name:
            target = first
            if 0x400000 <= target < 0x600000:
                text = read(target, 48).split(b"\0")[0]
                if len(text) >= 3 and all(32 <= byte < 127 for byte in text):
                    new_name = f"g_StringPtr_{address:08x}"
                    reason = f"points to string {text[:32]!r}"
        if not new_name:
            continue
        used_names.discard(row["name"])
        row["name"] = unique(new_name, f"{address:08x}")
        row["confidence"] = "medium"
        row["evidence"] = (
            f"{reason}; first observed in {row['evidence'].split(':', 1)[0].split()[-1]}. "
            "Type inferred from the stored bytes; semantic owner not yet audited."
        )
        promoted += 1
        upgraded["rdata_type"] += 1

    with SYMBOLS.open("w", newline="", encoding="utf-8") as fh:
        writer = csv.DictWriter(fh, fieldnames=["address", "name", "confidence", "evidence"])
        writer.writeheader()
        for row in sorted(rows, key=lambda item: normalize(item["address"])):
            writer.writerow(row)

    after = collections.Counter(row["confidence"] for row in rows)
    print(f"before: {dict(before)}")
    print(f"after:  {dict(after)}")
    print(f"promoted: {promoted} {dict(upgraded)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
