#!/bin/sh
# Strict byte-match verification for batch11/part1 (21 of 25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (C2.DLL 12.00.8447).
# Every check passes the manifest length and entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Usage: sh reconstructed/match/batch11/part1/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; flags=$4
    if $M "$address" "reconstructed/match/batch11/part1/$address.c" \
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

check 0x4e43f0 78 '?Save@BuildingValue@@QAEXPAUOStream@@@Z' '/O2 /TP'
check 0x4e4440 78 '?Load@BuildingValue@@QAEXPAUIStream@@@Z' '/O2 /TP'
check 0x4f1450 78 '?HasAdjacentTile@Building@@QAEHHPAUTile@@H@Z' '/O2 /TP'
check 0x513bf0 78 '?ComputeRecipePrice@Branch@@QAEMPAUBranchData@@H@Z' '/O2 /TP'
check 0x521740 78 '?DrawChildSprite@ChildSprite@@QAEXPAXH0HI@Z' '/O2 /TP'
check 0x521b40 78 '?BeginAnimation@Sprite@@QAEXHHH@Z' '/O2 /TP'
check 0x5315d0 78 '?CenterChildVertically@UI@@QAEHHH@Z' '/O2 /TP'
check 0x47a4a0 79 '@Matrix_Max100x8@4' '/O2 /TP'
check 0x481050 79 '?RemoveFromMap@MapObject@@QAEXPAX@Z' '/O2 /TP'
check 0x48b960 79 '?FindIdleObjectByClass@Game@@QAEHH@Z' '/O2 /TP'
check 0x4f5c80 79 '?GetFirstLinkedCell@Map@@QAEPAXPAUCell@@@Z' '/O2 /TP'
check 0x509240 79 '?SetChildHeightFromValue@UI@@QAEXXZ' '/O2 /TP'
check 0x511fa0 79 '_Math_TruncateDouble@8' '/O2 /TP'
check 0x539930 79 '?ScaleAndOffset@RectOwner@@QAEXPAH@Z' '/O2 /TP'
check 0x47f420 80 '?MarkAllObjectsDirty@Game@@QAEHH@Z' '/O2 /TP'
check 0x498ef0 80 '_RecipeMenu_ShowRecipeFileChooser' '/O2 /TP'
check 0x49c4d0 80 '_RecipeMenu_ShowMenuFileChooser' '/O2 /TP'
check 0x4da6b0 80 '_Player_HasRecordWithField30@8' '/O2 /TP'
check 0x4e4770 80 '?Construct@Ingredient@@QAEPAU1@H@Z' '/O2 /TP'
check 0x4f29d0 80 '_IsMenuIdRange@4' '/O2 /TP'
check 0x50bba0 80 '@Game_HasObjectWithSourceId@4' '/O2 /TP'

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
