# DirectSoundBuffer

- Vtable: `0x55c860`
- Constructor: `Sound_CreatePrimaryBuffer`
- Destructor: `DirectSoundBuffer_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: constructor symbol is Sound_CreatePrimaryBuffer (base/sibling name)

## Virtual methods

| # | Method |
|---:|---|
| 0 | `DirectSoundBuffer_Delete` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 2 | DirectSoundBuffer_Delete, DirectSoundBuffer_Destructor |
| `0x10` | 4 | 1 | SoundSystem_Destroy |
| `0x18` | 4 | 1 | SoundSystem_Destroy |
| `0x50` | 4 | 1 | SoundSystem_Destroy |
| `0x58` | 4 | 1 | SoundSystem_Destroy |
| `0x60` | 4 | 1 | SoundSystem_Destroy |
| `0x68` | 4 | 1 | SoundSystem_Destroy |
| `0x70` | 4 | 1 | SoundSystem_Destroy |
| `0x78` | 4 | 1 | SoundSystem_Destroy |
| `0x98` | 4 | 1 | SoundSystem_Destroy |

## Vtable references

- `DirectSoundBuffer_Delete`
- `DirectSoundBuffer_Destructor`
- `SoundSystem_Destroy`
- `Sound_CreatePrimaryBuffer`
