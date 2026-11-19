# Player object layout

Executable SHA-256:
`18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd`

Machine-readable packet: `player_layout.json`
Recovered C: `reconstructed/player/player_state.h` / `.c`
Tests: `reconstructed/player/test_player_state.c`
Verifier: `tools/verify_player_layout.py`

## Object identity

| Item | Value |
|---|---|
| Allocation | `operator_new(0xB0)` at `0x4820C7` |
| Constructor | `Player_Construct 0x50E8E0` |
| Constructor call | `0x4820E8` |
| Save | `Player_Save 0x50EA90` |
| Load | `Player_Load 0x50ECA0` |
| Destructor | `Player_Delete 0x50E9C0` |
| Vtable | `0x55C684` |
| Vtable slot 0 | `Player_Delete` |
| Size | `0xB0` |

## Fields

| Offset | Width | Name | Evidence |
|---|---:|---|---|
| `0x00` | 4 | `vtable` | constructor installs `0x55C684` |
| `0x04` | 4 | `character` | `Character_Save(*(this+4))`; `Player_Load` allocates `0x828` |
| `0x08` | 4 | `slot` | constructor `-1`; `Game_InitScenario` sets player slot |
| `0x0C` | 32 | `player_name` | 32-byte name buffer; saved as `0x20` bytes |
| `0x2C` | 4 | `field_2c` | zeroed, saved; role unresolved |
| `0x30` | 4 | `field_30` | zeroed, saved; role unresolved |
| `0x34` | 4 | `field_34` | zeroed, saved; role unresolved |
| `0x38` | 4 | `field_38` | zeroed, saved; role unresolved |
| `0x3C` | 24 | `character_values[6]` | Buyer..Guard base values |
| `0x54` | 24 | `extra_character_values[6]` | CompanyOverview Extra column |
| `0x6C` | 24 | `field_6c[6]` | zeroed, saved; role unresolved |
| `0x84` | 4 | `field_84` | constructor writes 1; saved |
| `0x88` | 4 | `field_88` | constructor writes 1; saved |
| `0x8C` | 28 | `events` | `List_Construct`; event count at `+0xA0` |
| `0xA8` | 4 | `ai_state` | optional `PlayerAIState` address |
| `0xAC` | 4 | `mission_state` | optional `PlayerMissionState` address |

### Event list

| Offset | Field |
|---|---|
| `0x8C` | vtable |
| `0x90` | entries |
| `0x94` | keys |
| `0x98` | count |
| `0x9C` | capacity |
| `0xA0` | total added / serialized event count |
| `0xA4` | next key |

## Constructor initialization

```text
vtable = 0x55C684
List_Construct(+0x8C)
+0x84 = 1
+0x88 = 1
+0x08 = -1
+0x3C..+0x68 = 0
+0x6C..+0x83 = 0
+0x2C/+0x30/+0x34/+0x38 = 0
+0xA8/+0xAC = 0
```

## Exact save/load order

```text
+0x84, +0x88, +0x08
+0x0C (32 bytes)
+0x2C, +0x30
+0x3C..+0x68 (12 dwords individually)
+0x6C (24 bytes)
+0x34, +0x38
Character_Save(+0x04)
event count + each event
optional AI state
optional mission state
```

## Static checks

`player_state.h` contains 19 `_Static_assert` checks covering the `0xB0`
object, the `0x1C` event list and every recovered field offset.

## Remaining gaps

- `+0x2C/+0x30/+0x34/+0x38` are saved and zeroed but semantically unknown.
- `+0x6C..+0x83` is a six-dword zeroed/saved block with no recovered meaning.
- `+0x84/+0x88` are initialized to 1 and saved; flag semantics unresolved.
- Event record contents live in `Player_Event_*`, not in this layout.
- Vtable has one recovered slot.
