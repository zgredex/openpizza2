# UI_TextElement

- Vtable: `0x55c7cc`
- Constructor: `UI_Text_Construct`
- Destructor: `UI_TextElement_Delete`
- Base guess: `UI_Child`
- Slots: 7
- Naming notes: constructor symbol is UI_Text_Construct (base/sibling name)

## Virtual methods

| # | Method |
|---:|---|
| 0 | `UI_TextElement_Delete` |
| 1 | `UI_TextElement_vfunc1` * |
| 2 | `UI_TextElement_vfunc2` * |
| 3 | `UI_TextElement_vfunc3` * |
| 4 | `UI_Child_ReturnTrue` * |
| 5 | `UI_Child_ForwardToVFunc4` * |
| 6 | `UI_Child_InvokeCallback` * |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x8` | 4 | 1 | UI_TextElement_Destroy |
| `0x14` | 4 | 1 | UI_Text_Construct |
| `0x40` | 4 | 1 | UI_Text_Construct |
| `0x54` | 4 | 2 | UI_TextElement_Destroy, UI_Text_Construct |
| `0x58` | 4 | 1 | UI_Text_Construct |
| `0x60` | 4 | 1 | UI_Text_Construct |
| `0x64` | 2 | 1 | UI_Text_Construct |
| `0x66` | 2 | 1 | UI_Text_Construct |
| `0x6c` | 4 | 1 | UI_Text_Construct |
| `0x70` | 4 | 1 | UI_Text_Construct |
| `0x74` | 4 | 2 | UI_TextElement_Destroy, UI_Text_Construct |
| `0x78` | 4 | 1 | UI_Text_Construct |
| `0x88` | 4 | 2 | UI_TextElement_Destroy, UI_Text_Construct |

## Vtable references

- `UI_TextElement_Destroy`
- `UI_Text_Construct`
