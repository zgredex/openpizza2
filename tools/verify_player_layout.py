#!/usr/bin/env python3
"""Verify the recovered Player (0xB0) layout evidence."""

from __future__ import annotations

import hashlib
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BASE = os.path.join(ROOT, "decompiled_fastfood2_named_v2")
EXE = os.path.join(ROOT, "game", "fastfood2.exe")
PACKET = os.path.join(BASE, "typed_packets", "player_layout.json")
HEADER = os.path.join(ROOT, "reconstructed", "player", "player_state.h")
SAVE = os.path.join(BASE, "functions_readable", "0x50ea90.c")
LOAD = os.path.join(BASE, "functions_readable", "0x50eca0.c")


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
        0x4820C7: "68 b0 00 00 00",
        0x4820E8: "e8 f3 c7 08 00",
        0x50E907: "e8 94 2a ef ff",
        0x50E916: "c7 06 84 c6 55 00",
        0x50E941: "89 86 84 00 00 00",
        0x50E947: "89 86 88 00 00 00",
        0x50E957: "c7 46 08 ff ff ff ff",
        0x50E95E: "89 5e 3c",
        0x50E982: "89 5e 2c",
        0x50E98E: "89 5e 34",
        0x50E994: "89 9e a8 00 00 00",
        0x50E99A: "89 9e ac 00 00 00",
    }
    for address, expected_bytes in expected.items():
        actual = bytes_at(image, address, len(expected_bytes.split()))
        if actual != expected_bytes:
            failures.append(
                f"0x{address:x}: bytes {actual} != {expected_bytes}")

    scalar_order = [
        0x84, 0x88, 0x08, 0x0C, 0x2C, 0x30, 0x3C, 0x40, 0x44, 0x48,
        0x4C, 0x50, 0x54, 0x58, 0x5C, 0x60, 0x64, 0x68, 0x6C, 0x34,
        0x38,
    ]
    for path, label in ((SAVE, "save"), (LOAD, "load")):
        text = open(path, encoding="utf-8").read()
        found = []
        for match in re.finditer(r"\(int\)(?:this|this_00) \+ (0x[0-9a-fA-F]+|\d+),", text):
            found.append(int(match.group(1), 0))
        if found != scalar_order:
            failures.append(f"{label}: field order {found} != {scalar_order}")
        compact = text.replace(" ", "")
        if label == "save" and "this+0xc,0x20" not in compact:
            failures.append("save: player name is not 0x20 bytes")
        if label == "save" and "this+0x6c,0x18" not in compact:
            failures.append("save: field_6c is not 0x18 bytes")
        if label == "save" and "Character_Save(*(void**)((int)this+4)" not in compact:
            failures.append("save: missing Character_Save pointer")
        if label == "load" and "Character_StreamConstruct" not in text:
            failures.append("load: missing Character_StreamConstruct")

    header = open(HEADER, encoding="utf-8").read()
    assert_count = header.count("_Static_assert")
    if assert_count != 19:
        failures.append(f"header has {assert_count} static asserts, expected 19")
    for needle in (
        "sizeof(Player) == PLAYER_SIZE",
        "offsetof(Player, character) == 0x04",
        "offsetof(Player, character_values) == 0x3C",
        "offsetof(Player, events) == 0x8C",
        "offsetof(Player, ai_state) == 0xA8",
        "offsetof(PlayerEventList, total_added) == 0x14",
    ):
        if needle not in header:
            failures.append(f"header missing: {needle}")

    offsets = {field["offset"] for field in packet["fields"]}
    for offset in ("0x000", "0x004", "0x00C", "0x03C", "0x08C", "0x0A8",
                   "0x0AC"):
        if offset not in offsets:
            failures.append(f"packet missing field {offset}")

    if failures:
        for failure in failures:
            print(f"FAIL {failure}")
        return 1
    print(
        "Player layout: 0xB0 bytes, 19 asserts, 21-field scalar save/load "
        "order, Character pointer, event list and vtable verified")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
