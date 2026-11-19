# Pizza Connection 2 — named decompilation (REA)

This is the readable decompilation of `game/fastfood2.exe` with evidence-based
function names applied in REA. Start with `subsystems.md`, then browse
`functions/0x<address>.c`.

## Target

| Field | Value |
|---|---|
| Game | Pizza Connection 2 / Fast Food Tycoon II v1.004 (GOG) |
| Executable | `game/fastfood2.exe` |
| Format | PE32, Intel i386, Windows GUI |
| Image base | `0x400000` |
| Entry point | `0x54fcd4` |
| PE timestamp | 2000-12-15 08:20:54 UTC |
| SHA-256 | `18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd` |
| Analysis | REA → Ghidra 12.2 (full auto-analysis) |

The GOG installer was unpacked with `innoextract 1.9` into `game/`. The game code
is one native executable; `binkw32.dll` is the third-party Bink video runtime.

## What is in this folder

| Path | Contents |
|---|---|
| `functions/0x<address>.c` | 3,919 Ghidra pseudocode bodies |
| `decompile-index.json` | Manifest: address, name, body ranges, file, SHA-256 |
| `symbols.csv` | 58 proposed names with confidence, annotation status and evidence |
| `leaf_symbols.csv` | **480/480** leaf-function names (complete ledger) |
| `LEAF_REVERSAL.md` | Leaf inventory, all passes and completion verification |
| `leaf_verification/` | Fresh export proving 480/480 leaves are named |
| `func_symbols.csv` | **2471** named non-leaf functions (full 3,029-function game map complete) |
| `FUNCTION_REVERSAL.md` | Non-leaf depth-1 wave, candidates and method |
| `DEPTH2_REVERSAL.md` | Depth-2 wave status and candidates |
| `DEPTH3_REVERSAL.md` | Depth-3 wave status and candidates |
| `DEPTH4_REVERSAL.md` | Depth-4 wave status and candidates |
| `DEPTH5_REVERSAL.md` | Depth-5 wave completion report |
| `DEPTH6_REVERSAL.md` | Depth-6 wave completion report |
| `DEPTH7_REVERSAL.md` | Depth-7 wave completion report |
| `DEPTH8_REVERSAL.md` | Depth-8 wave completion report |
| `DEPTH9_REVERSAL.md` | Depth-9 wave completion report |
| `DEPTH10_REVERSAL.md` | Depth-10 wave completion report |
| `LAYERS11_21_REVERSAL.md` | Layers 11–21 completion report |
| `FULL_GAME_REVERSAL.md` | **Full 3,029-function map completion report** |
| `VTABLES_AND_CLASSES.md` | **77 vtables, 308 slots, 1,575 observed field offsets** |
| `vtables_full.csv` | Canonical vtable table with class, ctor/dtor, base and slots |
| `class_skeletons.json` | Machine-readable class skeletons and field offsets |
| `vtable_slot_targets.csv` | All 308 slots with procedure/indirect-only status |
| `subsystems.md` | Architecture, startup flow, screens, resources, class model |
| `PAK_FORMAT.md` | Reverse-engineered `ResourceFile-ID-7654` header/index/entry spec |
| `pak_index.csv` | All 9,142 archive entries with archive, size, offset and metadata |
| `pak_layer_final/` | Named pak loader/decoder/lookup functions (`Pak_Open`, `Pak_DecodeIndex`, `Pak_FindEntry`, `Resource_Open`) |
| `PIZ_FORMAT.md` | `.piz` header, directory and payload order |
| `../tools/piz_payload.py` | `.piz` parser/editor and synthetic save generator |
| `../tools/isodaten_tool.py` | `Isodaten.idx` parser |
| `../tools/iso_tool.py` | `.iso` parser, path graph, CSV/JSON and PNG preview |
| `../tools/tab_tool.py` | `Size.tab` / `Ingredients.tab` decoder |
| `../tools/sim_core.py` | Headless economy simulator |
| `../tests/test_piz_payload.py` | End-to-end save/struct tests |
| `../tools/fuzz_piz.py` | Deterministic `.piz` synthetic-save fuzz oracle |
| `../tests/test_piz_fuzz.py` | 200-seed + boundary fuzz tests (7) |
| `../tests/test_iso_tool.py` | End-to-end map parser tests |
| `../tests/test_tab_tool.py` | `.tab` decoder tests |
| `../tests/test_sim_core.py` | Economy model validation tests |
| `SAVE_SCHEMA.md` | **38 writers, 368 fields, 141,342 fixed payload bytes** |
| `save_schema.json` | Machine-readable save field order, sizes and loader pairs |
| `STATE_MODEL.md` | Merged vtable field model + save model (318 confirmed persistent fields) |
| `state_model.json` | Machine-readable class/state coverage |
| `SAVE_STATE_REVERSAL.md` | Parser/editor, typed structs, globals and Isodaten report |
| `game_structs.h` | 28 packed C structs with exact offsets and padding |
| `STRUCTS.md` | Per-struct typed field tables |
| `ISODATEN_FORMAT.md` | `Isodaten.idx` sprite dictionary format |
| `ISO_FORMAT.md` | City and branch `.iso` map format |
| `iso_validation.csv` | All 25 maps with grid/object/tile counts |
| `iso_previews/` | 25 occupancy previews (PNG) |
| `SIMULATION.md` | Full hourly/daily/weekly/quarterly model and formulas |
| `AI_ACTION11_TRACE.md` | Company AI action 11 / City_TickBranches decode |
| `AD_SETTLEMENT_TRACE.md` | Advertising plan billing/lifecycle decode |
| `PIZ_FUZZ_VERIFICATION.json` | 1,006-case synthetic-save fuzz oracle |
| `balance_tables.json` | Extracted 8-group and 10-city balance tables |
| `sim_constants.json` | Simulator constants, extracted vs reconstructed |
| `market_table.json` | 86 market prices, tiers and Size.tab dimensions |
| `TAB_FORMAT.md` | `.tab` format reference |
| `SIM_VERIFICATION.json` | Simulator tests, demo and hashes |
| `BRANCH_CHOICE_VERIFICATION.json` | Decoded threshold/radius/score path |
| `CONSTRUCTION_COST_VERIFICATION.json` | Construction price and weighted batch cost |
| `MOVEMENT_PARTY_VERIFICATION.json` | Character party-size inputs, .iso path graph and walk timing |
| `samples/sim_demo_map_90.json` | 90-day run with obstacle-aware Berlin graph routing |
| `samples/sim_demo_360.json` | Deterministic 360-day two-company run |
| `samples/sim_sweep_90.json` | Price/quality/marketing scenario sweep |
| `save_layer_final/` | Named save writer/serializer |
| `save_layer_enum_final/` | Named save-list scan/sort/header reader |
| `samples/synthetic.piz` | Synthetic header-only save used to validate the parser |
| `mission_data.csv` | Ten city/campaign definitions parsed from `daten/<city>.ini` |
| `MISSION_DATA.md` | City campaign table and INI field reference |
| `LDF_FORMAT.md` | `language.ldf` flat string-table spec |
| `SPR_NOTES.md` | `.spr` header, alpha/RLE token format and decoder notes |
| `spr_layer_final/` | Named sprite loader, blitter/RLE, palette, collision and rotation functions |
| `spr_samples/` | Decoded sample PNGs (face, hair overlay, statistics screen) |
| `MODDING.md` | End-to-end unpack → edit → repack workflow |
| `../tools/pak_tool.py` | `.pak` extractor **and repacker** |
| `../tools/ldf_tool.py` | `language.ldf` dump/pack tool |
| `../tools/spr_tool.py` | `.spr` decoder and PNG exporter |
| `../tools/leaf_scan.py` | Ranks remaining leaf functions by in-degree |
| `../extracted/` | All 9,142 archive entries (447 MB) |
| `../extracted_png/` | 6,947 decoded sprite PNGs (65 MB) |
| `callgraph.json` | 3,919 nodes, 13,277 direct call edges, in-degree, byte sizes |
| `callgraph-winmain.dot` | WinMain one-hop call neighborhood (Graphviz) |
| `top-hubs.csv` | Top 80 most-called functions |
| `decompile-journal.jsonl` | Resume journal for `decompile_all` |

