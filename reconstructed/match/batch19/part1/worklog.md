# batch19 part1 worklog

25 manifest records attempted for genuine byte-identical C/C++ with
MSVC 6.0 SP3 (pinned `~/.local/share/pc2/vc6-sp3-toolchain/VC98`).
Accepted files compile with `/O2 /TP`, pass the manifest length and exact
entry symbol, and report `"strict_match": true` from
`tools/match_decomp.py --strict --auto-symbols`.

## Result

```text
strict matches: 7 / 25
```

Matched: 0x4029e0, 0x4f7920, 0x501580, 0x5300e0, 0x5402a0, 0x547ac0, 0x544760.

| address | length | entry symbol | notes |
| --- | ---: | --- | --- |
| 0x4029e0 | 225 | `?RegisterExtensionAlias@ResourceManager@@QAEXPAD0@Z` | inline `strcpy`/`strcat`; `CRT_Strlwr`; shared path separator read through `g_ResourceManager_RegisterExtensionAlias_RData` |
| 0x4f7920 | 223 | `?PickObject@Map@@QAEHH@Z` | `AI_ComputePlanScores` outputs use an `int[3]` so the frame and argument offsets match |
| 0x501580 | 220 | `?GetPlanName@GamePlan@@QAEPADH@Z` | 25-entry switch; case bodies emitted in original source order; `DAT_0057xxxx` labels resolve the jump-table targets |
| 0x5300e0 | 223 | `?HitTestChildAtPoint@UI@@QAEPAXPAH0@Z` | `Sprite_BlitClipped` must return `int` so `test eax,eax` and `*flags = eax` match |
| 0x5402a0 | 225 | `?AddExtensionMapping@SoundPakManager@@QAEXPAD0@Z` | sibling of 0x4029e0; identical inline copy/`Strlwr`/`strcat` block |
| 0x547ac0 | 224 | `?SetVolumeSetting@Sound@@QAEDHH@Z` | returns `char`; `goto done` keeps the shared `return changed` tail that emits `setne bl; mov al,bl` |
| 0x544760 | 223 | `?Sound_GetPlayPosition@@YGHPAUSoundBuffer@@PAHPAI@Z` | RAII `LockGuard` + `__stdcall` free-function ABI; virtual COM call at vtable `+0x10`; null-view path first, `result = (call >= 0) ? value : 0` makes VC6 reuse EAX=0 instead of emitting `xor eax,eax; jmp` |

## Non-matching (kept under `nonmatching/`)

| address | length | first diff | diffs | finding |
| --- | ---: | ---: | ---: | --- |
| 0x4edf30 | 223 | 0x00 | 191 | original keeps the object pointer in esi and `this` in ebx; candidate swaps the callee-saved roles and widens the prologue |
| 0x50b6d0 | 225 | 0x16 | 129 | only the duplicated `selected = param` case/default block (6 bytes) differs; MSVC merges the two loads in the candidate |
| 0x54aec0 | 225 | 0x11 | 58 | original delays `push edi` and loads `x` right after `push esi`; candidate schedules the prologue differently |
| 0x489070 | 225 | 0x3e | 63 | byte-identical with literal float constants, but those 4-byte `.rdata` COMDATs cannot pass the strict section locator; addressing the constants by label flips `fld value; fmul const` to `fld const; fmul value` |
| 0x522bd0 | 222 | 0x00 | 190 | original pushes only esi/edi and reloads `x` from the argument slot; candidate keeps `x` in ebx, and the text pointer lands in eax instead of ecx |
| 0x48a2d0 | 223 | 0x17 | 170 | original pushes all four callee-saved registers and keeps `type` in ebp; candidate spills `type` and hoists `&this->map` into ebp |

## Reproduction

```sh
bash reconstructed/match/batch19/part1/verify_strict.sh
```
