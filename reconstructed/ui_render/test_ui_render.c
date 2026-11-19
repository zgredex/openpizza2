#include "ui_render.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static uint8_t *load_file(const char *path, size_t *length) {
    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    if (size <= 0) {
        fclose(file);
        return NULL;
    }
    uint8_t *data = malloc((size_t)size);
    if (data == NULL) {
        fclose(file);
        return NULL;
    }
    if (fread(data, 1, (size_t)size, file) != (size_t)size) {
        free(data);
        fclose(file);
        return NULL;
    }
    fclose(file);
    *length = (size_t)size;
    return data;
}

static void test_sprite_and_text_composition(void) {
    size_t sprite_size = 0;
    uint8_t *sprite_data = load_file("../extracted/sprites/pb24_01.spr", &sprite_size);
    size_t font_size = 0;
    uint8_t *font_data = load_file("../extracted/fonts/timesfont.fnt", &font_size);
    assert(sprite_data != NULL);
    assert(font_data != NULL);

    uint8_t sprite_pixels[64 * 64 * 4];
    SpriteAsset sprite;
    assert(spr_decode(sprite_data, sprite_size, &sprite, sprite_pixels,
                      sizeof(sprite_pixels)));
    FntInfo font;
    assert(fnt_read_info(font_data, font_size, &font));

    uint8_t frame[64 * 64 * 4];
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, sizeof(frame), 64, 64));
    const uint8_t white[4] = {255, 255, 255, 255};
    const uint8_t black[4] = {0, 0, 0, 255};
    render_clear(&surface, white);
    assert(ui_draw_sprite(&surface, &sprite, 4, 4, false));

    bool sprite_ink = false;
    for (size_t index = 0; index < sizeof(frame); index += 4) {
        if (frame[index] != 255 || frame[index + 1] != 255 || frame[index + 2] != 255) {
            sprite_ink = true;
            break;
        }
    }
    assert(sprite_ink);

    assert(ui_measure_text(&font, "Start new game") > 100);
    assert(ui_draw_text(&surface, font_data, font_size, &font, 2, 2, "A", black));
    bool text_ink = false;
    for (uint32_t y = 2; y < 24; y++) {
        for (uint32_t x = 2; x < 24; x++) {
            size_t offset = ((size_t)y * 64 + x) * 4;
            if (frame[offset] < 255) {
                text_ink = true;
            }
        }
    }
    assert(text_ink);

    free(sprite_data);
    free(font_data);
}

static void test_clipping_and_hotspot(void) {
    uint8_t sprite_pixels[2 * 2 * 4] = {
        255, 0, 0, 255, 0, 255, 0, 255,
        0, 0, 255, 255, 255, 255, 255, 255,
    };
    SpriteAsset sprite = {
        .width = 2,
        .height = 2,
        .canvas_width = 2,
        .canvas_height = 2,
        .hotspot_x = 1,
        .hotspot_y = 1,
        .bpp = 32,
        .flags = 0,
        .pixels = sprite_pixels,
        .pixel_capacity = sizeof(sprite_pixels),
    };
    uint8_t frame[4 * 4 * 4];
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, sizeof(frame), 4, 4));
    const uint8_t black[4] = {0, 0, 0, 255};
    render_clear(&surface, black);
    assert(ui_draw_sprite(&surface, &sprite, 0, 0, true));
    size_t offset = 0;
    assert(frame[offset] == 255 && frame[offset + 1] == 255 && frame[offset + 2] == 255);
}

int main(void) {
    test_sprite_and_text_composition();
    test_clipping_and_hotspot();
    puts("UI render reconstruction: OK");
    return 0;
}
