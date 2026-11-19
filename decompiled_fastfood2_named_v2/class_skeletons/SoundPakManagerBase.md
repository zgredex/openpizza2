# SoundPakManagerBase

- Vtable: `0x55c864`
- Constructor: `SoundBuffer_ConstructBase`
- Destructor: `SoundPakManager_Delete`
- Base guess: ``
- Slots: 4
- Naming notes: constructor symbol is SoundBuffer_ConstructBase (base/sibling name); slot0 is RefCount_AddRef; destructor is slot 3; slots 0-2 implement COM AddRef/Release/QueryInterface

## Virtual methods

| # | Method |
|---:|---|
| 0 | `RefCount_AddRef` * |
| 1 | `RefCount_Release` |
| 2 | `COM_QueryInterfaceGuid` |
| 3 | `SoundPakManager_Delete` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 1 | SoundBuffer_ConstructBase |
| `0x149` | 1 | 1 | SoundBuffer_ConstructBase |
| `0x238` | 4 | 2 | SoundBuffer_ConstructBase, SoundPakManager_Destruct |
| `0x628` | 4 | 2 | SoundBuffer_ConstructBase, SoundPakManager_Destruct |

## Vtable references

- `SoundBuffer_ConstructBase`
- `SoundPakManager_Destruct`
