# Miss investigation matrix

`tools/compiler_matrix.py` checks variants with VC6 SP3 and the same strict
relocation gate as the audit. The small example retries four flag/source
recipes for two checked-in array and list utility near-misses.

```sh
python3 tools/compiler_matrix.py \
  reconstructed/match/investigations/utility-near-misses.json \
  --max-attempts 4 --top 4 --json-out /tmp/pc2-utility-near-misses.json
```

Use `--target 0xADDRESS` to focus on one function. The default limit is eight
attempts in config order. The summary ranks strict passes first, followed by
near-misses with fewer relocation/extent issues and smaller byte differences.
JSON adds the compiler hashes, flags, entry, first differing instruction, and
fixup evidence for each attempt. An experiment can finish with only near-misses.
Use `--require-match` when the exit code must require a strict pass.

Use `--symbol NAME=0xADDRESS` for independently established addresses. A JSON
`symbols` object can supply defaults per config, target, or variant. Narrower
scopes override broader ones, and command-line mappings take precedence.

## Cached near-miss pilot

Use the pinned VC6 toolchain and Capstone 5.0.7. Run a cold pass and then
point a warm pass at the same cache.

```sh
scratch=$(mktemp -d)
python3 tools/verify_near_miss_pilot.py \
  --recipes reconstructed/match/investigations/near-miss-pilot.json \
  --cache "$scratch/cache" --out "$scratch/cold" --jobs 4
python3 tools/verify_near_miss_pilot.py \
  --recipes reconstructed/match/investigations/near-miss-pilot.json \
  --cache "$scratch/cache" --out "$scratch/warm" --jobs 4 --cache-only
```

Each recipe references a tracked matcher receipt and source. A moved source
can override the receipt's path if its hash still agrees. Variants apply
reviewed, unique text substitutions to the pinned source. The pilot holds
the compiler, flags, entry, and symbol bindings fixed. Keep generated C++
and all objects and reports in scratch.

The report records the strict verdict, cache hit, first relocated block
differences, and review route for each attempt. A missing cache object makes
the cache-only run fail without compiling. Compare variants by gained and
lost equal blocks and use the strict matcher to certify any new match.

The pilot checked ten drafts. The final warm run reused all 22 objects with
zero compiler invocations and reproduced their hashes and comparison
results. Reusing locals for existing values improved `Sound_UpdateBufferFade`
(`0x542630`, 9 to 2 differing bytes) and `Game_FindTargetWithMinA8`
(`0x4e1fe0`, 27 to 23). The pilot added zero strict bytes. It also routed
`0x4cb950` to secondary-section review and `0x47f670` to extent review.

### Compiler profile screen

Use `near-miss-flag-screen.json` with the same runner and cache. Its
profiles hold the source, symbol bindings, language, and exception model
fixed. Each profile varies a selected optimization axis. The report
groups profiles with identical emitted bytes and relocations for each
address and ranks exact paired blocks ahead of a raw byte count.

The screen ran 51 attempts on 14 drafts, recompiling 43 and reusing eight
existing objects. It found 44 distinct emitted signatures. The warm pass
reproduced all 51 results without compiler calls. No profile gained an
equal block or passed strict matching. `/Oy-` reduced the raw count for
`0x4f1f70` from 164 to 157 with the same four equal blocks. `/O1` reduced
that raw count to 121 while losing all four equal blocks.

### Automatic VC6 unwind anchors

```sh
python3 reconstructed/match/investigations/0x4cb950/verify_strict.py
```

`tools/verify_vc6_eh_anchor.py` brackets the requested function with
neighboring indexed handlers and requires a unique compatible handler
shape. It omits the requested function's own handler operand during
anchor inference. The strict matcher then verifies that operand, the
primary code, and the relocated secondary sections. The pilot supports
the VC6 frame prologue and simple unwind-map format covered by
`compare_vc6_unwind.py`.

The new resolver reproduced the slider and bitmap gadget factory anchors
from the existing [controls](high-payoff-2026-11-22.md). The slider
interval contained two stubs with different unwind graphs. The resolver
selected the one-state graph. The registry reader at `0x4cb950` gained
**257 strict code bytes** with the inferred `$L270 = 0x558bb8` anchor.
The actual cleanup in both original and candidate uses `[ebp-0x14]`.
Changing that displacement in a scratch object preserved the inferred
anchor and failed strict verification. The three verified replacements
linked into a byte-identical scratch PE.

### Wider retained-draft sweep

```sh
scratch=$(mktemp -d)
python3 tools/sweep_vc6_drafts.py --cache "$scratch/coff" \
  --out "$scratch/drafts" --exclude 0x4cb950 --exclude 0x4cec60 --jobs 8
python3 tools/propose_symbol_mappings.py "$scratch/drafts" \
  --json-out "$scratch/symbols.json" --report-out "$scratch/symbols.md"
```

