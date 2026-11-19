# Player_Event

- Vtable: `0x55c660`
- Constructor: `Player_Event_StreamConstruct`
- Destructor: `AwardNode_Delete`
- Base guess: ``
- Slots: 1
- Naming notes: Player_Event ctor/save/load; slot0 symbol retains legacy AwardNode_Delete name

## Virtual methods

| # | Method |
|---:|---|
| 0 | `AwardNode_Delete` |

`*` = indirect-only function entry not promoted by Ghidra.


## Observed fields

| Offset | Size | Hits | Observed in |
|---|---:|---:|---|
| `0x4` | 4 | 2 | Player_Event_Load, Player_Event_Save |
| `0x8` | 2 | 3 | Player_Event_Load, Player_Event_Save, Player_Event_StreamConstruct |

## Vtable references

- `AwardNode_Destructor`
- `Player_Event_StreamConstruct`
