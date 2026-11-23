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
struct indexed_target {
    pc2_vk_texture *texture;
    uint32_t guest_target, pixels;
    int width, height, draw_count;
    int synchronized;
    uint16_t shadow[512 * 32];
};
static struct indexed_target live_targets[16];
static struct indexed_target *live_active;
static int live_pending;
static uint8_t live_readback[512 * 32 * 4];
static uint8_t live_source_rgba[32 * 32 * 4];
struct word_fill {
    uint32_t pixels, words;
    uint16_t color;
};
static _Thread_local struct word_fill recent_fills[16];
static _Thread_local unsigned fill_cursor;
enum { INDEXED_LIVE = 1, INDEXED_FIXTURE = 2, INDEXED_PUBLISH = 4 };
enum { MENU_ALPHA = 8 };
static int menu_alpha_before(uint32_t sprite, uint32_t stack);
static void menu_alpha_after(void);

void pc2_capture_word_fill(uint32_t pixels, uint32_t color, uint32_t words)
{
    recent_fills[fill_cursor++ % 16] = (struct word_fill){pixels, words, (uint16_t)color};
}

static int recorded_clear(const struct indexed_target *slot, const uint16_t *pixels, uint16_t *color)
{
    unsigned count = (unsigned)slot->width * slot->height;
    for (unsigned i = 0; i < 16; ++i) {
        const struct word_fill *fill = &recent_fills[(fill_cursor - 1 - i) % 16];
        if (fill->pixels != slot->pixels) continue;
        if (fill->words < count) return 0;
        /* The clear may have been followed by an unported draw. */
        for (unsigned j = 0; j < count; ++j)
            if (pixels[j] != fill->color) return 0;
        *color = fill->color;
        return 1;
    }
    return 0;
}
static void close_live_surface(void)
{
    for (size_t i = 0; i < sizeof live_targets / sizeof live_targets[0]; ++i)
        pc2_vk_texture_destroy(live_vk, live_targets[i].texture);
    pc2_vk_destroy(live_vk);
}

static size_t surface_bytes(const struct indexed_target *slot)
{
    return (size_t)slot->width * slot->height * sizeof(uint16_t);
}

static void remember_surface(struct indexed_target *slot)
{
    memcpy(slot->shadow, (const void *)ADDR(slot->pixels), surface_bytes(slot));
    slot->synchronized = 1;
}

static int sync_surface(struct indexed_target *slot)
{
    const uint16_t *pixels = (const uint16_t *)ADDR(slot->pixels);
    int changed = 0, cleared = 0;
    if (slot->synchronized) {
        if (!memcmp(slot->shadow, pixels, surface_bytes(slot))) return 1;
        for (int i = 0; i < slot->width * slot->height; ++i) {
            if (slot->shadow[i] == pixels[i]) continue;
            ++changed;
            cleared += pixels[i] == 0;
        }
    }
    uint16_t color;
    int ok;
    if (recorded_clear(slot, pixels, &color)) {
        ok = pc2_vk_begin_target(live_vk, slot->texture,
                 (((color >> 11) & 31) * 255 / 31) / 255.0f,
                 (((color >> 5) & 63) * 255 / 63) / 255.0f,
                 ((color & 31) * 255 / 31) / 255.0f, 1) && pc2_vk_end(live_vk);
        if (ok)
            fprintf(stderr, "[vk-live] cleared target %dx%d color=%04X surface=%08X\n",
                    slot->width, slot->height, color, slot->guest_target);
    } else {
        pc2_vk_texture *base = pc2_vk_texture_create_rgb565(
            live_vk, slot->width, slot->height, pixels, slot->width * 2, -1);
        ok = base && pc2_vk_begin_target(live_vk, slot->texture, 0, 0, 0, 1);
        if (ok) {
            pc2_vk_draw(live_vk, base, 0, 0, slot->width, slot->height, 0, 0, 1, 1,
                        0, 0, slot->width, slot->height);
            ok = pc2_vk_end(live_vk);
        }
        pc2_vk_texture_destroy(live_vk, base);
    }
    if (!ok) {
        slot->synchronized = 0;
        return 0;
    }
    if (changed)
        fprintf(stderr, "[vk-live] before draw %d target %dx%d external changes=%d zeroed=%d surface=%08X pixels=%08X\n",
                slot->draw_count + 1, slot->width, slot->height,
                changed, cleared, slot->guest_target, slot->pixels);
    remember_surface(slot);
    return 1;
}

