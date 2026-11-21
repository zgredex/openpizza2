# Reconstructed C code

This tree turns evidence-backed decompiled functions into normal C that a host
compiler can build. It is deliberately **not** byte-exact yet: the goal is a
readable, testable reconstruction with explicit layouts.

## Compare a reconstruction with the shipped executable

`check_decomp.py` compiles the candidate as freestanding i386 C and runs it
and the pinned GOG `fastfood2.exe` from the same state in Unicorn. It checks
stack cleanup, callee-saved registers, the declared return value and memory
effects. The recipe-price fixtures also compare the x87 return as 80 bits and
verify the order and arguments of the observed helper calls. Candidate code
can execute original code only within the helper ranges listed for that
routine.

Use Python 3.10+ with `unicorn==2.1.4` and `pefile==2024.8.26`, plus GCC
with i386 headers and GNU binutils. The environment from the
[lifted build](../tools/pcrecomp_pc2/README.md)
already provides both Python packages. Run the pilot suite and the two
negative controls with one command from the repository root.

```sh
make -C reconstructed check-decomp DECOMP_PYTHON=/tmp/opencode/pcrecomp-pc2-fresh/venv/bin/python
```

With the same Python on your path, inspect the queue, check a single
routine, and report the result:

```sh
python3 tools/check_decomp.py queue
python3 tools/check_decomp.py check 0x477100 --json-out /tmp/pc2-decomp.json
python3 tools/check_decomp.py queue --report /tmp/pc2-decomp.json
python3 tools/check_decomp.py toolchain
```

Check the whole queue by omitting the address. Use `--source /path/to/candidate.c`
to verify an alternate candidate for one address. Exit code 0 means all
selected checks passed. Exit code 1 means a candidate failed to compile or
disagreed with a fixture. Exit code 2 indicates a usage or environment error.

For a new batch, give each worker a routine address, the candidate source
file, and the check command. Keep the fixtures in
`tools/decomp_fixtures.py` under separate review. Reuse the retained
pseudocode and existing captures when preparing an evidence packet.

```sh
python3 tools/function_batch.py 0x401320 \
  --capture-report /path/to/capture/report.json \
  --json-out /tmp/pc2-function-packet.json --out /tmp/pc2-function-packet.md
```

`--capture-report` is optional and repeatable. It records observed indirect,
tail, and return-jump dispatch with scenario, phase, count, and resolution.
Coverage follows the supplied runs. Reports must match the shipped executable
hash. Packets generated without capture reports keep the existing format.

The pilot covers the clamp (32 cases), weighted distance (30), starting
capital (12), and recipe pricing (7). Recipe pricing exercises the original
active-stock-batch path with seeded branch and recipe records. The fallback
building-value path and the broader customer-order pipeline still need their
own fixtures. The JSON distinguishes compiled and behavior-verified results
and leaves byte matching unset. `toolchain` reports the PE linker version,
Rich-header product/build IDs, and installed tools to start compiler
identification. The original compiler and flags still need verification.

Current batches:

- `settings/` — settings block layout, `Settings_InitDefaults` behavior, and the
  defaults that the Unicorn probe `tools/emulate_settings_defaults.py` observes.
- `ingredient/` — `Ingredient` prefix layout and `Game_SetBuildingDesc`, checked
  against the Olives descriptor read back by
  `tools/emulate_ingredient_desc.py`.
- `mission/` — `MissionState` layout, the campaign branch of
  `Game_InitDateState`, and the London goal ids 0/1/2 from
  `Mission_EvaluateGoals`, tested against the existing 9/9 Unicorn mission
  fixture.
- `branch/` — one-serving branch economy, price formula and sale arithmetic
  using the Rust-verified constants (`13.420524712365806` cash delta at price
  `12`).
- `menu/` — main-menu controls, hit testing, selection, hover and activation
  status restored from `Screen_MainMenu`.
- `ui_screen/` — screen ids and transitions from `GameLoop_DispatchScreens`:
  main menu 0x15, briefing 0x16, session 0x17, free-play setup 0x18,
  sub-start menus 0x19/0x1B and character select 0x1C.
- `options/` — options/autosave page state, sound values, language 0..3 and the
  0x568D88 autosave interval table (1..120).
- `statistics/` — company overview counts/rank/share, branch-balance entries
  and `Stats_ComputePlayerAggregateStats` customer/profit/ratio totals,
  maxima and leader scores.
- `render/` — RGBA render surface, clipped fill/blit with alpha, and TGA
  decoding for uncompressed and RLE 24/32-bit true-colour plus 8-bit
  grayscale images.
- `assets/` — SPR 8/16bpp alpha/RLE/raw decoder, ANI sprite-sheet/raw/RLE
  16bpp chunk decoder and FNT glyph decoder,
  exercised against `extracted/sprites/pb24_01.spr` and
  `extracted/fonts/timesfont.fnt`.
- `ui_render/` — composes shipped SPR sprites and FNT text onto the RGBA
  render surface, including hotspot placement, alpha blending and text
  measurement.
- `map/` — `.iso` parser from `IsoMap_DeserializeGrid` (`0x4EB900`) and
  city/branch composition from `IsoMap_RenderFrame` (`0x4EF9E0`): crops the
  shipped 4096×2048 `lon.tga` city background around a tile, draws branch
  markers, renders the branch interior from
  `Iso_Filiale_einf_klein.iso` plus its background and 40 furniture sprites,
  and builds the `bg003.tga`/`mask.tga` statistics map panel.
