# List

- Vtable: `0x55c2ec`
- Constructor: `List_Construct`
- Destructor: `List_Node_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: slot0 symbol List_Node_Delete is a legacy name; List_Construct initializes this container vtable

## Virtual methods

| # | Method |
|---:|---|
| 0 | `List_Node_Delete` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 3 | List_Construct, List_Node_Destroy, List_Node_Reset |
| `0x8` | 4 | 3 | List_Construct, List_Node_Destroy, List_Node_Reset |
| `0xc` | 4 | 2 | List_Construct, List_Node_Reset |
| `0x10` | 4 | 2 | List_Construct, List_Node_Reset |
| `0x14` | 4 | 2 | List_Construct, List_Node_Reset |
| `0x18` | 4 | 2 | List_Construct, List_Node_Reset |

## Vtable references

- `List_Construct`
- `List_Node_Destroy`
