# Byte-matched PC2 reconstruction

The shipped `game/fastfood2.exe` is MSVC 6.0 SP3: `C2.DLL` 12.00.8447 and
`LINK.EXE` 6.00.8447. The SP3 command-line tree is kept outside the repository
under `/tmp/opencode/vc6-sp3-toolchain/VC98`; set `PC2_VC6` to another tree if
needed.

A candidate is verified when `tools/match_decomp.py --strict` reports
`"strict_match": true`. It compiles with `/O2` by default, compares the
function bytes with the PE, and checks every COFF `DIR32`/`REL32` relocation
against an independently resolved address.

Example:

```sh
python3 tools/match_decomp.py 0x48d3a0 /tmp/candidate.c \
  --length 0x80 --entry _pc2_get_capital --strict --auto-symbols \
  --symbol _game_difficulty=0x57bb24
```

Batch 1 is 100 functions from `decompiled_fastfood2_named_v2/final655_batches.json`
(split into four 25-function parts under `batch01/`). Each worker owns one part
and writes candidates only under `batch01/partN/`. Keep worklogs in
`batch01/partN/worklog.md`; commit only matched C and tests. Never commit the
VC6 tree or the game image.

## Historical progress

These counts predate the independent relocation gate. Use the audit below
to measure strict matches under the current gate.

```text
batch 1    53 / 100 C-only   (strict 51)
batch 2   100 / 100 C-only   (strict 88)
batch 3   100 / 100 strict
batch 4   100 / 100 strict
batch 5   100 / 100 strict
batch 6    98 / 100 strict
batch 7    98 / 100 strict
batch 8    92 / 100 strict
batch 9    88 / 100 strict
batch 10   91 / 100 strict
batch 11   62 / 100 committed (part4 paused)
batch 12   61 / 100 committed (part4 paused)
batch 13   57 / 100 strict
batch 14   44 / 100 committed (paused)
batch 15   30 / 100 committed (part2 paused)
total     1174 C-only / 1160 strict committed
```

Batches 5-9 are the next 500 smallest remaining functions and use the strict
extent/relocation gate. Nonmatching genuine C/C++ attempts are kept under each
part's `nonmatching/` directory with first-diff evidence.

The strict gate resolves unique PE import IAT slots, exact or decorated aliases
from the shipped symbol maps, address labels, and explicit `--symbol` entries.
It verifies secondary sections using independent anchors or unique byte
signatures. Run the relocation regressions with:

```sh
python3 reconstructed/match/tests/test_relocation_guard.py
python3 reconstructed/match/tests/test_auto_symbols.py
python3 reconstructed/match/tests/test_independent_relocations.py
```

## Batch runner

`tools/match_batch.py` runs a part manifest and writes a JSON report:

```sh
python3 tools/match_batch.py reconstructed/match/batch01/part1.json \
  reconstructed/match/batch01/part1 --symbols reconstructed/match/batch01/part1/symbols.json \
  --json-out /tmp/pc2-part1.json
```

## Golden smoke test

`reconstructed/match/golden/0x48d3a0.c` reproduces `Game_GetStartingCapital`
byte-for-byte with the SP3 compiler:

```sh
python3 tools/match_decomp.py 0x48d3a0 reconstructed/match/golden/0x48d3a0.c \
  --length 0x80 --entry _pc2_get_starting_capital \
  --symbol _game_difficulty=0x57bb24
```

## Strict audit

