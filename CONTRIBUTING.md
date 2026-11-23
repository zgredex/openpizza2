# Contributing to OpenPizza2

OpenPizza2 is a clean-room reverse-engineering project for **Pizza Connection 2 /
Fast Food Tycoon II v1.004 (GOG)**. The goal is source that a reader can
understand and that the original MSVC 6 compiler reproduces exactly.

You do not need the original source. You do need a legally obtained copy of the
game for local verification. Do not commit the game executable, data files,
extracted assets, screenshots, or any other copyrighted content. This project
distributes code and research only.

## What counts as a contribution

A contribution is one of:

- a new strict-matched function;
- a family generator or spec that produces strict functions;
- a documented near miss with exact first-difference evidence;
- a tool or test that makes verification faster or more reliable;
- documentation that lets the next contributor reproduce your result.

A plausible-looking function that does not pass the strict gate is still useful
if you record why, but it is not a match.

## Prerequisites

- Linux with Wine, Python 3, and Capstone 5.
- The pinned Microsoft Visual C++ 6.0 SP3 toolchain. Do not substitute a modern
  compiler. Restore and smoke-test it with
  [`reconstructed/match/VC6_TOOLCHAIN.md`](reconstructed/match/VC6_TOOLCHAIN.md).
- Optional: Rust/Cargo for the native engine and replay harness.
- A local copy of the supported game at `game/fastfood2.exe`, SHA-256
  `18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd`.

The toolchain is normally installed at:

```text
~/.local/share/pc2/vc6-sp3-toolchain/VC98
```

## Start with a family, not a random function

The highest-yield work is a recurring code shape. Use the family tools:

```sh
# Functions grouped by VC6 unwind cleanup target
python3 tools/map_vc6_cleanup_families.py --out /tmp/pc2-cleanup.json

# Functions grouped by their rarest direct/imported call
python3 tools/mine_feature_families.py \
  --out /tmp/pc2-call-families.json --report /tmp/pc2-call-families.md

# Join both lenses with tracked sources and matcher metadata
python3 tools/audit_matches.py --out /tmp/pc2-audit --jobs 8
python3 tools/build_family_registry.py \
  --inventory /tmp/pc2-cleanup.json \
  --features /tmp/pc2-call-families.json \
  --audit /tmp/pc2-audit \
  --ui-scan /tmp/pc2-ui-full/report.json \
  --out /tmp/pc2-registry/registry.json \
  --report /tmp/pc2-registry/report.md \
  --specs-out /tmp/pc2-family-specs
```

The checked-in registry snapshot is
[`reconstructed/match/investigations/family-registry/`](reconstructed/match/investigations/family-registry/).
Prefer families with many members and shared structure. Do not hand-match a
one-off register wall unless it unlocks a generator.

Pilot a family on three functions:

1. a simple member;
2. a typical member;
3. a held-out sibling you did not use to design the generator.

Only scale when the held-out sibling matches without hand tuning.

## Reconstruct one function

1. Find the record in the batch manifest/part JSON or in
   `decompiled_fastfood2_named_v2/full_game_symbols.json`. It gives the
   address, length, name, and often a decorated entry symbol.
2. Read the pseudocode at
   `decompiled_fastfood2_named_v2/full_game_verification/functions/0xADDRESS.c`.
   Ghidra output is evidence, not source.
3. Read the original disassembly:

   ```sh
   objdump -d -Mintel --start-address=0xADDRESS \
     --stop-address=0xEND game/fastfood2.exe
   ```

4. Recover struct layouts, argument widths, calling conventions, vtable slot
   order, global addresses, and EH cleanup shape from the PE. Use
   `reconstructed/match/symbol_registry.json` for shared facts and
   `decompiled_fastfood2_named_v2/full_game_symbols.json` for names.
5. Write genuine C/C++ in a file named after the address:

   ```text
   reconstructed/match/batchNN/partM/0xADDRESS.c
   reconstructed/match/batchNN/partM/0xADDRESS.cpp
   ```

   Use `.cpp` when the function has C++ EH, classes, or virtual calls, and add
   `/GX`. Use the exact entry symbol. Do not use inline assembly, `volatile`
   purely to steer codegen, fake calls, unreachable no-ops, or object patching.
6. Compile and strict-verify:

   ```sh
   python3 tools/match_decomp.py 0xADDRESS path/to/0xADDRESS.c \
     --length LENGTH \
     --entry 'DECORATED_ENTRY' \
     --flags '/O2 /TP' \
     --strict --auto-symbols
   ```

   Add `--symbol 'NAME=0xADDRESS'` for independently proven external targets,
   vtables, or private helpers that the automatic registry cannot resolve.

