# batch17 part4 worklog

Target: `game/fastfood2.exe`, MSVC 6.0 SP3 (`C2.DLL 12.00.8447`).
All accepted candidates are genuine C++ (`/O2 /TP`, no inline assembly) and
report `"strict_match": true` from `tools/match_decomp.py --strict
--auto-symbols` with the manifest length and the exact `--entry` symbol.

Result: **7 / 25 strict matches**. Failed C attempts are kept under
`nonmatching/` with first-diff evidence. Ten records were not written because
they are C++ EH constructors with the same circular `.text$x`/`.xdata$x`
limitation documented in the part3 worklog (`0x48c340`, `0x4d4880`,
`0x523800`), or were outside the time budget.

## Strict matches

| address | function | bytes | notes |
|---|---|---:|---|
| 0x54acc0 | Sound_GetChannelObject | 186 | `id = 0` before the count test; `other->fieldC > old` operand order |
| 0x48c860 | Game_HandleObjectDeath | 187 | `switch` on object type; each case sets up its own printf arguments, shared call tail |
| 0x507e20 | Object_SetDestinationAndTarget | 187 | local `Array *array` before the lookup; inverted inner `else if` |
| 0x478420 | Branch_GetPriceComparisonRating | 188 | integer percentage expression `((sum * -3 + 100) * rating) / 100` |
| 0x54afb0 | UI_RemoveAllById | 188 | two-path branch structure; `-1.0f` immediate store |
| 0x526640 | UI_ForgetChildById | 189 | `Get_Field24`/`Clear_Field228` as `__fastcall` free helpers to match the shipped labels |
| 0x4e2d00 | Player_ComputeAverageRating | 190 | nested map walks, sum divided by object count |

## Nonmatching

| address | bytes | diff | first difference |
|---|---:|---:|---|
| 0x479120 | 187 | 139 | offset 3: original zeroes the counts through EAX, candidate through EBP |
| 0x51ea20 | 187 | 6 | offset 29: first `GetSize` pointer is `[esp+0x10]` instead of `[esp+0xc]` |
| 0x4cb6e0 | 189 | 77 | offset 29: window argument lands in EBP instead of EBX |
| 0x53d4b0 | 189 | 102 | offset 16: equal-case value computation schedules `inc edx`/`mov edi,eax` differently |
| 0x50fec0 | 191 | 106 | offset 37: loop index allocated to EDI instead of EBX |
| 0x4cb3c0 | 191 | 122 | offset 11: candidate folds `slot-1` back into `slot` and lacks the `dec ebx` |
| 0x535740 | 190 | 166 | offset 2: register allocation for text/start/end differs; candidate spills a local |

## Not attempted

`0x48c340`, `0x4d4880`, `0x523800` are `new`-expression EH constructors and hit
the circular strict-section limitation; see the part3 worklog. `0x5145a0`
needs an explicit address for the `CRT_Onexit` callback at `0x514580`, which
has no independent symbol-map entry. The remaining records
(`0x4922d0`, `0x4982b0`, `0x4ab6a0`, `0x4dd590`, `0x50d4f0`, `0x547340`,
`0x4d64b0`) were not reached in this pass.

## Verification

```sh
bash reconstructed/match/batch17/part4/verify_strict.sh
# strict 7 / 7
```
