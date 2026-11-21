#!/bin/sh
# Strict byte-match verification for batch06/part3 (25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (C2.DLL 12.00.8447).
# Every check passes the manifest length and the exact entry symbol and
# requires tools/match_decomp.py --strict --auto-symbols to report
# "strict_match": true.
# Usage: sh reconstructed/match/batch06/part3/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch06/part3/$address.c" \
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

check 0x47c5b0 40 '?RemoveConstructionOrder@Branch@@QAEXH@Z' --flags "/O2 /TP"
check 0x489820 40 '?GetPlayerSubmapValue@Game@@QAEHHH@Z' --flags "/O2 /TP"
check 0x489850 40 '?GetPlayerMapValue@Game@@QAEHHH@Z' --flags "/O2 /TP"
check 0x48b3c0 40 '?GetDateFields@Game@@QAEXPAIPAH@Z' --flags "/O2 /TP"
check 0x496900 40 '_SaveList_FindIndex' --flags "/O2"
check 0x4c0390 40 '_ConstructionMenu_FillTimeLeft' --flags "/O2"
check 0x4f3490 40 '_Rect_Center@8' --flags "/O2"
check 0x50a080 40 '?SetRouteToBuilding@Person@@QAEXH@Z' --flags "/O2 /TP"
check 0x521da0 40 '?RefCounted_Free@@YGXPAURefCounted@@@Z' --flags "/O2 /TP"
check 0x52e880 40 '?GetRect@Window@@QAEXPAH@Z' --flags "/O2 /TP"
check 0x531470 40 '?SetField14ByKey@Array@@QAEXHH@Z' --flags "/O2 /TP" \
    --symbol '?FindIndex@Array@@QAEHHH@Z=0x531330'
check 0x5374b0 40 '?Clear@Surface@@QAEXXZ' --flags "/O2 /TP"
check 0x479ab0 41 '?UpdateActivePlayerCount@Game@@QAEXXZ' --flags "/O2 /TP"
check 0x47fb40 41 '?EndConstructionMode@Branch@@QAEXXZ' --flags "/O2 /TP"
check 0x4a19e0 41 '_File_Exists' --flags "/O2"
check 0x4e42c0 41 '?FindGroupSlot@Game@@QAEHHH@Z' --flags "/O2 /TP"
check 0x528190 41 '?QueueChildCommand@UI@@QAEHHH@Z' --flags "/O2 /TP"
check 0x533c60 41 '?ClearActive48@Record@@QAEXH@Z' --flags "/O2 /TP"
check 0x406a60 42 '?UI_CloseLoadingScreen@@YAXXZ' --flags "/O2 /TP"
check 0x4befd0 42 '?GangsterWeaponPanel_RefreshWithSound@@YAXH@Z' --flags "/O2 /TP"
check 0x4dd4a0 42 '?Reset@GameClock@@QAEXXZ' --flags "/O2 /TP"
check 0x4f5df0 42 '??0Player_MissionState@@QAE@PAX@Z' --flags "/O2 /TP"
check 0x4fcc00 42 '?AdjustPlayerPercentByKey@Game@@QAEXH@Z' --flags "/O2 /TP"
check 0x503250 42 '?AppendCommandIfActive@Panel@@QAEXHH@Z' --flags "/O2 /TP"
check 0x527a50 42 '?ReleasePendingSprite@Panel@@QAEXXZ' --flags "/O2 /TP"

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
