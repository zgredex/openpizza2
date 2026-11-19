# Free-play profile dependency packet

Executable SHA-256:
`18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd`

Raw scanner output: `freeplay_cash_multiplier.scan.json`
Machine-readable packet: `freeplay_cash_multiplier.json`
Fixture: `fixtures/freeplay_cash_multiplier.result.json`
Verifier: `tools/verify_freeplay_cash_multiplier.py`

## The record base is 0x57BC58, not 0x57BCD8

The six profiles start at `0x57BC58` with stride `0xC0`:

| Offset | Size | Field |
|---|---:|---|
| `0x00` | `0x40` | player name |
| `0x40` | `0x40` | enterprise name |
| `0x80` | 4 | cash multiplier |
| `0x84` | 4 | characteristic adjustment |
| `0x88` | 4 | Buyer |
| `0x8C` | 4 | Gangsters |
| `0x90` | 4 | Specialist |
| `0x94` | 4 | Politicians |
| `0x98` | 4 | Seller |
| `0x9C` | 4 | Guard |
| `0xA0` | 4 | gender |
| `0xA4` | 4 | hair |
| `0xA8` | 4 | eyes |
| `0xAC` | 4 | mouth |
| `0xB0` | 4 | head |
| `0xB4` | 4 | logo |
| `0xB8` | 4 | color |
| `0xBC` | 4 | active |

`0x57BCD8` is `record0 + 0x80` — the settings half.  That is why the previous
view showed `+0x40..+0xBF` as unknown: those addresses are `record1 + 0x00` to
`record1 + 0x7F`, i.e. the next profile's player and enterprise names.

## Names

The unnamed character-select confirmation procedure writes the character-select
values directly into record 0:

- `0x4C7B22..0x4C7B4C`: `0x57DD60` player name -> `0x57BC58`
- `0x4C7B6D..0x4C7B87`: `0x57DDBC` enterprise name -> `0x57BC98`

`FreePlaySetup_InitWindow` reads both names at `0x4CBD4F` / `0x4CBD60` and
copies the entire `0xC0`-byte record 0 for the preview at `0x4CBD81`.
`Game_GenerateRandomPlayers` fills AI names at `0x40523D` and `0x405257`.
`Game_InitScenario` copies record `+0x00` into Player `+0x0C` and formats the
company name from record `+0x40`.

## Settings fields

### `+0x80` — cash multiplier

- `Settings_InitDefaults` writes 100 through `[eax-0x30]` at `0x406B90`
  (`eax = 0x57B9AC`).
- `FreePlaySetup_InitWindow` copies it into record `+0x80` at `0x4CBEBD`.
- UI range is 70..990 (`0x4CC8DC/0x4CC92E`).
- `Game_InitScenario` applies `(multiplier * capital) / 100` at
  `0x48203D..0x482063`.

### `+0x84` — characteristic adjustment

- Free-play UI “Characteristics:” value, range -6..+6
  (`0x4CC973/0x4CC9C4`).
- `Game_InitScenario` loads it at `0x4821B4` and applies `abs(value)` random
  `±1` adjustments to Player `+0x3C..+0x50`, keeping each value in `-3..3`.
- Applied to AI players only; the human player uses `Player_AIState_Init`.

### `+0x88..+0x9C` — the six character values

| Offset | CharacterSelect label | Value control | Player offset |
|---|---|---|---:|
| `+0x88` | Buyer | `0x418` | `+0x3C` |
| `+0x8C` | Gangsters | `0x419` | `+0x40` |
| `+0x90` | Specialist | `0x41A` | `+0x44` |
| `+0x94` | Politicians | `0x41B` | `+0x48` |
| `+0x98` | Seller | `0x41C` | `+0x4C` |
| `+0x9C` | Guard | `0x41D` | `+0x50` |

The same procedure at `0x4C7B65` copies `0x57DD48..` into record `+0x88..+0x9C`.
`Game_InitScenario` `0x482144..0x482187` copies them into Player
`+0x3C..+0x50`.  `CompanyOverview_FillTotals` renders “Character values:” with
Base, Extra and Total columns at `0x2332..0x234D`.

### `+0xA0..+0xB0` — appearance

- `+0xA0` gender: `Random_RangeFast(0,1)` at `0x4051B5`; `IDMap_GetRandomName`
  at `0x40523D`; `UI_DrawOverlaySprites` `0x54B770` selects male lists when
  `param_2 == 0`.
- `+0xA4` hair, `+0xA8` eyes, `+0xAC` mouth, `+0xB0` head.
- `EmployeeAvatar_Construct` `0x54B460` loads:
  `HEAD_M +0x04`, `HEAD_F +0x20`, `AUGEN_M +0x3C`, `AUGEN_F +0x58`,
  `HAARE_M +0x74`, `HAARE_F +0x90`, `MUND_M +0xAC`, `MUND_F +0xC8`.
- Limits: `0x585588` head, `0x585580` eyes, `0x585584` mouth, `0x58557C`
  hair, each the minimum of the male/female list counts.

### `+0xB4` logo, `+0xB8` color

- `0x57B76C` and `0x57C25C` are shuffled eight-entry `0..7` permutations.
- Record `+0xB4` -> Company `+0x1E0` -> `LOGOS__%d.spr` (index + 1).
- Record `+0xB8` -> color table `0x563874` -> Company `+0x1DC` ->
  `SetTextColor`.

## Copy and UI rings

`FreePlaySetup_InitWindow` `0x4CBEB2..0x4CBED1` copies the three parallel
settings arrays:

- `0x4CBEBD`: record `+0x80`
- `0x4CBEC3`: record `+0x84`
- `0x4CBEC8`: record `+0xBC`

The reverse copy at `0x4CD4AE` writes record `+0x80` back to `0x57B97C`.
The unnamed UI procedure adjusts record `+0x80` and `+0x84` and clamps them to
70..990 and -6..+6 respectively.

## Lookup tables, x87, indirect calls

- **Lookup tables**: not applicable; fixed arrays, no index guard/fallback.
- **x87**: the starting-cash `/100` uses the `0x51EB851F` magic sequence and
  `fild` to double at `0x482063`; no control-word change.
- **Indirect calls**: none in the selected ranges.  Three vtable-style calls
  in the unnamed UI procedure (`0x4CD30B`, `0x4CD376`, `0x4CD38B`) remain
  unresolved.

## Fixture

`tools/emulate_freeplay_profiles.py` executes three original byte ranges:

- `init`: `0x406B7F..0x406BA7`
- `copy`: `0x4CBEB2..0x4CBED8`
- `cash`: `0x48203D..0x482063`
- `appearance`: `0x4822DF..0x48230F`
- `logo-color`: `0x48200C..0x482032`

Result: 11/11 cases matched.

```sh
python3 tools/emulate_freeplay_profiles.py \
  --json-out decompiled_fastfood2_named_v2/typed_packets/fixtures/freeplay_cash_multiplier.result.json
```

## Open questions

- The UI command procedure entry is absent from the retained decompile index.
- No save/load pair was found for `0x57BC58`.
- The three vtable-style calls in the UI procedure are unresolved.
