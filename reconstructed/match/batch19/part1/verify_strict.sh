#!/bin/bash
# Strict byte-match verification for batch19/part1.
# Every check passes the manifest length, the exact candidate entry symbol and
# requires tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Run from the repository root:
#   bash reconstructed/match/batch19/part1/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if python3 tools/match_decomp.py "$address" \
        "reconstructed/match/batch19/part1/$address.c" \
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

check_cpp() {
    address=$1; length=$2; entry=$3; shift 3
    if python3 tools/match_decomp.py "$address" \
        "reconstructed/match/batch19/part1/$address.cpp" \
        --length "$length" --entry "$entry" --strict --auto-symbols \
        --flags "/O2 /TP /GX" "$@" >"$OUT/$address.json" 2>&1; then
        echo "STRICT $address"
        pass=$((pass + 1))
    else
        echo "FAIL   $address"
        cat "$OUT/$address.json"
        fail=$((fail + 1))
    fi
}

check 0x4029e0 225 '?RegisterExtensionAlias@ResourceManager@@QAEXPAD0@Z'
check 0x4f7920 223 '?PickObject@Map@@QAEHH@Z'
check 0x501580 220 '?GetPlanName@GamePlan@@QAEPADH@Z'
check 0x5300e0 223 '?HitTestChildAtPoint@UI@@QAEPAXPAH0@Z'
check 0x5402a0 225 '?AddExtensionMapping@SoundPakManager@@QAEXPAD0@Z'
check 0x547ac0 224 '?SetVolumeSetting@Sound@@QAEDHH@Z'
check_cpp 0x544760 223 '?Sound_GetPlayPosition@@YGHPAUSoundBuffer@@PAHPAI@Z'

echo "strict $pass / $((pass + fail))"
[ "$fail" -eq 0 ]
