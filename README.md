# Pizza Connection 2 — decompilation and headless engine workspace

This repository contains the reverse-engineering record, data parsers, and
headless economy model for **Pizza Connection 2 / Fast Food Tycoon II v1.004
(GOG)**.

## Target

| Field | Value |
|---|---|
| Executable | `game/fastfood2.exe` |
| SHA-256 | `18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd` |
| Format | PE32, Intel i386 |
| Original data | `game/`, `extracted/` |

The supported executable is the GOG build above. The installed game data is
used for local compatibility research; the engine's distributable demo must use
original fixtures.

## Quick start

Original game files (`game/`, `extracted/`, `extracted_png/`) and rendered PNG
evidence are intentionally not committed. Install or extract them locally before
running the verification scripts; code, text, JSON evidence and synthetic saves
are tracked.

```sh
python3 tools/verify_all.py
```

This single entry point checks the executable hash, the 3,029-name manifest
against the named pseudocode export, all test suites, the 25-map `.iso` scan,
the Isodaten index, the typed-struct C11 compile, the four model generators
(regenerated in a scratch checkout and byte-compared, 80/80), the Rust archive
inventory, the Rust Berlin crop viewer, the main-menu and character-select
replays, and the simulation samples.
It regenerates `decompiled_fastfood2_named_v2/samples/sim_demo_360.json`,
`sim_sweep_90.json`, `sim_demo_map_90.json`, and refreshes
`decompiled_fastfood2_named_v2/SIM_VERIFICATION.json` from the same run.

Use `--no-write` for a read-only check. Current result: **39/39 checks**,
**191 Python tests**, and **69 Rust tests**.

### Typed function packets

`tools/function_batch.py` now emits JSON records keyed by executable SHA-256
and address, not only Markdown. Curated annotations add recovered signatures,
dispatch targets, fields read/written, event order and unresolved questions.
The first batch traces Free Play Start through `Game_RunSession`,
`Game_InitScenario` and `City_ConstructFromName`, with exact instruction
prefixes cross-checked against the PE image.

```sh
python3 tools/function_batch.py \
  0x472da0 0x4cbcd0 0x4cc640 0x4052c0 0x404af0 \
  0x481d90 0x48d3a0 0x482740 0x4d44e0 0x406a90 \
  --annotations decompiled_fastfood2_named_v2/typed_packets/free_play_start.annotations.json \
  --json-out decompiled_fastfood2_named_v2/typed_packets/free_play_start.json \
  --out decompiled_fastfood2_named_v2/typed_packets/free_play_start.md
python3 tools/verify_typed_packet.py
python3 tools/emulate_starting_capital.py
python3 tools/emulate_clock_command.py
```

```text
typed packets: 2 packet(s), 21 records, 80 trace steps, 3 tables, 8 fixtures,
80/80 instruction prefixes match, 15/15 mutations rejected
starting capital emulation: 12/12 cases, EAX matches
clock command emulation: 2/2 cases, 0xfffe79de -> 0x405aa9
```

The Free Play packet records the callback entry `0x4cc640` that is absent from
the named export, the screen-state dispatch edges, the difficulty jump table,
the city `%s.ini`/`%s.iso` construction, population forwarding, the ownership
percentage chain and the first write of starting cash to company `+0x108`.
The clock packet recovers the worker at `0x4dd300` and follows
`0xfffe79f7` through `Game_WindowProc` to its UI consumer. Retained REA
evidence covers both batches. See
[TYPED_FREE_PLAY_START.md](decompiled_fastfood2_named_v2/TYPED_FREE_PLAY_START.md)
and [TYPED_CLOCK_WORKER.md](decompiled_fastfood2_named_v2/TYPED_CLOCK_WORKER.md).

## Manual commands

```sh
sha256sum game/fastfood2.exe
PYTHONDONTWRITEBYTECODE=1 python3 -m unittest discover -s tests
python3 tools/iso_tool.py scan game/Isokarten
python3 tools/isodaten_tool.py info extracted/isodaten/isodaten.idx
python3 tools/sim_core.py demo --days 360 --city extracted/daten/ber.ini --json
printf '#include "decompiled_fastfood2_named_v2/game_structs.h"\n' | \
  cc -x c -std=c11 -fsyntax-only -
```

