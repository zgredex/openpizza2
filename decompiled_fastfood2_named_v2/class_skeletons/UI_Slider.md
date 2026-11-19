# UI_Slider

- Vtable: `0x55c78c`
- Constructor: `UI_Bar_Construct`
- Destructor: `UI_Slider_Delete`
- Base guess: `UI_Child`
- Slots: 7
- Naming notes: constructor symbol is UI_Bar_Construct (base/sibling name)

## Virtual methods

| # | Method |
|---:|---|
| 0 | `UI_Slider_Delete` |
| 1 | `UI_Slider_vfunc1` * |
| 2 | `UI_BuildListItem` |
| 3 | `UI_Slider_vfunc3` * |
| 4 | `UI_Slider_vfunc4` * |
| 5 | `UI_Slider_ReturnTrue` * |
| 6 | `UI_Child_InvokeCallback` * |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x8` | 4 | 1 | UI_Slider_Destroy |
| `0x28` | 4 | 1 | UI_Bar_Construct |
| `0x2c` | 4 | 1 | UI_Bar_Construct |
| `0x30` | 4 | 1 | UI_Bar_Construct |
| `0x34` | 4 | 1 | UI_Bar_Construct |
| `0x40` | 4 | 1 | UI_Bar_Construct |
| `0x54` | 4 | 1 | UI_Bar_Construct |
| `0x58` | 4 | 1 | UI_Bar_Construct |
| `0x5c` | 4 | 1 | UI_Bar_Construct |
| `0x60` | 4 | 1 | UI_Bar_Construct |
| `0x64` | 4 | 1 | UI_Bar_Construct |
| `0x68` | 4 | 1 | UI_Bar_Construct |
| `0x84` | 4 | 1 | UI_Bar_Construct |
| `0x88` | 4 | 1 | UI_Bar_Construct |
| `0x94` | 4 | 1 | UI_Bar_Construct |
| `0x98` | 4 | 1 | UI_Bar_Construct |
| `0x9c` | 4 | 1 | UI_Bar_Construct |
| `0xa0` | 4 | 1 | UI_Bar_Construct |
| `0xa4` | 4 | 1 | UI_Bar_Construct |
| `0xa8` | 4 | 1 | UI_Bar_Construct |
| `0xac` | 4 | 1 | UI_Bar_Construct |
| `0xb4` | 4 | 1 | UI_Bar_Construct |
| `0xb8` | 4 | 1 | UI_Bar_Construct |
| `0xbc` | 4 | 2 | UI_Bar_Construct, UI_Slider_Destroy |
| `0xc0` | 4 | 1 | UI_Bar_Construct |
| `0xc4` | 4 | 1 | UI_Bar_Construct |
| `0xc8` | 4 | 1 | UI_Bar_Construct |
| `0xcc` | 4 | 1 | UI_Bar_Construct |
| `0xd0` | 4 | 1 | UI_Bar_Construct |
| `0xd4` | 4 | 1 | UI_Bar_Construct |
| `0xd8` | 4 | 1 | UI_Bar_Construct |
| `0xdc` | 4 | 1 | UI_Bar_Construct |
| `0x1ec` | 0 | 1 | UI_Bar_Construct |
| `0x230` | 0 | 1 | UI_Bar_Construct |
| `0x274` | 0 | 1 | UI_Bar_Construct |
| `0x344` | 4 | 2 | UI_Bar_Construct, UI_Slider_Destroy |
| `0x388` | 4 | 1 | UI_Bar_Construct |
| `0x4f0` | 4 | 1 | UI_Bar_Construct |
| `0x4f4` | 4 | 1 | UI_Bar_Construct |

## Vtable references

- `UI_Bar_Construct`
- `UI_Slider_Destroy`
