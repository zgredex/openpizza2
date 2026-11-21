#!/bin/sh
# Strict byte-match verification for batch09/part2 (21 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (C2.DLL 12.00.8447).
# Every check passes the manifest length and entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Usage: sh reconstructed/match/batch09/part2/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch09/part2/$address.c" \
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

check 0x4c5fc0 64 '?CheatMenu_InitCompanyPage@@YAXPAX@Z' --flags "/O2 /TP"
check 0x4d28b0 64 '?Game_RemoveObjectFromUI@@YIXH@Z' --flags "/O2 /TP"
check 0x4d7e90 64 '?FindIndexByPtr@Array@@QAEHH@Z' --flags "/O2 /TP"
check 0x4dde30 64 '?GetActiveCompanyById@Game@@QAEPAHH@Z' --flags "/O2 /TP"
check 0x4dde70 64 '?FindCompanyIndex@Game@@QAEHH@Z' --flags "/O2 /TP"
check 0x4e2370 64 '?FindSubrecordIndex@Game@@QAEHH@Z' --flags "/O2 /TP"
check 0x50fbe0 64 '_Math_PiecewiseLinear@4' --flags "/O2"
check 0x510600 64 '?Stats_FreeRecordMap@@YIXH@Z' --flags "/O2 /TP"
check 0x5342e0 64 '?SetDoubles48@Record@@QAEHHHH@Z' --flags "/O2 /TP"
check 0x540000 64 '_Stream_Seek@12' --flags "/O2"
check 0x541210 64 '_SoundBuffer_Configure@8' --flags "/O2"
check 0x4a6680 65 '?UI_PrintSignedValue@@YAXPAX0H@Z' --flags "/O2 /TP"
check 0x4cb860 65 '?UI_SetImageFromTemplate@@YAXUTemplateArgs@@@Z' --flags "/O2 /TP"
check 0x4ddde0 65 '?Game_CountActiveCompanies@@YIHH@Z' --flags "/O2 /TP"
check 0x4e3730 65 '?GetLevelReward@Game@@QAEHH@Z' --flags "/O2 /TP"
check 0x4edb70 65 '?ClearRecordFirstBytes@Object@@QAEXPAH@Z' --flags "/O2 /TP"
check 0x50ab70 65 '?Deactivate@Object@@QAEXPAX@Z' --flags "/O2 /TP"
check 0x532890 65 '?SetWindowVisible@UI@@QAEXH@Z' --flags "/O2 /TP"
check 0x535520 65 '?SetMetrics@Text@@QAEXHHH@Z' --flags "/O2 /TP"
check 0x478250 66 '?Game_AverageObjectField0C@@YIHH@Z' --flags "/O2 /TP"
check 0x47aca0 66 '?Rating_ComputePenalty@@YIHH@Z' --flags "/O2 /TP"

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
