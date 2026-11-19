# Pizza Connection 2 — decompilation report

> **Named output:** `../decompiled_fastfood2_named_v2/` contains the same corpus with
> 51 REA-verified names applied (WinMain, GameLoop_DispatchScreens, Resource_Open,
> UI_AddText, SoundSystem_Init, screen constructors, …), plus `symbols.csv`,
> `vtables.csv`, `subsystems.md` and a call graph. This folder remains the
> anonymous baseline export. The `.pak` container has since been reversed; see
> `../decompiled_fastfood2_named_v2/PAK_FORMAT.md` and `../tools/pak_tool.py`.

## Target

| Field | Value |
|---|---|
| Game | Pizza Connection 2 / Fast Food Tycoon II, version 1.004 (GOG release) |
| Installer | `setup_pizza_connection_2_1.004_(1.006_de)_hotfix_(20623).exe` (Inno Setup 5.5.7) |
| Executable | `game/fastfood2.exe` |
| Format | PE32, Intel i386, Windows GUI |
| Image base | `0x400000` |
| Entry point | `0x54fcd4` |
| PE timestamp | 2000-12-15 08:20:54 UTC |
| SHA-256 | `18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd` |
| Analysis | REA → Ghidra 12.2, full auto-analysis |

The installer was unpacked with `innoextract 1.9` into `game/`. The game code is one
native executable; `binkw32.dll` is the third-party Bink video runtime.

## Output

| Path | Contents |
|---|---|
| `functions/0x<address>.c` | Ghidra pseudocode for each analyzed function (3,919 files) |
| `decompile-index.json` | Machine-readable manifest: address, name, ranges, file, SHA-256 |
| `decompile-journal.jsonl` | Export journal used by `decompile_all` resume |
| `functions.tsv` | Spreadsheet-friendly index (address, name, size, status, file) |

Counts:

- 4,090 procedures in the provider inventory
- 3,919 function bodies written, **0 failures**
- 171 external/import stubs (no body to decompile)
- 3,029 functions in game code (`0x401000`–`0x55558f`, ~1.21 MB of code)
- 890 CRT/compiler-support functions (`>= 0x555590`)
- 2,048 defined strings in the binary

The executable is a stripped MSVC-era build. Only CRT/import names survive
(`entry`, `_memset`, `DirectDrawCreate`, …), so almost all game functions appear as
`FUN_<address>`. Names were not invented.

## Key addresses

| Address | What it is | Basis |
|---|---|---|
| `0x54fcd4` | CRT `entry`; initializes runtime and calls the WinMain-style function | observed call graph |
| `0x403d90` | WinMain equivalent (receives `HINSTANCE`): registers class `Pizza Connection 2`, creates events/critical section, parses command line, starts the game | observed code and string refs |
| `0x537f20` | Renderer initialization wrapper; calls `DirectDrawCreate` | observed import call |
| `0x52ae20` | Bink movie player constructor; calls `BinkSetSoundSystem` / `BinkOpen` | observed import calls |
| `0x54cb86` | Save-file dialog wrapper around `GetSaveFileNameA` | observed import call |
| `0x4058d0` | `Game_WindowProc`: window/message procedure; handles WM/custom messages and the `pizza_shot%d.tga` screenshot branch | registered by `UI_Init`, 201 basic blocks |
| `0x433790` | Builds the branch-balance statistics screen (`STATISTIKFILIALBILANZ.spr`) | observed sprite resource IDs |
| `0x43edb0` | Builds the personnel screen (`SK_PERSONAL.spr`, `PERSOPLAN.spr`) | observed sprite resource IDs |
| `0x46f9c0` | Builds the end-result/score screen (`Pe_Endergebnis_Punkte.tga`) | observed resource IDs |
| `0x5146d0` | `Language_MapStrings`: bulk-copies parsed `language.ldf` strings into globals | observed LDF loader call chain |

The engine is DirectDraw-based with a custom resource layer for sprites, fonts,
animations and TGA images (`.spr`, `.fnt`, `.ani`, `.tga`), and Bink for movies.
Game content is loaded from `main.pak`, `iso.pak`, `sound.pak`, `movie.pak` and
`update.pak` (all present in `game/Resources/`). Mission text is read from
`mission.txt`; saves use the Windows registry key
`SOFTWARE\Software2000\Pizza Connection 2`.

## Limitations

- Pseudocode is Ghidra decompiler output, **not original source**; it is not
  text-equivalent to the shipped code and variable/function names are mostly lost.
- Static analysis does not prove runtime behavior.
- The 171 imported/external functions have no bodies in this executable.
- Data archives and art/audio assets were not decoded in this baseline export;
  the `.pak` format is reversed in `../decompiled_fastfood2_named_v2/PAK_FORMAT.md`.
- Ghidra 12.2 was used; REA reports its bridge as verified against 12.1.4 and
  accepts other 12.x builds.

## Re-running / resuming

Open `game/fastfood2.exe` with REA, then call `decompile_all` again with the same
output directory and `resume: true`. Completion is recorded in
`decompile-journal.jsonl`; verified files are skipped.
