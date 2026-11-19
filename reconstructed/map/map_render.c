#include "map_render.h"

#include <string.h>

static const IsoTile *find_tile_by_index(const IsoMap *map, uint32_t tile_index) {
    if (map == NULL) {
        return NULL;
    }
    for (size_t index = 0; index < map->tile_count; index++) {
        if (map->tiles[index].index == tile_index) {
            return &map->tiles[index];
        }
    }
    return NULL;
}

static void fill_dark(RenderSurface *surface) {
    const uint8_t dark[4] = {18, 20, 24, 255};
    render_clear(surface, dark);
}

static void crop_background(RenderSurface *surface, const RgbaSprite *background,
                            int32_t crop_x, int32_t crop_y) {
    fill_dark(surface);
    if (background == NULL || background->pixels == NULL) {
        return;
    }
    for (uint32_t y = 0; y < surface->height; y++) {
        int32_t source_y = crop_y + (int32_t)y;
        if (source_y < 0 || source_y >= (int32_t)background->height) {
            continue;
        }
        for (uint32_t x = 0; x < surface->width; x++) {
            int32_t source_x = crop_x + (int32_t)x;
            if (source_x < 0 || source_x >= (int32_t)background->width) {
                continue;
            }
            size_t source = ((size_t)source_y * background->width +
                             (size_t)source_x) * 4;
            size_t target = ((size_t)y * surface->width + x) * 4;
            memcpy(surface->pixels + target, background->pixels + source, 4);
        }
    }
}

