# batch03/part4 worklog

Part 4 of batch 3: 25 tiny functions (18-24 bytes) from `../part4.json`.
Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98` (`wine CL.EXE`, C2.DLL
12.00.8447).  No candidate uses inline assembly, and no explicit `--symbol`
map was required: every external call/global was resolved by
`--auto-symbols`.

Verification (from the repository root):

```sh
sh reconstructed/match/batch03/part4/verify_strict.sh
```

Result on the final tree: **25/25 strict byte matches**.  Each record is run
as its own `tools/match_decomp.py ADDRESS SOURCE --length LEN --entry ENTRY
--flags "..." --strict --auto-symbols` invocation; the script also rejects any
source containing `__asm`/`asm {` and writes a JSON report.

## Matched (25)

| address | name | bytes | form / flags | notes |
|---|---|---|---|---|
| 0x52fbe0 | Window_GadgetNotify_Input_GetText | 21 | C++ thiscall, `/O2 /TP` | forwards `(param, 4, 0xf, 0, 0)` to 0x52fdd0 |
| 0x52fcc0 | Window_GadgetNotify_Slider_SetGradientColors | 24 | C++ thiscall, `/O2 /TP` | forwards `(param, 5, 0x1b, 0, value)` |
| 0x52fce0 | Window_GadgetNotify_Slider_SetChangeNotify | 24 | C++ thiscall, `/O2 /TP` | forwards `(param, 5, 0x1c, value, 0)` |
| 0x52fd90 | Window_GadgetNotify_Slider_GetValue | 24 | C++ thiscall, `/O2 /TP` | forwards `(param, 5, 0x26, 0, value)` |
| 0x52ff80 | UI_DisableButton | 21 | C++ thiscall, `/O2 /TP` | forwards `(param, 1, 3, 3, 0)` |
| 0x531960 | UI_SetButtonColorVariant | 24 | C++ thiscall, `/O2 /TP` | forwards `(param, 6, 0x39, value, 0)` |
| 0x5319a0 | UI_GetButtonSpriteRecord | 21 | C++ thiscall, `/O2 /TP` | forwards `(param, 6, 0x38, 0, 0)` |
| 0x531b50 | UI_ClearButtonRecordAnimation | 24 | C++ thiscall, `/O2 /TP` | forwards `(param, 6, 0x12d, 0, 0)` |
| 0x531b90 | UI_GetButtonContext | 24 | C++ thiscall, `/O2 /TP` | forwards `(param, 6, 0x36, 0, value)` |
| 0x531c40 | UI_StartButtonMovie | 24 | C++ thiscall, `/O2 /TP` | forwards `(param, 6, 0x3e, value, 0)` |
| 0x531cf0 | UI_GetWindowObject | 21 | C++ thiscall, `/O2 /TP` | forwards `(param, 7, 0x36, 0, 0)` |
| 0x532310 | UI_SetPosition | 23 | C++ thiscall, `/O2 /TP` | stores the two dwords at +0x28c/+0x290 |
| 0x535160 | Object_GetPair4 | 21 | C++ thiscall, `/O2 /TP` | loads +4/+8 into the caller's outputs |
| 0x5354e0 | Image_FreePixelData | 18 | C++ thiscall, `/O2 /TP` | `if (pixels) Mem_Free(pixels)` at +0x460 |
| 0x5355d0 | Text_SetCursor | 23 | C++ thiscall, `/O2 /TP` | stores the two dwords at +0x9a0/+0x9a4 |
| 0x539180 | Surface_IsReady | 23 | C `__stdcall`, `/O2 /TP` | indirect `__stdcall` call at `*surface+0x80`; `== 0` becomes `neg/sbb/inc` |
| 0x539260 | Surface_Unlock | 18 | C `__fastcall`, `/O2 /TP` | nested `+0x40/+0x10`, indirect `__stdcall` call at `*target+0x80` |
| 0x539f00 | Object_GetRootType | 24 | C `__fastcall`, `/O2 /TP` | walks `+0x54` while the `+0x4c` type is 3 |
| 0x53d440 | Sprite_SetColorKey | 18 | C++ thiscall, `/O2 /TP` | stores +0x1c, then ORs byte flag at +4 with 2 |
| 0x53d480 | Sprite_GetPixelBuffer | 20 | C++ thiscall, `/O2 /TP` | realizes when byte +0x39 is zero, returns +0x2c |
| 0x53fbf0 | DirectSoundBuffer_Destructor | 20 | C++ thiscall, `/O2 /TP` | stores vtable 0x55c860, releases wrapper via slot +8 |
| 0x548d70 | Sound_SetTimeout | 21 | C `__fastcall`, `/O2 /TP` | if byte +0xfc, stores 500 at +0x150 |
| 0x54dc72 | Stream_ValidateRange | 23 | C `__fastcall`, **`/O1 /TP`** | unsigned range checks; returns -1 on inversion |
| 0x551f8b | _malloc | 18 | C `__cdecl`, **`/O1 /TP`** | `__nh_malloc(size, DAT_005858f8)` |
| 0x552385 | FileObject_InitBase | 19 | C++ `__cdecl`, `/O2 /TP` | installs `&DAT_00577040` at +0x50, 1 at +0x14 |

## Findings

- The 11 `Window_GadgetNotify_*` wrappers are thiscall members forwarding to
  0x52fdd0.  Declaring the callee as `Window::GadgetNotify` produces the COFF
  name `?GadgetNotify@Window@@QAEXHHHHH@Z`; `--auto-symbols` decomposes it with
  `llvm-undname` to `Window::GadgetNotify` and then matches the shipped symbol
  `Window_GadgetNotify`.
- The vtable/data immediates in 0x53fbf0 and 0x552385 are written as
  `&DAT_0055c860` / `&DAT_00577040`.  The matcher's `DAT_xxxxxxxx` fallback
  resolves them from the address embedded in the name, so no `--symbol` entry
  is needed.
- 0x54dc72 and 0x551f8b are CRT/library-style helpers compiled for size in the
  original image.  With `/O2` they still compile, but VC6 materialises both
  compare operands in registers and uses `add esp,8` after the call.  `/O1`
  reproduces the shipped `cmp reg,[mem]` folding, the direct
  `push dword ptr [DAT_005858f8]`, and `pop ecx; pop ecx`.  A uniform `/O2`
  run therefore reports 23/25, while the per-function flags used by
  `verify_strict.sh` report 25/25 strict.
- All candidates are genuine C/C++; `part4/nonmatching/` is empty because no
  strict attempts failed.  The relocation-guard regression still passes:
  `python3 reconstructed/match/tests/test_relocation_guard.py`.
