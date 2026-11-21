# batch10 part4 worklog

25 manifest records, reconstructed as genuine C/C++ with MSVC 6.0 SP3
(`/tmp/opencode/vc6-sp3-toolchain/VC98`). Every accepted file reports
`"strict_match": true` from `tools/match_decomp.py` with the manifest length,
exact entry symbol, `--strict --auto-symbols`, and explicit `--symbol` entries
only where the auto resolver cannot reach the original target (C++ member
callees that do not undecorate to the game symbol name, and dllimport IAT
slots).

## Result

```text
strict matches: 23 / 25
```

Matched: 0x52f080, 0x52f9d0, 0x5314a0, 0x531910, 0x5324c0, 0x5328e0,
0x533560, 0x534320, 0x534830, 0x538780, 0x539550, 0x539660, 0x539e20,
0x53a220, 0x53d600, 0x540a30, 0x5411c0, 0x5433e0, 0x5445a0, 0x548300,
0x549170, 0x54c830, 0x54d372.

Flags: `/O2 /TP` for every file except `0x54d372`, which needs `/O2 /Os /TP`
(`/Os` is what emits `cmp dword [esi+8], 0` instead of `mov`/`test`).

Explicit symbols:

- `0x5314a0`: `?BinarySearch8@Array@@QAEHHH@Z=0x531330` (the callee is
  `BinarySearch8`, but the mangled member name does not undecorate to it).
- `0x5433e0`: `__imp__EnterCriticalSection@4=0x55c1b8` and
  `__imp__LeaveCriticalSection@4=0x55c1a0` (dllimport IAT slots).

## Notes on shapes that were not obvious from the pseudocode

- `0x531910 UI_SetButtonSpriteByName` returns `int`: both paths leave a value
  in eax (0 from the failed load, the notify result otherwise). Declaring it
  `void` makes VC6 tail-merge the two epilogues and loses 6 bytes.
- `0x534320 Record_SetRect48` and `0x534830 Record_GetPairPositions` copy an
  8-byte `Pair { int; int; }`. The original stores/loads both dwords through
  two registers (`esi`/`edi`), which only appears with an aggregate copy
  (`record->pair = tmp;` / `*second = *(Pair *)...;`), not with two scalar
  member assignments.
- `0x534320` also checks `items[index].id` first and then takes
  `&items[index]`; that ordering is what produces the original's
  `mov edx,[ecx+0x4c]; lea eax,[eax+eax*8]` entry-pointer setup.
- `0x538780 Renderer_ToggleRenderTarget` calls
  `Surface_InitPixelFormat(&local, 1)` (format pointer first, mode second); the
  opposite argument order pushes the constant in the merged tail block.
- `0x539550 Surface_ClearRows` is a `memset(row, 0, width * 2)` loop; VC6
  inlines the zero fill as `rep stosd` + `rep stosb`. The guard is only
  `if (bits == 0)`, the `height == 0` exit comes from the loop rotation.
- `0x53a220 Sprite_InitFormat`: parameter 2 is an `int` truncated on store
  (`mov edx,[esp+8]`, not `mov dx`).
- `0x5411c0 SoundBuffer_SetVolume` must test the HRESULT with the success path
  first (`if (result >= 0) { ...; return 0; } return 0x80070057;`); the
  negative-first spelling puts the failure epilogue inline.
- `0x5445a0 SoundBuffer_StopPlayback` matches the game's
  `((hr >= 0) - 1) & 0x80004005` return idiom.

## Non-matching (kept under `nonmatching/`)

- `0x542b00 List_Remove`: the reconstructed C is semantically exact but VC6
  schedules the parameter load first (`mov eax,[esp+4]`) where the original
  starts with `mov edx,[ecx+8]`. The original also keeps `node` in eax across
  the whole body, keeps one `esi` scratch alive from the `node->prev` test to
  the final `ret` (push/pop at 0x542b14/0x542b41), and decrements the count via
  `mov edx,[ecx+0xc]; pop esi; dec edx; mov [ecx+0xc],edx`; all tested source
  forms (`count--`, `count = count - 1`, count through a pointer, local
  `next`/`last` copies, inverted branches) produce a different schedule.
  First difference: offset 1, original `0x51`, candidate `0x44`;
  54 differing bytes, no strict extent/relocation issue.
- `0x54b110 MessageList_FindKeyByValue`: the prologue, loop body and found
  block match exactly (count cached in ebx, map in edi, original value copy in
  ebp used for the comparison, `&value` passed to `Lookup`, `*key = value`
  after the call), but the loop back edge differs: original emits
  `inc esi; cmp esi,ebx; jl loop`, while every reconstructed form emits
  `jge end; jmp loop` (do/while rotation) or moves the `value`/`map` hoists
  before the count guard. First difference: offset 12, original `0x22`,
  candidate `0x35`; 30 differing bytes plus the 7-byte tail extent.

## Verify

```sh
sh reconstructed/match/batch10/part4/verify_strict.sh
```

The script checks the 23 accepted files and prints the two known non-matching
records.
