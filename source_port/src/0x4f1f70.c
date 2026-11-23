// Object_UpdateState: ported from Pizza Connection 2 at 0x4f1f70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f1f70
#include "pc2_port.h"

void __thiscall Object_UpdateState(void *self,int arg1)

{
  int *ptr1;
  int value2;
  
  value2 = *(int *)(arg1 + 0x30);
  if (*(int *)(arg1 + 4) == -1) {
    if ((((value2 != -1) && (value2 = *(int *)((intptr_t)self + 0x4c) + value2 * 0xc, value2 != 0)) &&
        (value2 = *(int *)(value2 + 8), value2 != 0)) && (0 < *(int *)(value2 + 0x30))) {
      *(int *)(value2 + 0x30) = *(int *)(value2 + 0x30) + -1;
    }
    if (((*(int *)(arg1 + 0x34) != -1) &&
        (value2 = *(int *)((intptr_t)self + 0x4c) + *(int *)(arg1 + 0x34) * 0xc, value2 != 0)) &&
       ((value2 = *(int *)(value2 + 8), value2 != 0 && (0 < *(int *)(value2 + 0x30))))) {
      *(int *)(value2 + 0x30) = *(int *)(value2 + 0x30) + -1;
      *(uint32_t *)(arg1 + 0x30) = 0xffffffff;
      *(uint32_t *)(arg1 + 0x34) = 0xffffffff;
      return;
    }
  }
  else {
    if (value2 != -1) {
      ptr1 = (int *)(*(int *)(*(int *)((intptr_t)self + 0x4c) + 8 + value2 * 0xc) + 0x34);
      *ptr1 = *ptr1 + -1;
    }
    if (*(int *)(arg1 + 0x34) != -1) {
      ptr1 = (int *)(*(int *)(*(int *)((intptr_t)self + 0x4c) + 8 + *(int *)(arg1 + 0x34) * 0xc) +
                      0x34);
      *ptr1 = *ptr1 + -1;
    }
  }
  *(uint32_t *)(arg1 + 0x30) = 0xffffffff;
  *(uint32_t *)(arg1 + 0x34) = 0xffffffff;
  return;
}