static struct indexed_target *live_target_for(uint32_t target, uint32_t pixels,
                                               int pitch, int bottom)
{
    for (size_t i = 0; i < sizeof live_targets / sizeof live_targets[0]; ++i) {
        struct indexed_target *slot = &live_targets[i];
        if (slot->texture) {
            if (slot->guest_target == target && slot->pixels == pixels &&
                slot->width == pitch && slot->height >= bottom)
                return slot;
            continue;
        }

        pc2_vk_texture *texture = pc2_vk_target_create(live_vk, pitch, bottom);
        if (!texture) return NULL;
        slot->texture = texture;
        slot->guest_target = target;
        slot->pixels = pixels;
        slot->width = pitch;
        slot->height = bottom;
        return slot;
    }
    return NULL;
}

static int live_draw(const char *shaders, uint32_t target, uint32_t pixels, int pitch,
                     uint32_t source, uint32_t size, uint32_t palette, uint8_t key,
                     int x, int y, int w, int h, int right, int bottom)
{
    if (!shaders || !*shaders || pitch > 512 || bottom > 32) return 0;
    if (!live_owner) {
        if (atomic_exchange_explicit(&live_claimed, 1, memory_order_relaxed)) return 0;
        live_owner = 1;
        live_vk = pc2_vk_create_offscreen(shaders);
        if (!live_vk) return 0;
        atexit(close_live_surface);
    }
    if (!live_vk || live_pending) return 0;
    struct indexed_target *surface = live_target_for(target, pixels, pitch, bottom);
    if (!surface || surface->draw_count >= 64 || !sync_surface(surface)) return 0;
    if (!pc2_sprite_decode_indexed_rle((const void *)ADDR(source), size, w, h, key,
                                      (const void *)ADDR(palette), 512, 1,
                                      live_source_rgba, sizeof live_source_rgba))
        return 0;
    pc2_vk_texture *sprite = pc2_vk_texture_create(live_vk, w, h, live_source_rgba, 0);
    if (!sprite) return 0;
    int ok = pc2_vk_begin_target_load(live_vk, surface->texture);
    if (ok) {
        surface->synchronized = 0;
        pc2_vk_draw(live_vk, sprite, x, y, w, h, 0, 0, 1, 1, x, y, right - x, bottom - y);
        ok = pc2_vk_end(live_vk);
    }
    pc2_vk_texture_destroy(live_vk, sprite);
    if (ok) {
        ++surface->draw_count;
        live_active = surface;
        live_pending = 1;
    }
    return ok;
}

static void check_live_draw(void)
{
    live_pending = 0;
    if (!pc2_vk_target_read_rgba(live_vk, live_active->texture, live_readback, sizeof live_readback, 0)) {
        fprintf(stderr, "[vk-live] readback failed: %s\n", pc2_vk_error(live_vk));
        return;
    }
    int count = live_active->width * live_active->height;
    int mismatches = 0;
    for (int i = 0; i < count; ++i) {
        uint16_t pixel = MEM16(live_active->pixels + i * 2);
        const uint8_t *rgba = live_readback + i * 4;
        mismatches += rgba[0] != ((pixel >> 11) & 31) * 255 / 31 ||
                      rgba[1] != ((pixel >> 5) & 63) * 255 / 63 ||
                      rgba[2] != (pixel & 31) * 255 / 31 || rgba[3] != 255;
    }
    fprintf(stderr, "[vk-live] indexed draw %d target %dx%d mismatches=%d/%d surface=%08X\n",
            live_active->draw_count, live_active->width, live_active->height, mismatches, count, live_active->guest_target);
    if (!mismatches) remember_surface(live_active);
}

