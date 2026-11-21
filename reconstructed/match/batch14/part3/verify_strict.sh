#!/bin/sh
# Strict byte-match verification for batch14/part3.
# Every accepted candidate is genuine C/C++ compiled with MSVC 6.0 SP3
# (/tmp/opencode/vc6-sp3-toolchain/VC98) and must report strict_match
# from tools/match_decomp.py --strict --auto-symbols with the manifest
# length and the exact entry symbol.
# Usage: sh reconstructed/match/batch14/part3/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; flags=$4; shift 4
    if python3 tools/match_decomp.py "$address" \
        "reconstructed/match/batch14/part3/$address.c" \
        --length "$length" --entry "$entry" --flags "$flags" \
        --strict --auto-symbols "$@" >"$OUT/$address.json" 2>&1; then
        echo "STRICT $address"
        pass=$((pass + 1))
    else
        echo "FAIL   $address"
        cat "$OUT/$address.json"
        fail=$((fail + 1))
    fi
}

check 0x505260 120 '?DestroyChildObject@UI@@QAEHXZ' '/O2 /TP'
check 0x5104f0 120 '?AverageActiveCategories@Stats@@QAEMPAE@Z' '/O2 /TP'
check 0x548350 120 '?UpdateVolumeByCitySize@Sound@@QAEXPAUGame@@@Z' '/O2 /TP'
check 0x4817c0 121 '?QueryMemoryInfo@System@@QAEXXZ' '/O2 /TP'
check 0x502810 121 '?IsInputIndexUsed@Game@@QAEDH@Z' '/O2 /TP'
check 0x502890 121 '?AnyBuildingRatingAbove@Game@@QAEDH@Z' '/O2 /TP'
check 0x502910 121 '?AnyBuildingCategoryRatingAbove@Game@@QAEDH@Z' '/O2 /TP'
check 0x502990 121 '?IsObjectStatAbove@Game@@QAEDH@Z' '/O2 /TP'
check 0x5314f0 121 '?GetBoundsByKey@Array@@QAEHHPAH@Z' '/O2 /TP'
check 0x47a3b0 122 '?GetCustomerGroupRating@Branch@@QAEHHH@Z' '/O2 /TP'
check 0x489e20 122 '?AnyBuildingReachesCellList@Game@@QAEHPAX@Z' '/O2 /TP'
check 0x4e4670 122 '?Approach@Value@@QAEXNN@Z' '/O2 /TP'
check 0x47c730 123 '?ClearPendingMapObjects@Game@@QAEXXZ' '/O2 /TP'
check 0x48cb30 123 '?RefreshObjectSprites@Map@@QAEXXZ' '/O2 /TP'
check 0x4ff9e0 123 '?ResetInventory@InventoryArray@@QAEXPAUBuilding@@@Z' '/O2 /TP'
check 0x502a10 123 '?AllBuildingCategoryRatingsAbove@Game@@QAEDH@Z' '/O2 /TP'
check 0x522d40 123 '?SetTextFit@UI@@QAEXPAD@Z' '/O2 /TP'
check 0x4c4e30 124 '_Window_UpdatePolicePage' '/O2 /TP'

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
