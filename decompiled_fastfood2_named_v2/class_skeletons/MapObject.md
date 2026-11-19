# MapObject

- Vtable: `0x55c4ec`
- Constructor: `MapObject_Construct`
- Destructor: `MapObject_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

## Virtual methods

| # | Method |
|---:|---|
| 0 | `MapObject_Delete` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 4 | MapObject_Construct, MapObject_Destroy, MapObject_Load, MapObject_Save |
| `0x8` | 4 | 3 | MapObject_Construct, MapObject_Load, MapObject_Save |
| `0xc` | 4 | 3 | MapObject_Construct, MapObject_Load, MapObject_Save |
| `0x10` | 0 | 2 | MapObject_Load, MapObject_Save |
| `0x20` | 4 | 3 | MapObject_Construct, MapObject_Load, MapObject_Save |
| `0x24` | 4 | 4 | MapObject_Construct, MapObject_InitRenderRecord, MapObject_Load, MapObject_Save |
| `0x28` | 4 | 2 | MapObject_Construct, MapObject_Load |
| `0x2c` | 4 | 3 | MapObject_Construct, MapObject_Load, MapObject_Save |
| `0x30` | 4 | 4 | MapObject_Construct, MapObject_InitRenderRecord, MapObject_Load, MapObject_Save |
| `0x34` | 4 | 3 | MapObject_Construct, MapObject_Load, MapObject_Save |
| `0x38` | 4 | 3 | MapObject_Construct, MapObject_Load, MapObject_Save |
| `0x3c` | 4 | 3 | MapObject_Construct, MapObject_Load, MapObject_Save |
| `0x40` | 8 | 3 | MapObject_Construct, MapObject_Load, MapObject_Save |
| `0x44` | 4 | 1 | MapObject_Construct |
| `0x48` | 4 | 3 | MapObject_Construct, MapObject_Load, MapObject_Save |
| `0x4c` | 4 | 3 | MapObject_Construct, MapObject_Load, MapObject_Save |
| `0x50` | 4 | 3 | MapObject_Construct, MapObject_Load, MapObject_Save |
| `0x54` | 4 | 3 | MapObject_Construct, MapObject_Load, MapObject_Save |
| `0x6c` | 4 | 1 | MapObject_Save |
| `0x74` | 4 | 5 | MapObject_Construct, MapObject_Destroy, MapObject_InitRenderRecord, MapObject_Load, MapObject_Save |
| `0x8c` | 0 | 1 | MapObject_Save |
| `0x94` | 4 | 3 | MapObject_Construct, MapObject_Load, MapObject_Save |
| `0xc4` | 4 | 1 | MapObject_InitRenderRecord |
| `0xc8` | 4 | 1 | MapObject_InitRenderRecord |

## Vtable references

- `MapObject_Construct`
- `MapObject_Destroy`