### Asset coverage

Before adding actors, the decoder audit opens every PAK entry and runs its format consumer:

```sh
cargo run -p pc2-audit -- --install game --check
```

```text
summary: 9142 entries, 7542 decoded, 1600 header-only, 0 unsupported, 0 errors
spr 6947  ani 328  tga 38  fnt 13  pcx 2  tab 2  db 1  idx 1  txt/ini 210
header-only: wav 1489, bik 109, bin 1, pix 1
```

All visual and data formats used by the viewer are decoded, including actor
animations, 8-bit run streams with the per-file colour key, RLE TGA, PCX and
font headers. Bink movies and WAV audio are validated at container/header
level; frame/audio playback is a separate consumer. The corrected export tree
contains **6,947 PNGs** plus `extracted_png/SHA256SUMS`; verification checks the
manifest and regenerates five representative PNGs byte-for-byte. The full
matrix is in [ASSET_VERIFICATION.json](decompiled_fastfood2_named_v2/ASSET_VERIFICATION.json).

## Modern runtime (Rust)

The roadmap starts the modern runtime as a Cargo workspace. The current
`assets` crate is dependency-free and reads the installations read-only:

```sh
cargo run -p pc2-inventory -- --install game --check
cargo test --all
```

```text
5 paks
9,142 entries
448,651,308 payload bytes
iso.pak     4,276 entries
main.pak    3,168 entries
movie.pak     109 entries
sound.pak   1,489 entries
update.pak    100 entries
```

`pc2-assets` validates the PAK header, decodes the obfuscated index, checks
every entry's name/data bounds, and reads entries on demand. `pc2-inventory`
is the headless inventory deliverable.

`pc2-render` is the first Vulkan renderer step: two overlapping textured quads
rendered to a 64×64 target and read back for deterministic pixel checks.

```sh
cargo run -p pc2-render
```

```text
adapter: AMD Radeon Graphics (RADV RENOIR)
backend: Vulkan
red corner:    [255, 0, 0, 255]
green corner:  [0, 255, 0, 255]
overlap center:[0, 255, 0, 255]
result: OK
```

### Berlin crop viewer

`pc2-scene` connects the ISO and SPR decoders. It projects the 164×164 Berlin
grid with the loader's cell coordinates, resolves all 275 distinct inline layer
names through the PAK index, decodes each sprite, and paints the crop in
deterministic ground-line order over `backgrounds/ber.tga`. The headless path
writes the PNG and then renders the same pixels through Vulkan for an exact
readback comparison.

```sh
cargo run -p pc2-app -- \
  --install game --map game/Isokarten/Ber.iso \
  --output berlin_crop.png --json berlin_draws.json
```

```text
map: game/Isokarten/Ber.iso
background: backgrounds\ber.tga 4096x2048 origin (2784, 1344)
crop: center (5056, 2464) origin (1872, 820) size 800x600
tiles: 2166 present, 1861 layers considered
draws: 125 ordered, missing 0, ambiguous 0
adapter: AMD Radeon Graphics (RADV RENOIR)
backend: Vulkan
vulkan: 800x600 readback, 0 byte mismatches
result: OK
```

The default crop is the Brandenburg Gate around the centre of the named tile
layers; `--center X,Y`, `--width` and `--height` select another crop. The
windowed viewer uses a Vulkan surface, nearest filtering and live resize; close
it with Esc or `--frames N`:

```sh
cargo run -p pc2-app -- --window
```

`pc2-scene` tests cover the loader projection, all 2,166 Berlin tiles, the exact
125-draw crop, a foreground occlusion, and deterministic draw-list and PNG
hashes. The 8-bit tree (`b_laub_b.spr`) and 16-bit sample (`pb07__01.spr`)
decode to the same FNV hashes in Python and Rust:

```text
8bpp  b_laub_b.spr  144x106  0x8c144b3bf0b94e51  6,619 opaque pixels
16bpp pb07__01.spr   29x29   0x4b1da7c6da626011    837 opaque pixels
```

![Berlin crop in the Vulkan viewer](decompiled_fastfood2_named_v2/samples/berlin_viewer_window.png)

