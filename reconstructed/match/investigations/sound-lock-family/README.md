# Sound lock-guard family: handoff

This file is a self-contained brief for another engineer/LLM with access to
`game/fastfood2.exe` and this repository. The goal is to finish strict
byte-matches for the sound lock-guard family. Everything below was reproduced
against the checked-in binary; all addresses are virtual addresses in
`game/fastfood2.exe`.

## Mission

Strict-match these functions with genuine C/C++ (no inline assembly, no
volatile/asm steering just to force bytes):

| address | manifest name | bytes | original entry/ABI |
|---|---|---:|---|
| `0x544620` | SoundBuffer_StopPlaybackLocked | 211 | `?StopPlaybackLocked@SoundBuffer@@QAEHXZ`; `__thiscall`, ECX=`this`, `ret 0` |
| `0x5448c0` | Sound_QueryStatusLocked | 210 | free/COM-style `__stdcall`, args `(SoundBuffer *self, void *buffer, int *status)`, `ret 0xc`; **the manifest's `?QueryStatusLocked@SoundBuffer@@QAE...` name is wrong** |
| `0x544760` | Sound_GetPlayPosition | 223 | free/COM-style `__stdcall`, args `(SoundBuffer *self, int *buffer, unsigned int *status)`, `ret 0xc` |
| `0x5449a0` | Media_QueryFlagLocked (optional third sibling) | 262 | free/COM-style `__stdcall`, three stack args, has nested lock guards, 2 unwind states |

The immediate goal is the first three. `0x544760` is the closest: only 33
differing bytes, and every EH/secondary section is already byte-identical.

## Repository state at handoff

- HEAD at the time of writing: `f7a4cb2a` plus the commits listed below.
- Worktree contains unrelated older batch11/12/15 drafts and a deleted
  `batch20/part2/nonmatching/0x4d9ef0.*`; do not overwrite them.
- `tools/match_decomp.py` has the new automatic EH-section anchor resolver
  (see below). It is committed with this handoff.
- Target binary: `game/fastfood2.exe`.
- Toolchain: `~/.local/share/pc2/vc6-sp3-toolchain/VC98` (MSVC 6.0 SP3,
  `C2.DLL 12.00.8447`). Do not use a different compiler.
- Flags used here: `/O2 /GX /TP`.
- All strict checks use `tools/match_decomp.py --strict --auto-symbols`.

Useful existing verifications:

```sh
sh reconstructed/match/batch21/part3/verify_strict.sh
# strict matches: 8/8
```

The new resolver was validated by `0x406cd0` without the manually bound
`$L`/`$T` labels:

```sh
python3 tools/match_decomp.py 0x406cd0 \
  reconstructed/match/batch21/part3/0x406cd0.c \
  --length 158 --entry '?Config_SaveOptionsToRegistry@@YAXXZ' \
  --flags '/O2 /TP /GX' --strict --auto-symbols \
  --symbol '??1RegistryKey@@QAE@XZ=0x4031a0'
# strict_match true, difference_count 0
```

## The shared source recipe already recovered

The original uses one RAII lock-guard class. The exact destructor is a real
out-of-line function at `0x53ff80`:

```asm
0053ff80: 8b 01             mov    (%ecx),%eax
0053ff82: 50                push   %eax
0053ff83: ff 15 a0 c1 55 00 call   *0x55c1a0   ; LeaveCriticalSection
0053ff89: c3                ret
```

The guard class is effectively:

```cpp
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void *);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void *);

class LockGuard {
    void *section;
public:
    LockGuard(void *value) : section(value) { EnterCriticalSection(value); }
    ~LockGuard() { LeaveCriticalSection(section); }
};
```

Facts confirmed from the PE:

- The guard object is a 4-byte local (`push ecx` in the prologue).
- The constructor is inlined; normal returns inline the destructor body
  (`call *0x55c1a0`).
- The EH unwind map has exactly one state, `previous = -1`; its action is
  `LockGuard::~LockGuard` at `0x53ff80` with frame offset `-0x10`.
