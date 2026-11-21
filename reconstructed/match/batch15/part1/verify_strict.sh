#!/bin/sh
# Strict byte-match verification for batch15/part1.
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (C2.DLL 12.00.8447).
# Each check passes the manifest length and entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# The eight functions in nonmatching/ are genuine C/C++ attempts that differ
# from the shipped bytes; see nonmatching/*.json for first-diff evidence.
# 0x54e170 (_strstr) is the hand-written VC6 CRT assembly routine and has no
# genuine C reconstruction.
# Usage: sh reconstructed/match/batch15/part1/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch15/part1/$address.c" \
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

check 0x4f9c10 128 '_City_FindMatchingCity@4' --flags "/O2 /TP"
check 0x4fcc30 128 '?AdjustShortPercent@Object@@QAEXHF@Z' --flags "/O2 /TP"
check 0x523d60 128 '?ShowWindowById@UI@@QAEXH@Z' --flags "/O2 /TP"
check 0x525af0 128 '?ProcessCommandQueue@UI@@QAEXXZ' --flags "/O2 /TP"
check 0x5271d0 128 '?ReleaseRefCount@UI@@QAEXH@Z' --flags "/O2 /TP"
check 0x54b1b0 128 '?Save@UI@@QAEXPAUStream@@@Z' --flags "/O2 /TP"
check 0x4d2d80 130 '?ClearObjectFlags@Map@@QAEXPAUMapObject@@I@Z' --flags "/O2 /TP"
check 0x4e5eb0 130 '?Load@ConstructionOrder@@QAEXPAUStream@@@Z' --flags "/O2 /TP"
check 0x4ed780 130 '?AlignSpriteToRect@UI@@QAEXPAHPAX00@Z' --flags "/O2 /TP"
check 0x4f9d50 130 '_Building_GetLevelFromType@4' --flags "/O2 /TP"
check 0x507d90 130 '?AdvanceRoute@Person@@QAEHH@Z' --flags "/O2 /TP"
check 0x5272f0 130 '?ShowTooltip@UI@@QAEXPAXHH@Z' --flags "/O2 /TP"
check 0x480ab0 131 '?RemoveAndRefund@Branch@@QAEXPAUMapObject@@@Z' --flags "/O2 /TP"
check 0x488b30 132 '?CollectByCategory@Ingredient@@QAEPAUList@@D@Z' --flags "/O2 /TP /GX"
check 0x521a50 132 '?DrawRectOutline@UI@@QAEXHHHHI@Z' --flags "/O2 /TP"
check 0x4b43f0 133 '_CompanyOverview_SortCompanyIndices' --flags "/O2 /TP" \
    --symbol '_Compare0=0x4b4480' \
    --symbol '_Compare1=0x4b4510' \
    --symbol '_Compare2=0x4b45b0'

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
