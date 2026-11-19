#ifndef PC2_RECONSTRUCTED_STATISTICS_BALANCE_LAYOUT_H
#define PC2_RECONSTRUCTED_STATISTICS_BALANCE_LAYOUT_H

#include <stddef.h>
#include <stdint.h>

#define BALANCE_ASSET_TAB09 0
#define BALANCE_ASSET_TABPB01 1
#define BALANCE_ASSET_SLIDER 2
#define BALANCE_ASSET_SEPARATOR 3
#define BALANCE_ASSET_PB33 4
#define BALANCE_ASSET_PB22 5
#define BALANCE_ASSET_PB24 6
#define BALANCE_ASSET_BUTTON 7
#define BALANCE_ASSET_HELP 8
#define BALANCE_ASSET_BACKGROUND 9
#define BALANCE_ASSET_COUNT 10

#define BALANCE_KIND_TEXT 0
#define BALANCE_KIND_SPRITE 1
#define BALANCE_KIND_IMAGE 2
#define BALANCE_KIND_SLIDER 3
#define BALANCE_KIND_BUTTON 4

typedef struct BalanceControl {
    int32_t id;
    int16_t x;
    int16_t y;
    uint8_t kind;
    uint8_t asset;
    uint8_t font;
    uint8_t align;   /* 0 left, 1 right, 2 centre */
    uint16_t width;
    const char *text;
} BalanceControl;

extern const BalanceControl kBalanceControls[];
extern const size_t kBalanceControlCount;

#endif
