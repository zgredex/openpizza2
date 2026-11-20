# pcrecomp PC2 native bring-up

Pinned, reproducible native-Linux bring-up for the static recompilation of
Pizza Connection 2. It runs the **shipped** `fastfood2.exe` as lifted C on a
32-bit Linux host through `pcrecomp` and `win32hle`; no Wine, no JIT.

## Pinned inputs

| Input | Pin |
|---|---|
| `game/fastfood2.exe` | SHA-256 `18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd` |
| pcrecomp | commit `621860a9d22c9b25ae2be4575b956596f4ddaeeb` |
| SDL2 | 2.30.9, SHA-256 `24b574f71c87a763f50704bbb630cbe38298d544a1f890f099a4696b1d6beba4` |
| SDL2_ttf | 2.22.0, SHA-256 `d48cbd1ce475b9e178206bf3b72d56b66d84d44f64ac05803328396234d67723` |
| Python packages | capstone 5.0.7, pefile 2024.8.26, unicorn 2.1.4 |

The recipe was tested with GCC 16.2.1, CMake 4.5.0 and Ninja 1.13.2 on Arch
Linux. It builds 32-bit SDL2/SDL2_ttf into a private sysroot; no root or
`sudo` is required.

## Run

```bash
tools/pcrecomp_pc2/build.sh
```

For headless input replays, guest function traces, and state capture, see [Lifted PC2 trace capture](TRACE_CAPTURE.md).

The default work directory is `/tmp/opencode/pcrecomp-pc2`; override it with
`PC2_WORK=/path`. Existing SDL builds, the lift and host objects are reused.

The script:

1. verifies the executable SHA-256;
2. checks out the pinned pcrecomp commit;
3. builds 32-bit SDL2 and SDL2_ttf (vendored FreeType) into the private sysroot;
4. lifts `fastfood2.exe` into C with `python -m tools ... --all`;
5. builds the host from this directory against the tested
   `runtime/win32hle` and `runtime/recomp32`;
6. runs it headlessly from the PE entry `0x0054FCD4` with the permissive import
   binder, `SDL_VIDEODRIVER=dummy`, and `HLE_FILETRACE=1`;
7. checks for entry into WinMain and the archive/string assets.

## Verified trace

```text
[host] fastfood2.exe booted: entry 0x0054FCD4, 0 unresolved imports
[trace] entered WinMain at 0x00403D90
[file] CreateFileA "...\resources\update.pak" -> ... ok
[file] CreateFileA "...\resources\main.pak"   -> ... ok
[file] CreateFileA "...\resources\movie.pak"  -> ... ok
[file] CreateFileA "...\resources\iso.pak"    -> ... ok
[file] CreateFileA "language.ldf"             -> language.ldf ok
[file] CreateFileA "resources\sound.pak"      -> Resources/sound.pak ok
[ddraw] SetDisplayMode(800x600x16)
[ddraw] CreateSurface 800x600 16 bpp caps 0xA18 primary -> ...
[trace] Movie_Play enter
[trace] Movie_Play return
[trace] Movie_Play enter
[trace] Movie_Play return
[file] CreateFileA "C:\test.spr" -> /tmp/opencode/pc2-cdrive/test.spr ok
[trace] Map_LoadIsodata enter
[trace] Map_LoadIsodata return
[trace] GameMain enter
[trace] GameLoop pending=21
[trace] Screen_MainMenu enter
[trace] Screen_MainMenu return
[trace] GameLoop pending=0
```

`0x0054FCD4` is the MSVC CRT entry; it calls `WinMain` at `0x00403D90`.
The first gap found on the way there was `GetCommandLineA`: the runtime's
default `game.exe` has no path separator, so WinMain derived the base `"g"`
and looked for `gresources\main.pak`. The host now passes the real guest path
as the command line.

The second gap was six unshimmed imports:

| Import | Stub behavior |
|---|---|
| `USER32!IsIconic` | 0 |
| `USER32!GetSystemMenu` | 0 |
| `USER32!SetClassLongA` | 0 |
| `USER32!UnregisterClassA` | 1 |
| `comdlg32!GetSaveFileNameA` | 0 (cancel) |
| `binkw32!_BinkGetSummary@8` | zero the summary, return 0 |

