# batch13 part3 worklog

Target: `game/fastfood2.exe`, MSVC 6.0 SP3 (`C2.DLL 12.00.8447`), strict gate
(`tools/match_decomp.py --strict --auto-symbols`). All accepted candidates are
genuine C/C++ (`/TP`), no inline assembly.

Result: **16 / 25 strict matches**. The two stream accessors need `/O1`; all
other matches use `/O2 /TP`.

## Strict matches

| address | function | bytes | flags / notes |
|---|---:|---:|---|
| 0x54d272 | Stream_GetWritePosition | 106 | `/O1`; vtable slot +0xc via a virtual stub |
| 0x54d2dc | Stream_GetReadPosition | 106 | `/O1`; same shape, virtual args 0,1,1 |
| 0x4da810 | Player_TrackRecentEntry | 107 | swap target kept as an `int *` local |
| 0x501040 | UI_RemoveListEntryByType | 107 | `for` loop plus `goto found` block order |
| 0x510390 | Stats_GetMaxCategoryValue | 107 | `value > maximum` keeps `fcom` operand order |
| 0x47a7b0 | Stats_GetMaxGroupScore | 108 | `limit <= 0` early-out and a single `finished` label |
| 0x48bf90 | UI_Briefing_Printf | 108 | `UI_Briefing_AddMessage` is cdecl, not thiscall |
| 0x50abc0 | Object_CanDetach | 108 | `RemoveObjectFromList` on two parent slots |
| 0x50e730 | Object_AttachToParent | 108 | `GetRecord28`/`SetChildTracking` member calls |
| 0x5334d0 | List_ReleaseSharedBuffers | 108 | nested `if (!freed)` keeps the pointer load in the loop |
| 0x539700 | Win32_PumpMessages | 108 | dllimport Peek/GetMessage cached in registers |
| 0x54b3d0 | Array_Grow | 108 | `memcpy` expands to `rep movsd`; `return count - 1` tail |
| 0x479a40 | Stats_ComputeTypeThreeShare | 109 | accumulator expression and `if (total > 0)` block order |
| 0x4f5d40 | CityView_ReserveCarCell | 109 | `Map`/`Grid` helper methods cast from `this` |
| 0x507fd0 | Person_ReturnToHomeBase | 109 | `fieldA0 != 0` puts the nonzero path first |
| 0x525270 | Window_DefaultProc | 109 | `switch` on the message lowers to the sub/je chain |

Batch check:

```sh
python3 tools/match_batch.py reconstructed/match/batch13/part3.json \
  reconstructed/match/batch13/part3 --flags "/O2 /TP" --strict --auto-symbols
```

reports 14/25 because the two `/O1` stream accessors are not in that command;
`verify_strict.sh` reports **16/16 checked, 16/25 of the manifest**.

## Unmatched (nonmatching/)

First differences from the stored matcher JSON:

| address | function | first diff | notes |
|---|---:|---|---|
| 0x4d2960 | Game_RemoveObjectFromList | offset 63: 0x46 vs 0x4e | 5 bytes; `Map_SetCellObjectFrame` argument/this load order |
| 0x4ff4c0 | AI_HireBranchWorker | offset 84: `mov eax,[esp+0x10]` vs `mov edx,...` | 2 bytes; target argument stays in edx |
| 0x4dbf50 | Game_GetPlayerSupplyScore | offset 88: 0x85 vs 0x33 | tail is if-converted to `setl/dec/and` instead of three returns |
| 0x510460 | Stats_GetMaxTimelineCategoryValue | offset 33: 0x53 vs 0x55 | `ebx` holds the last index instead of `category` |
| 0x5477a0 | Sound_ApplySettings | offset 1: 0x8b vs 0x8b (this/arg register swap) | `this` in edi, settings in esi; original is the reverse |
| 0x47e6e0 | Map_CollectType351ToList | offset 10: 0x56 vs 0x53 | `this` cached in edi instead of esi |
| 0x532af0 | UI_NotifyObjectsByKey | offset 1: 0x53 vs 0x55 | `this` in edi instead of ebp |
| 0x513f50 | Game_DecayProductValues | offset 0: 0x8b vs 0x53 | compiler emits magic divide plus `idiv` instead of one `idiv` |

## Not attempted / not expressible as C

| address | function | reason |
|---|---:|---|
| 0x539f20 | Surface_ResetFlags | body is an EFLAGS/CPUID probe (`pusha`, `pushf`, `popf`, `cpuid`, bit test) emitted from inline assembly; no genuine C/C++ spelling under the no-asm rule |
