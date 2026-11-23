#ifndef PC2_NATIVE_MOVIE_H
#define PC2_NATIVE_MOVIE_H
#include <stddef.h>
#include <stdint.h>
#include "pc2_vk.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct pc2_movie pc2_movie;
/* Open a Bink 1 movie directly from the movie.pak entry's decompressed bytes.
 * Input memory must stay valid until pc2_movie_close. No Bink DLL is loaded. */
pc2_movie *pc2_movie_open_memory(const uint8_t *bytes, size_t length);
void pc2_movie_close(pc2_movie *m);
/* Must be called before close when the movie has been drawn. */
void pc2_movie_release_gpu(pc2_movie *m, pc2_vk *renderer);
/* Decode one video frame, queueing Bink audio to SDL where available.
 * 1 = frame ready, 0 = EOF, -1 = decoding error. */
int pc2_movie_next(pc2_movie *m, const uint8_t **rgba, uint32_t *w,
                   uint32_t *h, double *presentation_seconds);
/* Direct GPU path: create/update a Vulkan video texture, draw onto the same
 * Vulkan swapchain as game sprites. Call only between active game frames. */
int pc2_movie_draw(pc2_movie *m, pc2_vk *renderer, const uint8_t *rgba,
                   uint32_t w, uint32_t h);
/* Seconds elapsed since the first frame was presented; caller owns event loop. */
void pc2_movie_reset_clock(pc2_movie *m);
double pc2_movie_clock(const pc2_movie *m);
const char *pc2_movie_error(const pc2_movie *m);
#ifdef __cplusplus
}
#endif
#endif
