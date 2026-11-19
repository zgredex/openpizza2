# ResourceManager

- Vtable: `0x55c2f0`
- Constructor: `ResourceManager_Construct`
- Destructor: `ResourceManager_ScalarDeletingDestructor`
- Base guess: ``
- Slots: 1
- Naming notes: -

## Virtual methods

| # | Method |
|---:|---|
| 0 | `ResourceManager_ScalarDeletingDestructor` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x66c` | 1 | 1 | ResourceManager_Construct |
| `0x1684` | 4 | 2 | ResourceManager_Construct, ResourceManager_Destruct |
| `0x1ab4` | 4 | 2 | ResourceManager_Construct, ResourceManager_Destruct |
| `0x1ab8` | 4 | 1 | ResourceManager_Construct |
| `0x1abc` | 4 | 1 | ResourceManager_Construct |
| `0x1ac0` | 4 | 1 | ResourceManager_Construct |

## Vtable references

- `ResourceManager_Construct`
- `ResourceManager_Destruct`