- The EH handler stubs/FuncInfo are:
  - `0x544620`: handler `0x55b378`, FuncInfo `0x560f98`
  - `0x5448c0`: handler `0x55b3b8`, FuncInfo `0x560fe8`
  - `0x544760`: handler `0x55b398`, FuncInfo `0x560fc0`
  - `0x5449a0`: handler `0x55b3e0`, FuncInfo `0x561010`, two unwind states
- The candidate objects reproduce `.text$x`, `.xdata$x`, and the out-of-line
  `LockGuard::~LockGuard` section **byte-identically** (after relocations) for
  all three primary candidates. The strict reports list no secondary-section
  byte differences; only the primary body and, for `0x544620`, one unresolved
  symbol `?DestroyObjects@ListObject@@QAEXXZ` remain.

The lock locations:

- `0x544620`: `this + 0x38` holds a `void *` lock pointer. The guard stores
  the pointer value.
- `0x5448c0`: `self + 0xa0` is the `CRITICAL_SECTION`; the guard stores
  `self + 0xa0`.
- `0x544760`: same as `0x5448c0`.
- `0x5449a0`: outer guard `self + 0xa0`; inner guard `object + 0x38`.

## ABI corrections

`0x5448c0`/`0x544760`/`0x5449a0` do **not** use `__thiscall`. The original
prologue loads the first stack argument into a register and the epilogue is
`ret 0xc`:

```asm
; 0x5448c0
005448d6: 56                push   %esi
005448d7: 8b 74 24 18       mov    0x18(%esp),%esi   ; arg1 = self
...
0054498f: c2 0c 00          ret    $0xc
```

That is a `__stdcall` function with `self` as the first stack argument
(COM-style). Compile them as C++ `__stdcall` free functions; `extern "C"`
suppresses the VC6 EH frame. For example:

```cpp
int __stdcall QueryStatusLocked(SoundBuffer *self, void *buffer, int *status);
int __stdcall Sound_GetPlayPosition(SoundBuffer *self, int *buffer,
                                    unsigned int *status);
```

The C++-linkage/`__stdcall` mangling is accepted by the matcher; use the
symbol that `nm`/`parse_coff` reports, e.g.
`?QueryStatusLocked@@YGHPAUSoundBuffer@@PAXPAH@Z`.

## Virtual COM calls are required

The calls on `view` are real **virtual** `__stdcall` member calls, not
function-pointer members. The original loads the vtable and calls through it:

```asm
; 0x5448c0, slot +0x24
00544944: 8b 40 48          mov    0x48(%eax),%eax   ; view
00544947: 85 c0             test   %eax,%eax
0054494b: 32 c0             xor    %al,%al
0054494f: 8b 08             mov    (%eax),%ecx      ; vtable
0054495d: 52                push   %edx             ; &value
0054495e: 50                push   %eax             ; this on stack
0054495f: ff 51 24          call   *0x24(%ecx)
```

and `0x544760` calls slot `+0x10` with two output pointers:

```asm
005447f8: 8b 08             mov    (%eax),%ecx
005447fa: 8d 54 24 28       lea    0x28(%esp),%edx
005447fe: 52                push   %edx
005447ff: 8d 54 24 24       lea    0x24(%esp),%edx
00544803: 52                push   %edx
00544804: 50                push   %eax
00544805: ff 51 10          call   *0x10(%ecx)
```

Model these as `virtual int __stdcall method(...)` in a dummy vtable struct.
For `0x5448c0` the method is at vtable offset `0x24` (slot 9); for
`0x544760` it is at `0x10` (slot 4). A function-pointer member produces
`call *0x24(%eax)` instead and does not match.

## Best candidate sources

The files in this directory are copied under their historical names:

- `0x544620-guard.cpp` — best `0x544620` candidate (diff 124/211)
- `0x5448c0-virtual-char.cpp` — best `0x5448c0` candidate (diff 51/210)
- `0x544760-virtual.cpp` — best `0x544760` candidate (diff 33/223)
- `0x*-original.asm`, `0x*-candidate.asm` — objdump evidence
- `0x*.json` — non-strict matcher receipts
- `0x*-strict.json` — strict receipts showing the EH sections are located and
  verified

