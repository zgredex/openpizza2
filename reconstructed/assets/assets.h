#ifndef PC2_RECONSTRUCTED_ASSETS_H
#define PC2_RECONSTRUCTED_ASSETS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define FNT_GLYPH_COUNT 224
#define FNT_MAX_COVERAGE 1024

typedef struct SpriteAsset {
    uint32_t width;
    uint32_t height;
    uint32_t canvas_width;
    uint32_t canvas_height;
    int16_t hotspot_x;
    int16_t hotspot_y;
    uint8_t bpp;
    uint8_t flags;
    uint8_t *pixels;
    size_t pixel_capacity;
} SpriteAsset;

typedef struct FntInfo {
    uint16_t line_height;
    uint16_t max_width;
    uint8_t advances[FNT_GLYPH_COUNT];
} FntInfo;

typedef struct FntGlyph {
    uint16_t width;
    uint16_t height;
    uint8_t x_offset;
    uint8_t y_offset;
    size_t coverage_length;
} FntGlyph;

/*
 * SPR decoder from Sprite_Load (0x53C7F0): 8/16bpp with alpha/RLE and raw
 * paths, palette after the pixel stream for 8bpp, RGB555 for 16bpp.
 * FNT decoder from Font_Load (0x535180): five 0xE0 tables, 224 lengths,
 * advances, line-height/max-width and concatenated glyph RLE streams.
 */
bool spr_decode(const uint8_t *data, size_t length, SpriteAsset *sprite,
                uint8_t *pixels, size_t capacity);
bool fnt_read_info(const uint8_t *data, size_t length, FntInfo *info);
bool fnt_decode_glyph(const uint8_t *data, size_t length, char ch,
                      FntGlyph *glyph, uint8_t *coverage, size_t capacity);

#endif
