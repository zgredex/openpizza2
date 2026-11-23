# OpenPizza2 — autonomous strict-family expansion handoff

Work in the existing local checkout of `https://github.com/zgredex/openpizza2`.
The user wants **as many new verified strict-matched function families as possible**, not
just research notes or an illustrative match. You have the local GOG executable and
pinned VC6 SP3 compiler. This task comes with these additional read-only tools:

- `tools/mine_pc2_shape_families.py`
- `tests/test_mine_pc2_shape_families.py`
- `reconstructed/match/investigations/shape-family-sweep/README.md`
- `reconstructed/match/investigations/shape-family-sweep/seed_evidence.json`

## Nonnegotiable safety and quality rules

- Before modifications read `AGENTS.md`, `CONTRIBUTING.md`, `git status`, the last
  20 commits, and current family docs. Respect pre-existing dirty files; never
  reset, delete, or overwrite unrelated local work.
- Use `game/fastfood2.exe` with SHA-256
  `18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd`.
- Use the project's pinned MSVC 6.0 SP3 toolchain, specifically C2 12.00.8447;
  do not substitute Clang/GCC, another SP, or an approximated compiler.
- Genuine C/C++ only; no inline assembly, fake calls, unreachable byte-steering,
  binary patching or pseudo-source accepted as a strict match.
- Treat strict as true **only** when `tools/match_decomp.py --strict --auto-symbols`
  verifies exact size, bytes, fixups, and secondary EH/COMDAT output.
- Do not commit or redistribute the original exe, assets, generated binary/obj files,
  or full disassembly; keep all scratch outputs under `/tmp`.
- Do not count names, decompiled C, plausible code, matching prefix, or a linker
  success as a verified match. Every accepted member needs a durable strict verifier.

## Run these steps first

```sh
set -eu
git status --short
git log -20 --oneline
sha256sum game/fastfood2.exe
python3 -m unittest discover -s tests -p test_mine_pc2_shape_families.py -v
python3 tools/mine_pc2_shape_families.py \
  --exe game/fastfood2.exe \
  --symbols decompiled_fastfood2_named_v2/full_game_symbols.json \
  --json /tmp/pc2-shape-families.json \
  --report /tmp/pc2-shape-families.md
sh reconstructed/match/runtime01/verify_strict.sh
```

Inspect newer matching state, especially recent sound-lock and sound-destructor
commits, before choosing targets. The checked-in registry is a snapshot, not
proof of what remains unmatched on current HEAD.

## Multi-family work queue (iterate, don't stop after one)

**Wave A — farm existing runnable specs.** Generate or refresh the existing
cleanup- and call-target inventories and audit, then run all remaining runnable
specs under `reconstructed/match/investigations/family-registry/` with
`tools/run_family_batch.py`, caching compiler objects. Do not rerun the already
complete 120/120 UI builder generators. Distinguish new strict matches, blocked
symbol/secondary sections, and primary body near-misses. Promote verified new
members to durable recipes; don't just print a report. Choose quick families first.

**Wave B — extend sound destructor generator.** Current docs nominate:
`0x541f30`, `0x546750`, `0x5408b0`, `0x541790`, `0x53fcc0`.
The supplied exe independently confirms the first body vtable assignment and EH
prologue for each:

- `0x541f30`: `mov [esi],0x55c8e0` (then reads `[esi+0x28]`)
- `0x546750`: `mov [esi],0x55cb14` (then reads `[esi+0x0c]`)
- `0x5408b0`: `mov [esi],0x55c874` (then reads byte `[esi+0x34]`)
- `0x541790`: `mov [esi],0x55c8b0` (then reads `[esi+0xac]`)
- `0x53fcc0`: `mov [esi],0x55c864` (then reads `[esi+0x238]`)

Read `tools/generate_destructor_family.py`, the existing destructor family
verification, original disassembly, pseudocode, EH state maps. First run an
unmodified baseline and match a simple/typical/held-out sibling. Extend the
source-shape parameter model to cover the tested branches, destructor state
transitions, virtual release calls and switches if grounded in real code.
Require **independent held-out strict matching** before scaling to all siblings.

