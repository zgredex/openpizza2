# Dialog

- Vtable: `0x55c808`
- Constructor: `Dialog_Construct`
- Destructor: `Dialog_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

## Virtual methods

| # | Method |
|---:|---|
| 0 | `Dialog_Delete` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 1 | Dialog_InitBase |
| `0x8` | 4 | 1 | Dialog_ConstructFixed |
| `0xc` | 4 | 1 | Dialog_ConstructFixed |
| `0x10` | 4 | 1 | Dialog_ConstructFixed |
| `0x14` | 4 | 1 | Dialog_ConstructFixed |
| `0x15` | 1 | 1 | Dialog_Destructor |
| `0x18` | 4 | 1 | Dialog_ConstructFixed |
| `0x1c` | 4 | 1 | Dialog_ConstructFixed |
| `0x20` | 4 | 1 | Dialog_ConstructFixed |
| `0x24` | 4 | 1 | Dialog_ConstructFixed |
| `0x28` | 4 | 1 | Dialog_SaveToFile |
| `0x2c` | 4 | 1 | Dialog_SaveToFile |
| `0x30` | 4 | 1 | Dialog_SaveToFile |
| `0x34` | 4 | 1 | Dialog_SaveToFile |
| `0x48` | 4 | 1 | Dialog_InitBase |
| `0x4c` | 4 | 1 | Dialog_InitBase |
| `0x50` | 4 | 2 | Dialog_Destructor, Dialog_InitBase |
| `0x54` | 1 | 2 | Dialog_ConstructWithSprite, Dialog_InitBase |
| `0x94` | 4 | 4 | Dialog_ConstructWithSprite, Dialog_Destructor, Dialog_InitBase, Dialog_SaveToFile |
| `0xd8` | 4 | 2 | Dialog_Destructor, Dialog_InitBase |
| `0xdc` | 4 | 2 | Dialog_Destructor, Dialog_InitBase |
| `0xe0` | 4 | 1 | Dialog_InitBase |
| `0xe4` | 4 | 1 | Dialog_InitBase |
| `0xe8` | 4 | 2 | Dialog_Destructor, Dialog_InitBase |
| `0xec` | 4 | 3 | Dialog_Destructor, Dialog_InitBase, Dialog_SaveToFile |
| `0xf0` | 4 | 3 | Dialog_Destructor, Dialog_InitBase, Dialog_SaveToFile |
| `0xf4` | 4 | 1 | Dialog_InitBase |
| `0xf8` | 1 | 5 | Dialog_ConstructWithPicture, Dialog_ConstructWithSprite, Dialog_Destructor, Dialog_InitBase, Dialog_SaveToFile |
| `0xfc` | 4 | 4 | Dialog_Construct, Dialog_ConstructFixed, Dialog_InitBase, Dialog_SaveToFile |
| `0x100` | 4 | 3 | Dialog_ConstructFixed, Dialog_InitBase, Dialog_SaveToFile |
| `0x104` | 4 | 3 | Dialog_ConstructFixed, Dialog_InitBase, Dialog_SaveToFile |
| `0x108` | 4 | 3 | Dialog_ConstructFixed, Dialog_InitBase, Dialog_SaveToFile |
| `0x10c` | 4 | 1 | Dialog_InitBase |
| `0x114` | 4 | 2 | Dialog_InitBase, Dialog_SaveToFile |
| `0x118` | 0 | 1 | Dialog_ConstructFixed |
| `0x120` | 0 | 1 | Dialog_ConstructFixed |
| `0x128` | 0 | 1 | Dialog_ConstructFixed |
| `0x130` | 0 | 1 | Dialog_ConstructFixed |
| `0x134` | 4 | 2 | Dialog_Destructor, Dialog_InitBase |
| `0x138` | 4 | 4 | Dialog_ConstructWithPicture, Dialog_Destructor, Dialog_InitBase, Dialog_SaveToFile |
| `0x13c` | 4 | 1 | Dialog_InitBase |
| `0x15c` | 4 | 2 | Dialog_Destructor, Dialog_InitBase |
| `0x160` | 4 | 2 | Dialog_Destructor, Dialog_InitBase |
| `0x164` | 4 | 1 | Dialog_InitBase |
| `0x168` | 4 | 2 | Dialog_InitBase, Dialog_SaveToFile |
| `0x16c` | 4 | 1 | Dialog_InitBase |
| `0x170` | 4 | 1 | Dialog_InitBase |
| `0x174` | 4 | 2 | Dialog_Destructor, Dialog_InitBase |
| `0x178` | 1 | 1 | Dialog_InitBase |
| `0x27c` | 4 | 1 | Dialog_InitBase |
| `0x284` | 4 | 1 | Dialog_InitBase |
| `0x28c` | 4 | 2 | Dialog_Destructor, Dialog_InitBase |
| `0x290` | 4 | 1 | Dialog_Destructor |
| `0x298` | 4 | 1 | Dialog_InitBase |
| `0x29c` | 4 | 1 | Dialog_InitBase |
| `0x2bc` | 4 | 1 | Dialog_InitBase |
| `0x2c0` | 4 | 1 | Dialog_InitBase |
| `0x2c4` | 4 | 1 | Dialog_ConstructFixed |

## Vtable references

- `Dialog_Construct`
- `Dialog_ConstructFixed`
- `Dialog_ConstructWithPicture`
- `Dialog_ConstructWithSprite`
- `Dialog_Destructor`
