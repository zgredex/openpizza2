# batch14 part1 worklog

Target: `game/fastfood2.exe`, MSVC 6.0 SP3 (`C2.DLL 12.00.8447`).
All accepted candidates are genuine C/C++ built with `/O2 /TP`, no inline
assembly.

Status: **15 / 25 strict matches** (`"strict_match": true` with
`tools/match_decomp.py ... --strict --auto-symbols` and the manifest length).
This part is **not complete**: ten manifest records are either recorded under
`nonmatching/` or not yet implemented, so the directory is left uncommitted.

## Strict matches

| address | function | bytes | notes |
|---|---:|---:|---|
| 0x4037d0 | Profiler_StopTimer | 114 | `extern "C" __declspec(dllimport)` `timeGetTime`; use `elapsed > max` so the operands are `cmp eax,ecx` |
| 0x47a850 | Stats_GetMatrixVariantValue | 115 | switch emits the 4-entry jump table at 0x47a8c4; four `int[2][9]` matrices |
| 0x485820 | Game_UpdateAmbientLight | 116 | `low[1]` / `high[1]` place the two tables at 0x2db0/0x2db4; positive `!=` branch shape |
| 0x49f500 | RecipeMenu_ShowSelectedRecipe | 116 | both `SetText` calls merge to one call site; member `QueueControlCommand` |
| 0x4a4a60 | CompanyOverview_AssignEmployeeToBuilding | 115 | local `manager` keeps `ecx=[game+0x90]` before the pushes |
| 0x4a4ae0 | Guard_RemoveFromRestaurant | 115 | same shape with `DAT_00581224` |
| 0x4af2f0 | Glossary_ShowIngredientDetail | 116 | reload `DAT_0057d654` for every field; do not cache the entry pointer |
| 0x4b5a40 | BranchScreen_SelectBranchRecord | 114 | class names `Window_GadgetNotify_Text`, `Sound`, `UI`, `IDMap` drive auto-symbol resolution |
| 0x4c51b0 | CityInfo_UpdateDemandRatingBars | 114 | do/while over 8 bars; `Rating_UpdateBarByKey` is cdecl |
| 0x4cd8e0 | MapList_AddIniRecord | 115 | explicit `--symbol _FUN_005570c0=0x5570c0`; the `for` loop hoists `record+0x40` after the count test |
| 0x500ec0 | UI_WaitForMenuSelection | 114 | `MenuSelection` struct forces the 0x10-byte frame and the `local_8` word store |
| 0x510030 | Stats_SumValuesByCategory | 115 | float accumulator in `st0`; `IDMap` record fields at +0x10/+0x14 |
| 0x522dc0 | UI_TrimTextToWidth | 114 | use `text[0]` for the pre-loop character; keeps `[eax+edi]` addressing |
| 0x5340d0 | Record_GetScreenRect48 | 115 | `double (*)[19]` rows; second access must use `records[entry]` |
| 0x537d80 | Renderer_ConstructChild | 114 | `for (index=0; index<5; index++) child[index]=0;` unrolls to the two-zero-register original |

## Nonmatching attempts (kept under `nonmatching/`)

| address | function | diffs | first difference |
|---|---:|---:|---|
| 0x4e3fb0 | FurnitureType_Construct | 33 | 0x4f: original `0x42` (`[edx+0x70]`) vs candidate `0x43` (`[ebx+0x58]`); the best attempt keeps the strcpy destination live so the prologue/strcpy half matches, but the slot loop uses immediates instead of `esi/edi` |
| 0x4ddd60 | Company_RemoveRecipe | 11 | 0x23: branch displacement differs; final invalidate reloads `this` through `ebx` (`mov ebx,[esp+0x10]; mov ecx,ebx`) where the original loads `ecx` directly |
| 0x508070 | Object_ScrollViewToObject | 13 | 0x53: the `ScrollToClamped` argument loads are scheduled in a different order (view first vs `local_8/local_4` first) |
| 0x47fd90 | Branch_GetBuildingValue | 7 | 0x4b: `push esi` vs `mov ecx,edi`; the member call sets `this` before pushing the stack argument |
| 0x4d2200 | MapObject_Destroy | 78 | 0x00: original `push 0xffffffff` vs candidate `push ebp`; explicit `__try/__finally` forces a frame pointer, while auto member destruction omits the EH sections |
| 0x4ed3c0 | Map_ClampScrollY | 65 | 0x2c: minimum computation and store schedule differ (`mov` vs `add`) |
| 0x4ff5d0 | AI_HireCourier | 2 | 0x56: original `mov eax,[esp+0x10]` vs candidate `mov edx,[esp+0x10]` (and `push eax` vs `push edx`) for the target argument |
| 0x54ac40 | UI_AdvanceChildProgress | 7 | 0x52: clamp store order differs (`mov eax,ecx` vs `mov [esi+0x14],0`) |

## Not implemented yet

`0x5049a0 Person_ConstructFromSave`, `0x54d612 Stream_BeginRead`.

## Verification

```sh
sh reconstructed/match/batch14/part1/verify_strict.sh
# strict 15/15

python3 tools/match_batch.py reconstructed/match/batch14/part1.json \
  reconstructed/match/batch14/part1 \
  --symbols reconstructed/match/batch14/part1/symbols.json \
  --flags "/O2 /TP" --strict --auto-symbols
```

`symbols.json` contains only the unnamed helper at 0x5570c0 used by 0x4cd8e0.
