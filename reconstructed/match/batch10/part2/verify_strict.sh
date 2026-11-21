#!/bin/sh
# Strict byte-match verification for batch10/part2 (22 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (C2.DLL 12.00.8447).
# Every check passes the manifest length, the exact entry symbol and
# requires tools/match_decomp.py --strict --auto-symbols to report
# strict_match. Three attempts remain under nonmatching/ with first-diff
# evidence; see nonmatching/first_diffs.txt.
# Usage: sh reconstructed/match/batch10/part2/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch10/part2/$address.c" \
        --length "$length" --entry "$entry" --flags "/O2 /TP" \
        --strict --auto-symbols "$@" >"$OUT/$address.json" 2>&1; then
        echo "STRICT $address"
        pass=$((pass + 1))
    else
        echo "FAIL   $address"
        cat "$OUT/$address.json"
        fail=$((fail + 1))
    fi
}

check 0x49f5f0 76 '_RecipeMenu_ChooseRecipe'
check 0x49fa20 77 '_RecipeMenu_PrevRecipe'
check 0x4a1aa0 71 '_IDMap_DestroyAllObjects'
check 0x4a21a0 71 '_Game_HandleQueryEndSession'
check 0x4a36d0 71 '_CompanyMenu_InitBranchOverview'
check 0x4c0b30 72 '_PriceMenu_Init'
check 0x4c39f0 74 '_GamePlan_UpdateEffectBars'
check 0x4c86a0 70 '_EndResultGraph_SelectCategory'
check 0x4cb900 78 '_FreePlaySetup_ShowMapPreview'
check 0x4ce720 70 '_Movie_PlayGameOverMovie'
check 0x4d2360 69 '@Game_GetObjectBottom@4'
check 0x4d2b40 78 '?ApplyTypeProperties@Entity@@QAEXH@Z'
check 0x4d3490 69 '?Save@CarList@@QAEXPAUCRT@@@Z'
check 0x4d8090 73 '@Game_GetMostAdvancedCompany@4'
check 0x4de0d0 70 '?GetMaxMatrixValue@Game@@QAEHPAX@Z'
check 0x4de6c0 77 '?CountRecordsByField34@Game@@QAEHH@Z'
check 0x4de710 71 '?CountRecordsWithFlag16F4@Game@@QAEHXZ'
check 0x4e0830 78 '?CountObjectsByType@Player@@QAEHI@Z'
check 0x4e3610 71 '@Game_ComputeActionCost@4'
check 0x4e3f00 77 '?ComputeAverageSkill@Game@@QAEHH@Z'
check 0x4e4810 71 '@Map_PickRandomExitDirection@4'
check 0x4eab00 74 '?LoadNameIndexTable@World@@QAEXPAUCRT@@@Z'

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
