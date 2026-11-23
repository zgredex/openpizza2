# batch21 part1 worklog

Scope: 9 functions from `reconstructed/match/batch21/part1.json` (the nine
smallest untried records of batch21). Work is confined to
`reconstructed/match/batch21/part1/`.

Toolchain: pinned persistent VC6 SP3 MSVC 6.0
(`~/.local/share/pc2/vc6-sp3-toolchain/VC98`, C2.DLL 12.00.8447).
`sh reconstructed/match/runtime01/verify_strict.sh` reported 6/6 before this
work. Every accepted function is genuine C/C++ and passes
`tools/match_decomp.py --strict --auto-symbols` with the manifest length and
the exact candidate entry symbol.

Reproduce with:

```sh
sh reconstructed/match/batch21/part1/verify_strict.sh
```

## Matches

| address | function | flags | entry | notes |
| --- | --- | --- | --- | --- |
| 0x5086e0 | `UI_ShiftChildRect` | /O2 /TP | `?UI_ShiftChildRect@@YIXPAD@Z` | C++ member calls (`CS::Enter/Leave`, `Gfx::BlitRectList`) resolve through the decorated-alias rule; `DAT_0058072c` is a pointer variable loaded into ECX. |
| 0x522f40 | `Array::InsertGrow` | /O2 /TP | `?InsertGrow@Array@@QAEHH@Z` | `__thiscall` member; `memcpy` is the compiler's inline `rep movsd/movsb`; `capacity` reloaded after `operator_new`. |
| 0x404460 | `ResourceManager_OpenArchivePath` | /O2 /TP | `?ResourceManager_OpenArchivePath@@YAHPAUResourceManager@@PAD@Z` | `GetFileAttributesA` is a dllimport (`mov edi,ds:IAT` on the two calls); the second probe's shipped test is the signed `% 16` sequence, so the source uses `attributes % 16 != 0`; `Pak_Open` is a `__thiscall` member call bound explicitly (`?Pak_Open@ResourceManager@@QAEXPAD@Z=0x401af0`). |

## Non-matching evidence

See the table at the end after all nine records have been attempted.

## Not attempted

None; all nine records are attempted at least once.
