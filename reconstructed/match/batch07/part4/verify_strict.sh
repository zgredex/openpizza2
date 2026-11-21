#!/bin/sh
# Strict byte-match verification for batch07/part4 (24 of 25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (CL 12.00.8168, C2.DLL 12.00.8447).
# Every check passes the manifest length and the exact entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# 0x505eb0 lives under nonmatching/ (see worklog).
# Usage: sh reconstructed/match/batch07/part4/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
P=reconstructed/match/batch07/part4
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "$P/$address.c" --length "$length" --entry "$entry" \
        --flags "/O2 /TP" --strict --auto-symbols "$@" \
        >"$OUT/$address.json" 2>&1; then
        echo "STRICT $address"
        pass=$((pass + 1))
    else
        echo "FAIL   $address"
        cat "$OUT/$address.json"
        fail=$((fail + 1))
    fi
}

check 0x498740 51 '?City_RebuildBuildingRatingIndex@@YAXH@Z'
check 0x49c170 51 '?Ranking_SortRecordIndices@@YAXH@Z'
check 0x49c240 51 '?Stats_SortCompanyIndexArray@@YAXH@Z'
check 0x4c1ef0 51 '?PlayerRecordPanel_SortIndices@@YAXH@Z'
check 0x4c1f30 51 '?City_RebuildProductSortIndex@@YAXH@Z'
check 0x4dd0f0 51 '?ApplyTablePercent@Economy@@QAEHH@Z'
check 0x4e2280 51 '?Game_GetPlayerFieldC20@@YIHPAUPlayer@@@Z'
check 0x4f0cc0 51 '?GetRecord28@Array@@QAEPAXHH@Z'
check 0x4f3b30 51 '?GetRect100@Object@@QAEXPAH000@Z'
check 0x4f5db0 51 '?Object_ClearState@@YGXPAUHolder@@@Z'
check 0x50f630 51 '??0GamePlan@@QAE@XZ'
check 0x5312f0 51 '?GetPair8@Array@@QAEHHPAH@Z'
check 0x532b60 51 '?StopBuffer@Sound@@QAEXXZ'
check 0x5335b0 51 '?SetDoubles48B@RecordTable@@QAEEHNN@Z'
check 0x534990 51 '?SetIndex48@RecordTable@@QAEXHH@Z'
check 0x535650 51 '?GetCharWidth@Font@@QAEHE@Z'
check 0x541250 51 '?FreeAll@List@@QAEXXZ'
check 0x4032a0 52 '?WriteValue@RegistryKey@@QAEHPBDPAEK@Z'
check 0x47fed0 52 '?Game_CountFreeResidentialBuildings@@YIHPAUObject@@@Z' \
    --flags "/O2 /G6 /TP"
check 0x4aaac0 52 '?Calendar_IsSelectedDate@@YAEXZ'
check 0x4e5d60 52 '??0ConstructionOrder@@QAE@HH@Z'
check 0x503280 52 '?ResetState@BuildingProject@@QAEXXZ'
check 0x50fba0 52 '?ComputeEffectValue@GamePlan@@QAEHH@Z'
check 0x5277d0 52 '?DecrementRowCounter@UI@@QAEXPAD@Z'

echo "strict $pass/$((pass + fail)) plus 0x505eb0 nonmatching"
[ "$fail" -eq 0 ]
