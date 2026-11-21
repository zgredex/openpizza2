# batch08 part2 worklog

Batch 8 part 2 (`reconstructed/match/batch08/part2.json`, 25 functions).
Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (CL 12.00.8168 front end,
C2.DLL 12.00.8447), matcher `tools/match_decomp.py`, default `/O2`
(`/O2 /TP` for C++ member functions).

**Result: 24 of 25 functions report `"strict_match": true`.** Run
`sh reconstructed/match/batch08/part2/verify_strict.sh` to re-check every
match; it passes each manifest length and the exact entry symbol and uses
`--strict --auto-symbols`. The remaining record is kept in
`part2/nonmatching/` and is not a match.

## Matches

| address | name | form / notes |
|---|---|---|
| 0x4ddce0 | Game_FindRecordByField4 | thiscall map search on field 4, `/O2 /TP` |
| 0x4ddd20 | Company_InvalidateAllBranchRatings | thiscall loop over branch records, `/O2 /TP` |
| 0x4e2330 | Game_FindRecordByField34 | thiscall map search on field 0x34, `/O2 /TP` |
| 0x4e3460 | Recipe_SetOnMenu | thiscall menu flag + ratings + UI queue, `/O2 /TP` |
| 0x4ead50 | Game_HideAllLinkedElements | thiscall loop over object records, `/O2 /TP` |
| 0x4ef4b0 | Grid_GetCell | thiscall bounds-checked cell address, `/O2 /TP` |
| 0x5273c0 | SpriteCache_MakeKey | stdcall `_strrchr`/`_strncpy` + `CRT_Strupr`, `/O2` |
| 0x531740 | UI_RemoveObjectByKey | thiscall `BinarySearch8` + clear flag; `--symbol '?BinarySearch8@UI@@QAEHHD@Z=0x531330'`, `/O2 /TP` |
| 0x532850 | UI_PurgeChildFromLists | thiscall `Array::GetPtr`/`RemoveValueLocked` loop, `/O2 /TP` |
| 0x53f840 | SoundFormat_Init | stdcall wave-format header init, `/O2` |
| 0x5414e0 | Input_GetDeviceObjectInfo | cdecl COM object-info query + supported-bit check, `/O2` |
| 0x549970 | Sound_ProcessEventForSelectedObject | thiscall selected-player event forwarding, `/O2 /TP` |
| 0x402990 | Resource_Close | thiscall lock + fclose + clear, `/O2 /TP` |
| 0x403750 | String_RegisterSlot | cdecl slot scan over the global string table, `/O2` |
| 0x48e060 | Game_HasIdleOtherPlayer | thiscall six-slot idle-player scan, `/O2 /TP` |
| 0x4dd050 | Game_RemoveRecordFromAllLocalMaps | thiscall loop over local maps, `/O2 /TP` |
| 0x4dd670 | GameClock_Destroy | thiscall vtable + 400×`Sleep(10)` wait; `--symbol __imp__Sleep@4=0x55c08c`, `/O2 /TP` |
| 0x4e43a0 | Game_SetHQLevel | thiscall dense switch; the 16-byte jump table follows the body and matches the original, `/O2 /TP` |
| 0x500030 | UI_UpdateAllSlots | thiscall six-slot deadline scheduling, `/O2 /TP` |
| 0x5043f0 | UI_DecrementTimer | thiscall dual timer arrays, `/O2 /TP` |
| 0x52e530 | UI_Tooltip_Destroy | thiscall vtable + refcount + free + virtual delete, `/O2 /TP` |
| 0x540260 | SoundStream_Close | thiscall `EnterCriticalSection` (IAT) + fclose + leave; `--symbol __imp__EnterCriticalSection@4=0x55c1b8 --symbol __imp__LeaveCriticalSection@4=0x55c1a0`, `/O2 /TP` |
| 0x547230 | Sound_ClampGlobalLimits | cdecl unsigned clamps of the three global limits, `/O2` |
| 0x54b930 | IDMap_DeleteContents | stdcall map clear with virtual deletes + `List_Node_Reset`, `/O2 /TP` |

## Nonmatching

| address | length | first diff | diagnosis |
|---|---|---|---|
| 0x486e20 | 56 | +0x0a: original `81`, candidate `91` | `Game_CountRecordsForSelectedPlayer`. In the `slot == -1` arm the original reuses EAX (already the slot argument) for `[this+0x2ec]` and loads the record value into EDX; VC6 always keeps the field in EDX and the value in EAX (4 differing bytes). Reassigning `slot`, local copies, member/array forms, and type permutations were tried. Candidate in `nonmatching/`. |

## Notes

* `0x531740` calls `BinarySearch8` (0x531330) as a real `__thiscall` member.
  The caller code (`mov ecx,edi`) requires thiscall, so the mangled member
  name is mapped explicitly in the verify script.
* `0x4e43a0` needed an explicit `case 3:` with the same body as `default:`
  to make VC6 emit the original 4-entry jump table instead of a compare chain.
* `0x4ef4b0` needed `pad2[0x28]` (cells at +0x4c); a larger pad produced
  `[ecx+0x50]`.
* `0x4dd670` and `0x540260` use `extern "C" __declspec(dllimport)` so the
  IAT symbols stay C (`__imp__Sleep@4`, `__imp__EnterCriticalSection@4`)
  rather than C++-mangled.
* `0x5273c0` is `__stdcall` (the original ends in `ret 8`), not cdecl.
* `0x403750` must use the literal array address `(void **)0x579ffc` for the
  scan pointer; using the extern array name made VC6 load the base twice.
  The scan value is the pointer variable `DAT_00563364`.

## Reproduce

```sh
sh reconstructed/match/batch08/part2/verify_strict.sh
```
