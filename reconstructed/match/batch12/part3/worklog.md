# batch12 part3 worklog

Target: `game/fastfood2.exe`, MSVC 6.0 SP3 (`C2.DLL 12.00.8447`).
All candidates are genuine C++ (`/O2 /TP`, no inline assembly); the one
function with `new` needs `/GX` for the compiler-generated EH frame.

Result: **23 / 25 strict matches** (`"strict_match": true`) with
`tools/match_batch.py --strict --auto-symbols --flags "/O2 /TP /GX"` and
23/23 with `verify_strict.sh` (which passes `--entry` and per-function flags).

## Strict matches

| address | function | bytes | notes |
|---|---|---:|---|
| 0x47fe70 | Game_HideBuildingOverlay | 94 | `switch (which)` lowers to `dec; jne`; map reload at loop tail |
| 0x489b60 | Game_AdvanceAnimFrame | 94 | `field = field + 1` (not `++field`) keeps store before compare |
| 0x48a270 | Game_FindFreeObjectByType | 94 | four-term `&&` from `State_Is2DOr2E` |
| 0x48e000 | Game_IsPlayerBestInStat | 94 | `if (value == 0) return 0;` shares the return-0 block |
| 0x5142c0 | Storage_ReceivePendingOrder | 94 | `Lookup(0,0)` result kept across the second call |
| 0x4783c0 | Branch_GetPriceRating | 95 | descending 8-iteration sum in `ecx` |
| 0x47e860 | AI_StepToNeighborCell | 95 | duplicated `GetCell` calls tail-merge after the pushes |
| 0x486b80 | Game_CountUnassignedObjectsByClass | 95 | `type == field` operand order (`cmp eax,ecx`) |
| 0x488cc0 | Game_SuspendSimulation | 95 | `f2d14` guarded flag is volatile; keeps store before thread load |
| 0x5052e0 | Person_Save | 95 | `CRT_Ostream_Write`/`MapSprite_Save` named as members |
| 0x507170 | Person_DebugPrintLocation | 95 | `DAT_`/`STR_` auto symbols; first call passes field 0xfc |
| 0x53d6c0 | Sprite_FillTransparentColor | 95 | invert `if`/`else`; `x ? mask : 0` yields `neg/sbb` |
| 0x47ffb0 | Game_GetBuildingConditionCode | 96 | `for (i=0; ...)` keeps the bottom test |
| 0x528510 | UI_ScrollChildByVelocity | 96 | unused first parameter preserved (`ret 8`, `fild [esp+0xc]`) |
| 0x534c30 | UI_SetListEntryPosition | 96 | `__real@8` 1000.0 constant located and verified |
| 0x539ea0 | Renderer_CreateChild | 96 | `new RendererChild(this)`, `/GX`; funclets match 0x55a260 |
| 0x401190 | StatsPeriodReport_Load | 97 | six `CRT_Istream_Read` calls |
| 0x401200 | StatsPeriodReport_Save | 97 | six `CRT_Ostream_Write` calls |
| 0x4781e0 | Game_ComputeRecordMapPercent | 97 | `(sum*100 + 199999) / (count*200000)` strength-reduced |
| 0x538a80 | Renderer_Destroy | 97 | literal vtable 0x55c818; node list walk |
| 0x47e8c0 | Branch_CancelConstructionAt | 98 | no cached grid pointer (original reloads `[this+0x14e0]`) |
| 0x4f5cd0 | CityView_IsCarSpawnCellFree | 98 | `int *array` is a member pointer at 0x4c |
| 0x50ad80 | Game_MoveTypeBObjectsToStateList | 98 | nested `char *base` keeps `mov ecx,ds:..; push; push; add ecx,0x3c` |

## Unmatched

Both attempts are complete, genuine C++ and are kept under `nonmatching/`
with first-diff notes.

| address | function | bytes | diff |
|---|---|---:|---|
| 0x478140 | City_GetProductPriceLevel | 98 | 2 bytes: table index scratch register `ecx` (original) vs `edx` (candidate) at 0x38/0x3a |
| 0x4dd090 | Game_RebuildLocalRecordOwners | 96 | 13 bytes: callee-saved register permutation `{i,map,local}` = `{ebx,ebp,edi}` (original) vs `{ebp,edi,ebx}` (candidate) |

## Verification

```sh
# Manifest-level run (uniform /GX is neutral for the other 22 functions):
python3 tools/match_batch.py reconstructed/match/batch12/part3.json \
  reconstructed/match/batch12/part3 --flags "/O2 /TP /GX" \
  --strict --auto-symbols
# matched 23/25; strict 23/25

# Per-function entries and flags (0x539ea0 = /O2 /TP /GX, rest /O2 /TP):
sh reconstructed/match/batch12/part3/verify_strict.sh
# strict 23/23
```

## Tooling notes

- No explicit `--symbol` maps were needed: IAT imports (`GetCurrentThreadId`,
  `MessageBoxA`-family), decorated C++ member names and `DAT_`/`STR_`
  literals all resolve from the shipped maps. Function-call helpers are
  declared with their symbol-map names so fuzzy resolution is unambiguous.
- `0x539ea0` needs `/GX`; the `.text$x` funclets/stub compiled byte-identical
  to the original at 0x55a260 (`mov ecx,[ebp-0x10]; add ecx,0x114; jmp` /
  `add ecx,0x130` / `mov eax,FuncInfo; jmp __CxxFrameHandler`).
- 0x534c30's literal `1000.0` lands in a `.rdata` COMDAT located through the
  text-relocation anchor and verifies against `0x55c4c8`.
- Register-allocation quirks are load-bearing: 0x488cc0 uses a volatile store
  to keep the guard store ahead of the later thread-pointer load; the two
  unmatched functions are exactly cases where MSVC 6 SP3's scratch/callee-saved
  choice could not be steered by any genuine source shape that was tried.
