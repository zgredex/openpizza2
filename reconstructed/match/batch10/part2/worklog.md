# batch10 part2 worklog

Part 2 of batch 10 (`reconstructed/match/batch10/part2.json`, 25 functions,
69-78 bytes each). Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98`
(CL 12.00.8168, C2.DLL 12.00.8447); matcher `tools/match_decomp.py` with
`--strict --auto-symbols`, `/O2 /TP` (C++ member/`__fastcall` forms) unless
noted. Every match below passes the **manifest length** and the exact entry
symbol.

**Result: 22 of 25 functions report `"strict_match": true`.**

```sh
sh reconstructed/match/batch10/part2/verify_strict.sh
# ... 22 x STRICT
# strict 22/22
```

## Matches

| address | name | form / flags |
|---|---|---|
| 0x49f5f0 | RecipeMenu_ChooseRecipe | C++ global, thiscall label update; `if (choice != 0)` fast path to match branch layout |
| 0x49fa20 | RecipeMenu_PrevRecipe | C++ member, wrapped counter clamp |
| 0x4a1aa0 | IDMap_DestroyAllObjects | C++ member, virtual `Destroy` calls through raw pointers |
| 0x4a21a0 | Game_HandleQueryEndSession | C++ member, `volatile` mode field preserves read/store/store order |
| 0x4a36d0 | CompanyMenu_InitBranchOverview | C++ member, thiscall count with two globals |
| 0x4c0b30 | PriceMenu_Init | C++ member slider calls, thiscall `SetValue`/`AttachValueText` |
| 0x4c39f0 | GamePlan_UpdateEffectBars | C++ member, two member calls share the same global `this` |
| 0x4c86a0 | EndResultGraph_SelectCategory | C++ member, `if (index == -1)` first keeps the shipped fall-through |
| 0x4cb900 | FreePlaySetup_ShowMapPreview | C++ member, 64-byte local + deferred `add esp` |
| 0x4ce720 | Movie_PlayGameOverMovie | C++ member, `volatile` flag keeps the store before the sound calls |
| 0x4d2360 | Game_GetObjectBottom | C++ `__fastcall`, `bottom = -1` initializer makes the shipped `or edi,-1` |
| 0x4d2b40 | Entity_ApplyTypeProperties | C++ member, flat `int` type table (`index += 4`) plus reordered property loads |
| 0x4d3490 | CarList_Save | C++ member, `CRT::Ostream_Write` demangles to `CRT_Ostream_Write` |
| 0x4d8090 | Game_GetMostAdvancedCompany | C++ `__fastcall`, loop init sunk below the early-return test |
| 0x4de0d0 | Stats_GetMaxMatrixValue | C++ member, `if (matrix == 0)` block first |
| 0x4de6c0 | Game_CountRecordsByField34 | C++ member, count local kept in a stack slot |
| 0x4de710 | Game_CountRecordsWithFlag16F4 | C++ member, byte flag count |
| 0x4e0830 | Player_CountObjectsByType | C++ member, inner call demangles to `Game_CountObjectsByType` |
| 0x4e3610 | Game_ComputeActionCost | C++ `__fastcall`, `100 - 30*(a+b)` cost formula over integer divide |
| 0x4e3f00 | Game_ComputeAverageSkill | C++ member, sum then `idiv`, explicit `count == 0` guard |
| 0x4e4810 | Map_PickRandomExitDirection | C++ `__fastcall`, `while ((int)value <= 3)` gives `cmp eax,3; jle` |
| 0x4eab00 | World_LoadNameIndexTable | C++ member, 100-byte read buffer and 2500-iteration table loop |

## Notes

* 0x4a21a0 and 0x4ce720 are store-order cases. Marking the one written field
  `volatile` (`GameState::mode` and `DAT_0056b40c`) stops VC6 from sinking the
  constant store below the dependent store / hoisting the next call setup.
* 0x4d2360 only emits the shipped `push edi; or edi,0xffffffff` when `-1` is a
  live local initialized before the `Lookup` call, not an early `return -1`.
* 0x4d2b40 indexes the type table as a flat `int[]`: `index += 4`, checks
  `DAT[index]`, and copies `DAT[index+2]`, `DAT[index+1]`, `DAT[index+3]` in
  that order. This reproduces both the pointer-walking loop and the
  `eax/edx` property load order.
* 0x4d8090 must declare the accumulator inside the post-test block; otherwise
  VC6 hoists `xor edi,edi`/`or eax,-1` and pushes extra registers before the
  early return.
* 0x4de0d0 needs the loops in the `matrix == 0` arm so the early return is
  emitted out of line (`jne`) like the original.
* 0x4e4810's `<= 3` loop condition is what produces `cmp eax,3; jle`; `< 4`
  produces `cmp eax,4; jl`.

## Strict failures kept under `nonmatching/`

`first_diffs.txt` holds the matcher output for each attempt.

| address | name | remaining difference |
|---|---|---|
| 0x4d2fd0 | Game_CanShowObject | 4 of 70 bytes differ; first diff at 0x18: shipped `8b 4e 04` (`mov ecx,[esi+4]`), ours `8b 56 04` (`mov edx,[esi+4]`). The shipped call allocates the `CountRecordsByOwner` argument to `ecx`, pushes it, then loads the receiver into `ecx`; VC6 picks `edx` for every equivalent source shape tried (direct cast, local `IDMap*`, intermediate `void*`, field/array forms). |
| 0x4d3020 | MapObject_SetCityFromPlayer | 14 of 73 bytes differ; first diff at 0x36 (offset 54): shipped `8b 4c 24 08` loads the `Record*` receiver into `ecx` before `xor eax,eax; push eax; mov eax,[esi+0x24]; push eax`; ours loads the cell index into `ecx` first and only then the receiver. The city arm (including the relocation at 0x40) matches; only the `slot == -1` tail differs. |
| 0x4e3d80 | Advertising_StopCampaign | 41 of 74 bytes differ; first diff at 0x15: shipped `push esi` reserves `esi` for the third parameter across the six stores (`mov esi,[esp+0x14]` later, `pop esi` before the tail branch); ours reuses `ecx` after the stores, shifting the whole tail. The `__stdcall` Gangster call and flag computation already match. |

No inline assembly was used; all three failures are VC6 register-allocation
or scheduling differences on otherwise equivalent C++.
