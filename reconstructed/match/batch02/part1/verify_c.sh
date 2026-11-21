#!/bin/sh
# Re-run the byte match for every genuine C/C++ match of batch02/part1.
# /TP is used only for the functions whose original code is a C++ member
# function or thiscall call (MT/CT/CTHUNK-style this pointers); the rest are
# plain C with /O2.
# Usage: sh reconstructed/match/batch02/part1/verify_c.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
fail=0
check() {
    address=$1; length=$2; source=$3; shift 3
    if $M "$address" "$source" --length "$length" "$@" >/tmp/part1-match.json 2>&1; then
        echo "MATCH $address"
    else
        echo "FAIL  $address"
        cat /tmp/part1-match.json
        fail=1
    fi
}
D=reconstructed/match/batch02/part1

check 0x401300 17 $D/0x401300.c --entry '@NamedLockable_Destroy@4'
check 0x4029d0 10 $D/0x4029d0.c --entry '_Resource_GetSize@4'
check 0x403190 9 $D/0x403190.c --entry '@Clear_Ptr@4'
check 0x403d40 8 $D/0x403d40.c --entry '@Input_LeaveLock@4'
check 0x403d60 13 $D/0x403d60.c --flags "/O2 /TP" \
  --entry '?MissionBriefing_InitList@@YAXXZ'
check 0x47ee50 15 $D/0x47ee50.c --entry '@Branch_InvalidateRatingCache@4'
check 0x480060 14 $D/0x480060.c --flags "/O2 /TP" \
  --entry '?Game_UpdateFreeBuildingCount@@YIXPAD@Z'
check 0x4800c0 14 $D/0x4800c0.c --flags "/O2 /TP" \
  --entry '?Game_CountFreeBuildingsTypeD@@YIXPAD@Z'
check 0x482710 14 $D/0x482710.c --entry '_Game_GetGlobalTableValue@4'
check 0x482810 16 $D/0x482810.c --flags "/O2 /TP" \
  --entry '?RegisterObject@Game@@QAEXPAX@Z'
check 0x482880 13 $D/0x482880.c --flags "/O2 /TP" \
  --entry '?Game_DestroyRootWindow@@YIXPAUGame@@@Z'
check 0x482910 17 $D/0x482910.c --entry '@Game_GetActiveScreenOrFallback@4'
check 0x483110 13 $D/0x483110.c --flags "/O2 /TP" \
  --entry '?SetField280@Object@@QAEXH@Z'
check 0x486f20 14 $D/0x486f20.c --flags "/O2 /TP" \
  --entry '?Game_MarkObjectsDirtyType6@@YGXPAUObjectList@@@Z'
check 0x489b10 10 $D/0x489b10.c --entry '@Game_GetDateField0C@4'
check 0x4900a0 17 $D/0x4900a0.c --flags "/O2 /TP" \
  --entry '?BranchMenu_Category_Load@@YAXPAUIStream@@@Z'
check 0x4900c0 17 $D/0x4900c0.c --flags "/O2 /TP" \
  --entry '?BranchMenu_Category_Save@@YAXPAUOStream@@@Z'
check 0x4919b0 17 $D/0x4919b0.c --flags "/O2 /TP" \
  --entry '?BranchStats_SeriesFlags_Load@@YAXPAUIStream@@@Z'
check 0x4919d0 17 $D/0x4919d0.c --flags "/O2 /TP" \
  --entry '?BranchStats_SeriesFlags_Save@@YAXPAUOStream@@@Z'
check 0x492230 17 $D/0x492230.c --flags "/O2 /TP" \
  --entry '?BranchDesign_ColorIndex_Load@@YAXPAUIStream@@@Z'
check 0x492250 17 $D/0x492250.c --flags "/O2 /TP" \
  --entry '?BranchDesign_ColorIndex_Save@@YAXPAUOStream@@@Z'
check 0x4973f0 18 $D/0x4973f0.c --entry '_Supplier_GetValuePlusOne'
check 0x499570 17 $D/0x499570.c --flags "/O2 /TP" \
  --entry '?IngredientPanel_Load@@YAXPAUIStream@@@Z'
check 0x499590 17 $D/0x499590.c --flags "/O2 /TP" \
  --entry '?IngredientPanel_Save@@YAXPAUOStream@@@Z'
check 0x4a0a60 12 $D/0x4a0a60.c --entry '_SaveGameMenu_DestroyList'

exit $fail
