# SoundBufferBase

- Vtable: `0x55c840`
- Constructor: `SoundBuffer_ConstructBase`
- Destructor: `SoundBufferBase_Delete`
- Base guess: ``
- Slots: 4
- Naming notes: constructor symbol is SoundBuffer_ConstructBase (base/sibling name); slot0 is RefCount_AddRef; destructor is slot 3; slots 0-2 implement COM AddRef/Release/QueryInterface

## Virtual methods

| # | Method |
|---:|---|
| 0 | `RefCount_AddRef` * |
| 1 | `RefCount_Release` |
| 2 | `COM_QueryInterfaceGuid` |
| 3 | `SoundBufferBase_Delete` * |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x3` | 1 | 1 | SoundBuffer_DestructBase |
| `0x4` | 4 | 3 | SoundBuffer_ConstructBase, SoundBuffer_CreateDSBuffer, SoundVoice_Construct |
| `0x8` | 4 | 6 | List_ContainerDestruct, SoundBuffer_CreateDSBuffer, SoundBuffer_DestructBase, SoundBuffer_Destructor, SoundSample_Destruct, SoundVoice_Construct |
| `0xc` | 4 | 4 | SoundBuffer_CreateDSBuffer, SoundBuffer_Destructor, SoundSample_Destruct, SoundVoice_Construct |
| `0xd` | 1 | 3 | SoundBuffer_DestroyInterfaces, SoundBuffer_DestructDerived, SoundStreamBuffer_Destruct |
| `0x10` | 4 | 4 | List_ContainerDestruct, SoundBuffer_CreateDSBuffer, SoundSample_Destruct, SoundVoice_Construct |
| `0x14` | 4 | 3 | List_ContainerDestruct, SoundBuffer_CreateDSBuffer, SoundVoice_Construct |
| `0x18` | 4 | 2 | SoundBuffer_CreateDSBuffer, SoundVoice_Construct |
| `0x1c` | 4 | 2 | SoundBuffer_CreateDSBuffer, SoundVoice_Construct |
| `0x20` | 4 | 2 | SoundBuffer_CreateDSBuffer, SoundVoice_Construct |
| `0x24` | 4 | 2 | SoundBuffer_CreateDSBuffer, SoundVoice_Construct |
| `0x28` | 4 | 3 | SoundBuffer_CreateDSBuffer, SoundTrack_Destruct, SoundVoice_Construct |
| `0x2c` | 4 | 3 | SoundBuffer_CreateDSBuffer, SoundTrack_Destruct, SoundVoice_Construct |
| `0x30` | 4 | 3 | SoundBuffer_CreateDSBuffer, SoundTrack_Destruct, SoundVoice_Construct |
| `0x34` | 4 | 3 | SoundBuffer_CreateDSBuffer, SoundTrack_Destruct, SoundVoice_Construct |
| `0x38` | 4 | 5 | SoundBuffer_CreateDSBuffer, SoundBuffer_DestroyInterfaces, SoundBuffer_DestructDerived, SoundStreamBuffer_Destruct, SoundVoice_Construct |
| `0x3c` | 4 | 3 | SoundBuffer_CreateDSBuffer, SoundSample_Destruct, SoundVoice_Construct |
| `0x40` | 4 | 5 | SoundBuffer_CreateDSBuffer, SoundBuffer_DestroyInterfaces, SoundBuffer_DestructDerived, SoundStreamBuffer_Destruct, SoundVoice_Construct |
| `0x44` | 4 | 6 | SoundBuffer_CreateDSBuffer, SoundBuffer_DestroyInterfaces, SoundBuffer_DestructDerived, SoundStreamBuffer_Destruct, SoundTrack_Destruct, SoundVoice_Construct |
| `0x48` | 4 | 5 | SoundBuffer_CreateDSBuffer, SoundBuffer_DestroyInterfaces, SoundBuffer_DestructDerived, SoundStreamBuffer_Destruct, SoundVoice_Construct |
| `0x4c` | 4 | 1 | SoundVoice_Construct |
| `0x51` | 1 | 1 | SoundVoice_Construct |
| `0x53` | 1 | 1 | SoundVoice_Construct |
| `0x55` | 1 | 1 | SoundVoice_Construct |
| `0x5c` | 4 | 2 | SoundBuffer_DestroyInterfaces, SoundStreamBuffer_Destruct |
| `0x70` | 1 | 1 | SoundVoice_Construct |
| `0x74` | 4 | 1 | SoundVoice_Construct |
| `0x78` | 4 | 1 | SoundVoice_Construct |
| `0x7c` | 4 | 1 | SoundVoice_Construct |
| `0x80` | 4 | 1 | SoundVoice_Construct |
| `0x84` | 4 | 1 | SoundVoice_Construct |
| `0x88` | 1 | 1 | SoundVoice_Construct |
| `0x8c` | 4 | 1 | SoundVoice_Construct |
| `0x90` | 4 | 1 | SoundVoice_Construct |
| `0x94` | 4 | 1 | SoundVoice_Construct |
| `0x98` | 4 | 1 | SoundVoice_Construct |
| `0x9c` | 4 | 1 | SoundVoice_Construct |
| `0xac` | 4 | 1 | SoundStreamBuffer_Destruct |
| `0x149` | 1 | 1 | SoundBuffer_ConstructBase |
| `0x238` | 4 | 2 | SoundBuffer_ConstructBase, SoundPakManager_Destruct |
| `0x628` | 4 | 2 | SoundBuffer_ConstructBase, SoundPakManager_Destruct |

## Vtable references

- `List_ContainerDestruct`
- `SoundBuffer_ConstructBase`
- `SoundBuffer_CreateDSBuffer`
- `SoundBuffer_DestroyInterfaces`
- `SoundBuffer_DestructBase`
- `SoundBuffer_DestructDerived`
- `SoundBuffer_Destructor`
- `SoundBuffer_Init`
- `SoundBuffer_SetBaseVTable`
- `SoundPakManager_Destruct`
- `SoundSample_Destruct`
- `SoundStreamBuffer_Destruct`
- `SoundTrack_Destruct`
- `SoundVoice_Construct`
- `Sound_LoadSample2D`
- `Sound_LoadSample3D`
- `Sound_LoadSample3DEx`
