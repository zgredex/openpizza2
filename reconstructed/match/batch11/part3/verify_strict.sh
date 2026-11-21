#!/bin/sh
# Strict byte-match verification for batch11/part3 (23 of 25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (C2.DLL 12.00.8447).
# Every check passes the manifest length and exact entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# 0x4897c0 (City_GetListEndpoints) and 0x5091c0 (UI_SetListEntryHalfScale)
# are not included; their best genuine C++ attempts and first-diff output are
# under nonmatching/. 0x54db85 needs /Oy- /Os (size-tuned frame scheduling).
# Usage: sh reconstructed/match/batch11/part3/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch11/part3/$address.c" \
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

check 0x401790 87 '?RemoveByKey@IDMap@@QAEHH@Z' --flags "/O2 /TP"
check 0x47eed0 84 '?SettleDueConstructionOrders@Branch@@QAEXH@Z' --flags "/O2 /TP"
check 0x47fe10 84 '?ShowBuildingOverlay@Game@@QAEXH@Z' --flags "/O2 /TP"
check 0x486ec0 84 '?GetPreviousPlayerSlot@Game@@QAEHHD@Z' --flags "/O2 /TP"
check 0x495500 86 '?Game_RebuildObjectTypeLists@@YAXXZ' --flags "/O2 /TP"
check 0x4c2950 85 '?MarketShareMenu_Init@@YAXPAH@Z' --flags "/O2 /TP"
check 0x4d2ae0 85 '?CountFreeBuildingsByType@Game@@QAEHH@Z' --flags "/O2 /TP"
check 0x4d3280 84 '?Destroy@Car@@QAEXXZ' --flags "/O2 /TP"
check 0x4d4070 86 '?SetRecordOpenState@Game@@QAEXD@Z' --flags "/O2 /TP"
check 0x4ddeb0 86 '?GetActiveCompanyOrdinal@Game@@QAEHH@Z' --flags "/O2 /TP"
check 0x4e23b0 84 '?FindRecordByCityId@Player@@QAEPAURecord@@PAX@Z' --flags "/O2 /TP"
check 0x4ed040 84 '?AliasPixelPlanes@Surface@@QAEXXZ' --flags "/O2 /TP"
check 0x4ed360 84 '?ClampScrollY@UI@@QAE_NH@Z' --flags "/O2 /TP"
check 0x4fb600 84 '?Stats_SumRecordCounts@@YGXPAUIDMap@@PAH1@Z' --flags "/O2 /TP"
check 0x502120 85 '?Game_GetPlayerSatisfactionBand@@YAHXZ' --flags "/O2 /TP"
check 0x502eb0 86 '?HasBuildingForPlayer@Game@@QAE_NXZ' --flags "/O2 /TP"
check 0x507d30 85 '?StepToRandomCell@MapObject@@QAEXXZ' --flags "/O2 /TP"
check 0x50a0b0 84 '?SetBuildingRecordForAllCompanies@Object@@QAEXHH@Z' --flags "/O2 /TP"
check 0x513980 84 '?Map8To5@Index@@QAEHH@Z' --flags "/O2 /TP"
check 0x520bc0 85 '?HitTestChild@UI@@QAEHHH@Z' --flags "/O2 /TP"
check 0x532520 85 '?ClearAll@UI_Group@@QAEHXZ' --flags "/O2 /TP"
check 0x5472a0 84 '?SetPosition@Sound@@QAEXHHM@Z' --flags "/O2 /TP"
check 0x54db85 86 '?WriteBytes@File@@QAEHPAEH@Z' --flags "/O2 /TP /Oy- /Os"

echo "strict $pass / $((pass + fail))"
[ "$fail" -eq 0 ]
