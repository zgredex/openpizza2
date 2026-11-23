// Stats_GetMatrixVariantValue: ported from Pizza Connection 2 at 0x47a850.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47a850
#include "pc2_port.h"

int __thiscall Stats_GetMatrixVariantValue(void *self,uint32_t arg1,int arg2,int arg3)

{
  switch(arg1) {
  case 0:
    return *(int *)((intptr_t)self + (arg2 + arg3 * 9) * 4 + 5000);
  case 1:
    return *(int *)((intptr_t)self + (arg2 + arg3 * 9) * 4 + 0x13d0);
  case 2:
    return *(int *)((intptr_t)self + (arg2 + arg3 * 9) * 4 + 0x1418);
  case 3:
    return *(int *)((intptr_t)self + (arg2 + arg3 * 9) * 4 + 0x1460);
  default:
    return arg3;
  }
}
