# `.iso` isometric map format

Reverse engineered from `IsoMap_DeserializeGrid` (`0x4EB900`), called by
`IsoMap_Construct` (`0x4EB0F0`). Validated against **all 25 maps** in
`game/Isokarten`: every parse consumes the file exactly, with zero remaining
bytes.

Two families share the format:

- city maps: `Ber.iso`, `Lon.iso`, `Mad.iso`, `Mos.iso`, `Par.iso`, `Rio.iso`,
  `Rom.iso`, `Syd.iso`, `Tok.iso`, `Yor.iso`
- branch/building maps: `Iso_Filiale_*.iso`

## Header — 0x7C bytes before the object tables

Little-endian.

| Offset | Type | Meaning | Observed |
|---|---|---|---|
| `0x00` | `u32` | format version | `0x10` on every map |
| `0x04` | `u32` | layer-name mode | `0` = inline 50-byte names |
| `0x08` | `u32` | viewport width in tiles | 64 city, 16 branch |
| `0x0C` | `u32` | viewport height in tiles | 32 city, 8 branch |
| `0x10` | `u32` | isometric tile pixel width | 72 city, 130 branch |
| `0x14` | `u32` | isometric tile pixel height | 72 city, 130 branch |
| `0x18` | `u32` | **tile grid width** | 164 city, 280 branch, 152 Paris |
| `0x1C` | `u32` | **tile grid height** | 164 city, 280 branch, 152 Paris |
| `0x20` | `u32` | map pixel width candidate | 2976 city, 1160 branch |
| `0x24` | `u32` | map pixel height candidate | 1344 city, 939 branch |
| `0x28` | `u32` | unknown | 2784 city, 1160 branch |
| `0x2C` | `u32` | unknown | 1344 city, 568 branch |
| `0x30` | `u32` | unknown | 6944 city, 1564 branch |
| `0x34` | `u32` | unknown | 3248 city, 1024 branch |
| `0x38` | `u8[16]` | layer flags | 1,1,0,0 city; 1,0,0,0 branch |
| `0x48` | `u32` | unknown | 1 |
| `0x4C` | `u32` | unknown | 1 |
| `0x50` | `char[30]` | background TGA/sprite name | e.g. `berlin_a.tga` |
| `0x6E` | `u16` | unknown | 0 |
| `0x70` | `u32` | unknown | 0 |
| `0x74` | `u32` | object table 1 count | 334–757 city, 0 branch |
| `0x78` | `u32` | object table 2 count | 373–1319 city, 0 branch |

The loader overwrites the 16 bytes at `0x38` with `1,1,0,0` and reads the grid
dimensions from `+0x1C` / `+0x20` in the object, i.e. file `0x18` / `0x1C`.
`0x08`/`0x0C` are the viewport/tile-window dimensions, not the grid size.

## Object tables

Immediately after the header come two tables of **34-byte records**. Table 1
count is at `0x74`, table 2 at `0x78`; records are sequential and table 2 starts
right after table 1.

| Record offset | Type | Meaning |
|---|---|---|
| `+0x00` | `u8` | flags |
| `+0x01` | `u16` | object ID (continues across the two tables) |
| `+0x03` | `u8` | type |
| `+0x04` | `u8` | subtype |
| `+0x05` | `u32` | key (sprite/object key; semantics not fully proven) |
| `+0x09` | `u32` | x coordinate candidate |
| `+0x0D` | `u32` | y coordinate candidate |
| `+0x11` | `u8[16]` | animation/layer block |
| `+0x21` | `u8` | extra |

The in-memory struct is 0x28 bytes; the on-disk record is 34 bytes and leaves
the same gaps the loader leaves.

## Tile grid

The grid starts at:

```text
0x7C + (list1_count + list2_count) * 34
```

Total tiles = `grid_w * grid_h` (164² = 26,896 city; 280² = 78,400 branch).

### RLE

For each grid position:

```text
u32 flag
if flag == 1:
    u32 run          # skip `run` empty tiles
else:
    tile record
```

### Tile record

Fixed part, 30 bytes:

| File offset | Type | Meaning |
|---|---|---|
| `+0x00` | `u32` | tile flags |
| `+0x04` | `u16` | tile word; observed `0xFFFF` on every non-empty tile |
| `+0x06` | `u32` | unknown |
| `+0x0A` | `u32` | unknown, often `0xFFFFFFFF` |
| `+0x0E` | `u32` | unknown, often `0xFFFFFFFF` |
| `+0x12` | `u32` | unknown |
| `+0x16` | `u32` | unknown |
| `+0x1A` | `u8[4]` | flags/bytes |

Then two layers:

```text
u32 raw_id
if header.name_mode == 0 and raw_id < 0x80000000:
    char name[50]
```

- `layer1` is the first sprite/object layer.
- `layer2` is the second sprite/object layer.
- `0xFFFFFFFF` means absent.
- Raw IDs are map-value keys into the 2,500-entry world name table
  (`Game_GetMapValue`); the 50-byte string is the inline sprite name used by the
  map editor/loader.

Example tiles from `Ber.iso`:

```text
index 3189  layer1=-1                    layer2=0x6FA LATERNEKL04_2.SPR
index 3355  layer1=-1                    layer2=0x65C B_LAUB_B.SPR
index 3680  layer1=-1                    layer2=0x888 W_BUERF_GER2.SPR
```

### Trailer

After the grid:

```text
u32 flag
if flag == 1:
    u32 count
    u32 values[count + 1]
```

