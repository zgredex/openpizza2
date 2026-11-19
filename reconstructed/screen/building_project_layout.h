#ifndef PC2_RECONSTRUCTED_BUILDING_PROJECT_LAYOUT_H
#define PC2_RECONSTRUCTED_BUILDING_PROJECT_LAYOUT_H

#include <stddef.h>
#include <stdint.h>

#define BUILDING_PROJECT_ASSET_COUNT 28
#define BUILDING_PROJECT_FONT_TIMES 0
#define BUILDING_PROJECT_FONT_VERDANA7 1
#define BUILDING_PROJECT_FONT_VERDANA8 2
#define BUILDING_PROJECT_FONT_VERDANA10 3
#define BUILDING_PROJECT_FONT_COUNT 4
#define BUILDING_PROJECT_KIND_TEXT 0
#define BUILDING_PROJECT_KIND_SPRITE 1
#define BUILDING_PROJECT_KIND_SLIDER 2
#define BUILDING_PROJECT_KIND_BUTTON 3
#define BUILDING_PROJECT_WINDOW_X 561
#define BUILDING_PROJECT_WINDOW_Y 218

typedef struct BuildingProjectControl {
    int32_t id;
    int16_t x;
    int16_t y;
    uint8_t kind;
    uint8_t asset;
    uint8_t font;
    uint8_t align;
    uint16_t width;
    const char *text;
} BuildingProjectControl;

extern const BuildingProjectControl kBuildingProjectControls[];
extern const size_t kBuildingProjectControlCount;
extern const char *const kBuildingProjectAssetNames[BUILDING_PROJECT_ASSET_COUNT];

#endif
