# SoundBufferAux

- Vtable: `0x55cb14`
- Constructor: ``
- Destructor: `SoundBuffer_Delete2`
- Base guess: ``
- Slots: 4
- Naming notes: slot0 is RefCount_AddRef; destructor is slot 3; slots 0-2 implement COM AddRef/Release/QueryInterface

## Virtual methods

| # | Method |
|---:|---|
| 0 | `RefCount_AddRef` * |
| 1 | `RefCount_Release` |
| 2 | `COM_QueryInterfaceGuid` |
| 3 | `SoundBuffer_Delete2` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x8` | 4 | 1 | SoundBuffer_Destructor |
| `0xc` | 4 | 1 | SoundBuffer_Destructor |

## Vtable references

- `SoundBuffer_Destructor`
