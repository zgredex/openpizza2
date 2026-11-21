#!/bin/sh
# Strict byte-match verification for batch12/part2 (20 of 25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (C2.DLL 12.00.8447).
# Every check passes the manifest length and entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# See nonmatching/ and worklog.md for the remaining functions.
# Usage: sh reconstructed/match/batch12/part2/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch12/part2/$address.c" \
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

check 0x548510 91 '?UpdatePositionCountdown@Sound@@QAEXXZ' --flags "/O2 /TP"
check 0x47cc10 92 '?CountPlayersByByte@Game@@QAEHI@Z' --flags "/O2 /TP"
check 0x47ccd0 92 '?CountRecordsByByteC@Game@@QAEHI@Z' --flags "/O2 /TP"
check 0x48c160 92 '?SelectPlayer@Game@@QAEXH@Z' --flags "/O2 /TP"
check 0x4dd270 92 '?Construct@GameClock@@QAEPAU1@PAX@Z' --flags "/O2 /TP"
check 0x4e2c40 92 '?GetMaxPlanSteps@AI@@QAEHH@Z' --flags "/O2 /TP"
check 0x4f0c60 92 '?FindRecordByKey28@Object@@QAEHPAHI@Z' --flags "/O2 /TP"
check 0x520b60 92 '?IsValidSize@UI@@QAEHHH@Z' --flags "/O2 /TP"
check 0x5392e0 92 '?InitFromBuffer@Surface@@QAEXHGGH@Z' --flags "/O2 /TP"
check 0x53f880 92 '@Sound_AllocDecompressedBuffer@4' --flags "/O2 /TP"
check 0x546fd0 92 '?Range@Random@@QAEHHH@Z' --flags "/O2 /TP"
check 0x4d4330 93 '?GetCostForType@Game@@QAEHH@Z' --flags "/O2 /TP"
check 0x4e3f50 93 '@Game_ScalePlayerStat80@4' --flags "/O2 /TP"
check 0x4eaa40 93 '?FindNameIndex@Map@@QAEHPAD@Z' --flags "/O2 /TP"
check 0x4f5ae0 93 '?ClearSlotRefs@Object@@QAEXPAUSlotObject@@@Z' --flags "/O2 /TP"
check 0x5397e0 93 '?RGBTo16@ColorSpace@@QAEIEEI@Z' --flags "/O2 /TP"
check 0x5483d0 93 '?StartSpeech@Sound@@QAEXH@Z' --flags "/O2 /TP"
check 0x5484b0 93 '@Sound_StopAmbientBuffers@4' --flags "/O2 /TP"
check 0x54a820 93 '?MoveToSidePanel@Window@@QAEXXZ' --flags "/O2 /TP"
check 0x4010f0 94 '?ConstructEmpty@StatsReport@@QAEPAU1@HH@Z' --flags "/O2 /TP"

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
