# batch05 part2 worklog

Part 2 of batch 5 (`reconstructed/match/batch05/part2.json`, 25 functions).
Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (CL 12.00.8168 front end,
C2.DLL 12.00.8447), matcher `tools/match_decomp.py`.

**Result: 25 of 25 functions report `"strict_match": true`.** Run
`sh reconstructed/match/batch05/part2/verify_strict.sh` to re-check every
match; it passes each manifest length and the exact entry symbol and uses
`--strict --auto-symbols`. There are no failed final candidates, so
`part2/nonmatching/` is empty.

## Matches

| address | name | form / flags |
|---|---|---|
| 0x53f000 | SoundBuffer_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x53f5b0 | SoundSample_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x53fca0 | SoundPakManager_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x540890 | SoundBuffer_DeleteObject | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x541730 | SoundBuffer_ScalarDeletingDestructor | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x541770 | SoundStreamBuffer_DeleteObject | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x541f10 | SoundTrack_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x5427c0 | SoundMixerThread_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x545b00 | List_ContainerDestroy | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x546730 | SoundBuffer_Delete2 | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x548d90 | Sound_PlayPoliceSfx | C++ member, guarded `Sound_PlayChannel`, `/O2 /TP` |
| 0x54a8c0 | UI_BriefingList_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x54b620 | EmployeeAvatar_Delete | scalar deleting destructor, C `__fastcall`, `/O2` |
| 0x54bf50 | Sound_SetListenerPosition | C++ member, `__ftol` of double to `__int64`, `/O2 /TP` |
| 0x54dc89 | Stream_GetStatus | C++ member, virtual call + status fold, `/O1 /TP` |
| 0x47fd50 | Game_IncrementVisitCounter | C++ member, total + per-slot counters, `/O2 /TP` |
| 0x485ac0 | Game_GetSpeedSetting | C++ member, two-condition return, `/O2 /TP` |
| 0x488bc0 | Game_FindPlayerSlot | C++ member, six-slot pointer search, `/O2 /TP` |
| 0x4e3dd0 | Player_InitSlotFlags | C++ member, byte + two int stores, `/O2 /TP` |
| 0x4e41a0 | Game_CountGroupSlots | C++ member, counted slot scan, `/O2 /TP` |
| 0x4f13b0 | Object_HideLinkedElements | C++ member, linked-list walk, `/O2 /TP` |
| 0x4f2a80 | IsMenuId351Or355 | C `__stdcall` id test, `/O2` |
| 0x4f2aa0 | IsMenuId34EOr350 | C `__stdcall` id test, `/O2` |
| 0x4f5fa0 | Array_SearchSet | C++ member, three-entry scan, `/O2 /TP` |
| 0x520fd0 | UI_DispatchCallback | C++ member, four-argument callback, `/O2 /TP` |

## Notes

* The 13 scalar deleting destructors use the batch01 C pattern
  `void *__fastcall Delete(void *this, int dummy, unsigned char flags)`, with
  `@Name@12` entries; `--auto-symbols` resolves the destructor and `Mem_Free`.
* `0x54dc89` is the one function that needs `/O1`: at `/O2` VC6 folds the two
  member tests into `mov eax,[ecx+8]; test eax,eax`, while the original uses
  `cmp dword ptr [ecx+8],0`. `/O1` (or `/Os`) emits the exact `cmp`-memory form
  and the full 30-byte body including the `inc/neg/sbb/and 2/dec` status fold.
  The vtable call is at offset 0x28, so the class declares ten dummy virtuals
  before `GetVirtualStatus`.
* `0x54bf50` declares its helper as `UpdateListener(__int64, int)`; MSVC 6
  spells the type `__int64` (not `long long`). The argument is pushed before
  `__ftol`, matching the original `push eax` prior to the conversion.
* `0x485ac0` uses `if (clock > 0x40 && speedIndex > 7) return 2; return 1;`,
  which produces the original `mov eax,2; jg` and `mov eax,1` placement.
* `0x4e41a0` needs the `while (count < 6) { if (*slot == -1) break; ... }`
  spelling; a `do/while` form made VC6 duplicate the slot test (48 bytes).
  `0x488bc0` likewise needs the `while` form with a moving pointer to avoid an
  unrolled loop.
* `0x548d90` passes the string at 0x576168 as `STR_00576168` so the
  `DAT_`/`STR_` fallback in `--auto-symbols` resolves it; `1.0f` becomes the
  original `push 0x3f800000`.
* All matched sources are genuine C/C++; no inline assembly and no
  `__declspec(naked)`.

## Reproduce

```sh
sh reconstructed/match/batch05/part2/verify_strict.sh
```
