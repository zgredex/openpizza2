# Readable source port

This tree is the **readable source-port phase** of OpenPizza2. It is separate
from `reconstructed/match/`, which contains byte-exact matching work.

The goal here is to recover many understandable functions and integrate them
into a new 32-bit Windows executable. Compilation proves that the sources are
syntactically and structurally integrated. It does **not** prove behavioural
equivalence with the original game. No byte comparison, strict matching or
equivalence testing is part of this phase.

## Current coverage

```text
exported pseudocode functions   3,919
compiled recovered functions    3,919
explicitly unsupported              0
still queued                        0
PE32 output                    2.3 MB, runs under Wine with exit 0
```

All functions are covered by a decision: compiled into the port, or recorded
under `unsupported/` with `PORT_STATUS: STUB` and the exact first compiler
error. Unsupported files are not counted as recovered. The queue reports zero
remaining work.

The batch pipeline processed 500 functions at a time. Beyond the initial
dependency-free batch, later batches allowed DAT_/FUN_/indirect-call functions
and used a temporary `/force:unresolved /force:multiple` link scaffold. Repair
passes then attacked shared categories: Win32/CRT types, generated data
symbols, Ghidra bitfield extraction and insertion, parameter/local pointer
retyping, string globals, and generated struct fields. The remaining 0 are
genuinely structural cases (nested field types, non-constant switch labels,
pointer arithmetic on `void *`, and malformed bitfield expressions).

Compiled means **structurally integrated**, not behaviorally verified. No byte
comparison, strict matching or equivalence testing is part of this phase.

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

1. Revisit the structural unsupported cases with recursive field typing,
   switch-label rewriting, and pointer-arithmetic cleanup.
2. Replace the mechanical first-pass naming/offset style in well-understood
   subsystems (math/rating helpers, list/map accessors, sound lock guards, UI
   geometry) with shared structs and named fields.
3. Replace the `/force:unresolved` scaffold with real implementations or
   explicit stubs for the startup path, then start the actual game flow.
4. Keep the compiled vs behaviorally-verified distinction in every report.
