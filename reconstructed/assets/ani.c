#include "ani.h"

#include <string.h>

static uint16_t read_u16(const uint8_t *data) {
    return (uint16_t)(data[0] | (data[1] << 8));
}

static uint32_t read_u32(const uint8_t *data) {
    return (uint32_t)data[0] | ((uint32_t)data[1] << 8) |
           ((uint32_t)data[2] << 16) | ((uint32_t)data[3] << 24);
}

static void put_rgb565(uint8_t *pixels, size_t offset, uint16_t value) {
    uint8_t red = (uint8_t)(((value >> 11) & 0x1fu) * 255u / 31u);
    uint8_t green = (uint8_t)(((value >> 5) & 0x3fu) * 255u / 63u);
    uint8_t blue = (uint8_t)((value & 0x1fu) * 255u / 31u);
    pixels[offset] = red;
    pixels[offset + 1] = green;
    pixels[offset + 2] = blue;
    pixels[offset + 3] = 255;
}

bool ani_read_info(const uint8_t *data, size_t length, AniInfo *info) {
    if (data == NULL || info == NULL || length < 0x30) {
        return false;
    }
    uint32_t magic = read_u32(data + 0x0c);
    if ((magic >> 16) != 0xca42u) {
        return false;
    }
    info->frame_count = read_u32(data);
    info->chunk_count = read_u32(data + 4);
    info->version = (uint16_t)(magic & 0xffffu);
    info->flags = data[0x14];
    info->color_key = read_u32(data + 0x2c) & 0xffffu;
    return info->frame_count != 0 && info->chunk_count != 0;
}

bool ani_decode_chunk(const uint8_t *data, size_t length, size_t chunk_index,
                      uint8_t *pixels, size_t capacity, RgbaSprite *sprite) {
    if (data == NULL || pixels == NULL || sprite == NULL || length < 0x30) {
        return false;
    }
    AniInfo info;
    if (!ani_read_info(data, length, &info)) {
        return false;
    }
    if (chunk_index >= info.chunk_count) {
        return false;
    }
    size_t records_end =
        0x30u + (size_t)info.frame_count * 0x98u;
    if (records_end + 4 > length) {
        return false;
    }
    uint32_t blob_length = read_u32(data + records_end);
    const uint8_t *blob = data + records_end + 4;
    size_t available = length - (records_end + 4);
    if ((size_t)blob_length > available + 4u) {
        return false;
    }
    size_t blob_size = (size_t)blob_length <= available ? (size_t)blob_length
                                                        : available;

    size_t array_bytes = (size_t)info.chunk_count * 2u;
    if (array_bytes * 4u > blob_size) {
        return false;
    }
    const uint8_t *widths = blob;
    const uint8_t *heights = blob + array_bytes;
    uint32_t width = read_u16(widths + chunk_index * 2u);
    uint32_t height = read_u16(heights + chunk_index * 2u);
    if (width == 0 || height == 0) {
        return false;
    }
    size_t needed = (size_t)width * height * 4u;
    if (capacity < needed) {
        return false;
    }

    const uint8_t *lengths = blob + array_bytes * 4u;
    size_t chunks_offset;
    if (info.version < 2) {
        chunks_offset = array_bytes * 4u + (size_t)info.chunk_count * 2u;
    } else {
        chunks_offset = array_bytes * 4u + (size_t)info.chunk_count * 4u;
    }
    if (chunks_offset > blob_size) {
        return false;
    }

    size_t chunk_offset = chunks_offset;
    size_t chunk_length = 0;
    for (size_t index = 0; index <= chunk_index; index++) {
        if (index > 0) {
            chunk_offset += chunk_length;
        }
        if (info.version < 2) {
            chunk_length = read_u16(lengths + index * 2u);
        } else {
            chunk_length = read_u32(lengths + index * 4u);
        }
        if (chunk_offset > blob_size ||
            chunk_length > blob_size - chunk_offset) {
            return false;
        }
    }
    const uint8_t *chunk = blob + chunk_offset;

    memset(pixels, 0, needed);
    if ((info.flags & 1u) == 0) {
        size_t source = 0;
        for (uint32_t y = 0; y < height; y++) {
            for (uint32_t x = 0; x < width; x++) {
                if (source + 1 >= chunk_length) {
                    break;
                }
                uint16_t value = read_u16(chunk + source);
                source += 2;
                if (value == (uint16_t)info.color_key || value == 0) {
                    continue;
                }
                put_rgb565(pixels, ((size_t)y * width + x) * 4u, value);
            }
        }
    } else {
        size_t source = 0;
        uint32_t x = 0;
        uint32_t y = 0;
        while (source + 1 < chunk_length && y < height) {
            uint16_t value = read_u16(chunk + source);
            source += 2;
            if (value == (uint16_t)info.color_key) {
                if (source + 1 >= chunk_length) {
                    break;
                }
                uint32_t run = read_u16(chunk + source);
                source += 2;
                x += run;
            } else {
                if (x < width) {
                    put_rgb565(pixels, ((size_t)y * width + x) * 4u, value);
                }
                x++;
            }
            while (x >= width) {
                x -= width;
                y++;
            }
        }
    }

    sprite->width = width;
    sprite->height = height;
    sprite->pixels = pixels;
    return true;
}
