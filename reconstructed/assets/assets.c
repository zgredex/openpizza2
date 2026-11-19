#include "assets.h"

#include <string.h>

#define SPR_HEADER_SIZE 0x21u
#define SPR_PALETTE_SIZE 0x300u

static uint16_t read_u16(const uint8_t *data) {
    return (uint16_t)data[0] | ((uint16_t)data[1] << 8);
}

static uint32_t read_u32(const uint8_t *data) {
    return (uint32_t)data[0] | ((uint32_t)data[1] << 8) |
           ((uint32_t)data[2] << 16) | ((uint32_t)data[3] << 24);
}

static uint8_t alpha8(uint8_t alpha) {
    if (alpha >= 0x3c) {
        return 255;
    }
    return (uint8_t)((uint32_t)alpha * 255u / 0x3c);
}

static void rgb555(uint16_t value, uint8_t rgba[4]) {
    rgba[0] = (uint8_t)(((value >> 10) & 31u) * 255u / 31u);
    rgba[1] = (uint8_t)(((value >> 5) & 31u) * 255u / 31u);
    rgba[2] = (uint8_t)((value & 31u) * 255u / 31u);
    rgba[3] = 255;
}

static void palette_color(const uint8_t *palette, uint8_t index, uint8_t rgba[4]) {
    size_t base = (size_t)index * 3;
    rgba[0] = palette[base + 2];
    rgba[1] = palette[base + 1];
    rgba[2] = palette[base];
    rgba[3] = 255;
}

static void put_pixel(uint8_t *pixels, uint32_t width, uint32_t height, uint32_t x,
                      uint32_t y, const uint8_t rgba[4]) {
    if (x >= width || y >= height) {
        return;
    }
    size_t offset = ((size_t)y * width + x) * 4;
    memcpy(pixels + offset, rgba, 4);
}

bool spr_decode(const uint8_t *data, size_t length, SpriteAsset *sprite,
                uint8_t *pixels, size_t capacity) {
    if (data == NULL || sprite == NULL || pixels == NULL || length < SPR_HEADER_SIZE) {
        return false;
    }
    uint8_t flags = data[5];
    uint8_t bpp = data[6];
    uint32_t stride = read_u16(data + 7);
    uint32_t height = read_u16(data + 9);
    int16_t hotspot_x = (int16_t)read_u16(data + 0x0b);
    int16_t hotspot_y = (int16_t)read_u16(data + 0x0d);
    uint32_t canvas_width = read_u16(data + 0x13);
    uint32_t canvas_height = read_u16(data + 0x15);
    size_t data_size = read_u32(data + 0x19);
    uint16_t color_key = read_u16(data + 0x1d);
    if ((bpp != 8 && bpp != 16) || (bpp == 8 && stride == 0)) {
        return false;
    }
    uint32_t width = stride / (bpp / 8u);
    if (width == 0 || height == 0) {
        return false;
    }
    size_t needed = (size_t)width * height * 4;
    if (capacity < needed) {
        return false;
    }
    const uint8_t *payload = data + SPR_HEADER_SIZE;
    if (length - SPR_HEADER_SIZE < data_size) {
        return false;
    }
    const uint8_t *body = payload;
    const uint8_t *palette = NULL;
    if (bpp == 8) {
        if (length - SPR_HEADER_SIZE < data_size + SPR_PALETTE_SIZE) {
            return false;
        }
        palette = payload + data_size;
    }
    memset(pixels, 0, needed);

    if (bpp == 8 && (flags & 0x10) != 0) {
        uint32_t x = 0;
        uint32_t y = 0;
        size_t position = 0;
        while (position + 2 <= data_size && y < height) {
            uint8_t alpha = body[position++];
            uint8_t index = body[position++];
            if (alpha == 0) {
                x += index;
            } else {
                uint8_t rgba[4];
                palette_color(palette, index, rgba);
                rgba[3] = alpha8(alpha);
                put_pixel(pixels, width, height, x, y, rgba);
                x += 1;
            }
            while (x >= width) {
                x -= width;
                y += 1;
            }
        }
    } else if (bpp == 8 && data_size >= (size_t)width * height) {
        uint8_t transparent = (uint8_t)(color_key & 0xff);
        for (size_t index = 0; index < (size_t)width * height; index++) {
            uint8_t value = body[index];
            if (value == transparent) {
                continue;
            }
            uint8_t rgba[4];
            palette_color(palette, value, rgba);
            put_pixel(pixels, width, height, (uint32_t)(index % width),
                      (uint32_t)(index / width), rgba);
        }
    } else if (bpp == 8) {
        uint32_t x = 0;
        uint32_t y = 0;
        size_t position = 0;
        while (position < data_size && y < height) {
            uint8_t value = body[position++];
            if (value == 0xff && position < data_size) {
                x += body[position++];
            } else {
                uint8_t rgba[4];
                palette_color(palette, value, rgba);
                put_pixel(pixels, width, height, x, y, rgba);
                x += 1;
            }
            while (x >= width) {
                x -= width;
                y += 1;
            }
        }
    } else if ((flags & 0x10) != 0) {
        uint32_t x = 0;
        uint32_t y = 0;
        size_t position = 0;
        while (position + 4 <= data_size && y < height) {
            uint16_t alpha_word = read_u16(body + position);
            uint16_t value = read_u16(body + position + 2);
            position += 4;
            if (alpha_word == 0) {
                x += value;
            } else {
                uint8_t rgba[4];
                rgb555(value, rgba);
                rgba[3] = alpha8((uint8_t)(alpha_word >> 8));
                put_pixel(pixels, width, height, x, y, rgba);
                x += 1;
            }
            while (x >= width) {
                x -= width;
                y += 1;
            }
        }
    } else {
        uint32_t x = 0;
        uint32_t y = 0;
        for (size_t position = 0; position + 2 <= data_size; position += 2) {
            uint16_t value = read_u16(body + position);
            if (value != color_key) {
                uint8_t rgba[4];
                rgb555(value, rgba);
                put_pixel(pixels, width, height, x, y, rgba);
            }
            x += 1;
            if (x >= width) {
                x = 0;
                y += 1;
            }
        }
    }

    sprite->width = width;
    sprite->height = height;
    sprite->canvas_width = canvas_width;
    sprite->canvas_height = canvas_height;
    sprite->hotspot_x = hotspot_x;
    sprite->hotspot_y = hotspot_y;
    sprite->bpp = bpp;
    sprite->flags = flags;
    sprite->pixels = pixels;
    sprite->pixel_capacity = capacity;
    return true;
}

