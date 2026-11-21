#!/bin/sh
# Re-run the byte match for every genuine C/C++ match of batch01/part1.
# Since tools/match_decomp.py commit 5cb2219c the matcher copies the original
# PE's linker-resolved DIR32/REL32 fields at the same offset, so --symbol is no
# longer required for matching (it is only used by --strict-symbols).
# Usage: sh reconstructed/match/batch01/part1/verify.sh
set -u
cd "$(dirname "$0")/../../../.."
M="python3 tools/match_decomp.py"
fail=0
check() {
    address=$1; length=$2; source=$3; shift 3
    if $M "$address" "$source" --length "$length" "$@" >/tmp/part1-match.json 2>&1; then
        echo "MATCH $address"
    else
        echo "FAIL  $address"
        cat /tmp/part1-match.json
        fail=1
    fi
}

check 0x401020 30 reconstructed/match/batch01/part1/0x401020.c \
  --entry '@StatsPeriodReport_Delete@12'

check 0x401a20 204 reconstructed/match/batch01/part1/0x401a20.c \
  --flags "/O2 /GX /TP" --entry '??1ResourceManager@@UAE@XZ'

check 0x48c1c0 92 reconstructed/match/batch01/part1/0x48c1c0.c \
  --entry '_Object_AbortOrderForTarget@12'

check 0x4cf690 898 reconstructed/match/batch01/part1/0x4cf690.c \
  --flags "/O2 /TP" --entry '?RestaurantInfoPanel_UpdateTabButtons@@YAXPAXH@Z'

check 0x4d3710 30 reconstructed/match/batch01/part1/0x4d3710.c \
  --entry '@Character_Delete@12'

check 0x4e4320 30 reconstructed/match/batch01/part1/0x4e4320.c \
  --entry '@BuildingValue_Delete@12'

check 0x4fecc0 367 reconstructed/match/batch01/part1/0x4fecc0.c \
  --flags "/O2 /TP" --entry '?AI_UpdateAdvertisingCampaigns@@YIHPAXHH@Z'

check 0x509060 57 reconstructed/match/batch01/part1/0x509060.c \
  --entry '@UI_SetChildRecordVariant@12'

check 0x5316b0 49 reconstructed/match/batch01/part1/0x5316b0.c \
  --entry '@UI_ShowChildByID@12'

exit $fail
