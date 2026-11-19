# Character object layout

Executable SHA-256:
`18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd`

Machine-readable packet: `character_layout.json`
Recovered C: `reconstructed/character/character_state.h` / `.c`
Tests: `reconstructed/character/test_character_state.c`
Verifier: `tools/verify_character_layout.py`

## Object identity

| Item | Value |
|---|---|
| Allocation | `operator_new(0x828)` at `0x4822A2` |
| Constructor | `Character_Construct 0x4D3730` |
| Stream constructor | `Character_StreamConstruct 0x4D36F0` |
| Destructor | `Character_Destroy 0x4D3F80` |
| Delete | `Character_Delete 0x4D3710` |
| Save | `Character_Save 0x4D3BA0` |
| Load | `Character_Load 0x4D3A50` |
| Vtable | `0x55C4FC` |
| Vtable slot 0 | `Character_Delete 0x4D3710` |
| Size | `0x828` |

## Fields

| Offset | Width | Name | Evidence |
|---|---:|---|---|
| `0x000` | 4 | `vtable` | constructor store `0x4D3752` |
| `0x004` | 4 | `skill` | `Person_SetSkill 0x4D4130`; constructor random `0x1E..0x46` |
| `0x008` | 4 | `speed` | `Person_SetSpeed 0x4D4140` |
| `0x00C` | 4 | `motivation` | `Person_SetMotivation 0x4D4120` |
| `0x010` | 4 | `health` | `Person_SetHealth 0x4D4150` |
| `0x014` | 4 | `skill_timer` | `Rating_DecayAndUpdateIndicators 0x4D4170` |
| `0x018` | 4 | `speed_timer` | same |
| `0x01C` | 4 | `motivation_timer` | same |
| `0x020` | 4 | `health_timer` | same |
| `0x024` | 4 | `gender` | `Game_InitScenario 0x4822E5`; `UI_ComposeOverlayWindowFromRecord` |
| `0x028` | 4 | `hair` | `0x4822EB` |
| `0x02C` | 4 | `eyes` | `0x4822F4` |
| `0x030` | 4 | `mouth` | `0x4822FD` |
| `0x034` | 4 | `head` | `0x482306` |
| `0x038` | 4 | `age` | constructor `Random_RangeFast(0x12,0x3C)`; rating functions |
| `0x03C` | 4 | `performance` | `Person_SetPerformance 0x4D4160`; constructor composite |
| `0x040` | 4 | `field_40` | initialized 0, saved; role unresolved |
| `0x044` | 2000 | `rating_data[500]` | constructor clears 500 dwords; `Character_ComputeRatingArray 0x4AF7A0`; save writes 2000 bytes |
| `0x814` | 4 | `registry_id` | `Game_AddObjectToRegistry`; `Game_GetRecordByField814 0x4D3910`; sentinel `-1` |
| `0x818` | 4 | `object_id` | constructor `param_1`; `Person_ReleaseFromBranch`; sentinel `-1` |
| `0x81C` | 4 | `player_slot` | `Game_GetPlayerBySlot` calls; set `-1` on release |
| `0x820` | 4 | `branch_id` | `Game_GetPlayerSubmapValue(..., +0x81C, +0x820)`; sentinel `-1` |
| `0x824` | 1 | `profession_type` | constructor `param_2`; salary switch `6/8/7/0xD` |
| `0x825` | 1 | `activity_state` | constructor writes `2`; Person/AI/UI switches |
| `0x826` | 2 | `padding_826` | untouched by constructor/save/load |

### Rating data blocks

The 500-dword array is five 100-dword blocks. `Character_Construct` stores the
first dword of each block:

| Offset | Cached value |
|---|---|
| `0x044` | `Rating_GetComposite` |
| `0x1D4` | `Rating_ClampAdjusted` |
| `0x364` | `Rating_AdjustA` |
| `0x4F4` | motivation |
| `0x684` | `Rating_AdjustB` |

`Character_ComputeRatingArray` fills the first 144 dwords of the array.

## Constructor initialization

```text
+0x00 = 0x55C4FC
+0x814/+0x818/+0x81C/+0x820 = -1
+0x04/+0x08/+0x0C/+0x10 = Random_RangeFast(0x1E, 0x46)
+0x38 = Random_RangeFast(0x12, 0x3C)
+0x824 = profession type
+0x40 = 0
+0x825 = 2
+0x14/+0x18/+0x1C/+0x20 = 0
+0x44..+0x813 = 0
+0x3C = Rating_GetCompositeTruncated
```

## Exact save/load order

```text
+0x04, +0x08, +0x0C, +0x10
+0x24, +0x28, +0x2C, +0x30, +0x34
+0x38, +0x3C
+0x44 (2000 bytes)
+0x814, +0x818, +0x81C, +0x820
+0x824 (1 byte)
+0x40
+0x825 (1 byte)
+0x14, +0x18, +0x1C, +0x20
```

Both routines have the same sequence and widths.

## Static checks

`character_state.h` contains 29 `_Static_assert` checks for:

- total size `0x828`
- every field offset
- the five rating-block offsets

## Remaining gaps

- `+0x40` is saved and zeroed but has no proven semantic role.
- `+0x826..+0x827` is untouched by constructor, save or load.
- Only the first dword of each rating block is directly named; the full
  500-dword matrix semantics are not mapped.
- The vtable has one recovered slot (`Character_Delete`).
