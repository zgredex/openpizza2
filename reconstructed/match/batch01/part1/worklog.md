# part1 worklog

Batch 1 part 1 (`reconstructed/match/batch01/part1.json`, 25 functions).
Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (CL 12.00.8168 front end,
C2.DLL 12.00.8447), matcher `tools/match_decomp.py`, default `/O2`.

**Result: 9 of 25 matched as genuine C/C++.** Run
`sh reconstructed/match/batch01/part1/verify.sh` to re-check every match. The
other 16 are not part of the match set; their candidates are in
`part1/nonmatching/` (see below).

## Matcher update (5cb2219c)

The matcher now copies the original PE's linker-resolved `DIR32`/`REL32` fields
from the same offset, so COMDAT `.text$x` EH handler thunks are no longer a
blocker. `--symbol` is only needed for `--strict-symbols`.

The 11 EH targets were re-run as C/C++ with `/O2 /GX`:

* `0x401a20` now matches as C++ `??1ResourceManager@@UAE@XZ`.  The key was
  declaring the game allocator `Mem_Free` with C++ linkage: VC6 assumes
  C-linkage CRT calls cannot throw, so only the C++ call makes the compiler
  emit the original unwinding frame (state slot, `this` save and the
  member-destructor unwind action).
* The other 10 EH targets were reconstructed (or re-attempted) in C/C++ but
  still differ for ordinary codegen reasons, not because of EH relocation
  handling; first diffs are listed below.

## Matches (C/C++ only)

| address | name | form / flags |
|---|---|---|
| 0x401020 | StatsPeriodReport_Delete | C, `__fastcall` shim, `/O2` |
| 0x401a20 | ResourceManager_Destruct | C++ destructor, `/O2 /GX /TP` |
| 0x48c1c0 | Object_AbortOrderForTarget | C, `__stdcall`, `/O2` |
| 0x4cf690 | RestaurantInfoPanel_UpdateTabButtons | C++, `/O2 /TP` |
| 0x4d3710 | Character_Delete | C, `__fastcall` shim, `/O2` |
| 0x4e4320 | BuildingValue_Delete | C, `__fastcall` shim, `/O2` |
| 0x4fecc0 | AI_UpdateAdvertisingCampaigns | C++, `/O2 /TP` |
| 0x509060 | UI_SetChildRecordVariant | C, `/O2` |
| 0x5316b0 | UI_ShowChildByID | C, `__fastcall` shim, `/O2` |

## Nonmatching (16)

`nonmatching/asm/` holds the naked-asm transcriptions from the previous commit
for all 16. They still match byte-for-byte under the updated matcher, but are
excluded from the C-only count because they are not source reconstruction.

`nonmatching/*.c` holds genuine C/C++ attempts for 10 of the 16; their first
diffs against the original:

| address | first diff | diagnosis |
|---|---|---|
| 0x4ecd70 | +0x6: orig `8b 74 24 28` (`mov esi,[esp+0x28]`), cand `89 4c 24 18` (`mov [esp+0x18],ecx`) | Prologue scheduling only: the compiler saves `this` before loading the stream argument; the rest of the 662-byte function is identical (9 differing bytes total). |
| 0x4aa740 | +0x8: orig `83 ec 34` (`sub esp,0x34`), cand `83 ec 3c` | Extra 8 bytes of spilled locals; `local_38`/`local_3c` slot order and `local_30` register allocation differ. |
| 0x532330 | +0x16: orig `53` (`push ebx`), cand `55` (`push ebp`) | `this` lands in esi instead of edi; candidate also keeps the count/first-arg regs differently (pushes ebp,esi,edi vs ebx,ebp). |
| 0x53cf40 | +0x17: orig `56` (`push esi`), cand `55` (`push ebp`) | `this` in esi vs edi and an extra ebp use for the `-1` compare; candidate 240 vs 244 bytes. |
| 0x498a70 | +0x17: orig `81 ec 20 03 00 00` (`sub esp,0x320`), cand `81 ec 1c 03 00 00` | Frame is 4 bytes smaller: the compiler overlaps the `new UIListEntry` temp with the first 4 bytes of `FindData`, and keeps the find handle in ebp instead of `[esp]`. |
| 0x49b720 | +0x17 | Same body shape as 0x498a70 with the menu-list globals. |
| 0x477c80 | +0x19: orig `77` (`ja`?), cand `d8` | `this` in esi vs edi and the first field compare folds into `cmp mem,eax` instead of a pre-call `mov esi,[edi+0x30]`. |
| 0x4ce450 | +0x1b: orig `57` (`push edi`), cand `33` (`xor ebx,ebx`) | Branch/register layout after `UI_SetPosition`; candidate 432 vs 437 bytes. |
| 0x4f2ac0 | +0x35: orig `74 20` (`je +0x20`), cand `74 21` | Map-base codegen: original `mov eax,[DAT]; lea ecx,[eax+0x74]`, candidate `mov ecx,[DAT]; add ecx,0x74`. |
| 0x4dc540 | +0x81: orig `8b 4b 08` (`mov ecx,[ebx+8]`), cand `8b 43 08` | Store-address register allocation in the two variant stores. |

The remaining six (0x4a6c20, 0x4b1f40, 0x4dd6b0, 0x51ef80, 0x5235b0, 0x532c40)
have no genuine C/C++ candidate yet; only the asm transcription exists.

## EH re-run status

| address | result |
|---|---|
| 0x401a20 | C++ match |
| 0x498a70 | C attempt, +0x17, 79 differing bytes |
| 0x49b720 | C attempt, +0x17, 79 differing bytes |
| 0x4ce450 | C attempt, +0x1b, 275 differing bytes |
| 0x4dd6b0 | asm only, no C candidate |
| 0x4f2ac0 | C attempt, +0x35, 81 differing bytes |
| 0x51ef80 | asm only, no C candidate |
| 0x5235b0 | asm only, no C candidate |
| 0x532330 | C attempt, +0x16, 145 differing bytes |
| 0x532c40 | asm only, no C candidate |
| 0x53cf40 | C attempt, +0x17, 171 differing bytes |