### Branch interior and animation

The same builder handles the 15 branch maps. Their background is a
`filiale_<size>_<style>_back.spr` room cut-out; the transparent floor diamond
is filled with the matching `filiale_<size>_boden<style>00.spr` floor sprite
before the 39-55 furniture draws are composited. All 15 branch backgrounds,
floors and tile layers resolve without missing or ambiguous assets.

```sh
cargo run -p pc2-app -- \
  --map game/Isokarten/Iso_Filiale_einf_klein.iso \
  --output branch_einf_klein.png --json branch_einf_klein_draws.json
```

```text
background: isodaten\sprites\filiale_klein_einf_back.spr (sprite) 799x551 origin (1080, 528)
floor: isodaten\sprites\filiale_klein_bodeneinf00.spr
tiles: 40 present, 40 layers considered
draws: 39 ordered, missing 0, ambiguous 0
vulkan: 800x600 readback, 0 byte mismatches
result: OK
```

![Branch interior in the Vulkan viewer](decompiled_fastfood2_named_v2/samples/branch_viewer_window.png)

`pc2-assets` also [decodes `.ani` files](decompiled_fastfood2_named_v2/ANI_FORMAT.md). The four Berlin tree types
(`b_allee_a`..`d`) have 12-frame sway animations; the default 800×600 crop has
14 visible animated tree draws, and the other draws stay unchanged. Static
rendering remains the default:

```sh
cargo run -p pc2-app -- --animation-frame 1 --output berlin_sway_01.png
cargo run -p pc2-app -- --animate --window
```

```text
animation: frame 1/12 on 14 animated draws
hash: dd41d009408d354d
```

### Main menu

`Screen_MainMenu` (`0x476920`) is rebuilt from the original
`Pe_Startscreen.tga` background, `TIMESFONT.fnt` and the nine
`TEXTPBTRANSPGELB_00..08.spr` panel tiles. All six controls use the recovered
labels, IDs, coordinates, original 38-pixel framed panels and centered
204-pixel text layout. The six labels are read from the installed
`language.ldf`; the font decoder is `crates/assets/src/fnt.rs` and the screen is
`crates/app/src/menu.rs`.

```sh
cargo run -p pc2-app -- --menu --window
cargo run -p pc2-app -- --menu --output main_menu.png
cargo run -p pc2-app -- --menu --menu-script 'down;down;enter' \
  --output menu_continue.png
```

Interactive controls: Up/Down or W/S select, Enter/Space activate, Esc exits.
Mouse hover uses the same control rectangles; a click is hit-tested against the
last cursor position so it still works after keyboard navigation. Start new
game and Start free game resolve the branch map under `--install` and open the
character-selection screen in a new process; a failed launch leaves the menu
open with an error. Continue, Options and Credits currently show the status
panel until their sub-screens are rebuilt.

```text
menu: items=6
menu: item 0 label="Start new game" id=0x3ee x=595 y=6 w=204 h=38
...
menu: item 5 label="Quit" id=0x3f6 x=595 y=560 w=204 h=38
menu: action=ContinueGame id=0x3f0 label="Continue game"
vulkan: 800x600 readback, 0 byte mismatches
result: OK
```

[MAIN_MENU_TRACE.md](decompiled_fastfood2_named_v2/MAIN_MENU_TRACE.md) records
the screen construction, callback dispatch, font format and replay. The sample
below is the deterministic frame checked by `verify_all.py`'s main-menu check.

![Rebuilt main menu](decompiled_fastfood2_named_v2/samples/main_menu.png)

### Character selection

The Start New Game destination is `Screen_CharacterSelect` (`0x46dbd0`). It
renders the original `Pe_Charakterauswahl.tga` background and composites the
four original face layers (`HEAD`, `MUND`, `AUGEN`, `HAARE`) for both genders.
Appearance arrows, gender, six attribute arrows and their total, the 8x8
Logo/color portrait, the difficulty slider and editable player/enterprise names
are functional. Labels and Back/Start button text come from the installed
`language.ldf`; hover help and normal/hover/pressed sprite states are wired,
and Start serializes the selected profile into the branch world.

