#!/bin/sh
# Verify every genuine C/C++ candidate in batch02/part4 with the official matcher.
#
# Usage: bash reconstructed/match/batch02/part4/verify_c.sh [report.json]
#
# All 25 candidates are compiled as C++ (/O2 /TP): the original uses
# __thiscall members and VC6's C front end rejects __thiscall.  The matcher
# rejects inline assembly, so any __asm/asm { candidate fails here.
set -eu

PART_DIR=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
ROOT=$(CDPATH= cd -- "$PART_DIR/../../../.." && pwd)
REPORT=${1:-${TMPDIR:-/tmp}/pc2-batch02-part4.json}

exec python3 "$ROOT/tools/match_batch.py" \
    "$ROOT/reconstructed/match/batch02/part4.json" \
    "$PART_DIR" \
    --flags "/O2 /TP" \
    --json-out "$REPORT"
