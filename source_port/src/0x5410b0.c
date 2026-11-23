// Sound_SetBufferVolume: ported from Pizza Connection 2 at 0x5410b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5410b0
#include "pc2_port.h"

uint32_t __thiscall Sound_SetBufferVolume(void *self,uint32_t arg1)

{
  int value1;
  uint32_t uvalue2;
  int64_t lvalue3;
  
  uvalue2 = 0xffffd8f0;
  if (10000 < arg1) {
    return 0x80070057;
  }
  if (arg1 != 0) {
    log2(ABS((double)-10000.0) / (double)arg1);
    lvalue3 = __ftol();
    uvalue2 = (uint32_t)lvalue3;
  }
  value1 = (**(code **)(**(int **)((intptr_t)self + 0x48) + 0x3c))(*(int **)((intptr_t)self + 0x48),uvalue2);
  return (-1 < value1) - 1 & 0x80070057;
}