```sh
cargo run -p pc2-app -- --character-select --window
cargo run -p pc2-app -- --character-select --output character_select.png
cargo run -p pc2-app -- --character-select \
  --character-script 'down;enter' --output character_start.png
```

Up/Down or W/S move between **To main menu** and **Start game**; Enter/Space
activates; Esc returns to the main menu. Mouse clicks on the arrows, gender
buttons, portrait selectors, difficulty slider and name fields update the
screen; click a name field and type, with Backspace and Enter supported. Free
Start opens the Free Play Setup screen. Campaign Start opens the first installed
mission city. Back spawns the main menu. The screen is
documented in
[CHARACTER_SELECT_TRACE.md](decompiled_fastfood2_named_v2/CHARACTER_SELECT_TRACE.md).

### Campaign Start

Campaign Start reads `update\mission.txt`, with `daten\mission.txt` as a
fallback, and loads the first city's INI and map from the installation. London
starts at the clock reset with 500,000 cash, two years, goals 0/1/2, one rival,
and no player branch. Goal and branch records are retained as mission metadata.
A New Game campaign starts with cash `500,000`, no player branch, no staff,
and an empty pantry. The city map shows the vacant London storefront at tile
`13694` (`(82,83)` in `Lon.iso`). Click its marker to open the lease terms:
property `13694`, rent `2,812`, one-time fee `1,000`, total cash debit
`3,812`, and current cash. **Enter** or the CONFIRM button leases it; **Esc**
or CANCEL closes the terms. The lease creates branch `100000` under
owner slot `0`, marks it player-controlled and leased, and leaves stock at zero. These values
match the lifted `Player_CreateBranch` checkpoint (`site_id=0`,
`branch_id=100000`, HUD cash `500000 -> 496188`).

Inside the branch, prepare the restaurant before opening:

```text
1/2/3  hire cook/service/errand (staff roster grows)
W      lease the warehouse
V      enable deliveries
D      deliver 200,000 stock units
H      set opening hours 06:00-22:00
O      open/close (requires staff, warehouse, deliveries, stock, and open hours)
Space  advance five minutes
C      return to the city
```

The keyboard path is mirrored by the campaign script:

```sh
cargo run -p pc2-app -- --campaign-start --playable-script \
  'lease=13694;hire=cook;hire=service;hire=errand;hire=errand;warehouse=1;deliveries;delivery=400000;hours=6-22;branch;minutes=360;open;step' \
  --output /tmp/opencode/campaign_prepare.png
```

The click path is covered by:

```sh
cargo test -p pc2-app city_click_selects_vacant_storefront_and_confirm_leases_it -- --nocapture
```

### Free Play Setup

`Screen_FreePlaySetup` (`0x472da0`, state `0x18`) is rebuilt from
`Pe_Freies_Spiel.tga`, `TIMESFONT.fnt` and the original panel tiles. It shows
the traced Berlin city/map, population 250, game length 11, opponent slots
`-1/-1/-1`, the profile's difficulty and the verified starting capital. Its
Back/Start controls use the original positions `0x4e2` at 595,509 and `0x4e3`
at 595,550.

```sh
cargo run -p pc2-app -- --free-play-setup --window
cargo run -p pc2-app -- --free-play-setup \
  --character-profile 'mode=free;...;difficulty=9;player=Ada;enterprise=Ada Pizza' \
  --scenario 'mode=free;city=ber;name=Berlin;map=Ber.iso;population=250;length=11;opponents=-1,-1,-1' \
  --output free_play_setup.png
```

![Free Play Setup screen](decompiled_fastfood2_named_v2/samples/free_play_setup.png)

Setup Start loads the selected city with the same profile and scenario. Press
**B** to enter the playable branch and **C** to return to the city. The
headless chain loads both maps before it initializes the simulation and runs
the first sale.

```text
free-play-chain: menu=StartFreeGame
free-play-chain: character=Start ...difficulty=9;...
free-play-chain: setup=Start city=ber map=Ber.iso starting_capital=22000
free-play-chain: loaded city=game/Isokarten/Ber.iso hash=... branch=game/Isokarten/Iso_Filiale_einf_klein.iso
free-play-chain: first sale sales=1 cash=22013.420525
```

