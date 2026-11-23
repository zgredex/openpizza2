#!/bin/sh
# Strict byte-match verification for batch19/part4.
# Run from the repository root:
#   sh reconstructed/match/batch19/part4/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; source=$4; shift 4
    if python3 tools/match_decomp.py "$address" \
        "reconstructed/match/batch19/part4/$source" \
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

check 0x4014b0 251 '?Add@List@@QAEHH@Z' 0x4014b0.cpp \
    --symbol '?g_listLock@@3UCriticalSection@@A=0x579af0' \
    --symbol '?Enter@CriticalSection@@QAEXXZ=0x401320' \
    --symbol '?Leave@CriticalSection@@QAEXXZ=0x401340'

echo "strict $pass / $((pass + fail))"
[ "$fail" -eq 0 ]
