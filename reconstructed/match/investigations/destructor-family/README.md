# VC6 destructor family generator

`tools/generate_destructor_family.py` emits and strict-verifies C++
destructors from a small JSON spec. It supplies the shared COM-style base
class, inserts explicit field padding, emits each destructor body, resolves
the original vtable/method addresses, compiles with the pinned VC6 toolchain,
and writes a `family.json` for `tools/run_family_batch.py`.

## Result

```text
sound-destructors: 4/4 strict, 523/523 bytes
  0x53f020   91  SoundBuffer      (vtable 0x55c830, deleting 0x53f000)
  0x53f5d0  126  SoundSample      (vtable 0x55c850, deleting 0x53f5b0)
  0x546750   99  SoundBuffer2     (vtable 0x55cb14, deleting 0x546730)
  0x53fcc0  207  SoundPakManager  (vtable 0x55c864, deleting 0x53fca0)
```

All four candidates reproduce the primary body, `.text$x`, `.xdata$x`, the
`0x53efd0` cleanup thunk, the derived/base vtables, and the shared
AddRef/Release/QueryInterface method targets.

## Shared recipe

The family base is:

```cpp
struct SoundBufferBase {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual ~SoundBufferBase() {}
};
```

The compiler emits the EH frame because the destructor has a virtual base;
the unwind cleanup resets the vtable to `0x55c840` through the tiny
`0x53efd0` thunk. The three shared methods are bound to:

```text
m0 = 0x53ef60   AddRef
m1 = 0x53ef70   Release
m2 = 0x53ef90   QueryInterface-like
base deleting destructor = 0x53efe0
```

`SoundBuffer` fields are `+4 int`, `+8 Child *`, `+0xc unsigned char`.
`SoundSample` fields are `+4 int`, `+8 SoundStream *`, `+0xc int`,
`+0x10 void *`, `+0x3c void *`.

## Run

```sh
sh reconstructed/match/investigations/destructor-family/verify_strict.sh
# 4/4 strict

python3 tools/generate_destructor_family.py \
  --spec reconstructed/match/investigations/destructor-family/destructors.json \
  --out /tmp/pc2-destructors

python3 tools/run_family_batch.py \
  --config reconstructed/match/investigations/destructor-family/generated/family.json \
  --out /tmp/pc2-destructor-batch --jobs 2
```

## Switch body form

`SoundBuffer2` matches with a real switch, not a range test:

```cpp
switch (state) {
case 0:
    field8->Release();
    break;
case 1:
    field8->Release();
    break;
case 2:
    field8->Release();
    break;
}
```

The generator accepts arbitrary body lines, so the switch form needs no
special syntax. `if (state < 3)` produced a single `cmp/jge` block and a
41-byte mismatch; the three-case switch reproduces the shipped
`sub/dec/dec` chain and two release tails.

## Shared helper matched by Gemma

The local Gemma worker matched two shared helpers:

```text
0x53ef60  RefCount_AddRef              strict  16/16 bytes
0x53efd0  SoundBuffer_SetBaseVTable    strict   7/7 bytes
0x53fd90  CS_Delete                     strict   8/8 bytes
```

They are verified by `verify_helpers.sh` and `helpers.json`. The AddRef
extent is 16 bytes; a 14-byte check only passes by splitting the `ret 4`
immediate into an inline tail, so the recipe uses the true extent. The
base-vtable bytes are the cleanup thunk referenced by the destructor unwind
maps.

## Member subobjects and unwind checks

The generator now supports a `members` list. Each member emits a real class
definition with explicit field padding, an optional inline destructor, and a
bound destructor symbol:

```json
"members": [
  {
    "class": "TrackBuffer",
    "address": "0x541f00",
    "inline": true,
    "fields": [
      {"decl": "char pad0[8];", "offset": 0},
      {"decl": "void *field8;", "offset": 8}
    ],
    "body": ["if (field8 != 0) { Mem_Free(field8); }"]
  }
]
```

Member classes are placed with a normal field entry:

```json
{"decl": "TrackBuffer buffer;", "offset": "0x3c", "size": "0xc"}
```

