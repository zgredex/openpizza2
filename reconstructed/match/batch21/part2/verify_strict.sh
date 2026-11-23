#!/bin/sh
# Strict byte-match verification for batch21/part2.
# Toolchain: ~/.local/share/pc2/vc6-sp3-toolchain/VC98 (C2.DLL 12.00.8447).
# Each check passes the manifest length and exact entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match true.
# Failed genuine C/C++ attempts are under nonmatching/ with first-diff JSON.
# Usage: sh reconstructed/match/batch21/part2/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; entry=$2
    if $M "$address" "reconstructed/match/batch21/part2/$address.c" \
        --length 156 --entry "$entry" --flags '/O2 /TP' \
        --strict --auto-symbols >"$OUT/$address.json" 2>&1; then
        echo "STRICT $address"
        pass=$((pass + 1))
    else
        echo "FAIL   $address"
        cat "$OUT/$address.json"
        fail=$((fail + 1))
    fi
}

check 0x50f6b0 '?SaveRecord@GamePlan@@QAEXPAVOStream@@@Z'
check 0x50f750 '?LoadRecord@GamePlan@@QAEXPAVIStream@@@Z'
check 0x549e80 '?PlayBuildingSpecialSfx@Sound@@QAEXH@Z'
check 0x50b5e0 '?AssignBranchStaffRole@Person@@QAEXHHHD@Z'
check 0x523930 '?AllocWindowSlot@UI@@QAEHPAH@Z'
check 0x532580 '?SelectMemberByKey@UI_Group@@QAEXH@Z'

echo "strict matches: $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
