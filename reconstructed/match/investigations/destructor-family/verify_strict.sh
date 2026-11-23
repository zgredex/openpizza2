#!/bin/sh
# Strict verification for the generated sound-destructor family.
# The generator writes one source per class, compiles with the pinned VC6
# toolchain and requires strict_match for every class.
# Run from the repository root:
#   sh reconstructed/match/investigations/destructor-family/verify_strict.sh
set -u
cd "$(dirname "$0")/../../../.."
OUT=$(mktemp -d)
trap 'rm -rf "$OUT"' EXIT
python3 tools/generate_destructor_family.py \
    --spec reconstructed/match/investigations/destructor-family/destructors.json \
    --out "$OUT"
