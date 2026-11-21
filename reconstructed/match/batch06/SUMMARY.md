# Batch 6 result

Exact byte matches, genuine C/C++ only, strict gate:

```text
part1  25 / 25
part2  24 / 25
part3  25 / 25
part4  24 / 25
total  98 / 100
```

Both misses are documented genuine C/C++ attempts under `nonmatching/`:
`0x54efd0 _strrchr` is hand-written CRT assembly, and `0x5548e7
Heap_FindBlock` differs only in the allocator's register assignment.
