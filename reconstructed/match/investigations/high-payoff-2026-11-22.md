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

The pinned VC6 SP3 recheck verifies all eight functions: 805 code bytes were
published as a byte-identical scratch PE. The cached repeat hit all eight COFF
objects.

The two UI factories needed independent placement for their 21-byte `.text$x`
and 40-byte `.xdata$x` sections. The shipped SEH handler addresses are strictly
monotonic with function address: 223 functions with the `6a ff 68` prologue
have 223 unique handlers and no inversion. That gives a link-order anchor
without using either factory's own handler relocation:

```text
0x52fc00 rank 159 -> handler 0x55ab2b -> funclet base 0x55ab20; $L298 = base + 0xb
0x531c60 rank 164 -> handler 0x55ac0b -> funclet base 0x55ac00; $L277 = base + 0xb
```

`locate_linked_section` then verifies the funclet bytes, the
`___CxxFrameHandler`/`??3` targets, and the `.xdata$x` back-pointer pair.
The per-recipe anchors are recorded in `high-payoff-recipes.json`.

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
