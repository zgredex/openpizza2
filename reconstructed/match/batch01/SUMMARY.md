# Batch 1 result

Exact byte matches, C/C++ only (no inline assembly):

```text
part1   9 / 25
part2  15 / 25
part3  12 / 25
part4  17 / 25
total  53 / 100
```

Each part has a `verify_c.sh`/`verify.sh` script carrying the exact `--entry`
and compiler flags. Nonmatching C attempts and assembly transcriptions are
under `<part>/nonmatching/`; they are evidence, not decompiled C.

The remaining 47 functions are concentrated in large UI/state routines where
MSVC 6's register allocation, switch cross-jumping, or EH frame placement did
not converge from C. Batch 2 targets the 100 smallest remaining functions,
where the exact-C hit rate is expected to be much higher.
