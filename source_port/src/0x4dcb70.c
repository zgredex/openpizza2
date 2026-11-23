// Random_SwapOneOfFour: ported from Pizza Connection 2 at 0x4dcb70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dcb70
#include "pc2_port.h"

uint32_t __thiscall Random_SwapOneOfFour(void *self,int arg1,uint32_t arg2,uint32_t arg3)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  
  uvalue2 = 0;
  do {
    uvalue1 = Random_RangeFast(0,3);
  } while (uvalue1 == arg2);
  switch(uvalue1) {
  case 0:
    uvalue2 = *(uint32_t *)((intptr_t)self + arg1 * 4 + 0x200);
    *(uint32_t *)((intptr_t)self + arg1 * 4 + 0x200) = arg3;
    return uvalue2;
  case 1:
    uvalue2 = *(uint32_t *)((intptr_t)self + arg1 * 4 + 0x240);
    *(uint32_t *)((intptr_t)self + arg1 * 4 + 0x240) = arg3;
    return uvalue2;
  case 2:
    uvalue2 = *(uint32_t *)((intptr_t)self + arg1 * 4 + 0x220);
    *(uint32_t *)((intptr_t)self + arg1 * 4 + 0x220) = arg3;
    return uvalue2;
  case 3:
    uvalue2 = *(uint32_t *)((intptr_t)self + arg1 * 4 + 0x260);
    *(uint32_t *)((intptr_t)self + arg1 * 4 + 0x260) = arg3;
  }
  return uvalue2;
}
