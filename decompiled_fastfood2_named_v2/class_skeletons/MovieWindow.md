# MovieWindow

- Vtable: `0x55c7b0`
- Constructor: `MovieWindow_Construct`
- Destructor: `MovieWindow_Delete`
- Base guess: `UI_Child`
- Slots: 7
- Naming notes: -

## Virtual methods

| # | Method |
|---:|---|
| 0 | `MovieWindow_Delete` |
| 1 | `Map_DrawRenderableByType` |
| 2 | `MovieWindow_vfunc2` * |
| 3 | `MovieWindow_vfunc3` * |
| 4 | `MovieWindow_IsPlaying` * |
| 5 | `UI_Child_ForwardToVFunc4` * |
| 6 | `Movie_UpdateFrame` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x8` | 4 | 1 | MovieWindow_Destroy |
| `0x15` | 1 | 1 | MovieWindow_Destroy |
| `0x28` | 4 | 1 | MovieWindow_Construct |
| `0x2c` | 4 | 1 | MovieWindow_Construct |
| `0x40` | 4 | 1 | MovieWindow_Construct |
| `0x54` | 4 | 1 | MovieWindow_Destroy |
| `0x94` | 4 | 2 | MovieWindow_Construct, MovieWindow_Destroy |
| `0x98` | 4 | 2 | MovieWindow_Construct, MovieWindow_Destroy |
| `0x9c` | 4 | 1 | MovieWindow_Construct |
| `0xa0` | 4 | 2 | MovieWindow_Construct, MovieWindow_Destroy |
| `0xa4` | 4 | 2 | MovieWindow_Construct, MovieWindow_Destroy |
| `0xa8` | 4 | 1 | MovieWindow_Construct |
| `0xac` | 4 | 2 | MovieWindow_Construct, MovieWindow_Destroy |
| `0xb0` | 4 | 1 | MovieWindow_Construct |
| `0xb4` | 4 | 1 | MovieWindow_Construct |
| `0xb8` | 4 | 2 | MovieWindow_Construct, MovieWindow_Destroy |

## Vtable references

- `MovieWindow_Construct`
- `MovieWindow_Destroy`
