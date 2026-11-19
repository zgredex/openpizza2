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

`0x55C688` is the **GamePlan** vtable, installed by `0x50F630`,
`0x50F690` and `0x50FB30`. It is not a second Player slot, so the Player
vtable has exactly one recovered slot.

## Fields

| Offset | Width | Name | Evidence |
|---|---:|---|---|
| `0x00` | 4 | `vtable` | constructor installs `0x55C684` |
| `0x04` | 4 | `character` | `Character_Save(*(this+4))`; `Player_Load` allocates `0x828` |
| `0x08` | 4 | `slot` | constructor `-1`; `Game_InitScenario` sets player slot |
| `0x0C` | 32 | `player_name` | 32-byte name buffer; saved as `0x20` bytes |
| `0x2C` | 4 | `reserved_2c` | cached-profile transplant and save/load only |
| `0x30` | 4 | `reserved_30` | cached-profile transplant and save/load only |
| `0x34` | 4 | `reserved_34` | constructor/save/load only |
| `0x38` | 4 | `attacks_fended_off` | sixth achievement metric; four attack-outcome writers |
| `0x3C` | 24 | `character_values[6]` | Buyer..Guard base values |
| `0x54` | 24 | `achievement_bonus_values[6]` | incremented with achievement tiers; CompanyOverview Extra column |
| `0x6C` | 24 | `achievement_tiers[6]` | six 0..4 achievement tiers |
| `0x84` | 4 | `reserved_84` | written as 1 by both initialization paths; no reader |
| `0x88` | 4 | `award_briefing_enabled` | gates medal briefings; cleared for AI slots |
| `0x8C` | 28 | `events` | `List_Construct`; event count at `+0xA0` |
| `0xA8` | 4 | `ai_state` | optional `PlayerAIState` address |
| `0xAC` | 4 | `mission_state` | optional `PlayerMissionState` address |

## Achievement tiers

`Player_MissionState_Tick` (`0x50EFE0`) operates on the `0xB0` Player object:
`Game_EndOfHour` (`0x486590`) iterates `g_Game+0x224` and passes each Player.
Its six tier counters are compared against these tables:

| Tier field | Metric | Thresholds | Table | Messages |
|---|---|---|---|---|
| `+0x6C` | employees in restaurants | 25/50/100/150 | `0x573054` | `0x2E7..0x2EA` |
| `+0x70` | attacks carried out in one city | 10/50/100/150 | `0x573064` | `0x2EB..0x2EE` |
| `+0x74` | medals / awards | 1/5/10/15 | `0x573074` | `0x2EF..0x2F2` |
| `+0x78` | restaurants opened | 2/4/6/8 | `0x573084` | `0x2F3..0x2F6` |
| `+0x7C` | quarterly sales | 100k/200k/300k/400k | `0x573094` | `0x2F7..0x2FA` |
| `+0x80` | attacks fended off in one city | 1/10/50/100 | `0x5730A4` | `0x2FB..0x2FE` |

The threshold tables were read directly from the image; the message IDs are
the `language.ldf` strings loaded into the five arrays by `UI_LoadStringTable`
(`0x51E650`). Each tier advance also increments the matching
`achievement_bonus_values[0..5]` entry at `+0x54..+0x68`.

`attacks_fended_off` (`+0x38`) is incremented by:

- `Person_ApplyAttackOutcome 0x50C0F0`
- `Person_ResolveGroupFight 0x50C2E0`
- `Object_ActionRemove 0x50A580`
- `Character_OnArriveAtDestination 0x50D930`

## Formerly unresolved fields

| Field | Final classification |
|---|---|
| `+0x2C`, `+0x30` | Read by `Game_CacheCurrentCityGlobals` (`0x48E0B0`), written back by `PlayerCompany_InitDefaults` (`0x50F590`), plus constructor/load/save. No gameplay consumer was found. |
| `+0x34` | Constructor/load/save only. |
| `+0x84` | Written as `1` by `Player_Construct` and `Player_ResetAiState` (`0x50EFC0`); load/save. No reader. |
| `+0x88` | `Player_Construct` writes 1; `Player_ResetAiState` writes 0 for AI slots; `City_GenerateRatingNews` (`0x4D9780`, reads at `0x4D988A`/`0x4D99C0`) uses it to gate medal briefings. |

## Event list

| Offset | Field |
|---|---|
| `0x8C` | vtable |
| `0x90` | entries |
| `0x94` | keys |
| `0x98` | count |
| `0x9C` | capacity |
| `0xA0` | total added / serialized event count |
| `0xA4` | next key |

## Player event node

`Player_Event` is a separate `0xC`-byte award node:

| Offset | Field | Evidence |
|---|---|---|
| `0x00` | vtable `0x55C660` | constructor `0x5019D0` |
| `0x04` | `event_type` | every creation site writes a known value |
| `0x08` | `date_word` | copied from `g_Game+0x94+4` |
| `0x0A` | padding | untouched |

Complete observed type set:

| Value | Name | Creation site |
|---|---|---|
| 0 | `PLAYER_EVENT_CITY_PRIZE` | `City_SettleAdvertisingCampaign 0x4DCE70` |
| 1 | `PLAYER_EVENT_BEST_RESTAURANT` | `City_GenerateRatingNews 0x4D9780` |
| 2 | `PLAYER_EVENT_BEST_BUILDING` | `City_GenerateRatingNews 0x4D9780` |

Every `List_Add` into `Player+0x8C` was audited; `Player_Load` is the only
other site and restores serialized values.

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

`player_state.h` contains 25 `_Static_assert` checks covering the `0xB0`
object, the `0x1C` event list, the `0xC` event node, the event-type values and
every recovered field offset.

## Remaining gaps

- `+0x2C/+0x30/+0x34/+0x84` are provably inert in this build: no gameplay
  reader exists. They are retained as reserved fields rather than assigned
  speculative meanings.
