# Rating skill trace — expected price and price positioning

## `Rating_GetFloat` (`0x489070`)

Returns the city's **expected price** for one customer group:

```text
inc   = City+0x98 = EINKOMMEN * 0.02
phase = (11 - DAT_0057BB24) * 0.5      # difficulty global
g0 = inc*3 + phase + 4
g1 = inc*4 + phase + 5
g2 = inc*4 + phase + 8
g3 = inc*3 + phase + 8
g4 = inc*7 + phase + 10
g5/g8 = inc*10 + phase + 8
g6 = inc*3 + phase + 7
g7 = phase + 12
```

Berlin (`EINKOMMEN=65 -> 1.3`, difficulty 5 -> phase 3):

```text
[10.9, 13.2, 16.2, 14.9, 22.1, 24.0, 13.9, 15.0]
```

## `Game_ComputeSkillRatings` (`0x513760`)

Writes the price-positioning component to `recipe+0x2E4`:

```text
local[g] = expected[g] + bonus
bonus = 2*inc at branch level 1, 4*inc at level 2, else 0

if price > local[g]:
    skill = trunc((price/local - 1) * -50)       # 0x55C6F8 = -50.0
elif price < local[g]:
    if price == 0: skill = 100
    else:          skill = trunc((local/price - 1) * 50)   # 0x55C6E0 = 50.0
    caps: [40,10,20,30,5,0,40,20]
else:
    skill = 0
```

Calibration (Berlin, level 0, price 12):

```text
[-5, 4, 17, 12, 5, 0, 7, 12]
price 0  -> [40,10,20,30,5,0,40,20]
price 30 -> g0 -87
```

## `Game_GetSkillRating` (`0x5139E0`)

```text
category 0..7: recipe+0x2C4[category] + recipe+0x2E4[category]
category -1:  average of the 8 sums
```

`recipe+0x2C4` is the base food-stat skill from `Game_ComputeCompanyRatings`
(`0x5136C0`), which mixes recipe food-stat arrays at `+0x264`, `+0x284`,
`+0x2A4` and a mission bonus. Those food-stat arrays are not modeled headlessly;
the simulator uses `recipe.quality` as the base-skill proxy and adds the exact
price-positioning term.

## Simulator wiring

```text
Branch.city_income_factor = City+0x98
Branch.city_rating_phase  = (11 - difficulty)*0.5
update_ratings:
    price_skills = game_compute_skill_ratings(...)
    skills[g] = clamp(recipe.quality + price_skills[g])
```

Tests:

- `test_rating_group_expectation`
- `test_game_compute_skill_ratings`

`Rating_GetFloat` is exposed as `rating_group_expectation`; the price term as
`game_compute_skill_ratings`.

## Remaining limitation

The food-stat term of `recipe+0x2C4` is now implemented in
`RATING_PRODUCT_TRACE.md`; layout quality and market factors remain proxies.
