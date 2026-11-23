// Market_GetPriceModifier: ported from Pizza Connection 2 at 0x4dbfc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dbfc0
#include "pc2_port.h"

int __thiscall Market_GetPriceModifier(void *self,int arg1,int arg2)

{
  int value1;
  
  value1 = *(int *)((intptr_t)self + (arg2 + 0xa0 + arg1 * 8) * 4);
  if (value1 == 0) {
    return 0;
  }
  return (-(uint32_t)(value1 != 1) & 0xffffffec) + 10;
}
