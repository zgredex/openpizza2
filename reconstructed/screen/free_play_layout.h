#ifndef PC2_RECONSTRUCTED_FREE_PLAY_LAYOUT_H
#define PC2_RECONSTRUCTED_FREE_PLAY_LAYOUT_H

#include <stddef.h>
#include <stdint.h>

#define FREE_PLAY_ASSET_PB22 0
#define FREE_PLAY_ASSET_PB24 1
#define FREE_PLAY_ASSET_PB26 2
#define FREE_PLAY_ASSET_PB27 3
#define FREE_PLAY_ASSET_PB14 4
#define FREE_PLAY_ASSET_SLIDER 5
#define FREE_PLAY_ASSET_PHOTO_FRAME 6
#define FREE_PLAY_ASSET_PHOTO_DUMMY 7
#define FREE_PLAY_ASSET_LOGO 8
#define FREE_PLAY_ASSET_PLAYLOG 9
#define FREE_PLAY_ASSET_PLAYLOG2 10
#define FREE_PLAY_ASSET_PLAYLOG3 11
#define FREE_PLAY_ASSET_BUTTON 12
#define FREE_PLAY_ASSET_BUTTON_YELLOW 13
#define FREE_PLAY_ASSET_BUTTON_GREEN 14
#define FREE_PLAY_ASSET_COUNT 15

#define FREE_PLAY_FONT_TIMES 0
#define FREE_PLAY_FONT_TIMES14 1
#define FREE_PLAY_FONT_VERDANA10 2
#define FREE_PLAY_FONT_VERDANA7 3
#define FREE_PLAY_FONT_VERDANA8 4
#define FREE_PLAY_FONT_COUNT 5

#define FREE_PLAY_KIND_TEXT 0
#define FREE_PLAY_KIND_SPRITE 1
#define FREE_PLAY_KIND_SLIDER 2
#define FREE_PLAY_KIND_BITMAP 3
#define FREE_PLAY_KIND_BUTTON 4

typedef struct FreePlayControl {
    int32_t id;
    int16_t x;
    int16_t y;
    uint8_t kind;
    uint8_t asset;
    uint8_t font;
    uint8_t align;
    uint16_t width;
    uint16_t height;
    const char *text;
} FreePlayControl;

extern const FreePlayControl kFreePlayControls[];
extern const size_t kFreePlayControlCount;

#endif
