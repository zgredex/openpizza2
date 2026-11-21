#!/bin/sh
# Strict verification of the accepted candidates from the paused part audit.
set -u
cd "$(dirname "$0")/../../../.." || exit 1
PART=reconstructed/match/batch11/part4
failed=0

check() {
    address=$1 length=$2 entry=$3 flags=$4
    shift 4
    if result=$(python3 tools/match_decomp.py "$address" "$PART/$address.c" \
        --length "$length" --entry "$entry" --flags "$flags" --strict --auto-symbols "$@" 2>&1); then
        printf 'STRICT %s\n' "$address"
    else
        printf 'FAIL %s\n%s\n' "$address" "$result"
        failed=1
    fi
}

check 0x4033c0 87 '?SetOwned@String@@QAEXPAD@Z' '/O2 /TP'
check 0x403420 87 '?SetField48@String@@QAEXPAD@Z' '/O2 /TP'
check 0x499be0 88 '?NewRecipe_CloseIngredientPalette@@YAXXZ' '/O2 /TP'
check 0x49c110 88 '?Game_ResizeGlobalArray@@YAXH@Z' '/O2 /TP'
check 0x49d910 88 '?RecipeEdit_CloseIngredientPalette@@YAXXZ' '/O2 /TP'
check 0x4c1e90 88 '?Game_ResizeGlobalArray2@@YAXH@Z' '/O2 /TP'
check 0x4d4480 88 '?StoreDailyResults@Rating@@QAEXXZ' '/O2 /TP'
check 0x501ea0 88 '?Game_GetPlayerWealthBand@@YAHXZ' '/O2 /TP'
check 0x520d10 87 '?SetTextString@UI@@QAEXPAD@Z' '/O2 /TP'
check 0x523050 87 '?RemoveValueLocked@Array@@QAEHH@Z' '/O2 /TP'
check 0x528700 87 '?Destroy@ContextMenu@@QAEXXZ' '/O2 /TP'
check 0x541cf0 87 '?Sound_AlignBufferSize@@YAINH@Z' '/O2 /TP'

exit "$failed"
