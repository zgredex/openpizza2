#!/bin/sh
# Strict byte-match verification for batch06/part1 (25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (CL 12.00.8168, C2.DLL 12.00.8447).
# Every check passes the manifest length and exact entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Usage: sh reconstructed/match/batch06/part1/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch06/part1/$address.c" \
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

check 0x51e9d0 35 '?InitInputHelper@UI@@QAEPAU1@H@Z' --flags "/O2 /TP"
check 0x401900 36 '?FindIndex@Map@@QAEHH@Z' --flags "/O2 /TP"
check 0x50a920 36 '?SetWorkState@Object@@QAEXXZ' --flags "/O2 /TP"
check 0x5230d0 36 '?IndexOfInt@Array@@QAEHH@Z' --flags "/O2 /TP"
check 0x54b390 36 '?Construct@MessageList@@QAEPAU1@XZ' --flags "/O2 /TP"
check 0x403bb0 37 '?RemoveById@Timer@@QAEHH@Z' --flags "/O2 /TP"
check 0x4d40f0 37 '?Game_ResetPlayerStatsByCity@@YIXPAD@Z' --flags "/O2 /TP"
check 0x4f5f70 37 '?SetSlot@Array@@QAEXHH@Z' --flags "/O2 /TP"
check 0x509fc0 37 '?Building_IsSpecialType@@YIHPAD@Z' --flags "/O2 /TP"
check 0x50f560 37 '?Game_GetPlayerTotalValue@@YIHPAD@Z' --flags "/O2 /TP"
check 0x5140b0 37 '?FindPair@Array@@QAEHH@Z' --flags "/O2 /TP"
check 0x522ef0 37 '?Clear@Array@@QAEXXZ' --flags "/O2 /TP"
check 0x54d3be 37 '?PeekChar@Stream@@QAEHXZ' --flags "/O1 /TP"
check 0x54d574 37 '?PutBackChar@Stream@@QAEHD@Z' --flags "/O1 /TP"
check 0x551de9 37 '?String_MakeRoomAtFront@@YAXPADH@Z' --flags "/O2 /Oi- /TP"
check 0x48b3f0 38 '?GetYearAndWeekday@Game@@QAEXPAI0@Z' --flags "/O2 /TP"
check 0x4986c0 38 '?GlobalArray_FindInt@@YAHHH@Z' --flags "/O2 /TP"
check 0x49c0e0 38 '?GlobalArray_FindIndex@@YAHHH@Z' --flags "/O2 /TP"
check 0x4dbfc0 38 '?GetPriceModifier@Market@@QAEHHH@Z' --flags "/O2 /TP"
check 0x521b90 38 '?DetachObject@Object@@QAEXXZ' --flags "/O2 /TP"
check 0x5281c0 38 '?InvokeCallback@UI@@QAEXHHHH@Z' --flags "/O2 /TP"
check 0x5301c0 38 '?QueueControlCommand@UI@@QAEXHHH@Z' --flags "/O2 /TP"
check 0x531f80 38 '?UI_ReleaseChildBufferByKey@@YIXPADHH@Z' --flags "/O2 /TP"
check 0x548040 38 '?TriggerSoundById@Sound@@QAEXH@Z' --flags "/O2 /TP"
check 0x548ac0 38 '?Object_FlushPending@@YIXPAD@Z' --flags "/O2 /TP"

echo "strict $pass/25, failed $fail"
[ "$fail" -eq 0 ]
