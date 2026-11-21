# batch13 part4 worklog

Target: `game/fastfood2.exe`, MSVC 6.0 SP3 (`C2.DLL 12.00.8447`), strict gate
(`tools/match_decomp.py --strict --auto-symbols`). All accepted candidates are
genuine C/C++ (`/TP`), no inline assembly.

Result: **13 / 25 strict matches**, all with `/O2 /TP`.

## Strict matches

| address | function | bytes | notes |
|---|---:|---:|---|
| 0x47eb30 | Branch_PayConstructionOrder | 110 | `price > 0.0f` keeps `fcomp` against the constant |
| 0x4e2a20 | Game_GetMostCommonTypeIndex | 110 | uninitialised `int counts[5]`; `*entry > best` operand order |
| 0x520d90 | UI_SetLabelIdText | 110 | `if (text != 0) ... else ...` block order |
| 0x4db310 | Parse_ReadIntToken | 111 | `String_SkipDelimiters` + `CRT_AtoiThunk`, sign flag |
| 0x51eae0 | UI_ClearChildExtent | 111 | two-int locals passed to `GetSize`/`Union` |
| 0x4d2d10 | Map_SetObjectFlags | 112 | repeated `cell[2]` loads; CS enter/leave around render |
| 0x4f5bb0 | UI_DrawCenteredSelectionRect | 112 | `int rect[4]` plus `rect[2] = rect[0] + 0x3c` |
| 0x531400 | UI_SetObjectRangeByKey | 112 | `BinarySearch8` and `MoveChildToPosition` on the lock |
| 0x4cb7e0 | FreePlaySetup_FillGameLengthText | 113 | `String_Format` is cdecl variadic; 4/3/4 argument branches |
| 0x4d5940 | Map_BuildOccupiedCellList | 113 | `List_Add` / `List_Node_Reset` / virtual destroy |
| 0x4aeac0 | Glossary_BuildingsPage_Init | 112 | `id`/`text` declared after the first three UI calls |
| 0x4e3e80 | Game_FindBestRatedBuilding | 113 | `bestRating` declared first; `if (count > 0) { ... } return best` |
| 0x5476f0 | Sound_InitSpeechVoice | 113 | `strcpy` at +0x174, then four field stores |

`verify_strict.sh` reports **13/13 checked, 13/25 of the manifest**. The same
13 match with `tools/match_batch.py ... --flags "/O2 /TP" --strict --auto-symbols`.

## Unmatched (nonmatching/)

First differences from the stored matcher JSON:

| address | function | first diff | notes |
|---|---:|---|---|
| 0x48e720 | Game_GetPreviousRecordField3C | offset 82: 0x0d vs 0x12 | loop exit/`return 0` block order; 18 bytes |
| 0x48e790 | Game_GetNextRecordField3C | offset 61: 0xf3 vs 0xde | same loop block ordering; 20 bytes |
| 0x4c3000 | Game_HandleMapClickCloseSubmenu | offset 67: 0x28 vs 0x29 | global store uses `mov edx,ds` (6 bytes) instead of `mov eax,ds`/`a1` (5) |
| 0x514510 | Storage_OrderDelivery | offset 39: 0x46 vs 0x4e | `[this+0x34]` reloaded into ecx instead of eax |
| 0x47aba0 | Game_GetMarketBonus | offset 1: 0x8b vs 0x57 | `this` cached in edi instead of esi |
| 0x4de600 | Game_SumPlayerMatrixValues | offset 5: 0x33 vs 0x55 | accumulator in ebp instead of ebx |
| 0x4e2dc0 | Player_ReleaseAssignmentForObject | offset 0: 0x51 vs 0x53 | `for` form removes the peeled body but swaps loop/exit blocks |
| 0x52ffe0 | UI_HitTestTopChild | offset 12: 0x75 vs 0x74 | do-while duplicates the hit-test body |
| 0x530060 | UI_HitTestExcludingChild | offset 12: 0x75 vs 0x74 | same duplicated hit-test body |

## Not attempted / deferred

| address | function | reason |
|---|---:|---|
| 0x496930 | City_RebuildBuildingSortIndexByMode | passes `&LAB_00496160`-style comparator code addresses to `CRT_QSort`; those addresses are absent from the decompile index and both shipped symbol maps, so an explicit `--symbol` cannot be independently derived |
| 0x5221e0 | UI_LabelElement_Destroy | MSVC SEH destructor with vtable COMDAT; no strict candidate completed |
| 0x4d4800 | City_Construct | MSVC SEH constructor with two list subobjects and vtable COMDAT; no strict candidate completed |
