# batch21 part2 worklog

Scope: 8 functions from `reconstructed/match/batch21/part2.json`.
Toolchain: `~/.local/share/pc2/vc6-sp3-toolchain/VC98` (MSVC 6.0 SP3,
C2.DLL 12.00.8447). `sh reconstructed/match/runtime01/verify_strict.sh`
reported 6/6 before this work. Every accepted function is genuine C++ and
passes `tools/match_decomp.py --strict --auto-symbols` with the manifest
length (156 bytes each) and the exact candidate entry symbol.

## Strict matches

| address | function | flags | entry | commit |
|---|---|---|---|---|
| 0x50f6b0 | `GamePlan_SaveRecord` | /O2 /TP | `?SaveRecord@GamePlan@@QAEXPAVOStream@@@Z` | |
| 0x50f750 | `GamePlan_LoadRecord` | /O2 /TP | `?LoadRecord@GamePlan@@QAEXPAVIStream@@@Z` | |
| 0x549e80 | `Sound_PlayBuildingSpecialSfx` | /O2 /TP | `?PlayBuildingSpecialSfx@Sound@@QAEXH@Z` | |
| 0x50b5e0 | `Person_AssignBranchStaffRole` | /O2 /TP | `?AssignBranchStaffRole@Person@@QAEXHHHD@Z` | |
| 0x523930 | `UI_AllocWindowSlot` | /O2 /TP | `?AllocWindowSlot@UI@@QAEHPAH@Z` | |

Notes:

* `0x50f6b0` / `0x50f750` are the same eleven-field serialization order
  (`+4,+8,+0x10,+0x14,+0x18,+0x1c,+0x20,+0x2c,+0xc,+0x24,+0x28`). Field
  declaration order in the class does not affect the emitted sequence; the
  call order does. The last write uses `add esi,0x28` because `this` is dead.
* `0x549e80`: the shipped switch jump table at `0x549f1c` matches a plain
  `switch` over cases 0..9; the city-name pointers are the existing packed
  strings at `0x576308`..`0x57632c` and the format string at `0x5762e0`.
  `Sound_PlayChannel` is called as a `Sound` member (thiscall), which is why
  `mov ecx,esi` precedes the call.
* `0x50b5e0`: the switch must be written with plain `break` in all three
  cases and the single `field10C = role` store *after* the switch. MSVC 6
  then duplicates the store and epilogue into cases 2 and 1, while case 0
  falls into the shared tail with `default`. Writing `field10C = role;
  return;` inside the cases folds the store to an immediate 1/2 and misses.
* `0x523930`: source must be a plain indexed `while (slot < count)` over
  `((int *)((char *)this + 0x14))[slot]`, not a hand-written `do/while`.
  MSVC strength-reduces the index to a pointer and emits the shipped
  check-value/increment/compare loop; the explicit `do/while` form is rotated
  and peeled. `count` is loaded once and `slot` stays in EDI.

## Non-matching evidence

| address | function | diff bytes | first diff | diagnosis |
|---|---|---:|---|---|
| 0x4af250 | `Glossary_IngredientList_Update` | 90 | offset 0x8: original `lea ebx,[eax+eax*2]` (row) / `lea eax,[eax+eax*2]`, candidate `lea ecx,[eax+eax*2]` / `lea edx,[eax+eax*2-0x42c]` | Size 156 and loop/branch skeleton match, but the allocator derives `row` from `3*entry - 0x42c + id` (spilling that base) instead of keeping a second induction variable in EBX as shipped. About 20 source shapes tried (`do/while`, `for`, reused entry, reordered increments, inverted branch, bool/int compare) either derive row from id or promote `id+0xb74` to the induction (`esi=0xfa0`). Saved under `nonmatching/0x4af250.c` with JSON. |
| 0x4be490 | `LeaseBuilding_UpdatePage` | 11 | offset 0x1e: original `mov ecx,ebx; lea eax,[esi+8]`, candidate `lea ecx,[esi+8]` then `mov ecx,ebx` after the pushes | Size and all other instructions/relocations match. The shipped code assigns ECX=ui before computing the text pointer, so the pointer lands in EAX; 15 source shapes (`UI*`/`UI&` parameter, local window pointer, reference, named text local, `player->name`, varargs, int* arithmetic, inline helper) all let MSVC choose ECX for the `lea` and delay the ECX=ui move. Saved under `nonmatching/0x4be490.c` with JSON. |
