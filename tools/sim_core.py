#!/usr/bin/env python3
"""Headless Pizza Connection 2 economy simulator.

Exact/strongly-grounded pieces (from the named decompilation):
  - menu/price city adjustment        Branch_GetMenuRating / GetPriceComparisonRating
  - customer-group rating             Branch_GetCustomerGroupRating
  - market bonus factor               Game_GetMarketBonusFactor
  - product freshness                 Product_ComputeFreshness
  - city service level                City_ComputeServiceLevel
  - order revenue / ingredient cost   Branch_ProcessCustomerOrder
  - monthly rent / hourly salary      Branch_CloseMonth / Company_ProcessHourlyTick
  - negative-cash interest            0.4% per hour
  - balance tables                    0x5677F8..0x5678F8, 0x5675A0/AC

Reconstructed layer (clearly marked):
  - hourly customer traffic and branch choice
  - menu/building rating drivers
  - stock consumption and market share smoothing

The model is deterministic under a seed and is intended as the core for a modern
engine/save-aware simulator, not a bit-exact reimplementation of every AI tick.

Run:
  python3 tools/sim_core.py demo --days 360
  python3 tools/sim_core.py demo --days 90 --json
"""

from __future__ import annotations

import argparse
import json
import math
import os
import random
import struct
from dataclasses import dataclass, field

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CONSTANTS = os.path.join(ROOT, "decompiled_fastfood2_named_v2", "sim_constants.json")
MARKET_TABLE = os.path.join(ROOT, "decompiled_fastfood2_named_v2",
                            "market_table.json")

GROUP_NAMES = ["kids", "teens", "students", "prolls", "clerks",
               "rich", "grufties", "tourists"]
# Berlin daten/ber.ini: VOLK 8 12 14 15 17 11 17 6
GROUP_SHARES = [0.08, 0.12, 0.14, 0.15, 0.17, 0.11, 0.17, 0.06]
# Reconstruction: minimum branch rating each group accepts.
GROUP_MIN_RATING = [20, 30, 35, 25, 40, 55, 35, 40]
# Reconstruction: price sensitivity / appetite by group.
GROUP_PRICE_SENS = [0.9, 1.0, 1.1, 1.2, 0.9, 0.7, 1.0, 0.8]
GROUP_APPETITE = [0.9, 1.1, 1.0, 1.3, 1.0, 0.9, 1.0, 1.0]

# Product_ComputeFreshness 0x47ACF0: product constant -> base shelf life.
FRESHNESS_BASE = {
    14.1: 38, 15.5: 30, 16.9: 22,
    6.5: 34, 7.5: 27, 8.6: 20,
    2.5: 30, 2.9: 24, 3.6: 18,
    1.0: 25, 1.2: 20, 1.6: 15,
}

# Extracted tables.
CITY_CONSTRUCTION_BASE = [35, 30, 23, 15, 12, 8, 65, 75, 85, 70]
CITY_SERVICE_DIVISOR = [15, 12, 8, 65, 75, 85, 70, 95, 100, 90]


def _load_constants():
    try:
        with open(CONSTANTS) as fh:
            return json.load(fh)
    except (OSError, ValueError):
        return {}


_CONST = _load_constants()
if _CONST:
    _g = _CONST.get("customer_groups", {})
    GROUP_NAMES = _g.get("names", GROUP_NAMES)
    GROUP_SHARES = _g.get("berlin_shares", GROUP_SHARES)
    GROUP_MIN_RATING = _g.get("min_rating", GROUP_MIN_RATING)
    GROUP_PRICE_SENS = _g.get("price_sensitivity", GROUP_PRICE_SENS)
    GROUP_APPETITE = _g.get("appetite", GROUP_APPETITE)
    FRESHNESS_BASE = {float(k): v for k, v in
                      _CONST.get("freshness_base", {}).items()} or FRESHNESS_BASE
    CITY_CONSTRUCTION_BASE = _CONST.get("city_construction_base",
                                        CITY_CONSTRUCTION_BASE)
    CITY_SERVICE_DIVISOR = _CONST.get("city_service_divisor",
                                      CITY_SERVICE_DIVISOR)
    LEDGER_NAMES = {int(k): v for k, v in
                    _CONST.get("ledger_names", {}).items()} or LEDGER_NAMES

# StatsPeriodReport expense categories, resolved through
# SubMenu_BuildBranchBalance + Language_MapStrings.
LEDGER_NAMES = {
    0: "stocks_warehouse",
    1: "rent_expenses",
    2: "construction",
    3: "expansion",
    4: "furnishings",
    5: "misc_expense_a",
    6: "wage_cook",
    7: "wage_service",
    8: "wage_errand",
    9: "service_fees",
    10: "city_operations",
    11: "training_cure",
    12: "ingredients",
    13: "training_expense",
    14: "stocks_warehouse_2",
    15: "city_advertising",
    16: "poster_advertising",
    17: "restaurant_advertising",
    18: "delivery_ingredients",
    19: "manager",
    20: "quarterly_bribes",
    21: "police_bribes",
    22: "delivery_income",
    23: "misc_admin",
    24: "advertising_campaign",
}

# Income array shown by FinanceScreen_UpdateStatement.
INCOME_LEDGER_NAMES = {
    0: "turnover_0", 1: "turnover_1", 2: "turnover_2", 3: "turnover_3",
    4: "turnover_4", 5: "turnover_5", 6: "turnover_6", 7: "turnover_7",
    21: "misc_income", 22: "delivery_income", 23: "manager_income",
}
LEDGER_SIZE = 25

# AI plan action/step tables at DAT_005726DC..DAT_005727CC.
PLAN_ACTION_RANDOM = [
    [0, 3, 6, 9], [1, 4, 7, 10], [2, 5, 8, 11], [48, 6, 12, 24],
]
PLAN_STEPS_RANDOM = [
    [48, 6, 12, 24], [48, 12, 48, 12], [48, 8, 12, 24], [12, 15, 18, 21],
]
PLAN_ACTION_EXPANSION = [
    [12, 15, 18, 21], [13, 16, 19, 22], [14, 17, 20, 23], [24, 12, 48, 48],
]
PLAN_STEPS_EXPANSION = [
    [24, 12, 48, 48], [24, 24, 48, 80], [24, 12, 48, 48], [24, 27, 30, 33],
]
PLAN_ACTION_STRATEGY = [
    [24, 27, 30, 33], [25, 28, 31, 34], [26, 29, 32, 35], [24, 24, 48, 48],
]
PLAN_STEPS_STRATEGY = [
    [24, 24, 48, 48], [48, 36, 48, 48], [24, 48, 48, 48], [1, 2, 3, 4],
]

# Company_ExecuteAction 0x5016C0 action ids.
MISSION_STRATEGY_ACTION_IDS = set(range(24, 36))

PLAN_ACTION_NAMES = {
    1: "advance", 2: "noop", 5: "buy_or_rent_branch",
    7: "validate_menu", 8: "customer_visit", 9: "style",
    10: "open_branch", 11: "tick_branches", 12: "assign_suppliers",
    13: "guards", 16: "annoy_rival", 17: "gangsters",
    19: "optimize_pricing", 20: "security", 21: "advancement",
    22: "build_branch", 23: "advertising",
}

TICKS_PER_SECOND = 100          # GameLoop_DispatchScreens waits 10 ms
TICKS_PER_HOUR = TICKS_PER_SECOND * 3600
# Map_ComputeIsoOffsets: cell steps are half the 64x32 view cell.
ISO_HALF_TILE_W = 32.0
ISO_HALF_TILE_H = 16.0
# Character walk ANI templates ("gehen1..8") carry delay byte 12.
WALK_FRAME_DELAY_UNITS = 12
WALK_FRAME_MS = 1000.0 / WALK_FRAME_DELAY_UNITS  # 83.33 ms per path node


def iso_cell_delta(dx, dy):
    """Iso screen displacement -> grid cell displacement.

    ``view_w=64``, ``view_h=32`` in the .iso header; a grid step is
    ``view_w/2`` horizontally and ``view_h/2`` vertically.
    """
    cell_x = (dx / ISO_HALF_TILE_W + dy / ISO_HALF_TILE_H) / 2.0
    cell_y = (dy / ISO_HALF_TILE_H - dx / ISO_HALF_TILE_W) / 2.0
    return cell_x, cell_y


PATH_NODE_CAP = 400


def path_cell_count(dx, dy):
    """Map_FindShortestPath 0x4F14A0 node count on the 8-neighbour grid.

    Map_LinkCells stores up to eight edges at record+0x14 and
    Grid_RebuildStreetNodes tests all eight neighbours.  On an open grid the
    shortest 8-neighbour node count is the Chebyshev cell distance.
    """
    cell_x, cell_y = iso_cell_delta(dx, dy)
    return min(PATH_NODE_CAP, max(1, int(math.ceil(abs(cell_x))),
                                  int(math.ceil(abs(cell_y)))))


def walk_node_ms(delay_units=WALK_FRAME_DELAY_UNITS):
    """Record_SetVariant 0x533B90: 1000 / template delay byte."""
    return int(round(1000.0 / max(1, int(delay_units))))


def path_travel_ms(dx, dy, delay_units=WALK_FRAME_DELAY_UNITS):
    """Walk time over the 8-neighbour graph in milliseconds."""
    return path_cell_count(dx, dy) * walk_node_ms(delay_units)


