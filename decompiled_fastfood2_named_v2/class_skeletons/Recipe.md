# Recipe

- Vtable: `0x55c698`
- Constructor: `Recipe_Construct`
- Destructor: `Recipe_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

## Virtual methods

| # | Method |
|---:|---|
| 0 | `Recipe_Delete` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 0 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x44` | 4 | 4 | Recipe_Construct, Recipe_CreateGenerated, Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x5c` | 0 | 1 | Recipe_SaveToStream |
| `0x64` | 0 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x1bc` | 0 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x1d8` | 4 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x1dc` | 1 | 4 | Recipe_Construct, Recipe_CreateGenerated, Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x1dd` | 1 | 2 | Recipe_Construct, Recipe_CreateGenerated |
| `0x1e0` | 0 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x240` | 4 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x244` | 4 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x248` | 4 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x24c` | 4 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x250` | 4 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x254` | 4 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x258` | 4 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x264` | 0 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x284` | 0 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x2a4` | 0 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x2c4` | 0 | 2 | Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x304` | 4 | 4 | Recipe_Construct, Recipe_CreateGenerated, Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x308` | 4 | 4 | Recipe_Construct, Recipe_CreateGenerated, Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x30c` | 4 | 3 | Recipe_Construct, Recipe_LoadFromStream, Recipe_SaveToStream |
| `0x310` | 4 | 2 | Recipe_CreateGenerated, Recipe_StreamConstruct |
| `0x318` | 0 | 1 | Recipe_CreateGenerated |
| `0x31c` | 0 | 1 | Recipe_CreateGenerated |
| `0x320` | 0 | 1 | Recipe_CreateGenerated |
| `0x324` | 0 | 1 | Recipe_CreateGenerated |
| `0x328` | 0 | 1 | Recipe_CreateGenerated |
| `0x32c` | 0 | 1 | Recipe_CreateGenerated |

## Vtable references

- `Recipe_Construct`
- `Recipe_CreateGenerated`
- `Recipe_Destroy`
