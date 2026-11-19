# Save-state, typed-struct and isometric-index phase

This phase turned the save schema into working tooling and named the persistent
global state in REA.

## 1. `.piz` payload parser/editor

`tools/piz_payload.py` is schema-driven from `save_schema.json`.

Supported:

- 0xF0 header: title, company, city, player flags, calendar, SYSTEMTIME,
  version and magic.
- 0xF0 **8-dword section directory**: decoded as section end offsets, not a
  zero reserved block.
- Fixed preamble: start marker, global game block, game fields/scalars, and all
  subsystem globals through the briefing list at 0x7DB.
- Variable briefing list: `u32 count`, then `u32 id + u32 length + text`.
- 2,500 × 50-byte tile-name table.
- Directory-bounded regions: iso maps, characters, cities/map objects, persons,
  cars, players, companies and the tail.
- Character list: count + `u32 id` + 2,082-byte record, parsed field by field.
- Six player slots: present flag, 132-byte Player fields, nested Character,
  events, optional AI state, optional mission state.
- 24 serialized globals with names, file offsets and values.
- Verification of magic, start/end markers, directory monotonicity, file size,
  briefing and tile-table bounds.

Commands:

```bash
python3 tools/piz_payload.py synth /tmp/test.piz --one-character --one-player
python3 tools/piz_payload.py info /tmp/test.piz
python3 tools/piz_payload.py sections /tmp/test.piz
python3 tools/piz_payload.py verify /tmp/test.piz
python3 tools/piz_payload.py dump /tmp/test.piz --json
python3 tools/piz_payload.py characters /tmp/test.piz --json
python3 tools/piz_payload.py players /tmp/test.piz --json
python3 tools/piz_payload.py globals /tmp/test.piz
python3 tools/piz_payload.py get /tmp/test.piz header.title
python3 tools/piz_payload.py set /tmp/test.piz game.scalar[0] 12345 --out new.piz
```

Editable fixed-size fields: header strings/calendar/player count, tile names,
the 20 game scalars, the 24 named globals, and arbitrary raw byte ranges.
Variable-length briefing strings are parsed but not rewritten yet.

## 2. Typed structs

`tools/build_structs.py` generates:

- `game_structs.h`: 28 packed C structs, 1,083 fields, with exact offsets,
  explicit padding, save-order comments and observing functions.
- `STRUCTS.md`: per-struct field tables.
- `structs_model.json`: machine-readable layout.

Known sizes are enforced for `Game` (0x2F890), `Company` (0x1F0), `Player`
(0xB0), `City` (0x1158), `WorldObject` (0x16C), `Character` (0x828), `IsoMap`
(0x10178) and `Car` (0x14). Impossible offsets beyond a known size are dropped.

The header compiles with `gcc -std=c11 -fsyntax-only` and static assertions for
the known struct sizes and `Player+0x84`.

## 3. REA global naming

The previous session's metadata was discarded on close, so the full map was
reapplied:

- `all_symbols_with_vtables.json`: **3,181** names (3,029 procedures + 75
  indirect-only slot functions + 77 vtable labels).
- `save_schema.json` globals: **24** serialized globals.
- Total applied: **3,205**; reported failures: **0**.
- Readback: all **24** globals plus a sample of vtable/function names
  verified, **0 failures**.
- Evidence: `save_state_rea-evidence.json` (220 records, 8.0 MB).

Named globals include `g_GameGlobalState` (0x57BB20, 1,464 bytes),
`g_GameCalendarState`, `g_CompanyMarketShare`, `g_AdvertisingPanelA/B`,
`g_BranchStatsSeriesFlags`, `g_IngredientPanelState`, `g_PersonnelState`,
`g_WarehouseProductState`, and the statistics/branch design groups.

## 4. Isodaten.idx format

`tools/isodaten_tool.py` and `ISODATEN_FORMAT.md` decode the isometric sprite
dictionary exactly:

- 173,504 bytes, **2,467 entries**, exact end-of-file.
- 2,458 sprite entries, 9 tag-0 functional markers.
- 750 entries with L/S/M variants; suffix order `.L.SPR`, `.S.SPR`, `.M.SPR`.
- 119 animation records across 89 entries.
- Parser validates that the final cursor equals the file size.

## 5. `.iso` map format

`ISO_FORMAT.md` and `tools/iso_tool.py` decode the city and branch map format
from `IsoMap_DeserializeGrid` (`0x4EB900`):

