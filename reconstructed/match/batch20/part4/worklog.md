# batch20 part4 worklog

Target: `game/fastfood2.exe`, MSVC 6.0 SP3 (`C2.DLL 12.00.8447`), pinned
toolchain (`~/.local/share/pc2/vc6-sp3-toolchain/VC98`; runtime smoke test
`reconstructed/match/runtime01/verify_strict.sh` reports `strict matches: 6/6`).
All candidates are genuine C++ and compile with `/O2 /TP`; no inline assembly,
no `stdint.h`, and no explicit `--symbol` overrides (auto-resolution only).

Result: **3 / 25 strict matches** (`"strict_match": true` with
`tools/match_decomp.py --strict --auto-symbols`) and with
`verify_strict.sh`, which passes the manifest length and the exact entry symbol
for every function.

## Strict matches

| address | function | bytes | notes |
|---|---:|---:|---|
| 0x485700 | Game_RefreshDaylightCurve | 284 | 25-entry `int` table materialised on the stack, per-entry `fild/fmul/fiadd/__ftol`, all 25 stores identical; `DAT_0057ba00` float global |
| 0x488a10 | Game_UpdateDateLabels | 288 | two 32-byte strings; `strcpy`/`String_Format` branch order and the `(day*5)&0xff` argument order match; `CS_Enter`/`CS_Leave` are `__fastcall` (lock in ECX, no stack cleanup) |
| 0x4aef90 | Glossary_BranchesPage_Init | 292 | `__cdecl` page initialiser; `GetPairByKey` output pointers reuse the incoming argument home; varargs `UI_Group_Create` and slider setter chains; all 14 static call sites lay out identically |

No explicit symbol mappings were needed; the shipped name map resolves
`Array_GetPairByKey`, `Window_GadgetNotify_*`, `UI_RemoveObjectByKey` and
`Glossary_*`, `CS_Enter`, `CS_Leave` and `Array_GetRecordByKeyPtr` via decorated aliases. `0x485700` only uses `__ftol`.

## Unmatched

Genuine C++ attempts are under `nonmatching/`; first difference is
`offset: original/candidate` in hex, per `tools/match_decomp.py`.

| address | function | bytes | first diff | cause |
|---|---:|---:|---|---|
| 0x5101d0 | AI_CountPlanSteps | 284 | 9: `57`/`53` | original saves only `edi` before the `map == 0` early return and pushes `ebx/ebp/esi` after it; VC6 emits all callee-saved pushes up front for every permutation tried. Body after the prologue is otherwise identical |
| 0x5100b0 | Stats_SumMaskedMapFloats | 283 | 9: `89`/`53` | same shrink-wrap difference; `sum` must be initialised with an integer zero store and the early `return` uses `DAT_0055c2e4` to avoid a `.rdata` float COMDAT |
| 0x498180 | BranchList_UpdateRows | 289 | 24: `84`/`94` | frame-pointer build (`and esp,-8`, 36-byte buffer) matches, but the record-map pointer lands in `eax`/`edx` differently and the offset induction is materialised as `shl` instead of the original `lea` |

## Other manifest records

0x537230, 0x4fc290 and 0x54b640 need `/GX` unwinding and are blocked by the
strict gate's current `.text$x`/`$L...` verification limits, like the EH
records in part3. The remaining part4 records (surface/sprite/person helpers)
were not attempted in this pass; they need their own first-diff work and are
left untouched.

## Commands

```sh
sh reconstructed/match/batch20/part4/verify_strict.sh
python3 tools/match_decomp.py 0x485700 reconstructed/match/batch20/part4/0x485700.c \
  --length 284 --entry '?RefreshDaylightCurve@Game@@QAEHM@Z' \
  --flags '/O2 /TP' --strict --auto-symbols
```
