# SoundStreamBuffer3D

- Vtable: `0x55c8c8`
- Constructor: `SoundStreamBuffer_Construct`
- Destructor: `SoundBuffer_ScalarDeletingDestructor`
- Base guess: `SoundStreamBuffer`
- Slots: 6
- Naming notes: constructor symbol is SoundStreamBuffer_Construct (base/sibling name); slot0 is RefCount_AddRef; destructor is slot 3; base inferred: SoundStreamBuffer (slots 0-2,4,5 identical; only slot 3 differs); slots 0-2 implement COM AddRef/Release/QueryInterface

## Virtual methods

| # | Method |
|---:|---|
| 0 | `RefCount_AddRef` * |
| 1 | `RefCount_Release` |
| 2 | `COM_QueryInterfaceGuid` |
| 3 | `SoundBuffer_ScalarDeletingDestructor` |
| 4 | `SoundStreamBuffer_vfunc4_ForwardQuery` * |
| 5 | `COM_E_NOTIMPL_Ret4` * |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0xc` | 4 | 1 | Sound_CreateAndRegisterBuffer |
| `0xd` | 1 | 2 | SoundBuffer_DestroyInterfaces, SoundStreamBuffer_Destruct |
| `0x28` | 1 | 1 | Sound_CreateAndRegisterBuffer |
| `0x38` | 4 | 2 | SoundBuffer_DestroyInterfaces, SoundStreamBuffer_Destruct |
| `0x40` | 4 | 2 | SoundBuffer_DestroyInterfaces, SoundStreamBuffer_Destruct |
| `0x44` | 4 | 2 | SoundBuffer_DestroyInterfaces, SoundStreamBuffer_Destruct |
| `0x48` | 4 | 5 | SoundBuffer_Construct, SoundBuffer_DestroyInterfaces, SoundStreamBuffer_Construct, SoundStreamBuffer_Destruct, Sound_CreateAndRegisterBuffer |
| `0x4c` | 4 | 3 | SoundBuffer_Construct, SoundStreamBuffer_Construct, Sound_CreateAndRegisterBuffer |
| `0x50` | 4 | 3 | SoundBuffer_Construct, SoundStreamBuffer_Construct, Sound_CreateAndRegisterBuffer |
| `0x54` | 4 | 3 | SoundBuffer_Construct, SoundStreamBuffer_Construct, Sound_CreateAndRegisterBuffer |
| `0x58` | 4 | 3 | SoundBuffer_Construct, SoundStreamBuffer_Construct, Sound_CreateAndRegisterBuffer |
| `0x5c` | 4 | 2 | SoundBuffer_DestroyInterfaces, SoundStreamBuffer_Destruct |
| `0x98` | 4 | 1 | Sound_CreateAndRegisterBuffer |
| `0xa0` | 1 | 2 | SoundBuffer_Construct, SoundStreamBuffer_Construct |
| `0xa1` | 1 | 3 | SoundBuffer_Construct, SoundStreamBuffer_Construct, Sound_CreateAndRegisterBuffer |
| `0xa4` | 4 | 3 | SoundBuffer_Construct, SoundStreamBuffer_Construct, Sound_CreateAndRegisterBuffer |
| `0xa8` | 4 | 3 | SoundBuffer_Construct, SoundStreamBuffer_Construct, Sound_CreateAndRegisterBuffer |
| `0xac` | 4 | 2 | SoundStreamBuffer_Construct, SoundStreamBuffer_Destruct |
| `0xb0` | 4 | 1 | SoundStreamBuffer_Construct |

## Vtable references

- `SoundBuffer_Construct`
- `SoundBuffer_DestroyInterfaces`
- `SoundStreamBuffer_Construct`
- `SoundStreamBuffer_Destruct`
- `Sound_CreateAndRegisterBuffer`
- `Sound_LoadSample3D`