/* Publish only the owned draw rectangle before the lifted traversal runs.
 * The traversal preserves its return/flag behavior, with its pixel store
 * suppressed on this path. RGB565 round-trips through the quad target. */
static int publish_live_draw(int x, int y, int source_width, int right, int bottom)
{
    live_pending = 0;
    if (!pc2_vk_target_read_rgba(live_vk, live_active->texture, live_readback, sizeof live_readback, 0)) {
        fprintf(stderr, "[vk-live] panel publication failed: %s\n", pc2_vk_error(live_vk));
        return 0;
    }
    for (int row = y; row < bottom; ++row) {
        for (int col = x; col < right; ++col) {
            unsigned source_index = (row - y) * source_width + col - x;
            if (!live_source_rgba[source_index * 4 + 3]) continue;
            unsigned index = row * live_active->width + col;
            const uint8_t *rgba = live_readback + index * 4;
            unsigned r = (rgba[0] * 31 + 127) / 255;
            unsigned g = (rgba[1] * 63 + 127) / 255;
            unsigned b = (rgba[2] * 31 + 127) / 255;
            MEM16(live_active->pixels + index * 2) = (r << 11) | (g << 5) | b;
        }
    }
    fprintf(stderr, "[vk-live] published indexed draw %d at %d,%d %dx%d surface=%08X\n",
            live_active->draw_count, x, y, right - x, bottom - y, live_active->guest_target);
    remember_surface(live_active);
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
    if (menu_alpha_before(sprite, stack)) return MENU_ALPHA;
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
    const char *publish = getenv("PC2_VK_LIVE_INDEXED_PUBLISH");
    int publishing = publish && !strcmp(publish, "1");
    int live = live_draw(shaders, target, pixels, target_stride, source, size, palette, key,
                         x, y, source_width, source_height, right, bottom)
             ? INDEXED_LIVE : 0;
    if (live && publishing)
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
    if (actions & MENU_ALPHA) menu_alpha_after();
    if (actions & INDEXED_LIVE) check_live_draw();
    if (!(actions & INDEXED_FIXTURE)) return;
    int ok = write_crop();
    ok = fclose(fixture) == 0 && ok;
    fixture = NULL;
    if (!ok) remove(path);
    else fprintf(stderr, "[draw-source] saved indexed sprite fixture %s\n", path);
}

static atomic_int menu_bitmap_claimed;
static pc2_vk *menu_vk;
static pc2_vk_texture *menu_target;
static pc2_vk_texture *menu_scratch;
static pc2_vk_texture *menu_blend_table;
static uint32_t menu_pixels;
static uint32_t menu_renderer;
static _Thread_local int menu_owner;
static uint8_t menu_readback[800 * 600 * 4];
static uint8_t menu_alpha_source[800 * 600 * 4];
static int alpha_draws, alpha_x, alpha_y, alpha_w, alpha_h;
static int alpha_left, alpha_top, alpha_right, alpha_bottom;

static void close_menu_target(void)
{
    pc2_vk_texture_destroy(menu_vk, menu_target);
    pc2_vk_texture_destroy(menu_vk, menu_scratch);
    pc2_vk_texture_destroy(menu_vk, menu_blend_table);
    pc2_vk_destroy(menu_vk);
}

