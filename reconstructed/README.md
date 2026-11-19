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
- `statistics/` — company overview counts/rank/share and branch-balance
  entries from `Stats_Report_FillCompanyOverview` and the statistics screens.
- `render/` — RGBA render surface, clipped fill/blit with alpha, and TGA
  decoding for uncompressed and RLE 24/32-bit true-colour plus 8-bit
  grayscale images.
- `assets/` — SPR 8/16bpp alpha/RLE/raw decoder and FNT glyph decoder,
  exercised against `extracted/sprites/pb24_01.spr` and
  `extracted/fonts/timesfont.fnt`.
- `ui_render/` — composes shipped SPR sprites and FNT text onto the RGBA
  render surface, including hotspot placement, alpha blending and text
  measurement.
- `screen/` — decodes `extracted/pictures/pe_startscreen.tga` into an 800×600
  RGBA frame and draws the reconstructed main-menu rows and status line with
  the shipped Times font. Also composes the character-select page over
  `extracted/pictures/pe_charakterauswahl.tga` at the documented control
  positions and the London briefing page over
  `extracted/pictures/pe_missionsbriefing_lon.tga` with wrapped body text.
- `operations/` — branch period accounting: sale revenue, ingredient cost,
  payroll, rent, advertising, profit and period close.
- `ai/` — customer visit state machine (walk 260, production 180, service 80)
  and competitor AI plan snapshot.
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
