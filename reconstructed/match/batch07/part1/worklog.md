# batch07 part1 worklog

Batch 7 part 1 (`reconstructed/match/batch07/part1.json`, 25 functions).
Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (CL 12.00.8168 front end,
C2.DLL 12.00.8447), matcher `tools/match_decomp.py` with `--strict
--auto-symbols`, default `/O2 /TP`; 0x54d921 is size-optimized and needs
`/O1 /TP`.

**Result: 24 of 25 functions report `"strict_match": true`.** Run
`sh reconstructed/match/batch07/part1/verify_strict.sh` to re-check every
match; it passes each manifest length and the exact entry symbol. The single
failure, `Rating_ClampAdjusted` (0x4d3f90), is kept with its closest candidate
in `nonmatching/`.

## Matches

| address | name | form / flags |
|---|---|---|
| 0x4e42f0 | BuildingValue_Construct | C++ member ctor, vtable store + `Game::SetHQLevel`, `/O2 /TP` |
| 0x4e4340 | BuildingValue_ConstructDefault | C++ member ctor, field 0xc = -1, `/O2 /TP` |
| 0x4ed330 | Map_SetTileFieldWithDefault | C++ member, default tile byte then `Array::SetField4Stride12`, `/O2 /TP` |
| 0x4f34c0 | UI_ComputeCenteredRect | C++ member, two centered-rect outputs, `/O2 /TP` |
| 0x50be00 | Object_StartOrderAction9 | C++ member, four object/UI calls, `/O2 /TP` |
| 0x50be30 | Courier_StartHeadquartersBombing | C++ member, same call sequence with action 0xc, `/O2 /TP` |
| 0x50bed0 | Person_SendToBranchForAction | C++ member, `GetPlayerValue`, destination, state, `/O2 /TP` |
| 0x50e7a0 | Person_CanContinuePath | C++ member, path visibility test, `/O2 /TP` |
| 0x50fb40 | Game_SetDifficulty | C++ member `switch` over 1..3, `/O2 /TP` |
| 0x52e850 | Renderer_FlushTarget | C++ member, guarded `Sprite::Draw`, `/O2 /TP` |
| 0x53a110 | Renderer_RestoreDisplay | C++ member, COM-style restore then thread wait, `/O2 /TP` |
| 0x543e90 | Sound_QueryFormatType | C++ member, COM format query, `& 0xc`, `/O2 /TP` |
| 0x54a7f0 | Window_MoveToRect | C++ member, `MoveWindow` through IAT global, `/O2 /TP` |
| 0x402260 | ResourceHandle_Alloc | C free `__fastcall`, 20-slot 0x24 scan, `/O2 /TP` |
| 0x403b60 | Input_CompleteEvent | C++ member, `List::FindByKey` + `SetEvent` IAT, `/O2 /TP` |
| 0x49d280 | UI_RemoveAllObjects | C cdecl, `Array::GetRecordByKeyPtr` / `UI::RemoveObject` loop, `/O2 /TP` |
| 0x4e63f0 | Game_ComputeRecordCompanyPrice | C++ member, `IDMap::Lookup` + `Game::ComputePrice`, float, `/O2 /TP` |
| 0x4eab50 | SparseMap_Lookup48 | C++ member, -1 / negative / 2500 bound checks, `/O2 /TP` |
| 0x514080 | Storage_RemoveRecord | C++ member, `Array::FindPair` then two clears, `/O2 /TP` |
| 0x52fef0 | Window_GetGadgetChecked | C++ member, lookup + `DebugConsole_Errorf`, `/O2 /TP` |
| 0x5405b0 | Sound_AllocVoice | C free `__fastcall`, 20-slot voice scan, `/O2 /TP` |
| 0x548480 | Sound_CheckSpeechState | C++ member, two byte guards + game state 4, `/O2 /TP` |
| 0x54d921 | Stream_SetBuffer | C++ member, virtual `Close`, flag update, `/O1 /TP` |
| 0x483fa0 | Game_MapPlayerStatusToAnimation | C `__stdcall`, status-to-animation `switch`, `/O2 /TP` |

