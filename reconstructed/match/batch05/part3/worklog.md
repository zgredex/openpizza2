# batch05 part3 worklog

25 of 25 functions are strict byte matches. Nothing is kept under
`nonmatching/`.

Verify with:

```sh
sh reconstructed/match/batch05/part3/verify_strict.sh
```

The script runs `tools/match_decomp.py ADDRESS FILE --length LEN --entry ENTRY
--flags FLAGS --strict --auto-symbols`, with the manifest length and the exact
candidate entry symbol, and adds explicit `--symbol` maps only where
auto-resolution cannot name the target (stdcall/import/member names whose
decorated form does not demangle to the shipped symbol). No candidate contains
inline assembly.

## Results

```text
0x531980 UI_GetButtonSprite                   _UI_GetButtonSprite@4            /O2
0x53d460 Sprite_GetPixelData                  ?GetPixelData@Sprite@@QAEHPAH@Z  /O2 /TP
0x4052a0 Screen_CloseSubStartMenu             ?Screen_CloseSubStartMenu@@YAXXZ  /O2 /TP
0x47f210 Branch_UpdateActiveConstruction      ?UpdateActiveConstruction@Branch@@QAEXXZ /O2 /TP
0x480880 City_IsIdle                          @City_IsIdle@4                   /O2
0x4d35e0 Car_PickRandomRoadStep               ?PickRandomRoadStep@Car@@QAEXXZ  /O2 /TP
0x4f34f0 UI_GetRecordCenteredRect             ?GetRecordCenteredRect@UI@@QAEXHPAH0@Z /O2 /TP
0x539e00 List_PushFront                       ?PushFront@List@@QAEXPAX@Z       /O2 /TP
0x54a5f0 DebugConsole_Construct               ?Construct@DebugConsole@@QAEPAU1@H@Z /O2 /TP
0x54a7b0 Window_ToggleVisibility              ?ToggleVisibility@Window@@QAEXXZ /O2 /TP
0x54a7d0 Dialog_SetItemText                   @Dialog_SetItemText@4           /O2
0x401f60 ResourceIterator_Init                ?Init@ResourceIterator@@QAEXPAD@Z /O2 /TP
0x4830e0 Game_DestroyEventWindow              ?DestroyEventWindow@Game@@QAEXXZ /O2 /TP
0x488db0 Game_ShowBranchInteriorDefaultZoom   ?ShowBranchInteriorDefaultZoom@Game@@QAEXPAX@Z /O2 /TP
0x4db2e0 String_SkipDelimiters                _String_SkipDelimiters           /O2
0x4e0f10 Game_IsRecordLinked                  ?IsRecordLinked@Game@@QAE_NH@Z   /O2 /TP
0x4eac00 Game_GetRecordChild14                ?GetRecordChild14@Game@@QAEHH@Z  /O2 /TP
0x50e200 Object_CountMatchingSlots            ?CountMatchingSlots@Object@@QAEHH@Z /O2 /TP
0x50e810 Object_GetClampedLevel               @Object_GetClampedLevel@4        /O2
0x53d690 Sprite_BlitOwnedRLE                  ?BlitOwnedRLE@Sprite@@QAEXPAXHH@Z /O2 /TP
0x5445f0 Sound_RewindBuffer                   ?RewindBuffer@Sound@@QAEII@Z     /O2 /TP
0x47fd20 Branch_ClearConstructionSites        ?ClearConstructionSites@Branch@@QAEXXZ /O2 /TP
0x482590 Game_AddScreenTimer                  ?AddScreenTimer@Game@@QAEXXZ     /O2 /TP
0x483120 UI_SyncSelectedChild                 ?SyncSelectedChild@UI@@QAEXXZ     /O2 /TP
0x489040 Map_GetTileByte                      ?GetTileByte@Map@@QAEDHH@Z       /O2 /TP
```

## Reconstruction notes / diffs fixed

* `0x531980` is a one-argument `__stdcall` helper, not a method: it loads the
  handle from `[esp+4]`, pushes five arguments and uses `ret 4`. The callee
  `Window_GadgetNotify` is stdcall (`_Window_GadgetNotify@20`), so it needs an
  explicit symbol map.
* `0x53d460` needed the correct member layout: byte flag at `+0x39`
  (`pad3[9]`, not 13). With the wrong pad the first diff was offset 5
  (`0x39` vs `0x3d`).
* `0x54a5f0` returns `this`. Declaring the constructor `void` made MSVC keep
  `this` in `ecx`; returning `DebugConsole *` moves it to `eax` and zeroes
  `ecx`, producing the shipped `mov %ecx,%eax` / `xor %ecx,%ecx` sequence.
* `0x4e0f10` is a `Game` member whose `this` stays live for the nested
  `HasRecordField14DC` thiscall. That keeps `ecx` occupied and makes the
  compiler test the byte in `dl`; a free function used `cl`. Returning
  `bool` through a local gives the shipped `test %al,%al; setne %al`
  normalization instead of the `neg/sbb/neg` idiom.
  Explicit symbol `?HasRecordField14DC@Game@@QAEDH@Z=0x4e0f40`.
* `0x47f210` passes an *uninitialized* 4-byte local by address; the shipped
  code only reserves the slot (`push %ecx`) without storing `this`.
* `0x539e00` calls `operator new(8)` (`??2@YAPAXI@Z`, explicit map).
* `0x5445f0` is a COM-style call through `buffer->vtbl->Method(buffer, pos)`:
  the vtbl pointer is loaded into `ecx` while the object is the first stack
  argument, and the return is normalized with `((r >= 0) - 1) & 0x80004005`.
* `0x482590` passes the literal callback `0x481190` and stores the returned
  timer id at `+0x2d8c`.
* `0x489040` returns `char` (not `int`): the shipped code only writes `%al`.

## Explicit symbol maps

```text
0x531980 _Window_GadgetNotify@20=0x52fdd0
0x47f210 ?GetBestObject@Branch@@QAEXHHPAM@Z=0x47f2e0
0x539e00 ??2@YAPAXI@Z=0x54e221
0x54a7b0 __imp_?IsWindowVisible@@YGHPAX@Z=0x55c200
0x54a7d0 __imp__GetDlgItem@8=0x55c1f0
0x54a7d0 __imp__SetWindowTextA@8=0x55c1d0
0x488db0 ?SetVolumePreset@Game@@QAEXH@Z=0x485a80
0x4e0f10 ?HasRecordField14DC@Game@@QAEDH@Z=0x4e0f40
0x47fd20 ?ConsumeObject@Branch@@QAEXH@Z=0x47eab0
```

Everything else (member calls such as `Sprite::RealizeLazy`,
`Game::ShowBranchScene`, `Timer::AddEntry`, `IDMap::Lookup`, and the globals)
resolves through `--auto-symbols`.