- 0x7C header with grid dimensions, viewport, tile pixels and background name
- two 34-byte object tables (13,839 city records)
- RLE tile grid (164x164 city, 280x280 branch; Paris 152x152)
- two layer IDs per tile with optional 50-byte sprite names
- trailing array hook

Validation: **25/25 maps parse to exact EOF** (10 city, 15 branch), 3.21 MB
total, 19,541 city tiles and 10,207 branch tiles. `iso_validation.csv` lists every
map; `iso_previews/` contains 25 occupancy PNGs. Tests: 7/7 pass in
`tests/test_iso_tool.py`.

## 6. Simulation and balance tables

`SIMULATION.md` now covers hourly/daily/weekly/quarterly pipelines, rating/menu/
price/building formulas, order economics, rent/salary/interest, market bonus,
freshness, service level, ledger categories and work duration.
`balance_tables.json` extracts the 8-group rating tables and 10-city
construction/service tables.

`tools/sim_core.py` is a deterministic headless economy: two companies, eight
customer groups, with a rule-based company AI that can price, advertise and
expand. It uses the exact rating/order/accounting
shapes and the decoded branch-choice path: 30–50 threshold, radius filter,
per-size max-score choice, and the six-size score-update bands. Hourly traffic
uses the decoded one-walk-in-per-open-branch-hour plus one pedestrian every
three hours; stock uses threshold-triggered deliveries and market share uses
quarter-to-date revenue; the exact strategy-plan step generator and some ledger semantics remain
partial. City profiles load real `daten/<city>.ini` population, rent, wage, quality and group-share data.
`tests/test_sim_core.py` passes **160/160** (bounds, cash conservation, monotonic
demand, deterministic seeds, quarter rollover, stock refill, scenario sweep, exact branch threshold/radius/score bands). Sample run:
4 quarters, **25,216 customers**, **$1,202,065 revenue**, year 2 rollover.

## 7. Verification

- `python3 tests/test_piz_payload.py`: **6/6 tests pass**.
- `python3 tests/test_tab_tool.py`: **5/5 tests pass**.
  Covers empty saves, briefing parsing, character/player records, fixed-field
  edits, all 24 globals, and C header compilation.
- `python3 tools/piz_payload.py verify` passes on all synthetic variants.
- REA readback 32/32 sampled names (24 globals + 8 prior symbols).
- Struct static assertions pass.

## 8. Deliverables

| File | Contents |
|---|---|
| `SAVE_SCHEMA.md` / `save_schema.json` | writer-level save layout |
| `save_top_level.csv` | computed section offsets |
| `STATE_MODEL.md` / `state_model.json` | observed vs serialized fields |
| `SAVE_SCHEMA_VERIFICATION.json` | counts, pairs, hashes, limits |
| `SAVE_STATE_REVERSAL.md` | this report |
| `tools/piz_payload.py` | parser/editor + synthetic generator |
| `tests/test_piz_payload.py` | end-to-end tests |
| `game_structs.h` / `STRUCTS.md` / `structs_model.json` | typed structs |
| `tools/build_structs.py` | struct generator |
| `ISODATEN_FORMAT.md` / `tools/isodaten_tool.py` | isometric sprite index |
| `SIMULATION.md` / `balance_tables.json` / `sim_constants.json` | economy model and constants |
| `tools/sim_core.py` / `tests/test_sim_core.py` | headless simulator and 11 validation tests |
| `ISO_FORMAT.md` / `tools/iso_tool.py` | `.iso` map format, parser and preview |
| `iso_validation.csv` / `iso_previews/` | all-map validation and PNG previews |
| `save_state_rea-evidence.json` | REA evidence bundle |

## 9. Limits and next

- REA checkpoint mode is disabled: the 3,205 names were applied and verified,
  but live metadata is discarded on close. Reapply from
  `all_symbols_with_vtables.json` + `save_schema.json`, or import
  `save_state_rea-evidence.json`.
- No real `.piz` save is present; layout validation is static + synthetic.
- Company slots and person/actor sub-records remain opaque variable graphs.
- `.iso` header fields `0x28`/`0x2C`/`0x30`/`0x34`, object-record keys and tile
  flag fields are structurally decoded but not semantically named.
- `.ani` frame format is not decoded.
- Struct field names are structural; semantics still need to be proven from
  formulas and UI labels.
