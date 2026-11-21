# batch04 part2 worklog

Batch 4 part 2 (`reconstructed/match/batch04/part2.json`, 25 functions).
Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (CL 12.00.8168 front end,
C2.DLL 12.00.8447), matcher `tools/match_decomp.py`, default `/O2`
(`/O2 /TP` for the C++ member functions).

**Result: 25 of 25 functions report `"strict_match": true`.** Run
`sh reconstructed/match/batch04/part2/verify_strict.sh` to re-check every
match; it passes each manifest length and the exact entry symbol and uses
`--strict --auto-symbols`. There are no failed candidates, so
`part2/nonmatching/` is empty.

## Matches

| address | name | form / flags |
|---|---|---|
| 0x49eca0 | Stats_SortActiveProductIndices | C, `CRT_QSort` with comparator 0x49ecc0, `/O2` |
| 0x49ed40 | Ranking_SortCompanyIndices | C, `CRT_QSort` with comparator 0x49ed60, `/O2` |
| 0x4c7090 | FreePlaySetup_SetDifficultyText | C++ member call, `/O2 /TP` |
| 0x4cda30 | NameMap_GetString | C++ member call to `IDMap::Lookup`, `/O2 /TP` |
| 0x4cda50 | NameMap_GetRecordString | C++ member call, `+0x40` on hit, `/O2 /TP` |
| 0x4d1d80 | MapObject_Delete | C++ destroying delete, `/O2 /TP` |
| 0x4d2e40 | IsSpecialIdRange | C, `__fastcall`, ids 0x84c..0x857, `/O2` |
| 0x4d2e60 | Object_IsIdIn840Range | C, `__fastcall`, ids 0x840..0x84b, `/O2` |
| 0x4d3240 | Car_Delete | C++ destroying delete, `/O2 /TP` |
| 0x4d3260 | Car_ConstructFromSave | C++ vtable store + `Car::LoadFromStream`, `/O2 /TP` |
| 0x4d3470 | Car_LoadSpriteRecord | C++ `MapSprite` base + `MapActor::ReadFromStream`, `/O2 /TP` |
| 0x4d36f0 | Character_StreamConstruct | C++ vtable store + `Character::Load`, `/O2 /TP` |
| 0x4d3fc0 | Rating_AdjustA | C, `__fastcall`, `(0x37 - hour) * 3`, `/O2` |
| 0x4d3fe0 | Rating_AdjustB | C, `__fastcall`, `(0x32 - hour) * 2`, `/O2` |
| 0x4d40d0 | Cost_ComputeQuantityPrice | C, signed `/10 * unit * 10` magic, `/O2` |
| 0x4d42f0 | State_GetFlags | C, `__fastcall`, byte return, `/O2` |
| 0x4d4310 | State_IsNegative | C, `__fastcall`, byte return, `/O2` |
| 0x4d47e0 | City_Delete | C++ destroying delete, `/O2 /TP` |
| 0x4da630 | Array_GetStride60 | C++ member, `index*0x60 + 0xdc8`, `/O2 /TP` |
| 0x4da690 | Array_FindIndexStride60 | C++ member, linear scan of four pointers, `/O2 /TP` |
| 0x4db010 | City_SetPlayerAdvertisingBudget | C++ member, stores + `UpdateSecurityPatrolFrames(0)`, `/O2 /TP` |
| 0x4dd8d0 | Company_Delete | C++ destroying delete, `/O2 /TP` |
| 0x4e3be0 | Player_ResetDebtHours | C, `__fastcall`, `double` compare, `/O2` |
| 0x4e4140 | Game_GetCityData | C, bounds-checked table at 0x57dfdc, `/O2` |
| 0x4e4370 | BuildingValue_StreamConstruct | C++ vtable store + `BuildingValue::Load`, `/O2 /TP` |

## Notes

* Every `ret N` callee is a real `__thiscall`; VC6 rejects `__thiscall` on free
  functions (C4234), so callers are written as C++ member functions and
  compiled with `/TP`. Member names were chosen so the mangled symbols demangle
  to the `full_game_symbols.json` names (`IDMap::Lookup` ->
  `IDMap_Lookup`, `Car::Destroy` -> `Car_Destroy`, `CRT_QSort`, ...), which is
  what `--auto-symbols` resolves.
* Global tables/vtables are spelled with `DAT_00xxxxxx` identifiers so
  `--auto-symbols` resolves them through the address-suffix rule:
  `DAT_0057cc40` (qsort array), `DAT_005840a8` (difficulty names),
  `DAT_00568310` (empty string), `DAT_0057dfdc` (city data),
  `DAT_0055c310` (`0.0` double), `DAT_0055c4f8`/`DAT_0055c4fc`/`DAT_0055c5a4`
  (class vtables). No explicit `--symbol` is needed for these.
* The only explicit symbols are the two qsort comparators,
  `_compare_0049ecc0=0x49ecc0` and `_compare_0049ed60=0x49ed60`: their names
  are plain function symbols, which the auto resolver does not look up.
* `0x4d42f0`/`0x4d4310` return `unsigned char`. The third check needs a local
  `flag = field <compare> 0; return flag;` so VC6 emits
  `test eax,eax; sete/setl al` without an extra `xor eax,eax`
  (`return field == 0` inserted one, adding three bytes).
* `0x4d3fc0`/`0x4d3fe0` need the positive `if (value >= 0) ...` layout for the
  final clamp; the negative form emits an inverted jump.
* `0x4da630` uses `if (index >= 0) return ...; return 0;` so the compare is
  `test eax,eax; jl zero` with the computed path inline.
* `0x4da690` is a `while (index < 4)` scan with `index++` before the pointer
  advance. VC6 removes the known-true first bound test and folds the bound
  check to the loop bottom, giving `inc eax; add ecx,0x60; cmp eax,4; jl`.
  A `for`/`do`-`while` with the bound in the update produced a rotated,
  32-byte loop instead.
* `0x4e3be0` compares against an external `double DAT_0055c310` (0.0) so the
  instruction stays `fcompl ds:0x55c310`; a literal `0.0` would relocate a
  local `.rdata` constant.
* `0x4d3470` models `Car : MapSprite` with a 4-byte `MapSprite` base (the
  original object has a dword at offset 0, actor at +4, record at +8). An
  empty base was collapsed by VC6, shifting the field loads to +0/+4.
