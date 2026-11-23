# batch20 part3 worklog

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
| 0x47a670 | Stats_GetGroupScore | 280 | switch jump table; five float sums; `0.0f` seed is `DAT_0055c2e4` so no COMDAT `.rdata` float is emitted |
| 0x4d01c0 | Screen_OptionsSidebar_SelectPage | 274 | `__cdecl` one argument; `UI_Group_Create` is a varargs call (8 pushes, caller adds 0x20); all decorated aliases auto-resolve |
| 0x53f0a0 | Sound_SetLastError | 276 | varargs; `Sound_FormatErrorString`'s argument stays on the stack until the batched `add esp,0x10`, so `[esp+0x818]` is `label` and the va_list is `&code+1`; string constant referenced as `DAT_00571be4` |

Registry entries used implicitly by `--auto-symbols`: `??2@YAPAXI@Z` /
`??3@YAXPAX@Z` (`operator new/delete`) and the `_Sound_FormatErrorString`
alias from the shipped function map. No explicit target mapping was supplied.

## Unmatched

Genuine C++ attempts are under `nonmatching/`; first difference is
`offset: original/candidate` in hex, per `tools/match_decomp.py`.

| address | function | bytes | first diff | cause |
|---|---:|---:|---|---|
| 0x52ac50 | UI_RefreshButtonSprites | 272 | 7: `8b`/`55` | allocator puts `this` in `ebx` and `mode` in `ebp`; original has the reverse, which also spills `win` to the stack |
| 0x514330 | Storage_ProduceBatch | 273 | 64: `4d`/`45` | `GetPlayerBySlot(slot)` argument is loaded into `ecx` before the `DAT_0057c670` load in the original; VC6 always picks `eax`/`edx` here. Also a COMDAT float for `100.0f` (use of `DAT_0055c320` would remove the `.rdata` issue but the call site still differs by one instruction) |
| 0x4f0ab0 | Map_LinkCells | 274 | 0: `8b`/`51` | 4 stack arguments with the third used; the source needs the used value in arg3 but VC6 re-orders the prologue/loop register set when arg4 is the unused one. A 4th-argument-use variant loads arg4's slot instead. Double constants come from `DAT_...` labels in the good attempt |
| 0x4f5990 | UI_DrawObjectWithBounds | 274 | 226: `89`/`83` | body is byte-identical except one scheduler slot: `mov [edi],eax` is placed before `add esi,0x32` in the original. `r.left -= 0x32; bounds[0] = r.left;` reproduces the original `sub` encoding; five bytes remain |
| 0x479b00 | Grid_ScoreRuns | 276 | 14: `55`/`56` | four 80-int run tables; declaration order changes which array lands in `[esp+0x290]` and the original keeps the score in `ebp` |
| 0x406a90 | Settings_InitDefaults | 280 | 256: `89`/`0f` | loop tail is identical except the original stores `[eax-0x30]`/`[eax-0x18]` before `setl dl`; VC6 hoists `setl` in every source permutation tried |
| 0x4c1ae0 | DeliveryMenu_FillProductRows | 276 | 0: `51`/`83` | two-argument `__cdecl` row filler; the current candidate allocates an 8-byte frame and reorders the count clamp, growing the extent by 28 bytes |
| 0x479290 | Game_ComputeCategoryDominance | 281 | 3: `33`/`53` | five-entry count table; original interleaves the zero stores with the callee-saved pushes and borrows `edi` inside the first loop; candidate groups the pushes |
| 0x529160 | UI_LayoutChildElements | 278 | 6: `57`/`8b` | rectangle arithmetic and three `Sprite_GetSize` calls; original materialises the four source fields before adding, so it needs `edi` and pushes it, while the candidate reuses `ecx` and the frame shrinks by four bytes |
| 0x508c20 | Object_RebindRenderList | 280 | 70: `92`/`86` | `switch (mode)` now reproduces the `sub/dec` dispatch and the `CS_Enter` fastcall locks; the `type == 0x10` path still differs: the original round-trips the `unsigned char` index through the dead second-argument home (`mov [esp+0xc],cl; mov edx,[esp+0xc]; and edx,0xff`), 8 bytes the candidate keeps in a register, shifting every later block |

## Skipped: C++ EH functions

0x49fad0, 0x50dbf0 and 0x406bb0 need `/GX` unwinding. The strict gate currently
cannot verify their `.text$x`/`.xdata$x` sections (the compiler's `$L...`
local-label relocations are not independently resolvable), so they are left
unattempted rather than committed as body-only matches.

## Commands

```sh
sh reconstructed/match/batch20/part3/verify_strict.sh
python3 tools/match_decomp.py 0x4d01c0 reconstructed/match/batch20/part3/0x4d01c0.c \
  --length 274 --entry '?Screen_OptionsSidebar_SelectPage@@YAXPAX@Z' \
  --flags '/O2 /TP' --strict --auto-symbols
```
