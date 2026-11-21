# batch15 part4 worklog

25 manifest records attempted for genuine byte-identical C/C++ with
MSVC 6.0 SP3 (`/tmp/opencode/vc6-sp3-toolchain/VC98`). Accepted files compile
with `/O2 /TP`, pass the manifest length and exact entry symbol, and report
`"strict_match": true` from `tools/match_decomp.py --strict --auto-symbols`.

## Result

```text
strict matches: 4 / 25
```

Matched: 0x4a5420, 0x4ab600, 0x4de030, 0x4ff650.

| address | length | entry symbol | notes |
| --- | ---: | --- | --- |
| 0x4a5420 | 147 | `_BauenPage_ResetBuildingSlots` | four `SetField14ByKey` + four `SetChildLabelText` calls |
| 0x4ab600 | 147 | `_StatisticsBalance_UpdateHeader` | per-branch `Gadget_SetText` calls force the original push placement |
| 0x4de030 | 145 | `?GetLeadingCompanyForCategory@StatsObject@@QAEHHPAX@Z` | `value > best` (not `best < value`) produces the original `fcom` form |
| 0x4ff650 | 143 | `?CompareRounded@Math@@QAEHPAXH@Z` | record parameter is first; return type is `int`, not `bool` |

## Non-matching (kept under `nonmatching/`)

| address | length | first diff | diffs | finding |
| --- | ---: | ---: | ---: | --- |
| 0x4da300 | 142 | 0x09 | 9 | zero stores and the `GetPlayerCity` this-load are scheduled in the opposite order |
| 0x4d2f10 | 143 | 0x3d | 3 | only `Game_GetTimeByMode` call scheduling differs (original pushes edi before `mov ecx,esi`) |
| 0x4e1db0 | 143 | 0x5a | 3 | only the excluded-order comparison register pair is swapped (ecx/edx) |
| 0x4e1ee0 | 142 | 0x74 | 2 | loop-bound reload of `this->object_count` uses eax in the original, edx in the candidate |
| 0x4e45e0 | 143 | 0x03 | 12 | original keeps `this` in esi and the city in edi; candidate swaps the callee-saved registers |
| 0x4ddf10 | 145 | 0x2e | 34 | loop matches; the zero-return block order differs |
| 0x48cdd0 | 147 | 0x00 | 98 | original spills `this`/total and uses 4-byte slot arrays; candidate keeps them in registers |
| 0x48d420 | 146 | 0x04 | 90 | original initialises the stack local with the entry `push ecx`; candidate emits an extra store |
| 0x507c90 | 147 | 0x5b | 5 | original pushes the `PickRandomLinkedCellInSteps` arguments before loading ecx |
| 0x53d570 | 143 | 0x15 | 83 | `pixels == 0` branch is out of line in the original; candidate orders the blocks differently |

Not attempted: 0x509ff0, 0x5341c0, 0x477f50, 0x4787f0, 0x47f180, 0x539f90,
0x4ff530, 0x50f4c0, 0x52d6b0, 0x403ac0, 0x53cea0.

## Notes

- 0x4de030 was matched after reversing the float comparison operand order to
  `value > best`; the reverse order made VC6 emit `fld best; fcomp st(1)`.
- 0x4ff650 needed the record parameter first and an `int` return type; `bool`
  changed `mov eax,edx` into `mov al,dl`.
- No explicit `--symbol` maps were needed in this part.

## Reproduce

```sh
bash reconstructed/match/batch15/part4/verify_strict.sh
```
