#include "render_state.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

static void test_tga_decode_bottom_origin(void) {
    uint8_t tga[18 + 2 * 2 * 3] = {0};
    tga[2] = 2;             /* uncompressed true-color */
    tga[12] = 2;            /* width low */
    tga[14] = 2;            /* height low */
    tga[16] = 24;           /* bpp */
    /* bottom row first: red, green; top row: blue, white */
    const uint8_t pixels[12] = {
        0, 0, 255, 0, 255, 0,
        255, 0, 0, 255, 255, 255,
    };
    memcpy(tga + 18, pixels, sizeof(pixels));

    uint8_t rgba[2 * 2 * 4];
    uint32_t width = 0;
    uint32_t height = 0;
    assert(tga_decode_rgba(tga, sizeof(tga), rgba, sizeof(rgba), &width, &height));
    assert(width == 2);
    assert(height == 2);
    assert(rgba[0] == 0 && rgba[1] == 0 && rgba[2] == 255 && rgba[3] == 255);
    assert(rgba[4] == 255 && rgba[5] == 255 && rgba[6] == 255);
    assert(rgba[8] == 255 && rgba[9] == 0 && rgba[10] == 0);
    assert(rgba[12] == 0 && rgba[13] == 255 && rgba[14] == 0);
}

static void test_surface_fill_and_blit(void) {
    uint8_t frame[4 * 4 * 4];
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, sizeof(frame), 4, 4));
    const uint8_t black[4] = {0, 0, 0, 255};
    render_clear(&surface, black);
    assert(frame[0] == 0 && frame[3] == 255);

    const uint8_t red[4] = {255, 0, 0, 255};
    render_fill_rect(&surface, 1, 1, 2, 2, red);
    size_t offset = (1 * 4 + 1) * 4;
    assert(frame[offset] == 255 && frame[offset + 3] == 255);
    offset = (2 * 4 + 2) * 4;
    assert(frame[offset] == 255);

    const uint8_t sprite_pixels[2 * 2 * 4] = {
        0, 255, 0, 255, 0, 0, 255, 255,
        255, 255, 255, 255, 0, 0, 0, 255,
    };
    RgbaSprite sprite = {2, 2, sprite_pixels};
    assert(render_blit(&surface, &sprite, 2, 2));
    offset = (2 * 4 + 2) * 4;
    assert(frame[offset] == 0 && frame[offset + 1] == 255);
    offset = (3 * 4 + 3) * 4;
    assert(frame[offset] == 0 && frame[offset + 1] == 0 && frame[offset + 2] == 0);

    /* Clip a blit that starts off-surface. */
    assert(render_blit(&surface, &sprite, -1, -1));
    offset = 0;
    assert(frame[offset] == 0 && frame[offset + 1] == 0 && frame[offset + 2] == 0);
}

static void test_alpha_and_rejects(void) {
    uint8_t frame[2 * 2 * 4];
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, sizeof(frame), 2, 2));
    const uint8_t black[4] = {0, 0, 0, 255};
    render_clear(&surface, black);

    const uint8_t half_red[4] = {255, 0, 0, 128};
    RgbaSprite sprite = {1, 1, half_red};
    assert(render_blit(&surface, &sprite, 0, 0));
    assert(frame[0] == 128 && frame[1] == 0 && frame[2] == 0 && frame[3] == 255);

    assert(!render_surface_init(&surface, frame, 3, 2, 2));
    uint8_t tga[18] = {0};
    tga[2] = 2;
    tga[12] = 1;
    tga[14] = 1;
    tga[16] = 24;
    assert(!tga_decode_rgba(tga, sizeof(tga), frame, sizeof(frame), NULL, NULL));
}

int main(void) {
    test_tga_decode_bottom_origin();
    test_surface_fill_and_blit();
    test_alpha_and_rejects();
    puts("render state reconstruction: OK");
    return 0;
}
