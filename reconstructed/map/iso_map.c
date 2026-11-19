#include "iso_map.h"

#include <string.h>

static uint32_t read_u32(const uint8_t *data) {
    return (uint32_t)data[0] | ((uint32_t)data[1] << 8) |
           ((uint32_t)data[2] << 16) | ((uint32_t)data[3] << 24);
}

static void read_name(char *target, const uint8_t *data) {
    memset(target, 0, ISO_LAYER_NAME_SIZE);
    memcpy(target, data, ISO_LAYER_NAME_SIZE - 1);
    target[ISO_LAYER_NAME_SIZE - 1] = '\0';
}

bool iso_map_parse(const uint8_t *data, size_t length, IsoMap *map, IsoTile *storage,
                   size_t capacity) {
    if (data == NULL || map == NULL || storage == NULL || length < ISO_HEADER_SIZE) {
        return false;
    }
    memset(map, 0, sizeof(*map));
    IsoHeader *header = &map->header;
    header->version = read_u32(data + 0x00);
    header->name_mode = read_u32(data + 0x04);
    header->view_w = read_u32(data + 0x08);
    header->view_h = read_u32(data + 0x0c);
    header->tile_px_w = read_u32(data + 0x10);
    header->tile_px_h = read_u32(data + 0x14);
    header->grid_w = read_u32(data + 0x18);
    header->grid_h = read_u32(data + 0x1c);
    header->pixel_w = read_u32(data + 0x20);
    header->pixel_h = read_u32(data + 0x24);
    header->origin_x = read_u32(data + 0x28);
    header->origin_y = read_u32(data + 0x2c);
    header->list1_count = read_u32(data + 0x74);
    header->list2_count = read_u32(data + 0x78);
    read_name(header->background, data + 0x50);

    if (header->grid_w == 0 || header->grid_h == 0) {
        return false;
    }
    if (header->grid_w > 0xffffu || header->grid_h > 0xffffu) {
        return false;
    }
    uint64_t total_64 = (uint64_t)header->grid_w * header->grid_h;
    if (total_64 > 0xffffffffu) {
        return false;
    }
    uint32_t total = (uint32_t)total_64;

    uint64_t offset_64 = ISO_HEADER_SIZE +
                         ((uint64_t)header->list1_count + header->list2_count) *
                             ISO_LIST_RECORD_SIZE;
    if (offset_64 > length) {
        return false;
    }
    size_t offset = (size_t)offset_64;

    map->tiles = storage;
    map->tile_capacity = capacity;
    map->tile_count = 0;
    uint32_t index = 0;
    while (index < total) {
        if (offset + 4 > length) {
            return false;
        }
        uint32_t flag = read_u32(data + offset);
        offset += 4;
        if (flag == 1) {
            if (offset + 4 > length) {
                return false;
            }
            uint32_t run = read_u32(data + offset);
            offset += 4;
            if (run == 0 || (uint64_t)index + run > total) {
                return false;
            }
            index += run;
            continue;
        }
        if (offset + ISO_TILE_FIXED_SIZE > length) {
            return false;
        }
        uint32_t tile_flags = read_u32(data + offset);
        offset += ISO_TILE_FIXED_SIZE;
        char layer1[ISO_LAYER_NAME_SIZE] = {0};
        char layer2[ISO_LAYER_NAME_SIZE] = {0};
        for (int layer = 0; layer < 2; layer++) {
            if (offset + 4 > length) {
                return false;
            }
            uint32_t raw = read_u32(data + offset);
            offset += 4;
            if (header->name_mode == 0 && raw < 0x80000000u) {
                if (offset + ISO_LAYER_NAME_SIZE > length) {
                    return false;
                }
                read_name(layer == 0 ? layer1 : layer2, data + offset);
                offset += ISO_LAYER_NAME_SIZE;
            }
        }
        if (map->tile_count >= capacity) {
            return false;
        }
        IsoTile *tile = &storage[map->tile_count];
        memset(tile, 0, sizeof(*tile));
        tile->index = index;
        tile->x = index % header->grid_w;
        tile->y = index / header->grid_w;
        tile->flags = tile_flags;
        if (layer1[0] != '\0') {
            memcpy(tile->layer1, layer1, ISO_LAYER_NAME_SIZE);
            tile->has_layer1 = true;
        }
        if (layer2[0] != '\0') {
            memcpy(tile->layer2, layer2, ISO_LAYER_NAME_SIZE);
            tile->has_layer2 = true;
        }
        map->tile_count += 1;
        index += 1;
    }
    if (offset < length) {
        /* Only the trailer may remain; every shipped map has flag 0. */
        if (offset + 4 <= length && read_u32(data + offset) == 1) {
            offset += 4;
            if (offset + 4 > length) {
                return false;
            }
            uint32_t count = read_u32(data + offset);
            offset += 4;
            if ((uint64_t)offset + ((uint64_t)count + 1) * 4 > length) {
                return false;
            }
        }
    }
    return true;
}

void iso_tile_world(const IsoMap *map, const IsoTile *tile, int32_t *world_x,
                    int32_t *world_y) {
    if (map == NULL || tile == NULL) {
        return;
    }
    int32_t x = (int32_t)((map->header.grid_h - tile->y + tile->x) *
                          map->header.view_w / 2);
    int32_t y = (int32_t)((tile->x + tile->y) * map->header.view_h / 2);
    if (world_x != NULL) {
        *world_x = x;
    }
    if (world_y != NULL) {
        *world_y = y;
    }
}

const IsoTile *iso_map_tile_at(const IsoMap *map, uint32_t x, uint32_t y) {
    if (map == NULL) {
        return NULL;
    }
    for (size_t index = 0; index < map->tile_count; index++) {
        if (map->tiles[index].x == x && map->tiles[index].y == y) {
            return &map->tiles[index];
        }
    }
    return NULL;
}
