/* Optional X11 readback regression for native source textures and clipping. */
#include "pc2_vk.h"
#include "pc2_sprite_decode.h"
#include <SDL2/SDL_syswm.h>
#include <X11/Xutil.h>
#include <stdio.h>

static unsigned channel(unsigned long pixel, unsigned long mask)
{
    while (mask && !(mask & 1)) {
        mask >>= 1;
        pixel >>= 1;
    }
    return mask ? (unsigned)((pixel & mask) * 255 / mask) : 0;
}

static int check_pixels(SDL_Window *window)
{
    SDL_SysWMinfo info;
    SDL_VERSION(&info.version);
    if (!SDL_GetWindowWMInfo(window, &info) || info.subsystem != SDL_SYSWM_X11) {
        fprintf(stderr, "source quad smoke requires an X11 Vulkan window\n");
        return 0;
    }
    const struct { int x, y; unsigned rgb; } expected[] = {
        {80, 100, 0}, {120, 100, 0}, {160, 100, 0x00ff00},
        {120, 140, 0xffffff}, {160, 140, 0xffff00},
        {260, 110, 0}, {300, 110, 0x0000ff}, {160, 500, 0},
        {420, 110, 0xff0000}, {460, 110, 0}, {500, 110, 0x0000ff},
    };
    for (unsigned retry = 0; retry < 40; ++retry) {
        SDL_PumpEvents();
        Display *display = info.info.x11.display;
        XImage *image = XGetImage(display, info.info.x11.window, 0, 0, 800, 600,
                                  AllPlanes, ZPixmap);
        if (!image) {
            fprintf(stderr, "cannot read back source quad smoke window\n");
            return 0;
        }
        int ok = 1;
        for (size_t i = 0; i < sizeof expected / sizeof *expected; ++i) {
            unsigned long pixel = XGetPixel(image, expected[i].x, expected[i].y);
            unsigned rgb = (channel(pixel, image->red_mask) << 16) |
                           (channel(pixel, image->green_mask) << 8) |
                            channel(pixel, image->blue_mask);
            if (rgb == expected[i].rgb) continue;
            ok = 0;
            if (retry == 39)
                fprintf(stderr, "pixel (%d,%d) #%06x, expected #%06x\n",
                        expected[i].x, expected[i].y, rgb, expected[i].rgb);
        }
        XDestroyImage(image);
        if (ok) return 1;
        SDL_Delay(25);
    }
    return 0;
}

static int draw_sources(pc2_vk *renderer)
{
    const unsigned char rgb565[] = {
        0x00, 0xf8, 0x1f, 0xf8, 0xe0, 0x07, 0x41, 0x42,
        0x1f, 0x00, 0xff, 0xff, 0xe0, 0xff, 0x51, 0x52,
    };
    if (!pc2_vk_begin(renderer, 0, 0, 0, 1)) return 0;
    pc2_vk_texture *sprite = pc2_vk_texture_create_rgb565(renderer, 3, 2, rgb565, 8, 0xf81f);
    if (!sprite) return 0;
    if (pc2_vk_texture_update_rgb565(renderer, sprite, rgb565, 8, -1)) {
        fprintf(stderr, "texture update accepted during active frame\n");
        pc2_vk_texture_destroy(renderer, sprite);
        return 0;
    }
    pc2_vk_draw_rect(renderer, sprite, 60, 80, 120, 80, 0, 0, 3, 2, 100, 80, 80, 80);
    pc2_vk_draw_rect(renderer, sprite, 240, 90, 80, 40, -1, 1, 2, 1, 0, 0, 800, 600);
    pc2_vk_texture_destroy(renderer, sprite);

    const uint8_t indexed[] = {1, 0xe6, 1, 2};
    const uint8_t palette[512] = { [3] = 0x7c, [4] = 0x1f };
    uint8_t rgba[12];
    if (!pc2_sprite_decode_indexed_rle(indexed, sizeof indexed, 3, 1, 0xe6,
                                      palette, sizeof palette, 0, rgba, sizeof rgba))
        return 0;
    sprite = pc2_vk_texture_create(renderer, 3, 1, rgba, sizeof rgba);
    if (!sprite) return 0;
    pc2_vk_draw_rect(renderer, sprite, 400, 90, 120, 40, 0, 0, 3, 1, 0, 0, 800, 600);
    pc2_vk_texture_destroy(renderer, sprite);
    return pc2_vk_end(renderer);
}

int main(void)
{
    SDL_setenv("SDL_VIDEODRIVER", "x11", 0);
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL init: %s\n", SDL_GetError());
        return 1;
    }
    SDL_Window *window = SDL_CreateWindow("PC2 source quad smoke", SDL_WINDOWPOS_CENTERED,
                                         SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_VULKAN);
    if (!window) {
        fprintf(stderr, "SDL window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    pc2_vk *renderer = pc2_vk_create(window, "shaders");
    int ok = renderer && draw_sources(renderer) && check_pixels(window);
    if (ok) puts("source quad smoke passed 11 pixel checks");
    pc2_vk_destroy(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return !ok;
}
