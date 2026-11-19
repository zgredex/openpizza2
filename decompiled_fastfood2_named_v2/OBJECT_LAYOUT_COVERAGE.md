# Object-layout coverage

## What is recovered

- Class skeletons with vtables: 77
- Observed field offsets in class skeletons: 1573
- Field offsets corroborated by at least two functions: 572
- Skeleton classes without field records: 10
- Typed offset structs in game_structs.h: 28
- Fields in game_structs.h: 1083 (340 serialized, 743 observed-only)
- Save functions: 38
- Serialized fields: 368
- Exact save/load pairs: 31
- Allocation sites: 508 (63 distinct sizes)

## Static layout checks

| File | Asserts |
|---|---:|
| `reconstructed/character/character_state.h` | 29 |
| `reconstructed/construction/construction_state.c` | 9 |
| `reconstructed/freeplay/freeplay_profiles.h` | 26 |
| `reconstructed/ingredient/ingredient.c` | 12 |
| `reconstructed/mission/mission_goals.c` | 1 |
| `reconstructed/mission/mission_state.c` | 14 |
| `reconstructed/piz/piz_container.c` | 6 |
| `reconstructed/settings/settings.c` | 24 |
| **Total** | **121** |

## Remaining gaps

- `game_structs.h` is still a structural skeleton: every field is `field_0xNN` or padding, and 743 of 1083 are observed-only.
- The large gameplay objects (Game 194704 bytes, City, Company, Branch, Player, Character 0x828, Window, Dialog) do not yet have C structs with complete static asserts.
- 1001 class-skeleton field offsets have fewer than two observing functions; vtable slot semantics are not fully named.
- 63 distinct allocation sizes exist; only a small subset is tied to a reconstructed struct and constructor.
- The save schema pairs 31 owners exactly, but 7 other save owners have a different or missing load path.
