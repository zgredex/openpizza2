#include "pc2_sprite_decode.h"

#include <string.h>

static unsigned read_le16(const uint8_t *bytes)
{
    return bytes[0] | ((unsigned)bytes[1] << 8);
}

static void write_pixel(uint8_t *rgba, unsigned color, int rgb565, unsigned alpha)
{
    unsigned red = (color >> (rgb565 ? 11 : 10)) & 31;
    unsigned green_max = rgb565 ? 63 : 31;
    unsigned green = (color >> 5) & green_max;
    rgba[0] = (uint8_t)(red * 255 / 31);
    rgba[1] = (uint8_t)(green * 255 / green_max);
    rgba[2] = (uint8_t)((color & 31) * 255 / 31);
    rgba[3] = (uint8_t)alpha;
}

static int output_fits(uint32_t width, uint32_t height, const uint8_t *rgba, size_t size)
{
    uint64_t pixels = (uint64_t)width * height;
    return rgba && pixels && pixels <= SIZE_MAX / 4 && size >= (size_t)pixels * 4;
}

int pc2_sprite_decode_indexed_rle(const void *stream, size_t stream_size,
                                  uint32_t width, uint32_t height, uint8_t key,
                                  const void *palette, size_t palette_size,
                                  int rgb565, uint8_t *rgba, size_t rgba_size)
{
    if (!stream || !palette || palette_size < 512 || !output_fits(width, height, rgba, rgba_size))
        return 0;

    const uint8_t *token = stream;
    const uint8_t *colors = palette;
    for (uint32_t row = 0; row < height; ++row) {
        uint32_t remaining = width;
        while (remaining) {
            if (stream_size == 0) return 0;
            unsigned index = *token++;
            --stream_size;
            if (index == key) {
                if (stream_size == 0) return 0;
                unsigned run = *token++;
                --stream_size;
                if (run == 0 || run > remaining) return 0;
                memset(rgba, 0, (size_t)run * 4);
                rgba += (size_t)run * 4;
                remaining -= run;
            } else {
                write_pixel(rgba, read_le16(colors + index * 2), rgb565, 255);
                rgba += 4;
                --remaining;
            }
        }
    }
    return stream_size == 0;
}

int pc2_sprite_decode_alpha_rle(const void *stream, size_t stream_size,
                                uint32_t width, uint32_t height, uint8_t depth,
                                const void *palette, size_t palette_size,
                                int rgb565, uint8_t *rgba, size_t rgba_size)
{
    if (!stream || !output_fits(width, height, rgba, rgba_size) || (depth != 8 && depth != 16) ||
        (depth == 8 && (!palette || palette_size < 512)))
        return 0;

    const uint8_t *token = stream;
    const uint8_t *colors = palette;
    size_t token_size = depth == 8 ? 2 : 4;
    for (uint32_t row = 0; row < height; ++row) {
        uint32_t remaining = width;
        while (remaining) {
            if (stream_size < token_size) return 0;
            unsigned alpha = token[0];
            unsigned value = token[1];
            if (depth == 16) {
                if (token[0] != 0) return 0;
                alpha = token[1];
                value = read_le16(token + 2);
            }
            token += token_size;
            stream_size -= token_size;
            if (alpha == 0) {
                if (value == 0 || value > remaining) return 0;
                memset(rgba, 0, (size_t)value * 4);
                rgba += (size_t)value * 4;
                remaining -= value;
                continue;
            }
            if (alpha > 60 || (alpha & 3) != 0) return 0;
            unsigned color = depth == 8 ? read_le16(colors + value * 2) : value;
            color &= 0x7fff;
            if (rgb565) color += color & 0x7fe0;
            write_pixel(rgba, color, rgb565, (alpha / 4) * 17);
            rgba += 4;
            --remaining;
        }
    }
    return stream_size == 0;
}
