# UI_ButtonElement

- Vtable: `0x55c7e8`
- Constructor: `UI_TextPanel_Construct`
- Destructor: `UI_ButtonElement_Delete`
- Base guess: `UI_Child`
- Slots: 7
- Naming notes: constructor symbol is UI_TextPanel_Construct (base/sibling name)

## Virtual methods

| # | Method |
|---:|---|
| 0 | `UI_ButtonElement_Delete` |
| 1 | `UI_ButtonElement_vfunc1` * |
| 2 | `UI_ButtonElement_vfunc2` * |
| 3 | `UI_ButtonElement_vfunc3` * |
| 4 | `UI_Child_ReturnTrue` * |
| 5 | `UI_Child_ForwardToVFunc4` * |
| 6 | `UI_Child_InvokeCallback` * |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x8` | 4 | 1 | UI_ButtonElement_Destroy |
| `0x28` | 2 | 1 | UI_TextPanel_Construct |
| `0x2c` | 2 | 1 | UI_TextPanel_Construct |
| `0x30` | 2 | 1 | UI_TextPanel_Construct |
| `0x34` | 2 | 1 | UI_TextPanel_Construct |
| `0x40` | 4 | 1 | UI_TextPanel_Construct |
| `0x54` | 4 | 2 | UI_ButtonElement_Destroy, UI_TextPanel_Construct |
| `0x58` | 4 | 2 | UI_ButtonElement_Destroy, UI_TextPanel_Construct |
| `0x9c` | 0 | 1 | UI_TextPanel_Construct |
| `0x38c` | 4 | 1 | UI_TextPanel_Construct |
| `0x390` | 4 | 1 | UI_TextPanel_Construct |
| `0x394` | 4 | 1 | UI_TextPanel_Construct |
| `0x398` | 4 | 1 | UI_TextPanel_Construct |
| `0x39c` | 0 | 1 | UI_TextPanel_Construct |
| `0x3a0` | 4 | 1 | UI_TextPanel_Construct |
| `0x3a4` | 4 | 1 | UI_TextPanel_Construct |
| `0x3a8` | 4 | 1 | UI_TextPanel_Construct |
| `0x3ac` | 4 | 1 | UI_TextPanel_Construct |
| `0x3b0` | 4 | 1 | UI_TextPanel_Construct |
| `0x3b2` | 2 | 1 | UI_TextPanel_Construct |
| `0x3b4` | 4 | 1 | UI_TextPanel_Construct |
| `0x3b8` | 4 | 1 | UI_TextPanel_Construct |
| `0x3bc` | 4 | 1 | UI_TextPanel_Construct |
| `0x3c0` | 4 | 1 | UI_TextPanel_Construct |
| `0x3c4` | 4 | 1 | UI_TextPanel_Construct |

## Vtable references

- `UI_ButtonElement_Destroy`
- `UI_TextPanel_Construct`
