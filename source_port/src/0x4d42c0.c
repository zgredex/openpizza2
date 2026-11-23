// State_HasFlags: ported from Pizza Connection 2 at 0x4d42c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d42c0
#include "pc2_port.h"

uint32_t __fastcall State_HasFlags(int arg1)

{
  if (*(int *)(arg1 + 0x14) < 1) {
    return CONCAT31((int3)((uint32_t)*(int *)(arg1 + 0x18) >> 8),0 < *(int *)(arg1 + 0x18));
  }
  return CONCAT31((int3)((uint32_t)*(int *)(arg1 + 0x14) >> 8),1);
}
