# VC6 compiler fingerprints

This is the project's retrieval library for compiler behaviour that has
already been solved. Before turning a byte difference into a new
compile-and-compare search, look it up here. The goal is that a later agent
reuses a known source shape instead of rediscovering it.

The machine-readable index is [`fingerprints.json`](fingerprints.json). Every
entry records:

- the observable symptom (prologue, state store, instruction form, extent);
- the compiler cause;
- the source pattern that reproduces it;
- the counter-pattern that does not;
- concrete evidence addresses and tracked files.

## Use it

```sh
python3 tools/lookup_fingerprint.py --list
python3 tools/lookup_fingerprint.py --query state-release
python3 tools/lookup_fingerprint.py --tag eh --tag destructor
python3 tools/lookup_fingerprint.py --address 0x5408b0
python3 tools/lookup_fingerprint.py --json --query stdcall
```

Search by the words in the diff you actually see, not by your hypothesis.
`--query` is ANDed and case-insensitive; `--tag` is ANDed; `--address` matches
the evidence addresses attached to an entry. The tool is read-only and has no
dependency on the game executable.

## Current entries

| id | shape |
|---|---|
| `eh-frame-requires-cpp-call` | a destructor loses the whole `fs:[0]` frame when the body only calls `extern "C"` functions |
| `state-release-cpp-linkage` | missing state-0 store before an inlined member destructor |
| `com-stdcall-vtable-slot` | COM methods push `this`; the slot is `__stdcall`, not thiscall |
| `destructor-chain-inline-ancestors` | multi-level destructor chains need inline ancestor destructors and an out-of-line target |
| `list-teardown-free-before-store` | free the node before storing the next head |
| `zero-constant-in-ebx` | VC6 hoists a shared zero into EBX for byte/pointer compares, an argument, and member stores |
| `eh-auto-anchors` | do not hand-bind `$L`/`$T`; the matcher derives them from the PE |
| `generator-field-size-default` | generator field arrays need an explicit `size` or the next field shifts by four |
| `eager-field-locals-compound-filter` | two filter fields in one condition must be locals to force register loads |
| `fp-add-value-local` | FP accumulation needs a value local to put the array load before the accumulator load |

## Add an entry

Add an entry only when the behaviour is reproduced by a strict match, not
because a source shape "looks right". Keep the symptom concrete: the first
differing offset, the original and candidate byte or instruction, the extent
delta, or the unresolved relocation. Link the generated source and the
verifier/README that explains it.

Use the library at three points:

1. **Triage** — search the symptom before choosing a family lane.
2. **Pilot** — cite the fingerprint that justifies a generator rule.
3. **Post-mortem** — add the new compiler behaviour once a held-out member
   proves it generalizes.
