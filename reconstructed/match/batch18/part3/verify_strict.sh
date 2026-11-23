#!/bin/sh
# Strict byte-match verification for batch18/part3.
# Toolchain: ~/.local/share/pc2/vc6-sp3-toolchain/VC98 (C2.DLL 12.00.8447).
# Only functions that pass tools/match_decomp.py --strict --auto-symbols
# are listed here; failed genuine C/C++ attempts live under nonmatching/.
# Usage: sh reconstructed/match/batch18/part3/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch18/part3/$address.c" \
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

check 0x401f90 206 '?Next@ResourceIterator@@QAEHPAD@Z' --flags "/O2 /TP"
check 0x402f10 206 '?AddName@NamePool@@QAEXPADH@Z' --flags "/O2 /TP"

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
