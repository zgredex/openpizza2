#!/bin/sh
# Strict byte-match verification for batch14/part4.
# Every accepted candidate is genuine C/C++ compiled with MSVC 6.0 SP3
# (/tmp/opencode/vc6-sp3-toolchain/VC98) and must report strict_match
# from tools/match_decomp.py --strict --auto-symbols with the manifest
# length and the exact entry symbol.
# Usage: sh reconstructed/match/batch14/part4/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; flags=$4; shift 4
    if python3 tools/match_decomp.py "$address" \
        "reconstructed/match/batch14/part4/$address.c" \
        --length "$length" --entry "$entry" --flags "$flags" \
        --strict --auto-symbols "$@" >"$OUT/$address.json" 2>&1; then
        echo "STRICT $address"
        pass=$((pass + 1))
    else
        echo "FAIL   $address"
        cat "$OUT/$address.json"
        fail=$((fail + 1))
    fi
}

check 0x51fa80 124 '?EnsureBackBufferWindow@Surface@@QAEXPAX@Z' '/O2 /GX /TP'
check 0x4dc6a0 125 '?InterpolateMonthlyValue@Calendar@@QAEHXZ' '/O2 /TP'
check 0x4ddfb0 125 '?FindTopScoringCompany@Game@@QAEPAUCompany@@HPAU2@@Z' '/O2 /TP'
check 0x54c5b0 126 '?DestroyObject@SoundObject@@QAEXXZ' '/O2 /TP'
check 0x4a5360 127 '_UI_RemoveProfileStatElements' '/O2 /TP'

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