int pc2_menu_bitmap_before(uint32_t bitmap, uint32_t stack)
{
    const char *shaders = getenv("PC2_VK_MENU_BITMAP_SHADERS");
    if (!shaders || !*shaders || atomic_load(&menu_bitmap_claimed) ||
        MEM32(0x0057C5B8u) != 21 || MEM32(0x0056386Cu) || !bitmap ||
        MEM8(bitmap + 0x10) != 16)
        return 0;

    uint32_t target = MEM32(stack + 4), source = MEM32(bitmap + 0x18);
    if (!target || !source || MEM32(bitmap + 4) != 800 || MEM32(bitmap + 8) != 600 ||
        MEM32(stack + 8) || MEM32(stack + 12) || (int32_t)MEM32(stack + 16) >= 0 ||
        MEM32(stack + 24) || MEM32(stack + 28) ||
        MEM32(target + 4) || MEM32(target + 8) != 800 || MEM32(target + 0x0c) ||
        MEM32(target + 0x10) != 600 || MEM32(target + 0x20) != 800 ||
        !MEM32(target + 0x28))
        return 0;

    if (atomic_exchange(&menu_bitmap_claimed, 1)) return 0;
    menu_vk = pc2_vk_create_offscreen(shaders);
    if (!menu_vk) return 0;
    atexit(close_menu_target);
    menu_target = pc2_vk_target_create(menu_vk, 800, 600);
    pc2_vk_texture *image = pc2_vk_texture_create_rgb565(
        menu_vk, 800, 600, (const void *)ADDR(source), 0, -1);
    int ok = image && menu_target && pc2_vk_begin_target(menu_vk, menu_target, 0, 0, 0, 1);
    if (ok) {
        pc2_vk_draw(menu_vk, image, 0, 0, 800, 600, 0, 0, 1, 1, 0, 0, 800, 600);
        ok = pc2_vk_end(menu_vk);
    }
    pc2_vk_texture_destroy(menu_vk, image);
    menu_pixels = MEM32(target + 0x28);
    if (ok) {
        menu_renderer = target;
        menu_owner = 1;
    }
    return ok;
}

void pc2_menu_bitmap_after(void)
{
    if (!pc2_vk_target_read_rgba(menu_vk, menu_target, menu_readback, sizeof menu_readback, 0)) {
        fprintf(stderr, "[vk-menu] bitmap readback failed: %s\n", pc2_vk_error(menu_vk));
        return;
    }
    unsigned mismatches = 0;
    for (unsigned i = 0; i < 800 * 600; ++i) {
        uint16_t pixel = MEM16(menu_pixels + i * 2);
        const uint8_t *rgba = menu_readback + i * 4;
        mismatches += rgba[0] != ((pixel >> 11) & 31) * 255 / 31 ||
                      rgba[1] != ((pixel >> 5) & 63) * 255 / 63 ||
                      rgba[2] != (pixel & 31) * 255 / 31 || rgba[3] != 255;
    }
    fprintf(stderr, "[vk-menu] bitmap mismatches=%u/480000\n", mismatches);
}

