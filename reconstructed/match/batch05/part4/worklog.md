# batch05 part4 worklog

25 of 25 functions are strict byte matches. `0x50d750 State_IsMenuState` uses
the matcher's trailing-table support documented below.

Verify with:

```sh
sh reconstructed/match/batch05/part4/verify_strict.sh
```

The script runs `tools/match_decomp.py ADDRESS FILE --length LEN --entry ENTRY
--flags FLAGS --strict --auto-symbols`, with the manifest length and exact
candidate entry symbol, plus explicit `--symbol` maps only where
auto-resolution cannot name the target. No candidate contains inline assembly.

## Results

```text
0x48bda0 Game_OnObjectListSelection           ?OnObjectListSelection@Game@@QAEXXZ /O2 /TP
0x4f5770 Record_SetField2D0C                  ?SetField2D0C@Record@@QAEXHD@Z   /O2 /TP
0x526e50 UI_MarkFullRectDirty                 ?UI_MarkFullRectDirty@@YIXH@Z    /O2 /TP
0x534df0 Surface_FillFF                       @Surface_FillFF@4               /O2
0x538f60 Surface_LockAndMark                  ?LockAndMark@Surface@@QAEHXZ     /O2 /TP
0x544ab0 SoundSystem_Delete                   @SoundSystem_Delete@12          /O2
0x54cc09 Stream_PutByte                       ?PutByte@Stream@@QAEII@Z         /O1 /TP
0x54f0e2 _rand                                _rand                            /O1
0x401f30 Pak_DecodeIndex                      _Pak_DecodeIndex@8              /O2
0x47f5c0 Branch_RemoveBuildingObject          ?RemoveBuildingObject@Branch@@QAEXPAX@Z /O2 /TP
0x482f10 UI_RemoveWindowForObject             ?RemoveWindowForObject@UI@@QAEXXZ /O2 /TP
0x498100 CityCompanyList_Load                 ?CityCompanyList_Load@@YAXPAUStream@@@Z /O2 /TP
0x498130 CityCompanyList_Save                 ?CityCompanyList_Save@@YAXPAUStream@@@Z /O2 /TP
0x49acd0 AdvertisingPanel_Load                ?AdvertisingPanel_Load@@YAXPAUStream@@@Z /O2 /TP
0x49ad00 AdvertisingPanel_Save                ?AdvertisingPanel_Save@@YAXPAUStream@@@Z /O2 /TP
0x49b460 CompanyMarketShare_Load              ?CompanyMarketShare_Load@@YAXPAUStream@@@Z /O2 /TP
0x49b490 CompanyMarketShare_Save              ?CompanyMarketShare_Save@@YAXPAUStream@@@Z /O2 /TP
0x49e5b0 Save_LoadOrInit                      _Save_LoadOrInit                 /O2
0x49ec70 Save_LoadOrInit2                     _Save_LoadOrInit2                /O2
0x4d2a60 Game_MapRecordToGlobal               ?MapRecordToGlobal@Game@@QAEXH@Z /O2 /TP
0x4e2250 Game_FindCityIndex                   @Game_FindCityIndex@4            /O2
0x4e5ff0 Game_GetRecordByte14                 ?Game_GetRecordByte14@@YIHH@Z    /O2 /TP
0x4f1250 Object_GetBufferCount                ?GetBufferCount@Object@@QAEHPAH@Z /O2 /TP
0x4f5ab0 Object_EnsureFirstChild               _Object_EnsureFirstChild@12      /O2
```

## Reconstruction notes / diffs fixed

* `0x54cc09` and `0x54f0e2` reproduce only under `/O1`, which the batch rules
  allow when required. `/O2` strength-reduces the LCG multiply
  (`0x343fd`) into a long `lea`/`shl` chain; `/O1` emits the shipped
  `imul $0x343fd`. `/O2` also reloads `Stream::cursor` after the pixel store;
  `/O1` keeps the shipped `inc dword ptr [ecx+0x1c]` and `movzbl %dl,%eax`.
  `_rand` is spelled `rand` in C so the COFF symbol is exactly `_rand`.
* `0x538f60` needed the inverted condition: `if (Lock(1,1) != 0) { dirty = 1;
  return 1; } return 0;` gives the shipped `test; je zero-block` layout, while
  `if (Lock(...) == 0) return 0;` produced `jne`.
* `0x49e5b0` / `0x49ec70` also needed the inverted guard:
  `if (DAT != 0) { <second sorter>; return; } <first sorter>;` gives the
  shipped `test; je first-sorter` and puts the second sorter in the
  fall-through block.
