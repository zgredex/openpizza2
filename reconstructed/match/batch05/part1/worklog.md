# batch05 part1 worklog

Part 1 of batch 5 (`reconstructed/match/batch05/part1.json`, 25 functions).
Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (CL 12.00.8168 front end,
C2.DLL 12.00.8447), matcher `tools/match_decomp.py`.

**Result: 25 of 25 functions report `"strict_match": true`.** Run
`sh reconstructed/match/batch05/part1/verify_strict.sh` to re-check every
match; it passes each manifest length and the exact entry symbol and uses
`--strict --auto-symbols`. There are no failed final candidates, so
`part1/nonmatching/` is empty.

## Matches

| address | name | form / flags |
|---|---|---|
| 0x501b50 | Player_AIState_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x50bf30 | Game_GetPlayerEconomyModifier | C++ member, global game lookup, `/O2 /TP` |
| 0x50d200 | Object_SetFrame5 | C++ member, `-1` special case, `/O2 /TP` |
| 0x50e9c0 | Player_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x50fdd0 | Recipe_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x513d30 | Storage_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x51f210 | UI_ImageElement_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x520af0 | UI_Child_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x521160 | UI_Viewport_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x5221c0 | UI_LabelElement_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x522ed0 | Array_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x523590 | UI_Manager_ScalarDeletingDestructor | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x5286e0 | UI_ContextMenu_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x529140 | UI_Slider_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x52b210 | MovieWindow_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x52bd50 | UI_TextElement_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x52d690 | UI_ButtonElement_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x52e510 | UI_Tooltip_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x52e9b0 | Dialog_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x532c20 | Animation_ScalarDeletingDestructor | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x534db0 | Gfx_RectList_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x536140 | Window_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x537d60 | Renderer_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x539840 | Color_RGBTo16FromDword | C++ member, packed-dword colour split, `/O2 /TP` |
| 0x53c7d0 | Sprite_ScalarDeletingDestructor | scalar deleting destructor, C `__fastcall`, `/O2` |

## Notes

* The 22 scalar deleting destructors use the batch01 C pattern
  `void *__fastcall Delete(void *this, int dummy, unsigned char flags)`, which
  yields `push esi; mov esi,ecx; call dtor; test [esp+8],1; ...; ret 4` and an
  `@Name@12` entry. The destructor and `Mem_Free` calls are undefined symbols
  that `--auto-symbols` resolves by name.
* `0x50bf30` needs `int slot = activePlayer;` before the
  `DAT_0057c670->GetPlayerBySlot(slot)` call. Passing `activePlayer` directly
  makes VC6 push the two `Economy::GetModifier` arguments before calling
  `GetPlayerBySlot`; the local forces the original order (call first, then
  `push 0; push 0x1e; mov ecx,eax`).
* `0x539840` only matches when the callee is declared with 32-bit parameters
  (`unsigned int` instead of `unsigned char`). The original caller zero-extends
  each component with `xor eax,eax; mov al,...` / `xor edx,edx; mov dl,ah` /
  `and eax,0xff`, which VC6 emits only when the formal parameter is 32-bit.
  The callee is reached through `ecx` unchanged, exactly like the member call
  in the original. Naming the struct `Color` and the member `RGBTo16` makes the
  mangled callee demangle to `Color_RGBTo16` for `--auto-symbols`.
* All matched sources are genuine C/C++; no inline assembly and no
  `__declspec(naked)`.

## Reproduce

```sh
sh reconstructed/match/batch05/part1/verify_strict.sh
```
