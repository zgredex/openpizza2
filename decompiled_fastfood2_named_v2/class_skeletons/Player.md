# Player

- Vtable: `0x55c684`
- Constructor: `Player_Construct`
- Destructor: `Player_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

## Virtual methods

| # | Method |
|---:|---|
| 0 | `Player_Delete` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 3 | Player_Destroy, Player_Load, Player_Save |
| `0x8` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0xc` | 0 | 2 | Player_Load, Player_Save |
| `0x2c` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x30` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x34` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x38` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x3c` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x40` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x44` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x48` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x4c` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x50` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x54` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x58` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x5c` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x60` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x64` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x68` | 4 | 3 | Player_Construct, Player_Load, Player_Save |
| `0x6c` | 0 | 2 | Player_Load, Player_Save |
| `0x84` | 4 | 4 | Player_Construct, Player_Load, Player_ResetAiState, Player_Save |
| `0x88` | 4 | 4 | Player_Construct, Player_Load, Player_ResetAiState, Player_Save |
| `0xa0` | 4 | 2 | Player_Destroy, Player_Save |
| `0xa8` | 4 | 4 | Player_Construct, Player_Destroy, Player_Load, Player_Save |
| `0xac` | 4 | 5 | Player_Construct, Player_Destroy, Player_InitSlotFlags, Player_Load, Player_Save |

## Vtable references

- `Player_Construct`
- `Player_Destroy`