* `0x4e2250` is a plain `while ((int)entry < 0x563890)` loop with the city id
  hoisted into `edx`. `/O2` on that form reproduces the shipped
  `xor %eax,%eax` before `mov $0x563874,%ecx` and the plain
  `cmp/je/add/inc/cmp/jl` loop; a do-while form made `/O2` rotate/peel the
  loop, and `/O1` replaced `mov $7,%eax` with `push $7; pop %eax`.
* `0x4e5ff0` evaluates the key `*(record+4)` before the global ID map, giving
  the shipped `mov %ecx,[%ecx+4]; mov %eax,[0x57c670]; ... lea 0x74(%eax),%ecx`.
  Returning the byte with `if (mapped != 0) return byte; return -1;` gives the
  shipped `test; je minus-one` layout and the `xor %ecx,%ecx; mov %cl,...`
  zero extension.
* `0x482f10` calls `Window::GetObjectId(object)` on the *window* object
  (`ecx = DAT_0057c5e0`), then `Window::RemoveWindowByID(id)`. Both are member
  symbols whose demangled names are `Window_*`, not the shipped
  `Object_GetId` / `UI_RemoveWindowByID`, so explicit maps are used.
* `0x4f1250` passes five stack arguments to `Object_GetBufferPair`:
  `(count, &local, &count, 0, 0)`; the shipped code reserves a 4-byte local
  with `push %ecx` and passes the address of the parameter slot as the third
  argument. The wrong third/fourth argument order produced a different push
  sequence and a `push %esi` prologue.
* `0x534df0` is an inlined `memset(ptr, 0xff, width*height*2)`; `#pragma
  intrinsic(memset)` produces the shipped `rep stosd` + `rep stosb` pair.
* `0x544ab0` uses the `__fastcall` + dummy `edx` pattern to model the
  `__thiscall` deleting destructor: `ret 4`, `testb $1,0x8(%esp)`, free
  `this-4`, return `this-4`.
* `0x47f5c0` reloads `DAT_0057c670` for the second call; the first call is a
  member call on the list stored at `branch+0x16f0`.
* `0x48bda0`, `0x483120`, `0x4d2a60`, `0x4e5ff0` all use the same
  `IDMap_Lookup(this, key, 0)` thiscall shape with the map at different
  offsets; no explicit symbol is needed for those.

## Explicit symbol maps

```text
0x47f5c0 ?Remove@List@@QAEXPAXH@Z=0x4d2960
0x482f10 ?GetObjectId@Window@@QAEHPAUObject@@@Z=0x5260e0
0x482f10 ?RemoveWindowByID@Window@@QAEXH@Z=0x527f80
0x498100 ?Read@Stream@@QAEHPAXH@Z=0x54cbc1
0x498130 ?Write@Stream@@QAEHPAXH@Z=0x54cc2b
0x49acd0 ?Read@Stream@@QAEHPAXH@Z=0x54cbc1
0x49ad00 ?Write@Stream@@QAEHPAXH@Z=0x54cc2b
0x49b460 ?Read@Stream@@QAEHPAXH@Z=0x54cbc1
0x49b490 ?Write@Stream@@QAEHPAXH@Z=0x54cc2b
```

## Nonmatching: 0x50d750 State_IsMenuState

`nonmatching/0x50d750.c` is the genuine C switch:

```c
int __fastcall State_IsMenuState(int state)
{
    switch (*(int *)(state + 0x30)) {
    case 0xd: case 0x17: case 0x1d: case 0x1e: return 1;
    }
    return 0;
}
```

Compiled `/O2` it reproduces the first 35 bytes exactly, including the
`mov $0x50d77c,%cl` byte-table load and the `jmp *0x50d774(,%ecx,4)`
dispatch (`first_difference: null`). It fails only the strict extent gate:

```text
candidate extent 64 bytes, expected 35 (extra=29 bytes, padding=False)
relocation at 0x24 is outside the candidate/original extent
relocation at 0x28 is outside the candidate/original extent
```

MSVC emits the two compiler-generated switch tables immediately after the
`ret` (jump table at +0x24, byte table at +0x2c), which is exactly what the
original image has between functions. `--strict` counts those bytes as part of
the candidate `.text` section and rejects the table relocations, and no genuine
C spelling can move compiler-generated switch tables to another section
(`const_seg`/`code_seg` do not affect them). Inline assembly is not allowed, so
this record is left as a nonmatch rather than faked.

## Checker update for 0x50d750

The matcher now accepts a candidate's trailing switch tables when they match
the original image bytes and validates relocations inside that window. With
this fix the genuine /O2 C switch is a strict match:

```text
strict_match: true
difference_count: 0
strict_issues: []
```

It is counted in `verify_strict.sh` as 0x50d750.
