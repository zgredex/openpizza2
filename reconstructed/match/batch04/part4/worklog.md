# batch04/part4 worklog

Part 4 of batch 4: the 25 smallest remaining functions (25-29 bytes) listed in
`../part4.json`.  Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98`
(`wine CL.EXE`, C2.DLL 12.00.8447).  Every candidate is genuine C/C++ compiled
with `/O2 /TP`; none uses inline assembly.

Verification (from the repository root):

```sh
sh reconstructed/match/batch04/part4/verify_strict.sh
```

Result on the final tree: **25/25 strict byte matches**
(`"strict_match": true` for every record, no relocation issues and no strict
extent/unwind issues).  The script runs one
`tools/match_decomp.py ADDRESS SOURCE --length LEN --entry ENTRY
--flags "/O2 /TP" --strict --auto-symbols` invocation per record, rejects any
source containing `__asm`/`asm {`, and writes a JSON report.

The batch runner gives the same result:

```sh
python3 tools/match_batch.py reconstructed/match/batch04/part4.json \
  reconstructed/match/batch04/part4 \
  --symbols reconstructed/match/batch04/part4/symbols.json \
  --flags "/O2 /TP" --strict --auto-symbols
# matched 25/25; strict 25/25
```

## Matched (25)

| address | name | bytes | form / flags | notes |
|---|---|---|---|---|
| 0x524970 | Window_NotifyMouseMove | 27 | C++ thiscall, `/O2 /TP` | forwards `(0x200, x@0x248, y@0x24c, 0)` to 0x524990 |
| 0x527ca0 | UI_ClearField230 | 27 | C++ thiscall, `/O2 /TP` | `if (field230 == value) field230 = 0` |
| 0x52fd70 | Window_GadgetNotify_Slider_SetValue | 27 | C++ thiscall, `/O2 /TP` | forwards `(param, 5, 0x25, value, extra)` |
| 0x52fdb0 | Window_GadgetNotify_Slider_AttachValueText | 27 | C++ thiscall, `/O2 /TP` | forwards `(param, 5, 0x27, value, extra)` |
| 0x52ff30 | Array_GetRecordField40 | 26 | C++ thiscall, `/O2 /TP` | `GetRecordByKey` then field 0x40, `-1` when absent |
| 0x531b70 | UI_SetButtonRecordVariant | 27 | C++ thiscall, `/O2 /TP` | forwards `(param, 6, 300, value, 0)` |
| 0x531dd0 | UI_OffsetPoint | 27 | C++ thiscall, `/O2 /TP` | adds origin 0x18/0x1c into two caller ints |
| 0x531df0 | UI_SubtractOrigin | 27 | C++ thiscall, `/O2 /TP` | subtracts origin 0x18/0x1c from two caller ints |
| 0x533540 | Get_WidthHeight | 27 | C++ thiscall, `/O2 /TP` | two `unsigned short` fields at 0x12/0x14 widened to `unsigned` |
| 0x533a50 | Record_Clear48 | 29 | C++ thiscall, `/O2 /TP` | signed bounds check, `records[index].id = -1`, stride 0x48 |
| 0x5355b0 | Text_GetPosition | 27 | C++ thiscall, `/O2 /TP` | copies 0x9a0/0x9a4 to the caller's two outputs |
| 0x535d50 | Array_GetPtrChecked | 26 | C++ thiscall, `/O2 /TP` | signed bounds check against count at +8 |
| 0x5377d0 | Surface_ConfigureFromOwner | 28 | C++ thiscall, `/O2 /TP` | forwards `(flags@0x18, w@4, h@8, w*2)` to 0x539280 |
| 0x5396e0 | Surface_Reset | 25 | C++ thiscall, `/O2 /TP` | zeroes +0xc/+4, reloads +8/+0x10 from 16-bit limits |
| 0x539e70 | Renderer_CopyStateToChildren | 29 | C++ thiscall, `/O2 /TP` | list walk at +0x50, indirect call per child |
| 0x53d140 | Sprite_SetHotspot | 27 | C++ thiscall, `/O2 /TP` | stores two 16-bit fields when byte flag +4 has bit 2 |
| 0x53ef70 | RefCount_Release | 29 | C `__stdcall`, `/O2 /TP` | virtual release at vtable+0xc when the count reaches 0 |
| 0x53f820 | StreamBuffer_Reset | 29 | C `__stdcall`, `/O2 /TP` | unrolled 4-iteration zero loop plus an explicit first-field store |
| 0x53ff90 | Pak_SortEmbeddedEntries | 28 | C `__stdcall`, `/O2 /TP` | `CRT_QSort(base, count, 0x14, 0x53ffb0)` |
| 0x547580 | Sound_ReloadSpeechSetIfNeeded | 27 | C++ thiscall, `/O2 /TP` | reloads at byte flag +0xfe, then clears it |
| 0x5482e0 | Sound_PlayEffectByIndex | 29 | C++ thiscall, `/O2 /TP` | plays `effects[index]` at +0x24 behind byte +0xfc |
| 0x54a5d0 | Window_GetChildAndNotify | 27 | C `__fastcall`, `/O2 /TP` | indirect query through child ops table, returns the out slot |
| 0x54b2c0 | MessageList_SetField34 | 29 | C++ thiscall, `/O2 /TP` | `IDMap_Lookup(this+4, key, 0)` then field 0x34 |
| 0x54b440 | Array_GetPtr4 | 26 | C++ thiscall, `/O2 /TP` | signed bounds check against count at +4 |
| 0x54c810 | List_FreeValuesAndObject | 28 | C++ thiscall, `/O2 /TP` | frees container values, virtual release at vtable+0, clears +0 |

## Findings

- The six `Window_GadgetNotify*` / button wrappers are thiscall members that
  forward to 0x52fdd0.  Declaring the callee as `Window::GadgetNotify` yields
  `?GadgetNotify@Window@@QAEXHHHHH@Z`, which `--auto-symbols` unmangles to
  `Window_GadgetNotify`.
- Four helpers are only reachable through their shipped names, so they are
  declared as members of the matching class: `Array::GetRecordByKey`
  (0x5313d0), `Surface::Configure` (0x539280), `Renderer::CopyState`
  (0x538870) and `IDMap::Lookup` (0x4017f0).  The matcher resolves each
  mangled name through `llvm-undname` and the shipped symbol map.
- 0x53f820 keeps a duplicate first-field store in the original because the
  four zero stores come from an unrolled 4-iteration loop; writing the same
  addresses as straight-line statements lets MSVC 6 fold the duplicate away.
  The loop form reproduces the original `mov edx,eax` pointer copy exactly.
- 0x54a5d0 passes an uninitialized `Child *result` to the indirect query.
  The original only reserves the slot with `push ecx` (so the slot happens to
  start as `this`) and reads it back after the call; initialising the local
  explicitly adds a `mov [esp],ecx` that the shipped code does not have.
- 0x53ff90 is the only record that needs an explicit map:
  `_Pak_CompareEmbeddedEntries=0x53ffb0` in `symbols.json`, because the
  embedded comparator has no shipped symbol name.  `CRT_QSort` itself is
  resolved from the shipped map (`extern "C"` gives `_CRT_QSort`).

No candidate in this part failed, so `nonmatching/` is absent.
