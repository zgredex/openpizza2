# Sprite

- Vtable: `0x55c82c`
- Constructor: `Sprite_CreateRaw`
- Destructor: `Sprite_ScalarDeletingDestructor`
- Base guess: `SpriteBase`
- Slots: 1
- Naming notes: -

## Virtual methods

| # | Method |
|---:|---|
| 0 | `Sprite_ScalarDeletingDestructor` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 1 | 4 | Sprite_CreateRaw, Sprite_InitFormat, Sprite_Load, Sprite_LoadIntoSlot78 |
| `0x5` | 1 | 2 | Sprite_InitFormat, Sprite_Load |
| `0x6` | 2 | 1 | Sprite_InitFormat |
| `0x8` | 2 | 1 | Sprite_InitFormat |
| `0xa` | 2 | 1 | Sprite_InitFormat |
| `0xc` | 2 | 1 | Sprite_InitFormat |
| `0xd` | 1 | 1 | Sprite_Destruct |
| `0xe` | 2 | 1 | Sprite_CreateRaw |
| `0x10` | 2 | 1 | Sprite_CreateRaw |
| `0x12` | 2 | 1 | Sprite_InitFormat |
| `0x14` | 2 | 1 | Sprite_InitFormat |
| `0x18` | 4 | 3 | Sprite_CreateRaw, Sprite_InitFormat, Sprite_Load |
| `0x1c` | 4 | 1 | Sprite_InitFormat |
| `0x20` | 4 | 3 | Sprite_CreateRaw, Sprite_Destruct, Sprite_Load |
| `0x24` | 4 | 3 | Sprite_CreateRaw, Sprite_Destruct, Sprite_Load |
| `0x28` | 4 | 2 | Sprite_CreateRaw, Sprite_Load |
| `0x2c` | 4 | 3 | Sprite_CreateRaw, Sprite_Destruct, Sprite_Load |
| `0x30` | 4 | 3 | Sprite_CreateRaw, Sprite_Destruct, Sprite_Load |
| `0x34` | 1 | 2 | Sprite_CreateRaw, Sprite_Load |
| `0x35` | 1 | 1 | Sprite_Load |
| `0x36` | 1 | 2 | Sprite_CreateRaw, Sprite_Load |
| `0x38` | 1 | 2 | Sprite_CreateRaw, Sprite_Load |
| `0x39` | 1 | 2 | Sprite_CreateRaw, Sprite_Load |
| `0x3c` | 4 | 3 | Sprite_CreateRaw, Sprite_Destruct, Sprite_Load |
| `0x40` | 4 | 1 | Sprite_Load |
| `0x44` | 4 | 1 | Sprite_Load |
| `0x48` | 0 | 1 | Sprite_Load |
| `0x78` | 4 | 1 | Sprite_LoadIntoSlot78 |
| `0xf4` | 4 | 1 | Sprite_LoadIntoSlot78 |

## Vtable references

- `Sprite_CreateRaw`
- `Sprite_Destruct`
- `Sprite_Load`
