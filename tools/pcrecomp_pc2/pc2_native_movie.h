#ifndef PC2_NATIVE_MOVIE_PLAYER_H
#define PC2_NATIVE_MOVIE_PLAYER_H

#include <stdint.h>

/* The game's Movie_Play (0x4ce9d0) is replaced with this native path. */
void pc2_native_movie_set_root(const char *asset_root);
void pc2_native_movie_play(void);

#endif
