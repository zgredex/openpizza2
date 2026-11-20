# pcrecomp static-recompilation spike

Date: 2026-11-20
Target: `game/fastfood2.exe`
SHA-256: `18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd`

## Question

NFSU2's `nfsu2-recompiled` project uses `pcrecomp` to lift x86-32 machine code
into C automatically. Is Pizza Connection 2 a viable target for the same
approach?

## Toolchain used

| Item | Value |
|---|---|
| pcrecomp | commit `621860a` (2026-11-18) |
| Python | 3.14 virtualenv |
| capstone | 5.0.7 |
| unicorn | 2.1.4 |
| pefile | 2024.8.26 |

The pcrecomp clone, virtualenv and generated C live outside the repository in
`/tmp/opencode/pcrecomp-spike/`. Generated lifted C is deliberately not
committed.

## Pipeline and results

### PE analysis

```text
python tools/pe/pe_analyze.py game/fastfood2.exe --json fastfood2.pe.json
```

- PE32, image base `0x400000`
- 174 IAT entries / imports
- `DDRAW.dll`, `binkw32.dll`, `ole32.dll`, `COMCTL32.dll`, `comdlg32.dll`,
  `WINMM.dll`, `KERNEL32.dll`, `USER32.dll`, `GDI32.dll`, `ADVAPI32.dll`

### Function discovery

```text
python tools/disasm/disasm32.py game/fastfood2.exe --output fastfood2.functions.json
```

| Metric | Value |
|---|---:|
| Code range | `0x401000..0x55C000` |
| Functions recovered | 9,261 |
| Instructions | 1,154,037 |
| Byte coverage | 96.6% |
| SEH filters/`__finally` blocks seeded | 16 |
| C++ EH stubs/funclets aliased | 1,141 |
| Functions found only through data pointers | 3,812 |

The function count is higher than Ghidra's 3,919 decompiled entries because
pcrecomp also recovers Chained/alias entries, jump-table arms, EH funclets and
small dispatch bodies.

### Lifting

```text
python -m tools game/fastfood2.exe --all --output gen
```

| Metric | Value |
|---|---:|
| Functions lifted | 9,275 |
| Lift failures | 0 |
| Generated C | 101 MB |
| Generated lines | 2,269,610 |
| Generated source files | 10 + dispatch + header |
| Direct calls | 101,480 |
| Indirect calls | 2,736 |
| Indirect tail calls | 1,528 |
| Unimplemented lift markers (`RECOMP_TODO`) | 0 |
| Lift time | 81.3 s |

Generated code is low-level but valid C: one function per guest address,
global x86 registers, `MEM8/16/32`, `PUSH32/POP32`, flag snapshots, and
`RECOMP_CALL`. Original addresses are preserved as comments.

Example (`sub_0050EFC0`, `Player_ResetAiState`):

```c
void sub_0050EFC0(void) {
    ...
    MEM32(ecx + 0x84) = 1; /* 0x0050EFC0: mov dword ptr [ecx + 0x84], 1 */
    MEM32(ecx + 0x88) = 0; /* 0x0050EFCA: mov dword ptr [ecx + 0x88], 0 */
    RECOMP_FLAGS_OUT(); esp += 4; return; /* 0x0050EFD4: ret */
}
```

### Syntax check

All generated C files pass a 32-bit GCC syntax check:

```text
gcc -m32 -std=c11 -w -fsyntax-only \
    -I runtime/recomp32 -I gen -include gen/recomp_funcs.h gen/recomp_*.c
```

Result: 11/11 files OK, 0 failures.

### Differential testing against Unicorn

`tools/lift/difftest.py` compiles a lifted body, runs it against the original
bytes under Unicorn, and compares every register, flag and memory byte.

```text
python tools/lift/difftest.py --pe game/fastfood2.exe --gen gen \
    --cases 100 --seed 7 -D RECOMP_GENERATED_CODE 0x50EFC0 0x50E8E0 0x4DD6B0
```

| Function | Cases | Result |
|---|---:|---|
| `Player_ResetAiState 0x50EFC0` | 100 | 100/100 match |
| `Player_Construct 0x50E8E0` | 100 | 100/100 match |
| `Company_ConstructDefault 0x4DD6B0` | 100 | 100/100 match |

Larger functions tested with 5 cases each:

