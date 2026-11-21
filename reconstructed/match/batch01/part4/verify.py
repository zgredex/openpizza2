#!/usr/bin/env python3
"""Verify every genuine-C batch01/part4 candidate with the official matcher.

The eight naked-assembly transcriptions from the first pass are kept under
`nonmatching/` and are NOT counted as decompiled C (see worklog.md).

Usage: python3 verify.py [address ...]
"""
import json
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[4]
PART = Path(__file__).resolve().parent
MATCHER = ROOT / "tools/match_decomp.py"

# address: (length, entry, flags, [optional --symbol args])
CASES = {
    0x401970: (133, "?Construct@ResourceManager@@QAEPAU1@XZ", "/O2 /TP",
               ["?Construct@NamedLockable@@QAEXPBD@Z=0x401280"]),
    0x477190: (456, "?SpawnWalkInCustomer@Branch@@QAEXXZ", "/O2 /GX /TP", []),
    0x47E930: (255, "?StartConstructionOnPlot@Branch@@QAEXH@Z", "/O2 /GX /TP", []),
    0x498090: (111, "_Mission_CheckGamePlanCategoryGoal", "/O2 /TP",
               ["_g_game=0x57c670", "_g_gamePlan=0x57c9ec",
                "?ComputeCategoryEffect@GamePlan@@QAEHHH@Z=0x50f870",
                "?AppendCommandIfActive@MissionGoal@@QAEXHH@Z=0x503250",
                "?HandleEvent@MissionGoal@@QAEXHHH@Z=0x502f10"]),
    0x49B5F0: (293, "?Menu_BuildUnassignedMenuList@@YAHXZ", "/O2 /GX /TP", []),
    0x4A66D0: (120, "_Personnel_SetEmployeePhotoByKey", "/O2 /TP",
               ["?FindCityIndex@Employee@@QAEHXZ=0x4e2250",
                "_String_Format=0x54dd83",
                "?RemoveObjectByKey@UIObject@@QAEXH@Z=0x531740",
                "?ShowChildByID@UIObject@@QAEXH@Z=0x5316b0",
                "?SetButtonSpriteByName@UIObject@@QAEXHPBD@Z=0x531910"]),
    0x4A80E0: (266, "_Rating_UpdateBarByKey", "/O2 /TP",
               ["_String_Format=0x54dd83", "_g_ratingFormatA=0x580f44",
                "_g_ratingFormatB=0x580f54", "_g_ratingOffsetsA=0x569288",
                "_g_ratingOffsetsB=0x5834d4",
                "?RemoveObjectByKey@UIObject@@QAEXH@Z=0x531740",
                "?ShowChildByID@UIObject@@QAEXH@Z=0x5316b0",
                "?ReleaseChildBufferByKey@UIObject@@QAEXH@Z=0x531f80",
                "?SetObjectTextByKey@UIObject@@QAEXHPBD@Z=0x531f50"]),
    0x4CDED0: (437, "?SubStartMenuA_InitSaveGamePage@@YAXPAX@Z", "/O2 /GX /TP", []),
    0x4DD2E0: (30, "?Delete@GameClock@@QAEPAXE@Z", "/O2 /TP",
               ["?Destroy@GameClock@@QAEXXZ=0x4dd670", "_Mem_Free=0x54dd78"]),
    0x4FBEE0: (459, "?CommitPendingObjectEdits@MapThis@@QAEXPAHD@Z", "/O2 /GX /TP", []),
    0x505E00: (82, "?IsVisibleThisFrame@MapObject@@QAEHXZ", "/O2 /TP",
               ["?UpdateLinkedOverlays@MapActor@@QAEHPAX@Z=0x4f1b60"]),
    0x50F670: (30, "?Delete@GamePlan@@QAEPAXE@Z", "/O2 /TP",
               ["?Destructor@GamePlan@@QAEXXZ=0x50fb30", "_Mem_Free=0x54dd78"]),
    0x52FC00: (191, "?CreateSlider@UI_Manager@@QAEHHHHIPADHH@Z", "/O2 /GX /TP", []),
    0x531C60: (133, "?CreateBitmapGadget@UI_Manager@@QAEPAXHHHIHI@Z", "/O2 /GX /TP", []),
    0x532BF0: (16, "_AnimCritical_Init", "/O2 /TP",
               ["?Construct@NamedLockable@@QAEXPBD@Z=0x401280"]),
    0x53C6E0: (16, "_SpriteCriticalSection_Init", "/O2 /TP",
               ["?Construct@NamedLockable@@QAEXPBD@Z=0x401280"]),
    0x54A610: (30, "?Delete@DebugConsole@@QAEPAXE@Z", "/O2 /TP",
               ["?Destructor@DebugConsole@@QAEXXZ=0x54a630", "_Mem_Free=0x54dd78"]),
}

# Kept as naked instruction transcriptions; not decompiled C.
NONMATCHING = {
    0x4B1A50: "PersonnelPlan_UpdateEmployeeDetail",
    0x4CF380: "CityAdminPanel_UpdateTabButtons",
    0x4D2420: "MapObject_SetTypeAndSprite",
    0x4DC420: "Object_SetSignAndLogoVariant",
    0x4E41C0: "FurnitureType_InitTable",
    0x4EB900: "IsoMap_DeserializeGrid",
    0x4F21E0: "Object_UpdateWalkStep",
    0x523100: "UI_Manager_Construct",
}


def main():
    wanted = {int(a, 0) for a in sys.argv[1:]} if len(sys.argv) > 1 else set(CASES)
    failures = []
    matched = 0
    for address in sorted(CASES):
        if address not in wanted:
            continue
        length, entry, flags, symbols = CASES[address]
        source = PART / f"{address:#x}.c"
        cmd = [sys.executable, str(MATCHER), hex(address), str(source),
               "--length", str(length), "--entry", entry, "--flags", flags]
        for item in symbols:
            cmd += ["--symbol", item]
        result = subprocess.run(cmd, capture_output=True, text=True)
        data = json.loads(result.stdout)
        status = "MATCH" if data.get("match") else "FAIL"
        if data.get("match"):
            matched += 1
        else:
            failures.append(address)
        print(f"{address:#08x} {status} {data.get('first_difference')} "
              f"{data.get('error', '')}".rstrip())
    for address in sorted(NONMATCHING):
        if address in wanted:
            print(f"{address:#08x} UNMATCHED {NONMATCHING[address]} "
                  f"(naked asm in nonmatching/)")
    print(f"genuine C matches: {matched}/{len(wanted & set(CASES))}")
    return 1 if failures else 0


if __name__ == "__main__":
    raise SystemExit(main())