All three candidates reproduce the EH sections and the guard destructor; only
the primary code differs.

### `0x544620` — `0x544620-guard.cpp`

Length 211 (manifest extent), first difference at offset 41 (`0x544649`).
The body is byte-identical from `0x544690` onward when the candidate is
shifted by `-0x61e`; only two early blocks are scheduled differently.

Original:

```asm
00544649: 33 db             xor    %ebx,%ebx
0054464b: 88 5e 54          mov    %bl,0x54(%esi)
0054464e: 8a 46 53          mov    0x53(%esi),%al
00544651: 3a c3             cmp    %bl,%al
00544653: 89 5c 24 18       mov    %ebx,0x18(%esp)
00544657: 75 1e             jne    0x544677
...
00544677: b0 01             mov    $0x1,%al
00544679: 88 5e 53          mov    %bl,0x53(%esi)
0054467c: 89 9e 84 00 00 00 mov    %ebx,0x84(%esi)
00544682: 88 86 88 00 00 00 mov    %al,0x88(%esi)
00544688: 38 5e 58          cmp    %bl,0x58(%esi)
0054468b: 74 03             je     0x544690
0054468d: 88 46 57          mov    %al,0x57(%esi)
```

Candidate:

```asm
  29: 8a 46 53          mov    0x53(%esi),%al
  2c: 33 db             xor    %ebx,%ebx
  2e: 3a c3             cmp    %bl,%al
  30: 89 5c 24 18       mov    %ebx,0x18(%esp)
  34: 88 5e 54          mov    %bl,0x54(%esi)
  37: 75 1e             jne    0x57
...
  57: 8a 4e 58          mov    0x58(%esi),%cl
  5a: b0 01             mov    $0x1,%al
  5c: 3a cb             cmp    %bl,%cl
  5e: 88 5e 53          mov    %bl,0x53(%esi)
  61: 89 9e 84 00 00 00 mov    %ebx,0x84(%esi)
  67: 88 86 88 00 00 00 mov    %al,0x88(%esi)
  6d: 74 03             je     0x72
  6f: 88 46 57          mov    %al,0x57(%esi)
```

The compiler hoisted the `field53` load above the `field54` store, and hoisted
the `field58` load and `al = 1` above the three stores. The source statement
order is already exactly the original's order:

```cpp
field54 = 0;
if (field53 == 0) return 1;
field53 = 0;
field84 = 0;
field88 = 1;
if (field58 != 0) field57 = 1;
```

Approaches tried without success: `if (!field53)`, `bool` fields, `if
(field58)`, conditional layouts A/B, moving `field54 = 0` into the branch,
`int result` vs `unsigned char`, virtual/non-virtual `ListObject` calls.
`ListObject::DestroyObjects` should be a `__thiscall` member
(`mov ecx,esi; call 0x540f60`) to remove the last unresolved relocation; the
current candidate already models it as `object->DestroyObjects()` and that
part matches.

This is a register/schedule wall. Use the `permute` skill or a bounded
source-shape search over the early statements and local declarations. The
rest of the function already matches, so any source change that keeps offsets
`0x72+` aligned and makes the two blocks shorter by 2 bytes should close it.

### `0x5448c0` — `0x5448c0-virtual-char.cpp`

Length 210, exact. First difference at offset 23 (`0x5448d7`): the original
chooses ESI for `self` and EDI for the guard; the candidate chooses EDI for
`self` and ESI for the guard.

Original:

```asm
005448d5: 51                push   %ecx
005448d6: 56                push   %esi
005448d7: 8b 74 24 18       mov    0x18(%esp),%esi   ; self
005448db: 57                push   %edi
005448dc: 8d be a0 00 00 00 lea    0xa0(%esi),%edi   ; guard
005448e2: 57                push   %edi
005448e3: 89 7c 24 0c       mov    %edi,0xc(%esp)
005448e7: ff 15 b8 c1 55 00 call   *0x55c1b8
```

Candidate:

