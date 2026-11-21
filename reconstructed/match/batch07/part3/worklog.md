# batch07 part3 worklog

Batch 7 part 3 (`reconstructed/match/batch07/part3.json`, 25 functions).
Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (CL 12.00.8168 front end,
C2.DLL 12.00.8447), matcher `tools/match_decomp.py`. Every candidate is
genuine C/C++ built with `/O2 /TP` (no inline assembly).

**Result: 25 of 25 functions report `"strict_match": true`.** Run
`sh reconstructed/match/batch07/part3/verify_strict.sh` to re-check every
match; it passes each manifest length, the exact entry symbol, and
`--strict --auto-symbols`. There are no failed final candidates, so
`part3/nonmatching/` is empty.

## Matches

| address | name | form |
|---|---|---|
| 0x4c70b0 | UI_SetMultipleLabels | `__cdecl` sentinel-pair loop, `UI::SetChildLabelText` call |
| 0x4ed440 | Map_SetScrollPosition | member, two clamp calls then `==0 && ==0` |
| 0x50be90 | Object_StartWorkOrderAndSetState | member, target load plus setter calls |
| 0x52ffa0 | Rect_ContainsPoint | member rectangle hit test |
| 0x531670 | UI_EnsureChildInitialized | member, `BinarySearch8_t::search` plus `Object_EnsureInit` |
| 0x547300 | Sound_SetParam | member, two vtable callback calls |
| 0x54b2e0 | IDMap_FindByField34 | member linear search over nested `IDMap` |
| 0x4018c0 | IDMap_Update | member, `< 100000` guard and index rewrite |
| 0x4808c0 | Game_SetMapRenderParams | member, four stores then dirty call |
| 0x489b20 | City_IndexOfListValue | member, lookup then `Game::FindGroupSlot` |
| 0x4d35a0 | Car_DriveToPoint | member, tile step plus `timeGetTime` walk step |
| 0x4f5730 | UI_AlignSpriteToObject | member, extent plus rect align calls |
| 0x4f78e0 | Game_MarkObjectsDirtyForState | `__stdcall`, state-6 array slot refresh |
| 0x508780 | Person_SetRandomResidentialTarget | `Object` member (person is `this`) |
| 0x50d710 | Object_BeginServiceDecision | member, state test plus two calls |
| 0x50e4e0 | Person_WatchTVProgram | member TV state transition |
| 0x50e850 | Object_SetFieldA4Locked | member, global critical section around store |
| 0x527810 | UI_FindStringRecord | member, `StringList::Find` plus `*0x48` record math |
| 0x534a80 | Record_GetTypeIndex48 | member, bounds plus type-byte lookup |
| 0x537350 | Window_Destroy | `__fastcall`, vtable reset and two frees |
| 0x53d650 | Surface_BlitRLEEnsureFormat | member, lazy-realize then RLE blit |
| 0x5499b0 | Sound_ProcessEventWithCooldown | member, cooldown gate |
| 0x47e6a0 | Branch_ApplyBuildingStyleVariant | member, `IsoMap::Load` tail-plus-stores |
| 0x4810a0 | Game_SetStageIfHigher | member, stage ladder |
| 0x492ae0 | TakeoverScreen_UpdateRatingBars | `__cdecl`, five-argument bar update |

## Notes

* All files build with `/O2 /TP`; member callees are declared as class methods
  so their mangled names demangle to the shipped names
  (`Map::ClampScrollY` -> `Map_ClampScrollY`, `Object::SetFieldA4Locked` ->
  `Object_SetFieldA4Locked`, and so on) and `--auto-symbols` resolves them.
* `0x531670` is the only one that needs an explicit symbol:
  `?search@BinarySearch8_t@@QAEHHH@Z=0x531330`. `BinarySearch8` is a
  `__thiscall` callee with no class-qualified name in the symbol map, so the
  batch01 `BinarySearch8_t::search` spelling is reused.
* `0x4ed440` needs the source order `int movedX = ...; int movedY = ...;` so
  VC6 tests `edi` first and folds the epilogue pops before the branch.
* `0x4810a0` only emits `cmp edx,eax; jle` for `if (stage > value)`; the
  swapped spelling `if (value < stage)` produced `cmp eax,edx; jge`.
* `0x52ffa0` needs `point->x >= right` (not `right <= point->x`) to keep the
  original `cmp eax,[ecx+0x10]; jge` operand order.
* `0x489b20` uses the `int result = -1; if (group) result = ...; return result`
  shape: it hoists `or esi,-1` before the call like the original, while the
  early-return spelling kept `or eax,-1` inline.
* `0x508780` is an `Object` member whose `this` is the person: the implicit
  `SetDestinationAndTarget(...)` call then places `mov ecx,esi` after the
  argument pushes, and `Map *city` keeps `mov ecx,eax` after the 0x18 push.
  The earlier `__fastcall` spelling emitted both `mov ecx,<reg>` too early.
* `0x547300`'s second argument slot is a real second `SetParam` argument
  (`[esp+8]`), not the buffer value; the buffer is only the first call's
  third argument.
* `0x534a80` needs the local `char type` to force the original
  `mov bl,[..]; test bl,bl` sequence and the `+0x80` table bias.
* `0x50e850` must reload `DAT_0057c670` for `CS_Leave`; caching the critical
  section in a local shortened the function.

## Reproduce

```sh
sh reconstructed/match/batch07/part3/verify_strict.sh
```