Verification checks that Berlin and London load distinct city scenes and
that a missing city map exits before the simulation runs.

![Free Play chain first sale](decompiled_fastfood2_named_v2/samples/free_play_chain_first_sale.png)

Free Play commits the traced `Screen_FreePlaySetup` values: Berlin (`ber`),
`Ber.iso`, population 250, game length 11 and opponent slots `-1/-1/-1`.
Difficulty selects the verified `Game_GetStartingCapital` value (9 -> 22,000).
The explicit Berlin campaign replay uses `STARTGELD` 70,000. The profile
and scenario are stored in `WorldSnapshot` and shown in the branch overlay:

```text
profile: mode=FreeGame ... difficulty=9 ...
scenario: mode=FreeGame city=ber name=Berlin map=Ber.iso population=250
          length=11 opponents=[-1, -1, -1] starting_capital=22000
sim: {"open":true,...,"cash":22013.420525,"stock":399.000000,...,"sales":1,...}
```

The same world initializer is used by the windowed branch and the headless
replay, including `--playable-script` and `--replay` command handling.

![Free Play first sale](decompiled_fastfood2_named_v2/samples/free_play_first_sale.png)

![Character selection screen](decompiled_fastfood2_named_v2/samples/character_select.png)

### Playable branch

`pc2-sim` is a deterministic one-branch model. `World` owns the five-minute
clock, the scripted customer visit and the branch economy; the viewer replay
and `pc2-clock` submit the same commands to it. The Python reference sale in
`tests/test_sim_core.py::test_one_sale_python_contract` is stock 400 -> 399 and
cash +13.4205247 after the market cost; Rust produces the same values.

```sh
cargo run -p pc2-app -- \
  --playable --map game/Isokarten/Iso_Filiale_einf_klein.iso \
  --window
```

Controls: `O` open/close, `-`/`+` or Up/Down change price, `Space`/`N` advance
five minutes. The plain built-in overlay shows clock, cash, stock, price, the
last sale and the control legend.

The branch also has visible actors. `m_service_m01.spr` places the waiter at
the counter and `kid_m_sma.ani` supplies 24 customer frames, drawn at 2x. Both
are hidden while closed. The customer appears while the world visit is
waiting, producing or departing, and its animation frame follows the
authoritative world clock.

The headless replay advances one full visit:

```sh
cargo run -p pc2-app -- \
  --map game/Isokarten/Iso_Filiale_einf_klein.iso \
  --replay 'open;step;step;step;step' \
  --output branch_playable_replay.png
```

```text
11:00 hourly dispatch -> arrival
11:05 production start
11:10 sale: stock 400 -> 399, cash 10000 -> 10013.420525
11:15 departure
vulkan: 800x600 readback, 0 byte mismatches
result: OK
```

![Playable branch sale](decompiled_fastfood2_named_v2/samples/branch_playable_sale.png)

### Two-party, one-slot queue

`World` now keeps separate parties with IDs, party size, phase and slot
assignment. The claim/release path follows `0x47d150` (only state `0xd`
targets), `0x409b10` (claim target and record `customer+0x10c`), `0x409c60`
(reuse a `0xb` target), `0x409d40` (queue-first retry) and `0x409d80`
(service-complete release).

```sh
cargo run -p pc2-app -- \
  --map game/Isokarten/Iso_Filiale_einf_klein.iso \
  --replay 'open;step;party;step;step;step;step;step;step;step' \
  --output two_party.png
```

```text
11:00 party 1 arrives; replay queues party 2
11:10 party 1 sells once; party 2 remains queued
11:15 party 1 leaves; party 2 claims the only slot
11:25 party 2 sells once; queue drains
```

`queue_snapshot_json()` exposes every party, slot, phase and 10 ms
`timer_ticks`. The precise timer lane uses `QUEUE_WALK_TICKS` 260,
`PRODUCTION_TICKS` 180 and `SERVICE_TICKS` 80; `advance_queue_ticks` drives
those values without moving the five-minute game clock. A contention snapshot
restores both customers and the claimed slot.

Queue capacity defaults to the existing Python model constant 40 and is
configurable in replay. Capacity 1 rejects the second party immediately,
increments `customers_lost` and leaves stock/cash untouched:

