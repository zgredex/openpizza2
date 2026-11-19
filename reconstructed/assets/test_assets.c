#include "assets.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static uint8_t *load_file(const char *path, size_t *length) {
    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        return NULL;
    }
    if (fseek(file, 0, SEEK_END) != 0) {
        fclose(file);
        return NULL;
    }
    long size = ftell(file);
    if (size <= 0 || fseek(file, 0, SEEK_SET) != 0) {
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

static void test_shipped_sprite(void) {
    size_t length = 0;
    uint8_t *data = load_file("../extracted/sprites/pb24_01.spr", &length);
    assert(data != NULL);
    uint8_t pixels[23 * 19 * 4];
    SpriteAsset sprite;
    assert(spr_decode(data, length, &sprite, pixels, sizeof(pixels)));
    assert(sprite.width == 23);
    assert(sprite.height == 19);
    assert(sprite.canvas_width == 29);
    assert(sprite.canvas_height == 25);
    assert(sprite.bpp == 8);
    assert((sprite.flags & 0x10) != 0);
    bool opaque = false;
    bool transparent = false;
    for (size_t index = 0; index < sizeof(pixels); index += 4) {
        if (pixels[index + 3] != 0) {
            opaque = true;
        } else {
            transparent = true;
        }
    }
    assert(opaque);
    assert(transparent);
    free(data);
}

static void test_shipped_font(void) {
    size_t length = 0;
    uint8_t *data = load_file("../extracted/fonts/timesfont.fnt", &length);
    assert(data != NULL);
    FntInfo info;
    assert(fnt_read_info(data, length, &info));
    assert(info.line_height == 23);
    assert(info.max_width == 18);
    assert(info.advances['A' - 0x20] == 16);

    FntGlyph glyph;
    uint8_t coverage[FNT_MAX_COVERAGE];
    assert(fnt_decode_glyph(data, length, 'A', &glyph, coverage, sizeof(coverage)));
    assert(glyph.width == 16);
    assert(glyph.height == 14);
    assert(glyph.x_offset == 0);
    assert(glyph.y_offset == 4);
    assert(glyph.coverage_length == 16 * 14);
    bool ink = false;
    for (size_t index = 0; index < glyph.coverage_length; index++) {
        if (coverage[index] != 0) {
            ink = true;
            break;
        }
    }
    assert(ink);
    free(data);
}

static void test_rejects_truncated(void) {
    uint8_t tiny[4] = {0};
    SpriteAsset sprite;
    FntInfo info;
    FntGlyph glyph;
    uint8_t coverage[4];
    assert(!spr_decode(tiny, sizeof(tiny), &sprite, coverage, sizeof(coverage)));
    assert(!fnt_read_info(tiny, sizeof(tiny), &info));
    assert(!fnt_decode_glyph(tiny, sizeof(tiny), 'A', &glyph, coverage, sizeof(coverage)));
}

int main(void) {
    test_shipped_sprite();
    test_shipped_font();
    test_rejects_truncated();
    puts("SPR/FNT asset reconstruction: OK");
    return 0;
}
