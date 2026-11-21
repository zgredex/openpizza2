#include "../reconstructed/leaf/leaf_functions.h"

/* Adapt the existing portable C routines to the callee-cleanup PE ABI. */
void __attribute__((stdcall)) pc2_clamp_0_100(int32_t *value) {
    clamp_0_100(value);
}

int32_t __attribute__((stdcall))
pc2_distance_manhattan3(int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
    return distance_manhattan3(x1, y1, x2, y2);
}
