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
