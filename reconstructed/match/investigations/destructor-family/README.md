# VC6 destructor family generator

`tools/generate_destructor_family.py` emits and strict-verifies C++
destructors from a small JSON spec. It supplies the shared COM-style base
class, inserts explicit field padding, emits each destructor body, resolves
the original vtable/method addresses, compiles with the pinned VC6 toolchain,
and writes a `family.json` for `tools/run_family_batch.py`.

## Result

```text
sound-destructors: 3/3 strict, 316/316 bytes
  0x53f020   91  SoundBuffer    (vtable 0x55c830, deleting 0x53f000)
  0x53f5d0  126  SoundSample    (vtable 0x55c850, deleting 0x53f5b0)
  0x546750   99  SoundBuffer2   (vtable 0x55cb14, deleting 0x546730)
```

Both candidates reproduce the primary body, `.text$x`, `.xdata$x`, the
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
# 2/2 strict

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

## Experimental members

`experimental.json` holds the next class:

```text
0x541f30 SoundTrack      138 bytes  diff 29
```

`SoundTrack` has two unwind states. State 1's cleanup at `0x541f00` frees
`[ebp-8]`, a local cleanup object; the candidate only models the base vtable
state. It needs a `locals`/`states` extension to the generator, not just a
body change.

## Next destructor targets

```text
0x5408b0 SoundBuffer_DestructDerived   169 bytes  vtable 0x55c874
0x541790 SoundStreamBuffer_Destruct    225 bytes  vtables 0x55c8b0/0x55c8c8/0x55c874
0x53fcc0 SoundPakManager_Destruct      207 bytes  vtable 0x55c864
0x546750 SoundBuffer_Destructor         99 bytes  experimental above
0x541f30 SoundTrack_Destruct           138 bytes  experimental above
```

The generator should be extended with a `states` field for extra unwind
cleanup actions and a `switch`/`if` body form, then the remaining members can
be emitted from the same spec.
