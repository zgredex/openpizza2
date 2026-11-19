# BuildingValue

- Vtable: `0x55c5a4`
- Constructor: `BuildingValue_Construct`
- Destructor: `BuildingValue_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

## Virtual methods

| # | Method |
|---:|---|
| 0 | `BuildingValue_Delete` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x8` | 4 | 2 | BuildingValue_Load, BuildingValue_Save |
| `0xc` | 4 | 4 | BuildingValue_Construct, BuildingValue_ConstructDefault, BuildingValue_Load, BuildingValue_Save |
| `0x10` | 8 | 4 | BuildingValue_Construct, BuildingValue_ConstructDefault, BuildingValue_Load, BuildingValue_Save |
| `0x14` | 4 | 2 | BuildingValue_Construct, BuildingValue_ConstructDefault |
| `0x18` | 4 | 4 | BuildingValue_Construct, BuildingValue_ConstructDefault, BuildingValue_Load, BuildingValue_Save |
| `0x1c` | 1 | 4 | BuildingValue_Construct, BuildingValue_ConstructDefault, BuildingValue_Load, BuildingValue_Save |

## Vtable references

- `BuildingValue_Construct`
- `BuildingValue_ConstructDefault`
- `BuildingValue_Destroy`
- `BuildingValue_StreamConstruct`
