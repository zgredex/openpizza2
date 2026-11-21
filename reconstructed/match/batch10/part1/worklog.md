# batch10 part1 worklog

Target: `game/fastfood2.exe`, MSVC 6.0 SP3 (`C2.DLL 12.00.8447`), all
candidates genuine C++ (`/O2 /TP`), no inline assembly.

Result: **24 / 25 strict matches** (`"strict_match": true`) with
`tools/match_batch.py --strict --auto-symbols` and with
`verify_strict.sh` (which also passes explicit `--entry` for every function).

## Strict matches

| address | function | bytes | notes |
|---|---:|---:|---|
| 0x4031b0 | RegistryKey_OpenOrCreate | 75 | 3 dllimport symbols supplied explicitly |
| 0x403300 | UI_ListEntry_ConstructWithValue | 75 | vtable via `DAT_0055c2f8` |
| 0x403370 | UI_ListEntry_Construct | 73 | vtable via `DAT_0055c2f8` |
| 0x403580 | ResetScreenRegistry | 70 | five 100-dword fills |
| 0x40bab0 | Game_UpdateIdleCars | 71 | `__fastcall` one-arg helpers resolve auto |
| 0x477b80 | Branch_ClearAssignedEmployee | 74 | member `ClearObjectFlag20` blocks tail jmp |
| 0x477bd0 | Branch_SetAssignedEmployee | 76 | store parameter before reading slot |
| 0x47a4f0 | Game_SumStatGrid | 71 | `int[9][9]` at 0x188, `grid[c][r]` |
| 0x47a5d0 | Stats_SumFloatMatrix | 73 | initial value read from `DAT_0055c2e4` (0.0f) |
| 0x47a620 | Grid_GetMaxValue | 70 | two-step `value > maximum` keeps max in memory |
| 0x47c370 | IDMap_FindIndexByValue | 73 | count cached in a local |
| 0x47cd30 | Game_FindRecordByPair | 74 | |
| 0x47e0e0 | Branch_EnqueueConstructionOrder | 73 | |
| 0x47e130 | Game_FindRecordByPairChecked | 78 | |
| 0x480bf0 | Game_ContainsObjectPointer | 71 | `pointer == Lookup(...)` operand order |
| 0x480e30 | MapObject_RestoreSignLogoAnimations | 75 | local `slot` forces the argument into ecx |
| 0x482740 | City_Register | 74 | `BuildOccupiedCellList` resolves as `Map::` |
| 0x482790 | Game_AddObjectToRegistry | 70 | switch table 0xe,1a,1b,1c,22,2b-2f |
| 0x483c40 | Game_DestroyCachedScreens | 75 | |
| 0x48cae0 | Game_SetObjectInfoWindowVisible | 69 | `Window::ShowWindowById` / `Window::HideWindowById` |
| 0x48d0c0 | Game_RemoveScreenTimers | 71 | |
| 0x491ea0 | BuildingInfoMenu_Init | 72 | UI method names must undname to `UI_*` |
| 0x4986f0 | Game_ResizeGlobalArray3 | 69 | |
| 0x49b880 | SaveMenu_MenuFileExists | 75 | `if (file != 0) ... return 1; return 0;` |

## Unmatched

`0x481140 Branch_GetCachedBillboards` (70 bytes). The best genuine C++
attempt is `nonmatching/0x481140.c`; it emits the exact success and cached
tails (including `mov edx,eax`) and matches 68/70 bytes. The only difference
is the register used to hold the Lookup key:

```text
0x481152  original 8b 4e 34   mov ecx,[esi+0x34]
0x481152  candidate 8b 56 34  mov edx,[esi+0x34]
0x481157  original 51         push ecx
0x481157  candidate 52        push edx
```

Every natural shape (direct member, local key, reference, inline helper,
unsigned/long/pointer casts, member-array access, base-class access, /O1,
/O2 with /GX /G5 /G6 /Ob1 /Ob2 /Oi /Og /Os /Ot, and /O2 without /Og) keeps
reloading the key into `edx`; forcing a separate cached reload conflicts
with the rest of the bytes. `nonmatching/0x481140_merged_tail.c` is the
straightforward shape, which additionally lets the compiler merge the two
return tails (64 bytes).

## Verification

```sh
python3 tools/match_batch.py reconstructed/match/batch10/part1.json \
  reconstructed/match/batch10/part1 \
  --symbols reconstructed/match/batch10/part1/symbols.json \
  --flags "/O2 /TP" --strict --auto-symbols
# matched 24/25; strict 24/25

sh reconstructed/match/batch10/part1/verify_strict.sh
# strict 24/24 (explicit --entry for every function; 0x481140 excluded)
```

## Tooling notes

- `symbols.json` holds only the three unresolved IAT imports used by
  0x4031b0; everything else is auto-resolved from
  `decompiled_fastfood2_named_v2/full_game_symbols.json`.
- Switch tables emitted after a body must equal the original image bytes;
  0x482790's table is at 0x4827d8/0x4827e0 and drives the case list.
- Helper names matter for auto-symbol resolution: e.g. the show/hide helpers
  must be `Window::ShowWindowById`/`Window::HideWindowById`, and the building
  cell-list helper must be `Map::BuildOccupiedCellList`.
