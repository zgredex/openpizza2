# batch21 part3 worklog

Scope: 8 functions from `reconstructed/match/batch21/part3.json`.
Toolchain: `~/.local/share/pc2/vc6-sp3-toolchain/VC98` (MSVC 6.0 SP3,
C2.DLL 12.00.8447). `sh reconstructed/match/runtime01/verify_strict.sh`
reported 6/6 before this work. Every accepted function is genuine C/C++ and
passes `tools/match_decomp.py --strict --auto-symbols` with the manifest
length and the exact candidate entry symbol.

Flush toolchain: `/O2 /TP` (0x406cd0 additionally `/GX`); matcher:
`--strict --auto-symbols`.

## Result: 8 / 8 strict matches, 8 attempted, 0 near misses

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
| 0x50f590 | PlayerCompany_InitDefaults | 157 | `?InitDefaults@PlayerCompany@@QAEXXZ` | the 6-dword copy must be written `copy[i++] = *src++;`; the natural `*dst++ = *src++;` makes VC6 C2 merge both induction pointers into `sub ecx,eax` / `[ecx+eax]` (this is also why the reverse function 0x48e0b0 is a known wall) |

Reproduce with:

```sh
sh reconstructed/match/batch21/part3/verify_strict.sh
```

## Commits

* `67806859` — Match 2 of 8 batch21 part3 functions strictly
* `cafb7784` — Match 7 of 8 batch21 part3 functions strictly
* final commit — Match the last function (0x50f590) and finish the worklog

## Toolchain / compiler findings

* **VC6 C2 induction-variable merge.** For a two-pointer copy loop
  `do { *dst++ = *src++; } while (src < END);` C2 replaces `dst` with a
  base+index (`sub ecx,eax` before the loop, `mov [ecx+eax],edx` inside).
  Writing the destination through an index, `copy[i++] = *src++;`, keeps the
  second induction variable and emits the shipped two-increment loop. This is
  the same wall recorded for the reverse function 0x48e0b0 in batch19/part3.
* **VC6 suppresses C++ EH frames for `extern "C"` functions.** 0x406cd0
  carries an `fs:[0]` chain, `__CxxFrameHandler` thunk at 0x557d78 and
  FuncInfo at 0x55d740. The identical body compiled as `extern "C"` has no
  EH at all; giving the function C++ linkage and compiling with `/GX` emits
  the frame. Ctor inline + dtor out-of-line is the combination that matches
  (both inline or both out-of-line changes the scope/state shape).
* **Linking compiler-generated EH sections.** `--auto-symbols` cannot name the
  local `$L`/`$T` labels. Binding them explicitly lets strict mode locate and
  verify `.text$x`/`.xdata$x`: `$L266=0x557d78` (handler),
  `$T265=0x55d740` (FuncInfo), `$T268=0x55d760` (unwind map),
  `$L258=0x557d70` (destructor action thunk); the out-of-line destructor
  (`??1RegistryKey@@QAE@XZ`) is bound to 0x4031a0. The label numbers are
  per-object and shift when unrelated declarations are edited, so keep them
  in sync with the final source.
* `memset` has no include path in the matcher's compile; declaring
  `extern "C" void *__cdecl memset(void *, int, unsigned int);` still lets
  C2 inline the `rep stos` form.
* For `if (a < b)`, swapping the operands to `if (b > a)` is what controls the
  `cmp` operand order (0x501f90, and the same pattern in 0x54b070's max update).
* A dead output temporary (`unsigned long type`) is enough for C2 to reuse the
  incoming argument home slots for the two `RegQueryValueExA` `lpType`
  pointers; a single named local is not required.
