# batch19 part4 worklog

Target: `game/fastfood2.exe`, MSVC 6.0 SP3 (`C2.DLL 12.00.8447`), genuine
C++ (`/O2 /TP`), no inline assembly.

Result: **1 / 25 strict matches.** `0x4014b0` is the first committed match;
the rest of the part remains incomplete.

## Strict match

| address | function | bytes | entry | notes |
|---|---:|---|---|---|
| 0x4014b0 | List_Add | 251 | `?Add@List@@QAEHH@Z` | two parallel int arrays, 0x14-entry growth, inline `memcpy` to `rep movs`, global `0x579af0` critical section via `?Enter`/`?Leave`. The shipped comparison is `cmp count,capacity; jl`, so the source condition is `if (count >= capacity)`. |

## Attempts

| address | function | bytes | first diff | cause |
|---|---:|---:|---|---|
| 0x4f7a50 | Game_SumPlayerAssetValue | 244 | 2: `14`/`10` | original reserves five local dwords; candidate folds the accumulators into four |

The remaining part4 targets were surveyed from the generated packets but not
attempted: `0x47fa40`, `0x50c8a0`, `0x5424b0`, `0x532930`, `0x4ba340`,
`0x507b90`, `0x477000`, `0x5239d0`, `0x52a160`, `0x4c89b0`, `0x478db0`,
`0x50b100`, `0x513e50`, `0x4b9a40`, `0x50c7a0`, `0x526100`,
`0x4f7320`, `0x54fcd4`, `0x4af370`, `0x4d6390`, `0x50d310`, `0x549070`,
`0x54f620`.
