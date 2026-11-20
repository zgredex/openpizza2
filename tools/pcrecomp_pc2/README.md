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

- Whole-image lift: 9,275 functions, 0 lift failures.
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
- The next blocker is presentation. `Window_RenderFrame` now reaches
  `UI_RenderScene` and `UI_ProcessChildEvent`; the menu sprite is drawn by
  `UI_ProcessWindowEvent 0x0052F2E0` (`f94` holds the sprite). The final blit
  is `Surface_BlitRectRetry 0x00538DA0`; `Gfx_BlitClipped16` is not called
  because `Window+0x1BC` is zero. The tracked 800x600x16 primary is still
  all-zero (`PC2_TRACE_FRAMES=1` reports `nonzero=0/960000`), so the UI drawing
  is going to the window/GDI target rather than the primary the presenter
  reads. Next: bind that target or route the completed UI surface through the
  presenter.

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
