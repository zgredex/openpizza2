#!/bin/sh
# Strict byte-match verification for batch16/part1.
# Toolchain: the pinned VC6 SP3 tree (C2.DLL 12.00.8447).
# Each check passes the manifest length and the exact candidate entry symbol and
# requires tools/match_decomp.py --strict --auto-symbols to report a strict match.
# Usage: sh reconstructed/match/batch16/part1/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch16/part1/$address.c" \
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

check 0x5136c0 147 '?ComputeCompanyRatings@Game@@QAEXH@Z'
check 0x5265a0 147 '?ClearDestroyedObjectReferences@UI@@QAEXH@Z'
check 0x5387d0 148 '?ReleaseTargets@Renderer@@QAEXXZ'
check 0x4fd0f0 149 '_Player_BuildHeadquarters@20'
check 0x533af0 149 '?ApplyVariantState@Record@@QAEHHHE@Z'
check 0x4e0df0 150 '?GetFilteredFloatDelta@Stats@@QAEMHH@Z'
check 0x49a040 150 '_Game_IsCompanyNameTaken'
check 0x4e6420 150 '?Filename_ToUpperStripExt@@YAXPAD@Z'
check 0x526e80 150 '?SetBackgroundSurfaceEnabled@UI@@QAEXH@Z'
check 0x409b10 151 '_AdCampaign_GoToNearestOwnBuilding@8'
check 0x52a3a0 152 '?SetClampedValue@UI@@QAEXHH@Z'
check 0x48a090 153 '?CountFilteredObjects2@Game@@QAEHHHHH@Z'
check 0x48ea50 153 '?Game_ReturnToPlayScreen@@YAXXZ'
check 0x4e2b70 153 '?GetTopProductCategory@City@@QAEHXZ'
check 0x540510 153 '?FindExtensionEntry@SoundPakManager@@QAEHPAD@Z'
check 0x48bef0 154 '?OpenObjectView@Game@@QAEXH@Z'
check 0x4e3780 154 '?ComputeNetStatTotal@Player@@QAEMXZ'
check 0x535d70 154 '?Initialize@Palette@@QAEPAV1@HPAHH@Z'

echo "strict matches: $pass/$((pass + fail))"
test "$fail" -eq 0