The report also decodes the generated object's unwind with
`compare_vc6_unwind.compare` and records:

```json
"unwind": {
  "original_states": 2,
  "candidate_states": 2,
  "differences": {"transfers": 2}
}
```

## Experimental members

`experimental.json` holds `0x541f30 SoundTrack` (138 bytes). The member
subobject now gives the candidate the correct **two unwind states**:

```text
0x541f30 SoundTrack  diff 29
  original_states=2 candidate_states=2
  compare_vc6_unwind: differences={"transfers": 2}
```

The `transfers: 2` line is a reporting artifact, not a wrong cleanup: the
strict locator places the candidate's two cleanup thunks at `0x53efd0` and
`0x541f00`, matching the original. `compare_vc6_unwind` leaves internal COMDAT
targets as `(section, offset)` and therefore cannot compare them to the
original VAs.

The real blocker is the primary state transition: the original writes the
EH state `0` **before** the inline member free (`movb [esp+0x10],0`), while
the candidate keeps state 1 active through the member destructor. The next
generator form needs to express that explicit state release, not another
member layout change.

### State-release experiments

| source shape | diff | result |
|---|---:|---|
| member subobject, inline destructor | 29 | correct 2 states/targets, missing state-0 store |
| member subobject, out-of-line destructor | 21 | emits `call` instead of the inline free |
| `Buffer` base subobject | 33 | adds null-adjustor checks and 6 extra bytes |
| explicit `buffer.release()` / scope | not expressible | no source-level EH-state store |

The state-0 store is a VC6 destructor-scope scheduling artifact; ordinary
C++ scope exit does not emit it before an implicit member destructor. Minimal
SP3 repros with a virtual base plus a member destructor — simple free, free
loop, virtual call, explicit member destructor call, and explicit base
destructor call — all failed to emit `movb [esp+state],0`. This suggests the
original `0x541f30`/`0x5408b0` state store may come from a different C2/EH
codegen revision or a non-obvious local scope, not a missing member shape.
SoundTrack is parked as a 29-byte near miss; `0x5408b0` has the same wall.

## SoundPakManager body and call linkage

`0x53fcc0` adds two requirements that the earlier members did not exercise:

1. A member subobject at `+0x23c` whose inline destructor calls
   `DeleteCriticalSection`. The compiler emits the normal-path call inline and
   the unwind action `mov ecx,[ebp-0x10]; add ecx,0x23c; jmp 0x53fd90`, i.e.
   the same cleanup shape as the shared member class.
2. C++-linkage declarations for `Mem_Free` and `CRT_Fclose`:

```cpp
void Mem_Free(void *);
int CRT_Fclose(void *);
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void *);
```

The linkage matters. With `extern "C"` calls, VC6 does not create a try region
for the destructor body, so the whole `fs:[0]` frame disappears (candidate
160 bytes, original 207). Declaring the two CRT calls as C++ makes them
potential throw sites and reproduces the two-state unwind frame.

The list loop must free before it stores the next head, otherwise VC6 keeps
`head` updated across the call and adds four bytes:

```cpp
while (head != 0) {
    Node *next = head->next;
    Mem_Free(head);
    head = next;
}
```

`head = next; Mem_Free(node);` produced a 52-byte mismatch; the free-first
order reproduces `mov edi,[eax+0x50]; push eax; call; mov [esi+0x628],edi;
test edi,edi; jne ...` exactly.

The array loop uses a 20-entry array at `+8` (stride `0x1c`, fields at
`+0/+4/+0x18`), a count at `+0x238`, and a list head at `+0x628`.

## Next destructor targets

```text
0x5408b0 SoundBuffer_DestructDerived   169 bytes  vtable 0x55c874
0x541790 SoundStreamBuffer_Destruct    225 bytes  vtables 0x55c8b0/0x55c8c8/0x55c874
0x546750 SoundBuffer_Destructor         99 bytes  experimental above
0x541f30 SoundTrack_Destruct           138 bytes  experimental above
```

The generator should be extended with a `states` field for extra unwind
cleanup actions and a `switch`/`if` body form, then the remaining members can
be emitted from the same spec.
