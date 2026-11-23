// State_HasPositive: ported from Pizza Connection 2 at 0x4d42e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d42e0
#include "pc2_port.h"

uint32_t __fastcall State_HasPositive(int arg1)

{
  return CONCAT31((int3)((uint32_t)*(int *)(arg1 + 0x20) >> 8),0 < *(int *)(arg1 + 0x20));
}
