# Gemma tiny destructor tasks

These are intentionally small: one or two helper functions per worker.
Work only in your assigned `gemma-*` directory. Do not edit shared tools,
specs, other workers' directories, or git history. Do not commit.

Use the pinned VC6 toolchain:

```text
/home/patryk/.local/share/pc2/vc6-sp3-toolchain/VC98
```

Compile with `/O2 /TP` (add `/GX` only where stated). Strict-verify with
`tools/match_decomp.py --strict --auto-symbols`. Genuine C/C++ only; no inline
assembly, no volatile steering, no fake calls, no object patching.

The shared destructor family uses these helpers. Matching them strengthens
the vtable/cleanup evidence even though they are not all separate manifest
records.

## Task 1: AddRef at `0x53ef60` (16 bytes)

Directory: `gemma-53ef60/`.

Original:

```asm
mov eax,[esp+4]
mov ecx,[eax+4]
inc ecx
mov [eax+4],ecx
mov eax,ecx
ret 4
```

This is a `__stdcall` free function with one stack pointer:

```cpp
struct RefCounted { int pad; unsigned int count; };
extern "C" unsigned int __stdcall RefCount_AddRef(RefCounted *self)
{
    return ++self->count;
}
```

Candidate entry: `_RefCount_AddRef@4`. Length: 16. Flags: `/O2 /TP`.
Expected strict result: zero differing bytes. The 2-byte tail after the
14-byte body is alignment/padding.

## Task 2: QueryInterface at `0x53ef90` (51 bytes)

Directory: `gemma-53ef90/`.

Original takes `self` and an output pointer, compares four dwords against
the GUID at `0x55cb68`, writes `self` to `*out` and returns 0 on a match,
otherwise writes 0 and returns `0x80004002`. It is `__stdcall` with
`ret 8`.

Start from this shape and tune it:

```cpp
struct RefCounted { void *vtable; int pad; };
struct Guid { unsigned int a, b, c, d; };
extern "C" const Guid GUID_0055cb68;
extern "C" int __stdcall RefCount_QueryInterface(RefCounted *self, void **out)
{
    if (self-> ... ) { ... }
}
```

Use the original bytes at `0x53ef90` and the GUID at `0x55cb68`. Candidate
entry is yours to choose; report the exact mangled name. Length: 51.
Flags: `/O2 /TP`.

## Task 3: base-vtable and CS cleanup (7 + 8 bytes)

Directory: `gemma-cleanup/`.

### `0x53efd0` SetBaseVTable (7 bytes)

```asm
mov [ecx],0x55c840
ret
```

This is a `__fastcall` helper with `self` in ECX and no stack args:

```cpp
extern "C" void __fastcall SoundBuffer_SetBaseVTable(void *self)
{
    *(void **)self = (void *)0x55c840;
}
```

Candidate entry: `@SoundBuffer_SetBaseVTable@4`. Length: 7. Flags: `/O2 /TP`.

### `0x53fd90` CS_Delete (8 bytes)

```asm
push ecx
call [0x55c1c0]
ret
```

This is a `__fastcall` helper that forwards `self` to
`DeleteCriticalSection`:

```cpp
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void *);
extern "C" void __fastcall CS_Delete(void *self)
{
    DeleteCriticalSection(self);
}
```

Candidate entry: `@CS_Delete@4`. Length: 8. Flags: `/O2 /TP`.

## Report

Write `report.md` in your directory:

```text
target(s):
source:
entry:
length:
strict: yes/no
candidate_length:
difference_count:
first_difference:
strict_issues:
```
