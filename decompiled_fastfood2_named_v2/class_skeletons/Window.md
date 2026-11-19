# Window

- Vtable: `0x55c814`
- Constructor: `Window_Construct`
- Destructor: `Window_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

## Virtual methods

| # | Method |
|---:|---|
| 0 | `Window_Delete` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 2 | FullscreenImage_Load, Window_Construct |
| `0x8` | 4 | 2 | FullscreenImage_Load, Window_Construct |
| `0xc` | 4 | 1 | Window_Construct |
| `0x10` | 1 | 2 | Window_Construct, Window_LoadSpriteCached |
| `0x11` | 1 | 2 | FullscreenImage_Load, Window_Construct |
| `0x14` | 4 | 3 | FullscreenImage_Load, Window_Construct, Window_Destroy |
| `0x18` | 4 | 3 | FullscreenImage_Load, Window_Construct, Window_Destroy |
| `0x82f8` | 4 | 1 | Window_LoadSpriteCached |
| `0x82fc` | 4 | 1 | Window_LoadSpriteCached |
| `0x8300` | 4 | 1 | Window_LoadSpriteCached |

## Vtable references

- `FullscreenImage_Load`
- `Window_Construct`
- `Window_Destroy`
