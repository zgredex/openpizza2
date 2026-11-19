# Skill and quality function batch

Function cards for the two arrays that feed candidate scoring. The batch
packet is [SKILL_QUALITY_BATCH.md](SKILL_QUALITY_BATCH.md).

## `Game_GetSkillRating` — `0x5139e0`

**Callers**

- `Game_ComputeObjectDetails` `0x5092b0`
- `Branch_RecomputeMenuPriceRatings` `0x4784e0`
- `Game_ComputeCompanyProductScore` `0x513b00`

**Inputs**

| Input | Meaning |
|---|---|
| `this` | object holding two nine-entry arrays: craft at `+0x2c4`, skill at `+0x2e4` |
| `param_1` | recipe/order record; `+0x34` is the category passed to `Game_ComputeSkillRatings` |
| `param_2` | float parameter forwarded to `Game_ComputeSkillRatings` |
| `param_3` | category; `8` is remapped to `5`; `-1` means average over eight categories |

**Return value**

```text
category in 0..7: craft[category] + skill[category]
category == -1:   (sum(craft[i] + skill[i], i=0..7) + sign-adjust) >> 3
category == 8:    category 5 result
no valid character lookup: 0
```

This is the value the scorer uses as the candidate's skill component. The
function only returns the sum; it does not write the arrays.

**State**

Reads the object arrays and the character lookup. Calls
`Game_ComputeSkillRatings(this, recipe, price)` first to refresh them. No
persistent writes.

**Test**

`crates/sim/src/lib.rs::tests::skill_rating_0x5139e0_aggregates_arrays` covers
category 2, category 8 → 5, category -1 averaging and an invalid category.

**Status:** aggregation and category remap are **S** from pseudocode and
disassembly. The contents of the arrays come from `Game_ComputeSkillRatings`
(next card) and are not yet reproduced.

## `Game_ComputeSkillRatings` — `0x513760`

**Callers**

- `Game_GetSkillRating` `0x5139e0`

**Inputs**

| Input | Meaning |
|---|---|
| `this` | object with two nine-entry rating arrays at `+0x2c4` and `+0x2e4` |
| `param_1` | recipe/order record; `+0x34` selects the character/company record |
| `param_2` | float scale/threshold passed from the caller |

**Output**

Fills eight craft values at `+0x2c4..+0x2e0` and eight skill values at
`+0x2e4..+0x300`. It clears the skill array, reads eight `Rating_GetFloat`
values from the character, adds a style/branch modifier (double for style 1,
quadruple for style 2), and clamps/rounds by category:

```text
skill[0], skill[6] <= 40
skill[1] <= 10
skill[2] <= 20
skill[3] <= 30
skill[4] <= 5
skill[5] = 0
skill[7] <= 20
```

**State**

Reads character rating floats and style field; writes the two arrays.

**Test**

Not yet added. A controlled fixture needs a real character/company record plus
the style field. The clamp values are **S**; the base float values are **R**
until an original character is chosen.

## `Player_ComputeProductQualityScore` — `0x47d910`

**Caller**

- `Game_ComputeObjectDetails` `0x5092b0` only

**Call contract from disassembly**

At `0x509323`–`0x50932e`, `ECX` holds the branch, and the caller pushes the
customer category followed by the candidate recipe pointer. All three exits
of `0x47d910` use `ret 8`. After the prologue, `[esp+0x24]` is the category
slot and supplies the index for both penalty matrices. The recipe pointer is
passed by the caller and unused by this callee. Ghidra's `param_4` and
`param_5` refer to the same stack slot. `extraout_EDX` reflects register
bookkeeping in the decompiler. The helper at `0x47ca80` receives the branch
in `ECX` and the literal `5` on the stack, and `0x47d910` consumes only its
low return byte. [Call site](full_game_verification/functions/0x5092b0.c) ·
[Retained pseudocode](full_game_verification/functions/0x47d910.c) ·
[Disassembly](SKILL_QUALITY_BATCH.md)

**Tables and state**

The pinned executable contains four contiguous arrays of little-endian i32
values. [Table fixture](PRODUCT_QUALITY_TABLES.json)

| Address | Dimensions | Use |
| --- | --- | --- |
| `0x567938` | 8 | Minimum flagged-batch average by category |
| `0x567958` | 8 | Minimum low-byte result from `0x47ca80` by category |
| `0x567978` | 8 × 6 | Penalty indexed by category and combined record score |
| `0x567a38` | 8 × 9 | Penalty indexed by category and staff rating bucket |

`0x56798c` and `0x567a58` point to the last column of their respective matrices.
Offsets into those addresses therefore select the last column of the current
row. The verifier compares all 136 table values with the pinned executable.

**Return value and side effects**

