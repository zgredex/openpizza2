#!/bin/sh
# Strict byte-match verification for batch20/part4 (2 of 25 functions).
# Toolchain: pinned VC6 SP3 tree (C2.DLL 12.00.8447); no stdint.h.
# Every check passes the manifest length and the exact candidate entry symbol and
# requires tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Failed genuine C++ attempts are kept under nonmatching/ with first-diff
# evidence in worklog.md.
# Usage: sh reconstructed/match/batch20/part4/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch20/part4/$address.c" \
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

check 0x485700 284 '?RefreshDaylightCurve@Game@@QAEHM@Z' --flags "/O2 /TP"
check 0x4aef90 292 '?Glossary_BranchesPage_Init@@YAXPAX@Z' --flags "/O2 /TP"

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
