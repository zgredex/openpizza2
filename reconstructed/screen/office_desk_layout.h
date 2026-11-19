#ifndef PC2_RECONSTRUCTED_OFFICE_DESK_LAYOUT_H
#define PC2_RECONSTRUCTED_OFFICE_DESK_LAYOUT_H

#include <stddef.h>
#include <stdint.h>

#define OFFICE_ASSET_MAUERBOGEN 0
#define OFFICE_ASSET_PB22 1
#define OFFICE_ASSET_PB24 2
#define OFFICE_ASSET_HPB00 3
#define OFFICE_ASSET_HPB01 4
#define OFFICE_ASSET_HPB02 5
#define OFFICE_ASSET_HPB03 6
#define OFFICE_ASSET_HPB04 7
#define OFFICE_ASSET_RB01 8
#define OFFICE_ASSET_RB02 9
#define OFFICE_ASSET_RB03 10
#define OFFICE_ASSET_RB04 11
#define OFFICE_ASSET_RB05 12
#define OFFICE_ASSET_CITYBUT 13
#define OFFICE_ASSET_PILOESCH 14
#define OFFICE_ASSET_REDO 15
#define OFFICE_ASSET_UNDO 16
#define OFFICE_ASSET_RING 17
#define OFFICE_ASSET_UHR 18
#define OFFICE_ASSET_LOCH 19
#define OFFICE_ASSET_HELP 20
#define OFFICE_ASSET_PLAYLOG 21
#define OFFICE_ASSET_STAR 22
#define OFFICE_ASSET_COUNT 23

#define OFFICE_FONT_TIMES 0
#define OFFICE_FONT_TIMES14 1
#define OFFICE_FONT_VERDANA7 2
#define OFFICE_FONT_VERDANA8 3
#define OFFICE_FONT_VERDANA10 4
#define OFFICE_FONT_COUNT 5

#define OFFICE_KIND_TEXT 0
#define OFFICE_KIND_SPRITE 1
#define OFFICE_KIND_ANIMATION 2
#define OFFICE_KIND_BITMAP 3

typedef struct OfficeDeskControl {
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
} OfficeDeskControl;

extern const OfficeDeskControl kOfficeDeskControls[];
extern const size_t kOfficeDeskControlCount;

#endif
