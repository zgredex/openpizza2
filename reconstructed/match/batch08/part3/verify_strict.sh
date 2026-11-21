#!/bin/sh
# Strict byte-match verification for batch08/part3 (25 functions, 23 matched).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (CL 12.00.8168, C2.DLL 12.00.8447).
# Every check passes the manifest length and the exact entry symbol and requires
# tools/match_decomp.py --strict --auto-symbols to report strict_match.
# Usage: sh reconstructed/match/batch08/part3/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3
    if $M "$address" "reconstructed/match/batch08/part3/$address.c" \
        --length "$length" --entry "$entry" --strict --auto-symbols \
        --flags "/O2 /TP" >"$OUT/$address.json" 2>&1; then
        echo "STRICT $address"
        pass=$((pass + 1))
    else
        echo "FAIL   $address"
        cat "$OUT/$address.json"
        fail=$((fail + 1))
    fi
}

check 0x47ec30 57 '?IDMap_FreeValuesAndReset@@YGXPAUIDMap@@@Z'
check 0x4bd490 57 '?UI_SelectNextObjectOfType@@YAXD@Z'
check 0x4cb7a0 57 '?FreePlaySetup_FillStartCapitalText@@YAXPAUWindow@@@Z'
check 0x4da650 57 '?Game_CollectAllOwnedObjects@@YGXPAXH@Z'
check 0x50e7d0 57 '?ResumeRouteOrDetach@Person@@QAEXXZ'
check 0x527380 57 '?UI_RefreshChildRect@@YIXPAX@Z'
check 0x527a10 57 '?RefreshChildSprite@Container@@QAEXHHH@Z'
check 0x535570 57 '?SetMetrics2@Text@@QAEXHHH@Z'
check 0x53a020 57 '?SetRectAndUpdateChildren@Window@@QAEXHH@Z'
check 0x481010 58 '?SetName@Branch@@QAEXPAD@Z'
check 0x482b30 58 '?UI_ShowAIStatusWindow@@YIXPAX@Z'
check 0x49d150 58 '?Game_GetNthFreePlayerSlot@@YAHH@Z'
check 0x4e1b80 58 '?ResetRecordTurnCounters@Game@@QAEXXZ'
check 0x4f1280 58 '?GetRandomRecord28B@Array@@QAEHPAH@Z'
check 0x4fc0b0 58 '?IDMap_FreeValuesAndDestroy@@YGXPAUIDMap@@@Z'
check 0x509130 58 '?SetChildScale@Object@@QAEXN@Z'
check 0x50ab30 58 '?Activate@Object@@QAEXPAX@Z'
check 0x5105c0 58 '?DeleteAllInMap@Object@@QAEXXZ'
check 0x526f20 58 '?DebugConsole_Errorf@@YAXHHPBDZZ'
check 0x54a770 58 '?SetVisible@Window@@QAEXH@Z'
check 0x54a880 58 '?UI_BriefingList_Construct@@YIPAXPAX@Z'
check 0x402fe0 59 '?FileObject_Destroy@@YIXPAUFileObject@@@Z'
check 0x48bae0 59 '?Game_ShowFindPersonPrompt@@YIXPAUUI@@@Z'

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
