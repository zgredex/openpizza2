# High-payoff batch 2026-11-22

Selected from the post-pilot queue: eight body-only functions in four shared
fact groups.

| function | needed facts |
|---|---|
| `0x513bf0` `Branch::ComputeRecipePrice` | `BranchValue::GetBuildingValue`, `BranchValue::GetFloat44` |
| `0x513c40` `Branch::GetRecipePriceParts` | same two |
| `0x498ef0` `RecipeMenu_ShowRecipeFileChooser` | `UIHelper::ShowConfirmationDialog`, `UIHelper::ShowScrollingListDialog` |
| `0x49c4d0` `RecipeMenu_ShowMenuFileChooser` | same two |
| `0x52fc00` `UI_Manager::CreateSlider` | `UI_Manager::EnsureObjectArray`, `UI_Bar::UI_Bar` |
| `0x531c60` `UI_Manager::CreateBitmapGadget` | `UI_Manager::EnsureObjectArray`, `UI_ImageChild::UI_ImageChild` |
| `0x531570` `Array::GetRectByKey` | `ArrayHelper::BinarySearch8` (already registered) |
| `0x531620` `Array::ToggleObjectActive` | `ObjectHelper::EnsureInit`, `ObjectHelper::ClearPendingCommand` |

Nine aliases were added to `symbol_registry.json` with three independent
evidence points each:

- the shipped name at the target address in `full_game_symbols.json`,
- the target body and ABI in `game/fastfood2.exe` (`ECX` receiver, `ret N`,
  or `flds [ecx+0x44]; ret`),
- the original call site in the committed candidate source.

The original call displacements also point at the same addresses:

```text
0x513bf0 -> 0x47fd90, 0x510570
0x513c40 -> 0x47fd90, 0x510570
0x498ef0 -> 0x482b70, 0x483210
0x49c4d0 -> 0x483210, 0x482b70
0x52fc00 -> 0x54e221, 0x528930, 0x530f80
0x531c60 -> 0x54e221, 0x521000, 0x530f80
0x531570 -> 0x531330
0x531620 -> 0x531330, 0x520cd0, 0x520cf0
```

## Pending byte recheck

The pinned VC6 SP3 tree formerly at
`/tmp/opencode/vc6-sp3-toolchain/VC98` was cleared by the environment reset,
so the strict matcher cannot compile the candidates. Restore it (or set
`PC2_VC6`) and run:

```sh
python3 tools/verify_linked_image.py --audit /tmp/pc2-tracked-audit-final --assess \
  --only-address 0x513bf0 --only-address 0x513c40 \
  --only-address 0x498ef0 --only-address 0x49c4d0 \
  --only-address 0x52fc00 --only-address 0x531c60 \
  --only-address 0x531570 --only-address 0x531620 \
  --cache /tmp/pc2-coff-cache --manifest /tmp/pc2-high-payoff-after.json
```

Then feed the assessment back into `tools/propose_symbol_mappings.py` with the
tracked audit. The expected direct wins are the eight functions above; any
remaining blocker will be the next audit entry for this batch.
