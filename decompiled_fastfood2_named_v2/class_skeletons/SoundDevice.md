# SoundDevice

- Vtable: `0x55c830`
- Constructor: `SoundDevice_Construct`
- Destructor: `SoundBuffer_Delete`
- Base guess: ``
- Slots: 4
- Naming notes: slot0 is RefCount_AddRef; destructor is slot 3; slots 0-2 implement COM AddRef/Release/QueryInterface

## Virtual methods

| # | Method |
|---:|---|
| 0 | `RefCount_AddRef` * |
| 1 | `RefCount_Release` |
| 2 | `COM_QueryInterfaceGuid` |
| 3 | `SoundBuffer_Delete` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x3` | 1 | 1 | SoundBuffer_DestructBase |
| `0x4` | 4 | 1 | SoundDevice_Construct |
| `0x8` | 4 | 1 | SoundBuffer_DestructBase |
| `0xc` | 1 | 1 | SoundDevice_Construct |

## Vtable references

- `SoundBuffer_DestructBase`
- `SoundDevice_Construct`
