#include "render_state.h"

#include <string.h>

static uint16_t read_u16(const uint8_t *data) {
    return (uint16_t)data[0] | ((uint16_t)data[1] << 8);
}

bool render_surface_init(RenderSurface *surface, uint8_t *buffer, size_t capacity,
                         uint32_t width, uint32_t height) {
    if (surface == NULL || buffer == NULL || width == 0 || height == 0) {
        return false;
    }
    size_t needed = (size_t)width * height * 4;
    if (capacity < needed) {
        return false;
    }
    surface->width = width;
    surface->height = height;
    surface->pixels = buffer;
    surface->capacity = capacity;
    memset(buffer, 0, needed);
    return true;
}

void render_clear(RenderSurface *surface, const uint8_t rgba[4]) {
    if (surface == NULL || rgba == NULL) {
        return;
    }
    for (size_t offset = 0; offset + 4 <= surface->capacity;
         offset += 4) {
        memcpy(surface->pixels + offset, rgba, 4);
    }
}

void render_fill_rect(RenderSurface *surface, int32_t x, int32_t y, int32_t w,
                      int32_t h, const uint8_t rgba[4]) {
    if (surface == NULL || rgba == NULL || w <= 0 || h <= 0) {
        return;
    }
    int32_t x0 = x < 0 ? 0 : x;
    int32_t y0 = y < 0 ? 0 : y;
    int32_t x1 = x + w;
    int32_t y1 = y + h;
    if (x1 > (int32_t)surface->width) {
        x1 = (int32_t)surface->width;
    }
    if (y1 > (int32_t)surface->height) {
        y1 = (int32_t)surface->height;
    }
    for (int32_t py = y0; py < y1; py++) {
        for (int32_t px = x0; px < x1; px++) {
            size_t offset = ((size_t)py * surface->width + (size_t)px) * 4;
            memcpy(surface->pixels + offset, rgba, 4);
        }
    }
}

bool render_blit(RenderSurface *surface, const RgbaSprite *sprite, int32_t x,
                 int32_t y) {
    if (surface == NULL || sprite == NULL || sprite->pixels == NULL) {
        return false;
    }
    for (uint32_t sy = 0; sy < sprite->height; sy++) {
        int32_t target_y = y + (int32_t)sy;
        if (target_y < 0 || target_y >= (int32_t)surface->height) {
            continue;
        }
        for (uint32_t sx = 0; sx < sprite->width; sx++) {
            int32_t target_x = x + (int32_t)sx;
            if (target_x < 0 || target_x >= (int32_t)surface->width) {
                continue;
            }
            const uint8_t *source = sprite->pixels + ((size_t)sy * sprite->width + sx) * 4;
            size_t offset = ((size_t)target_y * surface->width + (size_t)target_x) * 4;
            uint8_t *target = surface->pixels + offset;
            uint8_t alpha = source[3];
            if (alpha == 0) {
                continue;
            }
            if (alpha == 255) {
                memcpy(target, source, 4);
            } else {
                for (int channel = 0; channel < 3; channel++) {
                    target[channel] = (uint8_t)((source[channel] * alpha +
                                                  target[channel] * (255 - alpha) + 127) /
                                                 255);
                }
                target[3] = 255;
            }
        }
    }
    return true;
}

static bool read_tga_pixel(const uint8_t *data, size_t length, size_t *position,
                           uint8_t image_type, size_t pixel_bytes, uint8_t rgba[4]) {
    if (*position + pixel_bytes > length) {
        return false;
    }
    const uint8_t *source = data + *position;
    if (image_type == 3 || image_type == 11) {
        rgba[0] = source[0];
        rgba[1] = source[0];
        rgba[2] = source[0];
        rgba[3] = 255;
    } else {
        rgba[0] = source[2];
        rgba[1] = source[1];
        rgba[2] = source[0];
        rgba[3] = pixel_bytes == 4 ? source[3] : 255;
    }
    *position += pixel_bytes;
    return true;
}

static void store_tga_pixel(uint8_t *output, uint32_t width, uint32_t height,
                            bool top_origin, size_t index, const uint8_t rgba[4]) {
    uint32_t source_y = (uint32_t)(index / width);
    uint32_t y = top_origin ? source_y : height - 1 - source_y;
    uint32_t x = (uint32_t)(index % width);
    size_t target = ((size_t)y * width + x) * 4;
    output[target + 0] = rgba[0];
    output[target + 1] = rgba[1];
    output[target + 2] = rgba[2];
    output[target + 3] = rgba[3];
}

bool tga_decode_rgba(const uint8_t *data, size_t length, uint8_t *output,
                     size_t capacity, uint32_t *width, uint32_t *height) {
    if (data == NULL || output == NULL || length < 18) {
        return false;
    }
    uint8_t image_type = data[2];
    uint16_t image_width = read_u16(data + 12);
    uint16_t image_height = read_u16(data + 14);
    uint8_t bpp = data[16];
    uint8_t descriptor = data[17];
    if (image_width == 0 || image_height == 0) {
        return false;
    }
    bool rle = image_type == 10 || image_type == 11;
    bool grayscale = image_type == 3 || image_type == 11;
    bool truecolor = image_type == 2 || image_type == 10;
    if (!grayscale && !truecolor) {
        return false;
    }
    size_t pixel_bytes = (bpp + 7) / 8;
    if (grayscale && pixel_bytes != 1) {
        return false;
    }
    if (truecolor && pixel_bytes != 3 && pixel_bytes != 4) {
        return false;
    }
    size_t count = (size_t)image_width * image_height;
    size_t needed = count * 4;
    if (capacity < needed) {
        return false;
    }
    size_t offset = 18 + data[0];
    if (offset > length) {
        return false;
    }
    bool top_origin = (descriptor & 0x20) != 0;
    size_t index = 0;
    while (index < count) {
        if (!rle) {
            uint8_t rgba[4];
            if (!read_tga_pixel(data, length, &offset, image_type, pixel_bytes, rgba)) {
                return false;
            }
            store_tga_pixel(output, image_width, image_height, top_origin, index, rgba);
            index += 1;
            continue;
        }
        if (offset >= length) {
            return false;
        }
        uint8_t packet = data[offset++];
        size_t run = (size_t)(packet & 0x7f) + 1;
        if (packet & 0x80) {
            uint8_t rgba[4];
            if (!read_tga_pixel(data, length, &offset, image_type, pixel_bytes, rgba)) {
                return false;
            }
            for (size_t repeat = 0; repeat < run && index < count; repeat++) {
                store_tga_pixel(output, image_width, image_height, top_origin, index, rgba);
                index += 1;
            }
        } else {
            for (size_t raw = 0; raw < run && index < count; raw++) {
                uint8_t rgba[4];
                if (!read_tga_pixel(data, length, &offset, image_type, pixel_bytes, rgba)) {
                    return false;
                }
                store_tga_pixel(output, image_width, image_height, top_origin, index, rgba);
                index += 1;
            }
        }
    }
    if (width != NULL) {
        *width = image_width;
    }
    if (height != NULL) {
        *height = image_height;
    }
    return true;
}
