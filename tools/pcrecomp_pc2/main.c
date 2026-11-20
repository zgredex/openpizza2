#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "host.h"
#include "win32hle.h"
#include "ddraw_int.h"

int pc2_register_shims(void);

static uint32_t pc2_checksum(const uint8_t *p, size_t n) {
    uint32_t h = 2166136261u;
    for (size_t i = 0; i < n; i++) h = (h ^ p[i]) * 16777619u;
    return h;
}

static int pc2_blit_hook(surf_t *d, int dl, int dt, int dr, int db,
                         surf_t *s, int sl, int st, int sr, int sb,
                         int keyed, uint32_t klo, uint32_t khi) {
    static int n;
    if (n++ >= 20) return 0;
    uint32_t src_sum = s && s->px ? pc2_checksum(s->px, (size_t)s->pitch * (size_t)s->h) : 0;
    uint32_t dst_sum = d && d->px ? pc2_checksum(d->px, (size_t)d->pitch * (size_t)d->h) : 0;
    fprintf(stderr,
            "[trace] DDBLT d=%u primary=%d %dx%d bpp=%d pitch=%d rect=%d,%d..%d,%d "
            "s=%u %dx%d bpp=%d pitch=%d rect=%d,%d..%d,%d keyed=%d srcsum=%08X dstsum=%08X\n",
            d ? d->self : 0, d ? d->primary : 0, d ? d->w : 0, d ? d->h : 0,
            d ? d->bpp : 0, d ? d->pitch : 0, dl, dt, dr, db,
            s ? s->self : 0, s ? s->w : 0, s ? s->h : 0, s ? s->bpp : 0,
            s ? s->pitch : 0, sl, st, sr, sb, keyed, src_sum, dst_sum);
    return 0;
}

static int pc2_saw_menu;

static int pc2_cursor_hook(void) {
    return hle_cursor_shown();
}

static const uint8_t *pc2_dd_frame_hook(surf_t *primary) {
    static int n;
    if (n++ < 4) {
        fprintf(stderr, "[trace] DDPRIMARY self=%u %dx%d bpp=%d pitch=%d sum=%08X\n",
                primary ? primary->self : 0, primary ? primary->w : 0,
                primary ? primary->h : 0, primary ? primary->bpp : 0,
                primary ? primary->pitch : 0,
                primary && primary->px ? pc2_checksum(primary->px,
                    (size_t)primary->pitch * (size_t)primary->h) : 0);
    }
    if (pc2_saw_menu) {
        uint32_t ui = MEM32(0x0057C5E0);
        uint32_t renderer = ui ? MEM32(ui + 0xC) : 0;
        uint32_t buf = renderer ? MEM32(renderer + 0x28) : 0;
        if (buf) return (const uint8_t *)(uintptr_t)ADDR(buf);
    }
    return NULL;
}

static void pc2_dump_renderer(const char *path, int tag) {
    uint32_t ui = MEM32(0x0057C5E0);
    uint32_t renderer = ui ? MEM32(ui + 0xC) : 0;
    uint32_t buf = renderer ? MEM32(renderer + 0x28) : 0;
    if (!buf) return;
    const uint16_t *rp = (const uint16_t *)(uintptr_t)ADDR(buf);
    char name[1200];
    snprintf(name, sizeof name, "%s.%d", path, tag);
    FILE *rf = fopen(name, "wb");
    if (!rf) return;
    fprintf(rf, "P6\n800 600\n255\n");
    for (int y = 0; y < 600; y++)
        for (int x = 0; x < 800; x++) {
            uint16_t v = rp[(size_t)y * 800 + x];
            unsigned char rgb[3] = {
                (unsigned char)(((v >> 11) & 0x1f) * 255 / 31),
                (unsigned char)(((v >> 5) & 0x3f) * 255 / 63),
                (unsigned char)((v & 0x1f) * 255 / 31)};
            fwrite(rgb, 1, 3, rf);
        }
    fclose(rf);
    fprintf(stderr, "[trace] raw renderer dump %s buf=%X\n", name, buf);
}

