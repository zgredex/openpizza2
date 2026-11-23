// UI_HitTestChildPoint: ported from Pizza Connection 2 at 0x50b090.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50b090
#include "pc2_port.h"

uint32_t __thiscall UI_HitTestChildPoint(void *self,float arg1)

{
  int *ptr1;
  uint32_t uvalue2;
  void *local_4;
  
  ptr1 = *(int **)((intptr_t)arg1 + 200);
  if ((ptr1 == (int *)0x0) || ((void *)ptr1[0x16] == (void *)0x0)) {
    return 0;
  }
  local_4 = self;
  Record_GetTwoFloats48((void *)ptr1[0x16],*ptr1,&arg1,&local_4);
  arg1 = (float)((intptr_t)arg1 + *(int *)(*(int *)((intptr_t)self + 0xc4) + 0xf8));
  local_4 = (void *)((intptr_t)local_4 + *(int *)(*(int *)((intptr_t)self + 0xc4) + 0xfc));
  uvalue2 = UI_ComputeObjectDirection(self,arg1,(intptr_t)local_4);
  return uvalue2;
}
