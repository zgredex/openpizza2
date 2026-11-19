# Isodaten.idx format

Reverse engineered from `Map_LoadIsodata` (`0x4ea440`) and validated against
`game/Isokarten/Isodaten.idx`. The parser consumes the file exactly: the final
cursor equals the file size, with no padding or trailing records.

## Layout

Little-endian.

| Offset | Type | Meaning |
|---|---|---|
| `0x00` | `u32` | entry count = **2,467** |
| `0x04` | entry[] | variable-size entries |

### Entry

| Offset | Type | Meaning |
|---|---|---|
| `+0x00` | `u8` | tag: `0` = functional marker, `1` = isometric sprite |
| `+0x01` | `char[50]` | main `.SPR` name, NUL-padded with `0xCD` |
| `+0x33` | `u32` | has large variant (`name.L.SPR`) |
| `+0x37` | `u32` | has small variant (`name.S.SPR`) |
| `+0x3B` | `u32` | has medium variant (`name.M.SPR`) |
| `+0x3F` | `u32` | animation count |
| `+0x43` | anim[] | animation records |

Variant names replace the `.SPR` extension:

```text
DEKO_EDEL01.SPR  + large flag  -> DEKO_EDEL01.L.SPR
B_ALLEE_A.SPR    + small flag  -> B_ALLEE_A.S.SPR
H_UNI1.SPR       + medium flag -> H_UNI1.M.SPR
```

### Animation record

| Offset | Type | Meaning |
|---|---|---|
| `+0x00` | `u8[4]` | animation fields (observed `01 01 02 02`) |
| `+0x04` | `u8[0x0F]` | reserved / animation parameters |
| `+0x13` | `char[50]` | `.ANI` name |

Record size = `0x13 + 0x32 = 0x45` (69 bytes).

## Observed statistics

| Metric | Value |
|---|---:|
| File size | 173,504 bytes |
| Entries | 2,467 |
| Sprite entries (tag 1) | 2,458 |
| Marker entries (tag 0) | 9 |
| Entries with L/S/M variants | 750 |
| Animation records | 119 |
| Entries with animations | 89 |

The nine tag-0 markers are `APPEAR.SPR`, `CONCRETE.SPR`, `EXIT.SPR`,
`FORSERVICE.SPR`, `KISTENPLATZ.SPR`, `KITCHEN.SPR`, `OUTSIDE.SPR`,
`OUTSIDEPUNK.SPR`, `STOCK.SPR`. They are placement/semantic markers, not
renderable isometric sprites.

Variant coverage: 1,717 entries have no variants, 424 have small only, 274 have
all three, 20 have small+medium, 17 large+medium, 15 medium only.

## Tool

```bash
python3 tools/isodaten_tool.py info extracted/isodaten/isodaten.idx
python3 tools/isodaten_tool.py list extracted/isodaten/isodaten.idx
python3 tools/isodaten_tool.py list extracted/isodaten/isodaten.idx --json
python3 tools/isodaten_tool.py csv  extracted/isodaten/isodaten.idx isodaten.csv
```

## Relation to `.iso` maps

`Isodaten.idx` is the sprite dictionary. City and branch maps (`Isokarten/*.iso`)
reference entries by index. The `.iso` header and placement stream are a separate
format (`IsoMap_Load`, `0x4eb4f0`) and are not decoded by this tool.

## Evidence

- Loader: `Map_LoadIsodata` (`0x4ea440`), reads `Isodaten.idx` through
  `Resource_Open`/`Resource_Read`.
- Variant suffix constants: `DAT_005718d8` = `.L.SPR`, `DAT_005718d0` =
  `.S.SPR`, `DAT_005718c8` = `.M.SPR`.
- Parser: `tools/isodaten_tool.py`; exact end-of-file validation.
