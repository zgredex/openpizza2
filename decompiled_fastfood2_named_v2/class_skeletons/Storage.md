# Storage

- Vtable: `0x55c700`
- Constructor: `Storage_Construct`
- Destructor: `Storage_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

## Virtual methods

| # | Method |
|---:|---|
| 0 | `Storage_Delete` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 0 | 2 | Storage_LoadRecord, Storage_SaveRecord |
| `0x24` | 4 | 3 | Storage_Construct, Storage_LoadRecord, Storage_SaveRecord |
| `0x28` | 4 | 3 | Storage_Construct, Storage_LoadRecord, Storage_SaveRecord |
| `0x2c` | 4 | 3 | Storage_Construct, Storage_LoadRecord, Storage_SaveRecord |
| `0x30` | 4 | 3 | Storage_Construct, Storage_LoadRecord, Storage_SaveRecord |
| `0x34` | 4 | 3 | Storage_Construct, Storage_LoadRecord, Storage_SaveRecord |
| `0x38` | 4 | 3 | Storage_Construct, Storage_LoadRecord, Storage_SaveRecord |
| `0x3c` | 1 | 3 | Storage_Construct, Storage_LoadRecord, Storage_SaveRecord |
| `0x40` | 4 | 3 | Storage_Construct, Storage_LoadRecord, Storage_SaveRecord |
| `0x58` | 0 | 1 | Storage_SaveRecord |
| `0x60` | 0 | 2 | Storage_LoadRecord, Storage_SaveRecord |

## Vtable references

- `Storage_Construct`
- `Storage_Destroy`
