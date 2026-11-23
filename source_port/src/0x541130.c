// Sound_SetVolumeLogarithmic: ported from Pizza Connection 2 at 0x541130.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x541130
#include "pc2_port.h"

uint32_t __thiscall Sound_SetVolumeLogarithmic(void *self,int arg1)

{
  uint32_t uvalue1;
  int value2;
  int64_t lvalue3;
  
  uvalue1 = 0;
  if (arg1 != 0) {
    if (arg1 < 0) {
      if (arg1 < -9999) {
        uvalue1 = 0xffffd8f0;
        goto LAB_0054119e;
      }
      log2((double)10000.0 / (double)(arg1 + 10000));
    }
    else {
      uvalue1 = 10000;
      if (9999 < arg1) goto LAB_0054119e;
      log2((double)10000.0 / (double)(10000 - arg1));
    }
    lvalue3 = __ftol();
    uvalue1 = (uint32_t)lvalue3;
  }
LAB_0054119e:
  value2 = (**(code **)(**(int **)((intptr_t)self + 0x48) + 0x40))(*(int **)((intptr_t)self + 0x48),uvalue1);
  return (-1 < value2) - 1 & 0x80070057;
}
