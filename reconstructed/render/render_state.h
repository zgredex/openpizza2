#ifndef PC2_RECONSTRUCTED_RENDER_STATE_H
#define PC2_RECONSTRUCTED_RENDER_STATE_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct RenderSurface {
    uint32_t width;
    uint32_t height;
    uint8_t *pixels;
    size_t capacity;
} RenderSurface;

typedef struct RgbaSprite {
    uint32_t width;
    uint32_t height;
    const uint8_t *pixels;
} RgbaSprite;

/*
 * Small CPU render target reconstructed from the renderer/surface paths
 * (FullscreenImage_Load, Surface_LockPrimary, Gfx_BlitRectList) and the TGA
 * decoding rules documented in crates/assets/src/tga.rs. Pixels are RGBA8,
 * row-major, top-left origin.
 */
bool render_surface_init(RenderSurface *surface, uint8_t *buffer, size_t capacity,
                         uint32_t width, uint32_t height);
void render_clear(RenderSurface *surface, const uint8_t rgba[4]);
void render_fill_rect(RenderSurface *surface, int32_t x, int32_t y, int32_t w,
                      int32_t h, const uint8_t rgba[4]);
bool render_blit(RenderSurface *surface, const RgbaSprite *sprite, int32_t x,
                 int32_t y);

bool tga_decode_rgba(const uint8_t *data, size_t length, uint8_t *output,
                     size_t capacity, uint32_t *width, uint32_t *height);

#endif
