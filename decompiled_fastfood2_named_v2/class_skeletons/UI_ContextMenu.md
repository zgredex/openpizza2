# UI_ContextMenu

- Vtable: `0x55c788`
- Constructor: `ContextMenu_Construct`
- Destructor: `UI_ContextMenu_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: constructor symbol is ContextMenu_Construct (base/sibling name)

## Virtual methods

| # | Method |
|---:|---|
| 0 | `UI_ContextMenu_Delete` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 0 | 1 | ContextMenu_Construct |
| `0x28` | 4 | 1 | ContextMenu_Construct |
| `0x2c` | 4 | 1 | ContextMenu_Construct |
| `0x38` | 4 | 1 | ContextMenu_Construct |
| `0x3c` | 4 | 1 | ContextMenu_Construct |
| `0x44` | 4 | 1 | ContextMenu_Construct |
| `0x48` | 4 | 1 | ContextMenu_Construct |
| `0x50` | 4 | 2 | ContextMenu_Construct, UI_ContextMenu_Destroy |
| `0x54` | 4 | 2 | ContextMenu_Construct, UI_ContextMenu_Destroy |
| `0x5c` | 4 | 1 | ContextMenu_Construct |
| `0x60` | 4 | 1 | ContextMenu_Construct |
| `0x64` | 4 | 1 | ContextMenu_Construct |
| `0x68` | 4 | 2 | ContextMenu_Construct, UI_ContextMenu_Destroy |

## Vtable references

- `ContextMenu_Construct`
- `UI_ContextMenu_Destroy`
