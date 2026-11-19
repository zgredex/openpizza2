# Renderer

- Vtable: `0x55c818`
- Constructor: `Renderer_ConstructRoot`
- Destructor: `Renderer_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

## Virtual methods

| # | Method |
|---:|---|
| 0 | `Renderer_Delete` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0xc` | 1 | 1 | Renderer_Destroy |
| `0x14` | 4 | 2 | Renderer_ConstructChild, Renderer_ConstructRoot |
| `0x18` | 1 | 2 | Renderer_ConstructRoot, Renderer_InitOrCopyState |
| `0x1a` | 2 | 2 | Renderer_ConstructRoot, Renderer_InitOrCopyState |
| `0x1c` | 2 | 2 | Renderer_ConstructRoot, Renderer_InitOrCopyState |
| `0x24` | 4 | 1 | Renderer_InitOrCopyState |
| `0x2c` | 4 | 2 | Renderer_ConstructRoot, Renderer_InitOrCopyState |
| `0x30` | 1 | 2 | Renderer_ConstructChild, Renderer_ConstructRoot |
| `0x34` | 4 | 1 | Renderer_InitOrCopyState |
| `0x38` | 4 | 1 | Renderer_InitOrCopyState |
| `0x3c` | 4 | 1 | Renderer_InitOrCopyState |
| `0x40` | 4 | 5 | Renderer_ConstructChild, Renderer_ConstructRoot, Renderer_Destroy, Renderer_InitForWindow, Renderer_InitOrCopyState |
| `0x44` | 4 | 2 | Renderer_ConstructRoot, Renderer_InitOrCopyState |
| `0x48` | 4 | 2 | Renderer_ConstructRoot, Renderer_InitOrCopyState |
| `0x4c` | 4 | 2 | Renderer_ConstructChild, Renderer_ConstructRoot |
| `0x50` | 4 | 3 | Renderer_ConstructChild, Renderer_ConstructRoot, Renderer_Destroy |
| `0x54` | 4 | 4 | Renderer_ConstructChild, Renderer_ConstructRoot, Renderer_Destroy, Renderer_InitOrCopyState |
| `0x58` | 4 | 2 | Renderer_ConstructRoot, Renderer_InitOrCopyState |
| `0x5c` | 4 | 2 | Renderer_ConstructRoot, Renderer_InitOrCopyState |
| `0x60` | 4 | 2 | Renderer_ConstructRoot, Renderer_InitOrCopyState |
| `0x74` | 4 | 1 | Renderer_InitOrCopyState |
| `0x78` | 4 | 2 | Renderer_ConstructChild, Renderer_ConstructRoot |
| `0x7c` | 4 | 2 | Renderer_ConstructChild, Renderer_ConstructRoot |
| `0x80` | 4 | 2 | Renderer_ConstructChild, Renderer_ConstructRoot |
| `0x84` | 4 | 2 | Renderer_ConstructRoot, Renderer_InitOrCopyState |
| `0x88` | 4 | 2 | Renderer_ConstructRoot, Renderer_InitOrCopyState |
| `0x8c` | 4 | 2 | Renderer_ConstructRoot, Renderer_InitOrCopyState |
| `0x90` | 4 | 2 | Renderer_ConstructRoot, Renderer_InitOrCopyState |
| `0x94` | 4 | 3 | Renderer_ConstructRoot, Renderer_InitForWindow, Renderer_InitOrCopyState |
| `0x98` | 4 | 1 | Renderer_ConstructRoot |

## Vtable references

- `Renderer_ConstructChild`
- `Renderer_ConstructRoot`
- `Renderer_Destroy`
