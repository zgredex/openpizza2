// Sound_SetPosition: ported from Pizza Connection 2 at 0x5472a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5472a0
#include "pc2_port.h"

void __thiscall Sound_SetPosition(void *self,uint32_t arg1)

{
  int *ptr1;
  int value2;
  int64_t lvalue3;
  
  if (*(int *)((intptr_t)self + 0x1d0) != 0) {
    ptr1 = *(int **)((intptr_t)self + 8);
    value2 = *ptr1;
    lvalue3 = __ftol();
    (**(code **)(value2 + 0x7c))(ptr1,arg1,(intptr_t)lvalue3);
    (**(code **)(**(int **)((intptr_t)self + 8) + 0x58))(*(int **)((intptr_t)self + 8),arg1,0);
  }
  return;
}
