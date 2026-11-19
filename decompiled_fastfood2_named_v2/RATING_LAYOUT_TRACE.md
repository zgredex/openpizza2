# Rating layout trace — `Rating_StoreClampedScores` and `Game_ComputeMarketFactors`

## `Rating_StoreClampedScores` (`0x513270`)

Inputs are recipe fields `a=+0x244`, `b=+0x248`, `c=+0x24C`, `d=+0x258`.
The x87 sequence reduces to eight clamped scores written to `+0x264..+0x280`:

```text
s0 = trunc(0.33a + 0.70b)
s1 = trunc(0.70a + 0.33b)
s2 = trunc(0.50b + 50c)
s3 = trunc(0.60a + 0.20b + 0.20d)
s4 = trunc(0.40b + 60c)
s5 = trunc(0.40b + 30c + 0.30d)
s6 = trunc(0.33b + 30c + 0.40d)
s7 = trunc(a + 0.40b + d)
clamp each 0..100
```

Constants: `0x55C6F0=0.33`, `0x55C6E8=0.7`, `0x55C6E0=50`,
`0x55C300=0.5`, `0x55C6D8=0.2`, `0x55C678=0.6`, `0x55C6D0=0.4`,
`0x55C6C8=60`, `0x55C6C0=30`, `0x55C6B8=0.3`.

Calibration:

```text
a=10,b=20,c=0.1,d=30 -> [17,13,15,16,14,20,21,48]
a=100,b=15,c=0,d=50 -> [43,74,7,73,6,21,24,100]
```

Input provenance:

- `a` — `Screen_ScoreColorHistogram 0x512E50`: starts 100, −10 per outlier
  histogram bin, −20 per empty bin.
- `b` — `Recipe_RecomputeLayoutQuality 0x512F10`: placed ingredients ×5
  (cap 20), then `(placed - sum(amount/2)) * 10`, clamp 0..100.
- `c` — `Stats_ComputeWeightedAverages 0x513100`: usage-weighted average of the
  per-tier market byte at `market_record+0xC8`.
- `d` — `Recipe_RecomputeLayoutQuality` colour average ×100, clamp 0..100.

## `Game_ComputeMarketFactors` (`0x5133C0`)

Writes `+0x284..+0x2A0` (8 ints), starting from zero:

```text
m[7] += 10*c250
m[3] += -10*c250
m[2] += 5*c250 + 5*c254
m[4] += 5*c250 + 10*c254
m[5] += 10*c254 + 10*c250
m[6] += 5*c254 - 10*c250

if mission(+0x240): m[6]+=30; m[4]+=30; m[5]+=5; m[7]+=30
if city_score(+0x1D8) > 200: m[0]+=10; m[1]+=40; m[5]-=20
if city_score > 300: m[3]+=40; m[4]-=20; m[6]-=20; m[7]+=40

m[i] += sum_j branch_categories[j] * city_matrix[j*8+i]
if count(+0x5C) < 20: m[i] += (20-count)*-5
```

Calibration:

```text
c250=1,c254=2, count20 -> [0,0,15,-10,25,30,0,10]
same, count18           -> [-10,-10,5,-20,15,20,-10,0]
mission flag            -> m[4] 30
```

## Simulator wiring

```text
Recipe.layout_quality_scores()  -> +0x264 via rating_store_clamped_scores
Recipe.market_factor_scores()   -> +0x284 via game_compute_market_factors
Recipe.base_skill_ratings(market_scores)
    base[i] = (layout[i] + market[i])//2 + food[i]
```

`update_ratings` calls `base_skill_ratings(recipe.market_factor_scores())`.
Tests: `test_rating_store_clamped_scores`, `test_game_compute_market_factors`,
`test_layout_quality_scores`, `test_base_skill_market_factor_input`.

## Real upstream inputs

Extracted into `sim_constants.json -> market_descriptors` from the 86
`Game_SetBuildingDesc` calls in `Ingredient_LoadMarketTable` (`0x4E4930`):

- `category` (+0xA8)
- `amounts[4]` (+0xAC..+0xB8)
- `price_adjust` (+0xCC, signed)
- `quality_adjust` (+0xCD, signed)
- `taste[4]` (+0xC8..+0xCB, signed)

`Stats_ComputeWeightedAverages` is implemented in `Recipe.weighted_averages()`:

```text
total = sum(amounts[tier])
category_percent[1..6] = category_amount * 100 / total
taste = round_half_away(sum(amount * taste[tier]) / total)
price_adjust / quality_adjust = same weighted average
```

`PlayerStats_Reset` (`0x50FEC0`) gives the category percentages at `+0x1BC`
and the total at `+0x1D8`; the recipe topping count is `+0x5C`.
`AI_CheckPriceCompetitiveness` (`0x512CA0`) sets `+0x240`;
the simulator implements the competitor overlap/price-band test in
`Simulator.recipe_price_competitive()`.

The city 6x8 food-taste matrix at city `+0x280` is parsed from the INI keys
`GEMUESE/FLEISCH/FISCH/OBST/KAESE/GEWUERZ` into `CityProfile.food_taste`.

`Recipe.layout_quality_scores()`:
- `a` = `screen_score_color_histogram(Recipe.color_histogram())`
  - `Recipe.compose_surface()` renders every topping sprite onto an
    800x600 palette-index surface (`Screen_AccumulateColorHistogram` stride 800)
  - the scan uses the decoded circle geometry: radius `min(w,h)`,
    `half = trunc(radius*sqrt(1-(dy/radius)^2))`, row spans
    `cx-half .. cx+half-1`, mirrored above/below centre
  - counts bytes `1..24` (skips 0 and 0xFF)
  - eight 24-bin scores as in `Screen_ScoreColorHistogram`
- `b` = `min(20, 5*placed) + (placed - local_c)*10`
- `c` = weighted taste average
- `d` = `Recipe.layout_color_delta(orientation_deltas)`:
  - `delta = topping_variant - placed_variant`, signed byte then wrap to -4..4
  - `acc += abs(delta) - 2`; `d = clamp(round(acc/count)*100, 0, 100)`
  - `Branch.approach_objects` supplies actual placed objects; `Recipe.orientation_deltas(branch)`
    pairs each topping with an object and computes the signed delta
  - `Simulator.generate_branch_layout()` now uses the shipped branch
    `.iso` fixtures (`Iso_Filiale_<style>_<size>.iso`, 15 maps). Floor/kitchen
    Layer2 tiles (`_M_L_`, `_M_K_`, `KUECHE`) become approach objects; the
    orientation comes from the tile word and branch identity. It fills
    `branch.approach_objects` and `branch.topping_orientations`
  - missing maps fall back to the decoded approach point `(266,274)` line

`Recipe.market_factor_scores()` uses the weighted price/quality averages,
total amount, topping count, category percentages, price-competitiveness flag,
and the city food-taste matrix.

Calibration:

```text
recipe toppings 0+1+2:
weighted_averages = total 367, categories [100,0,0,0,0,0],
                    taste -1, price 0, quality -1
market factor scores = [-75,-45,10,-135,20,-10,-165,-125]
layout quality scores = [64,84,0,69,0,0,0,100]
```

The generator is a `.iso`-backed layout fixture: all 15 shipped branch maps
provide the floor/kitchen tile positions used as approach objects. It is not
the full procedural `CityMap_GenerateLayout` furniture algorithm, but the
positions come from shipped interior maps rather than a synthetic line.
