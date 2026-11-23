// UI_IsValidSize: ported from Pizza Connection 2 at 0x520b60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x520b60
#include "pc2_port.h"

uint32_t __thiscall UI_IsValidSize(void *self,int arg1,int arg2)

{
  uint32_t uvalue1;
  
  if (*(int *)((intptr_t)self + 0x18) != 0) {
    return 1;
  }
  if ((((*(int *)((intptr_t)self + 0x20) == 0) || (*(int *)((intptr_t)self + 0x14) == 0)) ||
      (arg1 < *(int *)((intptr_t)self + 0x28))) ||
     (((*(int *)((intptr_t)self + 0x30) <= arg1 || (arg2 < *(int *)((intptr_t)self + 0x2c))) ||
      (*(int *)((intptr_t)self + 0x34) <= arg2)))) {
    return 0;
  }
  uvalue1 = (**(code **)(*(int *)self + 0x10))
                    (arg1 - *(int *)((intptr_t)self + 0x38),arg2 - *(int *)((intptr_t)self + 0x3c));
  return uvalue1;
}
