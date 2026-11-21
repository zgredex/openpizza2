# batch13 part1 worklog

Target: `game/fastfood2.exe`, MSVC 6.0 SP3 (`C2.DLL 12.00.8447`), all
candidates genuine C++ (`/O2 /TP`), no inline assembly.

Result: **12 / 25 strict matches** (`"strict_match": true`) with
`tools/match_batch.py --strict --auto-symbols` and with `verify_strict.sh`
(which also passes the exact `--entry` for every function).

`symbols.json` contains one explicit symbol, `?BuildingMarket_Compare@@YAHPBX0@Z
= 0x4a73e0`. `0x4a73e0` is a real comparator routine reached by the immediate
in `0x4a7370`; it has no entry in `full_game_symbols.json` or the decompile
index, so auto-resolution cannot name it. The address is derived from the
`push 0x4a73e0` operand in the original disassembly.

## Strict matches

| address | function | bytes | notes |
|---|---:|---:|---|
| 0x47d010 | Game_CountAgedAdjacentBuildings | 101 | map count lives at `IDMap+0x14`; loop bound reloaded |
| 0x489750 | Game_FindRecordByTripleKey | 101 | `for` form keeps `jl` loop tail |
| 0x4f5b40 | Object_CanAssignSlot | 101 | `__stdcall`; `value > 0xc8` keeps the reset block fall-through |
| 0x50e2a0 | Person_SetAtWork | 101 | `__fastcall` (ecx=this, edx param); `extern "C"` not needed |
| 0x4a13e0 | SaveGame_NextFreeSlot | 102 | `STR_00568198`/`STR_00563184` resolve by address regex |
| 0x4b0020 | StatisticsBackdrop_UpdateCompanyValues | 102 | declaration order `index, id, entry` matches the three zero/constant moves |
| 0x4dc080 | Mission_ApplySettings | 102 | byte globals for the two `0x57bb34/0x57bb3c` stores |
| 0x500fd0 | UI_RemoveListEntryAt | 102 | inline `list*0x168 + index*0x10` expressions |
| 0x522fe0 | Array_RemoveAt | 102 | `index >= count` operand order; `CS` methods resolve as `CS_Enter/Leave` |
| 0x5247f0 | Window_HandleKeyInput | 102 | virtual call via `virtual Notify` at vtable `+0xc` |
| 0x4a7370 | BuildingMarket_BuildSortedIndex | 103 | explicit comparator symbol; `count*4` and `CRT_QSort` |
| 0x4f6d30 | Game_CompanyManager_Construct | 103 | lock starts at `+0x20`; the `+0x38` field is a raw store inside it |

## Unmatched

All failed candidates are under `nonmatching/`; the table gives the first
differing byte (`original`, `candidate`).

| address | function | bytes | first diff | cause |
|---|---:|---:|---|---|
| 0x54d0b1 | Stream_TryAttachBuffer | 100 | 0: `56`/`53` | original shrink-wraps `push ebx; push edi` into the slow path; VC6 hoists them. Also `cmp [mem],0` vs `mov/test` |
| 0x47e400 | Game_CountOperatingObjectsByType | 101 | 1: `56`/`53` | loop count allocated to `ebx` instead of `edi` |
| 0x47ee60 | Stats_GetAverageFlaggedValue | 101 | 19: `7e`/`7f` | shared `return 0` block placed after the division instead of before it |
| 0x4d28f0 | Game_AddObjectToList | 101 | 78: `4e`/`56` | x coordinate temp in `edx` instead of `ecx` for `SetCellObjectFrame` |
| 0x4e3820 | Game_ComputePlayerSalary | 102 | 16: `0b`/`0c` | original keeps the shared `return -1` between the two type tests |
| 0x4e3890 | Game_ComputePlayerTax | 102 | 16: `0b`/`0c` | same block-order issue as `0x4e3820` |
| 0x4f6fb0 | Game_InitPlayerSlotTables | 102 | 23: `07`/`38` | SIB base/index roles swapped in `mov eax,[edi+eax]` |
| 0x534150 | RecordList_TickFrame | 102 | 12: `51`/`50` | reload of `records` uses `add` instead of `lea`; one byte shifts the tail |
| 0x4c6780 | UI_WarpCursorToControl | 103 | 36: `89`/`8b` | store of the x local scheduled after the next load |
| 0x4d82b0 | Game_PickBestScoredRecord | 103 | 54: `40`/`50` | `scoreIndex` temp uses `edx` instead of `eax`; table loaded into `eax` |
| 0x4dca00 | Weather_SelectRandomState | 103 | 34: `8d`/`8b` | `DAT_0056ca28[next]` index/scale register order |
| 0x4ed500 | Object_Compare | 103 | 56: `4c`/`44` | original `abs` expansion uses `cdq`; VC6 emits `sar` for the explicit idiom |
| 0x513a90 | Company_GenerateNameFromTopProduct | 103 | 4: `8b`/`55` | `company` kept in `ebp` instead of being reloaded from the argument slot |

The unmatched sources are the best genuine C++ attempts; packing bounds and
all relocations are otherwise correct. No inline assembly was used.
