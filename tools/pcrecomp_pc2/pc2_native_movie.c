/*
 * Native movie playback for the recovered game's Movie_Play entry.
 *
 * The movie bytes stay in the shipped movie.pak. A small reader finds the
 * requested entry, the patched-in pc2_movie decoder (FFmpeg's Bink decoder)
 * produces RGBA frames, and the frames are presented through the native
 * Vulkan window. There is no binkw32.dll, no DirectDraw and no win32hle movie
 * player in this path.
 */
#include "pc2_native_movie.h"

#include "pc2_movie.h"
#include "pc2_vulkan.h"
#include "win32hle.h"

#include <SDL2/SDL.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define PAK_HEADER 0x6c
#define PAK_ENTRY 0x14

/* bink.c is excluded; the host still registers this table before the PC2
 * shim table. The actual safe stubs live in pc2_shims.c. */
const win32hle_shim win32hle_bink[] = { { 0, 0 } };

static char g_root[1024] = ".";

static void capture_frame(const uint8_t *rgba, uint32_t w, uint32_t h)
{
    const char *path = getenv("PC2_MOVIE_CAPTURE");
    if (!path || !*path) return;
    FILE *f = fopen(path, "wb");
    if (!f) return;
    fprintf(f, "P6\n%u %u\n255\n", w, h);
    for (uint32_t y = 0; y < h; y++) {
        const uint8_t *row = rgba + (size_t)y * w * 4;
        for (uint32_t x = 0; x < w; x++)
            fwrite(row + (size_t)x * 4, 1, 3, f);
    }
    fclose(f);
    fprintf(stderr, "[native-movie] captured %s %ux%u\n", path, w, h);
}

void pc2_native_movie_set_root(const char *asset_root)
{
    if (!asset_root || !*asset_root) return;
    snprintf(g_root, sizeof(g_root), "%s", asset_root);
    size_t n = strlen(g_root);
    while (n > 1 && g_root[n - 1] == '/') g_root[--n] = 0;
}

