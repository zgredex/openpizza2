# UI_Child

- Vtable: `0x55c720`
- Constructor: `UI_Child_Construct`
- Destructor: `UI_Child_Delete`
- Base guess: ``
- Slots: 7
- Naming notes: -

## Virtual methods

| # | Method |
|---:|---|
| 0 | `UI_Child_Delete` |
| 1 | `_purecall` * |
| 2 | `_purecall` * |
| 3 | `_purecall` * |
| 4 | `UI_Child_ReturnTrue` * |
| 5 | `UI_Child_ForwardToVFunc4` * |
| 6 | `UI_Child_InvokeCallback` * |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 1 | UI_Child_Construct |
| `0x8` | 4 | 1 | UI_Child_Construct |
| `0xc` | 4 | 2 | UI_Child_Construct, UI_Child_Destroy |
| `0x10` | 4 | 2 | UI_Child_Construct, UI_Child_Destroy |
| `0x14` | 4 | 1 | UI_Child_Construct |
| `0x18` | 4 | 1 | UI_Child_Construct |
| `0x1c` | 4 | 1 | UI_Child_Construct |
| `0x20` | 4 | 1 | UI_Child_Construct |
| `0x24` | 4 | 1 | UI_Child_Construct |
| `0x28` | 4 | 1 | UI_Child_Construct |
| `0x2c` | 4 | 1 | UI_Child_Construct |
| `0x30` | 4 | 1 | UI_Child_Construct |
| `0x34` | 4 | 1 | UI_Child_Construct |
| `0x38` | 4 | 1 | UI_Child_Construct |
| `0x3c` | 4 | 1 | UI_Child_Construct |
| `0x44` | 4 | 1 | UI_Child_Construct |
| `0x48` | 4 | 1 | UI_Child_Construct |
| `0x4c` | 4 | 1 | UI_Child_Construct |
| `0x50` | 4 | 1 | UI_Child_Construct |

## Vtable references

- `UI_Child_Construct`
- `UI_Child_Destroy`
