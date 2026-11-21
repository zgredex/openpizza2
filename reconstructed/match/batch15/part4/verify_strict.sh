#!/bin/bash
# Strict byte-match verification for batch15/part4.
# Every check passes the manifest length, the exact candidate entry symbol and
# requires tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Run from the repository root:
#   bash reconstructed/match/batch15/part4/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if python3 tools/match_decomp.py "$address" \
        "reconstructed/match/batch15/part4/$address.c" \
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

check 0x4a5420 147 '_BauenPage_ResetBuildingSlots'
check 0x4ab600 147 '_StatisticsBalance_UpdateHeader'
check 0x4de030 145 '?GetLeadingCompanyForCategory@StatsObject@@QAEHHPAX@Z'
check 0x4ff650 143 '?CompareRounded@Math@@QAEHPAXH@Z'

echo "strict $pass / $((pass + fail))"
[ "$fail" -eq 0 ]
