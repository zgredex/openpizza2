#!/usr/bin/env bash
# Strict byte-match verification for batch03/part2 (genuine C++ only).
#
# Runs tools/match_decomp.py once per record with the manifest length, the
# candidate's own mangled entry symbol, /O2 /TP, --strict and --auto-symbols,
# and counts only reports with "strict_match": true.
set -u
cd "$(dirname "$0")/../../../.." || exit 1
DIR=reconstructed/match/batch03/part2

if grep -qE '__asm|asm[[:space:]]*\{' "$DIR"/*.c; then
    echo "inline assembly is not decompiled C" >&2
    exit 1
fi

fail=0
total=0
while read -r address length entry; do
    [ -n "$address" ] || continue
    total=$((total + 1))
    out=$(python3 tools/match_decomp.py "$address" "$DIR/$address.c" \
        --length "$length" --entry "$entry" --flags "/O2 /TP" \
        --strict --auto-symbols 2>&1)
    if printf '%s' "$out" | grep -q '"strict_match": true'; then
        echo "strict MATCH $address $entry"
    else
        echo "STRICT FAIL $address $entry"
        printf '%s\n' "$out" | sed -n '1,40p'
        fail=$((fail + 1))
    fi
done <<'TABLE'
0x4dd650 21 ?SetGlobalWord16@Game@@QAEXG@Z
0x4ddca0 19 ?RemoveObjectReference@Player@@QAEXH@Z
0x4e4160 21 ?GetPair68@Object@@QAEXPAH0@Z
0x4e4180 21 ?FindEmptySlot8@Array8@@QAEXXZ
0x4eacb0 19 ?RemoveIDMapEntry@Game@@QAEXH@Z
0x4eb8e0 22 ?Map_MissingNameFallback@@YAHHH@Z
0x4f2a60 18 ?IsMenuId352@@YG_NH@Z
0x4f3b10 21 ?Array_GetField4Stride12@@YGHHH@Z
0x50d7f0 24 ?GetLevelProperty@Object@@QAEHH@Z
0x50dbd0 22 ?State_Is2DOr2E@@YIHPAX@Z
0x50e4c0 20 ?SetChildField2C@Object@@QAEXH@Z
0x50e520 23 ?ClearCompletedAction@Person@@QAEXXZ
0x50efc0 21 ?Player_ResetAiState@@YIXPAX@Z
0x50fe50 23 ?Game_CountActiveStats@@YIHPAX@Z
0x5104d0 23 ?MapInputIndex@Game@@QAEXH@Z
0x510c70 23 ?Output_StorePair@@YGXPAM0MM@Z
0x5140e0 22 ?ChargePurchaseCost@Storage@@QAEXXZ
0x514220 23 ?HasKey@Array@@QAE_NH@Z
0x514240 23 ?Array_CountNonZero20@@YIHPAX@Z
0x51ea00 21 ?RefPtr_Release@@YIXPAX@Z
0x51ef60 22 ?Object_GetByte36Max7@@YIHPAH@Z
0x521ae0 21 ?GetChildSize@UI@@QAEXPAH0@Z
0x521b10 23 ?Object_GetActiveValue@@YIIPAX@Z
0x522f20 21 ?Destroy@Array@@QAEXXZ
0x5260e0 20 ?Object_GetId@@YGHPAX@Z
TABLE

echo "strict matches: $((total - fail))/$total"
exit $((fail != 0))
