#ifndef PC2_RECONSTRUCTED_ISO_MAP_H
#define PC2_RECONSTRUCTED_ISO_MAP_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define ISO_HEADER_SIZE 0x7Cu
#define ISO_LIST_RECORD_SIZE 34u
#define ISO_TILE_FIXED_SIZE 30u
#define ISO_LAYER_NAME_SIZE 50u
#define ISO_MAX_TILES 4096u

typedef struct IsoHeader {
    uint32_t version;
    uint32_t name_mode;
    uint32_t view_w;
    uint32_t view_h;
    uint32_t tile_px_w;
    uint32_t tile_px_h;
    uint32_t grid_w;
    uint32_t grid_h;
    uint32_t pixel_w;
    uint32_t pixel_h;
    uint32_t origin_x; /* +0x28 */
    uint32_t origin_y; /* +0x2C */
    uint32_t list1_count;
    uint32_t list2_count;
    char background[ISO_LAYER_NAME_SIZE];
} IsoHeader;

typedef struct IsoTile {
    uint32_t index;
    uint32_t x;
    uint32_t y;
    uint32_t flags;
    bool has_layer1;
    bool has_layer2;
    char layer1[ISO_LAYER_NAME_SIZE];
    char layer2[ISO_LAYER_NAME_SIZE];
} IsoTile;

/*
 * Parser for the shipped .iso isometric maps, recovered from
 * IsoMap_DeserializeGrid (0x4EB900). The caller supplies tile storage so the
 * reconstructed module has no hidden allocation.
 */
typedef struct IsoMap {
    IsoHeader header;
    IsoTile *tiles;
    size_t tile_count;
    size_t tile_capacity;
} IsoMap;

bool iso_map_parse(const uint8_t *data, size_t length, IsoMap *map, IsoTile *storage,
                   size_t capacity);
void iso_tile_world(const IsoMap *map, const IsoTile *tile, int32_t *world_x,
                    int32_t *world_y);
const IsoTile *iso_map_tile_at(const IsoMap *map, uint32_t x, uint32_t y);

#endif
