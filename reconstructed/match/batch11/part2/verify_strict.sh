#!/bin/sh
# Strict byte-match verification for batch11/part2 (18 of 25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (C2.DLL 12.00.8447).
# Every check passes the manifest length and entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Usage: sh reconstructed/match/batch11/part2/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; flags=$4
    if $M "$address" "reconstructed/match/batch11/part2/$address.c" \
        --length "$length" --entry "$entry" --flags "$flags" \
        --strict --auto-symbols >"$OUT/$address.json" 2>&1; then
        echo "STRICT $address"
        pass=$((pass + 1))
    else
        echo "FAIL   $address"
        cat "$OUT/$address.json"
        fail=$((fail + 1))
    fi
}

check 0x513c40 80 '?GetRecipePriceParts@Branch@@QAEXPAUBranchData@@PAHPAM11@Z' '/O2 /TP'
check 0x531620 80 '?ToggleObjectActive@Array@@QAEHHH@Z' '/O2 /TP'
check 0x533aa0 80 '?SelectVariant@Record@@QAEHHH@Z' '/O2 /TP'
check 0x4db170 81 '?GetPriceDelta@Market@@QAEHI@Z' '/O2 /TP'
check 0x4810e0 82 '@Game_FreeSubmapObjects@4' '/O2 /TP'
check 0x4e2ca0 82 '?SumPlanSteps@AI@@QAEHH@Z' '/O2 /TP'
check 0x4eaaa0 82 '?SaveTileNameTable@Game@@QAEXPAUCRT@@@Z' '/O2 /TP'
check 0x4eae00 82 '@UI_SetWindowOffsets@4' '/O2 /TP'
check 0x5141c0 82 '?AddId@StaffList@@QAEHH@Z' '/O2 /TP'
check 0x534370 82 '?GetTwoFloats48@Record@@QAEHHPAH0@Z' '/O2 /TP'
check 0x54ae60 82 '?AdvanceBriefing@UI@@QAEXH@Z' '/O2 /TP'
check 0x54dd83 82 '_String_Format' '/O1 /TP'
check 0x47fb70 83 '@Branch_RefreshConstructionButtons@4' '/O2 /TP'
check 0x48d3a0 83 '_Game_GetStartingCapital' '/O2 /TP'
check 0x492270 83 '_UI_FillObjectWithPaletteColor' '/O2 /TP'
check 0x4d6ba0 83 '?CountObjectsByType2@Game@@QAEHI@Z' '/O2 /TP'
check 0x4f1d90 83 '_Enum_MapDirection@4' '/O2 /TP'
check 0x531570 83 '?GetRectByKey@Array@@QAEHHPAH0@Z' '/O2 /TP'

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
