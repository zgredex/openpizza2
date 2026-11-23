// UI_BringWindowToFront: ported from Pizza Connection 2 at 0x527ee0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x527ee0
#include "pc2_port.h"

void __thiscall UI_BringWindowToFront(void *self,int arg1)

{
  int value1;
  int *ptr2;
  void *local_4;
  
  local_4 = self;
  CS_Enter(*(int *)((intptr_t)self + 0x1c8));
  value1 = UI_FindWindowByID(self,arg1,(int *)&local_4);
  if ((value1 == 0) || (local_4 == (void *)0x0)) {
    CS_Leave(*(int *)((intptr_t)self + 0x1c8));
    return;
  }
  value1 = *(int *)((intptr_t)self + (intptr_t)local_4 * 4 + 0x14);
  ptr2 = (int *)((intptr_t)self + 0x14);
  _memmove((uint32_t *)((intptr_t)self + 0x18),ptr2,(intptr_t)local_4 * 4);
  *ptr2 = value1;
  value1 = 0;
  if (0 < *(int *)((intptr_t)self + 0x23c)) {
    do {
      if (*ptr2 != 0) {
        Sound_StopBuffer(*ptr2);
      }
      value1 = value1 + 1;
      ptr2 = ptr2 + 1;
    } while (value1 < *(int *)((intptr_t)self + 0x23c));
  }
  *(uint32_t *)((intptr_t)self + 0x83b8) = 1;
  CS_Leave(*(int *)((intptr_t)self + 0x1c8));
  return;
}
