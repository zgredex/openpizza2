#ifndef PC2_RECONSTRUCTED_CONSTRUCTION_STATE_H
#define PC2_RECONSTRUCTED_CONSTRUCTION_STATE_H

#include <stdbool.h>
#include <stdint.h>

#define CONSTRUCTION_INITIAL_DURATION 100u
#define CONSTRUCTION_TICK_PERIOD 10u

/*
 * ConstructionOrder, size 0x24, from ConstructionOrder_Construct (0x4E5D60)
 * and the field table in CONSTRUCTION_COST_VERIFICATION.json.
 */
#pragma pack(push, 1)
typedef struct ConstructionOrder {
    uint32_t vtable;          /* 0x00 */
    uint32_t type;            /* 0x04 */
    uint32_t quality;         /* 0x08 */
    uint32_t duration;        /* 0x0C, starts at 100 */
    uint32_t state;           /* 0x10 */
    int32_t tile_variant;     /* 0x14 */
    int32_t cell_x;           /* 0x18 */
    int32_t cell_y;           /* 0x1C */
    uint32_t cell_index;      /* 0x20 */
} ConstructionOrder;
#pragma pack(pop)

/* Observed MapObject fields used by the construction completion path. */
typedef struct MapObject {
    uint32_t type;
    uint32_t owner_slot;
    uint32_t tile_index;
    int32_t cell_x;
    int32_t cell_y;
    uint32_t cell_index;
    uint32_t state;
    bool owned;
    bool player_controlled;
} MapObject;

typedef struct ConstructionSite {
    ConstructionOrder order;
    MapObject object;
    uint32_t total_ticks;
    uint32_t ticks_remaining;
    bool complete;
} ConstructionSite;

void construction_order_construct(ConstructionOrder *order, uint32_t type,
                                  uint32_t quality);
void construction_order_enqueue(ConstructionOrder *order, int32_t cell_x,
                                int32_t cell_y, uint32_t map_width);

void construction_site_begin(ConstructionSite *site, uint32_t type,
                             uint32_t quality, uint32_t tile_index, int32_t cell_x,
                             int32_t cell_y, uint32_t map_width,
                             uint32_t duration_ticks);

/*
 * One object-update tick. The original Branch_UpdateConstruction decrements
 * its remaining counter only when tick_index % 10 == 0. Completion owns the
 * map object and sets the completed state.
 */
bool construction_site_tick(ConstructionSite *site, uint32_t tick_index);

#endif
