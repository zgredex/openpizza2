# batch09 part1 worklog

Part 1 of batch 9 (`reconstructed/match/batch09/part1.json`, 25 functions).
Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (CL 12.00.8168, C2.DLL
12.00.8447); matcher `tools/match_decomp.py` with `--strict --auto-symbols`;
default `/O2`, `/TP` for C++ member functions.

**Result: 22 of 25 functions report `"strict_match": true`.** Run
`sh reconstructed/match/batch09/part1/verify_strict.sh` to re-check every
match; it passes each manifest length and the exact entry symbol. The three
remaining candidates are under `part1/nonmatching/`.

## Matches

| address | name | form / flags |
|---|---|---|
| 0x4795e0 | Stats_GetAverageValue | C++ member, two calls then signed divide, `/O2 /TP` |
| 0x49cf50 | Game_SyncSelectedPlayerCompany | C++ member call plus UI command, `/O2 /TP` |
| 0x4a53e0 | UI_DrawNeighborhoodCustomerIcons | C++ member calls with an `int[8]` local, `/O2 /TP` |
| 0x4d2280 | Map_AssignObjectToCell | C++ member, id-map lookup then cell tag, `/O2 /TP` |
| 0x4d6a90 | Map_FindRecordByFirstField | C++ member, `for` scan over the id map, `/O2 /TP` |
| 0x4d80e0 | Game_GetLowestValuePlayer | C++ `__fastcall`, six-slot minimum scan, `/O2 /TP` |
| 0x4dc720 | Game_PlaceObjectInPlayerCity | C++ member with two stack args, `/O2 /TP` |
| 0x4e3510 | Game_FindPlanByTarget | C++ member, plan type/target match, `/O2 /TP` |
| 0x4f2a20 | Object_IsKnownId | C `__stdcall` id classifier, `/O2` |
| 0x54ad80 | UI_DestroyBriefingList | C++ `__fastcall` list teardown, `/O2 /TP` |
| 0x5548a9 | Heap_InitSmallBlock | C++ `__cdecl` heap pool init, `/O1 /TP` |
| 0x401440 | List_Node_Reset | C `__fastcall` buffer release and reset, `/O2` |
| 0x4aa6c0 | StatisticsBalance_Load | C++ member stream reads, `/O2 /TP` |
| 0x4aa700 | StatisticsBalance_Save | C++ member stream writes, `/O2 /TP` |
| 0x4d7600 | Game_FindRecordByField24 | C++ member, `for` scan on field 0x24, `/O2 /TP` |
| 0x4e2570 | Game_CollectObjectsByOwner | C++ member, owner filter then `List::Add`, `/O2 /TP` |
| 0x4f3a90 | Grid_GetRandomRecord28 | C `__fastcall`, random 40-byte record, `/O2` |
| 0x4f3ad0 | Array_GetRandomRecord28 | C `__fastcall`, same over offset 0x114, `/O2` |
| 0x4f4e90 | Map_ScreenToGridCell | C++ member, quotient/remainder of a cell index, `/O2 /TP` |
| 0x5238c0 | Movie_ReleasePlayer | C++ `__fastcall`, critical section and virtual release, `/O2 /TP` |
| 0x47a590 | Matrix_MaxByRow9x8 | C++ member, 9x8 matrix maximum, `/O2 /TP` |
| 0x492440 | CompanyMenu_InitStylePage | C++ group create plus button state, `/O2 /TP` |

## Notes

* 0x5548a9 only matches at `/O1`: `/O2` emits `mov eax,[global]; push eax` and
  `mov dword ptr [g],0`, while the shipped code uses `push dword ptr [g]` and
  `and dword ptr [g],0`, which is the VC6 `/O1` form. The entry is
  `?Heap_InitSmallBlock@@YAHXZ`.
* 0x4795e0 needs the `if (count > 0) {...} else {...}` spelling: an early
  `if (count < 1) return` produces `cmp ecx,1; jge`, but the original is
  `test ecx,ecx; jle` with the zero store at the tail.
* 0x4d6a90 and 0x4d7600 peel a `do/while` but not a `for` loop; the `for`
  spelling gives the single call site and the reloaded bound.
* 0x4f3a90/0x4f3ad0 need the `if (ptr != 0) { ... return ...; } return 0;`
  shape so VC6 puts the zero return after the main body (`je` to the tail).
* 0x4f4e90 has five parameters; the member entry demangles with
  `QAEXHHPAH00` (two `int *` plus one `int *` for the fifth argument).
* 0x5238c0 needs a virtual `Release(int)` declaration so VC6 emits
  `mov eax,[ecx]; push 1; call [eax]`; `CS_Enter`/`CS_Leave` resolve through
  class `CS`.

## Strict failures kept under `nonmatching/`

| address | name | remaining difference |
|---|---|---|
| 0x535cb0 | Palette_FindIndex | `repz cmpsd` compare is right, but the hoisted `*value` load lands in `esi` instead of the shipped `edx`, pushing `push esi` one slot earlier: first diff offset 9 (`8b` vs `56`), 42 bytes differ and the extent is 96 bytes |
| 0x551981 | Stub_ReturnZero | x87 FDIV probe; shipped code spills all three `double` locals with `fld`/`fstp` and branches with `sahf`, while every `/O1`/`/O2`/`/Od` spelling tested folds the locals into the FP stack or copies them with `mov` pairs: first diff offset 0, 48-byte candidate vs 62 |
| 0x50d8f0 | Object_SyncScreenY | same length (63 bytes) but the shipped second hazard test (`test eax,eax; je` at 0x50d907) is removed by VC6's jump threading, so the first `jmp` grows from 2 to 5 bytes: first diff offset 20 (`eb 02` vs `eb 05`) and 37 bytes shift after it |

No inline assembly was used; all three failures are compiler-scheduling or
optimizer differences, not unresolved symbols.
