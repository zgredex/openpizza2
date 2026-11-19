# Array

- Vtable: `0x55c774`
- Constructor: `Array_Construct`
- Destructor: `Array_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

## Virtual methods

| # | Method |
|---:|---|
| 0 | `Array_Delete` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 2 | Array_Construct, Array_Destroy |
| `0x8` | 4 | 1 | Array_Construct |
| `0xc` | 4 | 1 | Array_Construct |
| `0x10` | 4 | 1 | Array_Construct |

## Vtable references

- `Array_Construct`
- `Array_Destroy`
