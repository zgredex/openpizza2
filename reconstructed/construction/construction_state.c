#include "construction_state.h"

#include <stddef.h>

_Static_assert(sizeof(ConstructionOrder) == 0x24, "construction order size");
_Static_assert(offsetof(ConstructionOrder, type) == 0x04, "order type offset");
_Static_assert(offsetof(ConstructionOrder, quality) == 0x08, "order quality offset");
_Static_assert(offsetof(ConstructionOrder, duration) == 0x0c, "order duration offset");
_Static_assert(offsetof(ConstructionOrder, state) == 0x10, "order state offset");
_Static_assert(offsetof(ConstructionOrder, tile_variant) == 0x14, "order tile offset");
_Static_assert(offsetof(ConstructionOrder, cell_x) == 0x18, "order cell x offset");
_Static_assert(offsetof(ConstructionOrder, cell_y) == 0x1c, "order cell y offset");
_Static_assert(offsetof(ConstructionOrder, cell_index) == 0x20, "order cell index offset");

void construction_order_construct(ConstructionOrder *order, uint32_t type,
                                  uint32_t quality) {
    if (order == NULL) {
        return;
    }
    *order = (ConstructionOrder){
        .vtable = 0,
        .type = type,
        .quality = quality,
        .duration = CONSTRUCTION_INITIAL_DURATION,
        .state = 0,
        .tile_variant = -1,
        .cell_x = -1,
        .cell_y = -1,
        .cell_index = 0,
    };
}

void construction_order_enqueue(ConstructionOrder *order, int32_t cell_x,
                                int32_t cell_y, uint32_t map_width) {
    if (order == NULL) {
        return;
    }
    order->cell_x = cell_x;
    order->cell_y = cell_y;
    order->cell_index = (uint32_t)cell_y * map_width + (uint32_t)cell_x;
}

void construction_site_begin(ConstructionSite *site, uint32_t type,
                             uint32_t quality, uint32_t tile_index, int32_t cell_x,
                             int32_t cell_y, uint32_t map_width,
                             uint32_t duration_ticks) {
    if (site == NULL) {
        return;
    }
    construction_order_construct(&site->order, type, quality);
    construction_order_enqueue(&site->order, cell_x, cell_y, map_width);
    site->object = (MapObject){
        .type = type,
        .owner_slot = 0,
        .tile_index = tile_index,
        .cell_x = cell_x,
        .cell_y = cell_y,
        .cell_index = site->order.cell_index,
        .state = 1,
        .owned = false,
        .player_controlled = false,
    };
    site->total_ticks = duration_ticks;
    site->ticks_remaining = duration_ticks;
    site->complete = false;
}

bool construction_site_tick(ConstructionSite *site, uint32_t tick_index) {
    if (site == NULL || site->complete) {
        return site != NULL && site->complete;
    }
    if (tick_index % CONSTRUCTION_TICK_PERIOD == 0 && site->ticks_remaining > 0) {
        site->ticks_remaining -= 1;
    }
    if (site->ticks_remaining == 0) {
        site->complete = true;
        site->order.state = 2;
        site->object.state = 2;
        site->object.owned = true;
        site->object.player_controlled = true;
    }
    return site->complete;
}
