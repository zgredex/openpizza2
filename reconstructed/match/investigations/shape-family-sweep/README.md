# Structural family sweep: executable-grounded research

Target: Pizza Connection 2 v1.004 GOG, PE32 i386, SHA-256
`18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd`.

## What this adds

`tools/mine_pc2_shape_families.py` adds three **discovery** lenses beyond the existing
cleanup-target and rare-call registry:

1. Shared **vtable-like data pointer** references: groups constructors/destructors,
   aliases, and related class methods by immediate reference to tables with multiple
   pointers into `.text`. This is a heuristic; tables may be RTTI-free vtables or
   unrelated jump/function-pointer arrays.
2. Shared **printable string literal** references in `.rdata`/`.data`, suitable for
   grouping UI text and game table routines. UTF-16-only strings are not included.
3. **Normalized first-seven-instruction shapes**, after removing the standard VC6
   SEH registration prologue where present. Useful for finding destructor templates;
   normalizing constants does not mean the code matches.

It also records direct IAT import references as a sanity check, but the repo's
existing feature-family miner remains authoritative for call-based groups.

## Usage

```sh
python3 -m unittest discover -s tests -p 'test_mine_pc2_shape_families.py' -v
python3 tools/mine_pc2_shape_families.py \
  --exe game/fastfood2.exe \
  --symbols decompiled_fastfood2_named_v2/full_game_symbols.json \
  --json /tmp/pc2-shape-families.json \
  --report /tmp/pc2-shape-families.md
```

Import scanners rely on GNU `objdump` and Python stdlib, not Ghidra or the compiler;
run the pinned VC6 compiler for strict verification, not this report.

**DO NOT mark these family candidates strict.** Exact function extents, source,
compiler output, relocations, and secondary EH sections still require the project's
strict matcher. Function `span_upper_bound` is derived from the **next named
start** (or a cap), not the exact function length.

## Evidence reproduced directly from the supplied executable

| VA | Observation | Meaning / next action |
|---|---|---|
| `0x53fcc0` | Standard VC6 SEH prologue, `mov [esi],0x55c864` | Destructor generator seed; verify body and virtual table |
| `0x541f30` | Standard VC6 SEH prologue, `mov [esi],0x55c8e0` | Destructor generator seed |
| `0x546750` | Standard VC6 SEH prologue, `mov [esi],0x55cb14` | Destructor generator seed |
| `0x5408b0` | SEH prologue, `mov [esi],0x55c874`; tests byte `[esi+0x34]` | SoundBuffer derived destructor seed |
| `0x541790` | SEH prologue, `mov [esi],0x55c8b0`; tests DWORD `[esi+0xac]` | Destructor generator seed |
| `0x544620` | Enters critical section via IAT `0x55c1b8`; lock pointer from `this+0x38` | Unmatched sound-lock member; 211-byte known extent |
| `0x5448c0` | Enters critical section via IAT `0x55c1b8`; address `self+0xa0` | Unmatched COM-style `__stdcall` member; 210-byte known extent |
| `0x544760` | Same `self+0xa0` lock location | Already strict-matched, useful as controlled source exemplar |
| `0x5449a0` | Enters through function pointer loaded from IAT `0x55c1b8` into EBX | Two-lock candidate, 262-byte known extent |

The actual imported pointers are `0x55c1b8 = EnterCriticalSection` and
`0x55c1a0 = LeaveCriticalSection`. Treat pointers in `.rdata` as
**vtable-like**, not definitive class ownership, until call sites confirm them.

## Nonduplication and acceptance gate

Before choosing members, reread `AGENTS.md`, `CONTRIBUTING.md`, newest git log,
`reconstructed/match/investigations/family-registry/README.md`, and the current
audit receipts. The registry snapshot shows 120/120 generated UI builders, so
**do not redo those**. Prefer unhandled sound destructors, the small guard
family, the cleanup/vtable-related gaps, and high-yield near-matches.

Per family, first strict-match a simple, typical, and held-out member under
VC6 SP3; then turn the common shape into a parametrized source generator.
Count **zero** matches unless `tools/match_decomp.py --strict --auto-symbols`
confirms each target. Include a verifier recipe and independent evidence.
