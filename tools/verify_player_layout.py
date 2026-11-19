#!/usr/bin/env python3
"""Verify the recovered Player (0xB0) layout evidence."""

from __future__ import annotations

import hashlib
import json
import os
import re
import struct
import sys

from ldf_tool import read_ldf

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BASE = os.path.join(ROOT, "decompiled_fastfood2_named_v2")
EXE = os.path.join(ROOT, "game", "fastfood2.exe")
LDF = os.path.join(ROOT, "game", "language.ldf")
PACKET = os.path.join(BASE, "typed_packets", "player_layout.json")
HEADER = os.path.join(ROOT, "reconstructed", "player", "player_state.h")
SAVE = os.path.join(BASE, "functions_readable", "0x50ea90.c")
LOAD = os.path.join(BASE, "functions_readable", "0x50eca0.c")
TICK = os.path.join(BASE, "functions_readable", "0x50efe0.c")
RESET = os.path.join(BASE, "functions_readable", "0x50efc0.c")
NEWS = os.path.join(BASE, "functions_readable", "0x4d9780.c")
STRING_TABLE = os.path.join(BASE, "functions_readable", "0x51e650.c")


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
        0x5019D9: "c7 06 60 c6 55 00",
        0x5019FE: "66 89 56 08",
        0x4D988A: "8b 85 88 00 00 00",
        0x4D99C0: "8b 85 88 00 00 00",
        0x50EFC0: "c7 81 84 00 00 00 01 00 00 00 "
                   "c7 81 88 00 00 00 00 00 00 00",
        0x55C684: "c0 e9 50 00",
        0x55C688: "70 f6 50 00",
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

    threshold_tables = {
        0x573054: (25, 50, 100, 150),
        0x573064: (10, 50, 100, 150),
        0x573074: (1, 5, 10, 15),
        0x573084: (2, 4, 6, 8),
        0x573094: (100000, 200000, 300000, 400000),
        0x5730A4: (1, 10, 50, 100),
    }
    for address, expected_values in threshold_tables.items():
        values = struct.unpack_from("<4i", image, address - 0x400000)
        if values != expected_values:
            failures.append(
                f"threshold table 0x{address:x}: {values} != {expected_values}")

    strings = read_ldf(LDF)
    message_expectations = {
        0x2E7: "25 employees",
        0x2EB: "10 attacks",
        0x2EF: "first medal",
        0x2F3: "second restaurant",
        0x2F7: "$100,000",
        0x2FB: "fended off an attack",
    }
    for index, needle in message_expectations.items():
        if needle not in strings[index]:
            failures.append(
                f"language string 0x{index:x}: {strings[index]!r} lacks {needle!r}")

    writer_checks = {
        "0x50c0f0.c": "*(int*)(iVar2+0x38)=*(int*)(iVar2+0x38)+1;",
        "0x50c2e0.c": "*(int*)(iVar2+0x38)=*(int*)(iVar2+0x38)+1;",
        "0x50a580.c": "*(int*)(iVar2+0x38)=*(int*)(iVar2+0x38)+1;",
        "0x50d930.c": "*(int*)(iVar3+0x38)=*(int*)(iVar3+0x38)+1;",
    }
    for name, needle in writer_checks.items():
        text = open(os.path.join(BASE, "functions_readable", name),
                    encoding="utf-8").read().replace(" ", "")
        if needle not in text:
            failures.append(f"{name}: missing attacks_fended_off increment")

    tick_text = open(TICK, encoding="utf-8").read()
    for needle in ("this + 0x38", "005730a4", "Player_CountObjectsByType",
                   "Game_GetPlayerTotalValue", "this + 0xa0", "0x15c"):
        if needle not in tick_text:
            failures.append(f"tick: missing {needle}")

    reset_text = open(RESET, encoding="utf-8").read().replace(" ", "")
    if "*(undefined4*)(param_1+0x84)=1;" not in reset_text:
        failures.append("reset: +0x84 is not written as 1")
    if "*(undefined4*)(param_1+0x88)=0;" not in reset_text:
        failures.append("reset: +0x88 is not written as 0")

    news_text = open(NEWS, encoding="utf-8").read().replace(" ", "")
    if news_text.count("*(int*)(iVar3+0x88)!=0") < 2:
        failures.append("news: award_briefing_enabled is not read twice")
    if "puVar6[1]=1;" not in news_text or "local_14[1]=2;" not in news_text:
        failures.append("news: event types 1/2 are not written")
    contest_text = open(os.path.join(BASE, "functions_readable", "0x4dce70.c"),
                        encoding="utf-8").read().replace(" ", "")
    if "puVar3[1]=0;" not in contest_text:
        failures.append("contest: event type 0 is not written")

    header = open(HEADER, encoding="utf-8").read()
    assert_count = header.count("_Static_assert")
    if assert_count != 25:
        failures.append(f"header has {assert_count} static asserts, expected 25")
    for needle in (
        "sizeof(Player) == PLAYER_SIZE",
        "offsetof(Player, character) == 0x04",
        "offsetof(Player, character_values) == 0x3C",
        "offsetof(Player, attacks_fended_off) == 0x38",
        "offsetof(Player, award_briefing_enabled) == 0x88",
        "offsetof(Player, events) == 0x8C",
        "offsetof(Player, ai_state) == 0xA8",
        "offsetof(PlayerEventList, total_added) == 0x14",
        "sizeof(PlayerEvent) == 0x0C",
        "offsetof(PlayerEvent, event_type) == 0x04",
        "offsetof(PlayerEvent, date_word) == 0x08",
        "PLAYER_EVENT_CITY_PRIZE == 0",
        "PLAYER_EVENT_BEST_RESTAURANT == 1",
        "PLAYER_EVENT_BEST_BUILDING == 2",
    ):
        if needle not in header:
            failures.append(f"header missing: {needle}")

    offsets = {field["offset"] for field in packet["fields"]}
    for offset in ("0x000", "0x004", "0x00C", "0x038", "0x03C", "0x06C",
                   "0x088", "0x08C", "0x0A8", "0x0AC"):
        if offset not in offsets:
            failures.append(f"packet missing field {offset}")
    if "GamePlan" not in packet["vtable"]["next_vtable"]:
        failures.append("packet: vtable boundary is not attributed to GamePlan")
    if [tier["index"] for tier in packet["achievement_tiers"]] != list(range(6)):
        failures.append("packet: achievement tier indices are incomplete")
    if {event["value"] for event in packet["player_event"]["types"]} != {0, 1, 2}:
        failures.append("packet: event type enum is incomplete")

    if failures:
        for failure in failures:
            print(f"FAIL {failure}")
        return 1
    print(
        "Player layout: 0xB0 bytes, 25 asserts, 21-field scalar save/load "
        "order, attacks-fended-off metric, six achievement tiers, event "
        "type enum and vtable boundary verified")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
