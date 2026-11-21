#!/bin/sh
# Verify every genuine C/C++ candidate in batch02/part2 with the official matcher.
#
# Usage: bash reconstructed/match/batch02/part2/verify_c.sh [report.json]
#
# All 25 candidates are compiled as C++ (/O2 /TP): the original calls
# __thiscall members, which VC6's C front end rejects (and a C __fastcall
# declaration would need a dummy edx argument that the shipped code does not
# materialize).  The matcher rejects inline assembly, so any __asm/asm {
# candidate fails here.
set -eu

PART_DIR=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
ROOT=$(CDPATH= cd -- "$PART_DIR/../../../.." && pwd)
REPORT=${1:-${TMPDIR:-/tmp}/pc2-batch02-part2.json}

exec python3 "$ROOT/tools/match_batch.py" \
    "$ROOT/reconstructed/match/batch02/part2.json" \
    "$PART_DIR" \
    --flags "/O2 /TP" \
    --json-out "$REPORT"