- Begin at 100. Average the signed `+4` values for batches with nonzero
  `+0x1c` flags, using zero when no batch qualifies. For an average below the
  first threshold, subtract twice the shortfall, or four times the shortfall
  when the average itself is negative. [Batch calculation](full_game_verification/functions/0x47d910.c#L28)
- Store the low byte of `0x47ca80(branch, 5)` at branch `+0x1870`. Subtract
  ten times its shortfall from the second threshold. [Value helper](full_game_verification/functions/0x47ca80.c)
- Get the low byte of `0x47c9a0(branch, 5)` and the signed EAX result of
  `0x47cb70(branch, 5)`. Round their product scaled by the original `0.01f`,
  passing the product through a single-precision store before `0x403850`.
  Use that index for the first matrix, with column 5 as the upper cap and a
  penalty of 100 for negative indices. The accumulator at `[esp+0x10]` is
  the minuend at `0x47da40`–`0x47da54`. [Record average](full_game_verification/functions/0x47c9a0.c) ·
  [Company average](full_game_verification/functions/0x47cb70.c) ·
  [Rounding helper](full_game_verification/functions/0x403850.c)
- Average `Rating_ClampAdjusted` over staff entries whose record has a zero
  byte at `+0x824`. Divide by 12 to get the second matrix's column, use
  column 0 if there are no eligible staff, and cap the index to 0..8. Subtract
  that penalty and return the signed accumulator in EAX. The outer caller
  applies the building adjustment and final 0..100 clamp. [Staff rating](full_game_verification/functions/0x4d3f90.c)

**Inputs to the category-5 helpers**

Each helper walks branch `+0x16f8` using the count at `+0x170c`. The entry's
`+4` selects a furniture type from the global registry at `game+0x74`. The
selector `5` matches the type's `+8` byte. `0x47ca80` averages the type's
`+0x14` byte and caps it to 0..2 before rounding. `0x47c9a0` averages the
placement entry's `+0x0c` integer and caps it to 0..100 before rounding.
`0x47cb70` averages the type's `+0x70` double before rounding. [Type lookup](full_game_verification/functions/0x4e5df0.c) · [Type byte](full_game_verification/functions/0x4e5ff0.c)

`FurnitureType_InitTable` copies 66 source rows of `0xe0` bytes from
`0x56d160` into runtime objects starting at `+8`. It stops at `0x570b20`.
Rows 36 through 47 have type byte 5. For a controlled fixture, source row 38
at `0x56f2a0` has type byte 5, `+0x14` value 2, and `+0x70` value 1.6 in
its resulting runtime layout. A placement pointing to this type with
`+0x0c = 100` gives helper outputs 2, 100 and 2, respectively. The placed
object and staff values for a visit in the original remain to be observed.
[Furniture initialization](full_game_verification/functions/0x4e41c0.c)

**Static check cases**

The combined score is derived, not stored:

```text
combined = round_0x403850(f32(f32(helper_47c9a0_low) * f32(0.01))
                          * f32(helper_47cb70_signed))
```

`0x403850` adds `+0.5` for non-negative values or `-0.5` for negative values,
then truncates toward zero. `0x47ca80` is capped at 2 before it reaches this
step.

| Category | Flagged-batch average | `0x47ca80` low byte | Helper `0x47c9a0` low | Company `0x47cb70` | Derived combined | Staff bucket | Expected signed return |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 50 |
| 0 | 10 | 1 | 100 | 2 | 2 | 2 | 95 |
| 0 | -1 | 1 | 100 | 2 | 2 | 2 | 51 |
| 2 | 80 | 2 | 100 | 6 | 6 | 8 | 100 |

These fixtures follow the machine-code accumulator and table indices. Mutation
checks in `PRODUCT_QUALITY_REPLAY.json` prove the verifier notices changed
helper inputs:

```text
row38 helper_47c9a0_low 100 -> 0  => quality 95 -> 90
row38 helper_47ca80_low   2 -> 0  => quality 95 -> 85
```

Original branch and staff records, original runtime output, and rounding near
x87 conversion boundaries still need fixtures. The Rust scorer currently takes
quality from its caller.

## Branch/staff replay fixture

[PRODUCT_QUALITY_REPLAY.json](PRODUCT_QUALITY_REPLAY.json) records the controlled
branch and staff inputs around the category-5 helpers:

- source furniture row `0x56f2a0`: type byte 5, `+0x14 = 2`, `+0x70 = 1.6`;
- placement `+0x0c = 100`, giving helper outputs `2, 100, 2`;
- one eligible staff record with adjusted rating 24, giving staff bucket 2;
- flagged batch average 10 and combined record score 2.

`tools/quality_tool.py` evaluates the recovered tables and checks five cases:

```text
empty-branch                 50
shortage-adjacent-positive   95
negative-batch-average       51
category-four-high          100
row38-counter                95
```

These are controlled/static expectations. The original branch placement and
staff records, and a runtime quality readout, are still pending.

## Virtual calls reached

[VIRTUAL_CALL_TRACE.md](VIRTUAL_CALL_TRACE.md) traces the indirect sites in the
customer path. The only resolved logic call is the `List` destructor
`0x401420` via vtable `0x55c2ec`, reached from `Branch_ComputeWorkDuration`,
`AI_ChooseWalkTarget` and `Object_FindNearbyCustomer`. Audio backend slots
`0x7c`, `0x5c` and `0xf4` are runtime-selected DirectSound targets and are
effects-only; they do not change queue, stock or cash.

## Batch replay hook

Rust test `quality_95_replay_0x47d910_0x509580_0x47d4a0` uses the corrected
row38 quality 95, selects the price-14 candidate, and checks stock 400 -> 399
plus cash +15.7205247 in the settlement path.


The implemented batch is:

```text
skill_rating(...)          # 0x5139e0, tested
        ↓
candidate_score(quality, offset)  # 0x5092b0 return path
        ↓
select_candidate_index(...)       # 0x509580 rank bands
        ↓
BranchSim settlement       # 0x47d4a0
```

The next dependencies for `0x47d910` are representative branch records for
the three category-5 helpers, followed by a replay that exercises their inputs
through the scorer. The recovered table fixture and stack contract are in place.
