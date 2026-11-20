#include <stdio.h>
#include <stdlib.h>

#include "host.h"
#include "win32hle.h"

int pc2_register_shims(void);

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <image.exe>\n", argv[0]);
        return 64;
    }

    recomp_host_init();
    pc2_register_shims();

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

    int headless = getenv("PC2_HEADLESS") != NULL;
    if (hle_screen_open("Pizza Connection 2", 0, headless) != 0) {
        return 2;
    }

    return (int)recomp_host_run();
}
