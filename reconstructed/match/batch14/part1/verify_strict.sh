#!/bin/sh
# Strict byte-match verification for batch14/part1 (15 of 25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (C2.DLL 12.00.8447).
# Every check passes the manifest length, the exact decorated entry symbol,
# and requires tools/match_decomp.py --strict --auto-symbols to report
# strict_match. 0x4cd8e0 additionally needs the unnamed helper at 0x5570c0,
# which is not present in either shipped symbol map (see worklog.md).
# The remaining ten manifest records are not implemented yet or are recorded
# under nonmatching/; see worklog.md.
# Usage: sh reconstructed/match/batch14/part1/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch14/part1/$address.c" \
        --length "$length" --entry "$entry" --strict --auto-symbols \
        --flags "/O2 /TP" "$@" >"$OUT/$address.json" 2>&1; then
        echo "STRICT $address"
        pass=$((pass + 1))
    else
        echo "FAIL   $address"
        cat "$OUT/$address.json"
        fail=$((fail + 1))
    fi
}

check 0x4037d0 114 '?Profiler_StopTimer@@YAXH@Z'
check 0x47a850 115 '?GetMatrixVariantValue@Stats@@QAEHHHH@Z'
check 0x485820 116 '?UpdateAmbientLight@Game@@QAEHPAX@Z'
check 0x49f500 116 '?RecipeMenu_ShowSelectedRecipe@@YAXPAX@Z'
check 0x4a4a60 115 '?CompanyOverview_AssignEmployeeToBuilding@@YAXHPAX@Z'
check 0x4a4ae0 115 '?Guard_RemoveFromRestaurant@@YAXHPAX@Z'
check 0x4af2f0 116 '?Glossary_ShowIngredientDetail@@YAXPAX@Z'
check 0x4b5a40 114 '?BranchScreen_SelectBranchRecord@@YAXPAXD@Z'
check 0x4c51b0 114 '?CityInfo_UpdateDemandRatingBars@@YAXPAX@Z'
check 0x4cd8e0 115 '?MapList_AddIniRecord@@YAXPAXPAD@Z' \
    --symbol '_FUN_005570c0=0x5570c0'
check 0x500ec0 114 '?WaitForMenuSelection@MenuScreen@@QAEXH@Z'
check 0x510030 115 '?SumValuesByCategory@Stats@@QAEMHH@Z'
check 0x522dc0 114 '?TrimTextToWidth@UIText@@QAEXHH@Z'
check 0x5340d0 115 '?GetScreenRect@ScreenTable@@QAEXHPAH0@Z'
check 0x537d80 114 '?ConstructChild@Renderer@@QAEPAU1@PAU1@@Z'

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
