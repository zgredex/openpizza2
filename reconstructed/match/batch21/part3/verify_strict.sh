#!/bin/sh
# Strict byte-match verification for batch21/part3.
# Toolchain: ~/.local/share/pc2/vc6-sp3-toolchain/VC98 (C2.DLL 12.00.8447).
# Each check passes the manifest length and entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match true.
# Failed genuine C/C++ attempts are under nonmatching/ with first-diff JSON.
# Usage: sh reconstructed/match/batch21/part3/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch21/part3/$address.c" \
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

check 0x54b070 156 '?FindFreeSlot@MessageList@@QAEHPAH@Z' --flags '/O2 /TP'
check 0x4dd4f0 157 '?Save@GameCalendar@@QAEXPAVOStream@@@Z' --flags '/O2 /TP'
check 0x4e9d90 157 '?ReleaseConstructionSpriteLists@Game@@QAEXXZ' --flags '/O2 /TP'
check 0x501f90 157 '_Game_GetBestBuildingRatingBand' --flags '/O2 /TP'
check 0x527ee0 157 '?BringWindowToFront@UI@@QAEXH@Z' --flags '/O2 /TP'
check 0x50f590 157 '?InitDefaults@PlayerCompany@@QAEXXZ' --flags '/O2 /TP'
check 0x403200 158 '?ReadValue@RegistryKey@@QAEPAEPBDPAK@Z' --flags '/O2 /TP'
check 0x406cd0 158 '?Config_SaveOptionsToRegistry@@YAXXZ' --flags '/O2 /TP /GX' \
    --symbol '??1RegistryKey@@QAE@XZ=0x4031a0' \
    --symbol '$L266=0x557d78' --symbol '$T265=0x55d740' \
    --symbol '$T268=0x55d760' --symbol '$L258=0x557d70'

echo "strict matches: $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