The sweep selects tracked nonmatching C/C++ sources with contiguous
indexed extents and skips addresses with a tracked candidate outside
`nonmatching/`. Pass `--exclude` for strict generator matches that keep a
historical draft. It reuses current source-hash-verified recipes where
available and records the defaults used on older sources. `--eh-only`
selects the supported original prologue and `--address` narrows the set.
Full matcher receipts go in `functions/`. Eligible sources use the same
COFF cache as the near-miss pilot. `--cache-only` reports unavailable
objects without compiling.

The broader run checked 303 drafts. After retrying two entry and compiler
mode errors, every draft received a matcher receipt. A warm run reproduced
the 297 cache-eligible results. Six sources bypassed caching. The EH
resolver inferred six anchors among 28 EH drafts. All six still have
primary code differences, and three retain blocked secondary sections.
The symbol pass found no promotable
body-only matches. Forty-five drafts were within eight diagnostic bytes,
and the sweep added zero strict bytes.

The wider flag screen added 28 drafts and 84 attempts in two shards.
The warm screen reused all 84 objects. `Person_RefreshShopChoices`
(`0x4dcd00`) gained two equal blocks under `/O2 /TP /Oy-`, reaching
eight of 19. The other profiles added no net equal blocks and no strict
matches. A bounded source-shape check of the three clean one-byte misses
and a pair of hiring functions also left their strict status unchanged.

## Historical matrices

Compiler hashes recorded for `matrix01.json`:

```text
CL.EXE    d9220fdfaf355c81f26e7b03c5dc628ec72ff81c99dc38ed98b1ad4bdbbb309c
C2.DLL    a0cc45f83fd0ed009aa4f43df5598105a1049ad9675de0b1089be7cce7d3c153
LINK.EXE  9672e578fdfaa43bdb8e9c16071682988665cb90bba2904bf02f6a5576d8ffbc
```

## Results

| target | variant | differing bytes | first instruction |
|---|---|---|---|
| 0x4ecd70 | base `/O2 /TP` | 9 | `mov esi,[esp+0x28]` |
| 0x4ecd70 | `/O2 /Oy` | 9 | same |
| 0x4ecd70 | `/O1` | 431 | `sub esp,0x18` |
| 0x4ecd70 | stream volatile | 505 | `push ebx` |
| 0x4ecd70 | self local | 9 | same |
| 0x509a20 | base `/O2` | 320 | `je 0x509a6c` |
| 0x509a20 | `/O1` | 293 | `push esi` |
| 0x509a20 | `/Os` | 388 | `push ebx` |
| 0x509a20 | `/Ot` | 384 | `push ebx` |
| 0x509a20 | inverted switch | **178** | `je 0x509a6c` |
| 0x509a20 | inverted + `/O1` | 294 | `push esi` |
| 0x532400 | base | 152 | `push 0xffffffff` |
| 0x532400 | base `/GX` | **110** | `mov ebx,ecx` |
| 0x532400 | out-of-line ctor `/GX` | 128 | `push edi` |
| 0x532400 | volatile new | 134 | `sub esp,0x8` |

Second matrix (`matrix02.json`) on the two best source shapes:

```text
0x509a20 inverted + /Ob1, /Ob2, /Oy   178
0x509a20 inverted + /G6               218
0x532400 out-of-line ctor + /Ob1      128
0x532400 out-of-line ctor + /Ob2      110
0x532400 out-of-line ctor + /Oy       128
0x532400 out-of-line ctor + /G6       128
0x532400 ctor parentheses             128
0x532400 ctor initializer             128
```

The earlier 28-byte figure for the out-of-line constructor was an artifact of
the matcher selecting `.text` instead of the section containing the entry
symbol; the checker now selects the entry symbol's section, so 128 is the
correct result.

### Sound lock-guard family

`reconstructed/match/investigations/sound-lock-family/README.md` records the
shared RAII `LockGuard` recipe for `0x544620`, `0x5448c0`, `0x544760`, and
`0x5449a0`. The candidates reproduce the EH sections, the out-of-line
destructor at `0x53ff80`, and (for `0x5448c0`/`0x544760`) the exact function
extent. Remaining differences are primary-code scheduling and register
allocation. `0x544760` is a 223-byte strict match. `0x5448c0`, `0x544620`,
and `0x5449a0` remain deferred. Two ABI corrections are important: the free functions are `__stdcall`
with `self` on the stack (not `__thiscall`), and the `view` calls are virtual
COM calls (`mov ecx,(%eax); call *slot(%ecx)`), not function-pointer members.

#### Whole-executable cleanup inventory

```sh
python3 tools/map_vc6_cleanup_families.py \
  --cleanup 0x53ff80 --cleanup 0x401480 --out /tmp/pc2-cleanup-families.json
```

The inventory decodes 226 supported unwind maps. It groups functions by
the cleanup targets actually called by their unwind actions, recording the
handler, state transitions, and frame offsets. The lock-guard destructor
at `0x53ff80` appears in 24 functions covering 9,730 indexed bytes.
`List_Node_Destroy` at `0x401480` appears in 43 functions covering 36,931
indexed bytes. The counts describe search scope. A function can appear in
several groups, and sharing a cleanup target establishes an unwind
dependency.

