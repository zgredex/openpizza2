# Car

- Vtable: `0x55c4f8`
- Constructor: `Car_Construct`
- Destructor: `Car_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

## Virtual methods

| # | Method |
|---:|---|
| 0 | `Car_Delete` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 2 | Car_Construct, Car_LoadFromStream |
| `0x8` | 4 | 3 | Car_Destroy, Car_LoadSpriteRecord, Car_Save |
| `0xc` | 4 | 3 | Car_Construct, Car_Destroy, Car_LoadFromStream |
| `0x10` | 4 | 1 | Car_Destroy |

## Vtable references

- `Car_Construct`
- `Car_ConstructFromSave`
- `Car_Destroy`
