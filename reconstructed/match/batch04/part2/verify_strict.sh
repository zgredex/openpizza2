#!/bin/sh
# Strict byte-match verification for batch04/part2 (25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (CL 12.00.8168, C2.DLL 12.00.8447).
# Every check passes the manifest length and entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Usage: sh reconstructed/match/batch04/part2/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
P=reconstructed/match/batch04/part2
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "$P/$address.c" \
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

check 0x49eca0 30 '_Stats_SortActiveProductIndices' \
    --symbol '_compare_0049ecc0=0x49ecc0'
check 0x49ed40 30 '_Ranking_SortCompanyIndices' \
    --symbol '_compare_0049ed60=0x49ed60'
check 0x4c7090 27 '?FreePlaySetup_SetDifficultyText@@YAXPAXH@Z' --flags "/O2 /TP"
check 0x4cda30 26 '?NameMap_GetString@@YAPAXPAUIDMap@@H@Z' --flags "/O2 /TP"
check 0x4cda50 30 '?NameMap_GetRecordString@@YAPAXPAUIDMap@@H@Z' --flags "/O2 /TP"
check 0x4d1d80 30 '?Delete@MapObject@@QAEPAXE@Z' --flags "/O2 /TP"
check 0x4d2e40 26 '@IsSpecialIdRange@4'
check 0x4d2e60 26 '@Object_IsIdIn840Range@4'
check 0x4d3240 30 '?Delete@Car@@QAEPAXE@Z' --flags "/O2 /TP"
check 0x4d3260 25 '?InitFromSave@Car@@QAEPAU1@PAX@Z' --flags "/O2 /TP"
check 0x4d3470 29 '?LoadSpriteRecord@Car@@QAEXPAX@Z' --flags "/O2 /TP"
check 0x4d36f0 25 '?ConstructFromStream@Character@@QAEPAU1@PAX@Z' --flags "/O2 /TP"
check 0x4d3fc0 30 '@Rating_AdjustA@4'
check 0x4d3fe0 28 '@Rating_AdjustB@4'
check 0x4d40d0 30 '@Cost_ComputeQuantityPrice@4'
check 0x4d42f0 29 '@State_GetFlags@4'
check 0x4d4310 29 '@State_IsNegative@4'
check 0x4d47e0 30 '?Delete@City@@QAEPAXE@Z' --flags "/O2 /TP"
check 0x4da630 29 '?GetStride60@Array@@QAEHH@Z' --flags "/O2 /TP"
check 0x4da690 28 '?FindIndexStride60@Array@@QAEHPAH@Z' --flags "/O2 /TP"
check 0x4db010 25 '?SetPlayerAdvertisingBudget@City@@QAEXHH@Z' --flags "/O2 /TP"
check 0x4dd8d0 30 '?Delete@Company@@QAEPAXE@Z' --flags "/O2 /TP"
check 0x4e3be0 30 '@Player_ResetDebtHours@4'
check 0x4e4140 26 '_Game_GetCityData'
check 0x4e4370 25 '?ConstructFromStream@BuildingValue@@QAEPAU1@PAX@Z' --flags "/O2 /TP"

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
