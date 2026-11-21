#!/bin/sh
# Strict byte-match verification for batch14/part2 (6 of 25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (C2.DLL 12.00.8447).
# Every check passes the manifest length, the exact decorated entry symbol,
# and requires tools/match_decomp.py --strict --auto-symbols to report
# strict_match. The remaining manifest records are not implemented yet or are
# recorded under nonmatching/; see worklog.md.
# Usage: sh reconstructed/match/batch14/part2/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch14/part2/$address.c" \
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

check 0x489950 117 '?CountPlayerRecordsByField34@Game@@QAEHPAX@Z'
check 0x49c450 117 '?RecipeMenu_ShowRecipeChooser@@YAXXZ'
check 0x4ad2d0 117 '?Stats_SumByStorageMode@@YAMHPAX@Z'
check 0x4d1ba0 117 '?Save@RecipeTopping@@QAEXPAUCRT_Ostream@@@Z'
check 0x4d1c20 117 '?Load@RecipeTopping@@QAEXPAUCRT_Istream@@@Z'
check 0x4e5e30 117 '?Save@ConstructionOrder@@QAEXPAUCRT_Ostream@@@Z'

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
