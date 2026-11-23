#!/bin/bash
# Strict byte-match verification for batch19/part2.
# Every check passes the manifest length, the exact candidate entry symbol and
# requires tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Run from the repository root:
#   bash reconstructed/match/batch19/part2/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if python3 tools/match_decomp.py "$address" \
        "reconstructed/match/batch19/part2/$address.c" \
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

check 0x402750 227 '?Read@Resource@@QAEIPAXIPAUStream@@@Z'
check 0x4bf4d0 229 '?SchoolMenu_UpdatePage@@YAXPAX@Z'
check 0x4da390 227 '?AdjustPlayerRankingScores@Game@@QAEXXZ'
check 0x4fc470 226 '?RecomputeCompanyMenuSales@Game@@QAEHH@Z'

echo "strict $pass / $((pass + fail))"
[ "$fail" -eq 0 ]
