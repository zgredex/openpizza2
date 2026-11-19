# TimerClass

- Vtable: `0x55c308`
- Constructor: `TimerClass_Construct`
- Destructor: `TimerClass_ScalarDeletingDestructor`
- Base guess: ``
- Slots: 1
- Naming notes: -

## Virtual methods

| # | Method |
|---:|---|
| 0 | `TimerClass_ScalarDeletingDestructor` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 2 | TimerClass_Construct, Timer_Destroy |
| `0x8` | 4 | 2 | TimerClass_Construct, Timer_Destroy |
| `0xc` | 4 | 1 | TimerClass_Construct |
| `0x68` | 4 | 1 | TimerClass_Construct |
| `0x6c` | 4 | 2 | TimerClass_Construct, Timer_Destroy |

## Vtable references

- `TimerClass_Construct`
- `Timer_Destroy`
