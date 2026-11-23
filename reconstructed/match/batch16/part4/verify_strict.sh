#!/bin/sh
# Strict byte-match verification for batch16/part4.
# Toolchain: ~/.local/share/pc2/vc6-sp3-toolchain/VC98 (C2.DLL 12.00.8447).
# Each check passes the manifest length and entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# The functions in nonmatching/ are genuine C/C++ attempts that differ from
# the shipped bytes; see nonmatching/*.json for first-diff evidence.
# Usage: sh reconstructed/match/batch16/part4/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch16/part4/$address.c" \
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

check 0x4a14c0 166 '_SaveGame_CompareTime' --flags "/O2 /TP"
check 0x4dc0f0 166 '?PlaceScenarioBranches@ScenarioCompany@@QAEXPAX@Z' --flags "/O2 /TP"
check 0x50e550 165 '@Game_GetObjectStatusLevel@4' --flags "/O2 /TP"
check 0x50e600 170 '?ChooseWanderTarget@Person@@QAEXPAX@Z' --flags "/O2 /TP"
check 0x527d10 165 '?SetWaitCursor@UI@@QAEXH@Z' --flags "/O2 /TP"

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
