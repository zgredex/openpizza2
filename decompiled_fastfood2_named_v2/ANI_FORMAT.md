# `.ani` animation format

Recovered from `Anim_Load` (`0x532c40`) and validated against the shipped
tree-sway files in `extracted/isodaten/anims`. The decoder is implemented in
`crates/assets/src/ani.rs` and `tools/ani_tool.py`.

## Header

Little-endian.

| Offset | Type | Meaning |
|---|---|---|
| `0x00` | `u32` | render-template record count (`0x98` bytes each) |
| `0x04` | `u32` | frame count |
| `0x08` | `u32` | hotspot X candidate |
| `0x0C` | `u32` | magic `0xca42xxxx` |
| `0x14` | `u8` | flags |
| `0x15` | `u8` | bits per pixel (`8` for tree sway) |
| `0x16` | `u16` | stride |
| `0x18` | `u16` | base height |
| `0x14..0x30` | — | 0x1c-byte sprite header block |
| `0x30` | record[] | `record_count * 0x98` bytes |
| after records | `u32` | frame-block size, including this field |
| frame block | — | frame table, frame streams, palette |

The tree files use `record_count = 1`, `frame_count = 12` and magic
`0xca420002`. Actor animations use `record_count = 8` directions and up to
1,104 frames; `numbd.ani`/`numbh.ani` use the invalid-magic fallback with
one-byte coverage masks and 16-bit frame-size entries.

## Frame block

The block length is the stored size minus four bytes.

```text
u16 widths[frame_count]
u16 heights[frame_count]
u16 hotspot_x[frame_count]
u16 hotspot_y[frame_count]
u32 frame_sizes[frame_count]   (u16 when magic low < 2)
frame pixel streams            (concatenated)
BGR palette[0x300]             (8bpp)
```

Each frame stream uses the same opaque 8bpp run encoding as city sprites:
one byte is a palette index, and `<colour-key> <run>` advances by `run`
transparent pixels. The colour key comes from the animation header
(`0xff` for trees, `0x9d` for a kid actor, `0xe6` for another actor), not a
fixed escape byte. Frame width and height can change between frames; the tree
sway uses 43-44 by 72-73 pixels and `kid_m_sma` uses roughly 9-14 by 22-25.

## Validated sample

```text
file:        b_allee_a-b_allee_a.ani
frames:      12
frame 0:     44x72   FNV-1a64 6cd5e532690455f0
frame 1:     44x72   FNV-1a64 aa33f95e8fc718b5
frame 11:    44x73   FNV-1a64 e6637409a1c45575
```

`Isodaten.idx` maps `B_ALLEE_A.SPR` to this file. The Berlin crop has 14
visible animated tree draws; `pc2-viewer --animation-frame 0/1` changes the
composited pixels, and `--animate --window` cycles the prebuilt Vulkan frames.

## Tool

```sh
python3 tools/ani_tool.py extracted/isodaten/anims/b_allee_a-b_allee_a.ani
```

```text
frames: 12
  0 44x72 fnv=6cd5e532690455f0
  1 44x72 fnv=aa33f95e8fc718b5
  ...
```