All 25 shipped maps have `flag = 0`.

## Validation

`tools/iso_tool.py scan game/Isokarten`:

```text
summary: 25 OK, 0 failed
```

City maps:

| File | Bytes | Grid | Objects | Tiles |
|---|---:|---|---:|---:|
| `Ber.iso` | 251,732 | 164×164 | 673 + 970 | 2,166 |
| `Lon.iso` | 203,404 | 164×164 | 508 + 622 | 1,744 |
| `Mad.iso` | 210,764 | 164×164 | 598 + 696 | 1,768 |
| `Mos.iso` | 241,716 | 164×164 | 718 + 1,319 | 1,950 |
| `Par.iso` | 251,676 | 152×152 | 744 + 1,122 | 2,089 |
| `Rio.iso` | 189,958 | 164×164 | 334 + 373 | 1,738 |
| `Rom.iso` | 240,588 | 164×164 | 524 + 738 | 2,118 |
| `Syd.iso` | 215,182 | 164×164 | 481 + 562 | 1,942 |
| `Tok.iso` | 204,136 | 164×164 | 451 + 745 | 1,766 |
| `Yor.iso` | 259,414 | 164×164 | 757 + 904 | 2,260 |

Branch maps: 15 files, 260×260 or 280×280 grids, 39–4,094 non-empty tiles.
The full per-file table is `iso_validation.csv`.

## Tool

```bash
python3 tools/iso_tool.py scan game/Isokarten
python3 tools/iso_tool.py info game/Isokarten/Ber.iso
python3 tools/iso_tool.py header game/Isokarten/Ber.iso
python3 tools/iso_tool.py lists game/Isokarten/Ber.iso --limit 20
python3 tools/iso_tool.py tiles game/Isokarten/Ber.iso --limit 30
python3 tools/iso_tool.py json game/Isokarten/Ber.iso > ber.json
python3 tools/iso_tool.py csv game/Isokarten/Ber.iso ber_tiles.csv
python3 tools/iso_tool.py preview game/Isokarten/Ber.iso ber.png
python3 tools/iso_tool.py verify game/Isokarten/Ber.iso
```

Previews are written to `iso_previews/` for all 25 maps. Colours:

- dark blue-gray: empty tile
- green: first layer only
- yellow: second layer only
- orange: both layers

The preview is an occupancy/layout view, not a sprite-rendered map.

## Open questions

- Exact semantics of header `0x28`, `0x2C`, `0x30`, `0x34`.
- Object record `key` and the animation block layout.
- Tile fields `+0x06`, `+0x0A`, `+0x0E`, `+0x12`, `+0x16`, `+0x1A`.
- Mapping raw layer IDs through the 2,500-entry name table.
- Full sprite composition/rendering from layer names.

## Projection and composition

The runtime cell coordinates are created by `IsoMap_DeserializeGrid` before
the tile records are read:

```text
cell_x = ((grid_h - tile_y + tile_x) * view_w) / 2
cell_y =  (tile_x + tile_y) * view_h / 2
```

For `Ber.iso` (`grid 164x164`, `view 64x32`) that gives a 32x16-pixel step per
cell: `(x, y) -> ((164 - y + x) * 32, (x + y) * 16)`. The loader's
`Map_ComputeObjectDistance` ranks neighbouring cells with the same coordinates
and the weights `3*|dx| + 4*|dy|`.

`UI_AlignSpriteToRect` places a sprite horizontally centred on `cell_x`; the
map renderer paints cells in increasing ground-line order, so upper rows are
behind lower rows. `pc2-scene` uses a bottom-centre anchor and sorts by
`(cell_y, cell_x - width/2, asset, tile)` to reproduce that painter order.

The map background is a colour-mapped TGA. For Berlin it is
`backgrounds/ber.tga` (4096x2048, 8bpp palette) and it is placed at the header's
`u28`/`u2c` origin `(2784, 1344)`, i.e. it covers 128x128 cells at the city
zoom. The default 800x600 crop centres on the named-layer bounding box
`(5056, 2464)`, giving background origin `(1872, 820)` and 125 visible sprites:

```text
tiles: 2,166 present, 1,861 inline layers
unique inline names: 275 (all resolve uniquely through the PAK index)
crop: 125 ordered draws, 0 missing, 0 ambiguous
PNG SHA-256: e4c82cdaea60e74b27923b26b14942f23f823580d776bbeacfbca5cb9531fb49
```

Reference images from the original executable are still pending; current
validation covers the local data, draw order, an 8-bit and a 16-bit sample, and
a deterministic Vulkan readback.

## Branch interior composition

Branch headers name a `.tga` background (for example
`filiale_einf_klein_back.tga`), but the shipped asset is an 8bpp
`isodaten/sprites/filiale_klein_einf_back.spr`; the style and size tokens are
reversed between the header and the asset name. The sprite's fully transparent
diamond is an exact cut-out whose axis-aligned bounds match the corresponding
`filiale_<size>_boden<style>00.spr` floor sprite:

```text
Iso_Filiale_einf_klein.iso
  background  filiale_klein_einf_back.spr   799x551, transparent bbox (142,193)-(780,512)
  floor       filiale_klein_bodeneinf00.spr 639x320 at the bbox origin
  tiles       40, all with inline layer-2 names
  draws       39 after crop clipping
```

`pc2-scene` composites the floor into the cut-out, then paints furniture in
ground-line order. All 15 branch maps resolve the same way; the `roh` maps add
thousands of unnamed ground cells but still have 39-55 named furniture layers.
