// MapView_GetRotation: ported from Pizza Connection 2 at 0x527ab0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x527ab0
#include "pc2_port.h"

uint32_t __fastcall MapView_GetRotation(int arg1)

{
  if (*(int *)(arg1 + 0x8310) == 0) {
    return 0;
  }
  return *(uint32_t *)(*(int *)(arg1 + 0x8310) + 0x24);
}
