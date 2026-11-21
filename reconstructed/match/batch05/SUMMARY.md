# Batch 5 result

Exact byte matches, genuine C/C++ only, strict gate:

```text
part1  25 / 25
part2  25 / 25
part3  25 / 25
part4  25 / 25
total 100 / 100
```

`0x50d750` is matched from its genuine `/O2` C switch; the matcher validates
the compiler-generated jump/byte tables immediately after the 35-byte body
against the original image.