## Notes

* All C++ member functions are declared with the class name implied by the
  shipped flat symbol (`Object`, `Person`, `Game`, `UI`, `Window`, `Stream`,
  ...), so `--auto-symbols` demangles the candidate call target back to the
  flat name.  Calls whose `this` is the same object (e.g.
  `BuildingValue::Construct` -> `Game::SetHQLevel`) use an explicit cast on
  `this`.
* `0x4e42f0` / `0x4e4340` store the vtable through `&DAT_0055c5a4`; the
  `DAT_<address>` fallback resolves the immediate relocation.
* `0x50be00` / `0x50be30` reuse the class declarations from batch07 part3
  (`Object::SetFieldA4Locked`, `UI::SetChildState`, ...).
* `0x52e850` calls `Sprite::Draw` with `ecx` already holding the sprite loaded
  by the guard, so the member call is direct, not virtual.
* `0x53a110` uses an explicit `GraphicsVtbl` struct: the original calls through
  `p->vtbl->Restore(p, ...)` (stdcall style), not a C++ virtual call.
* `0x54a7f0` / `0x403b60` access the import table through function-pointer
  globals (`DAT_0055c284` = MoveWindow, `DAT_0055c094` = SetEvent).  Their
  `__stdcall` pointer type removes caller cleanup, matching `call [addr]`.
* `0x5405b0`/`0x402260` require the `for (i = 0; i < 20; i++)` form; VC6
  strength-reduces `i * 0x24` to `lea (i,i,8)` + `lea (base,eax,4)`.
* `0x54d921` only matches with `/O1`: the original uses memory-form
  `and [esi+8], ~4` / `or [esi+8], 4` and `cmp [esi+0x1c], 0`, which the
  /O2 back end lowers to register load/op/store and `mov`+`test`.  The
  `switch`-free branch order is `if (newBuffer != 0) flags &= ~4; else
  flags |= 4;` after the store to `buffer`.
* `0x483fa0`'s `sub eax,5; je` / `sub eax,2; je` chain comes from a
  `switch (status)` with cases 5 and 7 (not an if-chain).
* `0x4e63f0` needs the non-zero test laid out as the fall-through path:
  `if (record != 0) return ComputePrice(...); return DAT_0055c2e4;`.
* `0x4eab50` needs the `key != -1` case last so the `-1` return block is
  emitted out of line; `if (key >= 0x9c4) return 0; return table[...]` gives
  the original `jl`/`xor` order.
* `0x514080`'s `Array::FindPair` call must see the key in a local first;
  otherwise VC6 clobbers `ecx` and reloads `this`.
* `0x4f34c0` needs the top edge computed in a temporary before the left edge;
  writing the stores in pseudocode order gives the wrong register schedule.

## Non-matching

`0x4d3f90` `Rating_ClampAdjusted` (closest candidate in
`nonmatching/0x4d3f90.c`): all values, branches and the clamp are correct, but
the SP5 front end always encodes the low branch as
`lea -0x19(%ecx,%edx)` while the original is
`lea -0x19(%edx,%ecx)` (`8d 44 11 e7` vs `8d 44 0a e7`), and the high branch
as `(base + 4*d) + d` instead of `(d + base) + 4*d`.  Twenty source spellings
(base/value order, parentheses, unsigned/long types, arrays, `/O1`, `/Os`)
all canonicalise to the same two LEAs.  First difference: offset 13,
original `0x0a`, candidate `0x11`; 22 byte differences remain.

```sh
python3 tools/match_decomp.py 0x4d3f90 \
  reconstructed/match/batch07/part1/nonmatching/0x4d3f90.c \
  --length 48 --entry '@Rating_ClampAdjusted@4' --strict --auto-symbols \
  --flags "/O2 /TP"
```

## Reproduce

```sh
sh reconstructed/match/batch07/part1/verify_strict.sh
```