They live in `pc2_shims.c`; the shared runtime is unmodified.

## Current status

- Whole-image lift: 9,277 functions, 0 lift failures. The repo lift driver
  seeds `WorldObject_Delete 0x00504980`, `CRT_LocalUnwind2 0x00553C9D` and
  the exception-filter registration routine `0x00555F68`; `build.sh` relifts
  if any of those addresses is missing from the dispatch table.
- Native host: links 32-bit, runs from CRT entry `0x0054FCD4` through WinMain
  `0x00403D90`, both `Movie_Play` calls, `Map_LoadIsodata 0x004EA440` and into
  `GameMain 0x004043E0`.
- The four PC2 `.pak` archives, `language.ldf`, `sound.pak`, the loading image
  and the main-menu assets (`PE_STARTSCREEN.TGA`, `TIMESFONT.fnt`,
  `TEXTPBTRANSPGELB_*.spr`) open successfully through `Resource_Open`.
- The front-end dispatcher reaches `GameLoop_DispatchScreens 0x004052C0`,
  pending screen `0x15`, calls `Screen_MainMenu 0x00476920`, and returns to
  pending screen `0`. `Resource_Open` returns non-zero for `clipsprite.spr`,
  `rklick_00.spr`, `mission.txt` and the menu assets; the loose-file
  `CreateFileA` failures are fallback probes, not the lookup result.
- **The main menu is now presented.** The host arms
  `g_Window_RenderFrame_Flag_00584504` and clears
  `g_Surface_BlitRectRetry_Flag` after boot, which lets
  `UI_RenderScene`/`UI_ProcessChildEvent` draw. `Window_RenderFrame` still
  takes `Surface_BlitRectRetry 0x00538DA0` (the `Window+0x1BC` GDI branch is
  unchanged), and the tracked DirectDraw primary is still black.
- The presenter bridge is host-side and does not alter the guest branch or
  object layout: after `Screen_MainMenu`, `hle_dd_frame_hook` returns the
  completed 800x600 16bpp buffer at `renderer+0x28`. The first eight frames
  remain blank because the menu has not been built yet; the dump happens after
  `Screen_MainMenu` returns and `GameLoop pending` is `0`.
- Verified headless menu frame:

```text
menu frame: 800x600, 458 colors,
sha256=1abdbb3fffaa31003b9d17fbbea7d92a0d306762095ad7fb0d45b3bcea0a6e2b
```

  `build.sh` checks that digest whenever `PC2_FRAME_DUMP` is set.
- **DirectDraw trace:** `PC2_TRACE_DDBLT=1` captures the first menu blits
  with the dirty rectangle before and after clipping, the source/destination
  IDs and formats, the HRESULT, and the destination checksum after the copy:

```text
DDBLT d=4106965568 primary=0 800x600 bpp=16 pitch=1600
      rect=0,0..800,600
      s=4106965392 800x600 bpp=16 pitch=1600 rect=0,0..800,600
      keyed=0 srcsum=E50455C5 dstsum_before=E50455C5
DDBLT clip before=0,0..800,600 after=0,0..800,600
      src_after=0,0..800,600 bpp=16 keyed=0
DDBLT post d=4106965568 primary=0 pitch=1600 bpp=16
      hr=0x00000000 DD_OK dstsum_after=E50455C5 copy=1
```

  The post-copy destination is still blank, which is why the game's completed
  renderer buffer is presented instead of the tracked primary.
- **Cursor:** PC2 installs `LoadCursorA(NULL, IDC_ARROW)` as its window-class
  cursor and does not draw a software cursor into the picture. `win32hle`
  hides the SDL cursor unless `hle_screen_cursor_hook` is set, so the running
  window had no pointer. The host now sets the hook to `hle_cursor_shown()`;
  the trace prints `[screen] cursor: the system arrow`.
- **Campaign path:** `PC2_CLICK_START=1` clicks `Start new game` at
  `(650,18)`. With `PC2_START_CAMPAIGN=1` the host also clicks
  `Start game` at `(700,566)` and `Start Mission` at `(680,560)`.

```text
pending=21 Screen_MainMenu
  -> click -> pending=28 Screen_CharacterSelect
  -> click -> pending=22 Screen_MissionBriefing
  -> click -> pending=23 Game_RunSession
```

  A late preview dump (`PC2_GAME_DUMP_DELAY=2000`) contains the London
  welcome dialog and the `Town aims` panel.
