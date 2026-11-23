#!/bin/sh
# Strict byte-match verification for batch21/part1.
# Toolchain: ~/.local/share/pc2/vc6-sp3-toolchain/VC98 (C2.DLL 12.00.8447).
# Each check passes the manifest length and entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match true.
# Usage: sh reconstructed/match/batch21/part1/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
DIR="reconstructed/match/batch21/part1"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "$DIR/$address.c" --length "$length" --entry "$entry" \
        --flags '/O2 /TP' --strict --auto-symbols "$@" >"$OUT/$address.json" 2>&1; then
        echo "STRICT $address"
        pass=$((pass + 1))
    else
        echo "FAIL   $address"
        cat "$OUT/$address.json"
        fail=$((fail + 1))
    fi
}

check 0x5086e0 155 '?UI_ShiftChildRect@@YIXPAD@Z'
check 0x522f40 155 '?InsertGrow@Array@@QAEHH@Z'
check 0x404460 156 '?ResourceManager_OpenArchivePath@@YAHPAUResourceManager@@PAD@Z' \
    --symbol '?Pak_Open@ResourceManager@@QAEXPAD@Z=0x401af0'

echo "strict matches: $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
