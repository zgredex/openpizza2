// Sound_PlayChannel: ported from Pizza Connection 2 at 0x547340.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x547340
#include "pc2_port.h"

void __thiscall Sound_PlayChannel(void *self,uint32_t arg1,int arg2)

{
  int value1;
  int *ptr2;
  int64_t lvalue3;
  int unaff_retaddr;
  int *ptr4;
  uint32_t *uptr5;
  uint32_t local_c;
  int iStack_8;
  
  local_c = 0;
  if (arg2 == 1) {
    value1 = *(int *)((intptr_t)self + 0x1d0);
  }
  else if (arg2 == 2) {
    value1 = *(int *)((intptr_t)self + 0x1d4);
  }
  else {
    if (arg2 != 3) goto LAB_00547384;
    value1 = *(int *)((intptr_t)self + 0x1d8);
  }
  if (value1 == 0) {
    return;
  }
LAB_00547384:
  ptr4 = *(int **)((intptr_t)self + 8);
  uptr5 = &local_c;
  (**(code **)(*ptr4 + 0x34))(ptr4,arg1,1,uptr5);
  if (unaff_retaddr != 0) {
    (**(code **)(**(int **)((intptr_t)self + 8) + 0xa0))(*(int **)((intptr_t)self + 8),unaff_retaddr,uptr5);
  }
  ptr2 = *(int **)((intptr_t)self + 8);
  iStack_8 = *ptr2;
  lvalue3 = __ftol();
  (**(code **)(iStack_8 + 0x80))(ptr2,uptr5,(intptr_t)lvalue3);
  (**(code **)(**(int **)((intptr_t)self + 8) + 100))(*(int **)((intptr_t)self + 8),ptr4);
  return;
}
