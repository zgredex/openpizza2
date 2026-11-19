#ifndef PC2_RECONSTRUCTED_MAP_RENDER_H
#define PC2_RECONSTRUCTED_MAP_RENDER_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "../render/render_state.h"
#include "iso_map.h"

#define MAP_MAX_SPRITE_DRAWS 512u

typedef struct MapMarker {
    int32_t tile_x;
    int32_t tile_y;
    uint8_t rgba[4];
    int32_t half_size;
} MapMarker;

typedef struct MapSpriteDraw {
    RgbaSprite sprite;
    int32_t world_x;
    int32_t world_y;
} MapSpriteDraw;

/*
 * City and branch views reconstructed from IsoMap_RenderFrame (0x4EF9E0):
 * tiles project with
 *   world_x = ((grid_h - tile_y + tile_x) * view_w) / 2
 *   world_y =  (tile_x + tile_y) * view_h / 2,
 * and sprites are anchored bottom-centre and painted by ascending ground line.
 */
bool map_render_city_view(RenderSurface *surface, const RgbaSprite *background,
                          int32_t origin_x, int32_t origin_y, const IsoMap *map,
                          uint32_t focus_tile_index, const MapMarker *markers,
                          size_t marker_count);
bool map_render_branch_interior(RenderSurface *surface, const RgbaSprite *background,
                                int32_t origin_x, int32_t origin_y,
                                const IsoMap *map, const MapSpriteDraw *sprites,
                                size_t sprite_count);
bool map_render_stats_panel(RenderSurface *surface, const RgbaSprite *panel,
                            const RgbaSprite *city_background, int32_t origin_x,
                            int32_t origin_y, const IsoMap *map,
                            uint32_t focus_tile_index, const uint8_t *mask_pixels,
                            uint32_t mask_width, uint32_t mask_height,
                            const MapMarker *markers, size_t marker_count);

#endif
