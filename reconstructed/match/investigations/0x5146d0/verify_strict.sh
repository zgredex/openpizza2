#!/bin/sh
# Verify the 40,832-byte Language_MapStrings function.
set -eu
cd "$(dirname "$0")/../../../.."
python3 tools/match_decomp.py 0x5146d0 \
  reconstructed/match/investigations/0x5146d0/language_map.c \
  --length 40832 --entry _Language_MapStrings --flags /Od \
  --strict --auto-symbols
