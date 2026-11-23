#ifdef PC2_CAPTURE
#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "recomp_types.h"
#include "pc2_sprite_decode.h"
#include "pc2_vk.h"

/* The fixture contains the source followed by before/after target crops.
 * Sample indexed RGB565 sprites with optional bottom clipping. */
static FILE *fixture;
static const char *path;
static uint32_t crop;
static int width, height, stride;
static atomic_int captured;
static atomic_int live_claimed;
static _Thread_local int live_owner;
static pc2_vk *live_vk;
static pc2_vk_texture *live_surface;
static uint32_t live_target, live_pixels;
static int live_width, live_height, live_count, live_pending;
static uint8_t live_readback[512 * 32 * 4];
static uint8_t live_source_rgba[32 * 32 * 4];
enum { INDEXED_LIVE = 1, INDEXED_FIXTURE = 2, INDEXED_PUBLISH = 4 };

static void close_live_surface(void)
{
    pc2_vk_texture_destroy(live_vk, live_surface);
    pc2_vk_destroy(live_vk);
}

static int live_draw(const char *shaders, uint32_t target, uint32_t pixels, int pitch,
                     uint32_t source, uint32_t size, uint32_t palette, uint8_t key,
                     int x, int y, int w, int h, int right, int bottom)
{
    if (!shaders || !*shaders || pitch > 512 || bottom > 32) return 0;
    if (!live_owner) {
        if (atomic_exchange_explicit(&live_claimed, 1, memory_order_relaxed)) return 0;
        live_owner = 1;
        live_target = target;
        live_pixels = pixels;
        live_width = pitch;
        live_height = bottom;
        live_vk = pc2_vk_create_offscreen(shaders);
        if (!live_vk) return 0;
        atexit(close_live_surface);
        live_surface = pc2_vk_target_create(live_vk, pitch, bottom);
        pc2_vk_texture *base = pc2_vk_texture_create_rgb565(
            live_vk, pitch, bottom, (const void *)ADDR(pixels), pitch * 2, -1);
        if (!base || !live_surface || !pc2_vk_begin_target(live_vk, live_surface, 0, 0, 0, 1)) {
            pc2_vk_texture_destroy(live_vk, base);
            return 0;
        }
        pc2_vk_draw(live_vk, base, 0, 0, pitch, bottom, 0, 0, 1, 1, 0, 0, pitch, bottom);
        pc2_vk_texture_destroy(live_vk, base);
        if (!pc2_vk_end(live_vk)) return 0;
    }
    if (live_pending || live_count >= 64 || !live_surface || target != live_target ||
        pixels != live_pixels || pitch != live_width || bottom > live_height) return 0;
    if (!pc2_sprite_decode_indexed_rle((const void *)ADDR(source), size, w, h, key,
                                      (const void *)ADDR(palette), 512, 1,
                                      live_source_rgba, sizeof live_source_rgba))
        return 0;
    pc2_vk_texture *sprite = pc2_vk_texture_create(live_vk, w, h, live_source_rgba, 0);
    if (!sprite) return 0;
    int ok = pc2_vk_begin_target_load(live_vk, live_surface);
    if (ok) {
        pc2_vk_draw(live_vk, sprite, x, y, w, h, 0, 0, 1, 1, x, y, right - x, bottom - y);
        ok = pc2_vk_end(live_vk);
    }
    pc2_vk_texture_destroy(live_vk, sprite);
    if (ok) {
        ++live_count;
        live_pending = 1;
    }
    return ok;
}

static void check_live_draw(void)
{
    live_pending = 0;
    if (!pc2_vk_target_read_rgba(live_vk, live_surface, live_readback, sizeof live_readback, 0)) {
        fprintf(stderr, "[vk-live] readback failed: %s\n", pc2_vk_error(live_vk));
        return;
    }
    int count = live_width * live_height;
    int mismatches = 0;
    for (int i = 0; i < count; ++i) {
        uint16_t pixel = MEM16(live_pixels + i * 2);
        const uint8_t *rgba = live_readback + i * 4;
        mismatches += rgba[0] != ((pixel >> 11) & 31) * 255 / 31 ||
                      rgba[1] != ((pixel >> 5) & 63) * 255 / 63 ||
                      rgba[2] != (pixel & 31) * 255 / 31 || rgba[3] != 255;
    }
    fprintf(stderr, "[vk-live] indexed draw %d target %dx%d mismatches=%d/%d\n",
            live_count, live_width, live_height, mismatches, count);
}

/* Publish only the owned draw rectangle before the lifted traversal runs.
 * The traversal preserves its return/flag behavior, with its pixel store
 * suppressed on this path. RGB565 round-trips through the quad target. */
