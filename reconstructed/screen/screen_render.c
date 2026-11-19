#include "screen_render.h"

#include <string.h>

#include "../ui_render/ui_render.h"

static void blend_rect(RenderSurface *surface, int32_t x, int32_t y, int32_t w,
                       int32_t h, const uint8_t rgba[4]) {
    if (surface == NULL) {
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
    uint32_t alpha = rgba[3];
    for (int32_t py = y0; py < y1; py++) {
        for (int32_t px = x0; px < x1; px++) {
            size_t offset = ((size_t)py * surface->width + (size_t)px) * 4;
            for (int channel = 0; channel < 3; channel++) {
                surface->pixels[offset + channel] = (uint8_t)(
                    (rgba[channel] * alpha +
                     surface->pixels[offset + channel] * (255 - alpha) + 127) /
                    255);
            }
            surface->pixels[offset + 3] = 255;
        }
    }
}

bool screen_render_background(RenderSurface *surface, const uint8_t *tga_data,
                              size_t tga_size, uint8_t *decode_buffer,
                              size_t decode_capacity) {
    if (surface == NULL || tga_data == NULL || decode_buffer == NULL) {
        return false;
    }
    uint32_t width = 0;
    uint32_t height = 0;
    if (!tga_decode_rgba(tga_data, tga_size, decode_buffer, decode_capacity,
                         &width, &height)) {
        return false;
    }
    if (width != surface->width || height != surface->height) {
        return false;
    }
    memcpy(surface->pixels, decode_buffer, (size_t)width * height * 4);
    return true;
}

bool screen_render_menu(RenderSurface *surface, const uint8_t *tga_data,
                        size_t tga_size, const uint8_t *font_data,
                        size_t font_size, const FntInfo *font,
                        const MenuState *menu, uint8_t *decode_buffer,
                        size_t decode_capacity) {
    if (menu == NULL || font == NULL) {
        return false;
    }
    if (!screen_render_background(surface, tga_data, tga_size, decode_buffer,
                                  decode_capacity)) {
        return false;
    }
    const uint8_t active[4] = {255, 225, 120, 150};
    const uint8_t idle[4] = {30, 30, 30, 80};
    const uint8_t text_color[4] = {0, 0, 0, 255};
    for (int index = 0; index < MENU_ITEM_COUNT; index++) {
        const MenuItem *item = &menu->items[index];
        bool highlighted = menu->hover >= 0 ? index == menu->hover
                                             : (menu->interacted && index == menu->selected);
        blend_rect(surface, item->x, item->y, (int32_t)item->width,
                   (int32_t)item->height, highlighted ? active : idle);
        uint32_t text_width = ui_measure_text(font, item->label);
        int32_t text_x = item->x + ((int32_t)item->width - (int32_t)text_width) / 2;
        int32_t text_y = item->y + 9;
        if (!ui_draw_text(surface, font_data, font_size, font, text_x, text_y,
                          item->label, text_color)) {
            return false;
        }
    }
    if (menu->has_status) {
        const uint8_t status_color[4] = {255, 255, 255, 255};
        ui_draw_text(surface, font_data, font_size, font, 20,
                     (int32_t)surface->height - 30, menu->status, status_color);
    }
    return true;
}
