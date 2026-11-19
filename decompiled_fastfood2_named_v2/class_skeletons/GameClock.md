# GameClock

- Vtable: `0x55c564`
- Constructor: `GameClock_Construct`
- Destructor: `GameClock_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: -

## Virtual methods

| # | Method |
|---:|---|
| 0 | `GameClock_Delete` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 2 | 1 | GameClock_Reset |
| `0x6` | 1 | 1 | GameClock_Reset |
| `0x7` | 1 | 1 | GameClock_Reset |
| `0x8` | 1 | 1 | GameClock_Reset |
| `0xa` | 2 | 1 | GameClock_Reset |
| `0xc` | 4 | 1 | GameClock_Reset |
| `0x10` | 4 | 1 | GameClock_Reset |
| `0x14` | 4 | 1 | GameClock_Construct |
| `0x18` | 1 | 1 | GameClock_Reset |
| `0x19` | 1 | 1 | GameClock_Reset |
| `0x1c` | 4 | 1 | GameClock_Construct |
| `0x20` | 4 | 2 | GameClock_Construct, GameClock_Destroy |
| `0x24` | 4 | 2 | GameClock_Construct, GameClock_Destroy |

## Vtable references

- `GameClock_Construct`
- `GameClock_Destroy`
