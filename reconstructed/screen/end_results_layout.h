#ifndef PC2_RECONSTRUCTED_END_RESULTS_LAYOUT_H
#define PC2_RECONSTRUCTED_END_RESULTS_LAYOUT_H

#include <stddef.h>
#include <stdint.h>

#define END_RESULTS_ASSET_COUNT 20
#define END_RESULTS_FONT_TIMES 0
#define END_RESULTS_FONT_TIMES14 1
#define END_RESULTS_FONT_VERDANA7 2
#define END_RESULTS_FONT_VERDANA8 3
#define END_RESULTS_FONT_COUNT 4
#define END_RESULTS_KIND_TEXT 0
#define END_RESULTS_KIND_SPRITE 1
#define END_RESULTS_KIND_BUTTON 2

typedef struct EndResultsControl {
    int32_t id;
    int16_t x;
    int16_t y;
    uint8_t kind;
    uint8_t asset;
    uint8_t font;
    uint8_t align;
    uint16_t width;
    const char *text;
} EndResultsControl;

extern const EndResultsControl kEndResultsControls[];
extern const size_t kEndResultsControlCount;
extern const char *const kEndResultsAssetNames[END_RESULTS_ASSET_COUNT];

#endif
