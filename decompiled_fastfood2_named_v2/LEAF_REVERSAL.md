# Leaf-function reversal — complete (480/480)

Definition used: a game-code function with **no direct calls to another local function**. Final result: **480 leaves**, **480 named**, **0 unnamed**. Breakdown: pass 1 **30**, pass 2 **34**, pass 3 **136**, pass 4 **60**, pass 5 **60**, pass 6 **60**, pass 7 **61**, pass 8 **39 established names**.

## Completion verification

A fresh REA export of the current target (`leaf_verification/`) was checked against the 480-address leaf set:

```text
leaf functions: 480
named leaves: 480
unnamed leaves: 0
named functions in verification export: 672
```

The durable ledger `leaf_symbols.csv` has **480 rows / 480 unique addresses**, exactly matching the leaf set (0 missing, 0 extra).

## Pass 8 (39 established names)

These were already named in the pak/save/sprite layers or the main export and were re-applied to the current REA target: `Pak_FindEntry`, `ResourceIterator_Next`, `ResourceHandle_Alloc`, `Pak_DecodeIndex`, `SaveGame_CompareTime`, `Sprite_GetSize`/`Hotspot`/`Format`/`ColorKey`/`Palette`, `CS_Enter`/`CS_Leave`, `IDMap_Lookup`, `Resource_GetSize`, `RegistryKey_*`, `ResetScreenRegistry`, `SetScreenRects`, `ShutdownScreens`, `Language_MapStrings`, `UI_FindWindowByID`, `DirectDraw_Init`, import thunks and CRT string/math helpers.

## Pass 1

| Address | Name | In-degree | Bytes | Evidence |
|---|---|---:|---:|---|
| `0x488be0` | `Game_GetPlayerBySlot` | 220 | 1647 | Returns player pointer for slot 0..5 from this+0x200. |
| `0x482820` | `Game_GetCurrentPlayerCompanyName` | 98 | 1688 | Returns field +8 of the current player (company name per save header). |
| `0x48e0a0` | `NoOp_Stub` | 65 | 1505 | Empty function with 65 call sites; debug/error hook compiled out. |
| `0x53ff80` | `CS_LeavePtr` | 63 | 1585 | Leaves critical section through a pointer-to-pointer. |
| `0x4ddcc0` | `Game_GetPlayerCity` | 55 | 1598 | Returns city object for a player from the global player table. |
| `0x4f0cc0` | `Array_GetRecord28` | 39 | 1712 | Selects array at +0x9c/+0xa0 and returns index*0x28. |
| `0x532310` | `UI_SetPosition` | 29 | 1656 | Stores two coordinates at +0x28c/+0x290. |
| `0x5539be` | `CS_LeaveIndexed` | 27 | 1598 | Leaves indexed CRT lock-table critical section. |
| `0x4ef4b0` | `Grid_GetCell` | 25 | 1789 | Bounds-checked grid cell lookup, stride 0xc. |
| `0x531330` | `BinarySearch8` | 19 | 2401 | Binary search over 8-byte records, key at +4. |
| `0x54f110` | `__chkstk` | 18 | 1821 | CRT stack-probe helper. |
| `0x4d3fc0` | `Rating_AdjustA` | 15 | 1719 | Rating-dependent adjustment of +8, clamped at 0. |
| `0x4d3fe0` | `Rating_AdjustB` | 15 | 1722 | Rating-dependent adjustment of +0x10, clamped at 0. |
| `0x4d3f90` | `Rating_ClampAdjusted` | 12 | 1805 | Rating-dependent adjustment of +4, clamped to 0..100. |
| `0x4eab50` | `SparseMap_Lookup48` | 15 | 1772 | Sparse map with 2500 stride-0x48 slots. |
| `0x4da630` | `Array_GetStride60` | 12 | 1607 | Returns this+0xdc8 + index*0x60. |
| `0x4f34c0` | `UI_ComputeCenteredRect` | 12 | 1751 | Computes centered rect using half width/height. |
| `0x50d200` | `Object_SetFrame5` | 12 | 1669 | Sets field 0x94 to index*5 or -1. |
| `0x5321f0` | `UI_ClipRect` | 12 | 3126 | Clips and accumulates a dirty rectangle. |
| `0x553620` | `_strcpy` | 12 | 2552 | CRT strcpy. |
| `0x482720` | `Game_GetPlayerCount` | 11 | 1770 | Counts six player slots. |
| `0x521b10` | `Object_GetActiveValue` | 11 | 1673 | Returns +0x6c or +0x68 gated by flag 0x78. |
| `0x533a70` | `Record_ClearFlags48` | 11 | 1846 | Clears active flags in stride-0x48 record. |
| `0x53d040` | `Sprite_GetRenderSize` | 11 | 1854 | Returns render width/height, swapped for 90/270 rotation. |
| `0x540000` | `Stream_Seek` | 11 | 1925 | Sets stream position (absolute/relative/end), clamps to size. |
| `0x488d90` | `Game_GetTimeSegment` | 10 | 1567 | Game date byte / 3. |
| `0x4e2250` | `Game_FindCityIndex` | 10 | 1759 | Searches city table for +0x1dc, returns 0..6 or 7. |
| `0x401930` | `Map_LookupLinear` | 9 | 1896 | Linear key/value map lookup; 0xffffffff if missing. |
| `0x4032e0` | `RegistryKey_Close` | 9 | 1621 | Closes/clears an HKEY. |
| `0x477100` | `Clamp_0_100` | 9 | 1605 | Clamps an integer in place to 0..100. |