```asm
  15: 51                push   %ecx
  16: 56                push   %esi
  17: 57                push   %edi
  18: 8b 7c 24 1c       mov    0x1c(%esp),%edi   ; self
  1c: 8d b7 a0 00 00 00 lea    0xa0(%edi),%esi   ; guard
  22: 56                push   %esi
  23: 89 74 24 0c       mov    %esi,0xc(%esp)
  27: ff 15 b8 c1 55 00 call   *0x55c1b8
```

After the prologue the candidate uses `char result` (this is important; it
keeps the final result in AL and gives length 210). The remaining body
difference is the order of the `value = 0` initialization and the vtable load:

Original at `0x54494f`:

```asm
0054494f: 8d 54 24 1c       lea    0x1c(%esp),%edx
00544953: c7 44 24 1c 00 00 00 00  movl $0,0x1c(%esp)
0054495b: 8b 08             mov    (%eax),%ecx
0054495d: 52                push   %edx
0054495e: 50                push   %eax
0054495f: ff 51 24          call   *0x24(%ecx)
```

Candidate:

```asm
  8f: 8b 08             mov    (%eax),%ecx
  91: 8d 54 24 1c       lea    0x1c(%esp),%edx
  95: 52                push   %edx
  96: 50                push   %eax
  97: c7 44 24 24 00 00 00 00  movl $0,0x24(%esp)
  9f: ff 51 24          call   *0x24(%ecx)
```

Everything else (including `xor al,al`, `and al,1`, the final byte store,
and the guard destructor calls) is structurally the same. Try source shapes
that make the ESI/EDI assignment swap and the value initialization happen
before the vtable load. `char result` should be kept; `int result` gives 208
bytes and a different branch layout.

Note: the original does **not** check `view->vtable[0] != 0`; that was an
artifact in the old candidate. Do not reintroduce it.

### `0x544760` — `0x544760-virtual.cpp`

Length 223, exact. First difference at offset 151 (`0x5447f6`). The prologue
and all code through `0x5447f5` match exactly. Only the null-view zero
materialization differs.

Original:

```asm
005447f6: 74 1e             je     0x544816
...
00544814: 23 c1             and    %ecx,%eax
00544816: 33 c9             xor    %ecx,%ecx
00544818: 33 d2             xor    %edx,%edx
0054481a: 66 8b 4f 24       mov    0x24(%edi),%cx
```

Candidate:

```asm
  96: 74 20             je     0xb8
...
  b4: 23 c1             and    %ecx,%eax
  b6: eb 02             jmp    0xba
  b8: 33 c0             xor    %eax,%eax
  ba: 33 c9             xor    %ecx,%ecx
  bc: 33 d2             xor    %edx,%edx
  be: 66 8b 4f 24       mov    0x24(%edi),%cx
```

The original jumps straight to the divisor setup on the null path; EAX is
already 0 because it holds the tested `view` pointer. The candidate emits an
explicit `xor eax,eax` plus a `jmp` to skip it. Source variants tried:
`result = 0` initializer (reintroduces EBP/zero-register prologue mismatch),
explicit else branches (current, diff 33), ternary (diff 68), and
`if (view != 0) { if (call>=0) result=value; else result=0; }`. The goal is a
shape where VC6 reuses EAX=0 on the null path.

`Sound_GetPlayPosition` should keep the virtual COM call at vtable `+0x10`
with two uninitialized `int` out-parameters, and the unsigned division by
`*(unsigned short *)(object + 0x24)`.

## How to reproduce

Compile one candidate (from this directory):

```sh
VC=~/.local/share/pc2/vc6-sp3-toolchain/VC98
WINEDEBUG=-all wine "$VC/BIN/CL.EXE" /nologo /c /O2 /GX /TP \
  'Z:\home\patryk\pizzaconnection2\reconstructed\match\investigations\sound-lock-family\0x544760-virtual.cpp' \
  '/FoZ:\tmp\sound-0x544760.obj'
```

Or let the matcher compile it (it writes the object to a temp directory):

