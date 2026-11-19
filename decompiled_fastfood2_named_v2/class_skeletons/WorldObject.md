# WorldObject

- Vtable: `0x55c668`
- Constructor: `Object_Construct`
- Destructor: `WorldObject_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: constructor symbol is Object_Construct (base/sibling name)

## Virtual methods

| # | Method |
|---:|---|
| 0 | `WorldObject_Delete` * |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x24` | 4 | 1 | Object_Construct |
| `0x28` | 4 | 1 | Object_Construct |
| `0x2c` | 4 | 1 | Object_Construct |
| `0x30` | 4 | 1 | Object_Construct |
| `0x34` | 4 | 1 | Object_Construct |
| `0x38` | 4 | 1 | Object_Construct |
| `0x3c` | 4 | 1 | Object_Construct |
| `0x40` | 2 | 1 | Object_Construct |
| `0x4c` | 4 | 1 | Object_Construct |
| `0x50` | 4 | 1 | Object_Construct |
| `0x54` | 4 | 1 | Object_Construct |
| `0x58` | 4 | 1 | Object_Construct |
| `0x74` | 4 | 1 | Object_Construct |
| `0x78` | 4 | 1 | Object_Construct |
| `0x7c` | 4 | 1 | Object_Construct |
| `0x80` | 1 | 1 | Object_Construct |
| `0x81` | 1 | 1 | Object_Construct |
| `0x84` | 4 | 1 | Object_Construct |
| `0x88` | 4 | 1 | Object_Construct |
| `0x8c` | 4 | 1 | Object_Construct |
| `0x90` | 4 | 1 | Object_Construct |
| `0x94` | 4 | 1 | Object_Construct |
| `0x98` | 4 | 1 | Object_Construct |
| `0x9c` | 4 | 1 | Object_Construct |
| `0xa0` | 4 | 1 | Object_Construct |
| `0xa4` | 4 | 1 | Object_Construct |
| `0xa8` | 4 | 1 | Object_Construct |
| `0xc4` | 4 | 1 | Object_Construct |
| `0xcc` | 4 | 1 | Object_Construct |
| `0xd0` | 4 | 1 | Object_Construct |
| `0xf4` | 4 | 1 | Object_Construct |
| `0xf8` | 4 | 1 | Object_Construct |
| `0x100` | 4 | 1 | Object_Construct |
| `0x104` | 1 | 1 | Object_Construct |
| `0x108` | 4 | 1 | Object_Construct |
| `0x10c` | 4 | 1 | Object_Construct |
| `0x110` | 4 | 1 | Object_Construct |
| `0x164` | 4 | 1 | Object_Construct |
| `0x168` | 4 | 2 | Object_Construct, Person_ConstructFromSave |

## Vtable references

- `Object_Construct`
- `Person_ConstructFromSave`
- `UI_DestroyPanel`
