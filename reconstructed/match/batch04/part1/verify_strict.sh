#!/bin/sh
# Strict byte-match verification for batch04/part1 (25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (CL 12.00.8168, C2.DLL 12.00.8447).
# Every check passes the manifest length and entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Usage: sh reconstructed/match/batch04/part1/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch04/part1/$address.c" \
        --length "$length" --entry "$entry" --strict --auto-symbols "$@" \
        >"$OUT/$address.json" 2>&1; then
        echo "STRICT $address"
        pass=$((pass + 1))
    else
        echo "FAIL   $address"
        cat "$OUT/$address.json"
        fail=$((fail + 1))
    fi
}

check 0x401000 29 '?StreamConstruct@StatsPeriodReport@@QAEPAU1@PAX@Z' --flags "/O2 /TP"
check 0x401420 30 '@List_Node_Delete@12'
check 0x401a00 30 '@ResourceManager_ScalarDeletingDestructor@12'
check 0x402240 28 '_Pak_SortEntries@8'
check 0x402ef0 30 '@FileObject_Delete@12'
check 0x403350 30 '@UI_ListEntry_Delete@12'
check 0x4034b0 26 '_Random_Mod'
check 0x403a40 30 '@TimerClass_ScalarDeletingDestructor@12'
check 0x403b90 28 '?FindByKey@List@@QAEPAUNode@@H@Z' --flags "/O2 /TP"
check 0x476fe0 30 '@Branch_Delete@12'
check 0x477100 29 '_Clamp_0_100@4'
check 0x47c7b0 27 '?SetIndex171C@Object@@QAEXH@Z' --flags "/O2 /TP"
check 0x47d230 25 '?AddRecordToList@Screen@@QAEXPAX@Z' --flags "/O2 /TP"
check 0x47d250 25 '?QueueObjectTask@Game@@QAEXPAX@Z' --flags "/O2 /TP"
check 0x47eba0 25 '?AddRecordTo19C4@Game@@QAEXPAH@Z' --flags "/O2 /TP"
check 0x47fd70 28 '@Game_IsCurrentPlayer@4'
check 0x4817a0 30 '@GameWorld_Delete@12'
check 0x482720 26 '@Game_GetPlayerCount@4'
check 0x482820 25 '@Game_GetCurrentPlayerCompanyName@4'
check 0x482840 27 '?GetPlayerField8@Game@@QAEHH@Z' --flags "/O2 /TP"
check 0x482860 27 '?UI_DestroyWindowAt@@YGXPAPAX@Z' --flags "/O2 /TP"
check 0x488be0 28 '?GetPlayerBySlot@Game@@QAEPAUPlayer@@H@Z' --flags "/O2 /TP"
check 0x488d90 28 '@Game_GetTimeSegment@4'
check 0x49e5e0 30 '_Stats_SortCategoryIndexArray'
check 0x49e680 30 '_CompanyBuildingList_SortIndices'

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
