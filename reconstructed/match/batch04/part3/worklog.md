# batch04 part3 worklog

Batch 4 part 3 (`reconstructed/match/batch04/part3.json`, 25 functions).
Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (CL 12.00.8168 front end,
C2.DLL 12.00.8447), matcher `tools/match_decomp.py`, flags `/O2 /TP`.

**Result: 25 of 25 functions report `"strict_match": true`.**
`sh reconstructed/match/batch04/part3/verify_strict.sh` re-checks every
record with its manifest length, its exact entry symbol, and
`--strict --auto-symbols`. There are no failed candidates, so
`part3/nonmatching/` is empty.

`python3 tools/match_batch.py reconstructed/match/batch04/part3.json \
reconstructed/match/batch04/part3 --flags "/O2 /TP" --strict --auto-symbols`
also reports `matched 25/25; strict 25/25`.

## Matches

| address | name | length | form / notes |
|---|---|---|---|
| 0x4e5dc0 | ConstructionOrder_StreamConstruct | 25 | member, vtable 0x55c5bc, `ConstructionOrder::Load` |
| 0x4e5df0 | Game_GetPlayerByte8 | 30 | `__fastcall`, key local, `IDMap::Lookup` |
| 0x4e5e10 | Game_GetRecordByteC | 30 | `__fastcall`, key local, `IDMap::Lookup` |
| 0x4e9d70 | Game_Delete | 30 | deleting destructor, `Game::Destroy` + `Mem_Free` |
| 0x4eade0 | IsoMap_Delete | 30 | deleting destructor, `IsoMap::Destroy` + `Mem_Free` |
| 0x4ed310 | Array_SetField4Stride12 | 25 | `__stdcall`, 12-byte stride store |
| 0x4edbd0 | Array_CountValid8 | 30 | `__stdcall`, eight-short `-1` count |
| 0x4f12c0 | Array_PickRandomActiveRecord28 | 28 | member, two unused trailing args (`ret 0xc`) |
| 0x4f6db0 | Game_CompanyManager_Delete | 30 | deleting destructor, class named `Game_CompanyManager` |
| 0x5078b0 | Object_SetChildShort8 | 29 | member, selected child's word at +8 |
| 0x509290 | Screen_AddRecordToPanel | 25 | member, `List::Add` at +0x114 |
| 0x509bf0 | UI_RemoveLastChild | 25 | `__fastcall` returning `void *`, `Array::GetPtr4` |
| 0x509fa0 | State_Is1A1B1C | 27 | `__fastcall`, state 0x1a/0x1b/0x1c |
| 0x50ab10 | Object_ActivateAndSetState | 26 | member, `Object::Activate` + `Object::SetState(2)` |
| 0x50f690 | GamePlan_StreamConstruct | 25 | member, vtable 0x55c688, `GamePlan::LoadRecord` |
| 0x512730 | Product_HasStock | 27 | member returning `int` (`setg`/`mov eax,edx`) |
| 0x5144f0 | Storage_GetFillPercent | 25 | member, `used * 100 / GetCapacity()` |
| 0x520b40 | UI_SetAbsolutePosition | 27 | member, base + delta into +0x30/+0x34 |
| 0x520cd0 | Object_EnsureInit | 26 | `__fastcall`, virtual slot 3, command 0x34 |
| 0x520cf0 | UI_ClearPendingCommand | 26 | `__fastcall`, virtual slot 3, command 0x35 |
| 0x520d70 | Buffer_ReleaseField0C | 28 | `__fastcall`, free +0xc and clear |
| 0x520e60 | UI_ClearPendingClipFlag | 29 | `__fastcall`, `UI::ClipRect` at +0x28 |
| 0x521180 | Object_ClearFieldsA | 27 | `__fastcall`, seven dword clears in original order |
| 0x5230b0 | Array_GetPtr | 27 | member, bounds-checked element load |
| 0x5237e0 | UI_SetChildPosition | 27 | member, child +0x5c/+0x60 |

## Implementation notes

* Every record is a `__thiscall` callee or has an `ecx`-based receiver, so all
  candidates are compiled as C++ (`/TP`) and the receivers are modelled as
  member functions (`__fastcall` free functions where the original has no
  stack arguments and a plain `ret`). Member names were chosen so
  `llvm-undname` output demangles to the shipped symbol names:
  `IDMap::Lookup` -> `IDMap_Lookup`, `Array::GetPtr4` -> `Array_GetPtr4`,
  `Game::Destroy` -> `Game_Destroy`, `UI::ClipRect` -> `UI_ClipRect`,
  `Storage::GetCapacity` -> `Storage_GetCapacity`, and so on.
* `0x4f12c0` really pops three stack arguments (`ret 0xc`). The caller at
  `0x507d30` pushes the two extra arguments; the body only reads the first.
  It is modelled as a member with two unused trailing `int` parameters.
* `0x509bf0` returns `void *`: the zero path is `return 0;` and the body
  returns `Array::GetPtr4(...)`. This produces the original
  `test eax,eax; jne +1; ret` layout; an early `return;` in a void function
  makes VC6 emit `je` over the body instead.
* `0x4e5df0`/`0x4e5e10` need the key in a local before the call. The direct
  expression form puts the global in `ecx`; the local form reproduces
  `mov 0x4(ecx),ecx; mov eax,[0x57c670]; push 0; push ecx; lea 0x74(eax),ecx`.
  The global is declared `extern char *DAT_0057c670`, which `--auto-symbols`
  resolves by the `DAT_0057c670` name.
* `0x512730` returns `int`, not `bool`; a `bool` return adds the extra
  `mov al,dl` before the epilogue.
* The two stream constructors store the vtable constants (`0x55c5bc`,
  `0x55c688`) as numeric literals. Those slots are not in
  `full_game_symbols.json`, and the original instruction is a plain
  `movl $imm32,(%esi)` with no relocation, so no `--symbol` is needed.
* `0x520cd0`/`0x520cf0` use a C++ class with three dummy virtual slots so the
  virtual command lands in slot 3 (`call *0xc(%eax)`) and keeps `ecx` as the
  receiver, matching the original.
* `0x520e60` names the renderer class `UI` so `UI::ClipRect` auto-resolves to
  the shipped `UI_ClipRect`; the receiver struct itself is `ClipOwner`.
* No unresolved symbols and no byte differences; no `--symbol` override is
  used by `verify_strict.sh`.
