// Sound_StopAmbientBuffers: ported from Pizza Connection 2 at 0x5484b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5484b0
#include "pc2_port.h"

void __fastcall Sound_StopAmbientBuffers(int arg1)

{
  if (((*(char *)(arg1 + 0xfc) != '\0') && (*(char *)(arg1 + 0x16a) != '\0')) &&
     (*(uint8_t *)(arg1 + 0x16a) = 0, *(int *)(arg1 + 0x1d0) != 0)) {
    (**(code **)(**(int **)(arg1 + 8) + 0x68))
              (*(int **)(arg1 + 8),*(uint32_t *)(arg1 + 0x88));
    (**(code **)(**(int **)(arg1 + 8) + 0x68))
              (*(int **)(arg1 + 8),*(uint32_t *)(arg1 + 0x8c));
    (**(code **)(**(int **)(arg1 + 8) + 0xa8))
              (*(int **)(arg1 + 8),*(uint32_t *)(arg1 + 0xf4));
  }
  return;
}
