# SoundSample

- Vtable: `0x55c850`
- Constructor: `SoundSample_Construct`
- Destructor: `SoundSample_Delete`
- Base guess: ``
- Slots: 4
- Naming notes: slot0 is RefCount_AddRef; destructor is slot 3; slots 0-2 implement COM AddRef/Release/QueryInterface

## Virtual methods

| # | Method |
|---:|---|
| 0 | `RefCount_AddRef` * |
| 1 | `RefCount_Release` |
| 2 | `COM_QueryInterfaceGuid` |
| 3 | `SoundSample_Delete` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 1 | SoundSample_Construct |
| `0x8` | 4 | 2 | SoundSample_Construct, SoundSample_Destruct |
| `0xc` | 4 | 2 | SoundSample_Construct, SoundSample_Destruct |
| `0x10` | 4 | 2 | SoundSample_Construct, SoundSample_Destruct |
| `0x28` | 4 | 1 | SoundSample_Construct |
| `0x2c` | 4 | 1 | SoundSample_Construct |
| `0x30` | 4 | 1 | SoundSample_Construct |
| `0x34` | 1 | 1 | SoundSample_Construct |
| `0x38` | 4 | 1 | SoundSample_Construct |
| `0x3c` | 4 | 2 | SoundSample_Construct, SoundSample_Destruct |
| `0x48` | 1 | 1 | SoundSample_Construct |

## Vtable references

- `SoundSample_Construct`
- `SoundSample_Destruct`
- `Sound_LoadSample2D`
- `Sound_LoadSample3D`
- `Sound_LoadSample3DEx`