```sh
cargo run -p pc2-app --   --map game/Isokarten/Iso_Filiale_einf_klein.iso   --replay 'capacity=1;open;party;party;step;step;step;step'
```

```text
capacity 1: second party rejected, customers_lost=1
admitted party still sells once: cash 10013.420525, stock 399
```

The capacity threshold itself is a model parameter: the retained branch
export does not expose a proven admission limit. The lost-counter write at
`branch+0x16e0` is static evidence.

The exact timer lane is replayable without advancing the five-minute clock:

```sh
cargo run -p pc2-app -- \
  --map game/Isokarten/Iso_Filiale_einf_klein.iso \
  --replay 'open;party;ticks=259;ticks=1;ticks=180;ticks=80'
```

```text
259+1 queue ticks -> producing
180 production ticks -> sale
80 service ticks -> idle
```

### Camera and city-to-branch transition

`--explore` caches a full 4096×2048 city composite once, then pans an 800×600
crop without reloading the map. `B` switches to the branch interior, branch
controls become active, and `C` returns to the cached city view. Each
crop+overlay+upload measured 31-33 ms on this host.

```sh
cargo run -p pc2-app -- --explore --window
```

```text
explore: city 4096x2048, branch game/Isokarten/Iso_Filiale_einf_klein.iso
explore: city camera 1872,820
explore: city camera 1968,820 crop_us=31848
explore: city camera 2064,820 crop_us=32644
explore: branch
```

![Panned city camera](decompiled_fastfood2_named_v2/samples/city_camera_panned.png)

![City-to-branch transition](decompiled_fastfood2_named_v2/samples/city_to_branch_transition.png)

The generated crop is [berlin_crop.png](decompiled_fastfood2_named_v2/samples/berlin_crop.png)
and the ordered list is [berlin_draws.json](decompiled_fastfood2_named_v2/samples/berlin_draws.json).
An animated frame is [berlin_sway_01.png](decompiled_fastfood2_named_v2/samples/berlin_sway_01.png)
and the branch crop is [branch_einf_klein.png](decompiled_fastfood2_named_v2/samples/branch_einf_klein.png).
`tools/scene_tool.py` independently rebuilds the same 125-entry draw list in
Python; `tests/test_scene_tool.py` asserts it is byte-for-byte identical to the
Rust output.

## Customer visit trace

The branch visit model is documented in
[CUSTOMER_VISIT_TRACE.md](decompiled_fastfood2_named_v2/CUSTOMER_VISIT_TRACE.md).
It links the spawn, entrance, queue, production-worker, recipe-selection and
order-settlement addresses, with timers and queue/stock/cash columns. The three
worked traces cover a successful order (stock 400 -> 399, cash +13.4205247), a
full queue at the 40-seat boundary, and a missing-ingredient early return.
Facts are marked static, inferred, or runtime-pending.

### Function-by-function workflow

Each reverse-engineering batch starts from addresses, not names. This produces a
review packet with bodies, callers, unresolved Ghidra placeholders and bounded
disassembly:

```sh
python3 tools/function_batch.py 0x513bf0 0x5092b0 0x509580 0x47d4a0 \
  --out decompiled_fastfood2_named_v2/RECIPE_ORDER_BATCH.md
```

1. Review the packet and resolve register placeholders against callers or
   disassembly.
2. Record inputs, outputs, state reads/writes and callers in a function card.
3. Add a Rust function and a test named for its original address.
4. Run one combined replay and mark expected values as original runtime, static
   analysis or Python-model evidence.

