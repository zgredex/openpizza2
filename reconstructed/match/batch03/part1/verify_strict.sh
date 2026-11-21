#!/bin/sh
# Strict byte-match verification for batch03/part1 (25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (CL 12.00.8168, C2.DLL 12.00.8447).
# Every check passes the manifest length and entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Usage: sh reconstructed/match/batch03/part1/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch03/part1/$address.c" \
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

check 0x401150 23 '@Record_SumFloatArray26@4'
check 0x401170 23 '@Object_SumFloat25@4'
check 0x4032e0 24 '@RegistryKey_Close@4' --symbol '__imp__RegCloseKey@4=0x55c010'
check 0x4781b0 23 '@Rating_GetInverse100@4'
check 0x479ae0 23 '@Game_ComputeCityConditionScore@8'
check 0x47c3c0 24 '?Copy68@Array@@QAEXPAI@Z' --flags "/O2 /TP"
check 0x47c590 21 '@Array_ClearStride34@4'
check 0x47d210 25 '?AddObjectToStateList@GameObject@@QAEXPAX@Z' --flags "/O2 /TP"
check 0x47db10 23 '?Increment2D@Stats@@QAEXHH@Z' --flags "/O2 /TP"
check 0x47f400 21 '?Lookup1998@RecordMap@@QAEXH@Z' --flags "/O2 /TP"
check 0x480740 21 '@Object_AccumulateIncome@4'
check 0x4808a0 19 '?SetChildField94@Game@@QAEXH@Z' --flags "/O2 /TP"
check 0x486e00 21 '@Window_UnlockState@4'
check 0x48c000 19 '?HasQueuedEventType@Game@@QAEXH@Z' --flags "/O2 /TP"
check 0x48c020 24 '?HasKeyedRecordEntry@Game@@QAEXHH@Z' --flags "/O2 /TP"
check 0x48c040 24 '?SetMessageField34@Game@@QAEXHH@Z' --flags "/O2 /TP"
check 0x49f1c0 20 '?UI_RemoveObjectByOffsetKey@@YAXPAXH@Z' --flags "/O2 /TP"
check 0x49f1e0 20 '?RecipeKitchen_ShowPlacedIngredient@@YAXPAXH@Z' --flags "/O2 /TP"
check 0x4c70f0 20 '?UI_SetOnlineHelpText@@YAXPAXH@Z' --flags "/O2 /TP"
check 0x4d3450 20 '?Save@Car@@QAEXPAX@Z' --flags "/O2 /TP"
check 0x4d3910 23 '?Game_GetRecordByField814@@YIXPAD@Z' --flags "/O2 /TP"
check 0x4d42c0 19 '@State_HasFlags@4'
check 0x4d6ad0 21 '?LookupObjectByIndex@Game@@QAEXH@Z' --flags "/O2 /TP"
check 0x4d75b0 19 '?LookupSavedId@SaveGame@@QAEXH@Z' --flags "/O2 /TP"
check 0x4d8120 24 '?GetOwnedObjectByIndex@Game@@QAEXHPAH@Z' --flags "/O2 /TP"

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
