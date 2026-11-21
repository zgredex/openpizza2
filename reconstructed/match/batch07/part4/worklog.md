# batch07 part4 worklog

Batch 7 part 4 (`reconstructed/match/batch07/part4.json`, 25 functions).
Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (CL 12.00.8168 front end,
C2.DLL 12.00.8447), matcher `tools/match_decomp.py`. Candidates are genuine
C/C++ built with `/O2 /TP` (no inline assembly).

**Result: 24 of 25 functions report `"strict_match": true`.** Run
`sh reconstructed/match/batch07/part4/verify_strict.sh` to re-check them; it
passes each manifest length, the exact entry symbol, and
`--strict --auto-symbols`. One candidate stays under `part4/nonmatching/`.

## Matches

| address | name | form / flags |
|---|---|---|
| 0x498740 | City_RebuildBuildingRatingIndex | index fill plus `CRT_QSort` |
| 0x49c170 | Ranking_SortRecordIndices | index fill plus `CRT_QSort` |
| 0x49c240 | Stats_SortCompanyIndexArray | index fill plus `CRT_QSort` |
| 0x4c1ef0 | PlayerRecordPanel_SortIndices | index fill plus `CRT_QSort` |
| 0x4c1f30 | City_RebuildProductSortIndex | index fill plus `CRT_QSort` |
| 0x4dd0f0 | Economy_ApplyTablePercent | member, signed `/100` magic multiply |
| 0x4e2280 | Game_GetPlayerFieldC20 | `__fastcall`, player slot lookup |
| 0x4f0cc0 | Array_GetRecord28 | member, 0x28-stride record selection |
| 0x4f3b30 | Object_GetRect100 | member, four output stores |
| 0x4f5db0 | Object_ClearState | `__stdcall`, state record reset |
| 0x50f630 | GamePlan_Construct | constructor, vtable plus defaults |
| 0x5312f0 | Array_GetPair8 | member, bounds plus pair return |
| 0x532b60 | Sound_StopBuffer | member, virtual buffer release |
| 0x5335b0 | Record_SetDoubles48B | member, two double stores |
| 0x534990 | Record_SetIndex48 | member, id/limit guards plus short store |
| 0x535650 | Font_GetCharWidth | member, width table lookup |
| 0x541250 | List_FreeAll | member, node free loop |
| 0x4032a0 | RegistryKey_WriteValue | member, `RegSetValueExA` wrapper |
| 0x47fed0 | Game_CountFreeResidentialBuildings | `__fastcall`, `/O2 /G6 /TP` |
| 0x4aaac0 | Calendar_IsSelectedDate | `__cdecl`, date match |
| 0x4e5d60 | ConstructionOrder_Construct | constructor with two arguments |
| 0x503280 | BuildingProject_ResetState | member, 12 stores plus `List_Node::Reset` |
| 0x50fba0 | GamePlan_ComputeEffectValue | member, `__ftol` scale conversion |
| 0x5277d0 | UI_DecrementRowCounter | member, record counter decrement |

## Nonmatching

* `0x505eb0 Object_PlaceSpriteAtCenter` (`nonmatching/0x505eb0.c`). The
  candidate reproduces the sprite guard, the `x-0xa0`/`y-0xd0` arithmetic,
  the argument pushes, and the `Record_SetDoubles48` call, but it cannot
  reproduce the dead `cmp eax,1` at `0x505ec2`. The original loads `param_1`
  into `eax`, compares it with 1, then overwrites `eax` and never tests the
  flags again (`add` instructions immediately clobber them). The neighbouring
  `0x505e60 UI_SetChildTracking` has the same dead compare and its Ghidra body
  also ignores `param_1`. First diff: offset 1, original `0x91`
  (`mov edx,[ecx+0xc8]`) vs candidate `0x81` (`mov eax,[ecx+0xc8]`), 31
  differing bytes; the candidate is 48 bytes against the manifest's 52.
  Empty `if (mode == 1)`, empty switch cases, identical if/else arms,
  identical ternary arms, and empty inline validators all drop the compare in
  this compiler; no genuine C++ construct tried left a bare dead
  `cmp reg,1`.

## Notes

* The five qsort wrappers use `extern int *DAT_0057xxxx` (the shipped globals
  are pointer variables) and `DAT_<address>` comparator names, so the
  `--auto-symbols` `DAT_<hex>` fallback resolves both the array and the
  comparator pointer.
* `0x47fed0` needs `/O2 /G6`: with the default `/Gx` scheduling VC6 emits
  `mov ecx,esi; mov edi,eax; push 0x1b`, while the original (and `/G6`) uses
  `push 0x1b; mov ecx,esi; mov edi,eax`. Everything else in the function is
  plain `/O2`. It is a `__fastcall` free function taking the object pointer,
  not a member.
* `0x4f5db0` must reload `holder->state` for every byte store; caching the
  state pointer in a local shortened the function.
* `0x534990`'s `Record48` must be padded to exactly 0x48 bytes, otherwise
  VC6 emits the 0x34-stride `lea` chain instead of `*9` then `*8`.
* `0x535650` returns `int` (the original zero-extends the byte through
  `edx`), not `unsigned char`.
* `0x532b60` models the buffer as a class with a virtual `Release(int)` so the
  call is `mov eax,[ecx]; push 1; call [eax]`.
* `0x50fba0` needs `if (average >= 0x28) return ...; return 0x28 - average;`
  to place the low branch after the `__ftol` path.
* `0x4032a0` calls the import through
  `extern int (__stdcall *DAT_0055c00c)(...)` and returns
  `RegSetValueExA(...) == 0`, which VC6 renders as `neg/sbb/inc`.

## Reproduce

```sh
sh reconstructed/match/batch07/part4/verify_strict.sh
```
