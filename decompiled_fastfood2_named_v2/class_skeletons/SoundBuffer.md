# SoundBuffer

- Vtable: `0x55c874`
- Constructor: `SoundBuffer_CreateDSBuffer`
- Destructor: `SoundBuffer_DeleteObject`
- Base guess: `SoundBufferBase`
- Slots: 6
- Naming notes: slot0 is RefCount_AddRef; destructor is slot 3; base inferred: SoundBufferBase (slots 0-2 identical; adds slots 4,5); slots 0-2 implement COM AddRef/Release/QueryInterface

## Virtual methods

| # | Method |
|---:|---|
| 0 | `RefCount_AddRef` * |
| 1 | `RefCount_Release` |
| 2 | `COM_QueryInterfaceGuid` |
| 3 | `SoundBuffer_DeleteObject` |
| 4 | `SoundBuffer_vfunc4` * |
| 5 | `Sound_SetVolumeLogarithmic` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x3` | 1 | 1 | SoundBuffer_DestructBase |
| `0x4` | 4 | 3 | SoundBuffer_ConstructBase, SoundBuffer_CreateDSBuffer, SoundBuffer_Init |
| `0x8` | 4 | 4 | SoundBuffer_CreateDSBuffer, SoundBuffer_DestructBase, SoundBuffer_Destructor, SoundBuffer_Init |
| `0xc` | 4 | 3 | SoundBuffer_CreateDSBuffer, SoundBuffer_Destructor, SoundBuffer_Init |
| `0xd` | 1 | 3 | SoundBuffer_DestroyInterfaces, SoundBuffer_DestructDerived, SoundStreamBuffer_Destruct |
| `0x10` | 4 | 2 | SoundBuffer_CreateDSBuffer, SoundBuffer_Init |
| `0x14` | 4 | 2 | SoundBuffer_CreateDSBuffer, SoundBuffer_Init |
| `0x18` | 4 | 2 | SoundBuffer_CreateDSBuffer, SoundBuffer_Init |
| `0x1c` | 4 | 2 | SoundBuffer_CreateDSBuffer, SoundBuffer_Init |
| `0x20` | 4 | 2 | SoundBuffer_CreateDSBuffer, SoundBuffer_Init |
| `0x24` | 4 | 2 | SoundBuffer_CreateDSBuffer, SoundBuffer_Init |
| `0x28` | 2 | 2 | SoundBuffer_CreateDSBuffer, SoundBuffer_Init |
| `0x2c` | 4 | 2 | SoundBuffer_CreateDSBuffer, SoundBuffer_Init |
| `0x30` | 4 | 2 | SoundBuffer_CreateDSBuffer, SoundBuffer_Init |
| `0x34` | 1 | 2 | SoundBuffer_CreateDSBuffer, SoundBuffer_Init |
| `0x38` | 4 | 5 | SoundBuffer_CreateDSBuffer, SoundBuffer_DestroyInterfaces, SoundBuffer_DestructDerived, SoundBuffer_Init, SoundStreamBuffer_Destruct |
| `0x3c` | 4 | 2 | SoundBuffer_CreateDSBuffer, SoundBuffer_Init |
| `0x40` | 4 | 5 | SoundBuffer_CreateDSBuffer, SoundBuffer_DestroyInterfaces, SoundBuffer_DestructDerived, SoundBuffer_Init, SoundStreamBuffer_Destruct |
| `0x44` | 4 | 5 | SoundBuffer_CreateDSBuffer, SoundBuffer_DestroyInterfaces, SoundBuffer_DestructDerived, SoundBuffer_Init, SoundStreamBuffer_Destruct |
| `0x48` | 4 | 5 | SoundBuffer_Construct, SoundBuffer_CreateDSBuffer, SoundBuffer_DestroyInterfaces, SoundBuffer_DestructDerived, SoundStreamBuffer_Destruct |
| `0x4c` | 4 | 1 | SoundBuffer_Construct |
| `0x50` | 4 | 1 | SoundBuffer_Construct |
| `0x54` | 4 | 1 | SoundBuffer_Construct |
| `0x58` | 4 | 1 | SoundBuffer_Construct |
| `0x5c` | 4 | 2 | SoundBuffer_DestroyInterfaces, SoundStreamBuffer_Destruct |
| `0xa0` | 1 | 1 | SoundBuffer_Construct |
| `0xa1` | 1 | 1 | SoundBuffer_Construct |
| `0xa4` | 4 | 1 | SoundBuffer_Construct |
| `0xa8` | 4 | 1 | SoundBuffer_Construct |
| `0xac` | 4 | 1 | SoundStreamBuffer_Destruct |
| `0x149` | 1 | 1 | SoundBuffer_ConstructBase |
| `0x238` | 4 | 1 | SoundBuffer_ConstructBase |
| `0x628` | 4 | 1 | SoundBuffer_ConstructBase |

## Vtable references

- `SoundBuffer_CreateDSBuffer`
- `SoundBuffer_DestroyInterfaces`
- `SoundBuffer_DestructDerived`
- `SoundBuffer_Init`
- `SoundStreamBuffer_Destruct`
