#!/bin/sh
# Strict byte-match verification for batch21/part1.
# Toolchain: ~/.local/share/pc2/vc6-sp3-toolchain/VC98 (C2.DLL 12.00.8447).
# Each check passes the manifest length and entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match true.
# The C++ EH functions use /GX; the compiler-generated .text$x/.xdata$x
# sections are located from the original image's own handler data.
# Usage: sh reconstructed/match/batch21/part1/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
DIR="reconstructed/match/batch21/part1"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; flags=$4; shift 4
    if $M "$address" "$DIR/$address.c" --length "$length" --entry "$entry" \
        --flags "$flags" --strict --auto-symbols "$@" >"$OUT/$address.json" 2>&1; then
        echo "STRICT $address"
        pass=$((pass + 1))
    else
        echo "FAIL   $address"
        cat "$OUT/$address.json"
        fail=$((fail + 1))
    fi
}

check 0x5086e0 155 '?UI_ShiftChildRect@@YIXPAD@Z' '/O2 /TP'
check 0x522f40 155 '?InsertGrow@Array@@QAEHH@Z' '/O2 /TP'
check 0x404460 156 '?ResourceManager_OpenArchivePath@@YAHPAUResourceManager@@PAD@Z' '/O2 /TP' \
    --symbol '?Pak_Open@ResourceManager@@QAEXPAD@Z=0x401af0'
check 0x4a1940 154 '?SaveGame_Scan@@YAXPAUList@@H@Z' '/O2 /TP /GX' \
    --symbol '??0UI_ListEntry@@QAE@HH@Z=0x403370'
check 0x513c90 153 '??0Storage@@QAE@PAUIStream@@@Z' '/O2 /TP /GX' \
    --symbol '??0List@@QAE@H@Z=0x4013a0' \
    --symbol '??1List@@QAE@XZ=0x401480'
check 0x5317b0 152 '?CreateMovieWindow@UI@@QAEHHHHHH@Z' '/O2 /TP /GX' \
    --symbol '??0MovieWindow@@QAE@HHHHPAXPADH0@Z=0x52ae20'

echo "strict matches: $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
