# FileObject

- Vtable: `0x55c2f4`
- Constructor: `FileObject_Open`
- Destructor: `FileObject_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

## Virtual methods

| # | Method |
|---:|---|
| 0 | `FileObject_Delete` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 2 | FileObject_Destroy, FileObject_Open |
| `0x8` | 4 | 2 | FileObject_Destroy, FileObject_Open |
| `0xc` | 4 | 2 | FileObject_Destroy, FileObject_Open |
| `0x10` | 2 | 1 | FileObject_Open |
| `0x12` | 2 | 1 | FileObject_Open |
| `0x14` | 4 | 2 | FileObject_InitBase, FileObject_Open |
| `0x50` | 0 | 1 | FileObject_InitBase |

## Vtable references

- `FileObject_Destroy`
- `FileObject_Open`
