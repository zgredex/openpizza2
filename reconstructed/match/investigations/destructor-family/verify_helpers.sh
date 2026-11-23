#!/bin/sh
# Strict verification for the shared destructor-family helpers.
set -u
cd "$(dirname "$0")/../../../.."
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
python3 tools/run_family_batch.py \
    --config reconstructed/match/investigations/destructor-family/helpers.json \
    --out "$OUT" --jobs 1
