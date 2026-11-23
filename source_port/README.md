# Readable source port

This tree is the **readable source-port phase** of OpenPizza2. It is separate
from `reconstructed/match/`, which contains byte-exact matching work.

The goal here is to recover many understandable functions and integrate them
into a new 32-bit Windows executable. Compilation proves that the sources are
syntactically and structurally integrated. It does **not** prove behavioural
equivalence with the original game. No byte comparison, strict matching or
equivalence testing is part of this phase.

## Current batch

```text
recovered and compiled   443 functions
submitted to queue       443
generated but rejected    77 (compile errors recorded)
stub module                1 (Win32/CRT/global link scaffolding)
```

The queue still lists 3,476 functions as available. The 77 rejected files were
generated mechanically from pseudocode that needs pointer/integer cleanup or
additional interfaces; they were removed from `src/` and are listed with their
exact compiler errors in `work_queue/compile_report.json`.

## Layout

```text
include/pc2_port.h        shared fixed-width types, Win32 vocabulary, ABI declarations
src/0xADDRESS.cpp         one recovered function per file, `// original: 0x...`
src/port_entry.cpp        host harness entry point (not a recovered function)
stubs/                    temporary link scaffolding, `// PORT_STATUS: STUB`
build.sh                  clang i686 COFF + lld-link PE32 build
work_queue/               generated queue and build/compile reports
```

The recovered files are mechanically cleaned from the named Ghidra export:
fixed-width types, `self`/`argN`/`valueN`/`ptrN` names, `intptr_t` pointer
casts, and a short provenance header. They are a first readable pass, not a
line-by-line original-source reconstruction.

## Build and run

```sh
sh source_port/build.sh
WINEDEBUG=-all wine source_port/build/pc2_port.exe
```

The build uses clang's `i686-windows-gnu` target and `lld-link` with
`/nodefaultlib`; it needs no MinGW runtime. The resulting file is a PE32
console executable. It links the recovered functions and calls a few of them
from `port_entry.cpp` as an integration smoke test.

## Status markers

- `// original: 0x401000` marks a recovered function submitted to the queue.
- `// PORT_STATUS: STUB` marks temporary link scaffolding. Stubs are never
  counted as recovered functions.
- A file that compiles is **submitted and compiled**, not behaviourally
  verified. Keep that distinction in reports and commits.

## Next batch

1. Work through the remaining 77 compiler-error categories by fixing the
   shared types/interfaces once (pointer-to-integer assignments, `DWORD *`
   returns, registry/Win32 declarations).
2. Add dependency-bearing functions from `work_queue/queue.csv`, generating
   shared globals and declarations in `include/` and stubs only for unresolved
   externals.
3. Prefer well-understood subsystems (math/rating helpers, list/map accessors,
   sound lock guards, UI geometry) so the recovered source becomes more than a
   mechanical pseudocode dump.
4. Re-run `tools/port_work_queue.py` after each batch and keep the compiled
   source reports current.
