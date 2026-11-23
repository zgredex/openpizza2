#ifndef PC2_VULKAN_H
#define PC2_VULKAN_H

struct SDL_Window;

/* Native Vulkan window, presentation and input pump for the recovered game.
 * The module owns the SDL window and the Vulkan instance/device/swapchain; the
 * guest still supplies its DirectDraw RGB565 framebuffer through win32hle.
 * There is no win32hle window, SDL renderer, frame hook or GL bridge here. */

int  pc2_vulkan_open(const char *title, void (*poll)(void),
                     void (*present)(void));
int  pc2_vulkan_present(const unsigned char *pixels, int w, int h, int pitch,
                        int bpp, int menu_ready);
void pc2_vulkan_pump(void);
void pc2_vulkan_viewport(int *x, int *y, int *w, int *h);
struct SDL_Window *pc2_vulkan_window(void);
void pc2_vulkan_shutdown(void);
int  pc2_vulkan_active(void);

#endif
