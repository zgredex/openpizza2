#ifndef PC2_RECONSTRUCTED_ANI_H
#define PC2_RECONSTRUCTED_ANI_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "../render/render_state.h"

typedef struct AniInfo {
    uint32_t frame_count;
    uint32_t chunk_count;
    uint16_t version;
    uint16_t flags;
    uint32_t color_key;
} AniInfo;

/* Anim_Load (0x532C40) container summary. */
bool ani_read_info(const uint8_t *data, size_t length, AniInfo *info);

/* Decodes one RLE/raw 16bpp chunk from an .ani sprite sheet. The chunk
 * dimensions come from the file's four point arrays; colours are RGB565. */
bool ani_decode_chunk(const uint8_t *data, size_t length, size_t chunk_index,
                      uint8_t *pixels, size_t capacity, RgbaSprite *sprite);

#endif
