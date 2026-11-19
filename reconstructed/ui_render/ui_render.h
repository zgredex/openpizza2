#ifndef PC2_RECONSTRUCTED_UI_RENDER_H
#define PC2_RECONSTRUCTED_UI_RENDER_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "../assets/assets.h"
#include "../render/render_state.h"

bool ui_draw_sprite(RenderSurface *surface, const SpriteAsset *sprite, int32_t x,
                    int32_t y, bool use_hotspot);
uint32_t ui_measure_text(const FntInfo *info, const char *text);
bool ui_draw_text(RenderSurface *surface, const uint8_t *font_data, size_t font_size,
                  const FntInfo *info, int32_t x, int32_t y, const char *text,
                  const uint8_t rgba[4]);

#endif