The [current verification](STRICT_AUDIT.md#current-verification) summarizes
the full tracked audit under the independent relocation gate.

The audit runner reuses the tracked verification scripts and their source,
entry, extent, compiler flags, and symbol choices. It sets `PC2_STRICT=1` and
`PC2_AUTO_SYMBOLS=1`. The output directory must be new. Use `--jobs` to run
independent verifiers concurrently. The batch01/part1 and batch02/part1 wrappers
share a serial lane.

```sh
python3 tools/audit_matches.py --out /tmp/pc2-part3-audit \
  reconstructed/match/batch03/part3/verify_strict.sh
python3 tools/audit_matches.py --jobs 8 --out /tmp/pc2-tracked-audit
```

`functions/` keeps one JSON record per distinct attempted recipe, including
failures. Each record has source/compiler/executable hashes, flags, fixup
evidence, and the strict verdict. Numbered logs retain each script's output.
`report.json` counts distinct observed addresses, lists those without a strict
pass, and records each script's status. Counts cover the observed attempts,
so inspect the script log if a failure stopped a verifier early. The audit
exits nonzero if a script fails, the run produces no records, or any observed
address lacks a strict pass. Two legacy wrappers share `/tmp/part1-match.json`,
so keep batch01/part1 and batch02/part1 in the same audit or run them sequentially.

Set `PC2_MATCH_AUDIT_DIR` for the same records from a direct matcher or batch
invocation. If the instruction bytes match and a relocation is unresolved,
use the recorded symbol and fixup site to seek independent evidence. Supply
only an independently established address with `--symbol NAME=0xADDRESS`.
For code generation differences, run the [bounded retry matrix](investigations/README.md).

## Symbol and ABI registry

[`symbol_registry.json`](symbol_registry.json) records exact COFF names for the
pinned executable, with separately checked addresses and evidence references.
`--auto-symbols` uses these entries for fixups and independently anchored
sections. Explicit mappings still take precedence. The matcher records the
registry hash and relevant evidence, and checks the linked bytes and fixups.
Add an entry only when its address follows from evidence independent of the
fixup being checked. Candidate declarations describe the COFF spelling.
Observed ABI facts are recorded separately from those declarations.

Select callers by exact symbol from a previous audit and replay just the
selected source, flags, and relocation maps. The pilot covers eight stream
callers and one array search caller.

```sh
python3 tools/audit_symbol_targets.py /tmp/pc2-tracked-audit --unverified-only \
  --symbol '?Read@IStream@@QAEXPAXH@Z' --symbol '?Write@OStream@@QAEXPAXH@Z' \
  --symbol '?BinarySearch8@Array@@QAEHHH@Z' --json-out /tmp/pc2-symbol-pilot.json
python3 tools/compiler_matrix.py /tmp/pc2-symbol-pilot.json --max-attempts 9 \
  --require-match --json-out /tmp/pc2-symbol-pilot-results.json
python3 tools/function_batch.py 4900a0 5314f0 401a20 --no-disassembly --abi-context \
  --json-out /tmp/pc2-symbol-context.json
```

All nine pilot callers passed strict VC6 verification. The independent
ResourceManager constructor write also verified the destructor's vtable
fixup to `0x55c2f0`. The destructor is still blocked on other relocations,
including `_fclose`. `--abi-context` adds relevant aliases and existing class
layout observations to function packets on request.

## Scratch PE verification

`tools/verify_linked_image.py` compiles one candidate from the contiguous
function inventory and requires a strict match. It writes the COFF body into a
scratch PE after evaluating its `DIR32` and `REL32` addends with independently
resolved targets. The complete image must equal the original byte for byte.
The manifest records both images, source and COFF hashes, the function range,
relocation evidence, and direct call fixups. Both output paths must be new.
The strict matcher emits the same link plan consumed by the image builder.
It gives the VA, file range, bytes, and fixup sites for the primary function,
matching inline tables or tails, and independently placed secondary sections.
The builder writes identical shared spans once and rejects partial overlaps
or conflicting spans.

Run the pilot from the repository root with `scratch` pointing to an existing
scratch installation directory. The executable can then be replayed beside
the corresponding assets.

```sh
python3 tools/verify_linked_image.py 0x52f750 \
  reconstructed/match/batch09/part4/0x52f750.c --length 68 \
  --entry '?SetButtonColors@Gadget@@QAEXHHHH@Z' --flags '/O2 /TP' \
  --symbol '?GadgetNotify@Window@@QAEXHHHHH@Z=0x52fdd0' \
  --out "$scratch/fastfood2.exe" --manifest "$scratch/pilot-manifest.json"
cmp game/fastfood2.exe "$scratch/fastfood2.exe"
python3 reconstructed/match/tests/test_linked_image.py
```

Pass `--image` to use a previously verified byte-identical copy as the input
for another function. See the [capture guide](../../tools/pcrecomp_pc2/TRACE_CAPTURE.md#replay-a-scratch-image)
to replay the final copy with the pinned lift.

The VC6 pilot chained `Gadget_SetButtonColors` (`0x52f750`, 68 bytes, three
call fixups) and `Window_GadgetNotify_Text_SetTextColor` (`0x52f910`, 24 bytes,
one call fixup).
The final scratch PE was byte-identical to the original. The headless replay
used the existing pinned lift and moved from screen 21 to 28, tracing 2 and
34 entries at the two addresses respectively, with zero unresolved edges.

### Batch verification from an audit

Pass an audit directory to relink its eligible recipes into one scratch PE.
The verifier checks the pinned executable, saved source and compiler hashes,
and non-overlapping VA and file ranges before starting VC6. Priority addresses
come first in command-line order, followed by ascending VA. Omit `--limit` to
run the full plan. The limit counts attempted recipes.

```sh
python3 tools/verify_linked_image.py --audit /tmp/pc2-tracked-audit \
  --jobs 8 --limit 25 --address 0x52f750 --address 0x52f910 \
  --cache /tmp/pc2-coff-cache --out "$scratch/fastfood2.exe" \
  --manifest "$scratch/batch-manifest.json"
cmp game/fastfood2.exe "$scratch/fastfood2.exe"
```

The manifest records unique function and code-byte counts, each linked range,
and exclusions discovered before or after compilation. It counts primary code
bytes separately from the union of all written spans. A strict match or byte
comparison failure aborts publication of the image.

The optional cache uses the source path and hash, flags, compiler and Wine
binary hashes, and the same controlled environment used on cacheable builds.
The cache is for self-contained sources. Preprocessor directives, time macros,
and compiler or loader environment overrides bypass it. Every cache hit runs
the strict matcher and independent relocation checks again.

The shared plan recovered all 21 former layout exclusions, with 17 inline
tails and eight secondary spans. The full run linked all 1,047 planned
functions into a byte-identical PE with 56,847 code bytes and 57,539 total
linked bytes across 1,072 writes. It reused 1,039 cached objects. The pinned
lift replay advanced from screen 21 to 28, reached 111 linked functions, and
reported zero unresolved edges.

### Targeted dependency rechecks

Query previous audit records for exact symbols, section placement VAs, or
recorded source and evidence paths with `audit_symbol_targets.py --reverse`.
It reports consumed and blocked references. To isolate the impact of registry
changes, pass a saved `--registry-before` snapshot. This mode excludes callers
with explicit symbol mappings for a changed fact.

```sh
python3 tools/audit_symbol_targets.py /tmp/pc2-tracked-audit \
  --registry-before /tmp/pc2-registry-before.json --json-out /tmp/pc2-affected.json
python3 tools/verify_linked_image.py --audit /tmp/pc2-tracked-audit \
  --only-address 0x4900a0 --only-address 0x4919b0 \
  --only-address 0x492230 --only-address 0x499570 \
  --cache /tmp/pc2-coff-cache --cache-only --image "$scratch/fastfood2.exe" \
  --out "$scratch/rechecked.exe" --manifest "$scratch/rechecked.json"
```

`--only-address` gives the new manifest exactly the selected scope, even when
it uses a prior byte-identical image. Keep the prior manifest for its wider
coverage. `--include-blocked` allows an explicit recheck of previous body-only
recipes, and `--cache-only` requires every selected object to be retained.
The `IStream::Read` fact selected four callers and rechecked all four from
cache. An incorrect explicit target failed verification and published no PE.

### Assess blocked objects

Rank unresolved names by how many distinct functions list them as the sole
strict blocker. When audit sets are merged, receipts made under the current
registry supersede older receipts for the same compilation recipe. Older
evidence is used for recipes that have no current receipt.

```sh
python3 tools/audit_symbol_targets.py /tmp/pc2-tracked-audit --rank-blockers
python3 tools/verify_linked_image.py --audit /tmp/pc2-tracked-audit --assess \
  --only-address 0x4810e0 --only-address 0x4e2ca0 --cache /tmp/pc2-coff-cache \
  --manifest /tmp/pc2-before-assessment.json
```

An assessment records a verdict for each selected recipe and publishes JSON
only. A cacheable compiler object is retained before symbol resolution, so
a body-only candidate can be rechecked later. After changing the registry,
use `--registry-before` to find affected VAs and repeat the assessment with
`--cache-only` and a fresh report path. Missing objects or tool errors leave
diagnostics in the report and return nonzero. To publish an image, omit
`--assess`, supply `--out`, and select only recipes that now pass the strict
gate. Use `--include-blocked` if publishing from the older audit records.

The cold run retained all 12 blocked objects. Independently corroborated
`IDMapHelper::Lookup`, `CRT_IStream::Read`, and `CRT_OStream::Write` aliases
made nine strict on the warm recheck, with all 12 objects reused and three
functions still blocked. The nine strict functions published 472 code bytes
in a byte-identical scratch PE.

### Propose reusable symbol facts

`tools/propose_symbol_mappings.py` joins every unresolved COFF name in the
body-only audit set against independent evidence: strict audit recipes, the
shared symbol registry, the shipped function/data maps, the PE import table,
the stock CRT report, and the recovered vtable inventories. It keeps observed
relocation targets only as investigation leads; they never become accepted
facts by themselves.

```sh
python3 tools/propose_symbol_mappings.py /tmp/pc2-tracked-audit \
  --crt-report /tmp/pc2-crt-archive-report.json \
  --json-out /tmp/pc2-proposals.json \
  --report-out /tmp/pc2-proposals.md \
  --registry-fragment-out /tmp/pc2-registry-fragment.json \
  --pilot-fragment-out /tmp/pc2-pilot-registry.json
```

The report ranks groups of facts by the number of body-only functions they
would finish. `ready` facts have an independent source; `candidate` facts are
a unique name match corroborated by the observed target and still need an
independent check; `ambiguous`, `needs_evidence`, and `missing` lists are the
Luna review queue. `section_facts` isolates per-function `.text$x`/`.xdata$x`
and local-label placement issues from reusable symbol facts.

Only `ready` facts are written to a registry fragment. `--pilot` limits the
fragment to CRT, vtable, and C++ runtime helpers (`operator new/delete`,
constructors, destructors). Add those entries to
`reconstructed/match/symbol_registry.json` only with their evidence. Then use
the existing dependency index to recheck just the consumers:

```sh
cp reconstructed/match/symbol_registry.json /tmp/pc2-registry-before.json
# merge the reviewed fragment
python3 tools/audit_symbol_targets.py /tmp/pc2-tracked-audit \
  --registry-before /tmp/pc2-registry-before.json --json-out /tmp/pc2-affected.json
python3 tools/verify_linked_image.py --audit /tmp/pc2-tracked-audit --assess \
  --only-address 0x... --cache /tmp/pc2-coff-cache \
  --manifest /tmp/pc2-after.json
```

Feed the assessment JSON back with the original audit. Assessment receipts
supersede older recipes for the same address/source/flags, so resolved names
leave the queue and remaining blockers re-rank automatically. Cache hits
re-run the strict matcher and independent relocation checks; they do not
recompile. The regression test is:

```sh
python3 reconstructed/match/tests/test_symbol_proposals.py
```

## Stock CRT archive identification

```sh
python3 tools/match_crt_archive.py --json-out /tmp/pc2-crt-archive-report.json
python3 reconstructed/match/tests/test_crt_archive.py
```

The scanner defaults to `LIBC.LIB` and `LIBCMT.LIB` under `PC2_VC6` (or the SP3
tree above). To use other copies, pass the archive paths as positional
arguments. Wine and the compiler are unnecessary for this scan.

The report groups archive variants by PE address. Exact comparisons use
complete, contiguous game function bodies and COFF code sections with one
entry, or a function-definition auxiliary size. Relocated comparisons require
every i386 `DIR32` and `REL32` field to resolve with its addend. The scanner
uses same-section placement, unique exact anchors, or explicit external
addresses provided as `--symbol NAME=0xADDRESS`. An unresolved symbol remains
a candidate. Distinct archive identities with the same bytes are marked
ambiguous. These results measure equivalence to stock objects independently
of the C reconstruction counts and do not identify original compiler flags.

With the pinned SP3 archives and shipped executable, 43 PE locations have
verified bytes, including 33 with a single identity. `intrncvt.obj` contributes
three raw matches at `0x555896` (`__CopyMan`), `0x5558b1` (`__FillZeroMan`), and
`0x5558bd` (`__IsZeroMan`). The JSON records input hashes and relocation
evidence. Generate the report locally with the command above.
