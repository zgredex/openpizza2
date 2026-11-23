// Game_ComputeEventValue: ported from Pizza Connection 2 at 0x4e5f40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e5f40
#include "pc2_port.h"

int __thiscall Game_ComputeEventValue(void *self,int arg1,int *arg2)

{
  int value1;
  int64_t lvalue2;
  
  value1 = IDMap_Lookup((void *)(DAT_0057c670 + 0x74),*(int *)((intptr_t)self + 4),(int *)0x0);
  Game_ComputePrice(value1,arg1);
  if (arg2 != (int *)0x0) {
    lvalue2 = __ftol();
    *arg2 = (intptr_t)lvalue2;
  }
  if (*(int *)((intptr_t)self + 0xc) == 100) {
    return 0;
  }
  if (*(int *)((intptr_t)self + 0xc) < 1) {
    if (arg2 != (int *)0x0) {
      *arg2 = 0;
    }
    lvalue2 = __ftol();
    return (intptr_t)lvalue2;
  }
  __ftol();
  lvalue2 = __ftol();
  value1 = (intptr_t)((intptr_t)lvalue2 + ((intptr_t)lvalue2 >> 0x1f & 3U)) >> 2;
  if (arg2 == (int *)0x0) {
    return value1;
  }
  lvalue2 = __ftol();
  *arg2 = (intptr_t)lvalue2 - value1;
  return value1;
}
