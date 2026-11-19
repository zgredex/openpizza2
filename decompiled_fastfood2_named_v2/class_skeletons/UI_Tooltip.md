# UI_Tooltip

- Vtable: `0x55c804`
- Constructor: `Tooltip_Construct`
- Destructor: `UI_Tooltip_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: constructor symbol is Tooltip_Construct (base/sibling name)

## Virtual methods

| # | Method |
|---:|---|
| 0 | `UI_Tooltip_Delete` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 1 | Tooltip_Construct |
| `0x8` | 4 | 1 | Tooltip_Construct |
| `0xc` | 4 | 1 | Tooltip_Construct |
| `0x10` | 4 | 1 | Tooltip_Construct |
| `0x14` | 4 | 1 | Tooltip_Construct |
| `0x18` | 4 | 2 | Tooltip_Construct, UI_Tooltip_Destroy |
| `0x1c` | 4 | 2 | Tooltip_Construct, UI_Tooltip_Destroy |
| `0x20` | 4 | 1 | Tooltip_Construct |
| `0x24` | 4 | 1 | Tooltip_Construct |
| `0x28` | 4 | 1 | Tooltip_Construct |
| `0x2c` | 4 | 1 | Tooltip_Construct |
| `0x30` | 4 | 2 | Tooltip_Construct, UI_Tooltip_Destroy |
| `0x38` | 4 | 2 | Tooltip_Construct, UI_Tooltip_Destroy |
| `0x3c` | 4 | 1 | Tooltip_Construct |

## Vtable references

- `Tooltip_Construct`
- `UI_Tooltip_Destroy`
