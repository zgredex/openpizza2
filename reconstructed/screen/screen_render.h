#ifndef PC2_RECONSTRUCTED_SCREEN_RENDER_H
#define PC2_RECONSTRUCTED_SCREEN_RENDER_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "../assets/assets.h"
#include "../menu/menu_state.h"
#include "../render/render_state.h"

/*
 * Map/UI screen composition: decode a shipped TGA background into the RGBA
 * surface, then draw the reconstructed main-menu rows with the FNT decoder.
 */
bool screen_render_background(RenderSurface *surface, const uint8_t *tga_data,
                              size_t tga_size, uint8_t *decode_buffer,
                              size_t decode_capacity);
bool screen_render_menu(RenderSurface *surface, const uint8_t *tga_data,
                        size_t tga_size, const uint8_t *font_data,
                        size_t font_size, const FntInfo *font,
                        const MenuState *menu, uint8_t *decode_buffer,
                        size_t decode_capacity);
/* Draws the London briefing page over the shipped briefing TGA. Returns the
 * number of wrapped body lines drawn, or -1 on failure. */
int screen_render_briefing(RenderSurface *surface, const uint8_t *tga_data,
                           size_t tga_size, const uint8_t *font_data,
                           size_t font_size, const FntInfo *font,
                           const char *title, const char *body,
                           const char *prompt, uint8_t *decode_buffer,
                           size_t decode_capacity);

#endif
