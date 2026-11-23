// UI_RemoveWindowByID: ported from Pizza Connection 2 at 0x527f80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x527f80
#include "pc2_port.h"

void __thiscall UI_RemoveWindowByID(void *self,int arg1)

{
  uint32_t *uptr1;
  uint32_t uvalue2;
  int value3;
  int *ptr4;
  void *local_4;
  
  local_4 = self;
  CS_Enter(*(int *)((intptr_t)self + 0x1c8));
  value3 = UI_FindWindowByID(self,arg1,(int *)&local_4);
  if (value3 != 0) {
    if (local_4 != (void *)(*(int *)((intptr_t)self + 0x23c) + -1)) {
      uptr1 = (uint32_t *)((intptr_t)self + (intptr_t)local_4 * 4 + 0x14);
      uvalue2 = *uptr1;
      _memmove(uptr1,(uint32_t *)((intptr_t)self + (intptr_t)local_4 * 4 + 0x18),
               (((intptr_t)local_4 + 1) * 0x3fffffff + *(int *)((intptr_t)self + 0x23c)) * 4);
      *(uint32_t *)((intptr_t)self + *(int *)((intptr_t)self + 0x23c) * 4 + 0x10) = uvalue2;
      value3 = 0;
      if (0 < *(int *)((intptr_t)self + 0x23c)) {
        ptr4 = (int *)((intptr_t)self + 0x14);
        do {
          if (*ptr4 != 0) {
            Sound_StopBuffer(*ptr4);
          }
          value3 = value3 + 1;
          ptr4 = ptr4 + 1;
        } while (value3 < *(int *)((intptr_t)self + 0x23c));
      }
      *(uint32_t *)((intptr_t)self + 0x83b8) = 1;
      CS_Leave(*(int *)((intptr_t)self + 0x1c8));
      return;
    }
  }
  CS_Leave(*(int *)((intptr_t)self + 0x1c8));
  return;
}
