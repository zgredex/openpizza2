// UI_ComputeObjectDirection: ported from Pizza Connection 2 at 0x50b100.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50b100
#include "pc2_port.h"

uint32_t __thiscall UI_ComputeObjectDirection(void *self,float arg1,int arg2)

{
  int *ptr1;
  int value2;
  int64_t lvalue3;
  float local_8;
  int local_4;
  
  ptr1 = *(int **)((intptr_t)self + 200);
  if (ptr1 == (int *)0x0) {
    return 0;
  }
  Record_GetTwoFloats48((void *)ptr1[0x16],*ptr1,&local_8,&local_4);
  value2 = (intptr_t)arg1 - ((intptr_t)local_8 + *(int *)(*(int *)((intptr_t)self + 0xc4) + 0xf8));
  local_8 = (float)value2;
  arg1 = (float)(arg2 - (local_4 + *(int *)(*(int *)((intptr_t)self + 0xc4) + 0xfc)));
  if (arg1 == 0.0) {
    arg1 = 1.0;
  }
  fpatan((double)value2 / (double)arg1,(double)1);
  lvalue3 = __ftol();
  return -(-(intptr_t)lvalue3 - 1U & 7) & 7;
}
