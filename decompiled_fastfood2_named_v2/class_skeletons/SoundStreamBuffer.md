# SoundStreamBuffer

- Vtable: `0x55c8b0`
- Constructor: `SoundStreamBuffer_Construct`
- Destructor: `SoundStreamBuffer_DeleteObject`
- Base guess: ``
- Slots: 6
- Naming notes: slot0 is RefCount_AddRef; destructor is slot 3; slots 0-2 implement COM AddRef/Release/QueryInterface

## Virtual methods

| # | Method |
|---:|---|
| 0 | `RefCount_AddRef` * |
| 1 | `RefCount_Release` |
| 2 | `COM_QueryInterfaceGuid` |
| 3 | `SoundStreamBuffer_DeleteObject` |
| 4 | `SoundStreamBuffer_vfunc4_ForwardQuery` * |
| 5 | `COM_E_NOTIMPL_Ret4` * |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0xd` | 1 | 1 | SoundStreamBuffer_Destruct |
| `0x38` | 4 | 1 | SoundStreamBuffer_Destruct |
| `0x40` | 4 | 1 | SoundStreamBuffer_Destruct |
| `0x44` | 4 | 1 | SoundStreamBuffer_Destruct |
| `0x48` | 4 | 2 | SoundStreamBuffer_Construct, SoundStreamBuffer_Destruct |
| `0x4c` | 4 | 1 | SoundStreamBuffer_Construct |
| `0x50` | 4 | 1 | SoundStreamBuffer_Construct |
| `0x54` | 4 | 1 | SoundStreamBuffer_Construct |
| `0x58` | 4 | 1 | SoundStreamBuffer_Construct |
| `0x5c` | 4 | 1 | SoundStreamBuffer_Destruct |
| `0xa0` | 1 | 1 | SoundStreamBuffer_Construct |
| `0xa1` | 1 | 1 | SoundStreamBuffer_Construct |
| `0xa4` | 4 | 1 | SoundStreamBuffer_Construct |
| `0xa8` | 4 | 1 | SoundStreamBuffer_Construct |
| `0xac` | 4 | 2 | SoundStreamBuffer_Construct, SoundStreamBuffer_Destruct |
| `0xb0` | 4 | 1 | SoundStreamBuffer_Construct |

## Vtable references

- `SoundStreamBuffer_Construct`
- `SoundStreamBuffer_Destruct`
- `Sound_CreateAndEnqueueBuffer`
