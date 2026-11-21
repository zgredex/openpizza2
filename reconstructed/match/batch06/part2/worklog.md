# batch06 part2 worklog

Batch 6 part 2 (`reconstructed/match/batch06/part2.json`, 25 functions).
Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (CL 12.00.8168 front end,
C2.DLL 12.00.8447), matcher `tools/match_decomp.py`, manifest lengths and exact
entry symbols, `--strict --auto-symbols`.

**Result: 24 of 25 functions report `"strict_match": true`.**
`sh reconstructed/match/batch06/part2/verify_strict.sh` re-checks every C match
and prints `strict 24/24 C matches, failed 0`.

`0x54efd0` `_strrchr` is a known non-match (details below); its reference
source is in `part2/nonmatching/0x54efd0.c`.

Most records use `/O2 /TP`; `0x4ed570` needs C mode `/O2` (no `/TP`).

## Matches

| address | name | length | form / flags |
|---|---|---|---|
| 0x54bcc0 | MapBadgeAnim_SetWindow | 38 | member, stores +0x1a8, window object at +4, `/O2 /TP` |
| 0x47a820 | Game_SumStatRow8 | 39 | member, 8-dword row sum with row/-1 match, `/O2 /TP` |
| 0x47ec00 | Game_RemoveTrackedRecord | 39 | member, key local, `FindRecordByField10` + `RemoveByKey`, `/O2 /TP` |
| 0x4858a0 | Game_SetLockedField2FC | 39 | member, `lock->Enter/Leave` while re-reading +0x240, `/O2 /TP` |
| 0x4d29d0 | Game_RemoveRecordFromLocalMap | 39 | member, `RemoveByKey` result kept, `Set_Field168(record,0)`, `/O2 /TP` |
| 0x4d3530 | Record_GetFlag3E48 | 39 | member returning `int`, bounds-checked byte at +0x3e, `/O2 /TP` |
| 0x4eaa10 | Game_GetMapValue | 39 | member, -1/-2 sentinels, negative index clamp, `/O2 /TP` |
| 0x4ed010 | Map_ComputeIsoOffsets | 39 | member, width*2 stores then height*2/*3, `/O2 /TP` |
| 0x4ed570 | Distance_Manhattan3 | 39 | `__stdcall` free function, `abs` intrinsic, `/O2` (C) |
| 0x4f6b50 | Game_CompleteMissionStage | 39 | free function, `DAT ? 5 : 3`, queued child command, `/O2 /TP` |
| 0x501a40 | Player_Event_Save | 39 | member, `CRT_Ostream::Write` of +4/+8, `/O2 /TP` |
| 0x501a70 | Player_Event_Load | 39 | member, `CRT_Istream::Read` of +4/+8, `/O2 /TP` |
| 0x502cb0 | Game_PickRandomTableValue | 39 | member, `Random_RangeFast(0,1)` + `DAT_005728dc`, `/O2 /TP` |
| 0x508040 | UI_ResetChildRecord | 39 | `__fastcall`, two +0xc8 loads, `if (x == 0)` layout, `/O2 /TP` |
| 0x50be60 | Thug_StartRestaurantRampage | 39 | member, destination/target then locked field, `/O2 /TP` |
| 0x514660 | Language_IndexOfString | 39 | free function, global count/array, returns 0 not -1, `/O2 /TP` |
| 0x523900 | UI_ReplaceActiveObject | 39 | member, `Movie_ReleasePlayer` + store + dirty rect, `/O2 /TP` |
| 0x528160 | UI_ResetScrollPosition | 39 | member, embedded `CS` lock at +0x1cc, `/O2 /TP` |
| 0x52cb70 | Text_SkipFieldSeparators | 39 | `__stdcall`, separator scan (`ret 8`), `/O2 /TP` |
| 0x5313d0 | Array_GetRecordByKey | 39 | `__fastcall` free function, `BinarySearch8` + dummy, `/O2 /TP` |
| 0x534960 | Record_GetValue48 | 39 | member, 0x48-stride entry array, short at +0x32, `/O2 /TP` |
| 0x535690 | UI_GetFirstEnabledIndex | 39 | member, `for` over 0xe0 flags, byte index array, `/O2 /TP` |
| 0x5396b0 | Surface_GetCursorRect | 39 | member, four out-params in +4/+c/+8/+10 order, `/O2 /TP` |
| 0x54a630 | DebugConsole_Destructor | 39 | member, vtable 0x55cb3c, imported `DestroyWindow`/`FreeLibrary`, `/O2 /TP` |

## Known non-match

* `0x54efd0` `_strrchr` (39 bytes). The shipped body is the Visual Studio 1998
  CRT assembly leaf: `push ebp; mov ebp,esp; push edi`, forward `repnz scas`
  for the length, then `std` + backwards `repnz scas`, `cld`, `leave`, `ret`.
  No C/C++ source can make the MSVC 6 compiler set the direction flag, so the
  strict matcher can never pass. The closest genuine C reconstruction of the
  CRT source is in `nonmatching/0x54efd0.c`; its first difference is offset 0
  (`0x55 push ebp` original vs `0x8b mov` candidate) with 38 differing bytes.

## Implementation notes

* `0x4ed570` is compiled as C (`/O2`, no `/TP`). `abs` is only expanded to the
  original `cdq; xor edx,eax; sub edx,eax` sequence when C mode applies
  `#pragma intrinsic(abs)`; the C++ front end leaves a mangled `?abs@@YAHH@Z`
  call. The original ends in `ret 0x10`, so the function is `__stdcall`
  (`_Distance_Manhattan3@16`).
* `0x508040`: the original tests the child pointer twice. Two separate local
  loads from `ui + 0xc8` plus `if (x == 0) { zero path } else { load }` keeps
  both tests and the original `jne`-to-then/`je`-to-then polarity. A single
  `if (sub) { ... }` merges both paths into 32 bytes.
* `0x47ec00`: the key must be stored in a local before the member call. The
  expression form loads the key into `ecx` and then has to restore `ecx` with
  `mov esi,ecx`; the local form keeps the key in `eax` and `ecx` untouched.
* `0x4ed010`: `height` must be declared after the two `width` stores, otherwise
  VC6 hoists `mov 0x10(ecx),edx` above the `shl`.
* `0x4d3530` / `0x535690`: the return type is `int` (zero-extended byte), not
  `unsigned char`. A `char` return emits `xor al,al` / `mov ...,%al` instead of
  the original `xor edx,edx; mov dl; mov edx,eax`.
* `0x4d29d0`: the cleanup callee is `Set_Field168`, modelled as `Set::Field168`
  so the mangled name demangles to the shipped symbol (`Record::Field168`
  would demangle to `Record_Field168` and stay unresolved).
* `0x52cb70`: two stack arguments and `ret 8` mean `__stdcall`; the plain C
  function emitted a bare `ret` and failed only at offset 36.
* `0x535690`: a `for` loop reproduces the original un-peeled `do/while` shape;
  an explicit `do { ... } while` was peeled (duplicated compare).
* `0x54a630` calls the imported `DestroyWindow` and `FreeLibrary` through the
  IAT slots 0x55c1f8 / 0x55c068, declared as `DAT_0055c1f8` /
  `DAT_0055c068` function-pointer globals; the vtable store is the literal
  0x55cb3c (no relocation in the original).
* `0x4f6b50` is `DAT_0057bb20 ? 5 : 3`, which VC6 renders as
  `neg al; sbb eax,eax; and 2; add 3`; the mask form from the pseudocode
  produces `setne` instead.
* `Class_Method` callees are modelled as C++ member functions so their mangled
  names demangle to the shipped symbols (`CRT_Ostream::Write`,
  `CRT_Istream::Read`, `UI::QueueChildCommand`, `Movie::ReleasePlayer`,
  `Object::SetDestinationAndTarget`, `Record::ClearActive48`, and so on).
