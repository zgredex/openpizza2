# SoundVoice

- Vtable: `0x55c8e0`
- Constructor: `SoundVoice_Construct`
- Destructor: `SoundTrack_Delete`
- Base guess: ``
- Slots: 4
- Naming notes: slot0 is RefCount_AddRef; destructor is slot 3; slots 0-2 implement COM AddRef/Release/QueryInterface

## Virtual methods

| # | Method |
|---:|---|
| 0 | `RefCount_AddRef` * |
| 1 | `RefCount_Release` |
| 2 | `COM_QueryInterfaceGuid` |
| 3 | `SoundTrack_Delete` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 1 | SoundVoice_Construct |
| `0x8` | 4 | 1 | SoundVoice_Construct |
| `0xc` | 4 | 1 | SoundVoice_Construct |
| `0x10` | 4 | 1 | SoundVoice_Construct |
| `0x14` | 4 | 1 | SoundVoice_Construct |
| `0x18` | 4 | 1 | SoundVoice_Construct |
| `0x1c` | 4 | 1 | SoundVoice_Construct |
| `0x20` | 4 | 1 | SoundVoice_Construct |
| `0x24` | 4 | 1 | SoundVoice_Construct |
| `0x28` | 4 | 2 | SoundTrack_Destruct, SoundVoice_Construct |
| `0x2c` | 4 | 2 | SoundTrack_Destruct, SoundVoice_Construct |
| `0x30` | 4 | 2 | SoundTrack_Destruct, SoundVoice_Construct |
| `0x34` | 4 | 2 | SoundTrack_Destruct, SoundVoice_Construct |
| `0x38` | 4 | 1 | SoundVoice_Construct |
| `0x3c` | 1 | 1 | SoundVoice_Construct |
| `0x40` | 4 | 1 | SoundVoice_Construct |
| `0x44` | 4 | 2 | SoundTrack_Destruct, SoundVoice_Construct |
| `0x48` | 4 | 1 | SoundVoice_Construct |
| `0x4c` | 4 | 1 | SoundVoice_Construct |
| `0x51` | 1 | 1 | SoundVoice_Construct |
| `0x53` | 1 | 1 | SoundVoice_Construct |
| `0x55` | 1 | 1 | SoundVoice_Construct |
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

## Vtable references

- `SoundTrack_Destruct`
- `SoundVoice_Construct`
