#!/bin/bash
# Strict byte-match verification for batch17/part4.
# Every check passes the manifest length, the exact candidate entry symbol and
# requires tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Run from the repository root:
#   bash reconstructed/match/batch17/part4/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3
    if python3 tools/match_decomp.py "$address" \
        "reconstructed/match/batch17/part4/$address.c" \
        --length "$length" --entry "$entry" --strict --auto-symbols \
        --flags "/O2 /TP" >"$OUT/$address.json" 2>&1; then
        echo "STRICT $address"
        pass=$((pass + 1))
    else
        echo "FAIL   $address"
        cat "$OUT/$address.json"
        fail=$((fail + 1))
    fi
}

check 0x54acc0 186 '?GetChannelObject@Sound@@QAEHHH@Z'
check 0x48c860 187 '?HandleObjectDeath@Game@@QAEXPAX@Z'
check 0x507e20 187 '?SetDestinationAndTarget@MapObject@@QAEXHPAX@Z'
check 0x478420 188 '?GetPriceComparisonRating@Branch@@QAEHHPAH@Z'
check 0x54afb0 188 '?RemoveAllById@UI@@QAEXH@Z'
check 0x526640 189 '?ForgetChildById@UI@@QAEXH@Z'
check 0x4e2d00 190 '?ComputeAverageRating@Player@@QAEHXZ'

echo "strict $pass / $((pass + fail))"
[ "$fail" -eq 0 ]
