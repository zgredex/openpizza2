#!/usr/bin/env python3
"""Apply a curated, evidence-backed batch of global renames.

Each entry records the address, the new name and the evidence that establishes
the role.  Rows are promoted to high confidence.  The script refuses duplicate
names and invalid identifiers, then rewrites data_symbols.csv in address order.
"""

from __future__ import annotations

import csv
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SYMBOLS = ROOT / "decompiled_fastfood2_named_v2" / "data_symbols.csv"
NAME_RE = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")

RENAMES = {
    0x0057B768: (
        "g_FreePlayLogoPermutation",
        "Eight-entry 0..7 permutation; initialized at 0x4050E0 and shuffled before AI profile creation. Record+0xB4 selects LOGOS__%d.spr.",
    ),
    0x0057B76C: (
        "g_FreePlayLogoPermutationValue1",
        "Element 1 of the shuffled logo permutation; Game_GenerateRandomPlayers reads 0x57B76C + 4*i for AI records.",
    ),
    0x0057C258: (
        "g_FreePlayColorPermutation",
        "Eight-entry 0..7 permutation; initialized at 0x4050E0 and shuffled before AI profile creation. Record+0xB8 indexes color table 0x563874.",
    ),
    0x0057C25C: (
        "g_FreePlayColorPermutationValue1",
        "Element 1 of the shuffled color permutation; Game_GenerateRandomPlayers reads 0x57C25C + 4*i for AI records.",
    ),
    0x0057B97C: (
        "g_FreePlayCashMultipliers",
        "Six-dword staging array (record+0x80). Settings_InitDefaults writes 100 via [eax-0x30] with eax=0x57B9AC at 0x406B90; FreePlaySetup_InitWindow reads via [eax-0x18] at 0x4CBEB7.",
    ),
    0x0057B994: (
        "g_FreePlayCharacteristicAdjustments",
        "Six-dword staging array (record+0x84). Settings_InitDefaults zeroes it; FreePlaySetup_InitWindow copies it to record+0x84 at 0x4CBEC3; UI range -6..+6.",
    ),
    0x0057B9AC: (
        "g_FreePlayActiveFlags",
        "Six-dword staging array (record+0xBC). Settings_InitDefaults fills it from the setl flags; FreePlaySetup_InitWindow copies it to record+0xBC at 0x4CBEC8.",
    ),
    0x0057BC58: (
        "g_FreePlayProfiles",
        "Base of six 0xC0-byte player records: +0x00 player name, +0x40 company name, +0x80 settings. SubStartMenu writes names 0x4C7B3B/0x4C7B77; Game_InitScenario consumes records.",
    ),
    0x0057BC98: (
        "g_FreePlayProfile0CompanyName",
        "Record0+0x40 enterprise name; SubStartMenu writes it at 0x4C7B77/0x4C7B87 and FreePlaySetup_InitWindow reads it at 0x4CBD60.",
    ),
    0x0057BCD8: (
        "g_FreePlayProfileSettings",
        "Record0+0x80 settings base used by Game_InitScenario. FreePlaySetup_InitWindow writes record+0x80/+0x84/+0xBC at 0x4CBEBD/0x4CBEC3/0x4CBEC8.",
    ),
    0x0057B8AC: (
        "g_CharacterSelectColorIndex",
        "Persistent character-select color index; CharacterSelect_UpdateScreen copies it to the live value 0x57DD44, SubStartMenu writes the selected color back.",
    ),
    0x0057B8B0: (
        "g_CharacterSelectPhotoIndex",
        "Persistent character-select photo/portrait index; CharacterSelect_UpdateScreen copies it to live value 0x57DDB0, SubStartMenu writes the selected index back.",
    ),
    0x0057B938: (
        "g_CharacterSelectGender",
        "Character-select gender/name selector, Random_RangeFast(0,1). CharacterSelect_UpdateScreen copies it to live portrait gender 0x57DDAC; FreePlaySetup_InitWindow copies it to record+0xA0.",
    ),
    0x0057B93C: (
        "g_CharacterSelectHair",
        "Character-select hair index, range 0..g_AvatarHairCount-1. CharacterSelect_UpdateScreen copies it to live portrait hair 0x57DDA0.",
    ),
    0x0057B940: (
        "g_CharacterSelectEyes",
        "Character-select eye index, range 0..g_AvatarEyeCount-1. CharacterSelect_UpdateScreen copies it to live portrait eyes 0x57DDFC.",
    ),
    0x0057B944: (
        "g_CharacterSelectMouth",
        "Character-select mouth index, range 0..g_AvatarMouthCount-1. CharacterSelect_UpdateScreen copies it to live portrait mouth 0x57DDB8.",
    ),
    0x0057B948: (
        "g_CharacterSelectHead",
        "Character-select head index, range 0..g_AvatarHeadCount-1. CharacterSelect_UpdateScreen copies it to live portrait head 0x57DDA4.",
    ),
    0x0057B94C: (
        "g_CharacterSelectCharacterValueDefaults",
        "Six character-value defaults (Buyer, Gangsters, Specialist, Politicians, Seller, Guard); copied to live values 0x57DD48 and summed at 0x57DDB4.",
    ),
    0x0057DD44: (
        "g_CharacterSelectColorIndexLive",
        "Live character-select color index, copied from 0x57B8AC; CharacterSelect_DrawPortrait and SubStartMenu consume it.",
    ),
    0x0057DD48: (
        "g_CharacterSelectCharacterValues",
        "Live six character values (Buyer/Gangsters/Specialist/Politicians/Seller/Guard); SubStartMenu copies them to profile+0x88..+0x9C at 0x4C7B65.",
    ),
    0x0057DD60: (
        "g_CharacterSelectPlayerName",
        "Live character-select player-name buffer; SubStartMenu copies it to record0+0x00 at 0x4C7B3B/0x4C7B4C.",
    ),
    0x0057DDB0: (
        "g_CharacterSelectPhotoIndexLive",
        "Live character-select photo/portrait index, copied from 0x57B8B0; CharacterSelect_SetPhotoSprite uses it to format PLAYLOG__%d_%02d_00.spr.",
    ),
    0x0057DDAC: (
        "g_CharacterSelectPortraitGender",
        "Live portrait gender copy from 0x57B938; consumed by CharacterSelect_DrawPortrait / UI_DrawOverlaySprites.",
    ),
    0x0057DDA0: (
        "g_CharacterSelectPortraitHair",
        "Live portrait hair copy from 0x57B93C; consumed by CharacterSelect_DrawPortrait.",
    ),
    0x0057DDA4: (
        "g_CharacterSelectPortraitHead",
        "Live portrait head copy from 0x57B948; consumed by CharacterSelect_DrawPortrait.",
    ),
    0x0057DDFC: (
        "g_CharacterSelectPortraitEyes",
        "Live portrait eye copy from 0x57B940; consumed by CharacterSelect_DrawPortrait.",
    ),
    0x0057DDB8: (
        "g_CharacterSelectPortraitMouth",
        "Live portrait mouth copy from 0x57B944; consumed by CharacterSelect_DrawPortrait.",
    ),
    0x0057DDBC: (
        "g_CharacterSelectCompanyName",
        "Live character-select enterprise-name buffer; SubStartMenu copies it to record0+0x40 at 0x4C7B77/0x4C7B87.",
    ),
    0x0058557C: (
        "g_AvatarHairCount",
        "Hair sprite count = min(HAARE_M list count +0x88, HAARE_F +0xA4) in EmployeeAvatar_Construct 0x54B460; range for record+0xA4.",
    ),
    0x00585580: (
        "g_AvatarEyeCount",
        "Eye sprite count = min(AUGEN_M list count +0x50, AUGEN_F +0x6C) in EmployeeAvatar_Construct 0x54B460; range for record+0xA8.",
    ),
    0x00585584: (
        "g_AvatarMouthCount",
        "Mouth sprite count = min(MUND_M list count +0xC0, MUND_F +0xDC) in EmployeeAvatar_Construct 0x54B460; range for record+0xAC.",
    ),
    0x0057B964: (
        "g_FreePlayMissionsEnabled",
        "Free-play missions toggle; FreePlaySetup_InitWindow maps it to option flags bit 2 (0x57BB3C) and button 0x4A3, aligned with label 'Missions' 0x439.",
    ),
    0x0057B968: (
        "g_FreePlayInitialBranchEnabled",
        "Free-play initial-branch toggle; FreePlaySetup_InitWindow maps it to option flags bit 1 (0x57BB3C) and button 0x4A4, aligned with label 'Initial branch' 0x43A.",
    ),
    0x0057B96C: (
        "g_FreePlayStartHQEnabled",
        "Free-play start-HQ toggle; FreePlaySetup_InitWindow maps it to runtime 0x57BB34 and button 0x4A5, aligned with label 'Start HQ:' 0x43B.",
    ),
    0x0057B970: (
        "g_FreePlayMaxHQEnabled",
        "Free-play max-HQ toggle; FreePlaySetup_InitWindow maps it to option flags bit 0 (0x57BB3C) and button 0x4A6, aligned with label 'Max-HQ:' 0x43C.",
    ),
    0x0057BB34: (
        "g_FreePlayStartHQEnabledRuntime",
        "Runtime start-HQ enable flag copied from g_FreePlayStartHQEnabled 0x57B96C; bound to option button 0x4A5.",
    ),
    0x0057BB3C: (
        "g_FreePlayOptionFlags",
        "Runtime mission-option bitfield: bit2=Missions (0x57B964), bit1=Initial branch (0x57B968), bit0=Max-HQ (0x57B970); bound to buttons 0x4A3/0x4A4/0x4A6.",
    ),
    0x0057BCDC: (
        "g_FreePlayProfile0CharacteristicAdjust",
        "Record0+0x84 characteristic adjustment; FreePlaySetup_InitWindow writes it from 0x57B994 at 0x4CBEC3.",
    ),
    0x0057BD0C: (
        "g_FreePlayProfile0Logo",
        "Record0+0xB4 company logo index; Game_InitScenario reads it as the logo for Player 0/Company 0.",
    ),
    0x0057BD10: (
        "g_FreePlayProfile0Color",
        "Record0+0xB8 company color index; Game_InitScenario indexes color table 0x563874 from it.",
    ),
    0x0057BD14: (
        "g_FreePlayProfile0Active",
        "Record0+0xBC active flag; written by FreePlaySetup_InitWindow/Game_InitScenario and tested by the profile loops.",
    ),
    0x0057BD18: (
        "g_FreePlayProfile1PlayerName",
        "Record1+0x00 player-name buffer; Game_GenerateRandomPlayers fills it through the base-0x2a pointer at 0x40523D.",
    ),
    0x0057BD9C: (
        "g_FreePlayProfile1CharacteristicAdjust",
        "Record1+0x84 characteristic adjustment; initialized to 0 for AI players by Game_GenerateRandomPlayers at 0x405220.",
    ),
    0x0057BDC0: (
        "g_FreePlayProfile1Appearance",
        "Record1+0xA8 eye field used as the base pointer for the AI appearance cluster (+0x20..+0x38 relative to the settings half).",
    ),
    0x0057BDCC: (
        "g_FreePlayProfile1Logo",
        "Record1+0xB4 logo index; filled from the shuffled logo permutation by Game_GenerateRandomPlayers.",
    ),
    0x0057BDD4: (
        "g_FreePlayProfile1Active",
        "Record1+0xBC active flag; set to 1 by Game_GenerateRandomPlayers at 0x40525C.",
    ),
    0x0057BE94: (
        "g_FreePlayProfile2Active",
        "Record2+0xBC active flag; cleared by the final AI-profile cleanup loop at 0x405280.",
    ),
    0x0057B974: (
        "g_FreePlayStartHQ",
        "Free-play starting HQ level setting; FreePlaySetup_InitWindow copies it to runtime 0x57BB30 and displays it at control 0x43E (label 'Start HQ:' 0x43B).",
    ),
    0x0057B9C8: (
        "g_FreePlayPopulation",
        "Free-play population setting; FreePlaySetup_InitWindow copies it to runtime 0x57BB28 and drives slider 0x437 (label 'Population' 0x436, range 100..500).",
    ),
    0x0057B9D0: (
        "g_FreePlayMission1Goal",
        "First selected mission goal (settings default); FreePlaySetup_InitWindow copies it to runtime 0x57BB48 and displays it at control 0x483.",
    ),
    0x0057B9D4: (
        "g_FreePlayMission2Goal",
        "Second selected mission goal (settings default); FreePlaySetup_InitWindow copies it to runtime 0x57BB4C and displays it at control 0x486.",
    ),
    0x0057B9D8: (
        "g_FreePlayMission3Goal",
        "Third selected mission goal (settings default); FreePlaySetup_InitWindow copies it to runtime 0x57BB50 and displays it at control 0x489.",
    ),
    0x0057BB24: (
        "g_FreePlayDifficulty",
        "Runtime free-play difficulty 0..10; FreePlaySetup_InitWindow binds it to slider 0x407 and copies it from g_CharacterDifficulty 0x57B8B4.",
    ),
    0x0057BB28: (
        "g_FreePlayPopulationRuntime",
        "Runtime free-play population; copied from g_FreePlayPopulation 0x57B9C8 and bound to slider 0x437 (range 100..500).",
    ),
    0x0057BB2C: (
        "g_FreePlayTimeLimitRuntime",
        "Runtime free-play time limit; copied from g_FreePlayGameLength 0x57B9CC, bound to slider 0x434 as value*10 (range 10..110), label 'Time limit'.",
    ),
    0x0057BB30: (
        "g_FreePlayStartHQRuntime",
        "Runtime start-HQ level copied from g_FreePlayStartHQ 0x57B974; displayed at control 0x43E under 'Start HQ:'.",
    ),
    0x0057BB38: (
        "g_FreePlayMaxHQRuntime",
        "Runtime max-HQ level copied from g_FreePlayMaxHQ 0x57B978; displayed at control 0x43D under 'Max-HQ:'.",
    ),
    0x0057BB40: (
        "g_FreePlaySelectedMission",
        "Selected mission index used by FreePlaySetup_InitWindow NameMap_GetString and by the mission-goal UI; distinct from the three goal slots 0x57BB48/4C/50.",
    ),
    0x0057BB48: (
        "g_FreePlayMissionGoal1",
        "Runtime first mission-goal index; displayed at 0x483 under 'First aim of game:' 0x48B.",
    ),
    0x0057BB4C: (
        "g_FreePlayMissionGoal2",
        "Runtime second mission-goal index; displayed at 0x486 under 'Second aim of game:' 0x48C.",
    ),
    0x0057BB50: (
        "g_FreePlayMissionGoal3",
        "Runtime third mission-goal index; displayed at 0x489 under 'Third aim of game:' 0x48D.",
    ),
    0x00585588: (
        "g_AvatarHeadCount",
        "Head sprite count = min(HEAD_M list count +0x18, HEAD_F +0x34) in EmployeeAvatar_Construct 0x54B460; range for record+0xB0.",
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
    changed = 0

    for address, (name, evidence) in RENAMES.items():
        if not NAME_RE.match(name):
            raise SystemExit(f"invalid identifier {name}")
        key = f"{address:08x}"
        row = by_address.get(key)
        if row is not None:
            used_names.discard(row["name"])
        if name in used_names:
            raise SystemExit(f"duplicate name {name}")
        if row is None:
            row = {"address": f"0x{address:08X}", "name": name,
                   "confidence": "high", "evidence": evidence}
            rows.append(row)
            by_address[key] = row
        else:
            row["name"] = name
            row["confidence"] = "high"
            row["evidence"] = evidence
        used_names.add(name)
        changed += 1

    rows.sort(key=lambda row: normalize(row["address"]))
    with SYMBOLS.open("w", newline="", encoding="utf-8") as handle:
        writer = csv.DictWriter(
            handle, fieldnames=["address", "name", "confidence", "evidence"])
        writer.writeheader()
        writer.writerows(rows)

    print(f"renamed {changed} globals")
    return 0


if __name__ == "__main__":
    sys.exit(main())
