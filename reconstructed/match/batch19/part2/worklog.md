# batch19 part2 worklog

25 manifest records attempted for genuine byte-identical C/C++ with
MSVC 6.0 SP3 (pinned `~/.local/share/pc2/vc6-sp3-toolchain/VC98`).
Accepted files compile with `/O2 /TP`, pass the manifest length and exact
entry symbol, and report `"strict_match": true` from
`tools/match_decomp.py --strict --auto-symbols`.

## Result

```text
strict matches: 4 / 25
```

Matched: 0x402750, 0x4bf4d0, 0x4da390, 0x4fc470.

| address | length | entry symbol | notes |
| --- | ---: | --- | --- |
| 0x402750 | 227 | `?Read@Resource@@QAEIPAXIPAUStream@@@Z` | inlined `memcpy` needs an `extern "C"` declaration; the file branch is the fall-through (`mode != 2`) |
| 0x4bf4d0 | 229 | `?SchoolMenu_UpdatePage@@YAXPAX@Z` | 8x8 maxima reduction and `Rating_UpdateBarByKey` loop |
| 0x4da390 | 227 | `?AdjustPlayerRankingScores@Game@@QAEXXZ` | inverted `best != slot` test and `rank > top*3/4` comparison reproduce the original block layout/encodings |
| 0x4fc470 | 226 | `?RecomputeCompanyMenuSales@Game@@QAEHH@Z` | virtual list `Destroy(1)` through a real virtual method emits the `mov edx,[ebx]`/`call [edx]` form |

## Non-matching (kept under `nonmatching/`)

| address | length | first diff | diffs | finding |
| --- | ---: | ---: | ---: | --- |
| 0x4d74c0 | 232 | 0x02 | 174 | original keeps `count` in ebx and recomputes `&this->map`; candidate spills `count` and hoists the map address |
| 0x48c920 | 233 | 0x1b | 143 | original spills `this` before `rep stos` and loads the object count after the branch; candidate schedules both earlier |
| 0x533310 | 226 | 0x89 | 82 | byte-identical effect, but the loop cursor is based at record+0x14 in the original and record+0x18 in the candidate, changing every displacement |
| 0x4e2e40 | 231 | 0x00 | 194 | original saves `-1` in ebx and spills `this`; candidate keeps `this` in ebp and uses immediates |
| 0x48d2b0 | 230 | 0x06 | 191 | original pushes all four callee-saved registers up front; candidate pushes ebp/esi only inside the loop |
| 0x527850 | 231 | 0x02 | 215 | candidate keeps the base pointer, loop index, saved offset and removed count in a 0x14-byte frame; the original uses a 0x0c-byte frame and reloads the base/count from `this` |
| 0x4d59c0 | 228 | 0x19 | 169 | `new List(0)` EH frame matches; candidate keeps the returned list in esi instead of spilling it and loading `this` for the map |

## Reproduction

```sh
bash reconstructed/match/batch19/part2/verify_strict.sh
```