Durable list: `leaf_symbols.csv`. All 30 were annotated in the REA session.

## Pass 2

| Address | Name | In-degree | Bytes | Evidence |
|---|---|---:|---:|---|
| `0x54d35c` | `CS_EnterRaw` | 16 | 1568 | Raw EnterCriticalSection wrapper. |
| `0x54d367` | `CS_LeaveRaw` | 17 | 1568 | Raw LeaveCriticalSection wrapper. |
| `0x50e4c0` | `Object_SetChildField2C` | 21 | 1650 | Writes param to child+0x2c when this+200 is set. |
| `0x53efd0` | `SoundBuffer_SetBaseVTable` | 25 | 1563 | Sets base vtable PTR_LAB_0055c840 (sound object layer). |
| `0x50fe70` | `Game_GetPlayerWeightedStat` | 9 | 1941 | Weighted sum of 86 player counters times a double field /1000. |
| `0x5230b0` | `Array_GetPtr` | 9 | 1676 | Bounds-checked pointer array getter. |
| `0x4f5c70` | `Object_SetShort28` | 9 | 1588 | Stores a 16-bit value at +0x28. |
| `0x535650` | `Font_GetCharWidth` | 8 | 1755 | Per-character width from the font table, default if absent. |
| `0x50e810` | `Object_GetClampedLevel` | 8 | 1684 | Reads +0x10c, forcing it into 1..3. |
| `0x520b40` | `UI_SetAbsolutePosition` | 8 | 1684 | Sets +0x30/+0x34 = base(+0x28/+0x2c) + offset. |
| `0x54b440` | `Array_GetPtr4` | 8 | 1665 | Bounds-checked pointer array getter (element at +0). |
| `0x4e4160` | `Object_GetPair68` | 8 | 1658 | Writes fields +0x68 and +0x6c to two outputs. |
| `0x50e710` | `Object_SetFlag104` | 8 | 1589 | Stores a byte at +0x104. |
| `0x4f2aa0` | `IsMenuId34EOr350` | 8 | 1588 | Returns 1 for IDs 0x34e/0x350. |
| `0x534060` | `Record_GetBounds48` | 7 | 2244 | Reads four bounds arrays using record+0x32, stride 0x48. |
| `0x547fd0` | `SoundBuffer_Release` | 7 | 2139 | Stops/removes a sound buffer through the sound vtable. |
| `0x5342e0` | `Record_SetDoubles48` | 7 | 1906 | Writes two doubles at record+8/+0x10, stride 0x48. |
| `0x534990` | `Record_SetIndex48` | 7 | 1846 | Writes a 16-bit index at record+0x32, bounds-checked. |
| `0x401900` | `Map_FindIndex` | 7 | 1834 | Linear key search returning index or -1. |
| `0x4781b0` | `Rating_GetInverse100` | 7 | 1631 | Returns max(0, 100 - 3*field_0x19f4). |
| `0x489b10` | `Game_GetDateField0C` | 7 | 1577 | Returns field +0xc of the game date object. |
| `0x546f00` | `List_Insert` | 6 | 2534 | Inserts a node at list head or tail and fixes links. |
| `0x526d30` | `Rect_Union` | 6 | 2289 | Unions a rectangle into the accumulator at +0x1a4. |
| `0x5355f0` | `Font_MeasureText` | 6 | 2011 | Sums per-character widths for a string. |
| `0x535520` | `Text_SetMetrics` | 6 | 1946 | Writes a group of text metrics at +0x9a0..+0x9c4. |
| `0x4f3b30` | `Object_GetRect100` | 6 | 1811 | Writes four fields at +0x100/+0x104/+0x108/+0x10c. |
| `0x4e42c0` | `Game_FindGroupSlot` | 6 | 1788 | Searches six shorts at this + group*0xc + 0x78. |
| `0x5397e0` | `Color_RGBTo16` | 6 | 1762 | Packs RGB888 into RGB555 or RGB565. |
| `0x539f00` | `Object_GetRootType` | 6 | 1718 | Follows parent while type==3, then returns root type. |
| `0x55464e` | `CS_LeaveSlot` | 6 | 1662 | Leaves a CRT lock-table critical section by slot index. |
| `0x50d750` | `State_IsMenuState` | 6 | 1657 | Returns 1 for states 0xd/0x17/0x1d/0x1e. |
| `0x5260e0` | `Object_GetId` | 6 | 1596 | Returns field +4, or -1 for null. |
| `0x50e720` | `Object_SetFieldFC` | 6 | 1588 | Stores a dword at +0xfc. |
| `0x54b3c0` | `Object_ClearField4` | 6 | 1559 | Clears field +4. |