static uint32_t rd32(const uint8_t *p)
{
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

typedef struct {
    FILE *fp;
    uint8_t *index;
    uint32_t index_size;
    uint32_t count;
    uint32_t names_base;
} Pak;

static void pak_close(Pak *pak)
{
    if (!pak) return;
    if (pak->fp) fclose(pak->fp);
    free(pak->index);
    memset(pak, 0, sizeof(*pak));
}

static int pak_open(Pak *pak, const char *path)
{
    memset(pak, 0, sizeof(*pak));
    FILE *f = fopen(path, "rb");
    if (!f) return 0;
    uint8_t header[PAK_HEADER];
    if (fread(header, 1, sizeof(header), f) != sizeof(header) ||
        memcmp(header, "ResourceFile-ID-7654\n\r\x1a", 23) != 0) {
        fclose(f);
        return 0;
    }
    uint32_t index_size = rd32(header + 0x60);
    uint32_t obfuscated = rd32(header + 0x68);
    if (!index_size || index_size > 16u * 1024u * 1024u) {
        fclose(f);
        return 0;
    }
    uint8_t *encoded = malloc(index_size);
    uint8_t *decoded = malloc(index_size);
    if (!encoded || !decoded ||
        fread(encoded, 1, index_size, f) != index_size) {
        free(encoded);
        free(decoded);
        fclose(f);
        return 0;
    }
    if (obfuscated) {
        for (uint32_t i = 0; i < index_size; i++)
            decoded[i] = (uint8_t)((((encoded[i] - (i & 0xff)) & 0xff) ^ 0xaa));
    } else {
        memcpy(decoded, encoded, index_size);
    }
    free(encoded);
    uint32_t count = index_size >= 4 ? rd32(decoded) : 0;
    uint32_t names_base = 4 + count * PAK_ENTRY;
    if (index_size < 4 || names_base > index_size) {
        free(decoded);
        fclose(f);
        return 0;
    }
    pak->fp = f;
    pak->index = decoded;
    pak->index_size = index_size;
    pak->count = count;
    pak->names_base = names_base;
    return 1;
}

static int pak_find(Pak *pak, const char *name, uint32_t *size, uint32_t *rel)
{
    for (uint32_t i = 0; i < pak->count; i++) {
        const uint8_t *e = pak->index + 4 + i * PAK_ENTRY;
        uint32_t start = pak->names_base + rd32(e + 0x10);
        if (start >= pak->index_size) continue;
        const char *candidate = (const char *)(pak->index + start);
        if (strcasecmp(candidate, name) == 0) {
            *size = rd32(e + 8);
            *rel = rd32(e + 0x0c);
            return 1;
        }
    }
    return 0;
}

static uint8_t *pak_read(Pak *pak, const char *name, size_t *length)
{
    uint32_t size = 0, rel = 0;
    if (!pak_find(pak, name, &size, &rel) || !size) return NULL;
    uint8_t *data = malloc((size_t)size + 1);
    if (!data) return NULL;
    if (fseek(pak->fp, (long)(PAK_HEADER + rel), SEEK_SET) != 0 ||
        fread(data, 1, size, pak->fp) != size) {
        free(data);
        return NULL;
    }
    data[size] = 0;
    *length = size;
    return data;
}

static uint8_t *read_loose(const char *path, size_t *length)
{
    FILE *f = fopen(path, "rb");
    if (!f) return NULL;
    if (fseek(f, 0, SEEK_END) != 0) { fclose(f); return NULL; }
    long n = ftell(f);
    if (n <= 0) { fclose(f); return NULL; }
    rewind(f);
    uint8_t *data = malloc((size_t)n + 1);
    if (!data) { fclose(f); return NULL; }
    if (fread(data, 1, (size_t)n, f) != (size_t)n) {
        free(data);
        fclose(f);
        return NULL;
    }
    fclose(f);
    data[n] = 0;
    *length = (size_t)n;
    return data;
}

static uint8_t *load_movie(const char *name, size_t *length)
{
    char path[1200];
    char entry[512];
    if (strncasecmp(name, "movies\\", 7) == 0 ||
        strncasecmp(name, "movies/", 7) == 0) {
        snprintf(entry, sizeof(entry), "%s", name);
    } else {
        snprintf(entry, sizeof(entry), "movies\\%s", name);
    }
    for (int i = 0; entry[i]; i++)
        if (entry[i] == '/') entry[i] = '\\';

    snprintf(path, sizeof(path), "%s/Resources/movie.pak", g_root);
    Pak pak;
    if (pak_open(&pak, path)) {
        uint8_t *data = pak_read(&pak, entry, length);
        pak_close(&pak);
        if (data) return data;
    }
    snprintf(path, sizeof(path), "%s/movie.pak", g_root);
    if (pak_open(&pak, path)) {
        uint8_t *data = pak_read(&pak, entry, length);
        pak_close(&pak);
        if (data) return data;
    }
    snprintf(path, sizeof(path), "%s/%s", g_root, name);
    return read_loose(path, length);
}

/* The game hands Movie_Play a movie name such as "s2000_s.bik"; its window
 * object lives in guest memory and is not needed by the native player. */
void pc2_native_movie_play(void)
{
    const char *name = ASTR(1);
    if (!name || !*name) {
        RET(0, 0);
        return;
    }
    if (getenv("PC2_HEADLESS")) {
        fprintf(stderr, "[native-movie] %s skipped (headless)\n", name);
        RET(0, 0);
        return;
    }

    size_t length = 0;
    uint8_t *bytes = load_movie(name, &length);
    if (!bytes) {
        fprintf(stderr, "[native-movie] missing %s\n", name);
        RET(0, 0);
        return;
    }
    pc2_movie *movie = pc2_movie_open_memory(bytes, length);
    if (!movie) {
        fprintf(stderr, "[native-movie] cannot decode %s\n", name);
        free(bytes);
        RET(0, 0);
        return;
    }

    pc2_movie_reset_clock(movie);
    int running = 1, frames = 0;
    while (running) {
        const uint8_t *rgba = NULL;
        uint32_t w = 0, h = 0;
        double pts = 0.0;
        int result = pc2_movie_next(movie, &rgba, &w, &h, &pts);
        if (result <= 0) {
            if (result < 0)
                fprintf(stderr, "[native-movie] %s: %s\n", name,
                        pc2_movie_error(movie));
            break;
        }
        while (pc2_movie_clock(movie) < pts && running) {
            SDL_PumpEvents();
            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    running = 0;
                } else if (event.type == SDL_KEYDOWN &&
                           (event.key.keysym.sym == SDLK_ESCAPE ||
                            event.key.keysym.sym == SDLK_SPACE)) {
                    running = 0;
                } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                    running = 0;
                }
            }
            if (running) SDL_Delay(1);
        }
        if (!running) break;
        if (rgba && w && h) {
            static int captured, frame_index;
            if (!captured && frame_index == 30) { capture_frame(rgba, w, h); captured = 1; }
            frame_index++;
            uint16_t *frame = malloc((size_t)w * h * 2);
            if (frame) {
                for (uint32_t y = 0; y < h; y++) {
                    const uint8_t *src = rgba + (size_t)y * w * 4;
                    uint16_t *dst = frame + (size_t)y * w;
                    for (uint32_t x = 0; x < w; x++) {
                        uint8_t r = src[x * 4 + 0] >> 3;
                        uint8_t g = src[x * 4 + 1] >> 2;
                        uint8_t b = src[x * 4 + 2] >> 3;
                        dst[x] = (uint16_t)((r << 11) | (g << 5) | b);
                    }
                }
                pc2_vulkan_present((const unsigned char *)frame, (int)w, (int)h,
                                   (int)w * 2, 16, 0);
                free(frame);
            }
        }
        frames++;
    }
    fprintf(stderr, "[native-movie] %s: %d frames\n", name, frames);
    pc2_movie_release_gpu(movie, NULL);
    pc2_movie_close(movie);
    free(bytes);
    RET(0, 0);
}
