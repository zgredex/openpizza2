# batch08 part4 worklog

Batch 8 part 4 (`reconstructed/match/batch08/part4.json`, 25 functions).
Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (CL 12.00.8168 front end,
C2.DLL 12.00.8447), matcher `tools/match_decomp.py`, flags `/O2 /TP`.

**Result: 23 of 25 functions report `"strict_match": true`.** Run
`sh reconstructed/match/batch08/part4/verify_strict.sh` to re-check every
match; each check passes the manifest length and the exact entry symbol and
uses `--strict --auto-symbols`. The three failed final candidates are under
`part4/nonmatching/`.

## Matches

| address | name | form / notes |
|---|---|---|
| 0x4dc660 | Stats_SumSixSlotValues | thiscall; `slot * 0x18` becomes the original `lea` chain, six-slot sum |
| 0x4f43c0 | List_AppendQuad | `operator_new(0x10)`, four-dword copy, `List::Add` at `this+0x140` |
| 0x500e80 | Game_GetPlayerSubrecord | player index `slot*0x168`, map at `player+0x148` |
| 0x5090a0 | MapObject_SetRecordFrame | guarded `Record_ApplyVariantState`, cached frame store |
| 0x510580 | Game_CountRecordsWithoutFlag | `if (count > 0) { ... } return count;`, no early return |
| 0x512820 | IDMap_FindIndexByPointer | `__stdcall`; `if (pointer == (int)value)` fixes the `cmp` operand order |
| 0x47a8e0 | Matrix_Max4x9 | `__fastcall`; `if (value > maximum)` gives `cmp`/`jle` as in the original |
| 0x485a80 | Sound_SetVolumePreset | `Sound::ApplyVolumePreset` chosen so the name resolves |
| 0x488de0 | Game_EnterBranchInterior | branch view load, minimap, scene, volume |
| 0x49cf10 | CompanyRating_UpdateScoreText | inline `Gadget_SetTextf` 5-argument call |
| 0x4fc5f0 | Company_RefreshMenuSalesIfDue | `if (date >= field)` reproduces the original `cmp eax,edi; jl` |
| 0x4ffeb0 | Game_AdjustPlayerObjectPercent | `Object::AdjustShortPercent` member on the manager pointer |
| 0x5288f0 | UI_FinishDragAndExpandDirtyRect | `UI::QueueControlCommand`/`UI::GetOuterRect`, `Rect::Set1A4` on the target |
| 0x409d40 | Object_AdvanceToQueuedTarget | campaign check then child field/approach |
| 0x480010 | Stats_HasCurrentSales | `unsigned short` locals give `mov ax`/`mov dx` + `and`/`and` |
| 0x48d020 | Building_GetAreaByLevel | `__stdcall` float switch; cases written 3..0 so the jump table entries match |
| 0x48d070 | Stats_GetAmountByType | same descending-case switch shape |
| 0x4b8830 | CompanyProfile_UpdateRatingBars | nested `GetAverage8` call inside the five-argument rating call |
| 0x4e34a0 | Player_FindRecordType2ByKey | count in a local, type/key checks |
| 0x4e6300 | Game_SetModeByte | mode byte plus control-panel command |
| 0x4ea400 | Game_BlitScaledObjectSprite | `Gfx::BlitRLEScaled` with inlined `Sprite::GetPixelBuffer` argument |
| 0x508d50 | Object_ApplyDeferredType | inverted `if (type != 0x10)` places the 0x10 body last |
| 0x4f1370 | List_AppendNode | re-reading `this+0xbc` for the loop cursor keeps the peeled first test in ECX; `current = head` encoded EAX and left one byte |

## Nonmatching

| address | name | first diff | cause |
|---|---|---|---|
| 0x403790 | Profiler_StartTimer | offset 5: original `0x85` (`test eax,eax`), candidate `0x56` (`push esi`) | VC6 hoists the `push esi` prologue above the `DAT_0057b558` guard; the original saves `esi` only inside the active path and the zero path is a bare `ret`. Tried `if/return`, `if` body, `goto`, and a local copy. 31 differing bytes. |
| 0x549930 | Employee_NextSpriteVariant | offset 3: original `0x04` (`mov edx,[esp+4]`), candidate `0x08` (`mov edx,[esp+8]`) | Parameter registers differ: original `edx=slot`, `esi=cur`, `edi=limit`; VC6 assigns `edx=cur`, `esi=limit`, `edi=slot`. Tested member/free `__fastcall`, local copies, struct copies, and unsigned slot; all kept the swapped allocation. 16 differing bytes. |

## Reproduce

```sh
sh reconstructed/match/batch08/part4/verify_strict.sh
```
