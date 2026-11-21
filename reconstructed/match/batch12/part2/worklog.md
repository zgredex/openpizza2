# batch12 part2 worklog

Target: `game/fastfood2.exe`, MSVC 6.0 SP3 (`C2.DLL 12.00.8447`). All
candidates are genuine C/C++ (`/O2 /TP`, no inline assembly).

Result: **20 / 25 strict matches** (`"strict_match": true`, exact manifest
length, explicit `--entry`, `--strict --auto-symbols`).

## Strict matches

| address | function | bytes | notes |
|---|---:|---:|---|
| 0x548510 | Sound_UpdatePositionCountdown | 91 | position refresh then countdown/flag update |
| 0x47cc10 | Game_CountPlayersByByte | 92 | `Game_GetPlayerByte8` + `& 0xff` |
| 0x47ccd0 | Game_CountRecordsByByteC | 92 | `Game_GetRecordByteC` variant |
| 0x48c160 | Game_SelectPlayer | 92 | volatile read pins `previousView` after the stores |
| 0x4dd270 | GameClock_Construct | 92 | `if (data != 0)` order matches the `je` layout |
| 0x4e2c40 | AI_GetMaxPlanSteps | 92 | `char map[0x14]`, `if (steps > maximum)` |
| 0x4f0c60 | Object_FindRecordByKey28 | 92 | `count = *list` and a `for` loop give the single inline |
| 0x520b60 | UI_IsValidSize | 92 | fifth vtable slot call, explicit pad at 0x1c |
| 0x5392e0 | Surface_InitFromBuffer | 92 | dllimport `SetRect`, ushort width/height |
| 0x53f880 | Sound_AllocDecompressedBuffer | 92 | `memory != 0 ? 0 : 0x8007000e` reproduces `and`+`add` |
| 0x546fd0 | Random_Range | 92 | dllimport `GetCurrentThreadId`/`timeGetTime`, CRT srand/rand |
| 0x4d4330 | Game_GetCostForType | 93 | case order 0,3,1,2 matches the jump table |
| 0x4e3f50 | Game_ScalePlayerStat80 | 93 | division performed before the second lookup |
| 0x4eaa40 | Map_FindNameIndex | 93 | `strcmp` intrinsic expands to the original sbb loop |
| 0x4f5ae0 | Object_ClearSlotRefs | 93 | two slot references cleared |
| 0x5397e0 | Color_RGBTo16 | 93 | `format != 0` order and `(unsigned char)(blue & 0xff)` |
| 0x5483d0 | Sound_StartSpeech | 93 | `__stdcall` virtual dispatch at vtable +0x58 |
| 0x5484b0 | Sound_StopAmbientBuffers | 93 | `if (field1d0 > 0)` gives the `jbe` guard |
| 0x54a820 | Window_MoveToSidePanel | 93 | local `right`/`left` give `edi` for `desktop.left` |
| 0x4010f0 | Stats_Report_ConstructEmpty | 94 | `rep stos` clears, 20 `String_Format` slots |

## Unmatched

Best genuine C/C++ attempts are in `nonmatching/`.

| address | function | candidate bytes | first diff | evidence |
|---|---:|---:|---|---|
| 0x5355f0 | Font_MeasureText | 91 | 0x0: original 0x51 (`push ecx`), candidate 0x56 (`push esi`) | 87 diffs. Original keeps the character index in a four-byte frame slot initialised to zero (`mov [esp+8],edi`, byte store, dword reload); every natural `char`/`int` form keeps it in `edx` or spills the glyph instead. |
| 0x53f020 | SoundBuffer_DestructBase | 48 | 0x0: original 0x6a (`push -1`), candidate 0x56 (`push esi`) | 36 diffs. Original registers an SEH frame using handler thunk 0x55ae08 (`push 0xffffffff; push 0x55ae08; mov eax,fs:0`), which a plain destructor body does not emit. |
| 0x47c7d0 | MapObject_SettlePendingAmount | 94 | 0x0: original 0x56 (`push esi`), candidate 0x51 (`push ecx`) | 75 diffs. Original reloads `[this+0x171c]` with `fld` for both comparisons and calls; the compiler-generated form spills one load to `[esp+4]` and adds a frame slot. |
| 0x54e230 | _memmove | 80 | 0x0: original 0x55 (`push ebp`), candidate 0x53 (`push ebx`) | 79 diffs. The recorded 91-byte extent is only the forward-copy entry of a larger hand-written CRT routine that continues past 0x54e28a into jump tables; a compiler-generated memmove cannot reproduce that prefix. |
| 0x550cd0 | _memmove_2 | 80 | 0x0: original 0x55, candidate 0x53 | 79 diffs; duplicate CRT routine, same limitation as 0x54e230. |

## Verification

```sh
python3 tools/match_batch.py reconstructed/match/batch12/part2.json \
  reconstructed/match/batch12/part2 --flags "/O2 /TP" --strict --auto-symbols
# matched 20/25; strict 20/25

sh reconstructed/match/batch12/part2/verify_strict.sh
# strict 20/20
```

`nonmatching/evidence.md` records the raw matcher evidence for the five
failures.