- **Verified lease:** the replay below opens the `Rent buildings` panel,
  clicks the offer (`Lease` at `745,500`), confirms the `Do you want to lease
  this building for 2812$?` dialog (`O.K.` at `740,581`), and owns the branch.
  The bounded `Player_CreateBranch 0x004F7420` checkpoint reports:

```text
BRANCH before player=E600750 site_id=0 site=F41E8050 slot=0 type=0 flags=1
      branch_id_before=-1
BRANCH after player_slot=0 site_id=0 site=F41E8050 branch_id=100000
      site+2c=100000
```

  The human player slot is `0`; the site's branch ID changes from `-1` to
  `100000`. The HUD cash changes from `500000` to `496188` and the clock
  advances from `00:05` to `00:10`. `Game_EndOfHour 0x00486590` enters and
  returns repeatedly afterward. The Rust campaign uses the same site, branch
  ID, and total debit (`2812` quoted rent + the `1000` HUD difference recorded
  as a fee) and starts with an empty pantry. Its campaign preparation uses
  `London 1` storage ID `100000`, supplier `Central Market Partners`, and the
  verified first-order inputs; see `README.md` under Campaign Start.
- **Exception handling:** the startup registration routine `0x00555F68` is
  now lifted and dispatchable, but `win32hle`'s
  `SetUnhandledExceptionFilter` shim returns `0` and `RaiseException` exits.
  Filter registration runs; actual guest exception delivery is still
  unverified.

Replay command:

```bash
cd game
LD_LIBRARY_PATH=/tmp/opencode/pcrecomp-pc2-fresh/sysroot32/lib \
SDL_VIDEODRIVER=dummy SDL_AUDIODRIVER=dummy PC2_HEADLESS=1 \
PC2_TRACE_FRAMES=1 PC2_CLICK_START=1 PC2_START_CAMPAIGN=1 \
PC2_TUTORIAL_CLICKS=2 PC2_TUTORIAL_START=1000 PC2_TUTORIAL_INTERVAL=400 \
PC2_LEASE_CLICK=1 PC2_LEASE_DELAY=1700 PC2_LEASE_X=745 PC2_LEASE_Y=500 \
PC2_CONFIRM_CLICK=1 PC2_CONFIRM_DELAY=400 \
PC2_POST_LEASE_CLICKS=8 PC2_POST_LEASE_START=2300 PC2_POST_LEASE_INTERVAL=150 \
PC2_GAME_DUMP_DELAY=3800 \
PC2_RAW_DUMP=/tmp/opencode/pcrecomp-pc2-fresh/london-lease \
timeout 360s /tmp/opencode/pcrecomp-pc2-fresh/pc2-native/pc2 fastfood2.exe
```

## London staffing checkpoint

The staffing replay follows the in-game tutorial to City Administration and
the Employment Office. The `Go to` action centers a city building of type
`25`. Clicking the building at `(299,412)` reaches `UI_CreateInfoPanelPolice`.
The Employment Office tab at `(581,506)` opens `Screen_PersonnelOverview`.

The replay hires a cook (role `0`), a service employee (role `2`), and two
errand workers (role `3`). The `Company_AssignEmployee` trace checks each
person's recorded player slot and branch ID as well as their presence in the
branch roster. In the verified run, human slot `0` owns branch `100000`, and
its roster grows from zero to four. Employee IDs in that run were `100280`,
`100300`, `100310`, and `100312`. Candidate IDs may vary with simulation timing.

```sh
python3 tools/pcrecomp_pc2/capture.py run \
  tools/pcrecomp_pc2/scenarios/london-staff.json \
  --work /tmp/opencode/pcrecomp-pc2-fresh \
  --out /tmp/pc2-london-staff --timeout 150 --max-events 0
```

The replay stops when branch `100000` has four employees. Read the `STAFF`
lines in `host.log` and the final watches in `report.json`.

## London opening and first sale

The operations replay starts with the same lease and hires. It creates a
tomato-and-cheese recipe, adds it to Atrium's menu, leases the `London 1`
warehouse, chooses Central Market Partners, and enables deliveries to
Atrium. The simulation runs through its normal opening schedule and stops
at the 14:00 checkpoint.

