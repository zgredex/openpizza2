// Sound_Play: ported from Pizza Connection 2 at 0x547400.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x547400
#include "pc2_port.h"

uint32_t * __thiscall Sound_Play(void *self,uint32_t arg1,int arg2)

{
  int unaff_EDI;
  int value1;
  uint32_t *uptr2;
  uint32_t uvalue3;
  uint32_t local_4;
  
  value1 = 0;
  local_4 = 0;
  if (arg2 == 1) {
    value1 = *(int *)((intptr_t)self + 0x1d0);
    if (value1 == 0) {
      return (uint32_t *)0x0;
    }
  }
  else if (arg2 == 2) {
    value1 = *(int *)((intptr_t)self + 0x1d4);
    if (value1 == 0) {
      return (uint32_t *)0x0;
    }
  }
  else if ((arg2 == 3) && (value1 = *(int *)((intptr_t)self + 0x1d8), value1 == 0)) {
    return (uint32_t *)0x0;
  }
  uptr2 = &local_4;
  uvalue3 = 1;
  (**(code **)(**(int **)((intptr_t)self + 8) + 0x34))(*(int **)((intptr_t)self + 8),arg1,1);
  (**(code **)(**(int **)((intptr_t)self + 8) + 0x80))(*(int **)((intptr_t)self + 8),uvalue3,value1);
  if (unaff_EDI != 0) {
    (**(code **)(**(int **)((intptr_t)self + 8) + 0x78))(*(int **)((intptr_t)self + 8),value1,unaff_EDI);
  }
  (**(code **)(**(int **)((intptr_t)self + 8) + 0x60))(*(int **)((intptr_t)self + 8),value1);
  return uptr2;
}
