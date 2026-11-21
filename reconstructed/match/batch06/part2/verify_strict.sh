#!/bin/sh
# Strict byte-match verification for batch06/part2 (24 of 25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (CL 12.00.8168, C2.DLL 12.00.8447).
# Every check passes the manifest length and exact entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
#
# 0x54efd0 (_strrchr) is a known non-match: the shipped function is the Visual
# Studio 1998 CRT assembly leaf (`std` + backwards `repnz scas`), which cannot be
# produced from C/C++. Its reference source is in part2/nonmatching/.
#
# Usage: sh reconstructed/match/batch06/part2/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch06/part2/$address.c" \
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

check 0x54bcc0 38 '?SetWindow@MapBadgeAnim@@QAEXPAUUI@@H@Z' --flags "/O2 /TP"
check 0x47a820 39 '?SumStatRow8@Game@@QAEHH@Z' --flags "/O2 /TP"
check 0x47ec00 39 '?RemoveTrackedRecord@Game@@QAEXPAD@Z' --flags "/O2 /TP"
check 0x4858a0 39 '?SetLockedField2FC@Game@@QAEXH@Z' --flags "/O2 /TP"
check 0x4d29d0 39 '?RemoveRecordFromLocalMap@Game@@QAEHPAD@Z' --flags "/O2 /TP"
check 0x4d3530 39 '?GetFlag3E48@Record@@QAEHXZ' --flags "/O2 /TP"
check 0x4eaa10 39 '?GetMapValue@Game@@QAEII@Z' --flags "/O2 /TP"
check 0x4ed010 39 '?ComputeIsoOffsets@Map@@QAEXXZ' --flags "/O2 /TP"
check 0x4ed570 39 '_Distance_Manhattan3@16' --flags "/O2"
check 0x4f6b50 39 '?Game_CompleteMissionStage@@YAXXZ' --flags "/O2 /TP"
check 0x501a40 39 '?Save@Player_Event@@QAEXPAUCRT_Ostream@@@Z' --flags "/O2 /TP"
check 0x501a70 39 '?Load@Player_Event@@QAEXPAUCRT_Istream@@@Z' --flags "/O2 /TP"
check 0x502cb0 39 '?PickRandomTableValue@Game@@QAEHH@Z' --flags "/O2 /TP"
check 0x508040 39 '?UI_ResetChildRecord@@YIXPAD@Z' --flags "/O2 /TP"
check 0x50be60 39 '?StartRestaurantRampage@Thug@@QAEXPADH@Z' --flags "/O2 /TP"
check 0x514660 39 '?Language_IndexOfString@@YAHH@Z' --flags "/O2 /TP"
check 0x523900 39 '?ReplaceActiveObject@UI@@QAEXH@Z' --flags "/O2 /TP"
check 0x528160 39 '?ResetScrollPosition@UI@@QAEXXZ' --flags "/O2 /TP"
check 0x52cb70 39 '?Text_SkipFieldSeparators@@YGXPADPAH@Z' --flags "/O2 /TP"
check 0x5313d0 39 '?Array_GetRecordByKey@@YIPAXPADHH@Z' --flags "/O2 /TP"
check 0x534960 39 '?GetValue48@Record@@QAEHH@Z' --flags "/O2 /TP"
check 0x535690 39 '?GetFirstEnabledIndex@UI@@QAEHXZ' --flags "/O2 /TP"
check 0x5396b0 39 '?GetCursorRect@Surface@@QAEXPAH000@Z' --flags "/O2 /TP"
check 0x54a630 39 '?Destructor@DebugConsole@@QAEXXZ' --flags "/O2 /TP"

echo "strict $pass/24 C matches (0x54efd0 _strrchr is a CRT assembly leaf, non-matching), failed $fail"
[ "$fail" -eq 0 ]
