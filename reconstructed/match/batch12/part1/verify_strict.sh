#!/bin/sh
# Strict byte-match verification for batch12/part1 (18 of 25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (C2.DLL 12.00.8447).
# Every check passes the manifest length and entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# See nonmatching/ and worklog.md for the remaining functions.
# Usage: sh reconstructed/match/batch12/part1/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch12/part1/$address.c" \
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

check 0x4da2a0 89 '?ChargePoliceBribes@City@@QAEXXZ' --flags "/O2 /TP"
check 0x4da700 89 '?GetPlayerSharePercent@Stats@@QAEHH@Z' --flags "/O2 /TP"
check 0x4da760 89 '?ComputeRatingShare@Stats@@QAEHH@Z' --flags "/O2 /TP"
check 0x502c50 89 '?GetRandomResidentCount@Building@@QAEHH@Z' --flags "/O2 /TP"
check 0x50fdf0 89 '?Game_ResetStats@@YIXPAUGame@@@Z' --flags "/O2 /TP"
check 0x527dc0 89 '?GetScrollRatio@UI@@QAEN_J0@Z' --flags "/O2 /TP"
check 0x53fc40 89 '?ConstructBase@SoundBuffer@@QAEPAU1@XZ' --flags "/O2 /TP"
check 0x480b40 90 '?IsRatingBelowThreshold@Game@@QAEHH@Z' --flags "/O2 /TP"
check 0x48cbb0 90 '@Sound_RefreshMusicSelection@4' --flags "/O2 /TP"
check 0x4e2950 90 '@Game_RefreshBuildingCondition@4' --flags "/O2 /TP"
check 0x501e40 90 '?Game_GetActivityVolumeBand@@YAHXZ' --flags "/O2 /TP"
check 0x50fab0 90 '@GamePlan_GetCompanyCategoryMetric@20' --flags "/O2 /TP"
check 0x512c40 90 '?AccumulateQualityDelta@Recipe@@QAEXPAD0@Z' --flags "/O2 /TP"
check 0x53a140 90 '@Gfx_BuildBlendTable@4' --flags "/O2 /TP"
check 0x47aac0 91 '?CountObjectsByType@Game@@QAEHI@Z' --flags "/O2 /TP"
check 0x47cc70 91 '?CountRecordsByPair@Game@@QAEHHH@Z' --flags "/O2 /TP"
check 0x4dc9a0 91 '?PlaceObjectOnMap@City@@QAEXPAX0@Z' --flags "/O2 /TP"
check 0x510400 91 '?GetMaxTimelineCount@Stats@@QAEHH@Z' --flags "/O2 /TP"

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
