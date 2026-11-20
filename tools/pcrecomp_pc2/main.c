#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "host.h"
#include "win32hle.h"

int pc2_register_shims(void);

static void pc2_frame_hook(const uint8_t *px, int w, int h, int pitch, int bpp) {
    static int shown;
    if (shown >= 8) return;
    size_t bytes = (size_t)pitch * (size_t)h;
    size_t nonzero = 0;
    for (size_t i = 0; i < bytes; i++) nonzero += px[i] != 0;
    fprintf(stderr, "[trace] frame %d %dx%d bpp=%d nonzero=%zu/%zu\n",
            shown, w, h, bpp, nonzero, bytes);
    shown++;
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

    int headless = getenv("PC2_HEADLESS") != NULL;
    if (getenv("PC2_TRACE_FRAMES")) hle_screen_frame_hook = pc2_frame_hook;
    if (hle_screen_open("Pizza Connection 2", 0, headless) != 0) {
        return 2;
    }

    return (int)recomp_host_run();
}
