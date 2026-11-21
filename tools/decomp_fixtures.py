"""Reviewed inputs and ABI contracts for the PC2 function verifier."""

import json
import random
import struct
from dataclasses import dataclass, field
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
GAME = ROOT / "game/fastfood2.exe"
PE_HASH = "18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd"
SCRATCH = 0x00300000
DIFFICULTY = 0x0057BB24
ABI_SOURCE = "tools/decomp_abi.c"
LEAF_SOURCE = "reconstructed/leaf/leaf_functions.c"


def words(*values):
    return struct.pack(f"<{len(values)}I", *(value & 0xffffffff for value in values))


@dataclass(frozen=True)
class Case:
    name: str
    args: tuple[int, ...] = ()
    ecx: int = 0
    memory: tuple[tuple[int, bytes], ...] = ()
    expected_eax: int | None = None


@dataclass(frozen=True)
class Routine:
    address: int
    name: str
    source: str
    entry: str
    cases: tuple[Case, ...]
    result: str
    source_group: str
    adapter: bool = False
    stack_cleanup: int = 0
    observations: tuple[tuple[str, int, int], ...] = ()
    writable: tuple[tuple[int, int], ...] = ()
    symbols: dict[str, int] = field(default_factory=dict)
    # Original callees the candidate may reuse, with stack argument count
    # and inclusive executable end address for the fixture's path.
    calls: dict[int, tuple[int, int]] = field(default_factory=dict)


def clamp_cases():
    rng = random.Random(0x477100)
    values = (0, 1, -1, 99, 100, 101, -2**31, 2**31 - 1,
              *(rng.randint(-200, 300) for _ in range(24)))
    return tuple(Case(f"value_{value}_{index}", (SCRATCH + 4,),
                      memory=((SCRATCH, words(0x12345678, value, 0x9ABCDEF0)),))
                 for index, value in enumerate(values))


def distance_cases():
    rng = random.Random(0x4ED570)
    vectors = ((0, 0, 0, 0), (1, 2, 3, 4), (-8, 5, 13, -21), (10, -5, 2, 3),
               (0x7fffffff, -1, -2, 0x7fffffff), (-2**31, 0, 0, -2**31),
               *(tuple(rng.randint(-20000, 20000) for _ in range(4)) for _ in range(24)))
    return tuple(Case(f"coordinates_{index}", coordinates)
                 for index, coordinates in enumerate(vectors))


def capital_cases():
    source = ROOT / "decompiled_fastfood2_named_v2/typed_packets/fixtures/game_get_starting_capital.fixture.json"
    with source.open() as fp:
        fixture = json.load(fp)
    if fixture["executable"]["sha256"] != PE_HASH or int(fixture["entry"], 16) != 0x48D3A0:
        raise ValueError("starting-capital fixture target does not match the verifier")
    return tuple(Case(row["id"], memory=((DIFFICULTY, words(row["memory"]["0x57bb24"])),),
                      expected_eax=row["expected_eax"]) for row in fixture["cases"])


def recipe_price_cases():
    branch, recipe, entries, batch = (SCRATCH + offset for offset in (0, 0x2000, 0x2400, 0x2500))
    # Seed a valid IDMap entry for the fast path of the original
    # Branch_GetBuildingValue. The actual callee executes on both sides.
    cases = (
        ("stored_percent", -999, 110, 2, 10.0, 1.2),
        ("explicit_percent", 110, 75, -2, 11.85281086, 1.25),
        ("zero_percent", 0, 100, 4, 15.0, 1.0),
        ("zero_base", -999, 125, -3, 0.0, 0.75),
        ("binary32_base_a", 100, 130, 0, 12.42636204, 1.0),
        ("binary32_base_b", 100, 130, 0, 11.85281086, 1.0),
        ("multiplier_rounding", -999, 173, 7, 16.25, 0.71),
    )
    return tuple(
        Case(name, (branch, percent), ecx=recipe, memory=(
            (branch + 0x14A8, words(stored, offset)),
            (branch + 0x199C, words(entries)),
            (branch + 0x19A4, words(1)),
            (entries, words(batch)),
            (batch + 0x10, struct.pack("<f", value)),
            (batch + 0x1C, words(1)),
            (recipe + 0x44, struct.pack("<f", base)),
        ))
        for name, percent, stored, offset, base, value in cases
    )


def routines():
    return (
        Routine(0x477100, "Clamp_0_100", LEAF_SOURCE, "pc2_clamp_0_100",
                clamp_cases(), "void", "leaf", adapter=True, stack_cleanup=4,
                observations=(("value_and_guards", SCRATCH, 12),), writable=((SCRATCH + 4, 4),)),
        Routine(0x4ED570, "Distance_Manhattan3", LEAF_SOURCE, "pc2_distance_manhattan3",
                distance_cases(), "eax", "leaf", adapter=True, stack_cleanup=16),
        Routine(0x48D3A0, "Game_GetStartingCapital", "reconstructed/leaf/starting_capital.c",
                "game_get_starting_capital", capital_cases(), "eax", "leaf",
                observations=(("difficulty", DIFFICULTY, 4),),
                symbols={"game_difficulty": DIFFICULTY}),
        Routine(0x513BF0, "Branch_ComputeRecipePrice", "reconstructed/branch/recipe_price_x86.c",
                "branch_compute_recipe_price", recipe_price_cases(), "x87", "recipe",
                stack_cleanup=8,
                symbols={"branch_get_building_value": 0x47FD90, "recipe_get_base_price": 0x510570,
                         "pc2_price_percent_factor": 0x55C348},
                calls={0x47FD90: (0, 0x47FDB3), 0x4017F0: (2, 0x4018BA),
                       0x510570: (0, 0x510573)}),
    )
