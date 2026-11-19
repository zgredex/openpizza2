#ifndef PC2_RECONSTRUCTED_WAREHOUSE_LAYOUT_H
#define PC2_RECONSTRUCTED_WAREHOUSE_LAYOUT_H

#include <stddef.h>
#include <stdint.h>

#define WAREHOUSE_ASSET_COUNT 27
#define WAREHOUSE_FONT_TIMES 0
#define WAREHOUSE_FONT_VERDANA7 1
#define WAREHOUSE_FONT_VERDANA8 2
#define WAREHOUSE_FONT_COUNT 3
#define WAREHOUSE_KIND_TEXT 0
#define WAREHOUSE_KIND_SPRITE 1
#define WAREHOUSE_KIND_SLIDER 2
#define WAREHOUSE_KIND_BUTTON 3
#define WAREHOUSE_WINDOW_X 561
#define WAREHOUSE_WINDOW_Y 218

typedef struct WarehouseControl {
    int32_t id;
    int16_t x;
    int16_t y;
    uint8_t kind;
    uint8_t asset;
    uint8_t font;
    uint8_t align;
    uint16_t width;
    const char *text;
} WarehouseControl;

extern const WarehouseControl kWarehouseControls[];
extern const size_t kWarehouseControlCount;
extern const char *const kWarehouseAssetNames[WAREHOUSE_ASSET_COUNT];

#endif