def travel_ticks(dx, dy, delay_units=WALK_FRAME_DELAY_UNITS):
    """World ticks (10 ms) required for the path."""
    return max(1, path_travel_ms(dx, dy, delay_units) // 10)


def travel_hours(dx, dy, delay_units=WALK_FRAME_DELAY_UNITS):
    """Sub-hour paths round down to a same-hour arrival."""
    return path_travel_ms(dx, dy, delay_units) // 3_600_000


def service_ticks(branch_type):
    """Game_GetTimeByMode(branch, 6)."""
    return 0x50 if branch_type in (0x0F, 0x21) else 0x1E


HOUR_CURVE = [
    0.05, 0.03, 0.02, 0.02, 0.03, 0.06,
    0.12, 0.25, 0.45, 0.65, 0.85, 1.00,
    1.15, 1.10, 0.90, 0.80, 0.95, 1.15,
    1.30, 1.40, 1.15, 0.80, 0.40, 0.15,
]


def clamp(x, lo=0, hi=100):
    return max(lo, min(hi, x))


def city_adjust(value, taste_a=0, taste_b=0):
    """(100 - 3*(a+b)) * value / 100, clamped 0..100."""
    return clamp(((100 - 3 * (taste_a + taste_b)) * value) // 100)


def market_bonus(x):
    """Game_GetMarketBonusFactor: (100 + x) * 0.01."""
    return (100 + x) * 0.01


def party_size_from_rating(rating):
    """Object_UpdateCustomerQueue: (Rating_GetComposite(customer) >> 4) + 1."""
    return max(1, (int(rating) >> 4) + 1)


def freshness(product_constant, elapsed):
    base = FRESHNESS_BASE.get(product_constant)
    if base is None:
        return 0
    return max(0, base - int(elapsed))


def service_level(city_values, city_index):
    """City_ComputeServiceLevel: 4 values at +0xA4, divisor city table."""
    min_deficit = 24
    for v in city_values[:4]:
        min_deficit = min(min_deficit, v - 6)
    if min_deficit < 25:
        return (24 - min_deficit) // CITY_SERVICE_DIVISOR[city_index % 10] + 1
    return 0


def _load_market_table():
    try:
        with open(MARKET_TABLE) as fh:
            return json.load(fh).get("records", [])
    except (OSError, ValueError):
        return []


MARKET_RECORDS = _load_market_table()
MARKET_PRICES = [float(r["price"]) for r in MARKET_RECORDS] or [1.0] * 86
MARKET_AMOUNTS = [list(r.get("amounts", [1, 1, 1, 1]))
                  for r in MARKET_RECORDS] or [[1] * 4 for _ in range(86)]
FOOD_PAIRS = [tuple(t) for t in
              _CONST.get("food_pairs", {}).get("triples", [])]
MARKET_DESCRIPTORS = _CONST.get("market_descriptors", [])


def math_round_half_away(value):
    """Math_RoundFloat 0x403850: add/sub 0.5, then truncate."""
    return int(value + 0.5) if value >= 0 else int(value - 0.5)


@dataclass
class CityProfile:
    name: str = "Berlin"
    short: str = "ber"
    country: str = "Germany"
    rent_factor: int = 65
    patience: int = 40
    price_factor: int = 70
    income_factor: int = 65
    quality_factor: int = 65
    comfort: int = 80
    population: int = 260
    climate: list[int] = field(default_factory=lambda: [-10, 20, 0, -15])
    group_shares: list[float] = field(default_factory=lambda: list(GROUP_SHARES))
    volk: list[int] = field(default_factory=lambda: [8, 12, 14, 15, 17, 11, 17, 6])
    value_factor: int = 100
    rating_difficulty: int = 5

    @property
    def income_trade_factor(self):
        """City+0x98 = EINKOMMEN * 0.02 (used by Rating_GetFloat)."""
        return self.income_factor * 0.02

    @property
    def rating_phase(self):
        return (11 - self.rating_difficulty) * 0.5
    taste: list[int] = field(default_factory=lambda: [0, 0, 0, 0, 0, 0])
    food_taste: list[list[int]] = field(default_factory=lambda: [
        [0, 0, 1, -1, 1, 1, -1, -1],
        [1, 1, -1, 1, -1, -1, 1, 0],
        [0, -1, -1, 0, 0, 0, 1, 0],
        [-1, -1, 1, -1, 1, 1, 0, -1],
        [1, 1, 0, 0, -1, 0, -1, 1],
        [-1, 0, 0, 1, 0, -1, 0, 1],
    ])

    @property
    def traffic_scale(self):
        return self.population / 260.0

    @property
    def rent_scale(self):
        return self.rent_factor / 65.0

    @property
    def wage_scale(self):
        return self.income_factor / 65.0

    @property
    def price_scale(self):
        return self.price_factor / 70.0

    @property
    def quality_scale(self):
        return self.quality_factor / 65.0

    @property
    def ad_city_term(self):
        """100 - 3*(City+0x64 + City+0x4C) = 100 - 3*(VOLK[6] + VOLK[0])."""
        return 100 - 3 * (self.volk[6] + self.volk[0])

    @property
    def rent_trade_factor(self):
        """City+0x8C = MIETEN * 0.02 (CityDefinition_ParseIni type 1)."""
        return self.rent_factor * 0.02

    @property
    def purchase_trade_factor(self):
        """City+0x94 = KAUFPREIS * 0.02."""
        return self.price_factor * 0.02


def load_city_ini(path: str) -> CityProfile:
    """Parse daten/<city>.ini into a CityProfile."""
    values = {}
    with open(path, errors="replace") as fh:
        for line in fh:
            line = line.split("//", 1)[0].strip()
            if not line:
                continue
            parts = line.split()
            if len(parts) < 2:
                continue
            key, rest = parts[0].upper(), parts[1:]
            if rest and rest[0].startswith('"'):
                values[key] = " ".join(rest).strip('"')
            else:
                values[key] = rest
    def one(key, default):
        v = values.get(key)
        return int(v[0]) if isinstance(v, list) and v else default
    def ints(key, count, default):
        v = values.get(key)
        if isinstance(v, list) and len(v) >= count:
            try:
                return [int(x) for x in v[:count]]
            except ValueError:
                return default
        return default
    volk = ints("VOLK", 8, [8, 12, 14, 15, 17, 11, 17, 6])
    total = sum(volk)
    shares = [v / total for v in volk] if total else list(GROUP_SHARES)
    return CityProfile(
        name=str(values.get("NAME", "Berlin")),
        short=str(values.get("SHORT", "ber")),
        country=str(values.get("LAND", "Germany")),
        rent_factor=one("MIETEN", 65),
        patience=one("GEDULT", 40),
        price_factor=one("KAUFPREIS", 70),
        income_factor=one("EINKOMMEN", 65),
        quality_factor=one("QUALITAET", 65),
        comfort=one("KOMFORT", 80),
        population=one("BEVOELKERUNG", 260),
        climate=ints("KLIMA", 4, [-10, 20, 0, -15]),
        group_shares=shares,
        volk=volk,
        taste=ints("GESCHMACK", 6, [0, 0, 0, 0, 0, 0]),
        food_taste=[
            ints("GEMUESE", 8, [0, 0, 1, -1, 1, 1, -1, -1]),
            ints("FLEISCH", 8, [1, 1, -1, 1, -1, -1, 1, 0]),
            ints("FISCH", 8, [0, -1, -1, 0, 0, 0, 1, 0]),
            ints("OBST", 8, [-1, -1, 1, -1, 1, 1, 0, -1]),
            ints("KAESE", 8, [1, 1, 0, 0, -1, 0, -1, 1]),
            ints("GEWUERZ", 8, [-1, 0, 0, 1, 0, -1, 0, 1]),
        ],
    )


# Rating_ComputeBuildingScore 0x47A000: 56-entry per-group weight table.
BUILDING_WEIGHTS = [
    -7, 0, -5, -3, -17, -20, -15, -11,
    1, 1, 2, 2, 4, 5, 3, 3,
    -1, -2, -2, -3, -6, -7, -5, -4,
    2, 8, 6, 4, 14, 16, 12, 10,
    -1, -3, -2, -4, -7, -8, -6, -5,
    0, -3, -5, 0, 4, 5, 3, 2,
    -1, -1, -1, -1, -2, -3, -2, -2,
]

DEFAULT_FACILITIES = {
    0x16: 2, 0x17: 2, 0x0F: 1, 0x21: 1,
    0x1A: 5, 0x1B: 5, 0x1C: 5,
}


def clamp_int(value, lo=0, hi=100):
    return max(lo, min(hi, value))


def rating_composite(v4, v8, v12, v16, state=50, flagged=False):
    """Rating_GetComposite 0x4D4000 + ClampAdjusted/AdjustA/AdjustB."""
    if state < 51:
        c0 = v4 - 25 + state
    else:
        c0 = (55 - state) * 5 + v4
    c0 = clamp_int(c0)
    c1 = v8 + (55 - state) * 3 if state > 55 else v8
    c1 = max(0, c1)
    c2 = v12
    c3 = v16 + (50 - state) * 2 if state > 50 else v16
    c3 = max(0, c3)
    total = c0 + c1 + c2 + c3
    avg = total >> 2
    if flagged:
        avg = (avg - (total >> 31)) >> 1
    min_component = min(c0, c1, c2, c3)
    return min(avg, min_component * 4)


def building_score_for_group(group, facilities=None, floor_value=0,
                             staff_value=0):
    """Rating_ComputeBuildingScore for one group or -1 for all groups."""
    facilities = facilities or DEFAULT_FACILITIES
    def one(g):
        total = (facilities.get(0x17, 0) * BUILDING_WEIGHTS[g + 0x28]
                 + facilities.get(0x16, 0) * BUILDING_WEIGHTS[g]
                 + (facilities.get(0x21, 0) + facilities.get(0x0F, 0))
                 * BUILDING_WEIGHTS[g + 0x18] * 2)
        if staff_value:
            total += (staff_value // 60 + floor_value) * BUILDING_WEIGHTS[g + 8]
        for ftype, off in ((0x1A, 0x10), (0x1B, 0x20), (0x1C, 0x30)):
            count = facilities.get(ftype, 0)
            if count > 0:
                n = min(4, count // 5 + 1)
                total += round(BUILDING_WEIGHTS[g + off] * n)
        return total
    if group == -1:
        total = sum(one(g) for g in range(8))
        return (total + (total >> 31 & 7)) >> 3
    return one(group)


PRICE_SCALES = [5.0, 5.0, 5.0, 5.0, 3.0, 2.0, 3.0, 5.0]  # 0x56CCEC / 100


def market_price_delta(level_value):
    """Market_GetPriceDelta 0x4DB170."""
    if level_value == -1:
        return -40
    return 40 if level_value != 0 else 0


def market_value_adjustment(group, price_level, city_levels, price_adjust,
                            quality_adjust, city_pref, branch_price):
    """Market_ComputeValueAdjustment 0x4D7640 (price-level table supplied)."""
    level = max(0, min(5, price_level - 1))
    base = market_price_delta(city_levels[level] if level < len(city_levels) else 0)
    availability = sum(10 for v in city_levels if v == level)
    g = group - 2
    if g in (0, 2):
        adj_price = price_adjust * 5
    elif g in (1, 4):
        adj_price = price_adjust * -10
    elif g in (3, 5):
        adj_price = price_adjust * 10
    else:
        adj_price = 0
    if g in (0, 4):
        adj_quality = quality_adjust * 5
    elif g in (2, 3):
        adj_quality = quality_adjust * 10
    else:
        adj_quality = 0
    penalty = -1000 if city_pref / (PRICE_SCALES[group] * 0.01) < branch_price else 0
    return availability + adj_price + adj_quality + penalty + base


def rating_group_expectation(income_factor, phase, group):
    """Rating_GetFloat 0x489070: expected price per customer group."""
    inc = float(income_factor)
    if group == 0:
        return inc * 3.0 + phase + 4.0
    if group == 1:
        return inc * 4.0 + phase + 5.0
    if group == 2:
        return inc * 4.0 + phase + 8.0
    if group == 3:
        return inc * 3.0 + phase + 8.0
    if group == 4:
        return inc * 7.0 + phase + 10.0
    if group in (5, 8):
        return inc * 10.0 + phase + 8.0
    if group == 6:
        return inc * 3.0 + phase + 7.0
    return phase + 12.0


def c_trunc(value):
    """x87 __ftol: truncate toward zero."""
    return int(value)


SKILL_CAPS = [40, 10, 20, 30, 5, 0, 40, 20]


def game_compute_skill_ratings(income_factor, level, price, phase,
                               groups=8):
    """Game_ComputeSkillRatings 0x513760 price term.

    ``income_factor`` is City+0x98 (EINKOMMEN*0.02). The result is the
    price-positioning component written to recipe+0x2E4; the base skill at
    recipe+0x2C4 is a separate food-stat computation.
    """
    expected = [rating_group_expectation(income_factor, phase, g)
                for g in range(groups)]
    bonus = 0.0
    if level == 1:
        bonus = income_factor * 2.0
    elif level == 2:
        bonus = income_factor * 4.0
    expected = [v + bonus for v in expected]
    out = []
    for g in range(groups):
        local = expected[g]
        skill = 0
        if price > local:
            if local != 0:
                skill = c_trunc((price / local - 1.0) * -50.0)
        elif price < local:
            if price == 0:
                skill = 100
            else:
                skill = c_trunc((local / price - 1.0) * 50.0)
            cap = SKILL_CAPS[g] if g < len(SKILL_CAPS) else 0
            if skill > cap:
                skill = cap
        out.append(skill)
    return out


def rating_store_clamped_scores(a, b, c, d):
    """Rating_StoreClampedScores 0x513270 -> recipe+0x264[8]."""
    scores = [
        c_trunc(0.33 * a + 0.70 * b),
        c_trunc(0.70 * a + 0.33 * b),
        c_trunc(0.50 * b + 50.0 * c),
        c_trunc(0.60 * a + 0.20 * b + 0.20 * d),
        c_trunc(0.40 * b + 60.0 * c),
        c_trunc(0.40 * b + 30.0 * c + 0.30 * d),
        c_trunc(0.33 * b + 30.0 * c + 0.40 * d),
        c_trunc(1.00 * a + 0.40 * b + 1.00 * d),
    ]
    return [clamp_int(v) for v in scores]


def game_compute_market_factors(c250=0, c254=0, city_score=0,
                                mission_flag=0, count=20,
                                branch_categories=None, city_matrix=None):
    """Game_ComputeMarketFactors 0x5133C0 -> recipe+0x284[8]."""
    m = [0] * 8
    m[7] += 10 * c250
    m[3] += -10 * c250
    m[2] += 5 * c250 + 5 * c254
    m[4] += 5 * c250 + 10 * c254
    m[5] += 10 * c254 + 10 * c250
    m[6] += 5 * c254 - 10 * c250
    if mission_flag:
        m[6] += 30
        m[4] += 30
        m[5] += 5
        m[7] += 30
    if city_score > 200:
        m[0] += 10
        m[1] += 40
        m[5] -= 20
    if city_score > 300:
        m[3] += 40
        m[4] -= 20
        m[6] -= 20
        m[7] += 40
    if branch_categories is not None and city_matrix is not None:
        for i in range(8):
            for j in range(6):
                m[i] += branch_categories[j] * city_matrix[j * 8 + i]
    if count < 20:
        for i in range(8):
            m[i] += (20 - count) * -5
    return m


def skill_ratings(city_prefs, level=0, price_param=0.0):
    """Game_ComputeSkillRatings 0x513760 with per-category clamps."""
    values = list(city_prefs)
    bonus = 0.0
    if level == 1:
        bonus = city_prefs[0] * 2
    elif level == 2:
        bonus = city_prefs[0] * 4
    if bonus:
        values = [v + bonus for v in values]
    caps = [40, 10, 20, 30, 5, 0, 40, 20]
    out = []
    for i, v in enumerate(values):
        if price_param <= 0 or v <= price_param:
            val = int(v)
        else:
            val = int(v)
        out.append(max(0, min(caps[i] if caps[i] else 0, val)))
    return out


def game_compute_company_product_score(recipe, branch, category, price,
                                       city_recent=None):
    """Game_ComputeCompanyProductScore 0x513B00 (86-ingredient pass)."""
    counts = recipe.usage_counters()
    availability = 0
    counted = 0
    price_delta = 0
    for i, usage in enumerate(counts):
        if usage <= 0:
            continue
        record = MARKET_RECORDS[i] if i < len(MARKET_RECORDS) else {}
        level = int(record.get("category", 0))
        index = level - 1
        city_level = (branch.city_levels[index]
                      if 0 <= index < len(branch.city_levels) else 0)
        local4 = market_price_delta(city_level)
        local8 = 0
        if city_recent is not None and 0 <= category < len(city_recent):
            local8 = 10 * sum(1 for x in city_recent[category] if x == i)
        if i != 0:
            availability += local8
            counted += 1
        price_delta += local4
    base = -40 if counted < 1 else availability // counted + price_delta
    skill = recipe.total_skill_ratings(branch, price)[category]
    return clamp_int(base + skill)


def company_product_score(values, availability, skill):
    """Game_ComputeCompanyProductScore 0x513B00 (one product)."""
    if values:
        base = sum(values) / len(values)
    else:
        base = -40
    return clamp_int(int(base + availability + skill))


def price_rating(avg_price, expected_price):
    """Branch_RecomputeMenuPriceRatings price component."""
    if avg_price <= expected_price:
        return 100
    return clamp_int(100 - int((avg_price - expected_price) * 10))


_SPRITE_CACHE = {}


def topping_sprite_indices(ingredient, variant):
    """Return (width, height, palette indices) for one topping sprite."""
    key = (ingredient, variant)
    if key in _SPRITE_CACHE:
        return _SPRITE_CACHE[key]
    base = f"za{ingredient + 1:02d}a_{variant:02d}.spr"
    path = os.path.join(ROOT, "extracted", "sprites", "zutaten", base)
    try:
        with open(path, "rb") as fh:
            data = fh.read()
    except OSError:
        _SPRITE_CACHE[key] = (0, 0, [])
        return _SPRITE_CACHE[key]
    if len(data) < 0x21:
        _SPRITE_CACHE[key] = (0, 0, [])
        return _SPRITE_CACHE[key]
    bpp = data[6]
    flags = data[5]
    stride = int.from_bytes(data[7:9], "little")
    height = int.from_bytes(data[9:11], "little")
    data_size = int.from_bytes(data[0x19:0x1D], "little")
    width = stride // (bpp // 8)
    pixels = [0] * (width * height)
    if bpp != 8 or width <= 0 or height <= 0:
        _SPRITE_CACHE[key] = (0, 0, [])
        return _SPRITE_CACHE[key]
    payload = data[0x21 + 0x300:0x21 + 0x300 + data_size]
    if flags & 0x10:
        x = y = 0
        i = 0
        while i + 2 <= len(payload) and y < height:
            token = int.from_bytes(payload[i:i + 2], "little")
            i += 2
            alpha = token & 0xFF
            index = token >> 8
            if alpha == 0:
                x += index
            else:
                if 0 <= x < width:
                    pixels[y * width + x] = index
                x += 1
            while x >= width:
                x -= width
                y += 1
    else:
        x = y = 0
        for i in range(0, len(payload) - 1, 2):
            alpha = payload[i]
            index = payload[i + 1]
            if alpha and 0 <= x < width and 0 <= y < height:
                pixels[y * width + x] = index
            x += 1
            if x >= width:
                x = 0
                y += 1
    _SPRITE_CACHE[key] = (width, height, pixels)
    return _SPRITE_CACHE[key]


def topping_sprite_histogram(ingredient, variant):
    width, height, pixels = topping_sprite_indices(ingredient, variant)
    hist = [0] * 25
    for index in pixels:
        if 1 <= index <= 24:
            hist[index] += 1
    return hist


def screen_score_color_histogram(hist):
    """Screen_ScoreColorHistogram 0x512E50."""
    total = sum(hist)
    empty = sum(1 for value in hist if value < 1)
    mean = total // 24
    lower = c_trunc(mean * 0.5)
    upper = c_trunc(mean * 2.0)
    score = 100
    for value in hist:
        if value < lower or value > upper:
            score -= 10
    score -= 20 * empty
    return max(0, score)


@dataclass
class RecipeTopping:
    ingredient: int
    category: int = 0
    tier: int = 0
    x: int = 0
    y: int = 0
    variant: int = 0
    flag: int = 0
    reserved: bytes = b"\0" * 8


@dataclass
class Recipe:
    name: str
    price: float
    unit_cost: float
    quality: int = 55
    ingredients: dict[int, int] | None = None
    base_price: float | None = None
    toppings: list = field(default_factory=list)
    usage: list = field(default_factory=list)
    sales: float = 0.0
    skill_ratings: list = field(default_factory=list)
    _color_key: tuple | None = field(default=None, repr=False)
    _color_hist: list | None = field(default=None, repr=False)

    def skill_rating(self, category):
        if 0 <= category < len(self.skill_ratings):
            return clamp_int(self.skill_ratings[category])
        return clamp_int(self.quality)

    def food_stats(self):
        """Game_ComputeFoodStats 0x513590 from DAT_00573264 pairs."""
        counts = self.usage_counters()
        local = [0] * 7
        for a, b, weight in FOOD_PAIRS:
            if not (0 <= a < len(counts) and 0 <= b < len(counts)):
                continue
            if counts[a] <= 0 or counts[b] <= 0:
                continue
            ca = MARKET_RECORDS[a].get("category", 0) if a < len(MARKET_RECORDS) else 0
            cb = MARKET_RECORDS[b].get("category", 0) if b < len(MARKET_RECORDS) else 0
            if 0 <= ca < 7:
                local[ca] += weight
            if 0 <= cb < 7:
                local[cb] += weight
        a, b = local[1], local[2] + local[4]
        c, d = local[3] + local[6], local[5]
        stats = [c + 3 * b, c + 2 * b, d + 2 * a + b, 4 * c,
                 2 * (d + 2 * a), 2 * (a + 2 * d), 3 * c,
                 d + a + b + c]
        return [40 - v if v > 20 else v for v in stats]

    def weighted_averages(self):
        """Stats_ComputeWeightedAverages 0x513100."""
        counts = [0] * 7
        total = 0
        taste = 0
        price = 0
        quality = 0
        for topping in self.toppings:
            if not (0 <= topping.ingredient < len(MARKET_DESCRIPTORS)):
                continue
            record = MARKET_DESCRIPTORS[topping.ingredient]
            tier = max(0, min(3, int(topping.tier)))
            amount = record["amounts"][tier]
            category = int(record["category"])
            counts[category] += amount
            total += amount
            taste += amount * record["taste"][tier]
            price += amount * record["price_adjust"]
            quality += amount * record["quality_adjust"]
        if total <= 0:
            return {"total": 0, "categories": [0] * 6, "taste": 0,
                    "price_adjust": 0, "quality_adjust": 0}
        return {
            "total": total,
            "categories": [counts[i] * 100 // total for i in range(1, 7)],
            "taste": math_round_half_away(taste / total),
            "price_adjust": math_round_half_away(price / total),
            "quality_adjust": math_round_half_away(quality / total),
        }

    def compose_surface(self):
        """Compose topping sprites onto the 800x600 palette-index surface."""
        surface = bytearray(800 * 600)
        for topping in self.toppings:
            if not (0 <= topping.ingredient < len(MARKET_RECORDS)):
                continue
            tier = max(0, min(3, int(topping.tier)))
            variant = int(topping.variant) % 8
            sizes = MARKET_RECORDS[topping.ingredient].get("sizes")
            if not sizes or tier >= len(sizes) or variant >= len(sizes[tier]):
                continue
            w = int(sizes[tier][variant]["w"])
            h = int(sizes[tier][variant]["h"])
            sw, sh, pixels = topping_sprite_indices(
                topping.ingredient, variant % 4)
            if w <= 0 or h <= 0 or sw <= 0 or sh <= 0:
                continue
            ox = int(topping.x)
            oy = int(topping.y)
            for dy in range(h):
                sy = min(sh - 1, dy * sh // h)
                y = oy + dy
                if not (0 <= y < 600):
                    continue
                row = sy * sw
                base = y * 800
                for dx in range(w):
                    sx = min(sw - 1, dx * sw // w)
                    value = pixels[row + sx]
                    if value not in (0, 0xFF):
                        x = ox + dx
                        if 0 <= x < 800:
                            surface[base + x] = value
        return surface

    def color_histogram(self):
        """Screen_AccumulateColorHistogram 0x5123F0 diamond scan."""
        key = tuple((t.ingredient, t.tier, t.variant % 8, int(t.x), int(t.y))
                    for t in self.toppings)
        if self._color_key == key and self._color_hist is not None:
            return list(self._color_hist)
        surface = self.compose_surface()
        hist = [0] * 24
        for topping in self.toppings:
            if not (0 <= topping.ingredient < len(MARKET_RECORDS)):
                continue
            tier = max(0, min(3, int(topping.tier)))
            variant = int(topping.variant) % 8
            sizes = MARKET_RECORDS[topping.ingredient].get("sizes")
            if not sizes or tier >= len(sizes) or variant >= len(sizes[tier]):
                continue
            w = int(sizes[tier][variant]["w"])
            h = int(sizes[tier][variant]["h"])
            radius = min(w, h)
            if radius < 1:
                continue
            cx = w // 2 + int(topping.x)
            cy = h // 2 + int(topping.y)
            start = max(0, -cy, cy - 599)
            if start >= radius:
                continue
            for offset in range(start, radius):
                half = int(radius * math.sqrt(
                    max(0.0, 1.0 - (offset / radius) ** 2)))
                for y in (cy + offset, cy - offset):
                    if not (0 <= y < 600):
                        continue
                    base = y * 800
                    for x in range(cx - half, cx + half):
                        if 0 <= x < 800:
                            value = surface[base + x]
                            if 0 < value < 0xFF and value <= 24:
                                hist[value - 1] += 1
        self._color_key = key
        self._color_hist = list(hist)
        return hist

    def layout_color_delta(self, deltas=None):
        """Recipe_AccumulateQualityDelta 0x512C40 colour average (+0x258)."""
        placed = len(self.toppings)
        if placed < 1:
            return 0
        if deltas is None:
            deltas = [0] * placed
        acc = 0
        count = 0
        for delta in deltas:
            value = int(delta) & 0xFF
            if value >= 128:
                value -= 256
            if value > 4:
                value -= 8
            if value < -4:
                value += 8
            acc += abs(value) - 2
            count += 1
        if count < 1:
            return 0
        return max(0, min(100, math_round_half_away(acc / count) * 100))

    def layout_quality_scores(self, averages=None, orientation_deltas=None):
        """Rating_StoreClampedScores inputs from recipe layout."""
        avg = averages if averages is not None else self.weighted_averages()
        placed = len(self.toppings)
        local_c = 0
        a = screen_score_color_histogram(self.color_histogram())
        b = min(20, 5 * placed) + (placed - local_c) * 10
        b = max(0, min(100, b))
        c = avg["taste"]
        d = self.layout_color_delta(orientation_deltas)
        return rating_store_clamped_scores(a, b, c, d)

    def market_factor_scores(self, averages=None, city_matrix=None,
                             price_competitive=1):
        avg = averages if averages is not None else self.weighted_averages()
        if (city_matrix and len(city_matrix) == 6
                and isinstance(city_matrix[0], (list, tuple))):
            city_matrix = [v for row in city_matrix for v in row]
        return game_compute_market_factors(
            c250=avg["quality_adjust"], c254=avg["price_adjust"],
            city_score=avg["total"], mission_flag=price_competitive,
            count=len(self.toppings), branch_categories=avg["categories"],
            city_matrix=city_matrix)

    def base_skill_ratings(self, market_scores=None, averages=None,
                           city_matrix=None, price_competitive=1,
                           orientation_deltas=None):
        """Game_ComputeCompanyRatings 0x5136C0."""
        avg = averages if averages is not None else self.weighted_averages()
        layout = self.layout_quality_scores(avg, orientation_deltas)
        if market_scores is None:
            market_scores = self.market_factor_scores(
                avg, city_matrix, price_competitive)
        food = self.food_stats()
        return [clamp_int((layout[i] + market_scores[i]) // 2 + food[i])
                for i in range(8)]

    def orientation_deltas(self, branch):
        """Deltas from generated approach-line objects, or None."""
        objects = branch.approach_objects
        if not objects:
            return None
        return [(self.toppings[i].variant
                 - objects[i % len(objects)]["variant"]) & 0xFF
                for i in range(len(self.toppings))]

    def total_skill_ratings(self, branch, price):
        """Base skill + Game_ComputeSkillRatings price term."""
        avg = self.weighted_averages()
        deltas = self.orientation_deltas(branch)
        base = self.base_skill_ratings(
            averages=avg, city_matrix=branch.city_food_taste,
            price_competitive=branch.price_competitive,
            orientation_deltas=deltas)
        price_skill = game_compute_skill_ratings(
            branch.city_income_factor, branch.level, price,
            branch.city_rating_phase)
        return [clamp_int(base[i] + price_skill[i]) for i in range(8)]

    @classmethod
    def random_construct(cls, rng, name="Generated", price=12.0,
                         quality=55, count=7):
        """Recipe_Construct 0x50FC20 random fallback."""
        toppings = []
        for _ in range(count):
            idx = rng.randrange(86)
            toppings.append(RecipeTopping(
                idx, MARKET_RECORDS[idx].get("category", 0)
                if MARKET_RECORDS else 0,
                rng.randrange(4),
                rng.randrange(0x2D, 400) - 0x23,
                rng.randrange(0x35, 400) - 0x23))
        return cls(name, price, 4.0, quality, toppings=toppings)

    def to_stream(self, save_version=43):
        """Recipe_LoadFromStream 0x5108E0 wire format."""
        import struct
        name = self.name.encode("latin1", "replace")[:0x40].ljust(0x40, b"\0")
        out = bytearray(name)
        out += struct.pack("<f", float(self.unit_cost))
        out += struct.pack("<I", len(self.toppings))
        for t in self.toppings:
            out += struct.pack("<BBBiiBB8s",
                               int(t.ingredient) & 0xFF,
                               int(t.category) & 0xFF,
                               int(t.tier) & 0xFF,
                               int(t.x), int(t.y),
                               int(t.variant) & 0xFF,
                               int(t.flag) & 0xFF,
                               t.reserved[:8].ljust(8, b"\0"))
        counters = self.usage_counters()
        out += struct.pack("<86i", *counters)
        out += b"\0" * 0x1C          # +0x1BC
        out += b"\0" * 4             # +0x1D8
        out += b"\0"                 # +0x1DC
        if save_version < 0x2B:
            out += b"\0"
        out += b"\0" * 0x60          # +0x1E0
        out += b"\0" * 0x1C          # +0x240
        out += b"\0" * 0x80          # +0x264
        out += struct.pack("<I", 0)   # no sales records
        out += struct.pack("<II", 5, 0)
        return bytes(out)

    @classmethod
    def from_stream(cls, data, offset=0, save_version=43):
        import struct
        start = offset
        name = data[offset:offset + 0x40].split(b"\0", 1)[0].decode(
            "latin1")
        offset += 0x40
        unit_cost = struct.unpack_from("<f", data, offset)[0]
        offset += 4
        count = struct.unpack_from("<I", data, offset)[0]
        offset += 4
        toppings = []
        for _ in range(count):
            ing, cat, tier, x, y, variant, flag, reserved = (
                struct.unpack_from("<BBBiiBB8s", data, offset))
            offset += 21
            toppings.append(RecipeTopping(
                ing, cat, tier, x, y, variant, flag, reserved))
        usage = list(struct.unpack_from("<86i", data, offset))
        offset += 0x158
        offset += 0x1C + 4 + 1
        if save_version < 0x2B:
            offset += 1
        offset += 0x60 + 0x1C + 0x80
        sales = struct.unpack_from("<I", data, offset)[0]
        offset += 4
        if sales:
            n = struct.unpack_from("<I", data, offset)[0]
            offset += 4 + n * 0x1C
        offset += 8
        recipe = cls(name, 12.0, unit_cost, 55, toppings=toppings,
                     usage=usage)
        recipe.usage = usage
        recipe.stream_size = offset - start
        return recipe, offset

    @staticmethod
    def load_menu(data, offset=0, count=None, save_version=43):
        import struct
        if count is None:
            count = struct.unpack_from("<I", data, offset)[0]
            offset += 4
        recipes = []
        for _ in range(count):
            recipe, offset = Recipe.from_stream(data, offset, save_version)
            recipes.append(recipe)
        return recipes, offset

    @staticmethod
    def menu_to_stream(recipes, save_version=43):
        import struct
        return (struct.pack("<I", len(recipes))
                + b"".join(r.to_stream(save_version) for r in recipes))

    def usage_counters(self):
        """PlayerStats_Reset 0x50FEC0 for a recipe."""
        counters = [0] * 86
        if self.toppings:
            for t in self.toppings:
                if 0 <= t.ingredient < 86:
                    amounts = (MARKET_AMOUNTS[t.ingredient]
                               if t.ingredient < len(MARKET_AMOUNTS)
                               else [1, 1, 1, 1])
                    counters[t.ingredient] += int(
                        amounts[max(0, min(3, t.tier))])
        elif self.ingredients:
            for idx, qty in self.ingredients.items():
                if 0 <= int(idx) < 86:
                    counters[int(idx)] += max(0, int(qty))
        return counters


def batch_unit_cost(base_price, owned_count, product_multiplier=1.5,
                    product_scale=0.0, city_price=0.0, city_tax=0.0):
    """BuildingValue_Compute 0x4E2410."""
    local = product_multiplier
    local = (owned_count * product_scale + 1.0) * local
    return base_price * local * (1.0 - (city_price + city_tax) * 0.03)


@dataclass
class VehicleConvoy:
    vehicles: int
    delays: list[int]
    path_cells: int
    arrivals: list[int]
    arrived: int = 0


@dataclass
class PlanAction:
    action: int
    target: int
    ttl: int = 5
    steps: int = 1


@dataclass
class MissionPlan:
    action: int
    steps: int
    target: int = -1
    counter: int = 0


@dataclass
class Batch:
    qty: float
    unit_cost: float


@dataclass
class ConstructionOrder:
    cost: float
    weeks: int
    facility_type: int = 0x1F
    quality_gain: int = 2
    progress: int = 0
    paid: float = 0.0

    @property
    def progress_pct(self):
        return int(100 * self.progress / max(1, self.weeks))


@dataclass
class AdvertisingPlan:
    media_type: int
    category: int
    monthly_cost: float          # daily budget (plan+0x20)
    setup_cost: float = 0.0      # takeover fee only
    weeks_left: int = 4          # unused: plans have no time expiry
    plan_type: int = 3
    flags: int = 0
    target: int = -1
    percent: int = 100
    active: bool = True
    effect_value: float = 0.0

    @property
    def daily_budget(self):
        return self.monthly_cost


# DAT_005730AC rows by media type (rows 1..3 are used by advertising).
AD_WEIGHTS = [
    [0] * 8,
    [6, 1, -2, -4, 2, -2, -6, -2],
    [5, 0, 3, 5, -5, -6, 6, -4],
    [4, 2, 0, 1, -2, -5, 0, 2],
    [-6, -2, 6, -6, 6, 2, 2, -3],
    [2, 4, -6, -3, 5, 1, -5, 0],
    [3, 5, -4, -2, 0, -3, -4, 5],
    [0, -4, 5, 2, -3, 4, 4, -6],
    [-3, -5, -5, 4, -6, 6, 5, 3],
    [1, 3, 2, 0, 4, 0, -2, -5],
    [-2, -3, 1, 3, 1, 3, 3, 1],
    [-5, -6, 4, -5, 3, 5, 1, 6],
    [-4, 6, -3, 6, -4, -4, -3, 4],
]


def f32(value):
    """Round to IEEE-754 float32 (the game's hourly budget arithmetic)."""
    return struct.unpack("<f", struct.pack("<f", float(value)))[0]


F32_ONE_OVER_24 = f32(1.0 / 24.0)


# Game_ComputePrice 0x4E4060: per-level base values (level 1..6).
CONSTRUCTION_BASE = [0.0, 20.0, 100.0, 500.0, 150.0, 300.0, 180.0]


def game_compute_price(level, base_value, city_price_factor=0.0,
                       city_tax_factor=0.0):
    """Game_ComputePrice 0x4E4060.

    ``round((100 - 3*(city54 + city3C)) * base[level] * base_value * 0.01)``
    with the game's truncating Math_RoundFloat.
    """
    if level < 1 or level > 6:
        level = 1
    value = ((100 - 3 * (city_price_factor + city_tax_factor))
             * CONSTRUCTION_BASE[level] * base_value * 0.01)
    return int(value) if value >= 0 else -int(-value)


def construction_order_price(level, base_value, city_price_factor=0.0,
                             city_tax_factor=0.0):
    """Full construction-order price before installments.

    Game_ComputeCityPriceShare 0x47F230 returns the full Game_ComputePrice
    value while the order progress is 0, then 25% shares during the build.
    """
    return game_compute_price(level, base_value, city_price_factor,
                              city_tax_factor)


def market_weighted_unit_price(market_prices, usages):
    """Market_ComputeWeightedAveragePrice 0x48C060 (price part).

    The game sums ``market_price[i] * usage[i] * 0.001`` across active
    companies and divides by the total usage count.
    """
    weighted = 0.0
    total = 0
    for price, usage in zip(market_prices, usages):
        weighted += float(price) * int(usage) * 0.001
        total += int(usage)
    if total == 0:
        return 0.0
    return weighted / total


def derive_recipe_usage(unit_cost, count=3):
    """Derive an ingredient usage vector from the loaded market table.

    The game stores explicit recipe toppings; the headless recipes carry only
    a unit cost, so pick the ``count`` ingredient prices closest to an equal
    share of that cost.  Quantity weights come from Size.tab's first size tier.
    """
    if not MARKET_RECORDS:
        return {0: 1}
    target = float(unit_cost) / max(1, count)
    order = sorted(range(len(MARKET_RECORDS)),
                   key=lambda i: abs(MARKET_RECORDS[i]["price"] - target))
    usage = {}
    for i in order[:count]:
        amounts = MARKET_RECORDS[i].get("amounts", [1])
        usage[i] = max(1, int(amounts[0]) // 10)
    return usage


def weighted_order_cost(quantity, unit_price, market_prices, usages):
    """Order cost in Market_ComputeWeightedAveragePrice 0x48C060."""
    return (market_weighted_unit_price(market_prices, usages)
            * float(unit_price) * float(quantity))


def c_div(a, b):
    """C integer division: truncate toward zero."""
    a, b = int(a), int(b)
    if b == 0:
        return 0
    q = abs(a) // abs(b)
    return q if (a >= 0) == (b > 0) else -q


def company_percent_modifier(plan_type, budget):
    """Company_GetPercentModifier 0x50F7F0 for a game plan."""
    if plan_type == 1:
        return c_div(budget * 100, 10000)
    if plan_type == 2:
        return c_div(budget * 100, 5000)
    return 100


def advertising_effect(media_type, category, metric=50, competitor=50,
                       city_term=100, percent=100, flags=0,
                       competitor_metric=None):
    """GamePlan_ComputeCategoryEffect/ComputeEffectValue (0x50F870/0x50FBA0)."""
    media_type = max(1, min(12, media_type))
    category = max(0, min(7, category))
    effect = (AD_WEIGHTS[media_type][category] + 8) * 5
    metric = int(metric)
    competitor = int(competitor_metric if competitor_metric is not None
                     else competitor)
    for bit in (1, 2, 4, 8):
        if not (flags & bit):
            continue
        low = competitor - 5
        high = competitor + 5
        if metric < low:
            effect -= (low - metric) >> 2
        if metric > high:
            effect += (metric - high) >> 1
    effect = c_div(city_term * (c_div(percent * (effect - 40), 100) + 40),
                   100)
    return clamp_int(effect)


def plan_category_metric(branch, group, flag):
    """GamePlan_GetCompanyCategoryMetric 0x50FAB0."""
    if flag == 1:
        return int(branch.price_rating[group])
    if flag == 2:
        return int(branch.menu_rating[group])
    if flag == 4:
        return int(building_score_for_group(
            group, branch.facilities, branch.floor_value, branch.staff_value))
    if flag == 8:
        return int(branch.avg8[group])
    return 0


def plan_category_effect(plan_type, media, flags, owner, target_branch,
                         target_company, category, city_term=25, percent=100):
    """GamePlan_ComputeCategoryEffect 0x50F870 for one category."""
    if not owner.branches:
        return 0
    effect = 40 if media == 0 else (AD_WEIGHTS[media][category] + 8) * 5
    for bit in (1, 2, 4, 8):
        if not (flags & bit):
            continue
        lower, upper = 45, 55
        if target_company is not None and target_company.branches:
            vals = [plan_category_metric(b, category, bit)
                    for b in target_company.branches]
            avg = sum(vals) // len(vals)
            lower, upper = avg - 5, avg + 5
        if plan_type in (2, 3):
            own = (plan_category_metric(target_branch, category, bit)
                   if target_branch is not None else 0)
        else:
            vals = [plan_category_metric(b, category, bit)
                    for b in owner.branches]
            own = sum(vals) // len(vals) if vals else 0
        if own < lower:
            effect -= (lower - own) >> 2
        if upper < own:
            effect += (own - upper) >> 1
    inner = c_div(percent * (effect - 40), 100) + 40
    return clamp_int(c_div(city_term * inner, 100))


def plan_average_effect(plan_type, media, flags, owner, target_branch,
                        target_company, city_term=25, percent=100):
    """GamePlan_ComputeAverageEffect 0x50F840: sum(8 cats) >> 3."""
    if not owner.branches:
        return 0
    total = sum(
        plan_category_effect(plan_type, media, flags, owner, target_branch,
                             target_company, category, city_term, percent)
        for category in range(8))
    return total >> 3


def game_get_adjusted_value(ad_value, value_factor=100, city_term=25,
                            bonus=0, base_value=0):
    """Game_GetAdjustedValue 0x4E4490 for the animated ad component.

    ``value_factor`` is City+0xD40[owner] (default 100). ``city_term`` is
    City+0x64 + City+0x4C (Berlin 25 -> x1.75). The mission multipliers are
    human-only and omitted for AI companies.
    """
    v0 = int(ad_value) + int(bonus) + int(base_value)
    factor = max(0, 100 - c_div(100 - int(value_factor), 3))
    v0 = int(v0 * math.sqrt(factor * 0.01))
    v0 = c_div(v0 * (100 + 3 * int(city_term)), 100)
    if base_value > 0 and v0 < 60:
        v0 = 60
    return min(v0, 500)


def plan_effect_value(average_effect):
    """GamePlan_ComputeEffectValue 0x50FBA0 (V-shaped, 0..108)."""
    if average_effect < 40:
        return 40 - average_effect
    return int((average_effect - 40) * 1.8)


def optimize_advertising_plan(company, branch=None, competitors=None,
                             city_term=25, plan_type=3):
    """GamePlan_Optimize 0x4FE5F0: budget, category, media, flags, target."""
    budgets = {1: 10000, 2: 5000, 3: 3500}
    budget = budgets.get(plan_type, 3500)
    empty = {"plan_type": plan_type, "budget": 0, "media_type": 0,
             "category": 0, "flags": 0, "target": -1, "effect": 0,
             "percent": company_percent_modifier(plan_type, budget),
             "city_term": city_term, "allowed": False}
    if plan_type == 1 and (company.level < 3 or len(company.branches) < 3):
        return empty
    if branch is None:
        branch = company.branches[0] if company.branches else None
    if branch is None:
        return empty
    category = 0
    if any(company.product_usage):
        category = max(range(len(company.product_usage)),
                       key=lambda i: company.product_usage[i]) + 1
    competitors = list(competitors or [])
    percent = company_percent_modifier(plan_type, budget)
    baseline = plan_average_effect(
        plan_type, 0, 0, company, branch, None, city_term, percent)
    best_media, best_gain = 0, 0
    for media in range(1, 13):
        effect = plan_average_effect(
            plan_type, media, 0, company, branch, None, city_term, percent)
        gain = effect - baseline
        if media == 1 or gain > best_gain:
            best_media, best_gain = media, gain
    if best_gain < 1:
        media_type, current = 0, baseline
    else:
        media_type, current = best_media, baseline + best_gain
    flags = 0
    for bit in (1, 2, 4, 8):
        trial = flags | bit
        effect = plan_average_effect(
            plan_type, media_type, trial, company, branch, None,
            city_term, percent)
        if effect - current >= 1:
            flags = trial
            current = effect
    target, best_target_gain = -1, 0
    for other in competitors:
        effect = plan_average_effect(
            plan_type, media_type, flags, company, branch, other,
            city_term, percent)
        gain = effect - current
        if gain > best_target_gain:
            best_target_gain = gain
            target = other.id
    return {
        "plan_type": plan_type,
        "budget": budget,
        "media_type": media_type,
        "category": category,
        "flags": flags,
        "target": target,
        "effect": current,
        "percent": percent,
        "city_term": city_term,
        "allowed": True,
    }

# Game_ComputeTradeOffers 0x4D5DD0 constants.
TRADE_TYPE_BASE = {1: 5000, 2: 6000, 3: 4000, 4: 3000}
SPECIAL_RENT_TABLES = {1: (300, 600, 1200), 3: (200, 400, 800)}
MISSION_FACTORS = {"none": 1.0, "free": 0.0, "half": 0.5, "bonus": 1.5}
MISSION_FIELDS = {
    1: {"free": 0xC0, "half": 0x120, "bonus": 0x1A4},
    2: {},
    3: {"free": 0x15C, "half": 0x14C, "bonus": 0x230},
    4: {"free": 0x15C, "half": 0x14C, "bonus": 0x230},
}
SPECIAL_MISSION_FIELDS = {"free": 0x10C, "half": 0xFC, "bonus": 0x1E0}


def math_round_float(value):
    """Math_RoundFloat 0x54F140: x87 truncation toward zero."""
    return int(value)


def trade_offer_base(nearby_a=0, nearby_b=0, special_nearby=False):
    """Map_CountNearbyObjects 0x4D5CF0 base value."""
    base = float(nearby_a) * 0.1 + float(nearby_b) * 0.25 + 1.0
    if special_nearby:
        base *= 1.75
    return base


def city_price_adjust(city_factor=60):
    """1 + (60 - city+0xCC8[slot]) * 0.005; 60 is neutral."""
    return 1.0 + (60.0 - float(city_factor)) * 0.005


def trade_offer_price(offer_type, building_value=0.0, purchase_factor=1.0,
                      usage_count=0, nearby_a=0, nearby_b=0,
                      special_nearby=False, city_factor=60,
                      mission="none", current_player=True, visible=True):
    """Game_ComputeTradeOffers 0x4D5DD0 non-special path.

    ``purchase_factor`` is City+0x94 = KAUFPREIS * 0.02.
    Returns the two outputs: ``buy`` (*param_4) and ``sell`` (return value).
    """
    type_base = TRADE_TYPE_BASE.get(offer_type, 0)
    if not visible:
        # Game_CanShowObject == 0: buy price stays 0, sell stays type_base.
        return {"buy": 0, "sell": int(type_base)}
    base = trade_offer_base(nearby_a, nearby_b, special_nearby)
    if offer_type == 2:
        base = 0.0
        value = 0.0
    else:
        value = float((int(usage_count) + 6) * int(building_value) // 20)
    price = value - math_round_float(base * -5000.0)
    price = math_round_float(price * float(purchase_factor))
    price += math_round_float(price * city_price_adjust(city_factor))
    price += math_round_float(type_base * float(purchase_factor))
    sell = math_round_float(type_base * float(purchase_factor))
    if current_player:
        # Type 2 falls through to the default multiplier 1.0.
        factor = (MISSION_FACTORS.get(mission, 1.0)
                  if offer_type in (1, 3, 4) else 1.0)
        price = math_round_float(price * factor)
        sell = math_round_float(type_base * factor)
    return {"buy": int(price), "sell": int(sell)}


def special_trade_offer(offer_type, base_index=0, rent_factor=1.0,
                        object_flag=True, nearby_a=0, nearby_b=0,
                        special_nearby=False, city_factor=60,
                        mission="none", current_player=True):
    """Game_ComputeTradeOffers 0x4D5DD0 special-ID rent path.

    Type 1 ids 0x84C..0x857 use 300/600/1200; type 3 ids 0x840..0x84B use
    200/400/800. ``rent_factor`` is City+0x8C = MIETEN * 0.02.
    The rent is only offered when object+0x4C is non-zero.
    """
    table = SPECIAL_RENT_TABLES.get(offer_type)
    if table is None or not object_flag:
        return 0
    index = max(0, min(2, int(base_index)))
    base = trade_offer_base(nearby_a, nearby_b, special_nearby)
    rent = math_round_float(table[index] * base)
    rent = math_round_float(rent * float(rent_factor))
    rent += math_round_float(rent * city_price_adjust(city_factor))
    if current_player:
        rent = math_round_float(rent * MISSION_FACTORS.get(mission, 1.0))
    return int(rent)

@dataclass
class Branch:
    id: int
    company_id: int
    city_index: int = 0
    recipes: list[Recipe] = field(default_factory=list)
    avg8: list[int] = field(default_factory=lambda: [55] * 8)
    menu_rating: list[int] = field(default_factory=lambda: [55] * 8)
    price_rating: list[int] = field(default_factory=lambda: [55] * 8)
    building_rating: int = 55
    facilities: dict = field(default_factory=lambda: dict(DEFAULT_FACILITIES))
    floor_value: int = 0
    staff_value: int = 0
    price_level: int = 3
    level: int = 0
    price_adjust: int = 0
    quality_adjust: int = 0
    city_levels: list[int] = field(default_factory=lambda: [3] * 6)
    city_prefs: list[float] = field(default_factory=lambda: [50.0] * 8)
    staff: int = 8
    capacity: int = 40
    quality: int = 55
    marketing: float = 0.0
    rent_monthly: float = 2500.0
    size_class: int = 2
    branch_type: int = 0x0F
    x: float = 500.0
    y: float = 500.0
    radius: float = 500.0
    taste_a: int = 0
    taste_b: int = 0
    stock: float = 400.0
    stock_capacity: float = 400.0
    batches: list[Batch] = field(default_factory=list)
    supplier: bool = True
    delivery_pending: int = 0
    delivery_delay: int = 0
    reorder_threshold: float = 0.34
    delivery_vehicles: int = 1
    storage_level: int = 0
    supplier_node: int | None = None
    storage_node: int | None = None
    convoy: VehicleConvoy | None = None
    vehicles_out: int = 0
    city_price_factor: float = 0.0
    city_tax_factor: float = 0.0
    supplier_base_price: float = 0.0
    units_delivered: float = 0.0
    units_consumed: float = 0.0
    open_hours: list[bool] = field(
        default_factory=lambda: [10 <= h < 22 for h in range(24)])
    queue_capacity: int = 40
    queue: list[Customer] = field(default_factory=list)
    pedestrian_sources: int = 1
    construction_orders: list[ConstructionOrder] = field(default_factory=list)
    construction_level: int = 3
    construction_value: float = 100.0
    path_node: int | None = None
    ad_plans: list[AdvertisingPlan] = field(default_factory=list)
    served: int = 0
    lost: int = 0
    revenue: float = 0.0
    costs: float = 0.0
    customers_today: int = 0
    year_income: float = 0.0
    year_expenses: float = 0.0
    yearly_profit: dict = field(default_factory=dict)
    stat_start_year: int = 1
    opened: bool = True
    menu_ready: bool = True
    guards: int = 0
    security: int = 0
    flags: int = 0
    exterminator_tier: int = 0
    free_construction_slots: int = 1
    assigned_recipe: int | None = None
    ad_value: float = 0.0
    rating_factor: int = 100
    city_income_factor: float = 1.3
    city_rating_phase: float = 3.0
    city_recent: list | None = None
    city_food_taste: list | None = None
    price_competitive: int = 1
    topping_orientations: list | None = None
    approach_objects: list = field(default_factory=list)
    style: str = "einf"
    layout_iso: str | None = None
    sim: object | None = None
    ad_bonus: int = 0
    ad_base_value: int = 0
    type3_ad_groups: set = field(default_factory=set)
    type2_ad_effect: list = field(default_factory=lambda: [0] * 8)
    renovation_level: int = 0
    price_percent: float = 100.0
    price_offset: float = 0.0
    building_value: float = 1.0

    def record_income(self, amount):
        self.year_income += amount

    def record_expense(self, amount):
        self.year_expenses += amount

    def plan_scores(self, current_year, count=4):
        """AI_ComputePlanScores 0x4F7B90: newest full year first."""
        scores = []
        year = int(current_year) - 1
        while year >= self.stat_start_year and len(scores) < count:
            scores.append(round(self.yearly_profit.get(year, 0.0), 2))
            year -= 1
        return scores

    def group_rating(self, group: int, price_comparison=True):
        base = self.avg8[group]
        menu = city_adjust(self.menu_rating[group], self.taste_a, self.taste_b)
        score = base + self.building_rating + menu
        div = 3
        if price_comparison:
            ad = self.type2_ad_effect[group]
            if ad:
                # Branch_GetPriceComparisonRating: type-2 plan component.
                score += ad
            else:
                score += city_adjust(self.price_rating[group],
                                     self.taste_a, self.taste_b)
            div = 4
        building = building_score_for_group(
            group, self.facilities, self.floor_value, self.staff_value)
        return clamp(building + score // div)

    def batch_unit_cost(self):
        base = self.supplier_base_price
        if base <= 0:
            base = (self.recipes[0].unit_cost / 1.5) if self.recipes else 2.6667
        return batch_unit_cost(
            base, self.facilities.get(0x1A, 1), 1.5, 0.0,
            self.city_price_factor, self.city_tax_factor)

    def construction_price(self):
        """Game_ComputePrice for this branch's construction order."""
        return construction_order_price(
            self.construction_level, self.construction_value,
            self.city_price_factor, self.city_tax_factor)

    def recipe_price(self, recipe):
        """Branch_ComputeRecipePrice 0x513BF0."""
        base = recipe.base_price if recipe.base_price is not None else recipe.price
        return (base * self.price_percent * 0.01 * self.building_value
                + self.price_offset)

    def auto_tune_price(self, group_weights=None, percent_rng=None):
        """Branch_AutoTunePrice 0x4FF6E0.

        ``+0x14AC`` is the additive price offset.  The search target is
        ``sum(weights)*4//5``; ratings 30..49 contribute
        ``(rating-30)*weight//20`` and ratings >=50 contribute the full weight.
        Out-of-range offsets reset to 10, step starts at 16 and halves on a
        direction change.
        """
        if not (50 <= self.price_percent <= 150):
            # The game randomizes 0x32..0x96 and clears +0x1714.
            self.price_percent = (percent_rng(50, 150)
                                  if percent_rng is not None else 100)
        weights = [int(w) if float(w).is_integer() else w
                   for w in (group_weights or [1] * 8)]
        target = int(sum(weights) * 4 / 5)
        offset = int(self.price_offset)
        step = 16
        direction = 0
        while True:
            weighted = 0
            for g, w in enumerate(weights):
                rating = self.group_rating(g, price_comparison=False)
                if rating >= 50:
                    weighted += w
                elif rating > 30:
                    if isinstance(w, int):
                        weighted += ((rating - 30) * w) // 20
                    else:
                        weighted += (rating - 30) * w / 20.0
            if target < weighted:
                if direction == -1:
                    step >>= 1
                direction = 1
                delta = step
            else:
                if target <= weighted:
                    return offset
                if direction == 1:
                    step >>= 1
                direction = -1
                delta = -step
            offset += delta
            if offset < 0 or offset > 99:
                offset = 10
                break
            self.price_offset = offset
            if step < 2:
                break
        self.price_offset = offset
        return offset

    def price_index(self):
        if not self.recipes:
            return 1.0
        return sum(self.recipe_price(r) for r in self.recipes) / len(self.recipes) / 12.0

    def update_ratings(self, market_price_index=1.0):
        pidx = self.price_index()
        avg_price = pidx * 12.0
        coverage = min(1.0, self.staff / max(1, self.capacity / 5))
        price_skills = game_compute_skill_ratings(
            self.city_income_factor, self.level, avg_price,
            self.city_rating_phase)
        if self.recipes:
            if self.sim is not None:
                self.price_competitive = self.sim.recipe_price_competitive(
                    self.recipes[0], self.company_id)
            bases = []
            for r in self.recipes:
                avg = r.weighted_averages()
                market = r.market_factor_scores(
                    avg, self.city_food_taste, self.price_competitive)
                bases.append(r.base_skill_ratings(
                    market, avg, self.city_food_taste,
                    self.price_competitive, r.orientation_deltas(self)))
            base_skills = [sum(b[g] for b in bases) // len(bases)
                           for g in range(8)]
        else:
            base_skills = [55] * 8
        skills = [clamp(base_skills[g] + price_skills[g])
                  for g in range(8)]
        for g in range(8):
            expected = 12.0 + (self.city_prefs[g] - 50.0) * 0.02
            pr = price_rating(avg_price, expected)
            adj = market_value_adjustment(
                g, self.price_level, self.city_levels,
                self.price_adjust, self.quality_adjust,
                self.city_prefs[g], avg_price)
            product = company_product_score(
                [self.quality, 50, 50], min(4, self.staff // 3), skills[g] + adj)
            self.price_rating[g] = clamp(pr)
            self.menu_rating[g] = clamp(min(pr, (product + 10) // 2))
            self.avg8[g] = clamp(skills[g] + coverage * 10)
        factor = max(0, int(self.rating_factor))
        if factor != 100:
            for g in range(8):
                self.avg8[g] = clamp(self.avg8[g] * factor // 100)
                self.menu_rating[g] = clamp(self.menu_rating[g] * factor // 100)
                self.price_rating[g] = clamp(self.price_rating[g] * factor // 100)
        self.building_rating = clamp(int(
            25 + self.quality * 0.25 + coverage * 10 + self.marketing * 5
            - max(0, pidx - 1) * 10) * factor // 100)
        self.staff_value = int(self.staff * 60 + self.quality)


@dataclass
class Company:
    id: int
    name: str
    cash: float = 250000.0
    marketing_budget: float = 1000.0
    ledger: list[float] = field(default_factory=lambda: [0.0] * LEDGER_SIZE)
    revenue_total: float = 0.0
    period_revenue: float = 0.0
    period_profit: float = 0.0
    profit_history: list[float] = field(default_factory=list)
    strategy_type: int = 0
    product_usage: list[int] = field(default_factory=lambda: [0] * 86)
    plan_actions: list = field(default_factory=list)
    ai_personality: int = 0
    last_action: int = 0
    gangsters: int = 0
    advancement_score: int = 0
    annoy_cooldown: int = 0
    level: int = 0
    security_need: int = 1
    reserve_guards: int = 0
    mission_completions: dict = field(default_factory=dict)
    last_sales_refresh: int = 0
    menu_prune_policy: bool = False
    ad_plans: list = field(default_factory=list)
    net_stat_history: list = field(default_factory=list)
    storage_level: int = 0
    storage_mode: str = "rent"
    cost_multiplier: float = 1.0
    campaign_wins: int = 0
    trait_a: int = 0
    trait_b: int = 0

    @property
    def rating_factor(self):
        """(100 - 3*(Player+0x5C + Player+0x44)); serialized player fields."""
        return max(0, 100 - 3 * (int(self.trait_a) + int(self.trait_b)))
    last_quarter_share: float = 0.0
    lifetime_revenue: float = 0.0
    total_revenue: float = 0.0
    total_costs: float = 0.0
    branches: list[Branch] = field(default_factory=list)

    def charge(self, category: int, amount: float):
        self.ledger[category] += amount
        self.cash -= amount
        self.total_costs += amount
        self.period_profit -= amount

    def earn(self, category: int, amount: float):
        self.ledger[category] += amount
        self.cash += amount
        self.total_revenue += amount
        self.period_profit += amount


@dataclass
class Character:
    """Character_Construct 0x4D3730 rating inputs."""

    c4: int
    c8: int
    c12: int
    c16: int
    state: int
    flagged: bool = False

    @classmethod
    def create(cls, rng):
        # Random_RangeFast(0x1E, 0x46) and (0x12, 0x3C), inclusive.
        return cls(rng.randint(30, 70), rng.randint(30, 70),
                   rng.randint(30, 70), rng.randint(30, 70),
                   rng.randint(18, 60), False)

    def composite(self):
        return rating_composite(self.c4, self.c8, self.c12, self.c16,
                                self.state, self.flagged)

    def party_size(self):
        return (self.composite() >> 4) + 1


@dataclass
class Customer:
    group: int
    price_tolerance: float = 1.0
    branch_id: int = -1
    threshold: int = 40
    scores: list[int] = field(default_factory=lambda: [0] * 6)
    x: float = 500.0
    y: float = 500.0
    target_branch: int = -1
    arrival_hour: int = 0
    arrival_tick: int = 0
    arrival_ms: int = 0
    travel_ms: int = 0
    path_cells: int = 0
    path_node: int | None = None
    party_size: int = 1
    character: Character | None = None


class CompanyAI:
    """AI controller using the decoded action/step tables and plan queue."""

    def __init__(self, aggression=1.0):
        self.aggression = aggression
        self.company_strategy = 0

    # ---------------------------------------------------------------- selection
    def select_action_type(self, rng):
        """AI_SelectActionForType 0x502B80."""
        strategy = self.company_strategy
        if strategy == 0:
            return "random"
        if strategy == 1:
            return "expansion"
        if strategy == 2:
            return "strategy"
        roll = rng.randrange(300) if strategy == 6 else rng.randrange(100)
        if strategy == 3:
            return "random" if roll < 50 else "expansion"
        if strategy == 4:
            return "expansion" if roll < 50 else "strategy"
        if strategy == 5:
            return "strategy" if roll < 50 else "random"
        if strategy == 6:
            if roll < 100:
                return "random"
            if roll < 200:
                return "expansion"
            return "strategy"
        return "random"

    def choose_plan_action(self, group, personality, rng):
        """Pick from DAT_005726DC/0057273C/0057279C and step tables."""
        personality = max(0, min(3, int(personality)))
        if group == "random":
            actions, steps = PLAN_ACTION_RANDOM, PLAN_STEPS_RANDOM
        elif group == "expansion":
            actions, steps = PLAN_ACTION_EXPANSION, PLAN_STEPS_EXPANSION
        else:
            actions, steps = PLAN_ACTION_STRATEGY, PLAN_STEPS_STRATEGY
        choice = rng.randrange(4)
        action = actions[personality][choice]
        step_count = steps[personality][choice]
        if action >= 0x18:
            return None, 0
        return action, step_count

    @staticmethod
    def plan_step_weight(action, branch_count=0, needs_supplier=False):
        """Game_AssignPlanStepWeight 0x5012D0."""
        if action == 4:
            return 80
        if action == 5:
            return 20
        if action == 6:
            return branch_count * 20
        if action == 7:
            return 0
        if action == 8:
            return 100
        if action == 10:
            return 200
        if action == 11:
            return 40
        if action == 12:
            return 200 if needs_supplier else 20
        if action in (9, 13, 15):
            return 20
        if action == 14:
            return branch_count * 5
        if action in (16, 17):
            return 50
        if action == 18:
            return 10
        if 19 <= action <= 23:
            return 30
        return 0

    # ---------------------------------------------------------------- scoring
    def branch_plan_scores(self, company, current_year, count=4):
        return [(b, b.plan_scores(current_year, count))
                for b in company.branches]

    def plan_scores(self, company, start=0, count=4, current_year=None):
        """AI_ComputePlanScores 0x4F7B90: yearly profit, newest first."""
        if company.branches:
            year = current_year
            if year is None:
                year = max((max(b.yearly_profit) for b in company.branches
                            if b.yearly_profit), default=1) + 1
            rows = [b.plan_scores(year, count) for b in company.branches]
            width = max((len(r) for r in rows), default=0)
            out = []
            for i in range(width):
                vals = [r[i] for r in rows if i < len(r)]
                out.append(round(sum(vals) / len(vals), 2))
            return out[start:start + count]
        return [round(v, 2) for v in company.profit_history[start:start + count]]

    def select_best_plan_target(self, sim, company, action_type=2, rng=None):
        """Target scoring: lowest yearly profit branch is the plan target."""
        if not company.branches:
            return -1
        rows = self.branch_plan_scores(company, sim.year)
        if action_type == 2:
            filtered = [(b, s) for b, s in rows if b.group_rating(0) < 70]
            if filtered:
                rows = filtered

        def key(item):
            branch, scores = item
            avg = sum(scores) / len(scores) if scores else 0.0
            return (avg, branch.id)

        return min(rows, key=key)[0].id

    # ---------------------------------------------------------------- queue
    def push_action(self, company, action, target=-1, ttl=5, steps=1):
        """Company_PushRecentEntry 0x500F40 (newest first, max 10)."""
        company.plan_actions = [
            a for a in company.plan_actions
            if not (a.action == action and a.target == target)
        ]
        company.plan_actions.insert(
            0, PlanAction(action, target, ttl, steps))
        company.plan_actions = company.plan_actions[:10]
        company.last_action = action
        return company.plan_actions[0]

    def execute_next_action(self, sim, company):
        """Company_ExecuteAction 0x5016C0 queue semantics."""
        if not company.plan_actions:
            return None
        act = company.plan_actions[0]
        decision, success = self.execute_action(
            sim, company, act.action, act.target, act.steps)
        if success or act.ttl <= 1:
            if act in company.plan_actions:
                company.plan_actions.remove(act)
        else:
            act.ttl -= 1
        return decision

    def execute_action(self, sim, company, action, target=-1, steps=1):
        branch = next((b for b in company.branches if b.id == target), None)
        name = PLAN_ACTION_NAMES.get(action, f"action_{action}")

        if action >= 24:
            # AI_InitActionPlan mission-plan id; not a Company_ExecuteAction code.
            return ("mission_plan", action), True
        if action in (5, 22):
            return self._expand(sim, company), True
        if action == 11:
            return self._city_tick(sim, company), True
        if action == 13:
            return self._guard_action(sim, company), True
        if action == 16:
            return self._annoy_action(sim, company), True
        if action == 17:
            return self._gangster_action(sim, company), True
        if action == 21:
            return self._advancement_action(sim, company), True
        if action == 12:
            return self._supplier_action(sim, company), True
        if branch is None:
            return None, False
        if action == 7:
            branch.update_ratings()
            branch.menu_ready = True
            return ("validate_menu", branch.id), True
        if action == 8:
            branch.marketing = max(branch.marketing, 0.12)
            return ("customer_visit", branch.id), True
        if action == 10:
            branch.opened = True
            return ("open_branch", branch.id), True
        if action == 19:
            return self._price_action(sim, company, branch), True
        if action == 20:
            return self._security_action(sim, company, branch), True
        if action == 23:
            return self._ad_action(sim, company, branch), True
        return ((name, branch.id), True)

    def _expand(self, sim, company):
        expansion_cost = sim.branch_expansion_cost()
        if (company.cash <= max(150000 / self.aggression, expansion_cost)
                or len(company.branches) >= 4):
            return None
        b = sim.add_branch(
            company.id,
            recipes=[Recipe("New Branch", 12.0, 4.0, 55)],
            staff=8, quality=55, capacity=35, rent_monthly=2500,
            size_class=2,
            x=300 + 200 * len(company.branches),
            y=300 + 150 * len(company.branches),
            radius=360,
            construction_level=3, construction_value=100.0)
        b.opened = False
        b.menu_ready = False
        b.supplier = False
        b.stat_start_year = sim.year
        company.charge(3, expansion_cost)
        # Player_CreateBranch 0x4F7420 setup sequence.
        self.push_action(company, 12, b.id, 5, 1)
        self.push_action(company, 7, b.id, 5, 1)
        self.push_action(company, 8, b.id, 5, 1)
        self.push_action(company, 10, b.id, 5, 1)
        return ("expand", b.id)

    def _price_action(self, sim, company, branch):
        if not branch.recipes:
            return ("price_hold", branch.id)
        rating = branch.group_rating(0)
        competitor = [b.group_rating(0) for c in sim.companies
                      if c.id != company.id for b in c.branches]
        comp_avg = (sum(competitor) / len(competitor)
                    if competitor else rating)
        before = branch.price_offset
        weights = [int(round(x * 100)) for x in sim.group_shares]
        after = branch.auto_tune_price(weights)
        if after > before:
            return ("price_up", branch.id)
        if after < before:
            return ("price_down", branch.id)
        return ("price_hold", branch.id)

    def _ad_action(self, sim, company, branch):
        if company.cash < 0:
            for b in company.branches:
                b.ad_plans.clear()
            return ("ads_stop", company.id)
        if branch.group_rating(0) < 70 and company.cash > 60000:
            if not any(p.plan_type == 3 for p in branch.ad_plans):
                sim.optimize_advertising(branch, plan_type=3)
                return ("ads_start", branch.id)
        return ("ads_hold", branch.id)

    def _city_tick(self, sim, company):
        """City_TickBranches 0x4FC630: action 11 dispatcher.

        Order: pest-control coverage for all branches, stalled-order cleanup,
        one flagged branch (2 -> 0x10 -> 0x20 -> 4), then the 24h sales refresh.
        Supplier/storage work belongs to action 12 and is not touched here.
        """
        weights = [int(round(x * 100)) for x in sim.group_shares]
        decisions = []

        # Step A: City_EnsurePedestrianCoverage 0x4FD520.
        for b in company.branches:
            if not b.opened or b.exterminator_tier or b.pedestrian_sources <= 0:
                continue
            tier = 1 if company.cash <= 30000.0 else 2
            amount = 1000.0 if tier == 1 else 10000.0
            company.charge(5, amount)
            b.record_expense(amount)
            b.exterminator_tier = tier
            decisions.append(("exterminator", b.id))

        # Step B: Game_GetBestObject(b,1,0x22) 0x47F2E0 cleanup.
        for b in company.branches:
            if not b.opened or b.free_construction_slots > 0:
                continue
            cleared = [o for o in b.construction_orders
                       if o.progress_pct < 34]
            if not cleared:
                continue
            amount = 0.0
            for o in cleared:
                pct = o.progress_pct
                if pct < 1:
                    amount += o.cost
                else:
                    amount += o.cost * (1.0 - 0.01 * pct) * 0.25
            company.charge(5, amount)
            b.record_expense(amount)
            for o in cleared:
                b.construction_orders.remove(o)
            decisions.append(("construction_cleanup", b.id))

        # Step C: one flagged branch, ascending, priority 2/0x10/0x20/4.
        for b in company.branches:
            if not b.opened:
                continue
            if b.flags & 0x02:
                # Branch_ValidateMenuAndRecalculate 0x4F7C30.
                if not b.recipes:
                    b.staff = 0
                elif not b.menu_ready:
                    b.menu_ready = True
                b.flags &= ~0x02
                b.auto_tune_price(weights)
                decisions.append(("validate_menu", b.id))
                break
            if b.flags & 0x10:
                # Company_OpenBranchAtSite 0x4FC0F0 product creation.
                cap = min(len(company.branches) + 16, 20)
                active = sum(len(x.recipes) for x in company.branches)
                if b.assigned_recipe is None:
                    if not b.recipes:
                        b.recipes.append(Recipe.random_construct(
                            sim.rng, name="Generated", price=12.0))
                    b.assigned_recipe = 0
                    b.menu_ready = True
                    b.flags &= ~0x20
                    sim.rebuild_company_usage(company.id)
                    decisions.append(("assign_product", b.id))
                elif active >= cap:
                    b.flags &= ~0x10
                    decisions.append(("menu_cap", b.id))
                else:
                    b.recipes.append(Recipe.random_construct(
                        sim.rng, name="Generated", price=12.0))
                    sim.rebuild_company_usage(company.id)
                    decisions.append(("add_product", b.id))
                break
            if b.flags & 0x20:
                b.auto_tune_price(weights)
                decisions.append(("price_tune", b.id))
                break
            if b.flags & 0x04:
                # Customer_VisitBranch 0x4FB660 AI path.
                refund = sum(o.paid for o in b.construction_orders)
                if refund:
                    company.earn(21, refund)
                    b.record_income(refund)
                b.construction_orders.clear()
                b.flags &= ~0x04
                b.update_ratings()
                decisions.append(("rebuild", b.id))
                break

        # Step D: Company_RefreshMenuSalesIfDue 0x4FC5F0 (24h).
        now = sim.day * 24 + sim.hour
        if now >= company.last_sales_refresh:
            company.last_sales_refresh = now + 24
            recipes = [r for b in company.branches for r in b.recipes]
            if company.menu_prune_policy and recipes:
                mean = sum(r.sales for r in recipes) / len(recipes)
                for b in company.branches:
                    for r in list(b.recipes):
                        if len(b.recipes) > 1 and r.sales < mean / 2.0:
                            b.recipes.remove(r)
                sim.rebuild_company_usage(company.id)
            for r in recipes:
                r.sales = 0.0
            decisions.append(("sales_refresh", company.id))
        sim.last_city_tick_decisions = decisions
        return ("city_tick", company.id)

    def _supplier_action(self, sim, company):
        """AI_Action_AssignSuppliers 0x4FD190 + AI_EnsureBranchStorage."""
        if not company.branches:
            return ("assign_suppliers", company.id)
        mult = company.cost_multiplier
        if company.storage_level < 1:
            if company.storage_mode == "buy":
                price = sim.storage_buy_price
                company.charge(0, price)       # category 0, forced
            else:
                price = sim.storage_rent_price
                company.charge(2, price)       # category 2, forced
            company.storage_level = 1
        else:
            target = min(len(company.branches) >> 2, 2)
            if company.storage_level < target:
                level = company.storage_level
                # Stats_GetCombinedValue(3, level): level 0 -> 1000,
                # level 1 -> 2000 (0x55C4C4 / 0x55C4D4).
                cost = (1000.0 if level == 0 else 2000.0) * mult
                if company.cash >= cost:
                    company.charge(2, cost)     # category 2, checked
                    company.storage_level += 1
        for b in company.branches:
            b.supplier = True
        return ("assign_suppliers", company.id)

    def _guard_action(self, sim, company):
        """AI_CheckBranchGuards 0x4FE040.

        Guard target per branch = min(cap, round(K*4y_income/(4000*years))+1),
        with K effectively forcing the city cap.  Levels 5/6 add 2/4 guards.
        Hiring has no direct ledger charge in this function.
        """
        cap = max(1, int(sim.guard_cap))
        total_target = 0
        for b in company.branches:
            years = [b.yearly_profit[y] for y in sorted(b.yearly_profit)[-4:]]
            income = sum(max(0.0, b.year_income) for _ in [0])
            if years:
                # Exact structure; the constant clamps to the city cap.
                target = min(cap, int(round(16781057 * income
                                            / (4000.0 * len(years)))) + 1)
            else:
                target = 1
            target = max(1, min(cap, target))
            total_target += target
            while b.guards < target:
                b.guards += 1
        extra = 2 if company.level == 5 else 4 if company.level == 6 else 0
        company.reserve_guards = extra
        total_target += extra
        hired = sum(b.guards for b in company.branches) + extra
        return ("guards", hired)

    def _security_action(self, sim, company, branch):
        """AI_ImproveSecurity 0x4FFAD0: buy one type-2 security building."""
        total = sum(b.security for b in company.branches)
        needed = company.security_need * (total + 1) < sim.security_threat
        offer = trade_offer_price(
            2, purchase_factor=sim.city.purchase_trade_factor)
        price = offer["buy"]
        if total < 5 and needed and company.cash >= price:
            company.charge(2, price)  # Game_CanAffordWithCurrency(...,2,...)
            branch.record_expense(price)
            branch.security += 1
            return ("security", branch.id)
        return ("security_hold", branch.id)

    def _annoy_action(self, sim, company):
        """AI_Action_AnnoyRival 0x4FD610: sabotage a rival branch."""
        if company.annoy_cooldown > sim.day:
            return ("annoy_cooldown", company.id)
        rivals = [b for c in sim.companies if c.id != company.id
                  for b in c.branches]
        if not rivals:
            return ("annoy_none", company.id)
        target = max(rivals, key=lambda b: b.revenue)
        company.annoy_cooldown = sim.day + 30
        if sim.rng.random() < 0.5 and company.cash > 2000:
            company.charge(24, 2000)
            target.quality = max(0, target.quality - 3)
            target.stock *= 0.8
            return ("annoy", target.id)
        return ("annoy_miss", target.id)

    def _gangster_action(self, sim, company):
        """AI_ManageGangsters 0x4FF8B0: maintain protection staff."""
        target = min(3, 1 + len(company.branches) // 2)
        if company.gangsters < target and company.cash > 1000:
            company.charge(24, 1000)
            company.gangsters += 1
            return ("gangsters", company.gangsters)
        return ("gangsters_hold", company.gangsters)

    def _advancement_action(self, sim, company):
        """Game_UpdateCompanyAdvancementScore 0x4F8BF0."""
        rows = [b.plan_scores(sim.year, 4) for b in company.branches]
        avg_scores = [sum(r) / len(r) for r in rows if r]
        avg = sum(avg_scores) / len(avg_scores) if avg_scores else 0.0
        threshold = int(avg * 0.17)
        if (threshold >= company.advancement_score
                and company.cash > 5000):
            company.charge(20, 5000)
            company.advancement_score += 5000
            return ("advancement", company.advancement_score)
        return ("advancement_hold", company.advancement_score)

    def decompose_strategy(self, action):
        """AI_InitActionPlan 0x502CE0: one action id plus a step budget.

        Ids 24..35 are mission-plan action ids.  They are not decomposed into
        Company_ExecuteAction codes; the decoded tables supply only the id and
        its step count.
        """
        if action in MISSION_STRATEGY_ACTION_IDS:
            return [action]
        return [action]

    def push_strategy_plan(self, company, action, target=-1, steps=1):
        self.push_action(company, action, target, 5, steps)
        return [action]

    # ---------------------------------------------------------------- tick
    def weekly(self, sim, company):
        if not company.branches:
            return []
        self.company_strategy = company.strategy_type
        decisions = []
        executed = self.execute_next_action(sim, company)
        if executed:
            decisions.append(executed)

        if company.cash < 0 and any(b.ad_plans for b in company.branches):
            for b in company.branches:
                b.ad_plans.clear()
            decisions.append(("ads_stop", company.id))

        if not company.plan_actions:
            group = self.select_action_type(sim.rng)
            action, steps = self.choose_plan_action(
                group, company.ai_personality, sim.rng)
            if action is not None:
                target = self.select_best_plan_target(sim, company, 2)
                if action in (5, 22):
                    target = -1
                if action >= 24:
                    steps_list = self.push_strategy_plan(
                        company, action, target, steps)
                    if steps_list:
                        decision = self.execute_next_action(sim, company)
                        if decision:
                            decisions.append(decision)
                else:
                    decision, _ = self.execute_action(
                        sim, company, action, target, steps)
                    if decision:
                        decisions.append(decision)
        return decisions


class Simulator:
    def __init__(self, seed=1, city_traffic=3000.0, city_taste=(0, 0),
                 city: CityProfile | None = None):
        self.rng = random.Random(seed)
        self.seed = seed
        self.city = city or CityProfile()
        self.city_traffic = city_traffic * self.city.traffic_scale
        self.city_taste = city_taste
        self.group_shares = self.city.group_shares
        self.companies: list[Company] = []
        self.branches: list[Branch] = []
        self.hour = 0
        self.day = 0
        self.week = 0
        self.quarter = 0
        self.year = 1
        self.quarter_rows = []
        self.total_customers = 0
        self.total_revenue = 0.0
        self.total_costs = 0.0
        self.market_price_index = 1.0
        self.market_prices = list(MARKET_PRICES)
        self.market_price_reference = market_weighted_unit_price(
            self.market_prices, [1] * len(self.market_prices))
        self.choice_mode = "exact"
        self.traffic_mode = "exact"
        self.agents = self._make_agents()
        self.travelers: list[Customer] = []
        self.total_spawned = 0
        self.ai_enabled = True
        self.ai_controllers = {}
        self.ai_log = []
        self.path_graph = None
        self.guard_cap = 2
        self.security_threat = 10
        self.mission_plans: list = []
        self.city_scores: dict = {}
        self.mission_stats: dict = {}
        self.city_company_scores: dict = {}
        self.player_stat_actions: dict = {}
        self.last_city_tick_decisions: list = []
        self.auto_ad_plans = True
        self.city_campaign = {"active": False, "category": 0, "pot": 0,
                              "countdown": 0, "duration": 0}
        self.city_recent = [[-1] * 6 for _ in range(8)]
        self.storage_rent_price = special_trade_offer(
            3, 0, rent_factor=self.city.rent_trade_factor)
        self.storage_buy_price = trade_offer_price(
            3, building_value=0.0,
            purchase_factor=self.city.purchase_trade_factor)["buy"]

    def load_path_graph(self, path):
        """Load the exact .iso street graph for obstacle-aware routing."""
        from iso_tool import PathGraph
        self.path_graph = PathGraph.from_iso(path)
        return self.path_graph

    def assign_path_nodes(self):
        """Map abstract branch coordinates onto the loaded .iso node graph."""
        if self.path_graph is None or not self.branches:
            return
        xs = [n.x for n in self.path_graph.nodes]
        ys = [n.y for n in self.path_graph.nodes]
        min_x, max_x = min(xs), max(xs)
        min_y, max_y = min(ys), max(ys)
        for b in self.branches:
            tx = min_x + (max_x - min_x) * (b.x / 1000.0)
            ty = min_y + (max_y - min_y) * (b.y / 1000.0)
            b.path_node = min(
                range(len(self.path_graph.nodes)),
                key=lambda i: ((self.path_graph.nodes[i].x - tx) ** 2
                               + (self.path_graph.nodes[i].y - ty) ** 2))

    def graph_path_cells(self, start_node, end_node):
        if self.path_graph is None:
            return None
        count, _cost, _path = self.path_graph.shortest_path(
            int(start_node), int(end_node))
        return min(PATH_NODE_CAP, count) if count else None

    def _make_agents(self, count=1200):
        agents = []
        for g, share in enumerate(self.group_shares):
            for _ in range(max(1, int(count * share))):
                agents.append(Customer(
                    group=g,
                    threshold=self.rng.randint(30, 50),
                    scores=[0] * 6,
                    x=self.rng.uniform(0, 1000),
                    y=self.rng.uniform(0, 1000),
                ))
        return agents

    # ---------- setup ----------
    def add_company(self, name, cash=250000.0):
        c = Company(len(self.companies), name, cash,
                    strategy_type=self.rng.randrange(7),
                    ai_personality=self.rng.randrange(4))
        self.companies.append(c)
        if self.auto_ad_plans:
            # Company_ConstructDefault 0x4DD6B0: one company type-1 plan.
            c.ad_plans.append(AdvertisingPlan(
                0, 0, 10000.0, plan_type=1, active=False))
        return c

    def branch_expansion_cost(self, level=3, base_value=100.0):
        """Game_ComputePrice 0x4E4060 for a new branch shell."""
        return construction_order_price(
            level, base_value, self.city.price_factor / 100.0,
            self.city.income_factor / 100.0)

    def rebuild_company_usage(self, company_id):
        company = self.companies[company_id]
        usage = [0] * len(self.market_prices)
        for branch in company.branches:
            for recipe in branch.recipes:
                if recipe.toppings:
                    counters = recipe.usage_counters()
                    for index, quantity in enumerate(counters):
                        usage[index] += quantity
                    continue
                composition = recipe.ingredients
                if composition is None:
                    composition = derive_recipe_usage(recipe.unit_cost)
                for index, quantity in composition.items():
                    if 0 <= int(index) < len(usage):
                        usage[int(index)] += max(0, int(quantity))
        if not any(usage):
            usage[0] = 1
        company.product_usage = usage
        return usage

    def branch_layout_iso(self, branch):
        sizes = {1: "klein", 2: "mittel", 3: "gross"}
        size = sizes.get(int(branch.size_class), "mittel")
        style = branch.style if branch.style in (
            "einf", "rust", "mode", "edel", "roh") else "einf"
        return os.path.join(ROOT, "game", "Isokarten",
                            f"Iso_Filiale_{style}_{size}.iso")

    def generate_branch_layout(self, branch):
        """Populate approach objects from the shipped branch .iso fixture.

        The branch interior maps contain the real floor/kitchen tile positions
        (Layer2 names such as ``FI_EDEL_GROSS_M_L_*`` / ``_K_*``). Objects are
        placed on those tiles; orientation is deterministic from the tile word
        and branch identity. If the map is unavailable, fall back to the
        decoded approach point (266,274) line.
        """
        iso_path = self.branch_layout_iso(branch)
        branch.layout_iso = iso_path
        floor = []
        try:
            from iso_tool import IsoMap
            iso = IsoMap(iso_path)
            for tile in iso.tiles:
                name = tile.layer2 or ""
                if ("_M_L_" in name or "_M_K_" in name
                        or name.startswith("KUECHE")):
                    floor.append((tile.x, tile.y, tile.tile_word))
        except Exception:
            floor = []
        if floor:
            floor.sort(key=lambda item: (item[1], item[0]))
            objects = []
            for i, (x, y, word) in enumerate(floor[:24]):
                objects.append({
                    "slot": i,
                    "x": int(x),
                    "y": int(y),
                    "variant": (int(word) + i + branch.id) % 8,
                    "source": "iso",
                })
            branch.approach_objects = objects
            branch.topping_orientations = [o["variant"] for o in objects]
            return objects
        # Fallback: decoded approach-line origin.
        rng = random.Random(
            0x51A0 + branch.id * 97 + branch.company_id * 13
            + int(branch.x) * 7 + int(branch.y) * 11)
        count = max(1, branch.size_class * 3 + branch.level * 2
                    + branch.staff // 3)
        last = max(1, count - 1)
        objects = []
        for i in range(count):
            t = i / last
            objects.append({
                "slot": i,
                "x": 266 + int((32 + branch.size_class * 8) * t),
                "y": 274 + int((20 + branch.size_class * 6) * t),
                "variant": rng.randrange(8),
                "source": "fallback",
            })
        branch.approach_objects = objects
        branch.topping_orientations = [o["variant"] for o in objects]
        return objects

    def add_branch(self, company_id, recipes=None, **kwargs):
        if "quality" in kwargs:
            kwargs["quality"] = int(kwargs["quality"] * self.city.quality_scale)
        if "rent_monthly" in kwargs:
            kwargs["rent_monthly"] *= self.city.rent_scale
        if "supplier_base_price" not in kwargs:
            cost = (recipes[0].unit_cost / 1.5) if recipes else 2.6667
            kwargs["supplier_base_price"] = cost
        kwargs.setdefault("city_price_factor", self.city.price_factor / 100.0)
        kwargs.setdefault("city_tax_factor", self.city.income_factor / 100.0)
        b = Branch(len(self.branches), company_id,
                   recipes=recipes or [Recipe("Pizza", 12.0, 4.0, 55)],
                   taste_a=0, taste_b=0,
                   **kwargs)
        if "stock" not in kwargs:
            b.stock = b.stock_capacity
        if not b.batches:
            cost = b.recipes[0].unit_cost if b.recipes else 4.0
            b.batches = [Batch(b.stock, cost)]
        self.branches.append(b)
        self.companies[company_id].branches.append(b)
        b.rating_factor = self.companies[company_id].rating_factor
        b.city_income_factor = self.city.income_trade_factor
        b.city_rating_phase = self.city.rating_phase
        b.city_recent = self.city_recent
        b.city_food_taste = self.city.food_taste
        b.sim = self
        self.generate_branch_layout(b)
        if self.auto_ad_plans:
            # Player_AddBranchPlan 0x4DDB80: one branch type-2 plan.
            b.ad_plans.append(AdvertisingPlan(
                0, 0, 5000.0, plan_type=2, active=False))
        self.rebuild_company_usage(company_id)
        return b

    # ---------- ratings / market ----------
    def recompute_market(self):
        prices = [b.price_index() for b in self.branches if b.recipes]
        if prices:
            self.market_price_index = sum(prices) / len(prices)
        for b in self.branches:
            b.update_ratings(self.market_price_index)

    def market_share(self):
        total = sum(c.period_revenue for c in self.companies)
        if total > 0:
            return {c.id: c.period_revenue / total for c in self.companies}
        if any(c.last_quarter_share for c in self.companies):
            return {c.id: c.last_quarter_share for c in self.companies}
        total = sum(c.lifetime_revenue for c in self.companies)
        if total <= 0:
            return {c.id: 1.0 / max(1, len(self.companies)) for c in self.companies}
        return {c.id: c.lifetime_revenue / total for c in self.companies}

    # ---------- demand reconstruction ----------
    def generate_customers(self):
        hour_weight = HOUR_CURVE[self.hour % 24]
        total = int(self.city_traffic / 24.0 * hour_weight
                    + self.rng.random())
        chosen = self.rng.choices(self.agents, k=total)
        # Reconstruction of movement: a customer's position changes between visits.
        for c in chosen:
            c.x = self.rng.uniform(0, 1000)
            c.y = self.rng.uniform(0, 1000)
        return chosen

    def choose_branch(self, customer: Customer):
        if self.choice_mode == "exact":
            return self._choose_branch_exact(customer)
        return self._choose_branch_logit(customer)

    def _choose_branch_exact(self, customer: Customer):
        # City_CollectBranchesNearPoint: dx^2 + 4*dy^2 < 4*radius^2.
        candidates = []
        for b in self.branches:
            if not b.opened:
                continue
            dx = customer.x - b.x
            dy = customer.y - b.y
            # Game_GetAdjustedValue 0x4E4490: animated value widens catchment.
            radius = b.radius + game_get_adjusted_value(
                b.ad_value, self.city.value_factor, self.city.ad_city_term,
                b.ad_bonus, b.ad_base_value)
            if dx * dx + 4 * dy * dy > 4 * radius * radius:
                continue
            # Object_IsSiteRatingSufficient: no price-comparison term.
            rating = b.group_rating(customer.group, price_comparison=False)
            if customer.threshold > rating:
                continue
            candidates.append(b)
        # Type-3 billboard: City_CollectBranchesNearPoint 0x4D7ED0 adds the
        # advertised branch when the category effect is >= 51.
        for b in self.branches:
            if (b.opened and customer.group in b.type3_ad_groups
                    and b not in candidates):
                candidates.append(b)
        if not candidates:
            return None
        if len(candidates) == 1:
            return candidates[0]
        # Game_PickBestScoredRecord: max per-size score; ties favour later.
        best = candidates[0]
        best_score = customer.scores[best.size_class]
        for b in candidates[1:]:
            score = customer.scores[b.size_class]
            if best_score <= score:
                best = b
                best_score = score
        return best

    def _choose_branch_logit(self, customer: Customer):
        candidates = []
        for b in self.branches:
            if not b.opened:
                continue
            rating = b.group_rating(customer.group)
            if rating < GROUP_MIN_RATING[customer.group]:
                continue
            utility = ((rating - 50) / 18.0
                       - (b.price_index() / self.city.price_scale
                          / customer.price_tolerance - 1.0)
                       * 4.0 * GROUP_PRICE_SENS[customer.group]
                       + b.marketing * 0.8)
            candidates.append((utility, b))
        if not candidates:
            return None
        m = max(u for u, _ in candidates)
        weights = [math.exp(u - m) for u, _ in candidates]
        total = sum(weights)
        pick = self.rng.random() * total
        acc = 0.0
        for (u, b), w in zip(candidates, weights):
            acc += w
            if pick <= acc:
                return b
        return candidates[-1][1]

    def update_size_score(self, customer: Customer, branch: Branch):
        """Object_SyncChildState 0x5094A0 exact band table."""
        rating = branch.group_rating(customer.group)
        size = branch.size_class
        if rating >= 96:
            customer.scores[size] = 100
            for i in range(6):
                if i != size:
                    customer.scores[i] -= 10
        elif rating >= 85:
            customer.scores[size] += 10
        elif rating >= 75:
            customer.scores[size] += 8
        elif rating >= 65:
            customer.scores[size] += 5
        elif rating >= 55:
            customer.scores[size] += 3
        elif rating >= 44:
            pass
        elif rating >= 35:
            customer.scores[size] -= 3
        elif rating >= 25:
            customer.scores[size] -= 5
        elif rating >= 15:
            customer.scores[size] -= 10
        else:
            customer.scores[size] -= 20
        for i in range(6):
            customer.scores[i] = max(-100, min(100, customer.scores[i]))

    # ---------- construction / advertising ----------
    def add_construction(self, branch: Branch, cost: float = None,
                         weeks: int = 4, facility_type: int = 0x1F,
                         quality_gain: int = 2):
        if cost is None:
            cost = branch.construction_price()
        order = ConstructionOrder(cost, weeks, facility_type, quality_gain)
        branch.construction_orders.append(order)
        return order

    def optimize_advertising(self, branch, plan_type=3):
        company = self.companies[branch.company_id]
        plan = optimize_advertising_plan(
            company, branch=branch,
            competitors=[c for c in self.companies if c.id != company.id],
            city_term=self.city.ad_city_term,
            plan_type=plan_type)
        active = plan_type == 3 or plan["effect"] >= 41
        plan["active"] = active
        self.add_advertising(
            branch, media_type=plan["media_type"],
            category=plan["category"],
            monthly_cost=plan["budget"], setup_cost=0.0, weeks=4,
            plan_type=plan["plan_type"], flags=plan["flags"],
            target=plan["target"], percent=plan["percent"],
            active=active)
        return plan

    def add_advertising(self, branch: Branch, media_type=1, category=0,
                        monthly_cost=3500.0, setup_cost=0.0, weeks=4,
                        plan_type=3, flags=0, target=-1, percent=100,
                        active=True):
        """Branch_AddAdvertisingPlan 0x5001F0.

        ``monthly_cost`` is the game's **daily** plan budget (+0x20).
        Ordinary creation is free; ``setup_cost`` is only the rival-billboard
        takeover fee (10 x old budget, ledger 23).
        """
        plan = AdvertisingPlan(media_type, category, monthly_cost,
                               setup_cost, weeks, plan_type, flags,
                               target, percent, active)
        if setup_cost:
            self.companies[branch.company_id].charge(23, setup_cost)
        branch.ad_plans.append(plan)
        return plan

    def _tick_construction(self):
        for b in self.branches:
            for order in list(b.construction_orders):
                order.progress += 1
                weekly = order.cost / max(1, order.weeks)
                order.paid += weekly
                self.companies[b.company_id].charge(3, weekly)
                b.record_expense(weekly)
                if order.progress >= order.weeks:
                    b.facilities[order.facility_type] = (
                        b.facilities.get(order.facility_type, 0) + 1)
                    b.quality = min(100, b.quality + order.quality_gain)
                    b.construction_orders.remove(order)

    AD_LEDGER = {1: 15, 2: 16, 3: 17}

    def _approach_ad_value(self, branch, target):
        """Value_Approach 0x4E4670 for one branch value record."""
        step = target / 36.0
        if target > 0:
            if branch.ad_value >= target:
                return False
            branch.ad_value = min(target, branch.ad_value + step)
            return True
        if target < 0:
            if branch.ad_value <= target:
                return False
            branch.ad_value += step
            return True
        return False

    def allocate_menu_sales(self, company):
        """Company_AllocateMenuSales 0x4FE870 for types 1/2."""
        net4 = sum(company.net_stat_history[-4:])
        pool = (int(net4) >> 5) + int(company.cash * 0.05)
        plans = list(company.ad_plans)
        for b in company.branches:
            plans.extend(p for p in b.ad_plans if p.plan_type == 2)
        if pool < 1:
            for p in plans:
                p.active = False
            return 0
        scored = []
        total_score = 0
        for p in plans:
            if p.plan_type == 1:
                b = company.branches[0] if company.branches else None
            else:
                b = next((x for x in company.branches
                          if p in x.ad_plans), None)
            if b is None:
                p.active = False
                continue
            opt = optimize_advertising_plan(
                company, branch=b,
                competitors=[c for c in self.companies if c.id != company.id],
                city_term=self.city.ad_city_term, plan_type=p.plan_type)
            if not opt.get("allowed"):
                p.active = False
                continue
            p.media_type = opt["media_type"]
            p.flags = opt["flags"]
            p.target = opt["target"]
            p.category = opt["category"]
            p.percent = opt["percent"]
            target = (next((c for c in self.companies if c.id == p.target),
                           None) if p.target >= 1 else None)
            avg = plan_average_effect(
                p.plan_type, p.media_type, p.flags, company, b, target,
                self.city.ad_city_term, 100)
            if avg < 41:
                p.active = False
                continue
            p.monthly_cost = 10000.0 if p.plan_type == 1 else 5000.0
            score = avg * (len(company.branches) if p.plan_type == 1 else 1)
            scored.append((p, score))
            total_score += score
        for b in company.branches:
            for p in b.ad_plans:
                if p.plan_type == 3:
                    p.monthly_cost = 3500.0
                    p.active = True
        while pool >= 1 and scored and total_score >= 1:
            idx = max(range(len(scored)), key=lambda i: scored[i][1])
            p, score = scored.pop(idx)
            share = min(c_div(score * pool, total_score),
                        10000 if p.plan_type == 1 else 5000)
            p.monthly_cost = share
            p.active = share > 0
            if p.plan_type == 1:
                scored = [(q, s) for q, s in scored
                          if not (q.plan_type == 1 and s <= score)]
            pool -= share
            total_score -= score
        return pool

    def _update_advertising(self):
        """Company_ProcessHourlyTick 0x4E0200 ad billing/application."""
        moved = set()
        for company in self.companies:
            # Type 1 is company-wide; Company_ProcessHourlyTick charges the
            # company object to ledger 15.
            if company.branches:
                b0 = company.branches[0]
                type1 = list(company.ad_plans)
                type1.extend(p for b in company.branches
                             for p in b.ad_plans if p.plan_type == 1)
                seen = set()
                for plan in type1:
                    if id(plan) in seen:
                        continue
                    seen.add(id(plan))
                    if not plan.active:
                        continue
                    target = (next((c for c in self.companies
                                    if c.id == plan.target), None)
                              if plan.target >= 1 else None)
                    avg = plan_average_effect(
                        plan.plan_type, plan.media_type, plan.flags, company,
                        b0, target, self.city.ad_city_term, plan.percent)
                    plan.effect_value = plan_effect_value(avg)
                    hourly = f32(plan.monthly_cost * F32_ONE_OVER_24)
                    company.charge(15, hourly)
                    for other in company.branches:
                        if self._approach_ad_value(
                                other, plan.effect_value):
                            moved.add(other.id)
        for b in self.branches:
            company = self.companies[b.company_id]
            b.type3_ad_groups = set()
            b.type2_ad_effect = [0] * 8
            for plan in list(b.ad_plans):
                if not plan.active or plan.plan_type == 1:
                    continue
                target_company = (next((c for c in self.companies
                                        if c.id == plan.target), None)
                                  if plan.target >= 1 else None)
                avg = plan_average_effect(
                    plan.plan_type, plan.media_type, plan.flags, company,
                    b, target_company, self.city.ad_city_term,
                    plan.percent)
                plan.effect_value = plan_effect_value(avg)
                # Daily budget charged 1/24 per hour; type-specific ledger.
                hourly = f32(plan.monthly_cost * F32_ONE_OVER_24)
                company.charge(self.AD_LEDGER.get(plan.plan_type, 16),
                               hourly)
                b.record_expense(hourly)
                if plan.plan_type == 2:
                    if self._approach_ad_value(b, plan.effect_value):
                        moved.add(b.id)
                    for group in range(8):
                        b.type2_ad_effect[group] = plan_category_effect(
                            plan.plan_type, plan.media_type, plan.flags,
                            company, b, target_company, group,
                            self.city.ad_city_term, plan.percent)
                elif plan.plan_type == 3:
                    for group in range(8):
                        effect = plan_category_effect(
                            plan.plan_type, plan.media_type, plan.flags,
                            company, b, target_company, group,
                            self.city.ad_city_term, plan.percent)
                        if effect >= 51:
                            b.type3_ad_groups.add(group)
        for b in self.branches:
            if b.id not in moved:
                if b.ad_value > 0:
                    b.ad_value = max(0.0, b.ad_value - 4.0)
                elif b.ad_value < 0:
                    b.ad_value = min(0.0, b.ad_value + 2.0)
            b.marketing = min(1.0, max(0.0, b.ad_value / 100.0))

    # ---------- order economics ----------
    def weighted_market_price(self):
        """Market_ComputeWeightedAveragePrice price factor across companies."""
        usages = [0] * len(self.market_prices)
        for c in self.companies:
            for i, usage in enumerate(c.product_usage[:len(usages)]):
                usages[i] += int(usage)
        raw = market_weighted_unit_price(self.market_prices, usages)
        if self.market_price_reference <= 0:
            return raw
        return raw / self.market_price_reference

    def consume_stock(self, branch: Branch, quantity):
        available = sum(b.qty for b in branch.batches)
        if available < quantity:
            return None
        remaining = quantity
        cost = 0.0
        for batch in list(branch.batches):
            take = min(batch.qty, remaining)
            batch.qty -= take
            remaining -= take
            cost += take * batch.unit_cost
            if batch.qty <= 1e-9:
                branch.batches.remove(batch)
            if remaining <= 1e-9:
                break
        branch.stock -= quantity
        branch.units_consumed += quantity
        return cost

    def order_delivery(self, branch: Branch):
        """Storage_OrderDelivery 0x514510 + City_SpawnDeliveryVehicles 0x4DC1A0."""
        if (not branch.supplier or branch.vehicles_out > 0
                or branch.convoy is not None
                or branch.stock >= branch.stock_capacity * branch.reorder_threshold):
            return None
        branch.delivery_vehicles = min(3, int(branch.storage_level) + 1)
        delays = [self.rng.randint(4, 7) * i + 1
                  for i in range(branch.delivery_vehicles)]
        cells = None
        if (self.path_graph is not None and branch.supplier_node is not None
                and branch.storage_node is not None):
            cells = self.graph_path_cells(branch.supplier_node,
                                          branch.storage_node)
        if cells is None:
            cells = 1
        arrivals = sorted(d + cells for d in delays)
        convoy = VehicleConvoy(branch.delivery_vehicles, delays, cells,
                               arrivals)
        branch.convoy = convoy
        branch.vehicles_out = convoy.vehicles
        return convoy

    def process_convoy(self, branch: Branch, max_ticks=TICKS_PER_HOUR):
        """Advance state-0x34 vehicles and settle arrived batches."""
        convoy = branch.convoy
        if convoy is None:
            return 0
        arrived = 0
        while convoy.arrived < len(convoy.arrivals):
            if convoy.arrivals[convoy.arrived] > max_ticks:
                break
            convoy.arrived += 1
            arrived += 1
            self.receive_delivery(branch)
        branch.vehicles_out = convoy.vehicles - convoy.arrived
        if convoy.arrived >= convoy.vehicles:
            branch.convoy = None
            branch.vehicles_out = 0
        return arrived

    def receive_delivery(self, branch: Branch):
        units = max(0.0, branch.stock_capacity - branch.stock)
        if units <= 0:
            return 0.0
        unit_cost = branch.batch_unit_cost()
        branch.batches.append(Batch(units, unit_cost))
        branch.stock += units
        branch.units_delivered += units
        cost = units * unit_cost
        self.companies[branch.company_id].charge(14, cost)
        branch.record_expense(cost)
        return cost

    def process_order(self, branch: Branch, customer: Customer):
        recipe = branch.recipes[customer.group % len(branch.recipes)]
        servings = max(1, int(customer.party_size * GROUP_APPETITE[customer.group]
                             + self.rng.random() * 0.4))
        batch_cost = self.consume_stock(branch, servings)
        if batch_cost is None:
            branch.lost += 1
            return 0.0, 0.0

        tip = max(0, (branch.group_rating(customer.group)
                      - GROUP_MIN_RATING[customer.group]) // 2)
        revenue = (100 + tip) * servings * branch.recipe_price(recipe) * 0.01
        market_cost = (batch_cost * self.weighted_market_price()
                       * market_bonus(
                           int((branch.group_rating(customer.group) - 50) / 5)))
        profit = revenue - market_cost

        company = self.companies[branch.company_id]
        company.charge(12, market_cost)
        company.earn(0, revenue)
        company.revenue_total += revenue
        company.period_revenue += revenue
        company.lifetime_revenue += revenue
        branch.served += servings
        branch.revenue += revenue
        branch.costs += market_cost
        branch.record_income(revenue)
        branch.record_expense(market_cost)
        recipe.sales += servings
        branch.customers_today += 1
        self.update_size_score(customer, branch)
        return revenue, market_cost

    def recipe_price_competitive(self, recipe, owner_id):
        """AI_CheckPriceCompetitiveness 0x512CA0.

        The final ``__ftol`` expression in the original is not recovered;
        the mid-point test uses ``local_1c // 2``.
        """
        own = recipe.usage_counters()
        own_price = float(recipe.price)
        for company in self.companies:
            if company.id == owner_id:
                continue
            for branch in company.branches:
                for other in branch.recipes:
                    counts = other.usage_counters()
                    both = 0
                    other_only = 0
                    own_only = 0
                    close = 0
                    for i in range(min(len(own), len(counts), 86)):
                        has_own = own[i] > 0
                        has_other = counts[i] > 0
                        if has_other:
                            both += 1
                        if not has_own and has_other and counts[i] > 10:
                            other_only += 1
                        elif has_own and not has_other and own[i] > 10:
                            own_only += 1
                        elif (has_own and has_other
                              and other.price * 0.8 <= own_price
                              <= other.price * 1.2):
                            close += 1
                    if own_only < 2 and other_only < 2:
                        if both == close:
                            return 0
                        if both > 2 and both // 2 <= close:
                            return 0
        return 1

    def track_recent_entry(self, category, ingredient):
        """Player_TrackRecentEntry 0x4DA810."""
        if not (0 <= category < 8):
            return
        ring = self.city_recent[category]
        for i, value in enumerate(ring):
            if value == ingredient:
                if i == 0:
                    return
                ring[i] = ring[i - 1]
                ring[i - 1] = ingredient
                return
        ring[-1] = ingredient

    def start_city_ad_campaign(self):
        """Game_InitCompanyAIStrategy 0x4DCE00 city contest setup."""
        count = len(self.companies) - 1
        if count < 1:
            return None
        category = self.rng.randrange(8)
        self.city_campaign = {
            "active": True,
            "category": category,
            "pot": 5000 * count,
            "countdown": 12 // count + 3,
            "duration": 12 // count + 3,
        }
        return dict(self.city_campaign)

    def settle_city_ad_campaign(self):
        """City_SettleAdvertisingCampaign 0x4DCE70."""
        camp = self.city_campaign
        if not camp.get("active"):
            return None
        category = camp["category"]
        winner = None
        best = 0
        for company in self.companies:
            recipe = None
            if company.branches:
                branch = company.branches[0]
                if (branch.assigned_recipe is not None
                        and 0 <= branch.assigned_recipe < len(branch.recipes)):
                    recipe = branch.recipes[branch.assigned_recipe]
                elif branch.recipes:
                    recipe = branch.recipes[0]
            score = recipe.skill_rating(category) if recipe else 0
            if score > best:
                best = score
                winner = company
        if winner is not None:
            winner.campaign_wins += 1
            winner.earn(24, camp["pot"])
        self.city_campaign = {"active": False, "category": 0, "pot": 0,
                              "countdown": 0, "duration": 0}
        self.city_recent = [[-1] * 6 for _ in range(8)]
        self.storage_rent_price = special_trade_offer(
            3, 0, rent_factor=self.city.rent_trade_factor)
        self.storage_buy_price = trade_offer_price(
            3, building_value=0.0,
            purchase_factor=self.city.purchase_trade_factor)["buy"]
        return {"winner": winner.id if winner else -1,
                "prize": camp["pot"], "category": category}

    # ---------- ticks ----------
    def tick_hour(self):
        camp = self.city_campaign
        if camp.get("active"):
            camp["countdown"] -= 1
            if camp["countdown"] == 0:
                self.settle_city_ad_campaign()
        for c in self.companies:
            # Hourly salaries: Branch_ProcessHour/Company_ProcessHourlyTick.
            total_staff = sum(b.staff for b in c.branches)
            wage = (total_staff * 12.0
                    * self.city.wage_scale)  # model wage rate
            if wage:
                hourly = wage / 24.0
                c.charge(6, hourly)
                for b in c.branches:
                    if total_staff:
                        b.record_expense(hourly * b.staff / total_staff)
            # Negative cash interest: 0.4% per hour.
            if c.cash < 0:
                c.charge(22, -c.cash * 0.004)
        if self.hour == 0:
            for company in self.companies:
                self.allocate_menu_sales(company)
        self._update_advertising()
        for b in self.branches:
            if b.delivery_delay > 0:
                if (b.supplier and b.delivery_pending == 0
                        and b.stock < b.stock_capacity * b.reorder_threshold):
                    b.delivery_pending = b.delivery_delay
                if b.delivery_pending > 0:
                    b.delivery_pending -= 1
                    if b.delivery_pending == 0:
                        self.receive_delivery(b)
            else:
                convoy = self.order_delivery(b)
                if convoy is not None:
                    self.process_convoy(b)
        self.recompute_market()
        if self.traffic_mode == "exact":
            self._tick_exact_traffic()
        else:
            customers = self.generate_customers()
            for customer in customers:
                b = self.choose_branch(customer)
                if b is None:
                    continue
                self.process_order(b, customer)
                self.total_customers += 1
        self.hour += 1
        if self.hour >= 24:
            self.hour = 0
            self.tick_day()

    def _spawn_customer(self, branch: Branch, group=None):
        group = self.rng.randrange(8) if group is None else group
        character = Character.create(self.rng)
        customer = Customer(
            group=group,
            threshold=self.rng.randint(30, 50),
            scores=[0] * 6,
            x=self.rng.uniform(0, 1000),
            y=self.rng.uniform(0, 1000),
            target_branch=branch.id,
            party_size=character.party_size(),
            character=character,
        )
        dx = customer.x - branch.x
        dy = customer.y - branch.y
        # Map_FindShortestPath over the .iso graph when both nodes are known.
        if (self.path_graph is not None and branch.path_node is not None
                and customer.path_node is None):
            customer.path_node = self.rng.randrange(len(self.path_graph.nodes))
        cells = None
        if (self.path_graph is not None and branch.path_node is not None
                and customer.path_node is not None):
            cells = self.graph_path_cells(customer.path_node,
                                          branch.path_node)
        if cells is None:
            cells = path_cell_count(dx, dy)
        customer.path_cells = cells
        travel_ms = cells * walk_node_ms()
        customer.travel_ms = travel_ms
        now_ms = ((self.day * 24 + self.hour) * 3_600_000)
        now_tick = ((self.day * 24 + self.hour) * TICKS_PER_HOUR)
        customer.arrival_ms = now_ms + travel_ms
        customer.arrival_tick = now_tick + travel_ms // 10
        customer.arrival_hour = self.day * 24 + self.hour + travel_ms // 3_600_000
        self.travelers.append(customer)
        self.total_spawned += 1

    def _tick_exact_traffic(self):
        # Arrive travelers whose walking time has elapsed.
        now = self.day * 24 + self.hour
        remaining = []
        for customer in self.travelers:
            if customer.arrival_hour <= now:
                b = self.branches[customer.target_branch]
                seats = sum(c.party_size for c in b.queue)
                if seats + customer.party_size <= b.queue_capacity:
                    b.queue.append(customer)
                else:
                    b.lost += 1
            else:
                remaining.append(customer)
        self.travelers = remaining

        # Branch_ProcessHour + Branch_SpawnWalkInCustomer:
        # one walk-in per open branch-hour, random group 0..7.
        for b in self.branches:
            if b.opened and b.open_hours[self.hour % 24]:
                self._spawn_customer(b)

        # Branch_AdvanceWeekStatistics -> Branch_SpawnRandomPedestrian:
        # one ambient pedestrian every 3 hours when a source building exists.
        if self.hour % 3 == 0:
            for b in self.branches:
                if (b.opened and b.pedestrian_sources > 0
                        and b.open_hours[self.hour % 24]):
                    self._spawn_customer(b)
                    if b.marketing > 0.4:
                        self._spawn_customer(b)
            # Type-1 plan: customer spawn attempts every 3 hours when a
            # category effect exceeds 60; pct = 2.5*(effect-60).
            for company in self.companies:
                for b in company.branches:
                    plan = next((p for p in b.ad_plans
                                 if p.plan_type == 1 and p.active), None)
                    if plan is None:
                        continue
                    target_company = (
                        next((c for c in self.companies
                              if c.id == plan.target), None)
                        if plan.target >= 1 else None)
                    caps = []
                    for group in range(8):
                        effect = plan_category_effect(
                            plan.plan_type, plan.media_type, plan.flags,
                            company, b, target_company, group,
                            self.city.ad_city_term, plan.percent)
                        if effect > 60:
                            pct = (5 * effect - 300) * 5 // 10
                            caps.append((group, pct))
                    if caps:
                        ingredient = plan.category - 1
                        for group, pct in caps:
                            for _ in range(len(company.branches)):
                                if self.rng.randint(1, 100) < pct:
                                    self.track_recent_entry(group, ingredient)
                    break

        # Game_GetTimeByMode(branch, 6) gives 30 or 80 ticks per service;
        # both are far below one hour, so the queue drains each hour.
        for b in self.branches:
            if not b.opened:
                continue
            while b.queue:
                customer = b.queue.pop(0)
                self.process_order(b, customer)
                self.total_customers += 1

    def start_mission_plan(self, action, steps, target=-1):
        plan = MissionPlan(action, steps, target)
        self.mission_plans.append(plan)
        return plan

    def mission_condition(self, action, company):
        branches = company.branches
        if action == 24:
            return bool(branches)
        if action == 27:
            return any(b.group_rating(0) > 80 for b in branches)
        if action == 28:
            return any(max(b.avg8[0], b.menu_rating[0], b.price_rating[0],
                           b.building_rating) > 80 for b in branches)
        if action == 30:
            return any(b.quality > 80 for b in branches)
        if action == 32:
            return bool(branches) and all(
                b.group_rating(0) > 50
                and max(b.avg8[0], b.menu_rating[0], b.price_rating[0],
                        b.building_rating) > 50
                for b in branches)
        if action == 33:
            return bool(branches) and all(
                max(b.avg8[0], b.menu_rating[0], b.price_rating[0],
                    b.building_rating) > 50 for b in branches)
        if action in (25, 26, 29, 31, 34, 35):
            # These ids are event/timer-driven in the mission state machine,
            # not checked by MissionGoal_Evaluate.  The simulator completes
            # them when the company has an active branch.
            return bool(branches)
        return False

    def apply_mission_reward(self, plan, company):
        """MissionGoal_ApplyCompletionEffects 0x5032C0 subset."""
        action = plan.action
        if action == 24:
            plan.counter += 1
            for b in company.branches:
                b.update_ratings()
        elif action == 26:
            self.city_company_scores.setdefault("d40", {})[company.id] = 100
        elif action == 27:
            self.city_company_scores.setdefault("c98", {})[company.id] = 100
        elif action in (25, 28, 29, 33):
            company.mission_completions[action] = (
                company.mission_completions.get(action, 0) + 1)
            self.mission_stats[action] = self.mission_stats.get(action, 0) + 1
        elif action == 30:
            if company.branches:
                b = company.branches[0]
                b.facilities[0x1F] = b.facilities.get(0x1F, 0) + 1
        elif action == 31:
            for b in company.branches:
                b.renovation_level = min(5, b.renovation_level + 1)
        elif action == 32:
            company.advancement_score = 0
            self.city_company_scores.setdefault("cc8", {})[company.id] = 60
        elif action == 34:
            usage = company.product_usage
            if any(usage):
                index = max(range(len(usage)), key=lambda i: usage[i])
                self.player_stat_actions[company.id] = (
                    index, usage[index])
            company.mission_completions[34] = (
                company.mission_completions.get(34, 0) + 1)
        elif action == 35:
            if company.branches:
                size = company.branches[0].size_class
                reward = (size * 5 + 5) * 20000
                company.earn(24, reward)
                plan.counter += 1

    def tick_mission_plans(self):
        remaining = []
        for plan in self.mission_plans:
            company = next((c for c in self.companies
                            if any(b.id == plan.target for b in c.branches)),
                           self.companies[0] if self.companies else None)
            if company is None:
                continue
            if self.mission_condition(plan.action, company):
                self.apply_mission_reward(plan, company)
                continue
            plan.steps -= 1
            if plan.steps > 0:
                remaining.append(plan)
        self.mission_plans = remaining
        return self.mission_plans

    def tick_day(self):
        self.day += 1
        for b in self.branches:
            b.customers_today = 0
        if self.day % 7 == 0:
            self.week += 1
            self._tick_construction()
            self.tick_mission_plans()
            if self.ai_enabled:
                for c in self.companies:
                    if c.id == 0:
                        continue
                    ai = self.ai_controllers.setdefault(c.id, CompanyAI())
                    decisions = ai.weekly(self, c)
                    if decisions:
                        self.ai_log.append((self.day, c.id, decisions))
        if self.day % 30 == 0:
            for b in self.branches:
                self.companies[b.company_id].charge(1, b.rent_monthly)
                b.record_expense(b.rent_monthly)
        if self.day % 360 == 0:
            self.close_year()
        if self.day % 90 == 0:
            self.end_of_quarter()

    def close_year(self):
        for b in self.branches:
            b.yearly_profit[self.year] = round(
                b.year_income - b.year_expenses, 2)
            b.year_income = 0.0
            b.year_expenses = 0.0

    def end_of_quarter(self):
        row = {
            "year": self.year,
            "quarter": self.quarter + 1,
            "day": self.day,
            "customers": self.total_customers,
            "revenue": round(sum(c.revenue_total for c in self.companies), 2),
            "cash": {c.name: round(c.cash, 2) for c in self.companies},
            "market_share": {self.companies[k].name: round(v, 4)
                             for k, v in self.market_share().items()},
            "avg_rating": round(sum(b.group_rating(g) for b in self.branches
                                    for g in range(8))
                                / max(1, len(self.branches) * 8), 2),
        }
        self.quarter_rows.append(row)
        shares = self.market_share()
        for c in self.companies:
            c.last_quarter_share = shares.get(c.id, 0.0)
            c.profit_history.append(round(c.period_profit, 2))
            c.net_stat_history.append(c.period_profit)
            c.net_stat_history = c.net_stat_history[-4:]
            c.ledger = [0.0] * LEDGER_SIZE
            c.revenue_total = 0.0
            c.period_revenue = 0.0
            c.period_profit = 0.0
        self.total_customers = 0
        self.quarter += 1
        if self.quarter >= 4:
            self.quarter = 0
            self.year += 1

    def run(self, days):
        for _ in range(days * 24):
            self.tick_hour()
        return self.summary()

    def summary(self):
        return {
            "seed": self.seed,
            "city": self.city.name,
            "day": self.day,
            "year": self.year,
            "quarter": self.quarter + 1,
            "companies": [
                {"name": c.name, "cash": round(c.cash, 2),
                 "market_share": round(self.market_share()[c.id], 4),
                 "ledger": {LEDGER_NAMES.get(i, f"cat_{i}"): round(v, 2)
                            for i, v in enumerate(c.ledger) if abs(v) > 1e-9}}
                for c in self.companies
            ],
            "branches": [
                {"id": b.id, "company": self.companies[b.company_id].name,
                 "served": b.served, "lost": b.lost,
                 "revenue": round(b.revenue, 2),
                 "costs": round(b.costs, 2),
                 "profit": round(b.revenue - b.costs, 2),
                 "ratings": [b.group_rating(g) for g in range(8)]}
                for b in self.branches
            ],
            "quarters": self.quarter_rows,
        }


def build_default(city=None):
    sim = Simulator(seed=1, city_traffic=600, city=city)
    a = sim.add_company("Player Pizza", 250000)
    b = sim.add_company("Rival Pizza", 200000)
    sim.add_branch(0, recipes=[Recipe("Margherita", 11.0, 3.8, 60)],
                   staff=10, quality=65, capacity=45, rent_monthly=2500,
                   size_class=2, x=300, y=300, radius=360)
    sim.add_branch(1, recipes=[Recipe("Margherita", 10.0, 4.2, 50)],
                   staff=7, quality=50, capacity=35, rent_monthly=2200,
                   size_class=3, x=700, y=700, radius=360)
    return sim


def build_scenario(seed=1, city=None, price_mult=1.0, quality_mult=1.0,
                   marketing_mult=1.0, city_traffic=600):
    sim = Simulator(seed=seed, city_traffic=city_traffic, city=city)
    a = sim.add_company("Player Pizza", 250000)
    a.marketing_budget *= marketing_mult
    b = sim.add_company("Rival Pizza", 200000)
    b.marketing_budget *= marketing_mult
    sim.add_branch(0, recipes=[Recipe("Margherita", 11.0 * price_mult,
                                      3.8, 60)],
                   staff=10, quality=65 * quality_mult,
                   capacity=45, rent_monthly=2500,
                   size_class=2, x=300, y=300, radius=360)
    sim.add_branch(1, recipes=[Recipe("Margherita", 10.0 * price_mult,
                                      4.2, 50)],
                   staff=7, quality=50 * quality_mult,
                   capacity=35, rent_monthly=2200,
                   size_class=3, x=700, y=700, radius=360)
    return sim


def sweep(days=90, city=None):
    scenarios = [
        ("base", 1.0, 1.0, 1.0),
        ("price_-20%", 0.8, 1.0, 1.0),
        ("price_+20%", 1.2, 1.0, 1.0),
        ("quality_-20%", 1.0, 0.8, 1.0),
        ("quality_+20%", 1.0, 1.2, 1.0),
        ("ad_type3", 1.0, 1.0, 2.0),
    ]
    rows = []
    for label, pm, qm, mm in scenarios:
        sim = build_scenario(city=city)
        # Only the player's branch changes, so market share can move.
        if pm != 1.0:
            sim.branches[0].recipes[0].price *= pm
        if qm != 1.0:
            sim.branches[0].quality = int(sim.branches[0].quality * qm)
        if mm != 1.0:
            sim.add_advertising(sim.branches[0],
                                monthly_cost=3500.0 * mm, plan_type=3)
        sim.run(days)
        company = sim.companies[0]
        branch = sim.branches[0]
        rows.append({
            "scenario": label,
            "cash": round(company.cash, 2),
            "revenue": round(company.total_revenue, 2),
            "costs": round(company.total_costs, 2),
            "served": branch.served,
            "avg_rating": round(sum(branch.group_rating(g)
                                    for g in range(8)) / 8, 2),
            "market_share": round(sim.market_share()[0], 4),
            "customer_share": round(
                branch.served / max(1, branch.served + sim.branches[1].served),
                4),
        })
    return rows


def cmd_demo(args):
    city = load_city_ini(args.city) if args.city else None
    sim = build_default(city)
    if args.map:
        sim.load_path_graph(args.map)
        sim.assign_path_nodes()
    sim.run(args.days)
    data = sim.summary()
    if args.json:
        print(json.dumps(data, indent=2))
        return 0
    print(f"city {sim.city.name}  day {data['day']} year {data['year']} "
          f"quarter {data['quarter']}")
    for c in data["companies"]:
        print(f"  {c['name']:14s} cash={c['cash']:12,.2f} "
              f"share={c['market_share']:.3f}")
    for b in data["branches"]:
        print(f"  branch {b['id']} {b['company']:12s} served={b['served']:6d} "
              f"lost={b['lost']:4d} revenue={b['revenue']:12,.2f} "
              f"profit={b['profit']:12,.2f} avgRating="
              f"{sum(b['ratings'])/8:.1f}")
    for q in data["quarters"]:
        print(f"  Y{q['year']}Q{q['quarter']} customers={q['customers']:7d} "
              f"revenue={q['revenue']:14,.2f} avgRating={q['avg_rating']}")
    return 0


def cmd_sweep(args):
    city = load_city_ini(args.city) if args.city else None
    rows = sweep(args.days, city)
    if args.json:
        print(json.dumps(rows, indent=2))
        return 0
    print(f"{'scenario':14s} {'cash':>12s} {'revenue':>12s} {'costs':>12s} "
          f"{'served':>8s} {'rating':>7s} {'rev%':>7s} {'cust%':>7s}")
    for r in rows:
        print(f"{r['scenario']:14s} {r['cash']:12,.0f} {r['revenue']:12,.0f} "
              f"{r['costs']:12,.0f} {r['served']:8d} {r['avg_rating']:7.1f} "
              f"{r['market_share']:7.3f} {r['customer_share']:7.3f}")
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    sub = ap.add_subparsers(dest="command", required=True)
    p = sub.add_parser("demo", help="run the default two-company city")
    p.add_argument("--days", type=int, default=360)
    p.add_argument("--city", default=None,
                   help="path to daten/<city>.ini")
    p.add_argument("--map", default=None,
                   help="path to an .iso map for graph routing")
    p.add_argument("--json", action="store_true")
    p.set_defaults(func=cmd_demo)

    p = sub.add_parser("sweep", help="price/quality/marketing scenarios")
    p.add_argument("--days", type=int, default=90)
    p.add_argument("--city", default=None)
    p.add_argument("--map", default=None,
                   help="path to an .iso map for graph routing")
    p.add_argument("--json", action="store_true")
    p.set_defaults(func=cmd_sweep)

    args = ap.parse_args(argv)
    return args.func(args)


if __name__ == "__main__":
    raise SystemExit(main())
