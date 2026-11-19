# GameCompanyManager

- Vtable: `0x55c618`
- Constructor: `Game_CompanyManager_Construct`
- Destructor: `Game_CompanyManager_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

## Virtual methods

| # | Method |
|---:|---|
| 0 | `Game_CompanyManager_Delete` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 1 | Game_CompanyManager_Destructor |
| `0x8` | 4 | 2 | Game_CompanyManager_Construct, Game_CompanyManager_Destructor |
| `0xc` | 4 | 1 | Game_CompanyManager_Construct |
| `0x10` | 4 | 1 | Game_CompanyManager_Construct |
| `0x18` | 4 | 2 | Game_CompanyManager_Construct, Game_CompanyManager_Destructor |
| `0x1c` | 4 | 2 | Game_CompanyManager_Construct, Game_CompanyManager_Destructor |
| `0x38` | 4 | 1 | Game_CompanyManager_Construct |

## Vtable references

- `Game_CompanyManager_Construct`
- `Game_CompanyManager_Destructor`
