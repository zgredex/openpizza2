# Qwen destructor tasks

These are small, independent tasks for a local Qwen worker. Read
`reconstructed/match/investigations/destructor-family/README.md` first.

## Hard rules

- Work only inside your assigned `qwen-*` directory. Do not edit shared tools,
  specs, generated sources, other workers' directories, or git history.
- Do not commit. Leave your best source and a `report.md` in your directory.
- Use the pinned toolchain and the existing tools:
  - `/home/patryk/.local/share/pc2/vc6-sp3-toolchain/VC98`
  - `tools/match_decomp.py`
  - `tools/generate_destructor_family.py`
  - `tools/run_family_batch.py`
- Genuine C++ only. No inline assembly, no `volatile` steering, no fake calls,
  no object patching.
- A strict match needs the exact manifest length, exact entry symbol, zero
  differing bytes, and no strict/link-plan issues.
- Stop after your assigned function(s). If you cannot match, report the exact
  first difference and what you tried. A documented near miss is acceptable.

## Common base recipe

The sound destructors share:

```text
base vtable                0x55c840
base methods               0x53ef60 AddRef, 0x53ef70 Release, 0x53ef90 QI
base deleting destructor   0x53efe0
cleanup thunk              0x53efd0
```

`tools/generate_destructor_family.py` emits the shared base and binds these.
For a direct manual check:

```sh
python3 tools/match_decomp.py <address> <source.cpp> \
  --length <length> --entry '<mangled entry>' \
  --flags '/O2 /GX /TP' --strict --auto-symbols \
  --symbol '??_7SoundBufferBase@@6B@=0x55c840' \
  --symbol '?m0@SoundBufferBase@@UAEXXZ=0x53ef60' \
  --symbol '?m1@SoundBufferBase@@UAEXXZ=0x53ef70' \
  --symbol '?m2@SoundBufferBase@@UAEXXZ=0x53ef90' \
  --symbol '??_ESoundBufferBase@@UAEPAXI@Z=0x53efe0'
```

## Task A: `0x5408b0` SoundBuffer_DestructDerived (169 bytes)

Directory: `qwen-5408b0/`. Seed: `seed.cpp`.

- vtable `0x55c874`, deleting `0x540890`
- entry `??1SoundBufferDerived@@UAE@XZ`
- `List` member at `+0x38`, destructor `StreamList_FreeAll` at `0x541250`
- `List_DestroyObjects` at `0x540f60` (`__fastcall`, this in ECX)
- interface at `+0x48`: slots `+0x48` (query), `+0x34` (release2(0)), `+0x8` (release)
- flag at `+0x34`
- Original has two unwind states: base vtable `0x53efd0` and `List_FreeAll`
  `0x541250`. The state-0 store appears before the inlined list free.
- Current seed diff: 105, first at `0x16` (prologue/register allocation).
  Recover the `ebx`/`esi`/`edi` allocation and the list member shape.

## Task B: `0x53fcc0` SoundPakManager_Destruct (207 bytes)

Directory: `qwen-53fcc0/`.

- vtable `0x55c864`, deleting `0x53fd70` (check by disassembly; confirm)
- entry `??1SoundPakManager@@UAE@XZ`
- critical-section member at `+0x23c`, destructor `CS_Delete` at `0x53fd90`
- entries array at `+0x20`, count at `+0x238`; each entry stride `0x1c`
- linked list at `+0x628`, nodes freed via `0x54dd78`
- original has two unwind states: base vtable `0x53efd0` and `CS_Delete`
  `0x53fd90`.
- Reconstruct from the disassembly and the exported pseudocode at
  `decompiled_fastfood2_named_v2/full_game_verification/functions/0x53fcc0.c`.
- Work in small steps: first match the prologue and the count loop, then the
  linked-list tail, then the member cleanup.

## Task C: `0x541f30` state-release micro-experiment

Directory: `qwen-state-release/`. Seed: `seed.cpp`.
Read the "SoundTrack residual" section of the family README.

- Current member model: correct 2 unwind states and cleanup targets, diff 29.
- Missing sequence before the inlined member free:

```asm
mov  eax,[esi+0x44]
movb [esp+0x10],0
test eax,eax
```

- Try a **minimal class** with a member destructor and a virtual base, and
  find a legitimate C++ scope/order shape that makes VC6 emit the state-0
  store before the inline member free.
- Do not use explicit destructor calls that double-free; do not use asm or
  volatile.
- If no shape works, report the smallest repro and the exact codegen for each
  shape tried.

## Report format

Write `report.md` in your directory:

```text
target:
source:
entry:
length:
strict: yes/no
candidate_length:
difference_count:
first_difference:
strict_issues:
exact source change / remaining blocker:
```
