#!/bin/sh
# Strict byte-match verification for batch08/part1 (25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (CL 12.00.8168, C2.DLL 12.00.8447).
# Every check passes the manifest length and entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# The two remaining records are documented in nonmatching/ and worklog.md.
# Usage: sh reconstructed/match/batch08/part1/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; flags=$4; file=$5; shift 5
    if $M "$address" "$file" --length "$length" --entry "$entry" \
        --strict --auto-symbols --flags "$flags" "$@" \
        >"$OUT/$address.json" 2>&1; then
        echo "STRICT $address"
        pass=$((pass + 1))
    else
        echo "FAIL   $address"
        cat "$OUT/$address.json"
        fail=$((fail + 1))
    fi
}

D=reconstructed/match/batch08/part1
check 0x539340 52 '?Convert@ColorConverter@@QAEXPAGH@Z' "/O2 /TP" $D/0x539340.c
check 0x53d100 52 '?GetHotspot@Sprite@@QAEXPAH0@Z' "/O2 /TP" $D/0x53d100.c
check 0x545660 52 '?Sound_Get3DBufferParams@@YIHPAUSound3DHost@@@Z' "/O2 /TP" $D/0x545660.c
check 0x4962a0 53 '?CompareScreen_UpdateMenuRatingBars@@YAXPAXPAUBranch@@@Z' "/O2 /TP" $D/0x4962a0.c
check 0x4d2aa0 53 '?FindObjectByClass@Game@@QAEHH@Z' "/O2 /TP" $D/0x4d2aa0.c
check 0x4d2e80 53 '@Building_GetSpriteVariant@4' "/O2" $D/0x4d2e80.c
check 0x4d3560 53 '?PlaceAtPoint@MapObject@@QAEXPAH@Z' "/O2 /TP" $D/0x4d3560.c
check 0x523de0 53 '?RefreshAndCenter@UI@@QAEXPAUSurface@@@Z' "/O2 /TP" $D/0x523de0.c
check 0x528760 53 '?Window_ReleaseResources@@YIXH@Z' "/O2 /TP" $D/0x528760.c
check 0x4034d0 54 '_Random_RangeFast' "/O2" $D/0x4034d0.c
check 0x4043e0 54 '_GameMain' "/O2" $D/0x4043e0.c
check 0x404420 54 '_SetScreenRects' "/O2" $D/0x404420.c \
    --symbol '__imp__SetRect@20=0x55c280'
check 0x477360 54 '?Game_FindMapRecordByTypeE@@YIHPAUGameRoot@@@Z' "/O2 /TP" $D/0x477360.c
check 0x480a70 54 '?SetObjectValue100@Game@@QAEDPAU1@@Z' "/O2 /TP" $D/0x480a70.c
check 0x4d31b0 54 '?GetCenteredRectForRecord@UI@@QAEXPAH0@Z' "/O2 /TP" $D/0x4d31b0.c
check 0x4ffa90 54 '?ScheduleDeadline@Company@@QAEXHH@Z' "/O2 /TP" $D/0x4ffa90.c
check 0x5019d0 54 '?StreamConstruct@Player_Event@@QAEPAU1@PAUCRT_Istream@@@Z' "/O2 /TP" $D/0x5019d0.c
check 0x526f60 54 '?FindFontByName@UI@@QAEPAEPAE@Z' "/O2 /TP" $D/0x526f60.c \
    --symbol '_FUN_005570c0=0x5570c0'
check 0x527ad0 54 '?GetChildOrigin@Object@@QAEXPAH0@Z' "/O2 /TP" $D/0x527ad0.c
check 0x5288b0 54 '?GetOuterRect@UI@@QAEXPAH@Z' "/O2 /TP" $D/0x5288b0.c
check 0x47ebc0 55 '?FindRecordByField10@Game@@QAEHH@Z' "/O2 /TP" $D/0x47ebc0.c
check 0x4c6f50 55 '?CharacterSelect_DrawPortrait@@YAXPAX@Z' "/O2 /TP" $D/0x4c6f50.c
check 0x4dcb30 55 '?IncrementPlayerCounterC20@Game@@QAEXH@Z' "/O2 /TP" $D/0x4dcb30.c

echo "strict $pass/$((pass + fail)) (+2 nonmatching records)"
[ "$fail" -eq 0 ]