## Pass 3 (136 names)

Pass 3 covered the high-impact bulk: map/array helpers, field accessors, list/rect utilities, surface/palette helpers, sound buffer/channel functions, thread/sync wrappers, CRT memory/exception helpers, record accessors and UI geometry. The complete list with evidence is in `leaf_symbols.csv` (filter `pass=3`).

## Pass 4 (60 names)

Pass 4 merged the first parallel-review proposal file (`leaf_proposals_1.csv`): map/UI surface helpers, sound buffer/format functions, stats/calendar utilities, stream/profiler helpers and record accessors. Full evidence is in `leaf_symbols.csv` (`pass=4`).

## Pass 5 (60 names)

Pass 5 merged `leaf_proposals_4.csv`: UI/origin and scroll helpers, palette/font functions, building/economy stats, player AI/recent lists, sound voice/ADPCM, command-line parsing, save-list and media accessors. Full evidence is in `leaf_symbols.csv` (`pass=5`).

## Pass 6 (60 names)

Pass 6 merged `leaf_proposals_2.csv`: player/grid/matrix routines, tilemap and record accessors, renderer state copy, Win32 message pump, language/city lookups, sound position/device functions and CRT heap/exception helpers. Full evidence is in `leaf_symbols.csv` (`pass=6`).

## Status

All game-code leaf functions are named in REA and exported in `leaf_verification/`. The next reversal phase can move to non-leaf functions (callers of these leaves).

## Limits

- Leaf status comes from the direct-call graph; virtual/indirect calls and imports are not counted.

- Names are inferred from fields, constants, resources and call context, not original symbols.

- `Rating_AdjustA/B` and `Rating_ClampAdjusted` share a rating field (0x38) but the exact metric is not established.
