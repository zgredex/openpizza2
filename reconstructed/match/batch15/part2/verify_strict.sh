#!/bin/sh
# Strict verification of the accepted candidates from the paused part audit.
set -u
cd "$(dirname "$0")/../../../.." || exit 1
PART=reconstructed/match/batch15/part2
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

check 0x50d440 133 '?PlayStateSound@Object@@QAEXXZ' '/O2 /TP'
check 0x513ff0 133 '?SettlePendingOrders@Storage@@QAEXXZ' '/O2 /TP'

exit "$failed"
