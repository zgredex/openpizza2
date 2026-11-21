# part1 worklog

Batch 2 part 1 (`reconstructed/match/batch02/part1.json`, 25 functions).
Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (CL 12.00.8168 front end,
C2.DLL 12.00.8447), matcher `tools/match_decomp.py`, default `/O2`.

**Result: 25 of 25 matched as genuine C/C++.** Run
`sh reconstructed/match/batch02/part1/verify_c.sh` to re-check every match.
There are no failed candidates, so `nonmatching/` is empty.

## Matches

| address | name | form / flags |
|---|---|---|
| 0x401300 | NamedLockable_Destroy | C, `__fastcall`, dllimport `DeleteCriticalSection`, `/O2` |
| 0x4029d0 | Resource_GetSize | C, `__stdcall`, `/O2` |
| 0x403190 | Clear_Ptr | C, `__fastcall`, returns the cleared pointer, `/O2` |
| 0x403d40 | Input_LeaveLock | C, `__fastcall` tail call to `CS_Leave`, `/O2` |
| 0x403d60 | MissionBriefing_InitList | C++ member call to `List::Construct`, `/O2 /TP` |
| 0x47ee50 | Branch_InvalidateRatingCache | C, `__fastcall` tail call, `/O2` |
| 0x480060 | Game_UpdateFreeBuildingCount | C++ `BuildingManager` member call, `/O2 /TP` |
| 0x4800c0 | Game_CountFreeBuildingsTypeD | C++ `BuildingManager` member call, `/O2 /TP` |
| 0x482710 | Game_GetGlobalTableValue | C, `__stdcall` table index, `/O2` |
| 0x482810 | Game_RegisterObject | C++ `Game::RegisterObject` (thiscall), `/O2 /TP` |
| 0x482880 | Game_DestroyRootWindow | C++ `Game::DestroyWindowAt` (thiscall), `/O2 /TP` |
| 0x482910 | Game_GetActiveScreenOrFallback | C, `__fastcall`, `/O2` |
| 0x483110 | Object_SetField280 | C++ `Object::SetField280` (thiscall), `/O2 /TP` |
| 0x486f20 | Game_MarkObjectsDirtyType6 | C++ `ObjectList` member call, `/O2 /TP` |
| 0x489b10 | Game_GetDateField0C | C, `__fastcall` double indirection, `/O2` |
| 0x4900a0 | BranchMenu_Category_Load | C++ `IStream::Read`, `/O2 /TP` |
| 0x4900c0 | BranchMenu_Category_Save | C++ `OStream::Write`, `/O2 /TP` |
| 0x4919b0 | BranchStats_SeriesFlags_Load | C++ `IStream::Read`, `/O2 /TP` |
| 0x4919d0 | BranchStats_SeriesFlags_Save | C++ `OStream::Write`, `/O2 /TP` |
| 0x492230 | BranchDesign_ColorIndex_Load | C++ `IStream::Read`, `/O2 /TP` |
| 0x492250 | BranchDesign_ColorIndex_Save | C++ `OStream::Write`, `/O2 /TP` |
| 0x4973f0 | Supplier_GetValuePlusOne | C, cdecl, `/O2` |
| 0x499570 | IngredientPanel_Load | C++ `IStream::Read`, `/O2 /TP` |
| 0x499590 | IngredientPanel_Save | C++ `OStream::Write`, `/O2 /TP` |
| 0x4a0a60 | SaveGameMenu_DestroyList | C, cdecl, `/O2` |

## Notes

* `__thiscall` is rejected as a free-function keyword by VC6 in both C and C++
  (C4234), so the thiscall-shaped functions are expressed as real member
  functions and compiled with `/TP`. That is also what the original code must
  have used for the `ret N` cleanup.
* 0x482880 originally emits `lea eax,[ecx+0x264]; push eax; call`. A plain
  `__stdcall` callee makes VC6 shorten it to `add ecx,0x264; push ecx`; the
  `lea eax` form appears only when the callee is a thiscall member that still
  needs `ecx` as `this`. The candidate therefore calls `Game::DestroyWindowAt`.
* 0x401300 stores the vtable as an immediate (`c7 01 ...`); the vtable must be
  declared as an array/address constant, otherwise VC6 loads the data symbol's
  contents instead of its address.
* 0x403190 returns its argument, which accounts for the original
  `mov eax,ecx` before the zero store.
* 0x4973f0's `return 0` reuses the already zero `eax` after `test eax,eax`, so
  the compiler emits a bare `ret`; the C shape reproduces that naturally.
* The batch runner can also be used with `--flags "/O2 /TP"`, which matched
  25/25 for this part as well, but `verify_c.sh` uses per-function flags so the
  pure C functions stay C.
