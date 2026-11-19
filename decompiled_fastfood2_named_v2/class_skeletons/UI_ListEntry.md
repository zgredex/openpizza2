# UI_ListEntry

- Vtable: `0x55c2f8`
- Constructor: `UI_ListEntry_ConstructWithValue`
- Destructor: `UI_ListEntry_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

## Virtual methods

| # | Method |
|---:|---|
| 0 | `UI_ListEntry_Delete` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x44` | 4 | 3 | UI_ListEntry_Construct, UI_ListEntry_ConstructWithValue, UI_ListEntry_Destroy |
| `0x48` | 4 | 3 | UI_ListEntry_Construct, UI_ListEntry_ConstructWithValue, UI_ListEntry_Destroy |
| `0x4c` | 4 | 2 | UI_ListEntry_Construct, UI_ListEntry_ConstructWithValue |
| `0x54` | 4 | 2 | UI_ListEntry_Construct, UI_ListEntry_ConstructWithValue |

## Vtable references

- `UI_ListEntry_Construct`
- `UI_ListEntry_ConstructWithValue`
- `UI_ListEntry_Destroy`
