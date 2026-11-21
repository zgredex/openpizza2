# batch06 part3 worklog

Part 3 of batch 6 (`reconstructed/match/batch06/part3.json`, 25 functions).
Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (MSVC 6.0 SP3, C2.DLL
12.00.8447); matcher `tools/match_decomp.py`.

**Result: 25 of 25 functions report `"strict_match": true`** with
`--strict --auto-symbols`, the manifest length and the exact entry symbol.

```sh
sh reconstructed/match/batch06/part3/verify_strict.sh   # strict 25/25
```

`part3/nonmatching/` is empty. `0x531470` also passes one explicit
`--symbol` for the `BinarySearch8` callee because the candidate spells it as
`Array::FindIndex`; strict cannot resolve that mangled name from
`full_game_symbols.json` (which stores the flat name `BinarySearch8`).
The symbol is checked independently, exactly like the `--symbol` maps used by
batch 1.

## Matches

| address | name | form / flags |
|---|---|---|
| 0x47c5b0 | Branch_RemoveConstructionOrder | C++ member (`this` in ecx), ID map + upgrade calls, `/O2 /TP` |
| 0x489820 | Game_GetPlayerSubmapValue | C++ member, null-test before map lookup at 0x148, `/O2 /TP` |
| 0x489850 | Game_GetPlayerMapValue | C++ member, null-test before map lookup at 0x180, `/O2 /TP` |
| 0x48b3c0 | Game_GetDateFields | C++ member, two byte loads into out params, `/O2 /TP` |
| 0x496900 | SaveList_FindIndex | C, `while` over the save-key table, `ret`/cdecl, `/O2` |
| 0x4c0390 | ConstructionMenu_FillTimeLeft | C, five-argument `Gadget_SetTextf` call, `/O2` |
| 0x4f3490 | Rect_Center | C `__stdcall` two-pointer center, `/O2` |
| 0x50a080 | Person_SetRouteToBuilding | C++ member, `rep stosd` route fill, `/O2 /TP` |
| 0x521da0 | RefCounted_Free | C++ `__stdcall`, virtual destroy + `Mem_Free`, `/O2 /TP` |
| 0x52e880 | Window_GetRect | C++ member, four-field rect copy, `/O2 /TP` |
| 0x531470 | Array_SetField14ByKey | C++ member, `Array::FindIndex` call + explicit symbol, `/O2 /TP` |
| 0x5374b0 | Surface_Clear | C++ member, inlined `memset` (extern "C"), `/O2 /TP` |
| 0x479ab0 | Game_UpdateActivePlayerCount | C++ member, two count calls, `/O2 /TP` |
| 0x47fb40 | Branch_EndConstructionMode | C++ member, global player compare, `/O2 /TP` |
| 0x4a19e0 | File_Exists | C, `CRT_Fopen`/`CRT_Fclose` probe, `/O2` |
| 0x4e42c0 | Game_FindGroupSlot | C++ member, six signed-short slots, `/O2 /TP` |
| 0x528190 | UI_QueueChildCommand | C++ member, `UI::QueueCommand` member call, `/O2 /TP` |
| 0x533c60 | Record_ClearActive48 | C++ member, bounds-tested 72-byte record clear, `/O2 /TP` |
| 0x406a60 | UI_CloseLoadingScreen | C++ free function, three UI singleton calls, `/O2 /TP` |
| 0x4befd0 | GangsterWeaponPanel_RefreshWithSound | C, sound event + detail refresh, `/O2 /TP` |
| 0x4dd4a0 | GameClock_Reset | C++ member, duplicate field-0x10 clear required, `/O2 /TP` |
| 0x4f5df0 | Player_MissionState_Construct | C++ constructor, vtable + load/default branch, `/O2 /TP` |
| 0x4fcc00 | Game_AdjustPlayerPercentByKey | C++ member, six-entry key scan, `/O2 /TP` |
| 0x503250 | UI_AppendCommandIfActive | C++ member, two early-outs then `List::Add`, `/O2 /TP` |
| 0x527a50 | UI_ReleasePendingSprite | C++ member, extent clear + virtual release, `/O2 /TP` |

## Notes

- `0x496900` only matched with the pointer-increment `while` form: a
  `do/while` rotated the loop and a `for (entry[index]...)` form loaded the
  table pointer before the count test.
- `0x521da0` and `0x4f3490` are `__stdcall` (`ret 4` / `ret 8`), not cdecl.
- `0x4e42c0` matched only after declaring `int index = 0;` before the slot
  pointer; the original computes the slot from the second argument first.
- `0x4dd4a0` really does store `[this+0x10] = 0` twice; keeping both writes
  in the source is required.
- `0x528190` is a member call (`UI::QueueCommand`) rather than a `__stdcall`
  call: the callee pops 0x14 and reuses the incoming `this` in ecx. Treating
  it as stdcall produced `mov ecx/edx` ordering differences.
- `0x531470` needs `?FindIndex@Array@@QAEHHH@Z=0x531330` on the command line;
  `full_game_symbols.json` only has the flat `BinarySearch8` name.
