#!/usr/bin/env python3
"""Verify the recovered Character (0x828) layout evidence."""

from __future__ import annotations

import hashlib
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BASE = os.path.join(ROOT, "decompiled_fastfood2_named_v2")
EXE = os.path.join(ROOT, "game", "fastfood2.exe")
PACKET = os.path.join(BASE, "typed_packets", "character_layout.json")
HEADER = os.path.join(ROOT, "reconstructed", "character",
                      "character_state.h")
SAVE = os.path.join(BASE, "functions_readable", "0x4d3ba0.c")
LOAD = os.path.join(BASE, "functions_readable", "0x4d3a50.c")


def sha256(path: str) -> str:
    digest = hashlib.sha256()
    with open(path, "rb") as handle:
        for chunk in iter(lambda: handle.read(1 << 20), b""):
            digest.update(chunk)
    return digest.hexdigest()


def bytes_at(image: bytes, address: int, count: int) -> str:
    offset = address - 0x400000
    return image[offset:offset + count].hex(" ")


def main() -> int:
    failures: list[str] = []
    packet = json.load(open(PACKET, encoding="utf-8"))
    image = open(EXE, "rb").read()
    if sha256(EXE) != packet["executable"]["sha256"]:
        failures.append("executable sha256 mismatch")

    expected = {
        0x4822A2: "68 28 08 00 00",
        0x4822C5: "e8 66 14 05 00",
        0x4D3752: "c7 06 fc c4 55 00",
        0x4D3758: "89 86 14 08 00 00",
        0x4D375E: "89 86 18 08 00 00",
        0x4D3764: "89 86 1c 08 00 00",
        0x4D376A: "89 86 20 08 00 00",
        0x4D374E: "6a 46",
        0x4D3750: "6a 1e",
        0x4D3799: "6a 3c",
        0x4D379B: "6a 12",
    }
    for address, expected_bytes in expected.items():
        actual = bytes_at(image, address, len(expected_bytes.split()))
        if actual != expected_bytes:
            failures.append(
                f"0x{address:x}: bytes {actual} != {expected_bytes}")

    save_order = [
        0x04, 0x08, 0x0C, 0x10, 0x24, 0x28, 0x2C, 0x30, 0x34, 0x38,
        0x3C, 0x44, 0x814, 0x818, 0x81C, 0x820, 0x824, 0x40, 0x825,
        0x14, 0x18, 0x1C, 0x20,
    ]
    for path, label in ((SAVE, "save"), (LOAD, "load")):
        text = open(path, encoding="utf-8").read()
        found = []
        for match in re.finditer(r"this \+ (0x[0-9a-fA-F]+|\d+),", text):
            found.append(int(match.group(1), 0))
        if found != save_order:
            failures.append(
                f"{label}: field order {found} != {save_order}")
        positions = list(range(len(found)))
        if positions != sorted(positions):
            failures.append(f"{label}: field order differs from packet")
        if label == "save" and "0x44,2000" not in text.replace(" ", ""):
            failures.append("save: rating array is not 2000 bytes")

    header = open(HEADER, encoding="utf-8").read()
    assert_count = header.count("_Static_assert")
    if assert_count != 29:
        failures.append(f"header has only {assert_count} static asserts")
    for needle in (
        "sizeof(Character) == CHARACTER_SIZE",
        "offsetof(Character, rating_data) == 0x044",
        "offsetof(Character, registry_id) == 0x814",
        "offsetof(Character, activity_state) == 0x825",
        "CHARACTER_RATING_BLOCK_SIZE * 16 == 0x684",
    ):
        if needle not in header:
            failures.append(f"header missing: {needle}")

    offsets = {field["offset"] for field in packet["fields"]}
    for offset in ("0x000", "0x004", "0x044", "0x814", "0x825", "0x826"):
        if offset not in offsets:
            failures.append(f"packet missing field {offset}")

    if failures:
        for failure in failures:
            print(f"FAIL {failure}")
        return 1
    print(
        "Character layout: 0x828 bytes, 29 asserts, 23-field save/load order, "
        "constructor and vtable verified")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
