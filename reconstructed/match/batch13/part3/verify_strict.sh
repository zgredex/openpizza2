#!/bin/sh
# Strict byte-match verification for batch13/part3 (16 of 25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (C2.DLL 12.00.8447).
# Every check passes the manifest length and exact entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# The two stream accessors need /O1; every other match uses /O2 /TP.
# Unmatched functions are kept under nonmatching/ with matcher evidence.
# Usage: sh reconstructed/match/batch13/part3/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; shift 3
    if $M "$address" "reconstructed/match/batch13/part3/$address.c" \
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

check 0x54d272 106 '@Stream_GetWritePosition@4' --flags "/O1 /TP"
check 0x54d2dc 106 '@Stream_GetReadPosition@4' --flags "/O1 /TP"
check 0x4da810 107 '?TrackRecentEntry@Player@@QAEXHH@Z' --flags "/O2 /TP"
check 0x501040 107 '?RemoveListEntryByType@UI@@QAEXHHH@Z' --flags "/O2 /TP"
check 0x510390 107 '?GetMaxCategoryValue@Stats@@QAEMH@Z' --flags "/O2 /TP"
check 0x47a7b0 108 '?GetMaxGroupScore@Stats@@QAEMXZ' --flags "/O2 /TP"
check 0x48bf90 108 '_UI_Briefing_Printf' --flags "/O2 /TP"
check 0x50abc0 108 '@Object_CanDetach@4' --flags "/O2 /TP"
check 0x50e730 108 '?AttachToParent@AttachedObject@@QAEXPAXH@Z' --flags "/O2 /TP"
check 0x5334d0 108 '?ReleaseSharedBuffers@List@@QAEXXZ' --flags "/O2 /TP"
check 0x539700 108 '_Win32_PumpMessages' --flags "/O2 /TP"
check 0x54b3d0 108 '?Grow@Array@@QAEHPAX@Z' --flags "/O2 /TP"
check 0x479a40 109 '?ComputeTypeThreeShare@Stats@@QAEXXZ' --flags "/O2 /TP"
check 0x4f5d40 109 '?ReserveCarCell@CityView@@QAEXPAX0@Z' --flags "/O2 /TP"
check 0x507fd0 109 '?ReturnToHomeBase@Person@@QAEXXZ' --flags "/O2 /TP"
check 0x525270 109 '_Window_DefaultProc@16' --flags "/O2 /TP"

echo "strict $pass/$((pass + fail)) of 25 manifest functions"
[ "$fail" -eq 0 ]
