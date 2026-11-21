# batch03 part3 worklog

Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98`, `wine CL.EXE`, flags
`/O2 /TP`. All candidates are genuine C++ (member functions and calls); no
inline assembly.

## Result

Strict count: **25 / 25** (`"strict_match": true`).

Command (the accepted gate, run from the repository root):

```sh
python3 tools/match_batch.py reconstructed/match/batch03/part3.json \
  reconstructed/match/batch03/part3 --flags "/O2 /TP" \
  --strict --auto-symbols --json-out /tmp/pc2-part3-1.json
```

Output ended with `matched 25/25; strict 25/25`. Every result has
`difference_count: 0`, empty `strict_issues`, and empty `relocation_issues`;
there were no first-byte differences. `verify_strict.sh` repeats the same gate
and prints the strict-only count.

No `--symbol` overrides were needed. External calls auto-resolve because the
callee classes are named so that the MSVC mangled name undecorates to the
symbol-map name, for example `Window::GadgetNotify` -> `Window_GadgetNotify`,
`Tooltip::SetBackgroundImage` -> `Tooltip_SetBackgroundImage`,
`Renderer::ApplySpriteTint` -> `Renderer_ApplySpriteTint`, and
`Array::InsertGrow` / `Array::RemoveValueLocked`.

## Matched (25)

| address | name | bytes | notes |
| --- | --- | --- | --- |
| 0x526850 | Dialog_SetResult | 23 | stores flag 0x280 = 1, then result at 0x27c |
| 0x526d10 | UI_SetMenuToggle | 20 | stores toggle 0x234 = 1, then field 8 |
| 0x5272a0 | UI_SetFontName | 19 | `tooltip->SetBackgroundImage(name)` on field 0x244 |
| 0x5272d0 | UI_SetLayoutParams | 23 | two dword stores at 0x82e4 / 0x82e8 |
| 0x527a80 | UI_ApplyChildSpriteTint | 24 | `renderer->ApplySpriteTint` on field 0x8310 |
| 0x527c60 | UI_AddEffectObject | 19 | `effects.InsertGrow` on subobject +0x8324 (`add ecx`) |
| 0x527c80 | UI_RemoveEffectObject | 19 | `effects.RemoveValueLocked` on +0x8324 |
| 0x527cf0 | UI_ClearScrollDrag | 21 | `xor eax,eax` shared by zero stores at 0x8338/0x833c/0x8348 |
| 0x52e830 | Renderer_ReleaseTarget | 22 | guarded clear of 0x14 and release flag 0x3c = 1 |
| 0x52f0d0 | Gadget_GetSpriteFrames | 21 | notify(param, 0, 0x42, 0, 0) |
| 0x52f830 | Gadget_SetText | 24 | notify(param, 2, 0xe, 0, value) |
| 0x52f910 | Text_SetTextColor | 24 | notify(param, 3, 0xd, value, 0) |
| 0x52f930 | Text_GetFont | 21 | notify(param, 3, 0x33, 0, 0) |
| 0x52f950 | Text_GetLineCount | 21 | notify(param, 3, 0x10, 0, 0) |
| 0x52f970 | Text_GetHeight | 21 | notify(param, 3, 0x11, 0, 0) |
| 0x52f990 | Text_ResetScroll | 24 | notify(param, 3, 0x13, value, 0) |
| 0x52f9b0 | Text_SetText | 24 | notify(param, 3, 0xe, 0, value) |
| 0x52fa20 | Text_SetMode | 24 | notify(param, 3, 0x1f, value, 0) |
| 0x52fb00 | Input_SetFilter | 24 | notify(param, 4, 0x1d, value, 0) |
| 0x52fb20 | Input_GetFilter | 21 | notify(param, 4, 0x1e, 0, 0) |
| 0x52fb40 | Input_SetNormalColor | 24 | notify(param, 4, 0xd, value, 0) |
| 0x52fb60 | Input_SetEditingColor | 24 | notify(param, 4, 0x15, value, 0) |
| 0x52fb80 | Input_SetFocusColor | 24 | notify(param, 4, 0x17, value, 0) |
| 0x52fba0 | Input_SetSelectionColor | 24 | notify(param, 4, 0x19, value, 0) |
| 0x52fbc0 | Input_SetText | 24 | notify(param, 4, 0xe, 0, value) |

## Non-matching

None. `nonmatching/` is empty.
