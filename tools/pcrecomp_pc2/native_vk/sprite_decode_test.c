#include "pc2_sprite_decode.h"

#include <stdio.h>
#include <string.h>

#define CHECK(condition) do { \
    if (!(condition)) { \
        fprintf(stderr, "sprite decoder check failed at line %d\n", __LINE__); \
        return 1; \
    } \
} while (0)

int main(void)
{
    uint8_t pixels[24];
    uint8_t palette[512] = {0};
    /* The transparent index need not be 255. */
    const uint8_t indexed[] = {0xff, 0xe6, 2, 0xe6, 1, 1, 0xff};
    const uint8_t expected[] = {
        255, 0, 0, 255,  0, 0, 0, 0,      0, 0, 0, 0,
        0, 0, 0, 0,      0, 255, 0, 255,  255, 0, 0, 255,
    };
    palette[511] = 0xf8;  /* RGB565 red at 255. */
    palette[2] = 0xe0; palette[3] = 0x07;
    CHECK(pc2_sprite_decode_indexed_rle(indexed, sizeof indexed, 3, 2, 0xe6,
                                        palette, sizeof palette, 1, pixels, sizeof pixels));
    CHECK(memcmp(pixels, expected, sizeof pixels) == 0);
    palette[511] = 0x7c;  /* Same colors in an RGB555 target palette. */
    palette[2] = 0xe0; palette[3] = 0x03;
    CHECK(pc2_sprite_decode_indexed_rle(indexed, sizeof indexed, 3, 2, 0xe6,
                                        palette, sizeof palette, 0, pixels, sizeof pixels));
    CHECK(memcmp(pixels, expected, sizeof pixels) == 0);

    const uint8_t invalid[][3] = {{0xe6, 0, 1}, {0xe6, 4, 1}, {1, 1, 0xe6}, {0xe6, 3, 1}};
    for (size_t i = 0; i < sizeof invalid / sizeof *invalid; ++i)
        CHECK(!pc2_sprite_decode_indexed_rle(invalid[i], sizeof invalid[i], 3, 1, 0xe6,
                                             palette, sizeof palette, 1, pixels, sizeof pixels));
    CHECK(!pc2_sprite_decode_indexed_rle(indexed, sizeof indexed, UINT32_MAX, UINT32_MAX,
                                         0xe6, palette, sizeof palette, 1, pixels, sizeof pixels));
    CHECK(!pc2_sprite_decode_indexed_rle(indexed, sizeof indexed, 3, 2, 0xe6,
                                         palette, sizeof palette - 1, 1, pixels, sizeof pixels));
    CHECK(!pc2_sprite_decode_indexed_rle(indexed, sizeof indexed, 3, 2, 0xe6,
                                         palette, sizeof palette, 1, pixels, sizeof pixels - 1));

    const uint8_t alpha8[] = {0, 1, 60, 1, 20, 0xff};
    const uint8_t expected_alpha8[] = {0, 0, 0, 0, 0, 250, 0, 255, 255, 0, 0, 85};
    CHECK(pc2_sprite_decode_alpha_rle(alpha8, sizeof alpha8, 3, 1, 8,
                                      palette, sizeof palette, 1, pixels, sizeof pixels));
    CHECK(memcmp(pixels, expected_alpha8, sizeof expected_alpha8) == 0);
    const uint8_t alpha16[] = {0, 60, 0x1f, 0x80, 0, 0, 1, 0, 0, 56, 0, 0x7c};
    const uint8_t expected_alpha16[] = {0, 0, 255, 255, 0, 0, 0, 0, 255, 0, 0, 238};
    CHECK(pc2_sprite_decode_alpha_rle(alpha16, sizeof alpha16, 3, 1, 16,
                                      NULL, 0, 0, pixels, sizeof pixels));
    CHECK(memcmp(pixels, expected_alpha16, sizeof expected_alpha16) == 0);
    CHECK(!pc2_sprite_decode_alpha_rle(alpha16, sizeof alpha16 - 1, 3, 1, 16,
                                       NULL, 0, 0, pixels, sizeof pixels));
    const uint8_t invalid_alpha[] = {0, 3, 0, 0};
    CHECK(!pc2_sprite_decode_alpha_rle(invalid_alpha, sizeof invalid_alpha, 1, 1, 16,
                                       NULL, 0, 0, pixels, sizeof pixels));
    puts("indexed and alpha sprite decoder checks passed");
    return 0;
}