| Function | Cases | Result |
|---|---:|---|
| `Game_InitScenario 0x481D90` | 5 | 5/5 match |
| `Company_Load 0x4E0F90` | 5 | 5/5 match |
| `Character_Construct 0x4D3730` | 5 | 5/5 match |
| `Person_ApplyAttackOutcome 0x50C0F0` | 5 | 5/5 match |

No lifted body diverged from the original bytes in these runs.

## What this proves

- PC2's x86-32 code is liftable by pcrecomp with zero reported lift failures.
- The generated C is syntactically valid under GCC `-m32`.
- Instruction-level behavior matches Unicorn on constructors, save/load,
  scenario init and an attack-outcome path.
- The existing pcrecomp `win32hle` runtime already implements
  `IDirectDraw4`/surface 4, `DirectSound`, Bink, COM and registry surfaces,
  which covers most of PC2's imports.
- `native32` has guest SEH/C++-exception support (`seh32.c`, `eh32.c`); the
  default lift did not emit EH frames for PC2, so exception-heavy paths were
  not exercised.

## What this does not prove

- It is not a playable build. The runtime/host has not been linked or started.
- No 32-bit SDL2/ffmpeg host libraries are installed on this machine, so
  `win32hle` cannot be built here yet.
- SEH dispatch, DirectDraw presentation, Bink playback, input, threading and
  the game's custom resources are untested.
- Generated C is a translation of machine code, not a readable reconstruction;
  it does not recover the object layouts or semantic names used by the
  `reconstructed/` tree.

## Recommendation

Keep the current evidence-backed reconstruction as the source track. Treat
pcrecomp as a parallel **runnable reference** and differential oracle, not as a
replacement for the typed C reconstruction.

Next steps if the recompilation track is continued:

1. Install 32-bit SDL2/SDL2_ttf/ffmpeg development packages.
2. Build `runtime/win32hle` and link the generated C plus `runtime/recomp32`.
3. Start from the CRT entry (`0x54FCD4`) and the WinMain body (`0x403D90`).
4. Measure the first missing import, DirectDraw surface operation or SEH
   dispatch and close them one at a time.
5. Use `difftest.py` on every reconstructed routine as an independent oracle.

## Native Linux bring-up

The pinned recipe is in `tools/pcrecomp_pc2/`:

```bash
tools/pcrecomp_pc2/build.sh
```

It builds 32-bit SDL2/SDL2_ttf into a private sysroot, lifts the executable
with pcrecomp commit `621860a9d22c9b25ae2be4575b956596f4ddaeeb`, links the
generated C and dispatch table against `runtime/win32hle`, and runs headlessly
from the PE entry `0x0054FCD4`.

Verified trace:

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
```

The first gap was `GetCommandLineA`: the default `game.exe` command line made
WinMain derive the base `"g"` and look for `gresources\main.pak`. The host now
sets the real guest path. The second gap was six unshimmed imports
(`IsIconic`, `GetSystemMenu`, `SetClassLongA`, `UnregisterClassA`,
`GetSaveFileNameA`, `_BinkGetSummary@8`), handled by `tools/pcrecomp_pc2/pc2_shims.c`.

This is now a native execution path, not just a lift result: the CRT reaches
WinMain, the 800x600x16 primary surface is created, and the PC2 resource
archives and language table open. The next gap is the game's own
`ResourceManager`/`Pak_*` lookup for the `sprites\...` probes, then a visible
SDL window for the front end.

## Startup through the front end

The native run now reaches the front-end dispatcher and main menu:

```text
[...]
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

`GameLoop_DispatchScreens` is `0x004052C0`, `Screen_MainMenu` is
`0x00476920`, `Map_LoadIsodata` is `0x004EA440`, and `GameMain` is
`0x004043E0`.

The first failure after the intro was a null critical section:
`CreateFileA("C:\test.spr")` failed, and the loading-screen path called
`CRT_LockFile 0x00550877` -> `CRT_FwriteLocked 0x0054FB27` with a null file
lock. Mapping `C:` to a writable host directory (`PC2_CDRIVE`) fixed the
crash. The guest path was `LoadingWindow_Create 0x00474B90` ->
`UI_ShowLoadingOverlay 0x00406910` -> `UI_CreateSlider 0x0052FC00` ->
`UI_Bar_Construct 0x00528930` -> `UI_Bar_BuildGradientFill 0x0052A440` ->
`Sprite_Serialize 0x0053D160`.

After that fix, `Resource_Open 0x00402290` returns non-zero for
`clipsprite.spr`, `rklick_00.spr`, `mission.txt`, `PE_STARTSCREEN.TGA`,
`TIMESFONT.fnt` and the menu-button sprites. The loose-file `CreateFileA`
errors are fallback probes only.

