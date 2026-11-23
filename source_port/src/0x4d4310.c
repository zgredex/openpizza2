// State_IsNegative: ported from Pizza Connection 2 at 0x4d4310.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d4310
#include "pc2_port.h"

uint32_t __fastcall State_IsNegative(int arg1)

{
  if (*(int *)(arg1 + 0x14) < 0) {
    return CONCAT31((int3)((uint32_t)*(int *)(arg1 + 0x14) >> 8),1);
  }
  if (*(int *)(arg1 + 0x18) < 0) {
    return CONCAT31((int3)((uint32_t)*(int *)(arg1 + 0x18) >> 8),1);
  }
  return CONCAT31((int3)((uint32_t)*(int *)(arg1 + 0x1c) >> 8),*(int *)(arg1 + 0x1c) < 0);
}
