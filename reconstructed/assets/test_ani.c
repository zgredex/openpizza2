#include "ani.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

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
    if (data != NULL) {
        *length = fread(data, 1, (size_t)size, file);
    }
    fclose(file);
    return data;
}

static size_t opaque_count(const RgbaSprite *sprite) {
    size_t count = 0;
    for (size_t index = 0; index < (size_t)sprite->width * sprite->height; index++) {
        if (sprite->pixels[index * 4 + 3] != 0) {
            count++;
        }
    }
    return count;
}

static void decode_case(const char *path, size_t chunk, uint32_t width,
                        uint32_t height, size_t min_opaque) {
    size_t length = 0;
    uint8_t *data = load_file(path, &length);
    assert(data != NULL);
    AniInfo info;
    assert(ani_read_info(data, length, &info));
    assert(chunk < info.chunk_count);
    size_t capacity = 800u * 600u * 4u;
    uint8_t *pixels = malloc(capacity);
    assert(pixels != NULL);
    RgbaSprite sprite;
    assert(ani_decode_chunk(data, length, chunk, pixels, capacity, &sprite));
    assert(sprite.width == width);
    assert(sprite.height == height);
    assert(opaque_count(&sprite) >= min_opaque);
    assert(!ani_decode_chunk(data, length, info.chunk_count, pixels,
                             capacity, &sprite));
    free(pixels);
    free(data);
}

int main(void) {
    AniInfo info;
    uint8_t bad[4] = {0, 0, 0, 0};
    assert(!ani_read_info(bad, sizeof(bad), &info));
    decode_case("../extracted/sprites/haecksler.ani", 1, 122, 122, 10000);
    decode_case("../extracted/sprites/kakanim1.ani", 3, 29, 30, 800);
    decode_case("../extracted/sprites/kakanim2.ani", 12, 31, 34, 1000);
    decode_case("../extracted/sprites/spideranim.ani", 34, 16, 65, 1000);
    decode_case("../extracted/sprites/tomatenanim.ani", 0, 72, 33, 500);
    puts("ANI sprite-sheet reconstruction: OK");
    return 0;
}
