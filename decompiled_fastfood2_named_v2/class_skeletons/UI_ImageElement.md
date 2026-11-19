# UI_ImageElement

- Vtable: `0x55c704`
- Constructor: `UI_Image_Construct`
- Destructor: `UI_ImageElement_Delete`
- Base guess: `UI_Child`
- Slots: 7
- Naming notes: constructor symbol is UI_Image_Construct (base/sibling name)

## Virtual methods

| # | Method |
|---:|---|
| 0 | `UI_ImageElement_Delete` |
| 1 | `UI_ImageElement_vfunc1` * |
| 2 | `UI_ImageElement_vfunc2` * |
| 3 | `UI_ImageElement_vfunc3` * |
| 4 | `UI_ImageElement_vfunc4` * |
| 5 | `UI_Child_ForwardToVFunc4` * |
| 6 | `UI_Child_InvokeCallback` * |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x8` | 4 | 1 | UI_ImageElement_Destroy |
| `0x28` | 4 | 1 | UI_Image_Construct |
| `0x2c` | 4 | 1 | UI_Image_Construct |
| `0x30` | 4 | 1 | UI_Image_Construct |
| `0x34` | 4 | 1 | UI_Image_Construct |
| `0x40` | 4 | 1 | UI_Image_Construct |
| `0x164` | 4 | 1 | UI_Image_Construct |
| `0x168` | 4 | 1 | UI_Image_Construct |
| `0x16c` | 4 | 1 | UI_Image_Construct |
| `0x170` | 4 | 1 | UI_Image_Construct |

## Vtable references

- `UI_ImageElement_Destroy`
- `UI_Image_Construct`
