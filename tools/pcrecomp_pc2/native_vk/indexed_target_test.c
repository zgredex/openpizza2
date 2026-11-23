#include "pc2_vk.h"
#include "pc2_sprite_decode.h"

#include <stdio.h>
#include <string.h>

static void expand565(const uint8_t *pixels, uint8_t *rgba, size_t count)
{
    for (size_t i = 0; i < count; ++i) {
        unsigned pixel = pixels[i * 2] | ((unsigned)pixels[i * 2 + 1] << 8);
        rgba[i * 4] = ((pixel >> 11) & 31) * 255 / 31;
        rgba[i * 4 + 1] = ((pixel >> 5) & 63) * 255 / 63;
        rgba[i * 4 + 2] = (pixel & 31) * 255 / 31;
        rgba[i * 4 + 3] = 255;
    }
}

static int verify(FILE *fixture, const char *shader_dir)
{
    char magic[4];
    uint32_t header[5];
    if (fread(magic, 1, sizeof magic, fixture) != sizeof magic ||
        memcmp(magic, "SPR1", sizeof magic) ||
        fread(header, sizeof(uint32_t), 5, fixture) != 5) return 0;
    uint32_t width = header[0], source_height = header[1], size = header[2];
    uint32_t key = header[3], height = header[4];
    if (!width || width > 32 || !height || height > source_height || source_height > 32 ||
        !size || size > width * source_height * 2 || key > 255) return 0;
    size_t count = width * height;
    uint8_t source[2048], palette[512], before[2048], after[2048];
    uint8_t rgba[4096], actual[4096], expected[4096];
    if (fread(source, 1, size, fixture) != size ||
        fread(palette, 1, sizeof palette, fixture) != sizeof palette ||
        fread(before, 2, count, fixture) != count ||
        fread(after, 2, count, fixture) != count || fgetc(fixture) != EOF ||
        !pc2_sprite_decode_indexed_rle(source, size, width, source_height, key, palette,
                                       sizeof palette, 1, rgba, sizeof rgba)) return 0;

    pc2_vk *vk = pc2_vk_create_offscreen(shader_dir);
    if (!vk) return 0;
    pc2_vk_texture *base = pc2_vk_texture_create_rgb565(vk, width, height, before, 0, -1);
    pc2_vk_texture *sprite = pc2_vk_texture_create(vk, width, source_height, rgba, 0);
    pc2_vk_texture *target = pc2_vk_target_create(vk, width, height);
    pc2_vk_texture *result = pc2_vk_target_create(vk, width, height);
    int ok = base && sprite && target && result && pc2_vk_begin_target(vk, target, 0, 0, 0, 1);
    if (ok) {
        pc2_vk_draw(vk, base, 0, 0, width, height, 0, 0, 1, 1, 0, 0, width, height);
        ok = pc2_vk_end(vk) && pc2_vk_begin_target_load(vk, target);
    }
    if (ok) {
        pc2_vk_draw(vk, sprite, 0, 0, width, source_height, 0, 0, 1, 1, 0, 0, width, height);
        ok = pc2_vk_end(vk) && pc2_vk_begin_target(vk, result, 0, 0, 0, 1);
    }
    if (ok) {
        pc2_vk_draw(vk, target, 0, 0, width, height, 0, 0, 1, 1, 0, 0, width, height);
        ok = pc2_vk_end(vk) && pc2_vk_target_read_rgba(vk, result, actual, sizeof actual, 0);
    }
    if (ok) {
        expand565(after, expected, count);
        size_t matching = 0;
        for (size_t i = 0; i < count; ++i)
            matching += memcmp(actual + i * 4, expected + i * 4, 4) == 0;
        printf("Indexed sprite target: %zu/%zu pixels match legacy RGB565\n", matching, count);
        ok = matching == count;
    } else {
        fprintf(stderr, "Vulkan target failed: %s\n", pc2_vk_error(vk));
    }
    pc2_vk_texture_destroy(vk, result);
    pc2_vk_texture_destroy(vk, target);
    pc2_vk_texture_destroy(vk, sprite);
    pc2_vk_texture_destroy(vk, base);
    pc2_vk_destroy(vk);
    return ok;
}

int main(int argc, char **argv)
{
    if (argc != 2 && argc != 3) {
        fprintf(stderr, "usage: %s <sprite-fixture> [shader-dir]\n", argv[0]);
        return 2;
    }
    FILE *fixture = fopen(argv[1], "rb");
    if (!fixture) { perror(argv[1]); return 1; }
    int ok = verify(fixture, argc == 3 ? argv[2] : "shaders");
    fclose(fixture);
    if (!ok) fprintf(stderr, "indexed sprite fixture verification failed\n");
    return !ok;
}
