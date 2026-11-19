# Rating product trace — food stats, base skill, product score, recent ring

This closes the recipe rating pipeline after `Recipe_RecomputeAllStats`
(`0x512620`):

```text
Stats_ComputeWeightedAverages 0x513100
Rating_StoreClampedScores     0x513270
Game_ComputeMarketFactors     0x5133C0
Game_ComputeFoodStats         0x513590
Game_ComputeCompanyRatings    0x5136C0
```

## Food pairs (`Game_ComputeFoodStats 0x513590`)

The global table `DAT_00573264` is 83 triples `[ingredientA, ingredientB, weight]`
(extracted into `sim_constants.json -> food_pairs`).

```text
for each triple:
    if recipe.usage[A] > 0 and recipe.usage[B] > 0:
        local[market[A].category] += weight
        local[market[B].category] += weight

A = local[1]; B = local[2] + local[4]
C = local[3] + local[6]; D = local[5]

stats[0] = C + 3B      stats[1] = C + 2B
stats[2] = D + 2A + B  stats[3] = 4C
stats[4] = 2(D + 2A)   stats[5] = 2(A + 2D)
stats[6] = 3C          stats[7] = D + A + B + C
if stat > 20: stat = 40 - stat
```

## Base skill (`Game_ComputeCompanyRatings 0x5136C0`)

```text
base[i] = (((food[0x284+i] + food[0x264+i]) / 2) + food[0x2A4+i])
          * (bonus + 100) / 100
clamp 0..100
```

`+0x2A4` is the food-stat array above. `+0x264` and `+0x284` are now
implemented by `rating_store_clamped_scores()` and
`game_compute_market_factors()` (see `RATING_LAYOUT_TRACE.md`); their upstream
layout/colour/city inputs remain proxies.

## Product score (`Game_ComputeCompanyProductScore 0x513B00`)

```text
skill = recipe+0x2C4[category] + recipe+0x2E4[category]
for every ingredient i with usage > 0:
    local4 = Market_GetPriceDelta(i)          # city level -> -40/0/40
    local8 = 10 * (# recent-ring entries == i for the customer category)
    if i != 0: availability += local8; count += 1
    price_delta += local4
base = -40 if count < 1 else availability/count + price_delta
score = clamp(base + skill)
```

`Market_GetPriceDelta` (`0x4DB170`) maps market category 1..6 to
`City+0xC8+level*4`: `-1 -> -40`, `0 -> 0`, non-zero -> `40`.

## Recent ring (`Player_TrackRecentEntry 0x4DA810`)

`City+0xFE4 + category*0x18`, six entries:

```text
if ingredient found at index i:
    if i == 0: return
    ring[i] = ring[i-1]; ring[i-1] = ingredient
else:
    ring[5] = ingredient
```

Type-1 advertising calls this once per successful roll with
`plan.category - 1`; it does **not** spawn a customer directly. The ring feeds
`availability` in the product score.

## Simulator

- `Recipe.food_stats()`
- `Recipe.base_skill_ratings()`
- `Recipe.total_skill_ratings()`
- `game_compute_company_product_score()`
- `Simulator.city_recent`, `Simulator.track_recent_entry()`
- `update_ratings()` averages product scores across branch recipes
- type-1 ad path updates the recent ring instead of spawning a customer

Tests: `test_food_stats_pairs`, `test_track_recent_entry`,
`test_product_score_recent_ring`.

## Remaining limitation

`+0x264` layout quality and `+0x284` market factors are still proxies
(recipe quality / 0). The food-stat, price-delta, recent-ring and product-score
arithmetic is decoded.
