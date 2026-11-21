# Batch 7 result

Exact byte matches, genuine C/C++ only, strict gate:

```text
part1  24 / 25
part2  25 / 25
part3  25 / 25
part4  24 / 25
total  98 / 100
```

Both misses are documented genuine C/C++ attempts under `nonmatching/`:
`0x4d3f90` differs only in one `lea` operand association, and `0x505eb0`
contains a dead compare that this compiler does not emit from C/C++.