The recipe batch is documented in
[RECIPE_ORDER_FUNCTIONS.md](decompiled_fastfood2_named_v2/RECIPE_ORDER_FUNCTIONS.md)
and [RECIPE_ORDER_BATCH.md](decompiled_fastfood2_named_v2/RECIPE_ORDER_BATCH.md).
The follow-up skill/quality batch is in
[SKILL_QUALITY_FUNCTIONS.md](decompiled_fastfood2_named_v2/SKILL_QUALITY_FUNCTIONS.md)
and [SKILL_QUALITY_BATCH.md](decompiled_fastfood2_named_v2/SKILL_QUALITY_BATCH.md).
Virtual calls reached by the visit are recorded in
[VIRTUAL_CALL_TRACE.md](decompiled_fastfood2_named_v2/VIRTUAL_CALL_TRACE.md), and
the branch/staff quality fixture in
[PRODUCT_QUALITY_REPLAY.json](decompiled_fastfood2_named_v2/PRODUCT_QUALITY_REPLAY.json)
is checked by `tools/quality_tool.py`.
Disassembly establishes that `extraout_EDX`/`unaff_EDI` in the scorer are
decompiler artifacts: `Game_GetSkillRating` receives
`(recipe, branch, price, category)` and `Player_ComputeProductQualityScore`
receives `(branch, recipe, category)`.

The `0x47d910` callee uses the same customer category for both table lookups.
The [four recovered tables](decompiled_fastfood2_named_v2/PRODUCT_QUALITY_TABLES.json)
are checked byte for byte against the pinned executable by `verify_all.py`.
The quality fixture derives the combined score from the helper outputs using
the original `0x403850` rounding rule and includes two mutation assertions; the
five quality cases and both mutations pass. A rust replay (`quality_95_replay_…`)
uses the row38 quality of 95 to select a price-14 recipe, consume one stock unit
and reconcile cash. Original branch records and runtime comparison remain open.

### Clock replay

The original five-minute worker and hourly handler are documented in
[CLOCK_TRACE.md](decompiled_fastfood2_named_v2/CLOCK_TRACE.md). One `World`
drives the viewer and the CLI. The headless replay logs ordered events and
verifies one full visit, hourly-once, midnight and resume while waiting:

```sh
cargo run -p pc2-sim --bin pc2-clock -- \
  --start 10:55 --end 11:20 --snapshot-at 11:00 --snapshot-resume
cargo run -p pc2-sim --bin pc2-clock -- \
  --start 23:55 --end 00:05 --snapshot-at 00:00 --snapshot-resume
```

```text
11:00 hourly hour=11 index=1
  phase characters ... phase recipes
11:00 arrival queue=1
11:05 production_start
11:10 sale stock=399 cash_delta=13.420525
11:15 departure
hourly_count=1
snapshot_resume=identical
branch_clock=11:20
```

The snapshot is taken while the customer is waiting at 11:00. Restoring it
produces the same production, settlement and departure events, clock, stock
and cash as uninterrupted play.

## Data roots

| Path | Contents |
|---|---|
| `game/fastfood2.exe` | supported executable |
| `game/Isokarten/` | 25 shipped `.iso` maps |
| `extracted/` | PAK entries, sprites, `.tab`, Isodaten, city INIs |
| `decompiled_fastfood2_named_v2/` | named pseudocode, evidence, schemas, samples |
| `decompiled_fastfood2_named_v2/class_skeletons/` | generated per-class field tables |
| `tools/` | parsers, scene cross-check, simulator, verification entry point |
| `tests/` | simulation, map, table, save/fuzz, sprite and scene suites |

## Symbols and pseudocode

- `decompiled_fastfood2_named_v2/full_game_symbols.json` — **3,029** procedure
  names (address → name source of truth).
- `decompiled_fastfood2_named_v2/full_game_verification/functions/` — matching
  named pseudocode bodies.
- `decompiled_fastfood2_named_v2/full_game_verification/decompile-index.json` —
  manifest used by `verify_all.py`.

The earlier `decompiled_fastfood2/` and `decompiled_fastfood2_named/` exports are
historical inputs.

## Generated models

Run from `tools/` in this order, writing into
`decompiled_fastfood2_named_v2/`:

```text
build_class_skeletons.py
build_save_schema.py
build_state_model.py
build_structs.py
```

`build_structs.py` writes `game_structs.h` and `STRUCTS.md`; the C11 syntax
check is part of `verify_all.py`.

## Baseline status

- All **191** Python tests pass: 161 simulation, 13 save/synthetic-fuzz, 7 map,
  5 table, 3 sprite, 1 scene cross-check, and 1 animation test.
- The four generators reproduce **80/80** model files byte-for-byte in a scratch
  checkout; `verify_all.py` runs that check on every verification.
