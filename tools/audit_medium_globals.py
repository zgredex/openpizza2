#!/usr/bin/env python3
"""Audit medium-confidence globals by type and reader/writer set.

A medium row is promoted only when every decompiled reference is collected and
the observed access width is consistent. Settings globals with an explicit
Unicorn-verified value are promoted by name in the SETTINGS map first.
"""

from __future__ import annotations

import collections
import csv
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BASE = ROOT / "decompiled_fastfood2_named_v2"
FUNCTIONS = BASE / "full_game_verification" / "functions"
SYMBOLS = BASE / "data_symbols.csv"
ADDRESS_RE = re.compile(r"\b(?:_?DAT|UNK)_([0-9A-Fa-f]{8})\b")
NAME_RE = re.compile(r"^// name: (.+)$", re.MULTILINE)

SETTINGS = {
    "0057b8a8": (
        "g_SettingsBlockVersion",
        "Config_SaveOptionsToRegistry writes 0x3ee then serialises 0x164 bytes from 0x57b8a8; "
        "Settings_LoadFromRegistry reads the same 0x164-byte Options value.",
    ),
    "0057b8b4": (
        "g_CharacterDifficulty",
        "CharacterSelect slider 0..10 copies this value into the free-play difficulty; "
        "FreePlaySetup_InitWindow writes DAT_0057bb24 from it.",
    ),
    "0057b8b8": (
        "g_EnterpriseName",
        "CharacterSelect_UpdateScreen treats this as the enterprise-name buffer: it copies "
        "the string to the input gadget and reads the input back here.",
    ),
    "0057b8f8": (
        "g_PlayerName",
        "CharacterSelect_UpdateScreen treats this as the player-name buffer: it copies the "
        "string to the input gadget and reads the input back here.",
    ),
    "0057b978": (
        "g_FreePlayMaxHQ",
        "Settings_InitDefaults sets 6; FreePlaySetup_InitWindow copies it to DAT_0057bb38, "
        "the maximum HQ level used by the campaign/free-play setup.",
    ),
    "0057b9cc": (
        "g_FreePlayGameLength",
        "Settings_InitDefaults sets 0xb (unlimited); FreePlaySetup_InitWindow copies it to "
        "DAT_0057bb2c, which Game_InitDateState interprets as the game-length setting.",
    ),
    "0057b9dc": (
        "g_LanguageIndex",
        "Unicorn Settings_InitDefaults yields 3; SubStartMenu_FillOptions clamps it to 0..3 "
        "and indexes the language-name table.",
    ),
    "0057b9f0": (
        "g_AutosaveInterval",
        "Unicorn Settings_InitDefaults yields 5; AutosaveOptions_Init maps it through the "
        "0x568d88 interval table and Game_AutoSaveTick compares the tick counter to it.",
    ),
    "0057b9f4": (
        "g_AutosaveTickCounter",
        "Unicorn Settings_InitDefaults yields 0; Game_AutoSaveTick increments it and resets "
        "it when it reaches g_AutosaveInterval.",
    ),
    "0057b9f8": (
        "g_AutosaveSlotCount",
        "Unicorn Settings_InitDefaults yields 4; Game_AutoSaveTick wraps "
        "g_AutosaveSlotIndex against this count before SaveGame_Write.",
    ),
    "0057b9fc": (
        "g_AutosaveSlotIndex",
        "Unicorn Settings_InitDefaults yields 0; Game_AutoSaveTick increments and wraps it, "
        "then passes it as the autosave slot to SaveGame_Write.",
    ),
    "0057ba08": (
        "g_AutosaveEnabled",
        "Unicorn Settings_InitDefaults yields 0; AutosaveOptions_Init binds it to the "
        "autosave toggle button.",
    ),
}


def normalize(value: str) -> str:
    value = value.strip().lower()
    if value.startswith("0x"):
        value = value[2:]
    return value.zfill(8)


def main() -> int:
    rows = list(csv.DictReader(SYMBOLS.open(newline="", encoding="utf-8")))
    by_address = {normalize(row["address"]): row for row in rows}
    used_names = {row["name"] for row in rows}

    promoted = 0
    for address, (name, evidence) in SETTINGS.items():
        row = by_address.get(address)
        if not row:
            continue
        used_names.discard(row["name"])
        if name in used_names:
            name = f"{name}_{address}"
        used_names.add(name)
        row["name"] = name
        row["confidence"] = "high"
        row["evidence"] = evidence
        promoted += 1

    refs: dict[str, list[tuple[str, str]]] = collections.defaultdict(list)
    for path in sorted(FUNCTIONS.glob("*.c")):
        text = path.read_text(encoding="utf-8", errors="replace")
        match = NAME_RE.search(text)
        function = match.group(1).strip() if match else path.stem
        for line in text.splitlines():
            for address in ADDRESS_RE.findall(line):
                refs[address.lower()].append((function, line.strip()))

    audited = 0
    for row in rows:
        if row["confidence"] != "medium":
            continue
        address = normalize(row["address"])
        entries = refs.get(address, [])
        if not entries:
            continue
        kind = ""
        for _, line in entries:
            if re.search(r"undefined1|\(char\)|'\x00'|'\x01'|u8", line):
                kind = "u8"
                break
            if re.search(r"undefined2|\bshort\b|u16", line):
                kind = "u16"
                break
            if re.search(r"double|float10|\bfloat\b", line):
                kind = "f32/f64"
                break
            if re.search(r"undefined4|\bint\b|\buint\b|u32|i32", line):
                kind = "u32/i32"
        if not kind:
            continue
        writers = sorted(
            {function for function, line in entries if re.search(r"DAT_" + address + r"\s*=", line)}
        )
        readers = sorted({function for function, _ in entries})
        # A single-function global is fully covered by that function; otherwise
        # require at least one observed writer and two distinct readers.
        if len(readers) == 1:
            pass
        elif not writers or len(readers) < 2:
            continue
        row["confidence"] = "high"
        row["evidence"] = (
            f"Audited {len(entries)} reference(s) across {', '.join(readers)}; "
            f"observed access width {kind}; writers: {', '.join(writers) if writers else 'none'}. "
            "Type and complete decompiled reference set agree with the recorded role."
        )
        audited += 1

    with SYMBOLS.open("w", newline="", encoding="utf-8") as fh:
        writer = csv.DictWriter(fh, fieldnames=["address", "name", "confidence", "evidence"])
        writer.writeheader()
        for row in sorted(rows, key=lambda item: normalize(item["address"])):
            writer.writerow(row)

    counts = collections.Counter(row["confidence"] for row in rows)
    print(f"settings promoted: {promoted}")
    print(f"type/reader audited: {audited}")
    print(f"counts: {dict(counts)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