- `screen/` — decodes `extracted/pictures/pe_startscreen.tga` into an 800×600
  RGBA frame and draws the exact main-menu buttons at x=595 with tiled
  `TEXTPBTRANSPGELB_00.spr` backgrounds and the shipped Times font. Also composes the character-select page over
  `extracted/pictures/pe_charakterauswahl.tga` with all 66 exact constructor
  controls, four shipped fonts and the PB22/PB24/PB26/PB27, portrait, gender,
  light and button sprites, the free-play setup page over
  `extracted/pictures/pe_freies_spiel.tga` with all 157 exact constructor
  controls, five shipped fonts and the scenario sliders, player rows, buttons
  and status sprites,
  and the exact London briefing page over
  `extracted/pictures/pe_missionsbriefing_lon.tga` with the exact Mission
  title/city/description/help controls, LOGOFENSTER, slider and Back/Start
  Mission buttons, and the exact 162-control StatisticsBalance layout over
  STATISTIKBILANZBACK.spr with TAB09/TABPB01 rows, six shipped fonts, the
  SL01_00 slider and the PB22/PB24/PB33/TEXTPB05 controls, and the exact
  42-control office-desk layout over BG002.tga with its five fonts, desk
  sprites and button/status controls, with the six ANI animation windows
  drawing decoded raw/RLE 16bpp frames, the exact 185-control warehouse
  deliveries page with 27 sprites, the exact 172-control town-advertising
  page with 28 sprites and its five rating rows, and the exact 208-control
  end-results points page over PE_ENDERGEBNIS_PUNKTE.TGA, and the exact
  231-control personnel-record page with 39 shipped sprites.
- `leaf/` — leaf routines from the original executable: clamping, weighted
  Manhattan distance, RGB555/RGB565 conversion, quantity pricing, company
  percent modifiers, building level/area/sprite-variant mapping, direction
  mapping, calendar interpolation, array counters/search/pair access,
  8-byte-record binary search, game stat counters and trivial pointer clears.
- `player/` — the 0xB0-byte Player object: Character pointer, 32-byte name,
  slot, six character values plus six bonuses, six achievement tiers, the
  attacks-fended-off counter, event list and event type enum, AI/mission-state
  pointers and the exact save/load order with 25 layout asserts.
- `character/` — the full 0x828-byte Character object: constructor fields,
  save/load order, skill/age/performance fields, five 100-dword rating blocks,
  registry/object/player/branch IDs and 29 compile-time layout asserts.
- `freeplay/` — six 0xC0-byte player setup profiles at 0x57BCD8 with static
  asserts for the recovered offsets, the default multiplier/active writes and
  the `(multiplier * capital) / 100` starting-cash formula.
- `rating/` — `Branch_GetCustomerGroupRating` composition, city adjustment,
  `Stats_GetAverage8`/`Branch_GetMenuRating`, the baseline branch-score table
  rule and `Game_GetMarketBonusFactor`.
- `advertising/` — `Value_Approach`, hourly value decay,
  `Game_GetAdjustedValue` customer-radius conversion, company budget-percent
  conversion, per-category plan effect bars, the 12×8 media/category table
  with competitor metric adjustments, and the budget allocation loop that
  scores and shares the pool across plan types.
- `operations/` — branch period accounting (sale revenue, ingredient cost,
  payroll, rent, advertising, profit, period close) plus the hourly path:
  1/24 wage and advertising shares, 0.4%/hour negative-cash interest, opening
  hours, `Game_ComputePlayerSalary` and
  `Company_CollectUnprofitableBranches`.
- `ai/` — customer visit state machine (walk 260, production 180, service 80),
  competitor AI plan snapshot and `AI_ComputePlanScores` per-period
  income-expense scoring.
- `recipes/` — recipe toppings, base price, branch-menu assignment and the
  `Branch_ComputeRecipePrice` formula.
- `personnel/` — staff roster, profession, skill/speed/motivation/health,
  wage totals, average skill, branch assignment and training level.
- `save/` — packed save blob: "PC2S" header, the 0x164-byte settings block,
  and the 0xD0 bytes emitted by `Player_MissionState_Save`.
- `piz/` — expanded `.piz` container: 0xF0 header, 0x20 directory, fixed
  preamble through the game calendar, briefing list, 2500×50 tile-name table,
  and directory-bounded character/map-object/person/car/player/company
  sections. Character and player bodies use the schema field sequences
  (Character_Save 2082 bytes, Player_Save 132 bytes) and are validated by
  `piz_payload.py parse_characters`/`parse_players` with no errors.
  Company slots use CompanyData_Save's 270-byte fixed prefix, GamePlan records
  (11 u32), Recipe records (u32 id + 713-byte body), a Branch_Save list
  (u32 id + 6412-byte fixed body + zero variable tail), StatsPeriodReport
  records (856 bytes), Storage records (u32 id + 303-byte body), pair records
  (u32 id + 8 bytes) and 0x1A0-byte records. Validated by
  `piz_payload.py companies`.
- `construction/` — `ConstructionOrder` 0x24 layout, enqueue cell index and
  completion ownership derived from `Branch_EnqueueConstructionOrder` and
  `Branch_CompleteConstruction`.
- `city/` — city/branch state, London lease, HQ/rat mission actions and branch
  sale integration.
- `test_game` — one executable linking settings, ingredient, menu, UI screen,
  save, construction, mission, branch and city modules through the full London
  loop.
- `pc2-reconstructed` — full-game build target (`make full-game`) running the
  menu → character select → mission briefing → options/autosave → London
  mission → save and `.piz` container round trip.

Build and run:

```bash
make -C reconstructed check
```

Layout offsets are anchored with `_Static_assert`, so an accidental field
insertion fails the build instead of silently changing the ABI.