```sh
python3 tools/pcrecomp_pc2/capture.py run \
  tools/pcrecomp_pc2/scenarios/london-operations.json \
  --work /tmp/opencode/pcrecomp-pc2-fresh \
  --out /tmp/pc2-london-opening-day --timeout 750 --max-events 0

rg 'BRANCH_HOUR|SALE Branch_ProcessCustomerOrder|PAYMENT slot=0' \
  /tmp/pc2-london-opening-day/host.log
```

Use the lines for slot `0` and branch `100000`. An open hour shows
`scheduled=1` and `roster=4`. A successful `SALE` has positive servings,
lower stock, an additional recipe sales record, and positive revenue.
Match its customer ID to a `PAYMENT` line and check that the player's
cash increased by the payment amount. Both traces are enabled by
`PC2_TRACE_SALES=1`. The replay waits for the clock, so check the
transaction in `host.log` as well as the final state in `report.json`.

The verified run reached 14:00 with all 96 replay steps complete and zero
unresolved edges in the recorded phases. Atrium opened at 06:00 and
received stock by 09:00. Customer `100017` consumed `16100` stock units
(`400000` to `383900`), created the recipe's first sales record, and paid
`1387.28`. The human player's cash increased from `492135.14` to
`493522.42`. A second customer payment of `1354.92` also cleared before
the checkpoint.

## Reload checkpoint and paid order

The pre-order checkpoint is a real `.piz` written by the game's
`SaveGame_Write` routine. The disposable fixture is:

```text
/tmp/opencode/pc2-save-fixture/atrium-before-first-order.piz
```

It loads at 08:05 with player slot `0`, branch `100000`, four employees,
cash `493015.00`, and stock `200000`. The source state is the London
operations run's 08:05 autosave. The `london-save-checkpoint` scenario
re-emits it through the game writer and traces `SaveGame_Write`:

```sh
python3 tools/pcrecomp_pc2/capture.py run \
  tools/pcrecomp_pc2/scenarios/london-save-checkpoint.json \
  --work /tmp/opencode/pcrecomp-pc2-fresh \
  --out /tmp/pc2-london-save --skip-build --timeout 60
```

The generated slot is `game/Save/Games/auto_001.piz`; the fixture copy is
what the reload replay uses. The fresh-process reload is:

```sh
python3 tools/pcrecomp_pc2/capture.py run \
  tools/pcrecomp_pc2/scenarios/london-reload.json \
  --work /tmp/opencode/pcrecomp-pc2-fresh \
  --out /tmp/pc2-london-fixture-reload --skip-build --timeout 750 \
  --max-events 0
```

The reload waits for the saved clock, verifies branch `100000`, player
slot `0`, and four employees, then runs to 14:00. The verified trace is:

```text
BRANCH_HOUR slot=0 branch=100000 hour=9 scheduled=1 roster=4 stock=200000
SALE Branch_ProcessCustomerOrder slot=0 branch=100000 servings=100
     stock=400000->383900 records=0->1 revenue=1387.28 customer=100017
PAYMENT slot=0 branch=100000 customer=100017 amount=1387.28
     cash=492344.45->493731.73
snapshot checkpoint-14 cash=494638.71 hour=14
```

The lower stock, first sales record, and matching payment prove the
restaurant menu and stock survived the reload and the vehicle completed a
paid order in a fresh process. The fixture is the reference state for the
Rust customer-visit port.

## Captured order inputs

`PC2_TRACE_SALES=1` logs the inputs before `Branch_ProcessCustomerOrder`
and keeps the stock-consuming `SALE` and cash-crediting `PAYMENT` as
separate events. `ORDER_INPUT` carries the menu price and bits, the recipe
pointer and stable quantity fingerprint, the ingredient sum, the active
stock batches, the tip base, and the clock. `ORDER_RATING` carries the
customer-group rating. The verified reload run has two consecutive orders
with different recipes and prices:

