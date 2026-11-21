# Batch 8 result

Exact byte matches, genuine C/C++ only, strict gate:

```text
part1  23 / 25
part2  24 / 25
part3  23 / 25
part4  22 / 25
total  92 / 100
```

The eight misses are documented genuine C/C++ attempts under each part's
`nonmatching/` directory. They are single-byte SIB/ModRM encodings, branch
polarity, and register-allocation divergences, plus hand-written CRT
assembly. Two jump-table functions pass strict through the matcher's
trailing-table comparison.
