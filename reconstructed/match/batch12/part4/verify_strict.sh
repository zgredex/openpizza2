#!/bin/sh
# Strict verification of the accepted candidates from the paused part audit.
set -u
cd "$(dirname "$0")/../../../.." || exit 1
PART=reconstructed/match/batch12/part4
failed=0

check() {
    address=$1 length=$2 entry=$3 flags=$4
    shift 4
    if result=$(python3 tools/match_decomp.py "$address" "$PART/$address.c" \
        --length "$length" --entry "$entry" --flags "$flags" --strict --auto-symbols "$@" 2>&1); then
        printf 'STRICT %s\n' "$address"
    else
        printf 'FAIL %s\n%s\n' "$address" "$result"
        failed=1
    fi
}

check 0x48a200 99 '?CountFreeSlots@Game@@QAEHH@Z' '/O2 /TP'
check 0x4d8780 99 '?CountRecordsByOwner@Game@@QAEHPAX@Z' '/O2 /TP'
check 0x4e28e0 99 '?ResetBuildingUtilization@Game@@QAEXXZ' '/O2 /TP'
check 0x4e29b0 99 '?AdvanceProductionCounter@Game@@QAEXXZ' '/O2 /TP'

exit "$failed"
