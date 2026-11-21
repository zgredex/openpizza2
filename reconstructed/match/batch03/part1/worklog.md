# batch03 part1 worklog

Batch 3 part 1 (`reconstructed/match/batch03/part1.json`, 25 functions).
Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (CL 12.00.8168 front end,
C2.DLL 12.00.8447), matcher `tools/match_decomp.py`, default `/O2`
(`/O2 /TP` for the C++ member functions).

**Result: 25 of 25 functions report `"strict_match": true`.** Run
`sh reconstructed/match/batch03/part1/verify_strict.sh` to re-check every
match; it passes each manifest length and the exact entry symbol and uses
`--strict --auto-symbols`. There are no failed candidates, so
`part1/nonmatching/` is empty.

## Matches

| address | name | form / flags |
|---|---|---|
| 0x401150 | Record_SumFloatArray26 | C, `__fastcall`, 26-float sum, `/O2` |
| 0x401170 | Object_SumFloat25 | C, `__fastcall`, 25-float sum, `/O2` |
| 0x4032e0 | RegistryKey_Close | C, `__fastcall`, dllimport `RegCloseKey`, `/O2` |
| 0x4781b0 | Rating_GetInverse100 | C, `__fastcall`, `/O2` |
| 0x479ae0 | Game_ComputeCityConditionScore | C, `__fastcall`, 64-bit callee result cast to byte, `/O2` |
| 0x47c3c0 | Array_Copy68 | C++ member, 0x68-dword struct copy, `/O2 /TP` |
| 0x47c590 | Array_ClearStride34 | C, `__fastcall`, `/O2` |
| 0x47d210 | Game_AddObjectToStateList | C++ member call to `List::Add`, `/O2 /TP` |
| 0x47db10 | Stats_Increment2D | C++ member, `/O2 /TP` |
| 0x47f400 | RecordMap_Lookup1998 | C++ member call to `IDMap::Lookup`, `/O2 /TP` |
| 0x480740 | Object_AccumulateIncome | C, `__fastcall`, `/O2` |
| 0x4808a0 | Game_SetChildField94 | C++ member, `/O2 /TP` |
| 0x486e00 | Window_UnlockState | C, `__fastcall` tail call to `CS_Leave`, `/O2` |
| 0x48c000 | Game_HasQueuedEventType | C++ member call to `IDMap::FindByField34`, `/O2 /TP` |
| 0x48c020 | Game_HasKeyedRecordEntry | C++ member call to `Array::FindEntryByKeys`, `/O2 /TP` |
| 0x48c040 | Game_SetMessageField34 | C++ member call to `MessageList::SetField34`, `/O2 /TP` |
| 0x49f1c0 | UI_RemoveObjectByOffsetKey | C++ member call to `UI::RemoveObjectByKey`, `/O2 /TP` |
| 0x49f1e0 | RecipeKitchen_ShowPlacedIngredient | C++ member call to `UI::ShowChildByID`, `/O2 /TP` |
| 0x4c70f0 | UI_SetOnlineHelpText | C++ member call to `Window::GadgetNotify_Text_SetText`, `/O2 /TP` |
| 0x4d3450 | Car_Save | C++ member call to `MapSprite::Save`, `/O2 /TP` |
| 0x4d3910 | Game_GetRecordByField814 | C++, member call to `IDMap::Lookup`, `/O2 /TP` |
| 0x4d42c0 | State_HasFlags | C, `__fastcall`, byte return, `/O2` |
| 0x4d6ad0 | Game_LookupObjectByIndex | C++ member call to `IDMap::Lookup`, `/O2 /TP` |
| 0x4d75b0 | SaveGame_LookupSavedId | C++ member call to `Map::LookupLinear`, `/O2 /TP` |
| 0x4d8120 | Game_GetOwnedObjectByIndex | C++ member call to `IDMap::Lookup`, `/O2 /TP` |

## Notes

* Every `ret N` callee is a real `__thiscall`; VC6 rejects `__thiscall` as a
  free-function keyword, so those callers are written as C++ member functions
  and compiled with `/TP`. The member names were chosen so the mangled symbols
  demangle to the names in `full_game_symbols.json` (for example
  `IDMap::Lookup` -> `IDMap_Lookup`), which is what `--auto-symbols` resolves.
* `0x401150`/`0x401170` add single-precision floats, so their return type is
  `float`, not the decompiler's `float10`. The initial value is the shared
  `0.0f` constant at `0x55c2e4`; it is spelled as a direct dereference so the
  instruction stays `fld DWORD PTR ds:0x55c2e4` without an extra relocation.
* `0x4032e0` calls `RegCloseKey` through the IAT. Its undefined object symbol
  `__imp__RegCloseKey@4` cannot be resolved from the shipped name table, so
  `verify_strict.sh` supplies `--symbol __imp__RegCloseKey@4=0x55c010`. The
  slot is independently verified by the PE import table and the
  `PTR_RegCloseKey_0055c010` name in the leaf evidence.
* `0x47c3c0` is a copy of a 0x68-dword field. A plain struct assignment
  reproduces the original `push esi; push edi; rep movsd; pop edi; pop esi`
  exactly; calling `memcpy` did not (no headers/intrinsics are available in the
  toolchain tree).
* `0x4d42c0` returns a one-byte flag. Assigning the second comparison to a
  local `unsigned char` first avoids the `xor eax,eax; ... setg al` sequence
  VC6 emits for a direct `return (value > 0)`; the original keeps the loaded
  word in `eax` and only executes `test eax,eax; setg al`.
* `0x4d3910` needs `key` to stay in `ecx` while the game pointer is loaded into
  `eax` (`lea ecx,[eax+0x3c]`). The empty `if (key) ;` is a source-level
  scheduling barrier that preserves that register allocation; the lookup itself
  is unconditional, exactly as in the original bytes. Without it VC6 loads the
  key into `eax` and emits `add ecx,0x3c`, which differs from the target.

## Reproduce

```sh
sh reconstructed/match/batch03/part1/verify_strict.sh
```
