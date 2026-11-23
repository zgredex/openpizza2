// Game_GetCostForType: ported from Pizza Connection 2 at 0x4d4330.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d4330
#include "pc2_port.h"

int __thiscall Game_GetCostForType(void *self,uint32_t arg1)

{
  switch(arg1) {
  case 0:
    return (*(int *)((intptr_t)self + 4) * *(int *)((intptr_t)self + 4)) / 10;
  case 1:
    return 0x32;
  case 2:
    return 500;
  case 3:
    return (*(int *)((intptr_t)self + 8) * *(int *)((intptr_t)self + 8)) / 10;
  default:
    return 0;
  }
}
