#!/bin/sh
# Strict byte-match verification for batch16/part3.
# Toolchain: ~/.local/share/pc2/vc6-sp3-toolchain/VC98 (C2.DLL 12.00.8447).
# Each check passes the manifest length and entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# The functions in nonmatching/ are genuine C/C++ attempts that differ from
# the shipped bytes; see nonmatching/*.json for first-diff evidence.
# Usage: sh reconstructed/match/batch16/part3/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch16/part3/$address.c" \
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

check 0x47ff10 158 '?GetConstructionPriority@Game@@QAEHXZ' --flags "/O2 /TP"
check 0x478320 159 '?GetMenuRating@Branch@@QAEHH@Z' --flags "/O2 /TP"
check 0x48c7b0 163 '?GetRatingPercent@Game@@QAEHHH@Z' --flags "/O2 /TP"
check 0x4c3070 159 '_FurnitureMenu_InitChairPage' --flags "/O2 /TP"
check 0x4e0880 159 '?FindDailyStatRecord@Game@@QAEHHIH@Z' --flags "/O2 /TP"
check 0x4edbf0 159 '?DrawRecordLinkSprites@Map@@QAEXHPAX@Z' --flags "/O2 /TP"
check 0x51eb50 159 '?DrawPendingSprite@Renderer@@QAEHHPAH@Z' --flags "/O2 /TP"

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
