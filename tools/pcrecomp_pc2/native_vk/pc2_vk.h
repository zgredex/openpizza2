#ifndef PC2_NATIVE_VK_H
#define PC2_NATIVE_VK_H
/* Native 2D Vulkan drawing API. No DirectDraw objects, surfaces or framebuffer presents. */
#include <stdint.h>
#include <SDL2/SDL.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef struct pc2_vk pc2_vk;
typedef struct pc2_vk_texture pc2_vk_texture;
/* Caller owns an SDL_WINDOW_VULKAN window for the lifetime of the renderer. */
pc2_vk *pc2_vk_create(SDL_Window *window, const char *spirv_directory);
void pc2_vk_destroy(pc2_vk *ctx);
int pc2_vk_resize(pc2_vk *ctx);
/* Upload a decoded resource, not the legacy 800x600 composed frame.
 * Pixels are RGBA8; pitch is bytes per row (0 for tightly packed input).
 * Color-key/palette conversion belongs to the sprite asset decoder. */
pc2_vk_texture *pc2_vk_texture_create(pc2_vk *ctx, uint32_t width, uint32_t height,
                                       const uint8_t *rgba, uint32_t pitch);
int pc2_vk_texture_update(pc2_vk *ctx, pc2_vk_texture *texture,
                          const uint8_t *rgba, uint32_t pitch);
/* Upload a little-endian RGB565 source. color_key is -1 for opaque, or the
 * exact 16-bit value to make transparent. Texture updates are between frames. */
pc2_vk_texture *pc2_vk_texture_create_rgb565(pc2_vk *ctx, uint32_t width,
                                            uint32_t height, const void *pixels,
                                            uint32_t pitch, int color_key);
int pc2_vk_texture_update_rgb565(pc2_vk *ctx, pc2_vk_texture *texture,
                                const void *pixels, uint32_t pitch, int color_key);
void pc2_vk_texture_destroy(pc2_vk *ctx, pc2_vk_texture *texture);
/* Coordinates and clip are in the game's logical 800x600 space. */
int pc2_vk_begin(pc2_vk *ctx, float r, float g, float b, float a);
void pc2_vk_draw(pc2_vk *ctx, pc2_vk_texture *texture,
                 float x, float y, float w, float h,
                 float u0, float v0, float u1, float v1,
                 int clip_x, int clip_y, int clip_w, int clip_h);
/* Source coordinates use texture pixels. An out-of-bounds source rectangle
 * clips the destination proportionally. The clip rectangle is destination space. */
void pc2_vk_draw_rect(pc2_vk *ctx, pc2_vk_texture *texture,
                     float dst_x, float dst_y, float dst_w, float dst_h,
                     int src_x, int src_y, int src_w, int src_h,
                     int clip_x, int clip_y, int clip_w, int clip_h);
int pc2_vk_end(pc2_vk *ctx);
const char *pc2_vk_error(const pc2_vk *ctx);
#ifdef __cplusplus
}
#endif
#endif
