#!/usr/bin/env bash
# Strict byte-match verification for batch03/part3 (genuine C++ only).
# Uses the shipped VC6 SP3 toolchain through tools/match_decomp.py and counts
# only reports with "strict_match": true.
set -u
cd "$(dirname "$0")/../../../.." || exit 1
REPORT="${1:-/tmp/pc2-batch03-part3-strict.json}"
python3 tools/match_batch.py reconstructed/match/batch03/part3.json \
    reconstructed/match/batch03/part3 --flags "/O2 /TP" \
    --strict --auto-symbols --json-out "$REPORT" >/dev/null || true
python3 - "$REPORT" <<'PY'
import json
import sys

report = json.load(open(sys.argv[1]))
bad = [item for item in report["results"] if not item.get("strict_match")]
print(f"strict matches: {report['strict_matched']}/{report['total']}")
for item in bad:
    detail = (item.get("error")
              or item.get("strict_issues")
              or item.get("relocation_issues")
              or item.get("first_difference"))
    print(f"  {item['address']}: {detail}")
sys.exit(0 if not bad else 1)
PY
