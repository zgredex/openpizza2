# batch11 part3 worklog

Target: `game/fastfood2.exe`, MSVC 6.0 SP3 (`C2.DLL` 12.00.8447), all
candidates genuine C++ (`/TP`), no inline assembly.

Result: **23 / 25 strict matches** (`"strict_match": true`) with
`tools/match_decomp.py --strict --auto-symbols` and with
`verify_strict.sh` (which also passes the exact `--entry` for every function).

## Strict matches

| address | function | bytes | flags / notes |
|---|---:|---:|---|
| 0x401790 | IDMap::RemoveByKey | 87 | CS_Enter/CS_Leave around the scan |
| 0x47eed0 | Branch::SettleDueConstructionOrders | 84 | `deadline * 10` via lea/shl |
| 0x47fe10 | Game::ShowBuildingOverlay | 84 | single-case `switch (mode)` gives `dec/jne` |
| 0x486ec0 | Game::GetPreviousPlayerSlot | 84 | `if (index < -1)` reuses the `cmp esi,-1` flags |
| 0x495500 | Game_RebuildObjectTypeLists | 86 | `DAT_0057c6e0 + i` byte-offset globals |
| 0x4c2950 | MarketShareMenu_Init | 85 | `while` loop rotates to `jmp` + `jl`; `do` duplicates |
| 0x4d2ae0 | Game::CountFreeBuildingsByType | 85 | `<= 7`/`> 7` ordering |
| 0x4d3280 | Car::Destroy | 84 | vtable immediate 0x55c4f8, pad so records is at +8 |
| 0x4d4070 | Game::SetRecordOpenState | 86 | two `UI::SetChildState` calls tail-merged; CS from world |
| 0x4ddeb0 | Game::GetActiveCompanyOrdinal | 86 | ordinal spilled to the stack |
| 0x4e23b0 | Player::FindRecordByCityId | 84 | `IDMap::HasKey` returns bool |
| 0x4ed040 | Surface::AliasPixelPlanes | 84 | duplicated green-plane store kept |
| 0x4ed360 | UI::ClampScrollY | 84 | min/max expressions inline twice |
| 0x4fb600 | Stats_SumRecordCounts | 84 | `__stdcall` (ret 0xc) |
| 0x502120 | Game_GetPlayerSatisfactionBand | 85 | returns int (full-eax writes) |
| 0x502eb0 | Game::HasBuildingForPlayer | 86 | `<= 7` + world `GetCurrentPlayerCompanyName` |
| 0x507d30 | MapObject::StepToRandomCell | 85 | `RecomputePathStep(record)` lets the record be pre-pushed |
| 0x50a0b0 | Object::SetBuildingRecordForAllCompanies | 84 | 8-slot copy loop reloads the field |
| 0x513980 | Index::Map8To5 | 84 | two separate `if`s, not `else if` |
| 0x520bc0 | UI::HitTestChild | 85 | virtual slot 0x14 via 5 dummy virtuals |
| 0x532520 | UI_Group::ClearAll | 85 | array subobject at +0x148, count at +0x158 |
| 0x5472a0 | Sound::SetPosition | 84 | `(double)(unsigned)handle * float`, two vtable calls |
| 0x54db85 | File::WriteBytes | 86 | **`/O2 /TP /Oy- /Os`** (frame + `and [ebp-4],0`) |

## Unmatched

* `0x4897c0 City_GetListEndpoints` (86 bytes). Best genuine C++ attempt
  `nonmatching/0x4897c0.c`, 84/86 bytes, first diff at +0x1b:
  the compiler CSEs the two identical `record[(index*3+0x1e)*2]` loads, so
  the `if` emits `mov di,[eax+edx*4]; cmp di,-1` while the original compares
  the memory operand directly and reloads it for `*start`. Using
  `unsigned short`, a `p` pointer, a `char*` cast, or two textual index forms
  all keep the cached load.
* `0x5091c0 UI_SetListEntryHalfScale` (84 bytes). Best genuine C++ attempt
  `nonmatching/0x5091c0.c`, first diff at +0x23: the original evaluates the
  double expression, restores `esi`, and only then does `sub esp,8; fstp`;
  this build emits `sub esp,8` before the `fld` and pops `esi` after the
  call. `/Os` switches to `push ecx; push ecx` (2 bytes) instead of
  `sub esp,8`, so it cannot be used here.

First-diff JSON for both is next to the sources (`*.result.json`).

## Verification

```sh
sh reconstructed/match/batch11/part3/verify_strict.sh
# strict 23 / 23
```

## Tooling notes

- All symbols are auto-resolved; no explicit `--symbol` is used.
- 0x47fe10: a single-case `switch` (not `if (mode == 1)`) is what produces
  `dec eax; jne`.
- 0x486ec0: writing `if (index < -1)` makes VC6 reuse the `cmp esi,-1`
  flags; `if (index < 0)` adds a `test`.
- 0x507d30: the second argument of `Person_RecomputePathStep` is the map
  record; that shared push fixes the register allocation.
- 0x54db85: the surrounding 0x54dxxx/0x55xxxx CRT unit clearly used
  `/Os` with a frame pointer; `and dword [ebp-4],0` only appears with
  `/O2 /Oy- /Os`.
