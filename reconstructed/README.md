# Reconstructed C code

This tree turns evidence-backed decompiled functions into normal C that a host
compiler can build. It is deliberately **not** byte-exact yet: the goal is a
readable, testable reconstruction with explicit layouts.

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
  drawing decoded raw/RLE 16bpp frames.
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
