# Batch 3 result

Exact byte matches, genuine C/C++ only, strict gate:

```text
part1  25 / 25
part2  25 / 25
part3  25 / 25
part4  25 / 25
total 100 / 100
```

Every candidate reports `strict_match: true` with `--strict --auto-symbols`.
No inline assembly is counted. Part 4 applies `/O1` only where the shipped
module is genuinely `/O1`; the rest use `/O2 /TP`.

Batch 4 is registered but intentionally not launched.
