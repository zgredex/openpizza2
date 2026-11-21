#!/bin/sh
# Strict byte-match verification for batch06/part4 (24 of 25 functions; see
# nonmatching/0x5548e7.c and worklog.md).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (C2.DLL 12.00.8447).
# Every check passes the manifest length and the exact entry symbol and
# requires tools/match_decomp.py --strict --auto-symbols to report
# "strict_match": true.
# Usage: sh reconstructed/match/batch06/part4/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch06/part4/$address.c" \
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

check 0x531780 42 '?GetField20ByKey@Array@@QAEHH@Z' --flags "/O2 /TP" \
    --symbol '?FindIndex@Array@@QAEHHH@Z=0x531330'
check 0x547770 42 '_Options_GetGlobalSettings@4' --flags "/O2"
check 0x401480 43 '@List_Node_Destroy@8' --flags "/O2"
check 0x403480 43 '@UI_ListEntry_Destroy@8' --flags "/O2"
check 0x403850 43 '_Math_RoundFloat' --flags "/O2"
check 0x4d2fa0 43 '?SetObjectMode@Map@@QAEXPAUMapObject@@E@Z' --flags "/O2 /TP"
check 0x5080f0 43 '?IsSiteRatingSufficient@Object@@QAE_NPAUBranch@@H@Z' --flags "/O2 /TP"
check 0x50bf00 43 '?StartProtectionCollection@Object@@QAEXPAUBranch@@@Z' --flags "/O2 /TP"
check 0x50f840 43 '?ComputeAverageEffect@GamePlan@@QAEHH@Z' --flags "/O2 /TP"
check 0x50fb70 43 '?SetActiveEffect@GamePlan@@QAEXHH@Z' --flags "/O2 /TP"
check 0x531f50 43 '?SetObjectTextByKey@Array@@QAEXHPAD@Z' --flags "/O2 /TP" \
    --symbol '?FindIndex@Array@@QAEHHH@Z=0x531330'
check 0x539230 43 '?Release@Surface@@QAEXXZ' --flags "/O2 /TP"
check 0x547270 43 '?SetVolume@Sound@@QAEEI@Z' --flags "/O2 /TP"
check 0x54bc90 43 '?RemoveAllBriefings@UI@@QAEXXZ' --flags "/O2 /TP"
check 0x4e47e0 44 '@Game_GetMaxIndex4@8' --flags "/O2"
check 0x528200 44 '?SetActiveChild@UI@@QAEXPAUChild@@@Z' --flags "/O2 /TP"
check 0x53fc10 44 '?DirectSoundBuffer_Delete@@YIPAXPAUDirectSoundBuffer@@HE@Z' --flags "/O2 /TP"
check 0x49f190 45 '_Game_ClearObjectReferences' --flags "/O2"
check 0x4b02d0 45 '?StatisticsBackdrop_RestoreCategorySelection@@YAXPAUGadget@@@Z' --flags "/O2 /TP"
check 0x4d75d0 45 '?UpdateAndFetchMapEntryFAC@Game@@QAEXH@Z' --flags "/O2 /TP"
check 0x4eacd0 45 '?UpdateIDMapEntry@Game@@QAEXH@Z' --flags "/O2 /TP"
check 0x520e30 45 '?Activate@Child@@QAEXXZ' --flags "/O2 /TP"
check 0x54dca7 45 '?AllocateAttachedBuffer@Stream@@QAEHXZ' --flags "/O1 /TP"
check 0x4d2e10 46 '?TestFlag@Map@@QAEHPAUTileObject@@I@Z' --flags "/O2 /TP"

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
