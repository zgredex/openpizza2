# batch20 part2 worklog

Scope: 25 functions from `reconstructed/match/batch20/part2.json`.
Toolchain: `~/.local/share/pc2/vc6-sp3-toolchain/VC98` (MSVC 6.0 SP3,
C2.DLL 12.00.8447). Every accepted function is genuine C/C++ and passes
`tools/match_decomp.py --strict --auto-symbols` with the manifest length and
the exact candidate entry symbol. `sh reconstructed/match/runtime01/verify_strict.sh`
reported 6/6 before this work.

## Result: 1 / 25 strict matches

Reproduce with:

```sh
sh reconstructed/match/batch20/part2/verify_strict.sh
```

Matches (1):

| address | function | flags | entry |
| --- | --- | --- | --- |
| 0x48d110 | `Game_GetDataByIndex` | /O2 /TP | `_Game_GetDataByIndex@4` |

Notes:

* `0x48d110` is `__stdcall` (`mov eax,[esp+4]` / `ret 4`). All 31 returned
  globals resolve from `data_symbols.csv` names (`g_Text_0475_Kids` ...
  `g_Text_1311_Flyer_Boy`), and the default returns the address of
  `s__00568310`. The jump table has 35 entries with holes at 8, 9, 0x15 and
  0x19. Two details were essential: cases 0x0f and 0x21 must share one return
  block (`case 0xf: case 0x21:`), and that shared block must appear between the
  case 0x20 and case 0x22 blocks in source order, because MSVC emits the case
  bodies in source order while indexing the table by value.

## Non-matching evidence

Genuine C/C++ attempts are under `nonmatching/`, each with the matcher JSON
recorded beside the source. All use the manifest length, exact entry, and
`--strict --auto-symbols`.

| address | function | first diff (offset: original vs candidate) | differing bytes | diagnosis |
| --- | --- | --- | --- | --- |
| 0x47f670 | `Company::RemoveAttachedBuildingObjects` | 0x6a: 0x87 vs 0x15 | 34 | Loop, condition tests, callee order and lock handling match. The shipped code forms the map `this` as `mov ecx,[g_Game]; add ecx,0x3c` with the person key already in EAX, while every C form tried (`g_Game->persons`, cast expression, map local, named key) loads `g_Game` into EDX/EAX and uses `lea`. The owner compare is likewise EDX/EAX versus EAX/ECX. |
| 0x4da000 | `City::TrySendPoliceToDistrict` | 0x5: 0xee vs 0x8d | 233 | The entry-slot loops and stores match until variable coloring; an explicit `int j = 0`/`int zero = 0` pair changes which of EBX/EBP/ESI holds `this`, the shared zero and the lookup index. The shipped prologue reserves EBX for `this`, EBX/ECX/ESI for the three loop counters and keeps a shared zero in EBP. |
| 0x4d9ef0 | `City::SendPoliceToDistrict` | 0x5: 0xd9 vs 0x5c | 224 | Void sibling of 0x4da000 with the same entry-table loops (district slot type 0x1b). The early `int j = 0` live across the whole body makes this C2 coloring place `this` in EBP and the parameter in EBX; the shipped code uses EBX for `this` and a zero in EBP. |
| 0x52ee10 | `Dialog::InitBase` | 0x0: 0x53 vs 0x8b | 223 | The field list, offsets, order, `Renderer::CreateChild`, imported `SetRect` and the four 0xff000000 fills were recovered from disassembly, but MSVC hoists the parameter loads/stores to the top of the function and interleaves them differently from the shipped schedule (shipped stores param3 at +0x48 and param2 at +0x134 only after the first eight zero stores). |

## Not attempted

The remaining 20 records were not reached in this pass and have no candidate:

`0x4fdbe0`, `0x54a660`, `0x50d5e0`, `0x500470`, `0x506c00`, `0x521270`,
`0x526480`, `0x479ef0`, `0x4de360`, `0x499f30`, `0x5246e0`, `0x477e40`,
`0x47e750`, `0x5343d0`, `0x4fdcf0`, `0x49e160`, `0x49e830`,
`0x4aca80`, `0x53ec60`, `0x548570`, `0x4d9de0`.
