# Batch 10 result

Exact byte matches, genuine C/C++ only, strict gate:

```text
part1  24 / 25
part2  22 / 25
part3  22 / 25
part4  23 / 25
total  91 / 100
```

The nine misses are documented genuine C/C++ attempts under each part's
`nonmatching/` directory: register-allocation/scheduling divergences, one
loop back-edge shape, and one 2-byte stack-argument register choice. No
inline assembly is counted.
