# UI_Viewport

- Vtable: `0x55c73c`
- Constructor: `UI_ImageChild_Construct`
- Destructor: `UI_Viewport_Delete`
- Base guess: `UI_Child`
- Slots: 7
- Naming notes: constructor symbol is UI_ImageChild_Construct (base/sibling name)

## Virtual methods

| # | Method |
|---:|---|
| 0 | `UI_Viewport_Delete` |
| 1 | `UI_UpdateCustomControl` |
| 2 | `UI_Viewport_GetTypeId` * |
| 3 | `UI_Child_HandleControlCommand` |
| 4 | `UI_Viewport_vfunc4` * |
| 5 | `UI_Child_ForwardToVFunc4` * |
| 6 | `UI_Viewport_vfunc6` * |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x8` | 4 | 1 | UI_CustomControl_Destructor |
| `0x38` | 4 | 1 | UI_CustomControl_Destructor |
| `0x3c` | 4 | 1 | UI_CustomControl_Destructor |
| `0x40` | 4 | 1 | UI_ImageChild_Construct |
| `0x60` | 4 | 2 | UI_CustomControl_Destructor, UI_ImageChild_Construct |
| `0x64` | 4 | 1 | UI_CustomControl_Destructor |
| `0x68` | 4 | 2 | UI_CustomControl_Destructor, UI_ImageChild_Construct |
| `0x6c` | 4 | 1 | UI_CustomControl_Destructor |
| `0x7c` | 4 | 2 | UI_CustomControl_Destructor, UI_ImageChild_Construct |
| `0x80` | 4 | 2 | UI_CustomControl_Destructor, UI_ImageChild_Construct |
| `0x98` | 4 | 1 | UI_ImageChild_Construct |

## Vtable references

- `UI_CustomControl_Destructor`
- `UI_ImageChild_Construct`
