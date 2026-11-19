# Rating factor trace — `Game_GetPlayerCity` and Player+0x44/+0x5C

## Identity correction

`Game_GetPlayerCity` (`0x4DDCC0`) is misnamed. Assembly:

```asm
4ddcc0  mov eax,[esp+4]          ; player record
4ddcc4  mov eax,[eax+0x4c]       ; slot/index
4ddcc8  mov ecx,[0x57c670]       ; Game
4ddccc  mov eax,[ecx+eax*4+0x224]
4ddcd0  ret
```

`Game+0x224` is the **Player array**, not a City array:

- `Game_InitScenario` (`0x481D90`) creates `operator_new(0xB0)` +
  `Player_Construct` (`0x50E8E0`) records and stores them at
  `Game + slot*4 + 0x224`.
- `Player_Load` (`0x50ECA0`) / `Player_Save` (`0x50EA90`) serialize
  `+0x3C..+0x60`, including `+0x44` and `+0x5C`.

Therefore the rating multiplier

```text
(100 - 3*(Player+0x5C + Player+0x44)) * value / 100
```

is a **player/company record factor**, not a City field. The earlier
`City+0x5C` / `City+0x44` wording in `AD_SETTLEMENT_TRACE.md` describes the
same player fields reached through the misnamed getter.

## Where it is applied

| Function | Address | Use |
|---|---:|---|
| `Stats_GetAverage8` | `0x4787F0` | scales each `+0x17BC[group]` average |
| `Branch_GetMenuRating` | `0x478320` | scales each `+0x177C[group]` menu rating |
| `Branch_ComputeBuildingRating` | `0x478BE0` | scales the final building rating |
| `Branch_GetPriceComparisonRating` | `0x478420` | scales the type-2 ad / price component |

Each one clamps the result to `0..100`.

## Values

- `Player_Construct` initializes both fields to `0`.
- `Game_InitScenario` sets `+0x3C..+0x50` from scenario data and randomizes AI
  traits; `+0x44` is one of those scenario fields.
- `+0x5C` is serialized player state and is zero for a fresh record unless a
  scenario/save sets it.

With both fields zero the factor is `100` (neutral). Without a real save the
per-company values are scenario/runtime inputs, so the simulator exposes them
as `Company.trait_a`, `Company.trait_b`, and `Company.rating_factor`:

```text
rating_factor = max(0, 100 - 3*(trait_a + trait_b))
```

`Simulator.add_branch` copies the company factor to `Branch.rating_factor`;
`Branch.update_ratings` applies it to `avg8`, `menu_rating`, `price_rating`,
and `building_rating`.

## Calibration

```text
traits 0/0   -> factor 100 (neutral)
traits 10/10 -> factor 40
branch ratings <= 40 after update_ratings
```

Test: `test_rating_factor_from_player_fields`.

## Remaining limitation

The exact `trait_a`/`trait_b` values require a game-produced save or scenario
runtime data. The static code proves the factor location and arithmetic, not
the per-company values.
