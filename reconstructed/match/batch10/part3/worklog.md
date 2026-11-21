# batch10 part3 worklog

25 manifest records reconstructed as genuine C/C++ for MSVC 6.0 SP3
(`/tmp/opencode/vc6-sp3-toolchain/VC98`). Every accepted file compiles with
`/O2 /TP` and reports `"strict_match": true` from
`tools/match_decomp.py` with the manifest length, the exact entry symbol and
`--strict --auto-symbols`.

## Result

```text
strict matches: 22 / 25
```

Matched: 0x4eac30, 0x4ead00, 0x4ead90, 0x4ed930, 0x4f4ed0, 0x4f6b80,
0x4f6e20, 0x4fba90, 0x4fd0a0, 0x502360, 0x5078d0, 0x509170, 0x50b680,
0x50bbf0, 0x50e890, 0x50f7f0, 0x514450, 0x5144a0, 0x522e80, 0x526870,
0x527250, 0x528040.

| address | length | entry symbol | notes |
| --- | ---: | --- | --- |
| 0x4eac30 | 70 | `?GetNestedArrayEntry@Game@@QAEHHH@Z` | explicit `IDMap::Lookup`, `Game::GetRecordChild14` |
| 0x4ead00 | 70 | `?TickWorldObjects@Game@@QAEXXZ` | auto symbols |
| 0x4ead90 | 69 | `?Get2DTableValue@Map@@QAEHHHH@Z` | switch on table index |
| 0x4ed930 | 69 | `?SetHoverTile@Map@@QAEXPAUHoverSource@@@Z` | repeated `hover` member loads are required |
| 0x4f4ed0 | 72 | `?ResetLinkVisitedFlags@Object@@QAEXXZ` | explicit `GetRecord28`, `CountValid8` |
| 0x4f6b80 | 69 | `?TickGoalDeadline@Mission@@QAEXH@Z` | load/add/store for the counter |
| 0x4f6e20 | 69 | `?CompanySlots_Save@AI@@QAEXPAUOStream@@@Z` | explicit `OStream::Write` |
| 0x4fba90 | 70 | `_Map_GridToScreenOffset@20` | `__stdcall` five-argument function |
| 0x4fd0a0 | 77 | `?EnsureRequiredBranch@Company@@QAEXHPAXH@Z` | explicit `FindCheapestShop`, `BuildHeadquarters`; local reload of the branch field |
| 0x502360 | 71 | `?Stats_GetLevelFromTenCounters@@YAHXZ` | ten byte counters |
| 0x5078d0 | 74 | `?PathToTileAndStep@Person@@QAEHHH@Z` | `__imp__timeGetTime@0=0x55c294` |
| 0x509170 | 76 | `?Record_DoublePositionValue@@YIXH@Z` | explicit `UIList::SetEntryPosition`; one call after an if/else value select |
| 0x50b680 | 77 | `?SendToBranchWithCarryMode@Person@@QAEXHH@Z` | state 0x22/0x15 select |
| 0x50bbf0 | 72 | `?ClearAssignedRecord@Object@@QAEHPAURecordMap@@@Z` | auto symbols |
| 0x50e890 | 74 | `?SetState@Object@@QAEXH@Z` | `CS_Enter`/`CS_Leave` as `__fastcall` |
| 0x50f7f0 | 69 | `?GetPercentModifier@Company@@QAEHH@Z` | divisor variable makes VC6 emit `idiv` instead of a magic multiply |
| 0x514450 | 77 | `?SetSupplierBuilding@Storage@@QAEXH@Z` | commands -99868 and -99929 |
| 0x5144a0 | 75 | `?Stats_GetAverageRecordValue@@YIHH@Z` | do/while inside `if (count > 0)` |
| 0x522e80 | 77 | `?Construct@Array@@QAEPAU1@H@Z` | literal vtable address 0x55c774; auto `operator_new` |
| 0x526870 | 73 | `?UI_MessageBoxf@@YAHPAXPADZZ` | 512-byte buffer, `&format + 1` varargs |
| 0x527250 | 76 | `?ImageCache_Clear@@YIXH@Z` | auto symbols |
| 0x528040 | 76 | `?FindWindowByID@UI@@QAEHHPAH@Z` | indexed slot expression avoids the extra loop guard |

## Notes

- The SP3 C front end rejects `__thiscall` in C (`error C4234`), so all
  `ecx`-passed records are written as C++ member functions and compiled with
  `/TP`. Zero-stack-argument thiscall callees are written as
  `extern "C" __fastcall` free functions, which produces identical code and
  auto-resolves from the shipped plain-name table.
- Member callees whose decorated name includes a different class prefix than
  the shipped plain-name map (`IDMap::Lookup`, `Game::GetRecordChild14`,
  `Object::GetRecord28`, `Object::CountValid8`, `OStream::Write`,
  `UIList::SetEntryPosition`, `Company::FindCheapestShop`,
  `Company::BuildHeadquarters`) need explicit `--symbol` maps; the verify
  script carries them.
- `__imp__timeGetTime@0` is an IAT symbol and is also mapped explicitly.
- `__fltused` is undefined in 0x509170 but is not referenced by a `.text`
  relocation, so strict relocation checks still pass without a map.

## Non-matching (kept under `nonmatching/`)

- `0x4ede90 UI_DrawObjectSprite`: candidate length is 70, but the first byte
  differs (original `0x56 push esi`, candidate `0x8b mov eax,...`) and 52
  bytes differ overall. The original loads the sprite parameter directly into
  `edi` after pushing `esi`/`edi`; the compiler from every reconstructed
  source shape loads it through `eax` first, which shifts the argument
  register allocation. No `__asm` was used.
- `0x4f7a00 Game_FillNearbyTypeCompanyMatrix`: candidate length is 71 and
  only 7 bytes differ. First difference is offset 33 (`0x21`): original
  `0x50 push eax` after `push 0`, candidate `0x83 add ecx,4`. VC6 schedules
  `add ecx,4` before `push eax` in the reconstructed lookup call, and uses
  `esi` instead of `ecx` for the `param_1 + 0x16f0` temporary. The function is
  `__stdcall` (original `ret 8`).
- `0x50fe70 Game_GetPlayerWeightedStat`: candidate length is 70 and 29 bytes
  differ. First difference is offset 28 (`0x1c`): original `0x8b` (two
  independent pointer increments `add edx,4` / `add eax,4`), candidate `0x2b
  sub edx,eax` because VC6 merges the two induction pointers into a
  base-plus-index form. The 0x56-iteration loop and x87 expression otherwise
  have the same shape.

## Verify

```sh
bash reconstructed/match/batch10/part3/verify_strict.sh
```

The script checks the 22 accepted files with their manifest lengths, entry
symbols, explicit symbol maps and `/O2 /TP`, then prints the three known
non-matching records.
