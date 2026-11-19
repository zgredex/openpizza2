# SoundMixerThread

- Vtable: `0x55c8f0`
- Constructor: `SoundVoiceThread_Construct`
- Destructor: `SoundMixerThread_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: constructor symbol is SoundVoiceThread_Construct (base/sibling name)

## Virtual methods

| # | Method |
|---:|---|
| 0 | `SoundMixerThread_Delete` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 2 | SoundMixerThread_Destroy, SoundVoiceThread_Construct |
| `0x8` | 4 | 1 | SoundVoiceThread_Construct |
| `0xc` | 4 | 2 | SoundMixerThread_Destroy, SoundVoiceThread_Construct |
| `0xd` | 1 | 1 | SoundMixerThread_Destroy |
| `0x10` | 4 | 2 | SoundMixerThread_Destroy, SoundVoiceThread_Construct |
| `0x2c` | 4 | 2 | SoundMixerThread_Destroy, SoundVoiceThread_Construct |
| `0x30` | 4 | 2 | SoundMixerThread_Destroy, SoundVoiceThread_Construct |
| `0x34` | 1 | 1 | SoundVoiceThread_Construct |

## Vtable references

- `SoundMixerThread_Destroy`
- `SoundVoiceThread_Construct`
