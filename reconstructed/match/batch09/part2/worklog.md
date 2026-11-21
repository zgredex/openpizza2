# batch09 part2 worklog

Part 2 of batch 9 (`reconstructed/match/batch09/part2.json`, 25 functions).
Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (CL 12.00.8168, C2.DLL
12.00.8447); matcher `tools/match_decomp.py` with `--strict --auto-symbols`;
default `/O2`, `/TP` for C++ member functions.

**Result: 21 of 25 functions report `"strict_match": true`.** Run
`sh reconstructed/match/batch09/part2/verify_strict.sh` to re-check every
match; it passes each manifest length and the exact entry symbol. The four
remaining candidates are under `part2/nonmatching/`.

## Matches

| address | name | form / flags |
|---|---|---|
| 0x4c5fc0 | CheatMenu_InitCompanyPage | C++ member button disable plus panel refresh, `/O2 /TP` |
| 0x4d28b0 | Game_RemoveObjectFromUI | C++ `__fastcall`, window lookup then remove, `/O2 /TP` |
| 0x4d7e90 | Array_FindIndexByPtr | C++ member `for` scan returning the index, `/O2 /TP` |
| 0x4dde30 | Game_GetActiveCompanyById | C++ member, counts only active companies, `/O2 /TP` |
| 0x4dde70 | Game_FindCompanyIndex | C++ member pointer scan, `/O2 /TP` |
| 0x4e2370 | Game_FindSubrecordIndex | C++ member pointer scan (offset 0x180), `/O2 /TP` |
| 0x50fbe0 | Math_PiecewiseLinear | C `__stdcall` two-segment curve, `/O2` |
| 0x510600 | Stats_FreeRecordMap | C++ `__fastcall` reverse free loop, `/O2 /TP` |
| 0x5342e0 | Record_SetDoubles48 | C++ member, `(double)` stores via `fild`, `/O2 /TP` |
| 0x540000 | Stream_Seek | C `__stdcall` three-case seek plus clamp, `/O2` |
| 0x541210 | SoundBuffer_Configure | C `__stdcall` DirectSound vtable calls, `/O2` |
| 0x4a6680 | UI_PrintSignedValue | three merged `SetTextColor` calls, `/O2 /TP` |
| 0x4cb860 | UI_SetImageFromTemplate | C++ member overlay compose from a 50-field block, `/O2 /TP` |
| 0x4ddde0 | Game_CountActiveCompanies | C++ `__fastcall` active-company count, `/O2 /TP` |
| 0x4e3730 | Game_GetLevelReward | C++ member switch over reward kinds, `/O2 /TP` |
| 0x4edb70 | Object_ClearRecordFirstBytes | C++ member buffer-pair walk, `/O2 /TP` |
| 0x50ab70 | Object_Deactivate | C++ member detach and flag clear, `/O2 /TP` |
| 0x532890 | UI_SetWindowVisible | C++ member visibility and queued command, `/O2 /TP` |
| 0x535520 | Text_SetMetrics | C++ member metric triplets, `/O2 /TP` |
| 0x478250 | Game_AverageObjectField0C | C++ `__fastcall` sum over map records, `/O2 /TP` |
| 0x47aca0 | Rating_ComputePenalty | C++ `__fastcall` clamp then negated divide, `/O2 /TP` |

## Notes

* 0x4a6680 is a tail-merging case: the shipped code pushes `0xa000`, `0` and
  `0xff` inside three separate branches and then shares one call sequence, so
  the source must repeat the `SetTextColor` call in all three arms of the
  `if/else` chain. Assigning the colour to a local first makes VC6 fold the
  branches into `neg/sbb/and`.
* 0x4cb860 reads stack arguments 0xa8..0xc8; a by-value 50-`int` struct plus
  the call `ComposeOverlayWindow(a1, a50, a42, a46, a44, a43, a45)` reproduces
  the shipped load/push order exactly.
* 0x50fbe0 needs the `int result; if (...) result = ...; else result = ...;
  return result;` shape; direct `return` expressions change the order of
  `sar edx,3` and `mov eax,edx`.
* 0x541210 needs `int flag = 0; if (enable) flag = 1;`; a ternary gives
  `setne` instead of the shipped `test/je/mov`.
* 0x4d28b0 caches the window id in a local; that reproduces the shipped
  `mov eax,[game+0x2dac]` / `push eax` pair instead of a scratch-register
  copy.
* 0x4edb70 passes `&buffer` (the address of its own parameter) to
  `Object::GetBufferPair`, so the parameter must stay addressable.

## Strict failures kept under `nonmatching/`

| address | name | remaining difference |
|---|---|---|
| 0x4d2320 | Game_GetObjectCenterY | 61 of 64 bytes match; the shipped cell-table base lands in `edx` and the scaled index in `ecx`, VC6 picks the other way round here: `mov eax,[ecx+edx*4]` vs `mov eax,[edx+ecx*4]` |
| 0x4d8610 | AI_AddKnownRecord | 56 of 64 bytes match; the shipped null arm is `xor eax,eax; push eax`, ours is `push 0`, shifting the tail by one byte |
| 0x4e3d30 | Advertising_StartCampaignAgainstPlayer | shipped code loads the campaign argument into `edx` before the player pointer, ours always evaluates the store address first |
| 0x534a30 | Record_SetSlot6_98 | 59 of 65 bytes match; the shipped slot pointer ends in `edx` and the source pointer in `eax`, ours swaps them |

No inline assembly was used; all four failures are register-allocation or
scheduling differences, not unresolved symbols.