```sh
python3 tools/match_decomp.py 0x544760 \
  reconstructed/match/investigations/sound-lock-family/0x544760-virtual.cpp \
  --length 223 --entry '?Sound_GetPlayPosition@@YGHPAUSoundBuffer@@PAHPAI@Z' \
  --flags '/O2 /GX /TP' --strict --auto-symbols \
  --json-out /tmp/0x544760-strict.json
```

Use the exact manifest extent and entry. The candidate objects are also
checked with:

```sh
python3 tools/compare_vc6_unwind.py --address 0x544760 \
  --object /tmp/sound-0x544760.obj \
  --entry '?Sound_GetPlayPosition@@YGHPAUSoundBuffer@@PAHPAI@Z' \
  --symbol '??1LockGuard@@QAE@XZ=0x53ff80' \
  --out /tmp/0x544760-unwind.json
```

(The unwind tool reports the destructor as a COFF `(section, offset)` tuple
unless you map its section; the matcher's strict receipt is the authoritative
check that `.text$x`/`.xdata$x`/destructor bytes match.)

## Automatic EH anchor resolver (tool change made for this family)

`tools/match_decomp.py` now derives compiler `$L`/`$T` label addresses from
original PE bytes. When one EH section is located, a relocation field in that
section that points into a pending section yields the pending base directly
(`base = original_field - symbol.value - addend` for DIR32). This is
independent evidence and removes the need to hand-bind every per-object
`$L`/`$T` number. Implementation is `derived_section_anchors()` and the
location loop in `match_object()`.

Validated:

- `0x406cd0` strict without `$L266/$T265/$T268/$L258` bindings.
- The three sound candidates locate `.text$x`, `.xdata$x`, and the
  `0x53ff80` destructor section by derivation; no secondary-section bytes
  differ.
- `sh reconstructed/match/batch21/part3/verify_strict.sh` remains 8/8.

## Constraints / pitfalls

- Do not use inline assembly, naked functions, or hand-written stubs.
- Do not add `volatile` or opaque calls purely to steer codegen; that is a
  fakematch under `reconstructed/match/STRICT_AUDIT.md` / the code rules.
- Keep the guest semantics identical. The guard must be destroyed on every
  return and on unwind.
- `extern "C"` suppresses VC6's C++ EH frame. Use C++ linkage.
- The guard destructor must be the same class in all functions so the
  compiler emits/reuses the out-of-line `0x53ff80` shape.
- `0x5448c0`/`0x544760` are `__stdcall` with `self` on the stack; do not
  "fix" them to `__thiscall` just because the manifest name says `QAE`.
- A strict match requires the candidate extent to equal the manifest extent.
  The current `0x544620` candidate is 213 bytes before trimming; after using
  the manifest extent 211 the first 211 bytes still differ in the two early
  blocks.
- `0x544620`'s `ListObject::DestroyObjects` relocation should resolve as a
  `__thiscall` call (`mov ecx,esi; call 0x540f60`). The current source does
  this; keep it.

## Suggested next moves

1. Use the `permute` skill on `0x544760-virtual.cpp` first (33 bytes, exact
   length, exact EH). Vary only the null-view result shaping; keep the guard,
   virtual call, and prologue untouched.
2. Then permute `0x5448c0-virtual-char.cpp` (51 bytes). The prologue swap is
   likely source-shape driven; try local aliases for `self`, declaration
   order, and placing `value` initialization before the vtable load. Keep
   `char result`.
3. Leave `0x544620` for last; it is a pure scheduler wall but 124 bytes and
   2 bytes of length. A permutation search over the early field-write block
   is the right tool.
4. When a candidate becomes strict, move it to the appropriate batch
   directory, add a `verify_strict.sh` line, and record the shared recipe in
   this README rather than only in the per-function worklog.

## Quick status summary

```text
0x544620  211 bytes  diff 124  first 0x544649  EH sections match
0x5448c0  210 bytes  diff  51  first 0x5448d7  EH sections match
0x544760  223 bytes  diff  33  first 0x5447f6  EH sections match
0x5449a0  not attempted in this pass; same guard pattern, nested guards
```
