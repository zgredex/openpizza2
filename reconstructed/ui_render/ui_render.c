#include "ui_render.h"

#include <string.h>

bool ui_draw_sprite(RenderSurface *surface, const SpriteAsset *sprite, int32_t x,
                    int32_t y, bool use_hotspot) {
    if (surface == NULL || sprite == NULL || sprite->pixels == NULL) {
        return false;
    }
    if (use_hotspot) {
        x -= sprite->hotspot_x;
        y -= sprite->hotspot_y;
    }
    RgbaSprite rgba = {
        .width = sprite->width,
        .height = sprite->height,
        .pixels = sprite->pixels,
    };
    return render_blit(surface, &rgba, x, y);
}

uint32_t ui_measure_text(const FntInfo *info, const char *text) {
    if (info == NULL || text == NULL) {
        return 0;
    }
    uint32_t width = 0;
    for (const unsigned char *cursor = (const unsigned char *)text; *cursor != 0; cursor++) {
        if (*cursor >= 0x20) {
            width += info->advances[*cursor - 0x20];
        }
    }
    return width;
}

bool ui_draw_text(RenderSurface *surface, const uint8_t *font_data, size_t font_size,
                  const FntInfo *info, int32_t x, int32_t y, const char *text,
                  const uint8_t rgba[4]) {
    if (surface == NULL || font_data == NULL || info == NULL || text == NULL ||
        rgba == NULL) {
        return false;
    }
    int32_t pen_x = x;
    uint8_t coverage[FNT_MAX_COVERAGE];
    for (const unsigned char *cursor = (const unsigned char *)text; *cursor != 0; cursor++) {
        unsigned char code = *cursor;
        if (code < 0x20) {
            continue;
        }
        FntGlyph glyph;
        bool has_glyph = fnt_decode_glyph(font_data, font_size, (char)code, &glyph,
                                          coverage, sizeof(coverage));
        if (has_glyph) {
            for (uint16_t row = 0; row < glyph.height; row++) {
                for (uint16_t column = 0; column < glyph.width; column++) {
                    uint8_t alpha = coverage[(size_t)row * glyph.width + column];
                    if (alpha == 0) {
                        continue;
                    }
                    int32_t target_x = pen_x + glyph.x_offset + column;
                    int32_t target_y = y + glyph.y_offset + row;
                    if (target_x < 0 || target_y < 0 ||
                        target_x >= (int32_t)surface->width ||
                        target_y >= (int32_t)surface->height) {
                        continue;
                    }
                    size_t offset = ((size_t)target_y * surface->width +
                                     (size_t)target_x) * 4;
                    uint32_t source_alpha = (uint32_t)alpha * rgba[3] / 255u;
                    uint8_t *target = surface->pixels + offset;
                    for (int channel = 0; channel < 3; channel++) {
                        target[channel] = (uint8_t)(
                            (rgba[channel] * source_alpha +
                             target[channel] * (255 - source_alpha) + 127) /
                            255);
                    }
                    target[3] = 255;
                }
            }
        }
        pen_x += info->advances[code - 0x20];
    }
    return true;
}
