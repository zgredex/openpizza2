// State_GetFlags: ported from Pizza Connection 2 at 0x4d42f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d42f0
#include "pc2_port.h"

uint32_t __fastcall State_GetFlags(int arg1)

{
  if (*(uint32_t *)(arg1 + 0x14) != 0) {
    return *(uint32_t *)(arg1 + 0x14) & 0xffffff00;
  }
  if (*(uint32_t *)(arg1 + 0x18) == 0) {
    return CONCAT31((int3)((uint32_t)*(int *)(arg1 + 0x1c) >> 8),*(int *)(arg1 + 0x1c) == 0);
  }
  return *(uint32_t *)(arg1 + 0x18) & 0xffffff00;
}
