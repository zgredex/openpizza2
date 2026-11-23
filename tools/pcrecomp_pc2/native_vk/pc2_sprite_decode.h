#ifndef PC2_SPRITE_DECODE_H
#define PC2_SPRITE_DECODE_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Decode the 8-bit indexed RLE form of Sprite_BlitAlphaRLEAlt (flags 0x03).
 * A key byte is followed by a transparent run length; other bytes are palette
 * indices. Each run stays within one row. The caller supplies the game's
 * destination-format LE16 palette (512 bytes), with rgb565 set for RGB565.
 * The entire stream must be consumed. On failure discard the RGBA8 output.
 */
int pc2_sprite_decode_indexed_rle(const void *stream, size_t stream_size,
                                  uint32_t width, uint32_t height, uint8_t key,
                                  const void *palette, size_t palette_size,
                                  int rgb565, uint8_t *rgba, size_t rgba_size);

/* Decode a complete, bounded Sprite_BlitAlphaRLEAlt stream (flag 0x10).
 * Width is in pixels, height in rows. For depth 8, palette points to the
 * 256 little-endian RGB555 entries passed to the guest blitter. Depth 16
 * embeds RGB555 colors in the tokens and uses no palette.
 *
 * Set rgb565 for a 565 target to preserve its opaque channel expansion.
 * Output is row-major straight-alpha RGBA8, suitable for a source texture.
 * Partial-alpha coverage is preserved; the legacy target's quantized integer
 * blend remains a separate compositing concern. On failure discard the output.
 */
int pc2_sprite_decode_alpha_rle(const void *stream, size_t stream_size,
                                uint32_t width, uint32_t height, uint8_t depth,
                                const void *palette, size_t palette_size,
                                int rgb565, uint8_t *rgba, size_t rgba_size);

#ifdef __cplusplus
}
#endif
#endif
