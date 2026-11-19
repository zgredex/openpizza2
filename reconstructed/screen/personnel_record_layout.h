#ifndef PC2_RECONSTRUCTED_PERSONNEL_RECORD_LAYOUT_H
#define PC2_RECONSTRUCTED_PERSONNEL_RECORD_LAYOUT_H

#include <stddef.h>
#include <stdint.h>

#define PERSONNEL_RECORD_ASSET_COUNT 39
#define PERSONNEL_RECORD_FONT_TIMES 0
#define PERSONNEL_RECORD_FONT_VERDANA7 1
#define PERSONNEL_RECORD_FONT_VERDANA8 2
#define PERSONNEL_RECORD_FONT_COUNT 3
#define PERSONNEL_RECORD_KIND_TEXT 0
#define PERSONNEL_RECORD_KIND_SPRITE 1
#define PERSONNEL_RECORD_KIND_SLIDER 2
#define PERSONNEL_RECORD_KIND_BUTTON 3
#define PERSONNEL_RECORD_WINDOW_X 561
#define PERSONNEL_RECORD_WINDOW_Y 218

typedef struct PersonnelRecordControl {
    int32_t id;
    int16_t x;
    int16_t y;
    uint8_t kind;
    uint8_t asset;
    uint8_t font;
    uint8_t align;
    uint16_t width;
    const char *text;
} PersonnelRecordControl;

extern const PersonnelRecordControl kPersonnelRecordControls[];
extern const size_t kPersonnelRecordControlCount;
extern const char *const kPersonnelRecordAssetNames[PERSONNEL_RECORD_ASSET_COUNT];

#endif
