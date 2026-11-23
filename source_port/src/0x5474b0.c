// Sound_GetChannel: ported from Pizza Connection 2 at 0x5474b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5474b0
#include "pc2_port.h"

int __thiscall Sound_GetChannel(void *self,uint32_t arg1,int arg2)

{
  uint32_t unaff_ESI;
  int unaff_EDI;
  int value1;
  uint32_t uvalue2;
  uint32_t local_4;
  
  value1 = 0;
  local_4 = 0;
  if (arg2 == 1) {
    value1 = *(int *)((intptr_t)self + 0x1d0);
    if (value1 == 0) {
      return 0;
    }
  }
  else if (arg2 == 2) {
    value1 = *(int *)((intptr_t)self + 0x1d4);
    if (value1 == 0) {
      return 0;
    }
  }
  else if ((arg2 == 3) && (value1 = *(int *)((intptr_t)self + 0x1d8), value1 == 0)) {
    return 0;
  }
  uvalue2 = 1;
  (**(code **)(**(int **)((intptr_t)self + 8) + 0x34))(*(int **)((intptr_t)self + 8),arg1,1,&local_4);
  (**(code **)(**(int **)((intptr_t)self + 8) + 0x80))(*(int **)((intptr_t)self + 8),uvalue2);
  if (unaff_EDI != 0) {
    (**(code **)(**(int **)((intptr_t)self + 8) + 0x78))(*(int **)((intptr_t)self + 8),value1,unaff_EDI);
  }
  (**(code **)(**(int **)((intptr_t)self + 8) + 0x94))(*(int **)((intptr_t)self + 8),value1,unaff_ESI,1);
  (**(code **)(**(int **)((intptr_t)self + 8) + 0x60))(*(int **)((intptr_t)self + 8),unaff_ESI);
  return value1;
}
