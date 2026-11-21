# batch04 part1 worklog

Batch 4 part 1 (`reconstructed/match/batch04/part1.json`, 25 functions).
Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (CL 12.00.8168 front end,
C2.DLL 12.00.8447), matcher `tools/match_decomp.py`, default `/O2`
(`/O2 /TP` for the C++ member functions).

**Result: 25 of 25 functions report `"strict_match": true`.** Run
`sh reconstructed/match/batch04/part1/verify_strict.sh` to re-check every
match; it passes each manifest length and the exact entry symbol and uses
`--strict --auto-symbols`. There are no failed final candidates, so
`part1/nonmatching/` is empty.

## Matches

| address | name | form / flags |
|---|---|---|
| 0x401000 | StatsPeriodReport_StreamConstruct | C++ member constructor, vtable store, optional `Load`, `/O2 /TP` |
| 0x401420 | List_Node_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x401a00 | ResourceManager_ScalarDeletingDestructor | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x402240 | Pak_SortEntries | `__stdcall` wrapper around `CRT_QSort`, `/O2` |
| 0x402ef0 | FileObject_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x403350 | UI_ListEntry_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x4034b0 | Random_Mod | unsigned `rand() % modulus` guard, `/O2` |
| 0x403a40 | TimerClass_ScalarDeletingDestructor | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x403b90 | List_FindByKey | C++ member linear list search, `/O2 /TP` |
| 0x476fe0 | Branch_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x477100 | Clamp_0_100 | `__stdcall` two-sided clamp, `/O2` |
| 0x47c7b0 | Object_SetIndex171C | C++ member, store plus two clears, `/O2 /TP` |
| 0x47d230 | Screen_AddRecordToList | C++ member call to `List::Add`, `/O2 /TP` |
| 0x47d250 | Game_QueueObjectTask | C++ member call to `List::Add`, `/O2 /TP` |
| 0x47eba0 | Game_AddRecordTo19C4 | C++ member, record clear before `List::Add`, `/O2 /TP` |
| 0x47fd70 | Game_IsCurrentPlayer | C `__fastcall`, byte return, literal game global, `/O2` |
| 0x4817a0 | GameWorld_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x482720 | Game_GetPlayerCount | C `__fastcall`, six-slot `do/while`, `/O2` |
| 0x482820 | Game_GetCurrentPlayerCompanyName | C `__fastcall`, indexed player lookup, `/O2` |
| 0x482840 | Game_GetPlayerField8 | C++ member indexed lookup, `/O2 /TP` |
| 0x482860 | UI_DestroyWindowAt | C++ `__stdcall` free function, member `DestroyChild`, `/O2 /TP` |
| 0x488be0 | Game_GetPlayerBySlot | C++ member bounds-checked lookup, `/O2 /TP` |
| 0x488d90 | Game_GetTimeSegment | C `__fastcall`, byte / 3, `/O2` |
| 0x49e5e0 | Stats_SortCategoryIndexArray | guarded `CRT_QSort` over `DAT_0057cadc`, `/O2` |
| 0x49e680 | CompanyBuildingList_SortIndices | guarded `CRT_QSort` over `DAT_0057cadc`, `/O2` |

## Notes

* The seven scalar deleting destructors (0x401420, 0x401a00, 0x402ef0,
  0x403350, 0x403a40, 0x476fe0, 0x4817a0) use the batch01 C pattern
  `void *__fastcall Delete(void *this, int dummy, unsigned char flags)`, which
  yields the original `push esi; mov esi,ecx; call dtor; test [esp+8],1; ...;
  ret 4` code and a `@Name@12` entry. The destructor and `Mem_Free` calls are
  undefined symbols that `--auto-symbols` resolves by name.
* `0x402240` is `__stdcall` (the original ends in `ret 8`), not the `__cdecl`
  shape the pseudocode suggests. Its comparator is declared as
  `DAT_004021f0`, so the `DAT_<address>` fallback in `--auto-symbols` resolves
  the pushed function pointer to 0x4021f0.
* `0x4034b0` only matches with `if (modulus <= 0) return 0;` (unsigned): VC6
  then emits `test esi,esi; ja <rand body>` with the zero return inline, while
  `== 0`, `!modulus` and the ternary all emit `je`/`jne` and move the body.
* `0x403b90` needs the node layout key at 0x10 and next at 0x14; an extra pad
  dword generated `[eax+0x18]` and failed at offset 18.
* `0x47eba0` is a scheduling-order case: `*record = 0;` must precede
  `records.Add(record)` in the source. With the call first, VC6 keeps `record`
  in `esi` across the call and produces a 32-byte function; the original pushes
  the argument, stores zero, then calls.
* `0x488be0` needs the `slot >= 6` spelling; VC6 canonicalises `slot > 5` to
  `cmp eax,5; jg`, but the original is `cmp eax,6; jge`.
* `0x401000` stores the vtable through `DAT_0055c2e0` (resolved by the
  `DAT_<address>` fallback) and calls the member `Load`; that demangles to
  `StatsPeriodReport_Load`, which is present in the shipped symbol map.
* Member names for the C++ files were chosen so their mangled symbols demangle
  to the names in `full_game_symbols.json` (`List::FindByKey` ->
  `List_FindByKey`, `Game::GetPlayerBySlot` -> `Game_GetPlayerBySlot`, and so
  on), which is what `--auto-symbols` resolves.
* `0x482860` is a `__stdcall` free function that calls
  `Window::DestroyChild`; under `/TP` its entry is
  `?UI_DestroyWindowAt@@YGXPAPAX@Z`. The global window at 0x57c5e0 is
  `DAT_0057c5e0` and resolves through the `DAT_<address>` fallback.
* The two qsort wrappers share the array at 0x57cadc through
  `extern int DAT_0057cadc[]`; both comparators are named after their
  addresses so the pushed function pointers resolve to 0x49e600 / 0x49e6a0.

## Reproduce

```sh
sh reconstructed/match/batch04/part1/verify_strict.sh
```
