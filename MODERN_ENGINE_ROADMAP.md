# Pizza Connection 2 decompilation and engine roadmap

Reviewed 2026-11-18

## Recommendation

The main menu and its Start New Game destination, the character-selection screen, are rebuilt from the original background, fonts and control tables. Use the same evidence-driven pass for the **Continue/Options sub-start menus**, then return to the shared timeline for **two customer parties competing for one service slot**.

For planning, assume one supported executable and an independently authored desktop engine for Linux and Windows. Use the installed game files for local compatibility research and original fixtures for the engine's distributable demo. A byte-matching PE rebuild is a separate objective and should have its own acceptance criteria if the project chooses to pursue it.

## Current state

| Area | What the workspace supports today | What still needs evidence |
| --- | --- | --- |
| Executable and symbols | `game/fastfood2.exe` matches the recorded GOG PE32 target SHA-256. The named verification export matches all 3,029 entries in `full_game_symbols.json`. The v2 top-level manifest matches only 77 of those names, even though both exports contain bodies at all 3,029 addresses. Start with `full_game_verification/functions/` for named pseudocode. | Whole-program typing, indirect dispatch, and observed behavior. Name coverage measures annotation coverage. [Function map](decompiled_fastfood2_named_v2/FULL_GAME_REVERSAL.md) · [Named export manifest](decompiled_fastfood2_named_v2/full_game_verification/decompile-index.json) |
| Layouts and data models | The generators reproduce 77 vtables, 308 slots, 1,573 observed offsets, a save schema, a state model, and 28 packed C structs. All 80 generated files matched byte for byte in a temporary rebuild from the retained export. The generated header passed a C11 syntax check, including its static assertions. | Field semantics and state ownership. Keep legacy offsets in the format and research layer. Give the engine its own types and stable IDs. [Layout generator](tools/build_class_skeletons.py) · [State model](decompiled_fastfood2_named_v2/STATE_MODEL.md) · [Typed structs](decompiled_fastfood2_named_v2/STRUCTS.md) |
| Assets and maps | The Rust audit checks all 9,142 PAK entries. Of those, 7,315 SPR, ANI, TGA and PCX entries went through image or frame decoders. The remaining entries passed format-specific structural or header checks. All 25 shipped maps passed the Python scan, and the Rust scene tests cover all 15 branch templates. | Map placement and blending against the original, actor animation direction and timing, and consumers for fonts, audio, video and other data. Some entries in the audit's decoded count, including fonts and tables, received structural checks. [Asset audit](crates/pc2-audit/src/main.rs#L82) · [Asset matrix](decompiled_fastfood2_named_v2/ASSET_VERIFICATION.json) · [Scene tests](crates/scene/src/lib.rs#L905) |
| Saved games | The generated schema has 38 writers, 368 fields and 31 matching writer/reader field sequences. The reader handles the header, section boundaries, character records, and six player slots. The workspace contains two `.piz` samples, both synthetic. | Verify an original-generated save up front. Company slots and their branch/statistics/storage graphs, actor and map-object payloads, and original-game reload still need coverage. The `verify` command checks outer integrity. Deep checks belong in the section decoders. [Save schema](decompiled_fastfood2_named_v2/SAVE_SCHEMA.md) · [Save parser](tools/piz_payload.py#L262) · [Save-state report](decompiled_fastfood2_named_v2/SAVE_STATE_REVERSAL.md) |
| Simulation | The Python model runs a seeded two-company economy and covers routing, queues, service, stock, pricing, advertising, AI and quarter rollover to varying levels of fidelity. The current 360-day Berlin JSON matches the saved demo byte for byte. | The simulator uses Python's seeded RNG, a modeled wage rate, heuristic interior placement and data fallbacks. Its repeatability and invariants are good regression checks for the model. Matching the original clock, event order, rounding and outcomes needs a comparison against original-game observations. [Simulator](tools/sim_core.py) · [Simulation coverage](decompiled_fastfood2_named_v2/SIMULATION.md#coverage-matrix) |
| Front end | The viewer rebuilds `Screen_MainMenu` from `Pe_Startscreen.tga` and its Start New Game destination `Screen_CharacterSelect` from `Pe_Charakterauswahl.tga`. Both screens use recovered labels, IDs, coordinates and original panel tiles; character gender, four face layers, six attribute arrows, difficulty, 8x8 logo/color portraits and name fields are interactive. Free Play now opens a rebuilt `Screen_FreePlaySetup` from `Pe_Freies_Spiel.tga` with the original Back/Start controls, commits the traced Berlin city/settings and carries them with the profile into `pc2_sim::World`; difficulty drives the verified starting capital. The windowed chain Menu -> Character -> Setup -> first sale matches the headless replay snapshot. | The six character attributes are copied and saved but still have no established branch-economy consumer. Exact font colors, menu music, the credits movie, the Mission Briefing screen, and the Continue/Options sub-start menus still need reconstruction. Original runtime comparisons remain pending. [Menu trace](decompiled_fastfood2_named_v2/MAIN_MENU_TRACE.md) · [Character trace](decompiled_fastfood2_named_v2/CHARACTER_SELECT_TRACE.md) · [Menu sample](decompiled_fastfood2_named_v2/samples/main_menu.png) |
| Modern runtime | The viewer and `pc2-clock` submit the same `open`, `close`, `price` and `step` commands to one headless `World`. The five-minute clock dispatches the hourly update, creates one arrival, and advances that visit through waiting, production, one settlement and departure. A snapshot taken while the customer waits resumes with the same events, clock, stock and cash. | Player movement, multiple customers, queue admission and actor placement still need original evidence. The queue is a one-customer scripting rule, and actor coordinates are fixed. Runtime comparison of the original clock and saves remains pending. [World](crates/sim/src/lib.rs#L379) · [Actor composition](crates/app/src/actors.rs#L97) · [Playable sale](decompiled_fastfood2_named_v2/samples/branch_playable_sale.png) |

`python3 tools/verify_all.py --no-write` passed **39/39 checks**, including the main-menu and character-select replays, quality fixtures, the hourly and midnight clock replay, snapshot resume, the Free Play setup screen and chain, the two-party queue with the 10 ms timer lane and capacity rejection, the typed function packets, both Unicorn fixtures, and the Vulkan branch replay. Original-game comparisons remain pending, and Git history was unavailable in the visible workspace. [Baseline instructions](README.md#quick-start) · [Verification entry point](tools/verify_all.py)

## Completed milestone: one clock, one customer visit

**Done 2026-11-18.** `World` owns the five-minute clock, visit state, queue and
branch economy; `ClockReplay` is an alias. The viewer and `pc2-clock` submit
the same commands. The hourly dispatch creates an arrival at 11:00, production
runs at 11:05, settlement at 11:10, departure at 11:15, and the visit returns
to idle at 11:20. Stock and cash change only at settlement. A snapshot taken
at 11:00 while the customer waits resumes with identical events, clock, stock
and cash. `verify_all.py` covers the full visit, hourly-once boundaries,
midnight and waiting-snapshot resume. [World](crates/sim/src/lib.rs#L379) ·
[Viewer input](crates/app/src/main.rs#L1329) · [Clock replay](decompiled_fastfood2_named_v2/CLOCK_TRACE.md#replay-1-1055--1120-with-a-waiting-snapshot)

## Completed milestone: main menu screen

**Done 2026-11-18.** [MAIN_MENU_TRACE.md](decompiled_fastfood2_named_v2/MAIN_MENU_TRACE.md)
records `Screen_MainMenu 0x476920`, the six labels from `language.ldf`, the
exact control IDs/positions and the `0x4ceb80` dispatch table. `pc2-app --menu`
renders the original 800x600 background with the decoded `TIMESFONT.fnt`,
supports keyboard and mouse selection, and logs deterministic Continue/Quit
actions. `verify_all.py` checks all six rows and the fixed screenshot hash.
[Menu source](crates/app/src/menu.rs) · [Font decoder](crates/assets/src/fnt.rs) ·
[Sample](decompiled_fastfood2_named_v2/samples/main_menu.png)

## Completed milestone: character selection

**Done 2026-11-18.** `Screen_CharacterSelect 0x46dbd0` is rendered from
`Pe_Charakterauswahl.tga` with the recovered appearance, attribute, portrait,
name, difficulty and Logo/color controls. Start New Game/Free resolve the
branch map under `--install` and open character selection; Back returns to the
menu and Start game launches the playable branch. Free Play additionally
commits the traced `Screen_FreePlaySetup` Berlin city/settings and applies the
verified `Game_GetStartingCapital` difficulty table; campaign uses Berlin's
70,000 `STARTGELD`. Window and replay share one initializer. Labels and button
text come from `language.ldf`.
[Character trace](decompiled_fastfood2_named_v2/CHARACTER_SELECT_TRACE.md) ·
[Sample](decompiled_fastfood2_named_v2/samples/character_select.png) ·
[Branch sale](decompiled_fastfood2_named_v2/samples/branch_playable_sale.png) ·
[Screen source](crates/app/src/character_select.rs)

## Completed milestone: typed function packets

**Done 2026-11-19.** `tools/function_batch.py` emits JSON keyed by executable
SHA-256 and address, with curated signatures, dispatch targets, fields
read/written, event order, fixtures and unresolved questions. Two packets are
checked in:

- **Free Play start**: `0x472da0 -> 0x4cbcd0 -> 0x4cc640 -> 0x4052c0 ->
  0x404af0 -> 0x481d90 -> 0x4d44e0`, 10 records and 40 trace steps. Selected
  city, difficulty, population and starting cash reach their first consumers;
  ownership fixtures cover 22,000 at 100% and 24,200 at 110%.
- **Clock worker**: 11 records and 40 trace steps. The disassembly-only worker
  at `0x4dd300` is recovered, `0xfffe79f7` is followed to `0x405ae0`, and
  `0xfffe79de` is followed through the command table to `0x405aa9` and
  `Game_EndOfHour`. Controls `0x411..0x415` map to the city-view
  `KAKANIM*`/`TOMATENANIM`/`SPIDERANIM` pest animations. The wait import at
  `0x55c090` is `KERNEL32!WaitForSingleObject`.

`tools/verify_typed_packet.py` regenerates both JSON and Markdown files,
checks all **80** instruction prefixes against the PE image, validates three
dispatch tables, and rejects **15/15** mutation cases including changed
signatures, control semantics, import identities and missing/changed table
targets. Bounded Unicorn harnesses execute `Game_GetStartingCapital`
(**12/12** cases) and the `Game_WindowProc` command mapping (**2/2** cases:
`0xfffe79de` -> `0x405aa9`, `0xfffe79f7` -> `0x405ae0`).
[Free Play packet](decompiled_fastfood2_named_v2/typed_packets/free_play_start.json) ·
[Clock packet](decompiled_fastfood2_named_v2/typed_packets/clock_worker.json) ·
[Free Play trace](decompiled_fastfood2_named_v2/TYPED_FREE_PLAY_START.md) ·
[Clock trace](decompiled_fastfood2_named_v2/TYPED_CLOCK_WORKER.md) ·
[Batch tool](tools/function_batch.py) · [Unicorn fixture](decompiled_fastfood2_named_v2/typed_packets/fixtures/game_get_starting_capital.fixture.json)

## Completed milestone: two-party queue timers and capacity

**Done 2026-11-19.** `World` carries separate party IDs, party sizes, phases
and slot assignments. Claim and release follow `0x47d150`, `0x409b10`,
`0x409c60`, `0x409d40` and `0x409d80`.

- `--replay 'open;step;party;step;...'` serializes two parties through one slot:
  party 1 sells at 11:10, leaves at 11:15, party 2 claims the slot and sells at
  11:25.
- `advance_queue_ticks` implements the original 10 ms timer lane with 260 queue,
  180 production and 80 service ticks. `Customer.timer_ticks` is serialized.
- Queue capacity is configurable (default 40, the existing model parameter).
  `capacity=1;open;party;party` rejects the second party, increments
  `customers_lost`, and leaves stock/cash untouched.
- A contention snapshot restores both customers, the slot and the capacity.

The capacity threshold is still a model parameter; the retained branch export
does not expose a proven original admission limit. The lost-counter write at
`branch+0x16e0` is static evidence. [World source](crates/sim/src/lib.rs) ·
[Visit trace](decompiled_fastfood2_named_v2/CUSTOMER_VISIT_TRACE.md)

## Next project milestone

**Wire the 10 ms timer lane into the rendered actor cadence and reconcile the
capacity model with original seat data.** The queue ordering and rejection
counter are implemented; the remaining uncertainty is the exact original
admission limit and how the 100 Hz queue timers map onto the viewer's
five-minute simulation cadence. Keep the one-slot and capacity-1 replays as
baselines. [Queue state machine](decompiled_fastfood2_named_v2/full_game_verification/functions/0x409d80.c) ·
[Timer writer](decompiled_fastfood2_named_v2/full_game_verification/functions/0x50d200.c)

## Clock investigation and replay baseline

**Trace the original clock and the first hour boundary.** `GameClock_Construct` registers the thread callback at `0x4dd2d0`. Raw disassembly shows it forwards to `0x4dd300`, a clock worker outside the named export. The worker advances the minute field in five-minute simulation increments and queues command `0xfffe79de` on the hour. The window procedure receives that command and runs `Game_EndOfHour`. Its hourly path updates character ratings, then cities, player missions, companies, and object cleanup. At hour zero it calls the routine named `Game_EndOfQuarter`. Trace the rollover inputs and settle what the routine does on each boundary before using its label to set the schedule. [Thread registration](decompiled_fastfood2_named_v2/full_game_verification/functions/0x4dd270.c#L28) · [Clock fields](decompiled_fastfood2_named_v2/full_game_verification/functions/0x48b3c0.c) · [Command receiver](decompiled_fastfood2_named_v2/full_game_verification/functions/0x4058d0.c#L86) · [Hourly handler](decompiled_fastfood2_named_v2/full_game_verification/functions/0x486590.c)

Use the trace to define a headless replay with a versioned starting state, commands at explicit ticks, and ordered events. Record clock transitions, timestamps, and the queue, stock and cash deltas for one scripted branch. `10:55 → 11:05` proves the hourly update fires exactly once and creates the arrival. `10:55 → 11:20` runs the full waiting, production, settlement and departure visit. `23:55 → 00:05` exercises the midnight hourly/quarter boundary. Restoring a snapshot taken while the customer waits yields the same subsequent events as uninterrupted play. That fixture becomes the place to connect staff, restocking, advertising, AI and save/load as their rules are recovered. Original runtime observations can be added to the same scenario later. [World step](crates/sim/src/lib.rs#L466) · [Serialized clock fields](decompiled_fastfood2_named_v2/full_game_verification/functions/0x4dd4f0.c)

   **Status 2026-11-18:** [CLOCK_TRACE.md](decompiled_fastfood2_named_v2/CLOCK_TRACE.md) records the five-minute worker fields, `0xfffe79de → Game_EndOfHour`, the hourly phase order and the midnight boundary. `pc2-clock` and the viewer share `World`. `verify_all.py` checks hourly-once for 10:55→11:05, the full visit to 11:20, waiting-snapshot resume, and the midnight hourly/quarter boundary. The sale uses stock 400→399 and cash +13.4205247. Runtime capture of the real 3125 ms scheduler, original queue admission and the unresolved `0xfffe79f7` command remain pending.

## Customer-visit decompilation

**Trace one customer visit from the named export.** Use one small branch template, one customer group and a controlled menu. Start with `Branch_ProcessHour` and `Branch_SpawnWalkInCustomer`, then follow the entrance and queue states through `Person_UpdateIndoorAction` and `Object_UpdateCustomerQueue`. Identify the entrance and service markers from the map and follow the actor state and timing through production, service and exit. [Spawn](decompiled_fastfood2_named_v2/full_game_verification/functions/0x477190.c) · [Indoor states](decompiled_fastfood2_named_v2/full_game_verification/functions/0x406e90.c) · [Queue](decompiled_fastfood2_named_v2/full_game_verification/functions/0x409d80.c) · [Map markers](decompiled_fastfood2_named_v2/ISODATEN_FORMAT.md#observed-statistics)

Start the purchase trace at `0x40a380`. That production-worker routine calls `0x509580`, whose current name suggests a menu-edit action. The body computes candidate recipe prices and scores, selects a candidate, and calls `Branch_ProcessCustomerOrder` on the branch. Trace the price input into `0x5092b0` and record when the original checks ingredient availability and changes cash and stock. `Object_IsSiteRatingSufficient` passes zero for the optional price-comparison flag. How price affects the final choice still needs tracing through the scoring and selection code. [Production call](decompiled_fastfood2_named_v2/full_game_verification/functions/0x40a380.c#L105) · [Recipe selection](decompiled_fastfood2_named_v2/full_game_verification/functions/0x509580.c#L59) · [Recipe scoring](decompiled_fastfood2_named_v2/full_game_verification/functions/0x5092b0.c) · [Rating gate](decompiled_fastfood2_named_v2/full_game_verification/functions/0x5080f0.c#L18)

**Deliverable** is one state table with the function address, guard, next state, timer unit and changes to queue, stock and cash at each transition. Add controlled examples for a successful order, a full queue and a failed ingredient check. Mark which facts come from static pseudocode, which are inferences, and which still need runtime observation. Original screenshots and saves are pending, and the existing export is sufficient to start this pass. Use the traced examples to drive the headless simulation and use the resulting actor state for position and animation. [Simulation notes](decompiled_fastfood2_named_v2/SIMULATION.md#exact-hourly-traffic-and-queue) · [Order settlement](decompiled_fastfood2_named_v2/full_game_verification/functions/0x47d4a0.c)

   **Status 2026-11-18:** the state table and three traces are in [CUSTOMER_VISIT_TRACE.md](decompiled_fastfood2_named_v2/CUSTOMER_VISIT_TRACE.md). The successful trace reconciles stock 400 -> 399 and cash +13.4205247; the full-queue boundary and missing-ingredient early return are recorded with confidence labels. Queue-capacity field and cash-ledger split remain runtime observations.

   **Recipe batch:** `tools/function_batch.py` produces a repeatable packet; [RECIPE_ORDER_FUNCTIONS.md](decompiled_fastfood2_named_v2/RECIPE_ORDER_FUNCTIONS.md) records pricing, scoring, selection and settlement cards. Disassembly resolves the scorer's `extraout_EDX`/`unaff_EDI` and gives the returned score formula; Rust tests now cover price, score, rank bands, one sale and shortage. [Batch packet](decompiled_fastfood2_named_v2/RECIPE_ORDER_BATCH.md)

   **Skill/quality batch:** Disassembly establishes the `0x47d910` stack contract and a shared category index for both penalty matrices. The four original tables are recovered and verified directly against the frozen PE. The remaining scorer inputs are representative branch and staff records that exercise the category-5 helpers. [Function cards](decompiled_fastfood2_named_v2/SKILL_QUALITY_FUNCTIONS.md) · [Table fixture](decompiled_fastfood2_named_v2/PRODUCT_QUALITY_TABLES.json)

   **Visit evidence batch:** [VIRTUAL_CALL_TRACE.md](decompiled_fastfood2_named_v2/VIRTUAL_CALL_TRACE.md) resolves the list-cleanup vtable target (`0x401420`) and marks the audio backend slots as runtime-dependent. [PRODUCT_QUALITY_REPLAY.json](decompiled_fastfood2_named_v2/PRODUCT_QUALITY_REPLAY.json) supplies branch/staff inputs and five controlled quality cases; `tools/quality_tool.py` validates them against the recovered tables. Original branch/staff records and runtime cash/queue observations remain.

   **Quality replay correction:** `tools/quality_tool.py` now derives the combined score from `0x47c9a0` and `0x47cb70` through the original `0x403850` rounding step instead of reading a fixture field. `0x47ca80` is capped at 2. The fixture has five table cases plus two mutation assertions (100→0 and 2→0 helper inputs). A Rust replay uses the corrected row38 quality 95 to check recipe choice, stock 400→399 and cash +15.7205247.

### Evidence needed before each subsystem rewrite

1. **Identify the executable paths.** Record entry points, direct and virtual callees, and platform dependencies by original address. Start with virtual calls reached by one customer visit. The [vtable inventory](decompiled_fastfood2_named_v2/vtable_slot_targets.csv) lists 75 unique indirect-only targets that still need bodies or explicit compatibility contracts.
2. **Recover the data contract.** For each required routine, record arguments, return values, fields read or written, table bytes, event order and numeric rounding. For the branch, work outward from `0x47d910` to the category-5 record readers and from order settlement to stock batches and ledger writes. Keep raw offsets and their evidence linked to the function cards. [Branch layout](decompiled_fastfood2_named_v2/class_skeletons/Branch.md) · [Order settlement cards](decompiled_fastfood2_named_v2/RECIPE_ORDER_FUNCTIONS.md)
3. **Assemble repeatable evidence.** Build a fixture set for a successful visit, full queue, and ingredient shortage. Static boundary cases can proceed now. Original comparisons need known branch and staff state, timed events, and before/after cash and stock. Original-generated saves are required to confirm the remaining company and actor sections of the legacy file. [Visit state table](decompiled_fastfood2_named_v2/CUSTOMER_VISIT_TRACE.md) · [Save-state limits](decompiled_fastfood2_named_v2/SAVE_STATE_REVERSAL.md#9-limits-and-next)

## Language and engine architecture

Rust is my default for this project because the first substantial work is reading packed legacy formats and passing decoded data between a loader, scene builder, and renderer. Checked byte reads, explicit integer types and owned data fit that work well. Use one Cargo workspace and start with a few crates that can be tested independently. C++20 with Vulkan is a reasonable choice if the team already has substantially more C++ and Vulkan experience. The same module boundaries apply. [Cargo workspaces](https://doc.rust-lang.org/stable/cargo/reference/workspaces.html)

Use `winit` for window and input, and configure `wgpu` with `Backends::VULKAN` on Linux and Windows. Log the selected adapter and backend and report a clear error if Vulkan initialization fails. This uses Vulkan for rendering while `wgpu` manages resource synchronization and validation. If direct control of Vulkan extensions or synchronization becomes a concrete requirement, use `ash` inside the renderer crate. [Window event handling](https://docs.rs/winit/latest/winit/application/trait.ApplicationHandler.html) · [wgpu backends](https://docs.rs/wgpu/latest/wgpu/struct.Backends.html) · [Adapter diagnostics](https://docs.rs/wgpu/latest/wgpu/struct.AdapterInfo.html) · [ash Vulkan bindings](https://docs.rs/ash/latest/ash/)

| Module | Responsibility and boundary |
| --- | --- |
| `assets` | Mount a user-supplied install directory read-only, index PAKs and loose files, normalize asset keys, and decode legacy formats into owned CPU data. Keep file offsets, path resolution, palette and sprite metadata here. Expose typed asset IDs and errors that identify the source file and entry. |
| `scene` | Turn maps, tiles and objects into a stable ordered list of sprite draws with asset ID, source rectangle, projected destination, and blend mode. Apply anchors and camera transforms here. Test placement, sorting and picking without a GPU. |
| `render` | Own Vulkan-backed surfaces, textures, shaders and uploads. Consume the ordered draw list. Start with CPU-decoded RGBA textures, nearest filtering and explicit blend rules. Batch adjacent compatible draws once measured. Keep transparent draw order stable. |
| `app` | Wire up installation selection, the window, camera input, diagnostics and the viewer. Keep the platform event loop here. |
| `sim` | Add when the first sale can be replayed. Own world state, commands, clock and RNG. Emit snapshots and events, with no dependency on windowing or rendering. |

### C17 option

If the team prefers C, use **C17, CMake, and SDL3 GPU with the Vulkan backend**. Request `"vulkan"` with `SDL_GPU_SHADERFORMAT_SPIRV`, then check `SDL_GetGPUDeviceDriver()` at startup. Keep SDL GPU calls in `render`. If the project requires direct `vk*` calls, use SDL3 for the window and Vulkan surface and let `render` own the device, swapchain, synchronization, and resource lifetimes. [CMake C standard](https://cmake.org/cmake/help/latest/prop_tgt/C_STANDARD.html) · [SDL GPU device](https://wiki.libsdl.org/SDL3/SDL_CreateGPUDevice) · [Backend check](https://wiki.libsdl.org/SDL3/SDL_GetGPUDeviceDriver) · [SDL Vulkan surface](https://wiki.libsdl.org/SDL3/SDL_Vulkan_CreateSurface)

- Make `assets`, `scene`, and `render` separate static library targets. Let `app` link them into the viewer and add `sim` when the headless work starts. Use opaque handles for objects that own resources and plain structs for decoded data and sprite draws. Document who frees each buffer and use paired creation and destruction functions. Present future enhancements through the same asset IDs, ordered draws, and simulation commands.
- Parse the legacy files with a shared bounded reader for explicit little-endian fields. Check offsets, counts, and allocation sizes before reading or allocating. Use the generated C structs as layout references and decode file bytes field by field into runtime types. Run the decoder fixture tests with AddressSanitizer and UndefinedBehaviorSanitizer in a Clang build. [Generated layouts](decompiled_fastfood2_named_v2/STRUCTS.md) · [Clang sanitizer options](https://clang.llvm.org/docs/UsersManual.html)
- First deliver a headless archive inventory and two overlapping textured quads on Vulkan. Then connect the ISO and SPR decoders to the scene builder and render the Berlin crop. The asset coverage and reference-image acceptance checks below apply to either language.

### Make original asset support measurable

- Open the **five PAKs and the loose files from the installation itself**. Use archive offsets for on-demand reads, and keep any decoded cache outside the installation. Verify original lookup and override rules before claiming precedence parity. The extracted PNGs remain useful comparison samples, while the loader needs the original sprite headers for canvas, hotspot, palette and blend information. [Archive format](decompiled_fastfood2_named_v2/PAK_FORMAT.md) · [Original resource lookup](decompiled_fastfood2_named_v2/pak_layer_final/functions/0x402290.c) · [Sprite format](decompiled_fastfood2_named_v2/SPR_NOTES.md)
- Define two checks. Inventory coverage means all **9,142 archive entries** can be enumerated and read as bytes, alongside the known loose inputs. Format coverage means each asset family can be decoded or opened by its actual consumer, with unsupported files listed by path. Prioritize `.iso`, `Isodaten.idx` and `.spr` for the city viewer. Add `.sty`, `.ani`, `.fnt`, localization, tables and audio as their consumers arrive, and explicitly track remaining formats including Bink movies. Keep the real-install corpus check local and use synthetic fixtures in CI. [Map format](decompiled_fastfood2_named_v2/ISO_FORMAT.md) · [Isodaten format](decompiled_fastfood2_named_v2/ISODATEN_FORMAT.md) · [Asset inventory](decompiled_fastfood2_named_v2/pak_index.csv)

### Leave room for enhancements

Keep the ordered scene output independent of the renderer. That gives you a place to add widescreen, high-DPI UI, texture filtering, or an optional lighting pass without touching map parsing or simulation. Start with nearest filtering and the original zoom variant in a reference preset. Define enhanced camera and presentation settings explicitly. For replacement textures or mods, add a versioned asset overlay with explicit priority and original asset IDs. Introduce a scripting or plugin API once an enhancement needs a stable extension point.

## Viewer milestones and pending reference capture

1. **Make one branch playable in the existing viewer.** Give a small headless `pc2-sim` module one branch, one recipe, a starting balance and stock, and a scripted customer. Add `SetOpen`, `SetPrice` and `Step` commands with a snapshot for clock, cash, stock, servings and the latest transaction. Give the window an original, plain overlay and a control for each command. **Done when** opening the branch and stepping produces a visible sale, closing it prevents sales, and changing price changes the next sale under the same inputs. A headless test should replay the commands and get identical snapshots, with exact stock changes and a reconciled cash delta. Use the existing order and ledger tests to derive an expected result from the Python model. [Python order processing](tools/sim_core.py#L3117) · [Ledger test](tests/test_sim_core.py#L1556) · [Window input](crates/app/src/main.rs#L710)

   **Status 2026-11-18:** done. `pc2-sim` reproduces the Python sale exactly (stock 400 -> 399, cash +13.4205247), exposes `SetOpen`, `SetPrice` and `Step`, and has four replay tests. The window overlay and controls are active; the replay PNG checks cash, stock and the last sale through Vulkan.

2. **Collect original reference data alongside gameplay.** Capture a paused Berlin crop and branch interior at known zoom, an original manual save, and a second save after one controlled change. If possible, record the before/after stock and cash for one isolated sale. Record the executable hash, game time, inputs and values observed. Compare the first capture with the viewer and inspect the two saves read-only before attempting edits. [Original-game comparisons](decompiled_fastfood2_named_v2/VIEWER_VERIFICATION.json) · [Save tooling](tools/piz_payload.py)

   **Status 2026-11-18:** blocked; Wine capture was dropped by request. No original screenshot or manual save was collected.

3. **Add movement, then measure rendering.** Give the two working scenes a camera and a city-to-branch transition. Cache the parsed map and decoded assets across camera updates. Keep the CPU-composited crop as the reference image. Measure camera updates before moving sprite composition to Vulkan, where the existing ordered draw list provides a testable input. [Scene builder](crates/scene/src/lib.rs#L173) · [Vulkan presentation](crates/app/src/main.rs#L590)

   **Status 2026-11-18:** done for one city/branch pair. A cached 4096x2048 city composite pans without re-decoding (31-33 ms per 800x600 CPU crop+overlay+upload on this host), and `B`/`C` switches between city and the playable branch.

## After the milestone

- **Grow the playable loop.** Add a steady stream of customers, a stock refill decision and one daily objective. Use controlled inputs to compare service order, stock, cash and ledger deltas. Establish original RNG and clock ordering before comparing seeded timelines, then extend the replay to calendar boundaries and report the first divergent event. [Order economics and timing](decompiled_fastfood2_named_v2/SIMULATION.md) · [Simulator data fallbacks](tools/sim_core.py#L66)
- **Expand save compatibility from real data.** Use the controlled save pair to pick the first company/branch fields to decode. Follow the writer/loader pair, track exactly how much of each bounded section is consumed, and retain opaque data when inspecting unsupported records. Start with read-only import and compare parsed values with the original UI. Gate legacy export on the original opening a modified copy and showing the intended state. [Save layout](decompiled_fastfood2_named_v2/SAVE_SCHEMA.md) · [Payload tooling](tools/piz_payload.py)
- **Add rivals and campaign behavior after the loop is replayable.** Feed snapshots into the scene builder as moving actors and other state begin to affect the view. Add audio and broader content coverage as their consumers arrive. [Platform map](decompiled_fastfood2_named_v2/subsystems.md) · [Simulation coverage](decompiled_fastfood2_named_v2/SIMULATION.md#coverage-matrix)

## Reproduce the review checks

From the workspace root, with the matching local data already available:

```sh
sha256sum game/fastfood2.exe
PYTHONDONTWRITEBYTECODE=1 python3 -m unittest discover -s tests
python3 tools/iso_tool.py scan game/Isokarten
python3 tools/isodaten_tool.py info extracted/isodaten/isodaten.idx
python3 tools/sim_core.py demo --days 360 --city extracted/daten/ber.ini --json
printf '#include "decompiled_fastfood2_named_v2/game_structs.h"\n' | cc -x c -std=c11 -fsyntax-only -
```

Expected executable SHA-256 is `18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd`. To regenerate the data models, use a scratch copy and run `build_class_skeletons.py` and `build_save_schema.py`, then `build_state_model.py`, then `build_structs.py` from `tools/`. Those generators write into the v2 directory.
