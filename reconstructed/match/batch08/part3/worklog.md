# batch08 part3 worklog

Batch 8 part 3 (`reconstructed/match/batch08/part3.json`, 25 functions).
Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (CL 12.00.8168 front end,
C2.DLL 12.00.8447), matcher `tools/match_decomp.py`, flags `/O2 /TP`.

**Result: 23 of 25 functions report `"strict_match": true`.** Run
`sh reconstructed/match/batch08/part3/verify_strict.sh` to re-check every
match; each check passes the manifest length and the exact entry symbol and
uses `--strict --auto-symbols`. The two failed final candidates are under
`part3/nonmatching/`.

## Matches

| address | name | form / notes |
|---|---|---|
| 0x47ec30 | IDMap_FreeValuesAndReset | `__stdcall`, member `IDMap::Lookup`, `List_Node::Reset`, `Mem_Free` |
| 0x4bd490 | UI_SelectNextObjectOfType | cdecl; one game-pointer load inside the selection branch |
| 0x4cb7a0 | FreePlaySetup_FillStartCapitalText | 32-byte buffer, `String_Format`, member text notify |
| 0x4da650 | Game_CollectAllOwnedObjects | `__stdcall`; `i = 0` must follow the reset call |
| 0x50e7d0 | Person_ResumeRouteOrDetach | thiscall; visibility test returns `int` (`test eax,eax`) |
| 0x527380 | UI_RefreshChildRect | reloads the child pointer after `GetRect` (otherwise an extra `push edi`) |
| 0x527a10 | UI_RefreshChildSprite | thiscall, three arguments, element/sprite reloads |
| 0x535570 | Text_SetMetrics2 | thiscall, store order a,a,a,b,b,b,c |
| 0x53a020 | Window_SetRectAndUpdateChildren | 16-bit width/height fields, `SetRect` through `DAT_0055c280` |
| 0x481010 | Branch_SetName | `#pragma intrinsic(strcpy)` gives the inline `repnz scas`/`rep movs` copy |
| 0x482b30 | UI_ShowAIStatusWindow | uninitialized `int id` filled by `AI_DebugStatusWindow_Create` |
| 0x49d150 | Game_GetNthFreePlayerSlot | `for` loop needed for the bottom `cmp esi,6; jl` |
| 0x4e1b80 | Game_ResetRecordTurnCounters | count guard, count reloaded each iteration |
| 0x4f1280 | Array_GetRandomRecord28B | base is an `int *` filled by `Object_GetBufferPair`; `*base + i*0x28` |
| 0x4fc0b0 | IDMap_FreeValuesAndDestroy | unconditional `Mem_Free`, vtable `Destroy(1)` call |
| 0x509130 | UI_SetChildScale | address-taken parameter forces `fldl/fstpl [esp+4]` and the two memory pushes |
| 0x50ab30 | Object_Activate | direct `*(byte*)(child+0x10) |= 1` keeps `or byte [esi+0x10],1` |
| 0x5105c0 | Object_DeleteAllInMap | declare `i` before `count` to get `ebp=this`, `ebx=count` |
| 0x526f20 | DebugConsole_Errorf | 2048-byte buffer, `&format + 1` varargs pointer |
| 0x54a770 | Window_SetVisible | `ShowWindow` through `DAT_0055c1ec` |
| 0x54a880 | UI_BriefingList_Construct | raw offsets, literal vtable `0x55cb40` |
| 0x402fe0 | FileObject_Destroy | literal vtable, three guarded `Mem_Free` calls |
| 0x48bae0 | Game_ShowFindPersonPrompt | explicit 16-iteration zero loop gives `rep stos` with `ecx=0x10` |

## Nonmatching

| address | name | first diff | cause |
|---|---|---|---|
| 0x54e940 | _strncmp | offset 0: original `0x55` (`push ebp`), candidate `0x56` (`push esi`) | The original is the hand-written CRT assembly `strncmp` (`repnz scas`/`repz cmps`, full EBP frame). The genuine C CRT body compiles to a normal loop; 56 of 56 bytes differ. |
| 0x541880 | Parser_ResetTokenState | offset 0x1d: original `0x4e` (`mov ecx,[esi+4]`), candidate `0x46` (`mov eax,[esi+4]`) | Only register width/naming differs: the original finishes the flag update with `or ecx,2`, VC6 emits `or al,2` for every equivalent C spelling tested (`|=`, local, pointer, volatile, `switch`, free `__fastcall`). 24 differing bytes. |

## Reproduce

```sh
sh reconstructed/match/batch08/part3/verify_strict.sh
```
