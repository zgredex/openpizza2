#!/bin/sh
# Strict byte-match verification for batch10/part4.
# Every check passes the manifest length and exact entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Run from the repository root:
#   sh reconstructed/match/batch10/part4/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; flags=$4; shift 4
    if python3 tools/match_decomp.py "$address" "reconstructed/match/batch10/part4/$address.c" \
        --length "$length" --entry "$entry" --strict --auto-symbols \
        --flags "$flags" "$@" >"$OUT/$address.json" 2>&1; then
        echo "STRICT $address"
        pass=$((pass + 1))
    else
        echo "FAIL   $address"
        cat "$OUT/$address.json"
        fail=$((fail + 1))
    fi
}

check 0x52f080 70 '?Gadget_SetTextf@@YAXPAXHPADH@Z' '/O2 /TP'
check 0x52f9d0 69 '?GadgetNotify_Text_SetLayout@Window@@QAEXHHFFH@Z' '/O2 /TP'
check 0x5314a0 71 '?GetPairByKey@Array@@QAEHHPAH0@Z' '/O2 /TP' \
    --symbol '?BinarySearch8@Array@@QAEHHH@Z=0x531330'
check 0x531910 70 '?SetButtonSpriteByName@Window@@QAEHHPAD@Z' '/O2 /TP'
check 0x5324c0 74 '?RemoveAt@UI_Group@@QAEHH@Z' '/O2 /TP'
check 0x5328e0 70 '?TickChildRepeatTimer@UI@@QAEXH@Z' '/O2 /TP'
check 0x533560 72 '?GetPointPair@Sprite@@QAEDHPAH0@Z' '/O2 /TP'
check 0x534320 72 '?SetRect48@Record@@QAEHHHHN@Z' '/O2 /TP'
check 0x534830 71 '?GetPairPositions@Record@@QAEXHPAHPAUPair@@@Z' '/O2 /TP'
check 0x538780 77 '?ToggleRenderTarget@Renderer@@QAEXXZ' '/O2 /TP'
check 0x539550 69 '?ClearRows@Surface@@QAEXXZ' '/O2 /TP'
check 0x539660 71 '?SetBounds@Surface@@QAEXHHHH@Z' '/O2 /TP'
check 0x539e20 77 '?RemoveByValue@List@@QAEXH@Z' '/O2 /TP'
check 0x53a220 77 '?InitFormat@Sprite@@QAEXFHHHDFF@Z' '/O2 /TP'
check 0x53d600 69 '?BlitWithDefaultAlpha@Sprite@@QAEHHHHHH@Z' '/O2 /TP'
check 0x540a30 73 '?FillFromSample@SoundBuffer@@QAEHPAUSoundSample@@@Z' '/O2 /TP'
check 0x5411c0 77 '?SetVolume@SoundBuffer@@QAEHM@Z' '/O2 /TP'
check 0x5433e0 70 '?Media_SetValue94@@YGHPAUMedia@@H@Z' '/O2 /TP' \
    --symbol '__imp__EnterCriticalSection@4=0x55c1b8' \
    --symbol '__imp__LeaveCriticalSection@4=0x55c1a0'
check 0x5445a0 77 '?StopPlayback@SoundBuffer@@QAEHXZ' '/O2 /TP'
check 0x548300 75 '?PlayTrackIfSelected@Sound@@QAEXH@Z' '/O2 /TP'
check 0x549170 74 '?StopMusic@Sound@@QAEXXZ' '/O2 /TP'
check 0x54c830 75 '?FreeValues@Container@@QAEXXZ' '/O2 /TP'
check 0x54d372 76 '?GetChar@Stream@@QAEHXZ' '/O2 /Os /TP'

echo "strict matches: $pass; failures: $fail"
for known in 0x542b00 0x54b110; do
    echo "known non-matching: $known (see reconstructed/match/batch10/part4/nonmatching/)"
done
[ "$fail" -eq 0 ]