Counts: 4,090 procedures in inventory, 3,919 bodies written, 171 external/import
stubs, **0 failures**. 51 of the 58 proposed names are annotated in REA and appear
in the pseudocode; the remaining 7 are listed as proposed only.

## Reading order

1. **`subsystems.md`** — what the program does and where each subsystem lives.
2. **`symbols.csv`** — address → proposed name, confidence, evidence.
3. **`functions/0x403d90.c`** — `WinMain`.
4. **`functions/0x4052c0.c`** — `GameLoop_DispatchScreens` and the screen switch.
5. **`functions/0x4058d0.c`** — `Game_WindowProc` (window/message procedure).
6. **`functions/0x5145a0.c`** / **`0x5146d0.c`** — `language.ldf` loading.
7. **`functions/0x5475a0.c`** — DirectSound initialization.
8. **`PAK_FORMAT.md`** and **`pak_layer_final/`** — archive format and loader.
9. **`PIZ_FORMAT.md`** and **`save_layer_final/`** — save header and save-list layer.
10. **`MODDING.md`** — extract, edit and repack assets/localization.
11. **`LEAF_REVERSAL.md`** — ongoing function-naming ledger, leaf-first.

## Key addresses

| Address | Name | Role |
|---|---|---|
| `0x54fcd4` | `CRT_Entry` | CRT startup |
| `0x403d90` | `WinMain` | registers class `Pizza Connection 2`, parses command line, plays intros, starts game |
| `0x4043e0` | `GameMain` | wraps the screen loop |
| `0x4052c0` | `GameLoop_DispatchScreens` | loads `mission.txt`, dispatches screen states `0x15`–`0x1d` |
| `0x4067d0` | `UI_Init` | creates UI manager and registers `Game_WindowProc` |
| `0x4058d0` | `Game_WindowProc` | window/message procedure; screenshot branch `pizza_shot%d.tga` |
| `0x404500` | `ResourceManager_Init` | creates resource manager, registers `sprites\`/`fonts\`/`pictures\`/`daten\` |
| `0x401af0` | `Pak_Open` | opens/validates a `.pak`, reads and decodes its index |
| `0x401f30` | `Pak_DecodeIndex` | index byte transform |
| `0x402060` | `Pak_FindEntry` | binary search of the decoded entry table |
| `0x402290` | `Resource_Open` | central resource open (18 callers) |
| `0x487520` | `SaveGame_Write` | writes the 0xF0 save header and serializes state |
| `0x487b50` | `SaveGame_Serialize` | save payload section graph |
| `0x4a1570` | `SaveGame_ReadHeaderEntry` | reads/validates save magic for the save list |
| `0x4e64c0` | `Game_Construct` | main game object (0x2f890 bytes) — proposed only |
| `0x4ea440` | `Map_LoadIsodata` | loads `Isodaten.idx` and map/tile objects |
| `0x4ce9d0` | `Movie_Play` | Bink intro movies — proposed only |
| `0x5145a0` | `Language_LoadLDF` | loads/parses `language.ldf` |
| `0x5146d0` | `Language_MapStrings` | maps LDF strings into globals |
| `0x5475a0` | `SoundSystem_Init` | DirectSound + `resources\sound.pak` |
| `0x537f20` | `DirectDraw_Init` | `DirectDrawCreate` |
| `0x476920` | `Screen_MainMenu` | `Pe_Startscreen.tga` |
| `0x474df0` | `Screen_MissionBriefing` | `PE_MISSIONSBRIEFING_*.tga` |
| `0x472da0` | `Screen_FreePlaySetup` | `Pe_Freies_Spiel.tga` |
| `0x46dbd0` | `Screen_CharacterSelect` | `Pe_Charakterauswahl.tga` |

## Known data files

`language.ldf`, `Resources/main.pak`, `Resources/iso.pak`,
`Resources/movie.pak`, `Resources/sound.pak`, `Resources/update.pak`, loose
`Isokarten/*.iso`, `Isokarten/*.STY`, `Isokarten/palette.db`.
`mission.txt` (city list) and `Isodaten.idx` are opened through `Resource_Open`.
`language.ldf` is a flat `u32 count` + NUL-terminated string table; see
`LDF_FORMAT.md` and `tools/ldf_tool.py`.

The `.pak` format is **reversed** — see `PAK_FORMAT.md`. All 9,142 entries across
the five paks were extracted to `../extracted/` (447 MB). The ten city/campaign
definitions (`daten/<city>.ini`) are normalized in `mission_data.csv`.
Save games use `save\games\save_%03d.piz`, `save\games\auto_%03d.piz`,
`save\piz\*.piz` and `save\menu\*.men`. The `.piz` **header and save-list layer**
are decoded in `PIZ_FORMAT.md`. The field-level payload schema is decoded in
`SAVE_SCHEMA.md` (368 explicit fields, 141,342 fixed bytes, 29 exact Save↔Load
pairs); variable sub-records are catalogued but not byte-expanded.

## Limits

- This is Ghidra pseudocode, **not original source**. Variable names and most
  internal function names are lost; proposed names are inferred from resources,
  imports and call structure.
- Static analysis does not observe runtime behavior.
- 171 imported/external functions have no bodies.
- Virtual/indirect calls are excluded from the call graph; 13,277 edges are a
  lower bound.
- `0x54fcd4`, `0x401970`, `0x4e64c0`, `0x4ce9d0`, `0x433790`, `0x43edb0` and
  `0x46f9c0` remain `FUN_*` in the export because they were not annotated (large
  routines exceeded the retained-response budget); their proposed names are in
  `symbols.csv`.

## Re-running

Open `game/fastfood2.exe` with REA and resume `decompile_all` in this directory, or
re-apply `symbols.csv` in a Ghidra checkpoint. The REA evidence bundle from the
annotation session is `rea-evidence-bundle.json` in this folder.
