# batch06 part4 worklog

Part 4 of batch 6 (`reconstructed/match/batch06/part4.json`, 25 functions).
Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (MSVC 6.0 SP3, C2.DLL
12.00.8447); matcher `tools/match_decomp.py`.

**Result: 24 of 25 functions report `"strict_match": true`.** The remaining
function is `0x5548e7 Heap_FindBlock`, kept in `nonmatching/0x5548e7.c`.

```sh
sh reconstructed/match/batch06/part4/verify_strict.sh   # strict 24/24
```

`0x531780` and `0x531f50` pass one explicit
`?FindIndex@Array@@QAEHHH@Z=0x531330` symbol because the candidate spells the
`BinarySearch8` callee as `Array::FindIndex`; `full_game_symbols.json` only
has the flat `BinarySearch8` name. The address is checked independently.

## Matches

| address | name | form / flags |
|---|---|---|
| 0x531780 | Array_GetField20ByKey | C++ member, keyed lookup + explicit symbol, `/O2 /TP` |
| 0x547770 | Options_GetGlobalSettings | C `__stdcall`, four global copies, `/O2` |
| 0x401480 | List_Node_Destroy | C `__fastcall` destructor, vtable + two frees, `/O2` |
| 0x403480 | UI_ListEntry_Destroy | C `__fastcall` destructor, vtable + two frees, `/O2` |
| 0x403850 | Math_RoundFloat | C, x87 compare + `__ftol` tail calls, `/O2` |
| 0x4d2fa0 | Map_SetObjectMode | C++ member, mode byte + render call, `/O2 /TP` |
| 0x5080f0 | Object_IsSiteRatingSufficient | C++ member, rating compare (bool via if/return), `/O2 /TP` |
| 0x50bf00 | Gangster_StartProtectionCollection | C++ member, three object calls, `/O2 /TP` |
| 0x50f840 | GamePlan_ComputeAverageEffect | C++ member, eight-category average, `/O2 /TP` |
| 0x50fb70 | GamePlan_SetActiveEffect | C++ member, zero-effect early out, `/O2 /TP` |
| 0x531f50 | UI_SetObjectTextByKey | C++ member, keyed text set + explicit symbol, `/O2 /TP` |
| 0x539230 | Surface_Release | C++ member, COM-style vtable call at 0x80, `/O2 /TP` |
| 0x547270 | Sound_SetVolume | C++ member, virtual device call at 0xf8, `/O2 /TP` |
| 0x54bc90 | UI_RemoveAllBriefings | C++ member, detach + six row clears, `/O2 /TP` |
| 0x4e47e0 | Game_GetMaxIndex4 | C `__fastcall`, four signed score bytes, `/O2` |
| 0x528200 | UI_SetActiveChild | C++ member, virtual deactivate at 0xc, `/O2 /TP` |
| 0x53fc10 | DirectSoundBuffer_Delete | C++ `__fastcall` deleting destructor, `/O2 /TP` |
| 0x49f190 | Game_ClearObjectReferences | C, two global pointer clears, `/O2` |
| 0x4b02d0 | StatisticsBackdrop_RestoreCategorySelection | C++ member calls with a shared pushed 1, `/O2 /TP` |
| 0x4d75d0 | Game_UpdateAndFetchMapEntryFAC | C++ member, ID map update + lookup at 0xfac, `/O2 /TP` |
| 0x4eacd0 | Game_UpdateIDMapEntry | C++ member, ID map update + lookup at 0x2c3f8, `/O2 /TP` |
| 0x520e30 | UI_Child_Activate | C++ member, group select + clip rect, `/O2 /TP` |
| 0x54dca7 | Stream_AllocateAttachedBuffer | C++ member, size-optimized build, `/O1 /TP` |
| 0x4d2e10 | TileDef_TestFlag | C++ member, tile flag test, `/O2 /TP` |

## Nonmatch

`0x5548e7 Heap_FindBlock` (43 bytes): the original keeps the block count in
eax, the `count * 5` temporary in ecx, and subtracts the block end directly
from the address register (`sub edx,[eax+0xc]`). Every genuine C spelling
tried (value and pointer block types, explicit `count`/`end`/`five`
temporaries, `while`/`do`/`for`/`goto` shapes, `/O2 /TP /O1 /Ox /Oa /Ow /Op
/G5 /G6`) assigns the count to ecx and materializes the subtraction in two
registers, so the candidate saves esi/edi and is 21 bytes longer. First byte
difference is offset 0 (original `a1`, candidate `8b`). The closest attempt
is in `nonmatching/0x5548e7.c`.

## Notes

- `0x403850` needed the comparison written as `value >= 0.0f` (with the
  float/double constants taken from their original addresses
  `DAT_0055c2e4` / `DAT_0055c300`) so MSVC emits `jne` to the negative
  half-away-from-zero branch.
- `0x5080f0` has two stack arguments but only uses the first. A
  one-argument member produced `ret 4`; `(Branch*, int unused)` produced
  `ret 8`. `return cond;` generated `setle cl; mov al,cl`; the
  `if (cond) return true; return false;` form generated the original
  `setge al`.
- `0x54dca7` only matches with `/O1 /TP`: `/O2` cleans the `operator_new`
  argument with `add esp,4` and materializes `1` with `mov eax,1`, while the
  original uses `pop ecx` and `push 1; pop eax`.
- `0x4d75d0` / `0x4eacd0` need a real local (`int value = key;`) before
  `map.Update(&value)`; passing `&key` directly omits the original's
  self-store to the argument slot.
- `0x547270` needs the vtable call as an array-indexed function-pointer
  (`((Fn *)device->vtable)[0x3e](...)`) so MSVC emits
  `call dword ptr [ecx+0xf8]` instead of computing `vtable+0xf8`.
- `0x50bf00` must be a C++ member; as a free `__fastcall` the compiler
  reorders `mov ecx,esi` before `push 0x1a`.
