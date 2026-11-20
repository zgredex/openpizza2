#include <stdio.h>

/* The generated CRT entry calls WinMain directly (0x0054FDAF -> 0x00403D90).
 * Linker --wrap gives a trace point without touching generated C. */
void __real_sub_00403D90(void);

void __wrap_sub_00403D90(void) {
    fprintf(stderr, "[trace] entered WinMain at 0x00403D90\n");
    fflush(stderr);
    __real_sub_00403D90();
}