```text
ORDER_INPUT clock=11:09 customer=100017 menu_price=12.42636204
            recipe=E9312127 ingredients=194 tip_base=31 stock=200000
ORDER_RATING customer=100017 rating=65 tip_base=31
SALE        stock=200000->180600 records=0->1 revenue=1454.38
            recipe_hash=E9312127 tip=17
PAYMENT     customer=100017 amount=1454.38 cash=492401.80->493856.19

ORDER_INPUT clock=12:01 customer=100004 menu_price=11.85281086
            recipe=01437164 ingredients=161 tip_base=42 stock=580600
ORDER_RATING customer=100004 rating=66 tip_base=42
SALE        stock=580600->564500 records=0->1 revenue=1328.01
            recipe_hash=01437164 tip=12
PAYMENT     customer=100004 amount=1328.01 cash=493856.19->495184.20
```

The stock drop is `ingredients * 100`: `19,400` and `16,100`. The native
tip is `max(0, (rating - tip_base) >> 1)`; the revenue is
`(100 + tip) * 100 * menu_price * 0.01 + 0.5`, stored as a 32-bit float.
The different recipe fingerprints each start their own sales record.

The two paid orders above come from:

```sh
python3 tools/pcrecomp_pc2/capture.py run \
  tools/pcrecomp_pc2/scenarios/london-reload-20.json \
  --work /tmp/opencode/pcrecomp-pc2-fresh \
  --out /tmp/pc2-london-orders --timeout 1200 --max-events 0
```

The run completes at 20:00 with branch `100000`, player slot `0`, four staff,
and cash `496362.49`. The Rust predictor uses only the first two paid orders;
the later simulation activity is not part of the transaction comparison.

## Rust customer-visit fixture

`pc2-sim` now has a `World::london_checkpoint()` fixture carrying the saved
state: branch `100000`, player slot `0`, four employees, saved cash
`493015.00`, saved stock `200000`, and the next customer ID `100017`. The
focused pre-order checkpoint is 10:55; the operational costs and delivery
before the visit leave `492344.45` cash and `400000` stock at the order.

```sh
cargo test -p pc2-sim london_checkpoint_completes_one_customer_visit
```

The test advances through the native visit cadence: arrival at 11:00,
production at 11:05, sale at 11:10, and departure at 11:15. It asserts the
branch ID and staff count, one sales record for customer `100017`, the exact
native stock drop `400000 -> 383900`, revenue `1387.28`, and cash
`492344.45 -> 493731.73` (the native `SALE`/`PAYMENT` delta).

The two-order predictor uses the captured inputs directly:

```sh
cargo test -p pc2-sim london_two_orders_predict_from_captured_inputs
```

It asserts the two different recipe fingerprints, the captured ratings and
tip bases (tips `17` and `12`), the exact stock drops (`19,400` and
`16,100`), one sales record per recipe, the computed revenues
(`1454.3843994140625` and `1328.0147705078125`), and the separate payment
credits (`492401.80 -> 493856.19` and `493856.19 -> 495184.20`). The
`pc2-sim` suite has 31 passing tests.

To verify the menu frame through the recipe:

```bash
PC2_WORK=/tmp/opencode/pcrecomp-pc2-fresh \
PC2_FRAME_DUMP=/tmp/opencode/pcrecomp-pc2-fresh/menu.ppm \
tools/pcrecomp_pc2/build.sh
```

## Crash fixed after the intro

Before the C: mapping, the run reached the loading-screen path and crashed:

```text
CreateFileA "C:\test.spr" -> No such file or directory
SIGSEGV in hle_enter_cs (ecx=0)
  k_EnterCriticalSection <- shim_entry
  sub_00550877 (CRT_LockFile)
  sub_0054FB27 (CRT_FwriteLocked)
  sub_0053D160 (Sprite_Serialize)
  sub_0052A440 (UI_Bar_BuildGradientFill)
  sub_00528930 (UI_Bar_Construct)
  sub_0052FC00 (UI_CreateSlider)
  sub_00406910 (UI_ShowLoadingOverlay)
  sub_00474B90 (LoadingWindow_Create)
  sub_00403D90 (WinMain)
```

`C:` is now mapped to a writable host directory (`PC2_CDRIVE`, default
`/tmp/opencode/pc2-cdrive`), so `C:\test.spr` succeeds and the run continues
through `Map_LoadIsodata` into `GameMain`.

Generated C and the pcrecomp clone stay in `PC2_WORK` and are not committed.
