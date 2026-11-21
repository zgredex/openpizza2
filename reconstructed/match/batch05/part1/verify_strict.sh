#!/bin/sh
# Strict byte-match verification for batch05/part1 (25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (CL 12.00.8168, C2.DLL 12.00.8447).
# Every check passes the manifest length and entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Usage: sh reconstructed/match/batch05/part1/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch05/part1/$address.c" \
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

check 0x501b50 30 '@Player_AIState_Delete@12'
check 0x50bf30 30 '?GetPlayerEconomyModifier@Game@@QAEXXZ' --flags "/O2 /TP"
check 0x50d200 30 '?SetFrame5@Object@@QAEXH@Z' --flags "/O2 /TP"
check 0x50e9c0 30 '@Player_Delete@12'
check 0x50fdd0 30 '@Recipe_Delete@12'
check 0x513d30 30 '@Storage_Delete@12'
check 0x51f210 30 '@UI_ImageElement_Delete@12'
check 0x520af0 30 '@UI_Child_Delete@12'
check 0x521160 30 '@UI_Viewport_Delete@12'
check 0x5221c0 30 '@UI_LabelElement_Delete@12'
check 0x522ed0 30 '@Array_Delete@12'
check 0x523590 30 '@UI_Manager_ScalarDeletingDestructor@12'
check 0x5286e0 30 '@UI_ContextMenu_Delete@12'
check 0x529140 30 '@UI_Slider_Delete@12'
check 0x52b210 30 '@MovieWindow_Delete@12'
check 0x52bd50 30 '@UI_TextElement_Delete@12'
check 0x52d690 30 '@UI_ButtonElement_Delete@12'
check 0x52e510 30 '@UI_Tooltip_Delete@12'
check 0x52e9b0 30 '@Dialog_Delete@12'
check 0x532c20 30 '@Animation_ScalarDeletingDestructor@12'
check 0x534db0 30 '@Gfx_RectList_Delete@12'
check 0x536140 30 '@Window_Delete@12'
check 0x537d60 30 '@Renderer_Delete@12'
check 0x539840 30 '?RGBTo16FromDword@Color@@QAEXI@Z' --flags "/O2 /TP"
check 0x53c7d0 30 '@Sprite_ScalarDeletingDestructor@12'

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
