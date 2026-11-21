#!/bin/sh
# Strict byte-match verification for batch05/part4 (25 functions).
# Toolchain: /tmp/opencode/vc6-sp3-toolchain/VC98 (CL 12.00.8168, C2.DLL 12.00.8447).
# 25 candidates are strict matches.  The matcher accepts the compiler-generated
# switch tables directly after 0x50d750's 35-byte body when they match the
# original image table bytes.
# Usage: sh reconstructed/match/batch05/part4/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
pass=0
fail=0

check() {
    address=$1; length=$2; entry=$3; flags=$4
    shift 4
    if $M "$address" "reconstructed/match/batch05/part4/$address.c" \
        --length "$length" --entry "$entry" --flags "$flags" \
        --strict --auto-symbols "$@" >"$OUT/$address.json" 2>&1; then
        echo "STRICT $address $entry"
        pass=$((pass + 1))
    else
        echo "FAIL   $address $entry"
        python3 - "$OUT/$address.json" <<'PY'
import json, sys
try:
    result = json.load(open(sys.argv[1]))
except Exception:
    print(open(sys.argv[1]).read())
    raise SystemExit
print("  first_difference:", result.get("first_difference"))
print("  strict_issues:", result.get("strict_issues"))
print("  relocation_issues:", result.get("relocation_issues"))
print("  error:", result.get("error"))
PY
        fail=$((fail + 1))
    fi
}

check 0x48bda0 34 '?OnObjectListSelection@Game@@QAEXXZ' '/O2 /TP'
check 0x4f5770 34 '?SetField2D0C@Record@@QAEXHD@Z' '/O2 /TP'
check 0x526e50 34 '?UI_MarkFullRectDirty@@YIXH@Z' '/O2 /TP'
check 0x534df0 34 '@Surface_FillFF@4' '/O2'
check 0x538f60 34 '?LockAndMark@Surface@@QAEHXZ' '/O2 /TP'
check 0x544ab0 34 '@SoundSystem_Delete@12' '/O2'
check 0x54cc09 34 '?PutByte@Stream@@QAEII@Z' '/O1 /TP'
check 0x54f0e2 34 '_rand' '/O1'
check 0x401f30 35 '_Pak_DecodeIndex@8' '/O2'
check 0x47f5c0 35 '?RemoveBuildingObject@Branch@@QAEXPAX@Z' '/O2 /TP' \
    --symbol '?Remove@List@@QAEXPAXH@Z=0x4d2960'
check 0x482f10 35 '?RemoveWindowForObject@UI@@QAEXXZ' '/O2 /TP' \
    --symbol '?GetObjectId@Window@@QAEHPAUObject@@@Z=0x5260e0' \
    --symbol '?RemoveWindowByID@Window@@QAEXH@Z=0x527f80'
check 0x498100 35 '?CityCompanyList_Load@@YAXPAUStream@@@Z' '/O2 /TP' \
    --symbol '?Read@Stream@@QAEHPAXH@Z=0x54cbc1'
check 0x498130 35 '?CityCompanyList_Save@@YAXPAUStream@@@Z' '/O2 /TP' \
    --symbol '?Write@Stream@@QAEHPAXH@Z=0x54cc2b'
check 0x49acd0 35 '?AdvertisingPanel_Load@@YAXPAUStream@@@Z' '/O2 /TP' \
    --symbol '?Read@Stream@@QAEHPAXH@Z=0x54cbc1'
check 0x49ad00 35 '?AdvertisingPanel_Save@@YAXPAUStream@@@Z' '/O2 /TP' \
    --symbol '?Write@Stream@@QAEHPAXH@Z=0x54cc2b'
check 0x49b460 35 '?CompanyMarketShare_Load@@YAXPAUStream@@@Z' '/O2 /TP' \
    --symbol '?Read@Stream@@QAEHPAXH@Z=0x54cbc1'
check 0x49b490 35 '?CompanyMarketShare_Save@@YAXPAUStream@@@Z' '/O2 /TP' \
    --symbol '?Write@Stream@@QAEHPAXH@Z=0x54cc2b'
check 0x49e5b0 35 '_Save_LoadOrInit' '/O2'
check 0x49ec70 35 '_Save_LoadOrInit2' '/O2'
check 0x4d2a60 35 '?MapRecordToGlobal@Game@@QAEXH@Z' '/O2 /TP'
check 0x4e2250 35 '@Game_FindCityIndex@4' '/O2'
check 0x4e5ff0 35 '?Game_GetRecordByte14@@YIHH@Z' '/O2 /TP'
check 0x4f1250 35 '?GetBufferCount@Object@@QAEHPAH@Z' '/O2 /TP'
check 0x4f5ab0 35 '_Object_EnsureFirstChild@12' '/O2'
check 0x50d750 35 '@State_IsMenuState@4' '/O2'

echo "strict $pass/$((pass + fail))"
[ "$fail" -eq 0 ]