### Main menu presented

`Window_RenderFrame` was returning before `UI_ProcessChildEvent` because
`g_Window_RenderFrame_Flag_00584504` was zero. The host now arms that flag and
clears `g_Surface_BlitRectRetry_Flag` after boot. The menu reaches:

```text
UI_RenderScene -> UI_ProcessChildEvent -> UI_ProcessWindowEvent
```

`UI_ProcessWindowEvent 0x0052F2E0` has the menu sprite at `+0x94` and draws
it. `Window_RenderFrame` still takes the `Surface_BlitRectRetry 0x00538DA0`
path (`Window+0x1BC` is zero); the `Gfx_BlitClipped16` branch and the guest
object layout are unchanged. The tracked DirectDraw primary remains blank.

The bounded DDraw trace proves the divergence:

```text
DDPRIMARY self=4106965392 800x600 bpp=16 pitch=1600 sum=E50455C5
DDBLT d=4106965568 primary=0 800x600 bpp=16 pitch=1600
      rect=0,0..800,600
      s=4106965392 800x600 bpp=16 pitch=1600 rect=0,0..800,600
      keyed=0 srcsum=E50455C5 dstsum_before=E50455C5
DDBLT clip before=0,0..800,600 after=0,0..800,600
      src_after=0,0..800,600 bpp=16 keyed=0
DDBLT post d=4106965568 primary=0 pitch=1600 bpp=16
      hr=0x00000000 DD_OK dstsum_after=E50455C5 copy=1
```

The source is the tracked primary and the destination is a non-primary
surface; both are blank before and after the copy. The completed image is in
the renderer's draw buffer at `renderer+0x28`. The focused host-side presenter
bridge returns that buffer from `hle_dd_frame_hook` after `Screen_MainMenu`;
no guest surface selection is changed.

Verified headless menu frame:

```text
800x600, 458 colors,
sha256=1abdbb3fffaa31003b9d17fbbea7d92a0d306762095ad7fb0d45b3bcea0a6e2b
```

`tools/pcrecomp_pc2/build.sh` checks this digest when `PC2_FRAME_DUMP` is set.

### Campaign start and London

`PC2_CLICK_START` posts the main-menu click at `(650,18)`.
`PC2_START_CAMPAIGN` also posts `Start game` at `(700,566)` and
`Start Mission` at `(680,560)`. The dispatcher trace is:

```text
GameLoop pending=21 -> Screen_MainMenu
click -> GameLoop pending=28 -> Screen_CharacterSelect
click -> GameLoop pending=22 -> Screen_MissionBriefing
click -> GameLoop pending=23 -> Game_RunSession
```

A late renderer dump contains the London welcome dialog and `Town aims`
panel. The repo lift driver seeds three confirmed targets into discovery:
`WorldObject_Delete 0x00504980`, `CRT_LocalUnwind2 0x00553C9D`, and the
exception-filter registration routine `0x00555F68`; a clean build asserts all
three are in the dispatch table.

`Game_EndOfHour 0x00486590` now enters and returns repeatedly. The scripted
rent flow opens the `Rent buildings` panel, clicks `Lease` at `(745,500)`,
and confirms at `(740,581)`. The bounded `Player_CreateBranch 0x004F7420`
checkpoint reports:

```text
BRANCH before player=E600750 site_id=0 site=F41E8050 slot=0 type=0 flags=1
      branch_id_before=-1
BRANCH after player_slot=0 site_id=0 site=F41E8050 branch_id=100000
      site+2c=100000
```

The human player slot is `0`; the site's branch ID changes from `-1` to
`100000`. Cash changes from `500000` to `496188`, and the clock advances from
`00:05` to `00:10`. The tutorial remains on the `Hire personnel` page, but
the first business transaction is verified.

Exception handling is still only partially proven: the registration routine
is lifted and dispatched, but `SetUnhandledExceptionFilter` returns `0` and
`RaiseException` exits in `win32hle`, so guest exception delivery has not been
tested.

### Cursor

PC2 installs `LoadCursorA(NULL, IDC_ARROW)` as its window-class cursor; it
does not draw a software cursor. The runtime hides the SDL cursor unless
`hle_screen_cursor_hook` is set, so the window had no pointer. The host now
sets the hook to `hle_cursor_shown()`, which prints
`[screen] cursor: the system arrow`.