static int menu_alpha_before(uint32_t sprite, uint32_t stack)
{
    if (!menu_owner || alpha_draws >= 32 || MEM32(0x0057C5B8u) != 21 ||
        MEM32(0x0056386Cu) || MEM32(stack + 4) != menu_renderer ||
        MEM32(menu_renderer + 0x28) != menu_pixels ||
        MEM8(sprite + 4) != 0x17 || MEM8(sprite + 5) != 8 ||
        MEM32(stack + 24) != UINT32_MAX || MEM32(stack + 28) != UINT32_MAX)
        return 0;
    uint32_t source = MEM32(stack + 8), palette = MEM32(stack + 12);
    uint32_t size = MEM32(sprite + 0x18);
    int w = (int16_t)MEM16(sprite + 6), h = (int16_t)MEM16(sprite + 8);
    int32_t x = MEM32(stack + 16), y = MEM32(stack + 20);
    if (!source || !palette || w <= 0 || w > 800 || h <= 0 || h > 600 ||
        !size || size > (uint32_t)(w * h * 2) ||
        x < -1600 || x > 1600 || y < -1200 || y > 1200)
        return 0;
    x += (int16_t)MEM16(sprite + 10);
    y += (int16_t)MEM16(sprite + 12);
    int32_t left = MEM32(menu_renderer + 4), right = MEM32(menu_renderer + 8);
    int32_t top = MEM32(menu_renderer + 0x0c), bottom = MEM32(menu_renderer + 0x10);
    if (left < 0 || top < 0 || right > 800 || bottom > 600 ||
        left >= right || top >= bottom || x >= right || y >= bottom ||
        x + w <= left || y + h <= top)
        return 0;
    if (!pc2_sprite_decode_alpha_rle((const void *)ADDR(source), size, w, h, 8,
                                     (const void *)ADDR(palette), 512, 1,
                                     menu_alpha_source, sizeof menu_alpha_source))
        return 0;
    if (!menu_scratch) menu_scratch = pc2_vk_target_create(menu_vk, 800, 600);
    if (!menu_blend_table) {
        uint8_t table[64 * 16 * 4] = {0};
        for (unsigned i = 0; i < 64 * 16; ++i)
            table[i * 4] = (uint8_t)((int8_t)MEM8(0x00584518u + i * 4) + 128);
        menu_blend_table = pc2_vk_texture_create(menu_vk, 64, 16, table, 0);
    }
    if (!menu_scratch || !menu_blend_table) return 0;
    pc2_vk_texture *texture = pc2_vk_texture_create(menu_vk, w, h, menu_alpha_source, 0);
    if (!texture) return 0;
    int ok = pc2_vk_begin_target(menu_vk, menu_scratch, 0, 0, 0, 1);
    if (ok) {
        pc2_vk_draw(menu_vk, menu_target, 0, 0, 800, 600, 0, 0, 1, 1, 0, 0, 800, 600);
        int drawn = pc2_vk_draw_legacy_blend(menu_vk, texture, menu_target, menu_blend_table,
                                              x, y, w, h, left, top, right - left, bottom - top);
        ok = pc2_vk_end(menu_vk) && drawn;
    }
    pc2_vk_texture_destroy(menu_vk, texture);
    if (!ok) return 0;
    pc2_vk_texture *previous = menu_target;
    menu_target = menu_scratch;
    menu_scratch = previous;
    alpha_x = x; alpha_y = y; alpha_w = w; alpha_h = h;
    alpha_left = left > x ? left : x;
    alpha_top = top > y ? top : y;
    alpha_right = right < x + w ? right : x + w;
    alpha_bottom = bottom < y + h ? bottom : y + h;
    ++alpha_draws;
    return 1;
}

static void menu_alpha_after(void)
{
    if (!pc2_vk_target_read_rgba(menu_vk, menu_target, menu_readback, sizeof menu_readback, 0)) {
        fprintf(stderr, "[vk-menu] alpha readback failed: %s\n", pc2_vk_error(menu_vk));
        return;
    }
    unsigned compared = 0, mismatches = 0, packed_mismatches = 0, partial = 0;
    for (int y = alpha_top; y < alpha_bottom; ++y) {
        for (int x = alpha_left; x < alpha_right; ++x) {
            unsigned offset = ((y - alpha_y) * alpha_w + x - alpha_x) * 4;
            unsigned opacity = menu_alpha_source[offset + 3];
            if (!opacity) continue;
            unsigned index = y * 800 + x;
            uint16_t pixel = MEM16(menu_pixels + index * 2);
            const uint8_t *rgba = menu_readback + index * 4;
            ++compared;
            partial += opacity != 255;
            unsigned r = (rgba[0] * 31 + 127) / 255;
            unsigned g = (rgba[1] * 63 + 127) / 255;
            unsigned b = (rgba[2] * 31 + 127) / 255;
            packed_mismatches += ((r << 11) | (g << 5) | b) != pixel;
            mismatches += rgba[0] != ((pixel >> 11) & 31) * 255 / 31 ||
                          rgba[1] != ((pixel >> 5) & 63) * 255 / 63 ||
                          rgba[2] != (pixel & 31) * 255 / 31 || rgba[3] != 255;
        }
    }
    fprintf(stderr, "[vk-menu] alpha draw %d %dx%d mismatches=%u/%u rgb565=%u partial=%u\n",
            alpha_draws, alpha_w, alpha_h, mismatches, compared, packed_mismatches, partial);
}
#endif