bool fnt_read_info(const uint8_t *data, size_t length, FntInfo *info) {
    if (data == NULL || info == NULL || length < 0x624) {
        return false;
    }
    size_t total = 0;
    for (size_t index = 0; index < FNT_GLYPH_COUNT; index++) {
        total += read_u16(data + 0x380 + index * 2);
    }
    if (total > length - 0x624) {
        return false;
    }
    memcpy(info->advances, data + 0x540, FNT_GLYPH_COUNT);
    uint32_t metrics = read_u32(data + 0x620);
    info->line_height = (uint16_t)(metrics & 0xffff);
    info->max_width = (uint16_t)(metrics >> 16);
    return true;
}

bool fnt_decode_glyph(const uint8_t *data, size_t length, char ch,
                      FntGlyph *glyph, uint8_t *coverage, size_t capacity) {
    if (data == NULL || glyph == NULL || coverage == NULL || length < 0x624) {
        return false;
    }
    unsigned char code = (unsigned char)ch;
    if (code < 0x20) {
        return false;
    }
    size_t index = (size_t)(code - 0x20);
    uint16_t width = (uint16_t)(data[index] / 2);
    uint16_t height = data[0xe0 + index];
    uint8_t x_offset = data[0x1c0 + index];
    uint8_t y_offset = data[0x2a0 + index];
    size_t glyph_length = read_u16(data + 0x380 + index * 2);
    if (width == 0 || height == 0 || glyph_length == 0 ||
        capacity < (size_t)width * height) {
        return false;
    }
    size_t stream = 0x624;
    for (size_t prior = 0; prior < index; prior++) {
        stream += read_u16(data + 0x380 + prior * 2);
    }
    if (stream + glyph_length > length) {
        return false;
    }
    size_t position = stream;
    size_t end = stream + glyph_length;
    size_t written = 0;
    for (uint16_t row = 0; row < height; row++) {
        uint16_t row_written = 0;
        while (row_written < width) {
            if (position >= end) {
                return false;
            }
            uint8_t token = data[position++];
            if (token == 0) {
                if (position >= end) {
                    return false;
                }
                uint16_t skip = data[position++];
                if (skip > width - row_written) {
                    skip = width - row_written;
                }
                memset(coverage + written, 0, skip);
                written += skip;
                row_written += skip;
            } else {
                coverage[written++] = token >= 15 ? 255 : (uint8_t)(token * 17);
                row_written += 1;
            }
        }
    }
    if (position != end) {
        return false;
    }
    glyph->width = width;
    glyph->height = height;
    glyph->x_offset = x_offset;
    glyph->y_offset = y_offset;
    glyph->coverage_length = written;
    return true;
}
