# UI_LabelElement

- Vtable: `0x55c758`
- Constructor: `UI_TextLabel_Construct`
- Destructor: `UI_LabelElement_Delete`
- Base guess: `UI_Child`
- Slots: 7
- Naming notes: constructor symbol is UI_TextLabel_Construct (base/sibling name)

## Virtual methods

| # | Method |
|---:|---|
| 0 | `UI_LabelElement_Delete` |
| 1 | `UI_LabelElement_vfunc1` * |
| 2 | `UI_LabelElement_vfunc2` * |
| 3 | `UI_LabelElement_vfunc3` * |
| 4 | `UI_Child_ReturnTrue` * |
| 5 | `UI_Child_ForwardToVFunc4` * |
| 6 | `UI_Child_InvokeCallback` * |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x8` | 4 | 1 | UI_LabelElement_Destroy |
| `0x40` | 4 | 1 | UI_TextLabel_Construct |
| `0x54` | 4 | 1 | UI_TextLabel_Construct |
| `0x58` | 4 | 1 | UI_TextLabel_Construct |
| `0x5c` | 4 | 1 | UI_TextLabel_Construct |
| `0x60` | 4 | 1 | UI_TextLabel_Construct |
| `0x64` | 4 | 1 | UI_TextLabel_Construct |
| `0x68` | 4 | 1 | UI_TextLabel_Construct |
| `0x6c` | 4 | 2 | UI_LabelElement_Destroy, UI_TextLabel_Construct |
| `0x70` | 4 | 2 | UI_LabelElement_Destroy, UI_TextLabel_Construct |
| `0x74` | 4 | 1 | UI_TextLabel_Construct |
| `0x78` | 4 | 1 | UI_TextLabel_Construct |
| `0x7c` | 4 | 1 | UI_TextLabel_Construct |
| `0x80` | 4 | 1 | UI_TextLabel_Construct |
| `0x84` | 4 | 1 | UI_TextLabel_Construct |
| `0x88` | 4 | 1 | UI_TextLabel_Construct |
| `0x98` | 4 | 1 | UI_TextLabel_Construct |

## Vtable references

- `UI_LabelElement_Destroy`
- `UI_TextLabel_Construct`