static int pc2_raw_done;
static int pc2_raw_char_done;
static int pc2_char_seen;
static int pc2_char_clicked;
static int pc2_mission_seen;
static int pc2_mission_clicked;
static int pc2_started;
static void pc2_poll(void) {
    uint32_t pending = MEM32(0x0056386C);
    if (pending == 21) pc2_saw_menu = 1;
    if (pending == 28) pc2_char_seen = 1;
    if (pending == 22) pc2_mission_seen = 1;
    const char *path = getenv("PC2_RAW_DUMP");
    if (path && pc2_saw_menu && pending == 0 && !pc2_raw_done) {
        pc2_dump_renderer(path, 100);
        pc2_raw_done = 1;
    }
    if (getenv("PC2_CLICK_START") && pending == 28 && path && !pc2_raw_char_done) {
        pc2_dump_renderer(path, 200);
        pc2_raw_char_done = 1;
    }
    if (getenv("PC2_CLICK_START") && pc2_char_seen && pending == 0 && path) {
        static int after_char;
        if (!after_char) {
            pc2_dump_renderer(path, 300);
            after_char = 1;
        }
    }
    if (getenv("PC2_START_CAMPAIGN") && pc2_char_seen && pending == 0 && !pc2_char_clicked) {
        uint32_t hwnd = hle_first_hwnd();
        if (hwnd) {
            uint32_t lp = ((566u & 0xffffu) << 16) | (700u & 0xffffu);
            hle_post_message(hwnd, 0x0200, 0, lp);
            hle_post_message(hwnd, 0x0201, 1, lp);
            hle_post_message(hwnd, 0x0202, 0, lp);
            pc2_char_clicked = 1;
            fprintf(stderr, "[trace] scripted click Start game at 700,566\n");
        }
    }
    if (getenv("PC2_START_CAMPAIGN") && pc2_mission_seen && pending == 0 && !pc2_mission_clicked) {
        static int mission_polls;
        if (++mission_polls < 4) return;
        uint32_t hwnd = hle_first_hwnd();
        if (hwnd) {
            uint32_t lp = ((560u & 0xffffu) << 16) | (680u & 0xffffu);
            hle_post_message(hwnd, 0x0200, 0, lp);
            hle_post_message(hwnd, 0x0201, 1, lp);
            hle_post_message(hwnd, 0x0202, 0, lp);
            pc2_mission_clicked = 1;
            fprintf(stderr, "[trace] scripted click Start Mission at 680,560\n");
        }
    }
    if (getenv("PC2_START_CAMPAIGN") && pc2_mission_clicked && path) {
        static int game_polls;
        static int game_dumped;
        const char *delay = getenv("PC2_GAME_DUMP_DELAY");
        int target = delay && *delay ? atoi(delay) : 300;
        if (!game_dumped && ++game_polls >= target) {
            pc2_dump_renderer(path, 400);
            game_dumped = 1;
        }
    }
    if (getenv("PC2_CLICK_START") && pc2_saw_menu && pending == 0 && !pc2_started) {
        uint32_t hwnd = hle_first_hwnd();
        if (hwnd) {
            uint32_t lp = ((18u & 0xffffu) << 16) | (650u & 0xffffu);
            hle_post_message(hwnd, 0x0200, 0, lp);
            hle_post_message(hwnd, 0x0201, 1, lp);
            hle_post_message(hwnd, 0x0202, 0, lp);
            pc2_started = 1;
            fprintf(stderr, "[trace] scripted click Start new game at 650,18\n");
        }
    }
}

static void pc2_frame_hook(const uint8_t *px, int w, int h, int pitch, int bpp) {
    static int shown;
    static int dumped;
    size_t bytes = (size_t)pitch * (size_t)h;
    if (shown < 8) {
        size_t nonzero = 0;
        for (size_t i = 0; i < bytes; i++) nonzero += px[i] != 0;
        fprintf(stderr, "[trace] frame %d %dx%d bpp=%d nonzero=%zu/%zu\n",
                shown, w, h, bpp, nonzero, bytes);
    }
    shown++;
    const char *path = getenv("PC2_FRAME_DUMP");
    if (path && pc2_saw_menu && MEM32(0x0056386C) == 0 && !dumped && bpp == 16) {
        FILE *f = fopen(path, "wb");
        if (f) {
            fprintf(f, "P6\n%d %d\n255\n", w, h);
            for (int y = 0; y < h; y++) {
                const uint16_t *row = (const uint16_t *)(px + (size_t)y * pitch);
                for (int x = 0; x < w; x++) {
                    uint16_t v = row[x];
                    unsigned char rgb[3] = {
                        (unsigned char)(((v >> 11) & 0x1f) * 255 / 31),
                        (unsigned char)(((v >> 5) & 0x3f) * 255 / 63),
                        (unsigned char)((v & 0x1f) * 255 / 31)};
                    fwrite(rgb, 1, 3, f);
                }
            }
            fclose(f);
            dumped = 1;
            fprintf(stderr, "[trace] frame dump %s\n", path);
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <image.exe>\n", argv[0]);
        return 64;
    }

    recomp_host_init();
    pc2_register_shims();

    /* PC2 writes a scratch sprite to C:\test.spr while building its loading
     * screen. Map C: to a writable host directory so that path exists. */
    const char *cdrive = getenv("PC2_CDRIVE");
    if (!cdrive || !*cdrive) cdrive = "/tmp/opencode/pc2-cdrive";
    mkdir(cdrive, 0755);
    hle_set_drive('C', cdrive);

    /* WinMain derives its base directory from GetCommandLineA(). The runtime's
     * default "game.exe" has no separator, which leaves the game looking for
     * "gresources\\main.pak". Give it the real guest path. */
    char guest[1024];
    char cmdline[1100];
    hle_guest_path(argv[1], guest, sizeof guest);
    snprintf(cmdline, sizeof cmdline, "\"%s\"", guest);
    hle_set_command_line(cmdline);

    if (recomp_host_boot_permissive(argv[1]) != 0) {
        return 1;
    }

    /* PC2's window proc enables rendering on its first window message. The
     * headless host does not generate that message, so arm the flag once. */
    MEM32(0x00584504) = 1;
    MEM32(0x005844FC) = 0;

    hle_dd_blit_hook = pc2_blit_hook;
    hle_dd_frame_hook = pc2_dd_frame_hook;
    hle_screen_cursor_hook = pc2_cursor_hook;

    int headless = getenv("PC2_HEADLESS") != NULL;
    if (getenv("PC2_TRACE_FRAMES")) hle_screen_frame_hook = pc2_frame_hook;
    if (hle_screen_open("Pizza Connection 2", 0, headless) != 0) {
        return 2;
    }
    hle_screen_poll_hook = pc2_poll;

    return (int)recomp_host_run();
}