`tools/match_decomp.py` checks:

- exact candidate extent;
- every DIR32/REL32 target and addend against the original PE;
- independent symbol resolution, not original relocation bytes;
- compiler-generated EH/text/data COMDATs, including `.text$x`, `.xdata$x`,
  vtables, and `$L`/`$T` anchors derived from the original PE.

## Add the verifier

A match is not accepted until it is in a verifier:

- add a `check` line to the batch `verify_strict.sh`; or
- add a recipe to a family `family.json` and run
  `tools/run_family_batch.py`; or
- add a generator verification script.

Examples:

```sh
sh reconstructed/match/batch19/part1/verify_strict.sh
python3 tools/run_family_batch.py \
  --config reconstructed/match/investigations/list-family/family.json \
  --out /tmp/pc2-list --cache /tmp/pc2-list-cache --jobs 4
sh reconstructed/match/investigations/destructor-family/verify_strict.sh
sh reconstructed/match/batch21/part3/verify_strict.sh
```

For EH or vtable-heavy functions, keep the strict receipt and check the
secondary spans. For C++ EH, `/GX` is required; `extern "C"` suppresses VC6's
EH frame.

## When it does not match

Keep the best genuine candidate under `nonmatching/` and document:

- exact candidate length and first differing offset;
- original/candidate bytes at that offset;
- the inferred cause (calling convention, struct layout, lifetime/scope,
  register allocation, scheduling, missing/extra call, EH state);
- source shapes already tried;
- whether the secondary sections and relocations are already exact.

Do not keep a failed candidate as if it were accepted. Do not add fake
source-level tricks to close a register or scheduling byte. Route those to a
bounded permuter/source-shape search instead.

Useful existing examples:

- [`batch21/part1/nonmatching/0x535c10.c`](reconstructed/match/batch21/part1/nonmatching/0x535c10.c)
- [`batch21/part2/nonmatching/0x4be490.c`](reconstructed/match/batch21/part2/nonmatching/0x4be490.c)
- [`investigations/destructor-family/`](reconstructed/match/investigations/destructor-family/)

## Families already in the repository

- **UI builders**: `tools/generate_ui_builder.py` and
  `tools/verify_ui_builder_batch.py` currently generate and link all
  **120/120** builders, 437,467 bytes.
- **List operations**: `reconstructed/match/investigations/list-family/`, 6/7
  strict, with a cached batch runner and a 1-byte near miss.
- **Sound destructors**: `tools/generate_destructor_family.py`, 3/3 strict,
  plus a helpers family.
- **Feature/cleanup registry**: 60 joined families and 31 runnable specs under
  `reconstructed/match/investigations/family-registry/`.

A good first contribution is to take one runnable family spec, run it with
`--cache`, and close the first documented near miss or turn the family into a
generator.

## Verification and regression checks

Before opening a pull request:

```sh
python3 tools/verify_all.py --no-write
sh reconstructed/match/runtime01/verify_strict.sh
sh reconstructed/match/batch21/part3/verify_strict.sh
```

If you changed a matcher or generator, rerun every verifier it affects, not
just your new function. The strict audit is the source of truth:

```sh
python3 tools/audit_matches.py --out /tmp/pc2-audit --jobs 8
```

Commit only source, specs, receipts, worklogs, and tools. Do not commit:

- `game/fastfood2.exe`, `.iso`, `.pak`, `.ldf`, audio/video/images, or extracted
  game data;
- generated `.obj`, `.exe`, or COFF/PE scratch output;
- `target/`, `__pycache__`, or temporary `/tmp` artifacts.

The `.gitignore` already excludes the known asset and build paths. Check
`git status --short` before committing.

## Pull request checklist

- [ ] The function passes `--strict --auto-symbols` with its exact length and
      decorated entry symbol.
- [ ] The verifier includes the function and passes.
- [ ] No exe/assets/generated binaries are added.
- [ ] The source is genuine C/C++, with no inline assembly or byte-steering
      fakematch.
- [ ] A worklog or family README records the source shape and any remaining
      blocker.
- [ ] Unrelated dirty files are not included.
- [ ] `python3 tools/verify_all.py --no-write` is green, or the affected
      subset is documented.

## Legal note

OpenPizza2 is not affiliated with or endorsed by the rights holders. It is a
clean-room reverse-engineering and preservation project. Contributors must not
submit original assets, leaked source, or material they do not have the right
to distribute. Users must supply their own legally obtained copy of the game.
