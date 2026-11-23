# VC6 destructor family generator

`tools/generate_destructor_family.py` emits and strict-verifies C++
destructors from a small JSON spec. It supplies the shared COM-style base
class, inserts explicit field padding, emits each destructor body, resolves
the original vtable/method addresses, compiles with the pinned VC6 toolchain,
and writes a `family.json` for `tools/run_family_batch.py`.

## Result

```text
sound-destructors: 8/8 strict, 1,250/1,250 bytes
  0x53f020   91  SoundBuffer          (vtable 0x55c830, deleting 0x53f000)
  0x53f5d0  126  SoundSample          (vtable 0x55c850, deleting 0x53f5b0)
  0x5408b0  169  SoundBufferList      (vtable 0x55c874, deleting 0x540890)
  0x541660  195  SoundStreamLayer     (vtable 0x55c8c8, deleting 0x541730)
  0x541790  225  SoundStreamBuffer    (vtable 0x55c8b0, deleting 0x541770)
  0x541f30  138  SoundTrack           (vtable 0x55c8e0, deleting 0x541f10)
  0x546750   99  SoundBuffer2         (vtable 0x55cb14, deleting 0x546730)
  0x53fcc0  207  SoundPakManager      (vtable 0x55c864, deleting 0x53fca0)
```

All eight candidates reproduce the primary body, `.text$x`, `.xdata$x`, the
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
# 8/8 strict

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

## State release resolved (0x541f30 and 0x5408b0)

Both parked members now match. The missing `mov [esp+state],0` was not a C2
revision or a scope artifact: it depends on whether the member destructor can
throw. With `extern "C"` `Mem_Free`, VC6 keeps state 1 active through the
inlined member destruction. Declaring `Mem_Free` as a C++ function makes the
member destructor a throw site and VC6 emits the state-0 store before inlining
it, exactly as in the original:

```cpp
void Mem_Free(void *);          // C++ linkage, can throw
```

The same distinction explains the `0x541f30` near miss: the experimental spec
used `extern "C" void __cdecl Mem_Free` and also advanced the `TrackBuffer`
cursor by four bytes too many (`char pad0[8]` without `"size": 8`), placing
`field8` at `+0xc` instead of `+0x8`. With the C++ declaration and the corrected
field size, both `0x541f30` and `0x5408b0` are byte-identical. `experimental.json`
is retained as the single-class reproduction; the classes are also in the main
`destructors.json`.

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

## Destructor inheritance chains

`0x541660` and `0x541790` are one single-inheritance chain:

```text
SoundBufferBase        vtable 0x55c840
  SoundBufferList      vtable 0x55c874  dtor 0x5408b0
    SoundStreamLayer   vtable 0x55c8c8  dtor 0x541660
      SoundStreamBuffer vtable 0x55c8b0 dtor 0x541790
```

The spec expresses this with a `base` field and a per-class `symbols` map. The
generator resolves the ancestry automatically and emits the ancestor classes
with **inline** destructor bodies; the target destructor is declared
out-of-line and defined after the classes. That is the shape VC6 needs:

- an inline ancestor destructor is inlined into the derived destructor;
- the out-of-line target destructor forces emission of the entry COMDAT and of
  the ancestor vtables/deleting destructors;
- defining the ancestors out-of-line instead leaves real calls and produces a
  96-byte target instead of 225.

The target body only releases its own interface at `+0xac`; the inlined chain
then performs the `+0x5c` release, the `List` teardown, and the base vtable
reset, with EH states numbered 0/1/2/3 by the compiler.

## Next destructor targets

The indexed sound-destructor set is complete. The next destructor-shaped work
is the other classes in the cleanup registry (`0x53fcc0`-like pak managers,
stream/base buffers, and vtable-linked COM wrappers), which should be grouped
by their unwind-map shape before hand-matching.

The generator should be extended with a `states` field for extra unwind
cleanup actions and a `switch`/`if` body form, then the remaining members can
be emitted from the same spec.
