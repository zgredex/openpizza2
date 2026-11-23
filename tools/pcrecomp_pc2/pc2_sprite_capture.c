#ifdef PC2_CAPTURE
#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>

#include "recomp_types.h"

/* The fixture contains the source followed by before/after target crops.
 * Sample indexed RGB565 sprites with optional bottom clipping. */
static FILE *fixture;
static const char *path;
static uint32_t crop;
static int width, height, stride;
static atomic_int captured;

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
    if (atomic_load_explicit(&captured, memory_order_relaxed) || !sprite) return 0;
    const char *output = getenv("PC2_INDEXED_SPRITE_FIXTURE");
    if (!output || !*output) return 0;

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
    if (x < left || x + source_width > right || y < top || y >= bottom ||
        x + source_width > target_stride) return 0;
    if (atomic_exchange_explicit(&captured, 1, memory_order_relaxed)) return 0;

    path = output;
    width = source_width;
    height = y + source_height > bottom ? bottom - y : source_height;
    stride = target_stride;
    crop = pixels + (y * stride + x) * 2;
    fixture = fopen(path, "wb");
    if (!fixture) {
        perror(path);
        return 0;
    }
    const uint32_t header[] = { (uint32_t)width, (uint32_t)source_height, size, key, (uint32_t)height };
    if (fwrite("SPR1", 1, 4, fixture) == 4 &&
        fwrite(header, sizeof(uint32_t), 5, fixture) == 5 &&
        fwrite((const void *)ADDR(source), 1, size, fixture) == size &&
        fwrite((const void *)ADDR(palette), 1, 512, fixture) == 512 &&
        write_crop()) return 1;
    fclose(fixture);
    fixture = NULL;
    remove(path);
    return 0;
}

void pc2_capture_indexed_sprite_after(void)
{
    int ok = write_crop();
    ok = fclose(fixture) == 0 && ok;
    fixture = NULL;
    if (!ok) remove(path);
    else fprintf(stderr, "[draw-source] saved indexed sprite fixture %s\n", path);
}
#endif