static int publish_live_draw(int x, int y, int source_width, int right, int bottom)
{
    live_pending = 0;
    if (!pc2_vk_target_read_rgba(live_vk, live_surface, live_readback, sizeof live_readback, 0)) {
        fprintf(stderr, "[vk-live] panel publication failed: %s\n", pc2_vk_error(live_vk));
        return 0;
    }
    for (int row = y; row < bottom; ++row) {
        for (int col = x; col < right; ++col) {
            unsigned source_index = (row - y) * source_width + col - x;
            if (!live_source_rgba[source_index * 4 + 3]) continue;
            unsigned index = row * live_width + col;
            const uint8_t *rgba = live_readback + index * 4;
            unsigned r = (rgba[0] * 31 + 127) / 255;
            unsigned g = (rgba[1] * 63 + 127) / 255;
            unsigned b = (rgba[2] * 31 + 127) / 255;
            MEM16(live_pixels + index * 2) = (r << 11) | (g << 5) | b;
        }
    }
    fprintf(stderr, "[vk-live] published indexed draw %d at %d,%d %dx%d\n",
            live_count, x, y, right - x, bottom - y);
    return INDEXED_PUBLISH;
}

static int write_crop(void)
{
    for (int row = 0; row < height; ++row) {
        const void *pixels = (const void *)ADDR(crop + (uint32_t)row * stride * 2);
        if (fwrite(pixels, 2, width, fixture) != (size_t)width) return 0;
    }
    return 1;
}

int pc2_capture_indexed_sprite_before(uint32_t sprite, uint32_t stack)
{
    if (!sprite) return 0;
    const char *output = getenv("PC2_INDEXED_SPRITE_FIXTURE");
    const char *shaders = getenv("PC2_VK_LIVE_INDEXED_SHADERS");
    if ((!output || !*output || atomic_load_explicit(&captured, memory_order_relaxed)) &&
        (!shaders || !*shaders)) return 0;

    uint32_t target = MEM32(stack + 4);
    uint32_t source = MEM32(stack + 8);
    uint32_t palette = MEM32(stack + 12);
    if (!target || !source || !palette || MEM8(sprite + 4) != 3 ||
        MEM8(sprite + 5) != 8 || MEM8(target + 0x18) != 1) return 0;
    if (MEM32(stack + 24) != UINT32_MAX || MEM32(stack + 28) != UINT32_MAX) return 0;

    int source_width = (int16_t)MEM16(sprite + 6);
    int source_height = (int16_t)MEM16(sprite + 8);
    int target_stride = (int32_t)MEM32(target + 0x20);
    int32_t x = MEM32(stack + 16);
    int32_t y = MEM32(stack + 20);
    uint32_t size = MEM32(sprite + 0x18);
    uint32_t key = MEM32(sprite + 0x1c);
    uint32_t pixels = MEM32(target + 0x28);
    if (source_width <= 0 || source_width > 32 || source_height <= 0 || source_height > 32 ||
        target_stride <= 0 || target_stride > 8192 || x < 0 || x > 8192 || y < 0 || y > 8192 ||
        !pixels || !size || size > (uint32_t)(source_width * source_height * 2) || key > 255)
        return 0;
    int32_t left = MEM32(target + 4), right = MEM32(target + 8);
    int32_t top = MEM32(target + 0x0c), bottom = MEM32(target + 0x10);
    if (x < left || x >= right || y < top || y >= bottom || right > target_stride)
        return 0;
    int live = live_draw(shaders, target, pixels, target_stride, source, size, palette, key,
                         x, y, source_width, source_height, right, bottom) ? INDEXED_LIVE : 0;
    const char *publish = getenv("PC2_VK_LIVE_INDEXED_PUBLISH");
    if (live && publish && !strcmp(publish, "1"))
        return publish_live_draw(x, y, source_width, x + source_width < right
                                 ? x + source_width : right, y + source_height < bottom
                                 ? y + source_height : bottom);
    if (x + source_width > right || !output || !*output ||
        atomic_exchange_explicit(&captured, 1, memory_order_relaxed))
        return live;

    path = output;
    width = source_width;
    height = y + source_height > bottom ? bottom - y : source_height;
    stride = target_stride;
    crop = pixels + (y * stride + x) * 2;
    fixture = fopen(path, "wb");
    if (!fixture) {
        perror(path);
        return live;
    }
    const uint32_t header[] = { (uint32_t)width, (uint32_t)source_height, size, key, (uint32_t)height };
    if (fwrite("SPR1", 1, 4, fixture) == 4 &&
        fwrite(header, sizeof(uint32_t), 5, fixture) == 5 &&
        fwrite((const void *)ADDR(source), 1, size, fixture) == size &&
        fwrite((const void *)ADDR(palette), 1, 512, fixture) == 512 &&
        write_crop()) return live | INDEXED_FIXTURE;
    fclose(fixture);
    fixture = NULL;
    remove(path);
    return live;
}

void pc2_capture_indexed_sprite_after(int actions)
{
    if (actions & INDEXED_LIVE) check_live_draw();
    if (!(actions & INDEXED_FIXTURE)) return;
    int ok = write_crop();
    ok = fclose(fixture) == 0 && ok;
    fixture = NULL;
    if (!ok) remove(path);
    else fprintf(stderr, "[draw-source] saved indexed sprite fixture %s\n", path);
}
#endif
