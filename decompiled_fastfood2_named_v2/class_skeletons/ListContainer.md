# ListContainer

- Vtable: `0x55cb04`
- Constructor: ``
- Destructor: `List_ContainerDestroy`
- Base guess: ``
- Slots: 4
- Naming notes: slot0 is RefCount_AddRef; destructor is slot 3; slots 0-2 implement COM AddRef/Release/QueryInterface

## Virtual methods

| # | Method |
|---:|---|
| 0 | `RefCount_AddRef` * |
| 1 | `RefCount_Release` |
| 2 | `COM_QueryInterfaceGuid` |
| 3 | `List_ContainerDestroy` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x8` | 4 | 1 | List_ContainerDestruct |
| `0x10` | 4 | 1 | List_ContainerDestruct |
| `0x14` | 4 | 1 | List_ContainerDestruct |

## Vtable references

- `List_ContainerDestruct`
