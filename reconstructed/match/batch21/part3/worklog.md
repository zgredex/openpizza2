# batch21 part3 worklog

Scope: 8 functions from `reconstructed/match/batch21/part3.json`.
Toolchain: `~/.local/share/pc2/vc6-sp3-toolchain/VC98` (MSVC 6.0 SP3,
C2.DLL 12.00.8447). `sh reconstructed/match/runtime01/verify_strict.sh`
reported 6/6 before this work. Every accepted function is genuine C/C++ and
passes `tools/match_decomp.py --strict --auto-symbols` with the manifest
length and the exact candidate entry symbol.

Flush toolchain: `/O2 /TP`; matcher: `--strict --auto-symbols`.

## Strict matches

| address | function | bytes | entry | notes |
|---|---:|---:|---|---|
| 0x54b070 | MessageList_FindFreeSlot | 156 | `?FindFreeSlot@MessageList@@QAEHPAH@Z` | `memset` (declared manually) reproduces `rep stos` 9 dwords; writing `entry[3] + addend` in both the condition and the assignment lets CSE produce the original `lea eax,[ecx+edx]` |
| 0x4dd4f0 | GameCalendar_Save | 157 | `?Save@GameCalendar@@QAEXPAVOStream@@@Z` | eleven sequential `OStream::Write` calls; last argument is the data label `DAT_0057dfbc` |

Reproduce with:

```sh
sh reconstructed/match/batch21/part3/verify_strict.sh
```
