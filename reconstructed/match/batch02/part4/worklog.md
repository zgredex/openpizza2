# batch02/part4 worklog

Part 4 of batch 2: the 25 smallest functions from `../part4.json`
(8-17 bytes). Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (`wine
CL.EXE`, C2.DLL 12.00.8447).

Verification (from the repository root):

```sh
bash reconstructed/match/batch02/part4/verify_c.sh
```

Result on the final tree: **25/25 genuine C/C++ candidates match**
(`tools/match_batch.py`, `/O2 /TP`, manifest lengths). No `__asm`/`asm {`
and no `--symbol` map is needed: every relocation is linker-resolved from the
original PE.

## Matched (25)

| address | name | bytes | entry | notes |
|---|---|---|---|---|
| 0x527aa0 | UI_ResetInputHelper | 11 | `@UI_ResetInputHelper@4` | tail `jmp` to Object_GetByte36Max7 (same fastcall shape) |
| 0x527ab0 | MapView_GetRotation | 17 | `@MapView_GetRotation@4` | `p ? p[9] : 0` gives the shipped `test/je/mov/ret/xor/ret` |
| 0x5281f0 | UI_SetEventCallback | 13 | `?SetEventCallback@UI_Manager@@QAEXH@Z` | thiscall store at +0x8308 |
| 0x52ff20 | Array_GetRecordByKeyPtr | 13 | `?GetRecordByKeyPtr@Array@@QAEXH@Z` | `push arg; call` (not a tail jump) |
| 0x532510 | UI_Group_DestroyMemberList | 8 | `?DestroyMemberList@UI_Group@@QAEXXZ` | `add ecx,4; jmp Array_Destroy` |
| 0x532bc0 | Atexit_RegisterAnimSwapCritSectDtor | 12 | `_Atexit_RegisterAnimSwapCritSectDtor` | `atexit(cb)`: push/call/pop ecx/ret |
| 0x532c00 | Atexit_RegisterAnimCritSectDtor | 12 | `_Atexit_RegisterAnimCritSectDtor` | same shape, callback 0x532c10 |
| 0x534dd0 | Gfx_RectList_Destroy | 17 | `@Gfx_RectList_Destroy@4` | buffer load scheduled before the vptr store |
| 0x535150 | Object_GetPair10 | 15 | `?GetPair10@ObjectPair@@QAEHPAH@Z` | stores +0x10 through `out`, returns +0x14 |
| 0x535500 | Set_Field9B8 | 13 | `?SetField9B8@FieldSet@@QAEXH@Z` | thiscall store at +0x9b8 |
| 0x535e10 | Palette_Free | 14 | `@Palette_Free@4` | conditional `Mem_Free(*palette)` |
| 0x537c30 | Object_GetChildField14 | 11 | `@Object_GetChildField14@4` | `jne` over a bare `ret`; null path leaves eax=0 |
| 0x538f90 | Surface_LockPrimary | 10 | `@Surface_LockPrimary@4` | two zero args; emitted `call`, not a tail jump |
| 0x539e90 | Object_ClearField54 | 8 | `@Object_ClearField54@4` | immediate zero store |
| 0x53a1b0 | Gfx_InitBlendTable | 10 | `_Gfx_InitBlendTable` | `mov ecx,offset table; jmp Gfx_BuildBlendTable` |
| 0x53a1c0 | Gfx_BlendTable_RegisterAtexit | 12 | `_Gfx_BlendTable_RegisterAtexit` | `atexit`, callback 0x53a1d0 |
| 0x53a1e0 | SpriteBase_Construct | 9 | `??0SpriteBase@@QAE@XZ` | constructor returns `this` (`mov eax,ecx`) |
| 0x53c6f0 | Sprite_CriticalSection_RegisterAtexit | 12 | `_Sprite_CriticalSection_RegisterAtexit` | `atexit`, callback 0x53c700 |
| 0x53d430 | Sprite_GetColorKey | 13 | `@Sprite_GetColorKey@4` | branch polarity: `(flags & 0x10) != 0 -> return 0` |
| 0x541f00 | Buffer_ReleaseField8 | 15 | `@Buffer_ReleaseField8@4` | conditional `Mem_Free(*(p+8))` |
| 0x544ae0 | List_UnlinkNode | 15 | `_List_UnlinkNode` | cdecl wrapper; `this` reloaded into ecx, node pushed |
| 0x545650 | Rect_Zero | 16 | `??0Rect@@QAE@XZ` | constructor returns `this`; `xor ecx,ecx` + four stores |
| 0x54b3c0 | Object_ClearField4 | 8 | `@Object_ClearField4@4` | immediate zero store |
| 0x54bcf0 | Window_ClearState | 12 | `@Window_ClearState@4` | one zero register, stores +0x1a8 then +4 |
| 0x54cf82 | Stream_GetAvailable | 16 | `@Stream_GetAvailable@4` | unsigned `pos < end` / `end - pos` |

## Findings

- 20 of 25 originals are `__thiscall`. VC6's C front end rejects
  `__thiscall` (C4234), so every candidate is compiled as C++ (`/O2 /TP`)
  and models the member (`struct` + member function). Plain C is used
  implicitly for the `extern "C"` free functions; no `/GX` is needed because
  none of these has an unwind frame.
- Free `__fastcall` functions in C++ are decorated `@name@4` (one stack
  dword), even with `extern "C"`; the verify script relies on the batch
  runner's automatic entry detection, so the entries above are informational.
- 0x53a1e0 and 0x545650 return `this` in `eax` and zero fields through
  `ecx`; they are C++ constructors. Writing them as plain `void` functions
  stores immediates and does not match.
- 0x534dd0 loads `buffer` from +0x14 *before* storing the vtable pointer;
  naming the `Mem_Free` argument as a local first reproduces that schedule.
- 0x53d430 is the only candidate that needed the inverted condition: the
  Ghidra polarity (`bit clear -> return key`) emits the mirrored layout.
  The failed first attempt is kept in `nonmatching/0x53d430.c`.
- Tail calls (`jmp`) appear for 0x527aa0, 0x532510 and 0x53a1b0; wrappers
  that pass stack arguments (0x52ff20, 0x538f90, 0x544ae0) keep `call`+`ret`
  in this compiler.

## Unmatched

None. The single failed polarity attempt for 0x53d430 is under
`nonmatching/` for evidence only.