- The Rust inventory reads all **9,142** entries and **448,651,308** payload
  bytes; ``cargo test --all`` covers a synthetic archive and the installed
  corpus.
- `pc2-scene` builds the Berlin crop with **125 ordered draws**, no missing or
  ambiguous layers, and an 800×600 Vulkan readback with zero byte mismatches.
- All **15 branch maps** resolve their sprite background, floor and tile layers;
  the sample `Iso_Filiale_einf_klein.iso` renders 39 ordered draws.
- The `.ani` decoder reproduces the 12-frame tree sway; frame 0/1 hashes are
  stable and the window cycles the prebuilt frames on Vulkan.
- The asset audit reads every **9,142** PAK entry: **7,542 decoded**, **1,600
  header-only**, **0 unsupported**, **0 errors**.
- The Rust replay opens a branch, sells one serving (stock 400 -> 399, cash
  +13.42), keeps a closed branch idle, and changes the next sale after a price
  change. The window exposes the same commands over a plain overlay.
- Free Play carries the committed Berlin scenario and profile through the same
  initializer: difficulty 9 starts at 22,000 and the first sale reaches
  22,013.420525; campaign Berlin starts at 70,000. Windowed and headless runs
  produce the same `sim:` snapshot.
- The rebuilt Free Play Setup screen uses `Pe_Freies_Spiel.tga` and original
  controls `0x4e2`/`0x4e3`. `--free-play-chain` exercises Menu -> Character ->
  Setup, loads the selected city and playable branch, and verifies the first sale.
- `World` serializes two parties through one slot with separate IDs, phases and
  a claimed slot. `--replay 'open;step;party;...'` sells party 1 at 11:10,
  admits party 2 at 11:15 and sells it at 11:25; contention snapshots resume
  with both parties and the slot intact.
- Queue/service phases also expose the original 10 ms unit:
  `advance_queue_ticks` covers 260 queue, 180 production and 80 service ticks.
  A capacity-1 replay rejects the second party and increments `customers_lost`
  without changing stock or cash.
- Two typed packets cover **21 records**, **80 trace steps**, **3 dispatch
  tables** and **8 fixtures**. Every stored instruction prefix matches the
  executable at its PE address; the callbacks at `0x4cc640` and `0x4dd300`
  are recovered outside the named export. The verifier regenerates both
  packets and rejects 15/15 mutation cases.
- A bounded Unicorn fixture executes `Game_GetStartingCapital` `0x48d3a0`
  directly from the PE bytes for difficulty 0..9 and fallbacks 10/255. All
  **12/12** EAX results match, with stop addresses at the original RET.
- A second Unicorn fixture executes the `Game_WindowProc` command mapping.
  `0xfffe79de` reaches `0x405aa9` (index `0x62`, selector 4) and
  `0xfffe79f7` reaches `0x405ae0`; **2/2** cases match.
- The city camera pans a cached 4096×2048 composite and transitions to the
  branch with `B`/`C`; no map or sprite decode is repeated during panning.
- The Rust Vulkan bring-up renders two overlapping textured quads and verifies
  draw order and overlap pixels on the local Vulkan adapter.
- The 360-day Berlin demo is regenerated by `verify_all.py`; the recorded
  player cash is in `SIM_VERIFICATION.json`.
- The original game was **not executed** during this baseline. Pending
  comparisons are printed by `verify_all.py`: paused city/branch crops, two
  controlled saves, one reload of a modified save, one controlled sale, and one
  calendar-boundary event.
- No original `.piz` save or real menu record exists in the workspace; those
  comparisons remain blocked.

## Further reading

- `MODERN_ENGINE_ROADMAP.md` — reviewed roadmap and next milestone.
- `decompiled_fastfood2_named_v2/README.md` — detailed artifact index.
- `decompiled_fastfood2_named_v2/SIMULATION.md` — economy model and formulas.
- `decompiled_fastfood2_named_v2/SAVE_SCHEMA.md` — save writer/reader schema.
- `decompiled_fastfood2_named_v2/ISO_FORMAT.md` — map format.
- `decompiled_fastfood2_named_v2/SPR_NOTES.md` — sprite format.
