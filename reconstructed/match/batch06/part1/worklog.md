# batch06 part1 worklog

Batch 6 part 1 (`reconstructed/match/batch06/part1.json`, 25 functions).
Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (CL 12.00.8168 front end,
C2.DLL 12.00.8447), matcher `tools/match_decomp.py`, manifest lengths and exact
entry symbols, `--strict --auto-symbols`.

**Result: 25 of 25 functions report `"strict_match": true`.**
`sh reconstructed/match/batch06/part1/verify_strict.sh` re-checks every record
and prints `strict 25/25, failed 0`. There are no failed final candidates, so
`part1/nonmatching/` is empty.

The default flag set is `/O2 /TP`. Three records need a different flag
(`/O1 /TP` or `/O2 /Oi- /TP`); the verify script carries the exact flags per
record.

## Matches

| address | name | length | form / flags |
|---|---|---|---|
| 0x51e9d0 | UI_InitInputHelper | 35 | member returning `this`, seven stores in source order, `/O2 /TP` |
| 0x401900 | Map_FindIndex | 36 | member, `if (count>0)` + `while`, `/O2 /TP` |
| 0x50a920 | Object_SetWorkState | 36 | member, `SetState(0x2e)` + global store + `SetFlag104(1)`, `/O2 /TP` |
| 0x5230d0 | Array_IndexOfInt | 36 | member, `if (count>0)` + `while`, `/O2 /TP` |
| 0x54b390 | MessageList_Construct | 36 | member, `operator_new(0xf0)`, capacity then count, `/O2 /TP` |
| 0x403bb0 | Timer_RemoveById | 37 | member, list walk, tail `return RemoveEntry(node)`, `/O2 /TP` |
| 0x4d40f0 | Game_ResetPlayerStatsByCity | 37 | `__fastcall`, member lookup + tail `ResetAverages`, `/O2 /TP` |
| 0x4f5f70 | Array_SetSlot | 37 | member, `slot = keys` do/while, `/O2 /TP` |
| 0x509fc0 | Building_IsSpecialType | 37 | `__fastcall`, 4/5/0xb/0x21/0xf compare chain, `/O2 /TP` |
| 0x50f560 | Game_GetPlayerTotalValue | 37 | `__fastcall`, base-bumped `values[6]+values[2]+values[1]`, `/O2 /TP` |
| 0x5140b0 | Array_FindPair | 37 | member, 20-entry 12-byte-stride pair scan, `/O2 /TP` |
| 0x522ef0 | Array_Clear | 37 | member, conditional `Mem_Free`, stores 4/0xc/8/0x10, `/O2 /TP` |
| 0x54d3be | Stream_PeekChar | 37 | member, virtual slot 8, `/O1 /TP` |
| 0x54d574 | Stream_PutBackChar | 37 | member, virtual slot 9, `int` virtual arg, `/O1 /TP` |
| 0x551de9 | String_MakeRoomAtFront | 37 | free function, `strlen`+1 and `memmove`, `/O2 /Oi- /TP` |
| 0x48b3f0 | Game_GetYearAndWeekday | 38 | member, byte at date+8 then word at date+4, `/O2 /TP` |
| 0x4986c0 | GlobalArray_FindInt | 38 | free function, `DAT_0057ca08`, `/O2 /TP` |
| 0x49c0e0 | GlobalArray_FindIndex | 38 | free function, `DAT_0057ca94`, `/O2 /TP` |
| 0x4dbfc0 | Market_GetPriceModifier | 38 | member, `value == 1 ? 10 : -10`, `/O2 /TP` |
| 0x521b90 | UI_DetachObject | 38 | member, `renderer->ui->RemoveEffectObject(this)`, `/O2 /TP` |
| 0x5281c0 | UI_InvokeCallback | 38 | member, cdecl callback through +0x8308, `/O2 /TP` |
| 0x5301c0 | UI_QueueControlCommand | 38 | member, `queue->QueueCommand(command,this,a,b,c)`, `/O2 /TP` |
| 0x531f80 | UI_ReleaseChildBufferByKey | 38 | `__fastcall` free function, `BinarySearch8` with dummy, `/O2 /TP` |
| 0x548040 | Sound_TriggerSoundById | 38 | member, enabled byte and nonnegative index, `/O2 /TP` |
| 0x548ac0 | Object_FlushPending | 38 | `__fastcall`, `__stdcall` virtual flush at +0x68, `/O2 /TP` |

## Implementation notes

* `0x401900`, `0x5230d0`, `0x4986c0`, `0x49c0e0`: the original has a single
  copy of the loop body with a bottom `cmp; jl`. A `do { ... } while` produced
  loop peeling (a duplicated compare/body, 48 bytes). Writing
  `if (count > 0) { p = items; while (i < count) { ... } }` gives the original
  36/38-byte shape exactly.
* `0x50f560`: the original computes `add ecx,0x70` after loading `+0x88` and
  then reads `+8(ecx)` / `+4(ecx)`. This is VC6's base-pointer bump for
  `int *values = player + 0x70; values[6] + values[2] + values[1]`; direct
  `*(int *)(player+0x78)` / `+0x74` accesses lose the `add` and fail at
  offset 23.
* `0x4dbfc0`: the `dec; neg; sbb; and al,0xec; add 0xa` sequence is what VC6
  emits for `value == 1 ? 10 : -10`. The Ghidra-style
  `(-(unsigned)(value != 1) & 0xffffffec) + 10` produces `setne`/`neg` and
  fails.
* `0x548ac0`: the indirect virtual call at vtable +0x68 is followed by no
  `add esp,8`, so the target is `__stdcall`; `__cdecl` adds the cleanup and
  fails at offset 12.
* `0x531f80`: `BinarySearch8` is a single-token symbol. It is declared as a
  `__fastcall` function with an unused `dummy` argument, matching the batch01
  pattern; the incoming `edx` is forwarded so no extra `mov edx` is emitted.
* `0x54d3be` / `0x54d574`: these two need `/O1`. `/O2` emits a load + `test
  reg,reg` where the original has `cmpl $0,mem` and reverses the compare
  operands. `0x54d574`'s virtual slot 9 takes an `int` argument, which produces
  the original `movsbl [esp+4],edx; push edx` rather than a byte push.
* `0x551de9` needs `/Oi-`: with `/O2` the `strlen` call is recognised as an
  intrinsic and expanded to inline `repnz scas` (no call, 3 stack args cleaned
  instead of 4). `/O2 /Oi-` keeps the `_strlen` call and matches exactly.
* `0x50f560`, `0x531f80`, `0x548ac0` and the `Game_*` callers model `Class_Method`
  callees as C++ member functions whose mangled names demangle to the shipped
  symbol names, so `--auto-symbols` resolves every relocation.
* Global data slots are declared as `DAT_<address>`; `--auto-symbols` resolves
  them through its `DAT_/STR_` fallback.