static void plot_marker(RenderSurface *surface, int32_t screen_x, int32_t screen_y,
                        int32_t half_size, const uint8_t rgba[4]) {
    for (int32_t dy = -half_size; dy <= half_size; dy++) {
        int32_t span = half_size - (dy < 0 ? -dy : dy);
        for (int32_t dx = -span; dx <= span; dx++) {
            int32_t x = screen_x + dx;
            int32_t y = screen_y + dy;
            if (x < 0 || y < 0 || x >= (int32_t)surface->width ||
                y >= (int32_t)surface->height) {
                continue;
            }
            size_t offset = ((size_t)y * surface->width + (size_t)x) * 4;
            uint32_t alpha = rgba[3];
            if (alpha == 255) {
                memcpy(surface->pixels + offset, rgba, 4);
            } else {
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
}

static void draw_markers(RenderSurface *surface, const IsoMap *map,
                         int32_t origin_x, int32_t origin_y, int32_t crop_x,
                         int32_t crop_y, const MapMarker *markers,
                         size_t marker_count) {
    if (markers == NULL) {
        return;
    }
    for (size_t index = 0; index < marker_count; index++) {
        int32_t world_x = 0;
        int32_t world_y = 0;
        IsoTile tile = {
            .x = (uint32_t)markers[index].tile_x,
            .y = (uint32_t)markers[index].tile_y,
        };
        iso_tile_world(map, &tile, &world_x, &world_y);
        int32_t screen_x = world_x - origin_x - crop_x;
        int32_t screen_y = world_y - origin_y - crop_y;
        int32_t half = markers[index].half_size > 0 ? markers[index].half_size : 4;
        plot_marker(surface, screen_x, screen_y, half, markers[index].rgba);
    }
}

bool map_render_city_view(RenderSurface *surface, const RgbaSprite *background,
                          int32_t origin_x, int32_t origin_y, const IsoMap *map,
                          uint32_t focus_tile_index, const MapMarker *markers,
                          size_t marker_count) {
    if (surface == NULL || background == NULL || map == NULL) {
        return false;
    }
    const IsoTile *focus = find_tile_by_index(map, focus_tile_index);
    if (focus == NULL) {
        return false;
    }
    int32_t center_x = 0;
    int32_t center_y = 0;
    iso_tile_world(map, focus, &center_x, &center_y);
    int32_t crop_x = center_x - origin_x - (int32_t)surface->width / 2;
    int32_t crop_y = center_y - origin_y - (int32_t)surface->height / 2;
    crop_background(surface, background, crop_x, crop_y);
    draw_markers(surface, map, origin_x, origin_y, crop_x, crop_y, markers,
                 marker_count);
    return true;
}

bool map_render_branch_interior(RenderSurface *surface, const RgbaSprite *background,
                                int32_t origin_x, int32_t origin_y,
                                const IsoMap *map, const MapSpriteDraw *sprites,
                                size_t sprite_count) {
    (void)map;
    if (surface == NULL || background == NULL) {
        return false;
    }
    int32_t center_x = origin_x + (int32_t)background->width / 2;
    int32_t center_y = origin_y + (int32_t)background->height / 2;
    int32_t crop_x = center_x - origin_x - (int32_t)surface->width / 2;
    int32_t crop_y = center_y - origin_y - (int32_t)surface->height / 2;
    crop_background(surface, background, crop_x, crop_y);

    if (sprites == NULL || sprite_count == 0) {
        return true;
    }
    if (sprite_count > MAP_MAX_SPRITE_DRAWS) {
        return false;
    }
    size_t order[MAP_MAX_SPRITE_DRAWS];
    for (size_t index = 0; index < sprite_count; index++) {
        order[index] = index;
    }
    for (size_t index = 1; index < sprite_count; index++) {
        size_t value = order[index];
        size_t move = index;
        while (move > 0) {
            size_t previous = order[move - 1];
            int32_t value_left = sprites[value].world_x -
                                 (int32_t)sprites[value].sprite.width / 2;
            int32_t previous_left = sprites[previous].world_x -
                                    (int32_t)sprites[previous].sprite.width / 2;
            bool after = sprites[previous].world_y < sprites[value].world_y ||
                         (sprites[previous].world_y == sprites[value].world_y &&
                          previous_left <= value_left);
            if (after) {
                break;
            }
            order[move] = previous;
            move -= 1;
        }
        order[move] = value;
    }
    for (size_t slot = 0; slot < sprite_count; slot++) {
        const MapSpriteDraw *draw = &sprites[order[slot]];
        if (draw->sprite.pixels == NULL || draw->sprite.width == 0 ||
            draw->sprite.height == 0) {
            continue;
        }
        int32_t x = draw->world_x - origin_x - crop_x -
                    (int32_t)draw->sprite.width / 2;
        int32_t y = draw->world_y - origin_y - crop_y -
                    (int32_t)draw->sprite.height;
        render_blit(surface, &draw->sprite, x, y);
    }
    return true;
}

bool map_render_stats_panel(RenderSurface *surface, const RgbaSprite *panel,
                            const RgbaSprite *city_background, int32_t origin_x,
                            int32_t origin_y, const IsoMap *map,
                            uint32_t focus_tile_index, const uint8_t *mask_pixels,
                            uint32_t mask_width, uint32_t mask_height,
                            const MapMarker *markers, size_t marker_count) {
    if (surface == NULL || panel == NULL || city_background == NULL || map == NULL ||
        mask_pixels == NULL) {
        return false;
    }
    const IsoTile *focus = find_tile_by_index(map, focus_tile_index);
    if (focus == NULL) {
        return false;
    }
    fill_dark(surface);
    for (uint32_t y = 0; y < surface->height; y++) {
        if (y >= panel->height) {
            break;
        }
        for (uint32_t x = 0; x < surface->width; x++) {
            if (x >= panel->width) {
                break;
            }
            size_t target = ((size_t)y * surface->width + x) * 4;
            memcpy(surface->pixels + target,
                   panel->pixels + ((size_t)y * panel->width + x) * 4, 4);
        }
    }
    int32_t center_x = 0;
    int32_t center_y = 0;
    iso_tile_world(map, focus, &center_x, &center_y);
    int32_t crop_x = center_x - origin_x - (int32_t)surface->width / 2;
    int32_t crop_y = center_y - origin_y - (int32_t)surface->height / 2;
    for (uint32_t y = 0; y < surface->height && y < mask_height; y++) {
        for (uint32_t x = 0; x < surface->width && x < mask_width; x++) {
            size_t mask_offset = ((size_t)y * mask_width + x) * 4;
            if (mask_pixels[mask_offset] == 0 && mask_pixels[mask_offset + 1] == 0 &&
                mask_pixels[mask_offset + 2] == 0) {
                continue;
            }
            int32_t source_x = crop_x + (int32_t)x;
            int32_t source_y = crop_y + (int32_t)y;
            if (source_x < 0 || source_y < 0 ||
                source_x >= (int32_t)city_background->width ||
                source_y >= (int32_t)city_background->height) {
                continue;
            }
            size_t source = ((size_t)source_y * city_background->width +
                             (size_t)source_x) * 4;
            size_t target = ((size_t)y * surface->width + x) * 4;
            memcpy(surface->pixels + target, city_background->pixels + source, 4);
        }
    }
    draw_markers(surface, map, origin_x, origin_y, crop_x, crop_y, markers,
                 marker_count);
    return true;
}