The first new lock-guard holdout was `List_RemoveNodeLocked` at `0x544af0`.
Using the existing guard recovered the exact 166-byte extent, call
relocations, unwind sections, and emitted destructor. A null-first ternary
for the `current` update reduced the mismatch from 11 to **1 byte**; the
remaining byte is the `jne` displacement around the conditional store.

```sh
python3 tools/match_decomp.py 0x544af0 \
  reconstructed/match/batch16/part4/nonmatching/0x544af0.cpp \
  --length 166 --entry '?RemoveNodeLocked@LockedList@@QAEXPAULockedListNode@@@Z' \
  --flags '/O2 /GX /TP' --strict --auto-symbols
```

#### Cached family batch runner

`tools/run_family_batch.py` compiles, caches, strict-verifies and scores a
JSON family spec. The small lock-guard spec is tracked at
`reconstructed/match/investigations/sound-lock-family/family.json`.

```sh
python3 tools/run_family_batch.py \
  --config reconstructed/match/investigations/sound-lock-family/family.json \
  --out /tmp/pc2-family-lock --cache /tmp/pc2-family-cache --jobs 4

# Warm run: no compiler invocations, every object reused.
python3 tools/run_family_batch.py \
  --config reconstructed/match/investigations/sound-lock-family/family.json \
  --out /tmp/pc2-family-lock-warm --cache /tmp/pc2-family-cache \
  --jobs 4 --cache-only
```

Current scoreboard: **1/5 strict, 223/1,072 bytes**. `0x544760` is strict;
`0x544af0` is 1 byte away; `0x5448c0` is 51 bytes away; `0x544620` is 124
bytes away; `0x5449a0` is 86 bytes away and 6 bytes short. A warm run reuses
all five objects without invoking VC6.

### Family registry

`reconstructed/match/investigations/family-registry/README.md` joins two
independent family lenses: 20 VC6 cleanup families from the unwind maps and
147 call-target families from `tools/mine_feature_families.py`. After
joining with tracked sources and matcher metadata there are **60 families**
and **31 runnable batch specs**.

Measured scoreboards:

```text
call:0x4017f0   72/78 strict   5,002/5,898 bytes   5 near misses, 1 blocked
call:0x54cc2b   22/23 strict   1,418/1,546 bytes   1 blocked
call:0x54cbc1   20/21 strict   1,135/1,265 bytes   1 blocked
call:0x488be0   12/13 strict     817/919 bytes     1 blocked
call:0x54f140   13/14 strict   1,512/1,671 bytes   1 mismatch
list pilot        6/7 strict     466/632 bytes     1 near miss (1 byte)
small guard       1/5 strict     223/1,072 bytes   EH sections exact
sound destructors 3/3 strict     316/316 bytes     generator emitted
```

The UI call-target groups are already covered by the existing UI builder
generator: `0x523bb0` is 79/79 generated (259,523 bytes), `0x531c60` is 26/26
(138,825 bytes), and `0x523c90` is 6/7 (26,925 bytes). Across the five UI
families the generator covers **436,776 bytes**. `Screen_MissionGoals` was
added by accepting whitespace before a call's semicolon; `OfficeView`
needed local buffers, `IDMap_Lookup`, `String_Format`, and the
`DAT_0057c670` pointer global. Only `Screen_MissionBriefing` remains
unsupported.

### List family pilot

`reconstructed/match/investigations/list-family/README.md` applies the same
cached batch runner to the `List_Node_Destroy` family. The pilot is **6/7
strict, 466/632 bytes**: `List_Node_Destroy` (43), `List_Add` (251, new strict
match), `List_AppendNode` (59, new strict match), `List_PushFront` (32),
`List_FreeAll` (51) and `List_ContainerDestroy` (30).
`List_RemoveNodeLocked` is one byte away.

`List_Add` is the first new list-family match from the inventory. Its source
uses `if (count >= capacity)` to reproduce the shipped `cmp count,capacity;
jl` operand order, and `memcpy(new, old, capacity * 4)` to reproduce the
inline `rep movsl`/`rep movsb` growth copies. The global lock is `0x579af0`
with `Enter`/`Leave` at `0x401320`/`0x401340`.

`List_AppendNode` matches after re-reading `this+0xbc` for the loop cursor;
using the `head` local left the peeled first test in EAX instead of ECX.

## Next experiments

- `0x4ecd70`: the nine-byte prologue difference is unchanged by `/Oy`,
  `/O1`, the volatile stream local, and the self local. Park the member
  signature; the next experiment should change the first live use of `this`
  without changing the body (e.g. an explicit self alias passed through the
  stream read).
- `0x509a20`: the inverted-switch source is the clear winner (178 vs 320);
  `/Ob1`, `/Ob2` and `/Oy` do not change it, `/G6` is worse (218). Next change
  block/table layout and the explicit `default:` path, not the flags.
- `0x532400`: `/GX` with the inline constructor is the best result (110).
  The out-of-line/initializer forms are worse (128). Next vary temporary
  lifetime and constructor declaration while keeping `/GX`, then compare the
  EH state stores.

No compiler setting from this matrix has been applied across a batch. Any
batch-wide flag change must first rerun a known matching sibling.
