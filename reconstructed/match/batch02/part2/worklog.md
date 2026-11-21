# batch02/part2 worklog

Part 2 of batch 2: 25 tiny functions (8-18 bytes) from `../part2.json`.
Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (`wine CL.EXE`, C2.DLL
12.00.8447).

Verification (from the repository root):

```sh
bash reconstructed/match/batch02/part2/verify_c.sh
```

Result on the final tree: **25/25 genuine C/C++ candidates match**
(`tools/match_batch.py`, `/O2 /TP`, manifest lengths). No `__asm`/`asm {` and
no `--symbol` map is needed: every relocation is linker-resolved from the
original PE.

## Matched (25)

| address | name | bytes | entry | notes |
|---|---|---|---|---|
| 0x4a1af0 | SaveGameList_Destroy | 12 | `?SaveGameList_Destroy@@YAXXZ` | `IDMap_DestroyAllObjects(&DAT_0057cfc8)`; cdecl push/call/pop ecx |
| 0x4a8450 | Personnel_GetTrainingLevel | 18 | `?Personnel_GetTrainingLevel@@YAHH@Z` | index 0 returns through the bare `ret`; `test/jne/ret/mov/inc/ret` |
| 0x4aa690 | CompanyMenu_InitPolicePage | 12 | `?CompanyMenu_InitPolicePage@@YAXPAX@Z` | cdecl wrapper to Window_UpdatePolicePage 0x4c4e30 |
| 0x4b0d40 | Personnel_Load | 17 | `?Personnel_Load@@YAXPAUCRT_IStream@@@Z` | C++ `CRT_IStream::Read(&DAT_0056a6d8, 4)` thiscall |
| 0x4b0d60 | Personnel_Save | 17 | `?Personnel_Save@@YAXPAUCRT_OStream@@@Z` | C++ `CRT_OStream::Write(&DAT_0056a6d8, 4)` thiscall |
| 0x4b63f0 | StaffCosts_UpdatePage | 12 | `?StaffCosts_UpdatePage@@YAXPAX@Z` | cdecl wrapper to AnnoyancesPage_FillCosts 0x4b5ac0 |
| 0x4bb650 | FurniturePriceMenu_Init | 16 | `?FurniturePriceMenu_Init@@YAXPAX@Z` | two cdecl args: page, 1; `add esp,8` |
| 0x4c0d40 | WarehouseProduct_Load | 17 | `?WarehouseProduct_Load@@YAXPAUCRT_IStream@@@Z` | same stream shape, `&DAT_0057d714` |
| 0x4c0d60 | WarehouseProduct_Save | 17 | `?WarehouseProduct_Save@@YAXPAUCRT_OStream@@@Z` | same stream shape, `&DAT_0057d714` |
| 0x4c3c70 | Lookup_BytePlusOne | 18 | `?Lookup_BytePlusOne@@YAHH@Z` | identical shape to 0x4a8450, table `0x57d73c` |
| 0x4cb390 | MissionMap_InitList | 13 | `?MissionMap_InitList@@YAXXZ` | `push 0; mov ecx,offset; call` List::Construct |
| 0x4cb3a0 | MissionMap_RegisterCleanup | 12 | `?MissionMap_RegisterCleanup@@YAXXZ` | `CRT_Atexit(0x4cb3b0)`, push/call/pop ecx |
| 0x4cde30 | SaveGame_DestroyList | 12 | `?SaveGame_DestroyList@@YAXXZ` | same as 0x4a1af0, map `0x57df84` |
| 0x4d2a90 | Game_RemoveLocalEntryRecursive | 16 | `?RemoveLocalEntryRecursive@Game@@QAEXH@Z` | C++ member; `add ecx,0x78; push arg; call; ret 4` |
| 0x4d3070 | Entity_SetTileId | 10 | `?Entity_SetTileId@@YIXPAXHH@Z` | fastcall store at +0x24, `ret 4` |
| 0x4d32e0 | MapSprite_ReleaseRecordList | 8 | `?MapSprite_ReleaseRecordList@@YIXPAX@Z` | tail call `add ecx,0x14; jmp Palette_Free` |
| 0x4d3930 | Game_GetRecordField814Value | 9 | `?Game_GetRecordField814Value@@YIHPAX@Z` | forwards this unchanged, `call; add eax,4; ret` |
| 0x4d4120 | Person_SetMotivation | 15 | `?Person_SetMotivation@@YIXPAXHH@Z` | store +0xc, then `Game_ResetPlayerStatsByCity(this)` |
| 0x4d4130 | Person_SetSkill | 15 | `?Person_SetSkill@@YIXPAXHH@Z` | store +0x4, same tail call |
| 0x4d4140 | Person_SetSpeed | 15 | `?Person_SetSpeed@@YIXPAXHH@Z` | store +0x8, same tail call |
| 0x4d4150 | Person_SetHealth | 15 | `?Person_SetHealth@@YIXPAXHH@Z` | store +0x10, same tail call |
| 0x4d4160 | Person_SetPerformance | 15 | `?Person_SetPerformance@@YIXPAXHH@Z` | store +0x3c, same tail call |
| 0x4d42e0 | State_HasPositive | 9 | `?State_HasPositive@@YIDPAX@Z` | returns `char`; `mov eax,[ecx+0x20]; test; setg al; ret` |
| 0x4d6c00 | City_RemovePersonEntry | 15 | `?RemovePersonEntry@City@@QAEXPAH@Z` | C++ member; loads `*person` into edx, push, call |
| 0x4d8d30 | Player_SetSlotFlag18 | 18 | `?Player_SetSlotFlag18@@YIXPAXHH@Z` | `lea eax,[eax+eax*2]`; byte store at `ecx+eax*8+0x10e5` |

