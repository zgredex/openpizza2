#!/bin/sh
# Strict byte-match verification for batch09/part1 (22 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (C2.DLL 12.00.8447).
# Every check passes the manifest length and entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Usage: sh reconstructed/match/batch09/part1/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch09/part1/$address.c" \
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

check 0x4795e0 62 '?GetAverageValue@Stats@@QAEXH@Z' --flags "/O2 /TP"
check 0x49cf50 62 '?Game_SyncSelectedPlayerCompany@@YAXXZ' --flags "/O2 /TP"
check 0x4a53e0 62 '?UI_DrawNeighborhoodCustomerIcons@@YAXPAXH@Z' --flags "/O2 /TP"
check 0x4d2280 62 '?AssignObjectToCell@Map@@QAEXH@Z' --flags "/O2 /TP"
check 0x4d6a90 62 '?FindRecordByFirstField@Map@@QAEPAHH@Z' --flags "/O2 /TP"
check 0x4d80e0 62 '?Game_GetLowestValuePlayer@@YIHH@Z' --flags "/O2 /TP"
check 0x4dc720 62 '?PlaceObjectInPlayerCity@Game@@QAEXPAUMapObject@@H@Z' --flags "/O2 /TP"
check 0x4e3510 62 '?FindPlanByTarget@Game@@QAEPAHH@Z' --flags "/O2 /TP"
check 0x4f2a20 62 '_Object_IsKnownId@4' --flags "/O2"
check 0x54ad80 62 '?UI_DestroyBriefingList@@YIXPAX@Z' --flags "/O2 /TP"
check 0x5548a9 62 '?Heap_InitSmallBlock@@YAHXZ' --flags "/O1 /TP"
check 0x401440 63 '@List_Node_Reset@4' --flags "/O2"
check 0x4aa6c0 63 '?StatisticsBalance_Load@@YAXPAX@Z' --flags "/O2 /TP"
check 0x4aa700 63 '?StatisticsBalance_Save@@YAXPAX@Z' --flags "/O2 /TP"
check 0x4d7600 63 '?FindRecordByField24@Game@@QAEPAHH@Z' --flags "/O2 /TP"
check 0x4e2570 63 '?CollectObjectsByOwner@Game@@QAEXPAUList@@H@Z' --flags "/O2 /TP"
check 0x4f3a90 63 '@Grid_GetRandomRecord28@4' --flags "/O2"
check 0x4f3ad0 63 '@Array_GetRandomRecord28@4' --flags "/O2"
check 0x4f4e90 63 '?ScreenToGridCell@Map@@QAEXHHPAH00@Z' --flags "/O2 /TP"
check 0x5238c0 63 '?Movie_ReleasePlayer@@YIXH@Z' --flags "/O2 /TP"
check 0x47a590 64 '?MaxByRow9x8@Matrix@@QAEHH@Z' --flags "/O2 /TP"
check 0x492440 64 '?CompanyMenu_InitStylePage@@YAXPAX@Z' --flags "/O2 /TP"

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
