#!/bin/sh
# Strict byte-match verification for batch07/part2 (25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (CL 12.00.8168 front end,
# C2.DLL 12.00.8447).  Default flags are /O2; 0x54dcd4 requires /O1.
# Every check passes the manifest length and the exact entry symbol and
# requires tools/match_decomp.py --strict --auto-symbols to report
# "strict_match": true.  0x531fb0 needs an explicit symbol map for the
# free-function callee BinarySearch8 (0x531330), whose flat symbol name has no
# class prefix and therefore cannot be derived by --auto-symbols.
#
# Usage: sh reconstructed/match/batch07/part2/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch07/part2/$address.c" \
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

check 0x4e34e0 48 '@Player_GetFirstRecordType1@4' --flags "/O2 /TP"
check 0x4eac80 48 '?RegisterWorldObject@Game@@QAEXHH@Z' --flags "/O2 /TP"
check 0x4ffa60 48 '?GetDateStage@Game@@QAEHH@Z' --flags "/O2 /TP"
check 0x508fb0 48 '_Building_MapSubtypeToState@4' --flags "/O2 /TP"
check 0x512700 48 '?AreBothCountsPositive@Array@@QAEHHH@Z' --flags "/O2 /TP"
check 0x520b10 48 '@UI_Child_Destroy@4' --flags "/O2 /TP"
check 0x520f80 48 '@UI_DetachChild@4' --flags "/O2 /TP"
check 0x527cc0 48 '?SetModalHandler@UI@@QAEXHPAUModalWindow@@@Z' --flags "/O2 /TP"
check 0x52e8b0 48 '?SetBackgroundImage@Tooltip@@QAEXPAD@Z' --flags "/O2 /TP"
check 0x52f800 48 '?SetButtonState@Gadget@@QAEXHH@Z' --flags "/O2 /TP"
check 0x52ff50 48 '?Button_SetState@Window_GadgetNotify@@QAEXHH@Z' --flags "/O2 /TP"
check 0x531fb0 48 '?SetChildLabelText@UI@@QAEXHHPAD@Z' --flags "/O2 /TP" \
    --symbol '?BinarySearch8@UI@@QAEHHD@Z=0x531330'
check 0x533a70 48 '?ClearFlags48@Record@@QAEXH@Z' --flags "/O2 /TP"
check 0x535e20 48 '?WriteToStream@Palette@@QAEXPAH@Z' --flags "/O2 /TP"
check 0x542ad0 48 '@Sound_QueryBufferFlag@4' --flags "/O2 /TP"
check 0x54bb00 48 '?ComposeOverlayWindowFromRecord@UI@@QAEXPAXHH@Z' --flags "/O2 /TP"
check 0x54dcd4 48 '?AttachBuffer@Stream@@QAEXHHH@Z' --flags "/O1 /TP"
check 0x401930 49 '?LookupLinear@Map@@QAEHH@Z' --flags "/O2 /TP"
check 0x403150 49 '?FormatObjectNameRandom@Game@@QAEXPADH@Z' --flags "/O2 /TP"
check 0x49bd50 49 '_Player_AddRecipeToMenu' --flags "/O2 /TP"
check 0x4ac3c0 49 '_StatisticsBranchBalance_Load' --flags "/O2 /TP"
check 0x4ac400 49 '_StatisticsBranchBalance_Save' --flags "/O2 /TP"
check 0x4b3ca0 49 '_CompanyOverview_Load' --flags "/O2 /TP"
check 0x4b3ce0 49 '_CompanyOverview_Save' --flags "/O2 /TP"
check 0x4bd450 49 '_UI_SelectPreviousObjectOfType' --flags "/O2 /TP"

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