## Findings

- VC6's C front end rejects `__thiscall` (C4234), and a C `__fastcall`
  declaration used to model a thiscall member needs a dummy second parameter.
  Passing an explicit `0` for it makes the compiler materialize `xor edx,edx`
  before the call, which the shipped code does not contain.  The four stream
  wrappers, `MissionMap_InitList`, `Game_RemoveLocalEntryRecursive` and
  `City_RemovePersonEntry` therefore model the callee as a C++ member in a
  `struct`/`class`; every candidate is compiled `/O2 /TP`.
- 0x4d42e0 is the only non-obvious source shape.  `int` / `bool` / cast forms
  all emit `mov edx,[ecx+0x20]; xor eax,eax; test edx,edx; setg al; ret`
  (11 bytes).  The shipped 9-byte form keeps the field in `eax`, which needs a
  one-byte return value plus a named `char` local:
  `char positive = field > 0; return positive;`.
- 0x4d32e0 is a `jmp` tail call after `add ecx,0x14`; writing the call as the
  last statement of the function lets VC6 emit it.
- `Person_Set*` all reload nothing after the store: `ecx` still holds `this`,
  so the `__fastcall` reset call is emitted without any argument setup.
- All relocations (`call` targets, absolute data addresses, atexit callback)
  are copied from the original PE by `tools/match_decomp.py`; the candidate
  symbol names only have to make the object compile.

## Unmatched

None.  The eight superseded first attempts (all failing only on the dummy
`edx` argument or on the int-return `setg` shape) are kept under
`nonmatching/` for evidence:

| address | first difference | diff bytes |
|---|---|---|
| 0x4b0d40 | offset 11: original 0xe8 (call) vs 0x33 (`xor edx,edx`) | 3 |
| 0x4b0d60 | offset 11: 0xe8 vs 0x33 | 3 |
| 0x4c0d40 | offset 11: 0xe8 vs 0x33 | 3 |
| 0x4c0d60 | offset 11: 0xe8 vs 0x33 | 3 |
| 0x4cb390 | offset 2: 0xb9 (`mov ecx,imm32`) vs 0x33 | 4 |
| 0x4d2a90 | offset 4: 0x83 (`add ecx,0x78`) vs 0x33 | 8 |
| 0x4d42e0 | offset 1: 0x41 (`mov eax,[ecx+0x20]`) vs 0x51 (`mov edx,...`) | 6 |
| 0x4d6c00 | offset 7: 0xe8 (call) vs 0x33 | 4 |