**Wave C — finish remaining sound lock-guard members.** Read
`reconstructed/match/investigations/sound-lock-family/README.md`, compare
historical best candidates and fresh disassembly, and avoid losing the already
strict `0x544760` control. Pending addresses from the handoff:

- `0x544620`: 211 bytes; `__thiscall`; guard stores pointer from `this+0x38`.
- `0x5448c0`: 210 bytes; free/COM-style `__stdcall` with 3 stack arguments,
  `ret 0xc`, lock at `self+0xa0`, virtual call at vtable `+0x24`.
- `0x5449a0`: 262 bytes; nested lock guards and two EH unwind states.

`0x544760` (223 bytes) is the strict control: free/COM-style `__stdcall`,
virtual call slot `+0x10`. All four use VC6 C++ EH; `/O2 /GX /TP` is the known
candidate profile. The real lock-guard destructor is `0x53ff80` and the
LeaveCriticalSection IAT slot is `0x55c1a0`. The EnterCriticalSection slot is
`0x55c1b8`. Preserve original stack ABI, exception state graph, and member
lifetime. The notes report the 0x5448c0 best candidate only 51 bytes off with
secondary EH sections exact — optimize the primary C++ source shape, not EH.

**Wave D — remaining structural families.** Cross-reference the live audit and
prior family recipes before working:

- list-family's one-byte near miss: route controlled source-shape variants through
  a bounded permuter, not hacks;
- `0x4017f0` stats/object utilities: registry snapshot had 34 missing and
  five near misses, but already 72 strict;
- `0x54dd78` Mem_Free and related cleanup: huge repeat opportunities, use
  generator and exact `__thiscall`/scalar-deleting-destructor conventions;
- `0x401480` List_Node_Destroy cleanup (41 missing in snapshot);
- `0x520b10` UI_Child_Destroy cleanup (14 missing);
- `0x53efd0` SoundBuffer_SetBaseVTable cleanup (17 missing);
- `0x522f20` Array_Destroy cleanup (9 missing).

Do **not** invent success rates from these prior snapshot counts. Use current
strict audit, original calls, vtable layout, memory ownership, and real code to
pick the highest expected new verified bytes.

**Wave E — new reference lenses.** Inspect `/tmp/pc2-shape-families.md` and
`/tmp/pc2-shape-families.json`. Prioritize only structurally repeated groups
with at least 3 genuinely distinct unverified members: shared vtable-like refs,
shared ASCII string refs, and normalized opcode prefixes. Confirm candidate
vtable ownership through writes and virtual-call sites before generating C++.
Consolidate any new families into the registry and strict batch recipes. Do
not duplicate the existing feature-call and cleanup-target miners.

## Implementation loop for each family

1. Collect exact start, length, decorated entry, flags, pseudocode, disassembly,
   references, call targets, and EH/secondary-section layout from existing tools.
2. Identify recurring **C/C++ source structure**, not just recurring bytes.
3. Make one legitimate, parameterized source or generator, and test simple,
   typical, then **held-out** sibling.
4. Verify every member with `tools/match_decomp.py --strict --auto-symbols`.
   Resolve only independently supported symbol bindings. Record first mismatch
   and exact cause of each nonmatch in `nonmatching/` notes if retained.
5. Add `verify_strict.sh` or family JSON/verifier. If a source generator is
   used, regenerate to scratch and test deterministic output.
6. Update family README with strict address/byte counts and exact invocations.
7. Run affected verifiers plus `python3 tools/verify_all.py --no-write` when
   practical. Commit only validated focused source/metadata/docs.
8. Continue to next high-yield family instead of stopping after a single win.

## Final report required

Give a table, per family: new strict functions, newly verified code bytes,
verified addresses, failed/blocked addresses and exact blockers, verifier
commands/results, commits made. Explicitly distinguish **strict / near miss /
research-only**. Provide the total *incremental* strictly matched bytes versus
initial audit. No inflated numbers from preexisting UI or CRT matches.

If a family is blocked, record durable evidence and move on to the next one;
throughput across families matters more than polishing one isolated register
scheduling difference indefinitely.
