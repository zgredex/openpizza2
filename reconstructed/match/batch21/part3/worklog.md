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
| 0x4e9d90 | Game_ReleaseConstructionSpriteLists | 157 | `?ReleaseConstructionSpriteLists@Game@@QAEXXZ` | two 0x29-entry pointer arrays 0xc0 apart; `listsA[i]`/`listsB[i]` in a descending-count loop gives the single induction pointer |
| 0x501f90 | Game_GetBestBuildingRatingBand | 157 | `_Game_GetBestBuildingRatingBand` | `if (value > best)` gives the original `cmp eax,edi`; the reverse `<` emits the swapped `cmp edi,eax` |
| 0x527ee0 | UI_BringWindowToFront | 157 | `?BringWindowToFront@UI@@QAEXH@Z` | `cs` is a member pointer at +0x1c8 so it reloads from `this` at each lock call; `windows` has 109 entries before `cs` |
| 0x403200 | RegistryKey_ReadValue | 158 | `?ReadValue@RegistryKey@@QAEPAEPBDPAK@Z` | dead `type` temporary lets VC6 reuse the name/size argument slots for the two `lpType` outputs; `operator new`/`operator delete` resolve from the registry |
| 0x406cd0 | Config_SaveOptionsToRegistry | 158 | `?Config_SaveOptionsToRegistry@@YAXXZ` | needs `/GX`, C++ linkage (VC6 suppresses EH frames for `extern "C"`), inline ctor + out-of-line dtor, and `$L`/`$T` anchors for the EH sections (see toolchain findings) |

Reproduce with:

```sh
sh reconstructed/match/batch21/part3/verify_strict.sh
```
