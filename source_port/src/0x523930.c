// UI_AllocWindowSlot: ported from Pizza Connection 2 at 0x523930.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x523930
#include "pc2_port.h"

int __thiscall UI_AllocWindowSlot(void *self,uint32_t *arg1)

{
  int *ptr1;
  uint32_t unaff_EDI;
  int value2;
  
  *(uint32_t *)((intptr_t)self + 0x83b8) = 1;
  CS_Enter(*(int *)((intptr_t)self + 0x1c8));
  value2 = 0;
  *arg1 = *(uint32_t *)((intptr_t)self + 0x83e0);
  *(int *)((intptr_t)self + 0x83e0) = *(int *)((intptr_t)self + 0x83e0) + 1;
  if (0 < *(int *)((intptr_t)self + 0x23c)) {
    ptr1 = (int *)((intptr_t)self + 0x14);
    do {
      if (*ptr1 == 0) {
        CS_Leave(*(int *)((intptr_t)self + 0x1c8));
        return value2;
      }
      value2 = value2 + 1;
      ptr1 = ptr1 + 1;
    } while (value2 < *(int *)((intptr_t)self + 0x23c));
  }
  CS_Leave(*(int *)((intptr_t)self + 0x1c8));
  if (value2 == 100) {
    DebugConsole_Errorf(self,3,(uint8_t *)s_To_many_windows_created__Please_d_005740b0,unaff_EDI);
    return -1;
  }
  *(int *)((intptr_t)self + 0x23c) = *(int *)((intptr_t)self + 0x23c) + 1;
  return value2;
}
