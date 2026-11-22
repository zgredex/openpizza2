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

## Byte recheck

The pinned VC6 SP3 recheck verified six functions totaling 481 bytes and
linked them into a byte-identical scratch PE. The cached repeat hit all eight
COFF objects. The two UI factories at `0x52fc00` and `0x531c60` still need
independent placements for their 21-byte `.text$x` and 40-byte `.xdata$x`
sections. Their main bodies match.

```sh
scratch=$(mktemp -d)
python3 tools/verify_replay_batch.py \
  --recipes reconstructed/match/investigations/high-payoff-recipes.json \
  --cache "$scratch/cache" --out "$scratch/cold.json" --jobs 4
python3 tools/verify_replay_batch.py \
  --recipes reconstructed/match/investigations/high-payoff-recipes.json \
  --cache "$scratch/cache" --out "$scratch/warm.json" --cache-only \
  --linked-out "$scratch/fastfood2.exe"
```
