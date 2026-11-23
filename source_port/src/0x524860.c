// UI_DispatchMouseEvent: ported from Pizza Connection 2 at 0x524860.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x524860
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall UI_DispatchMouseEvent(void *self,uint32_t arg1,int arg2,int arg3)

{
  void *this_00;
  uint32_t uvalue1;
  LONG LVar2;
  LONG LVar3;
  int *ptr4;
  int *ptr5;
  int value6;
  uint32_t *uptr7;
  tagPOINT local_8;
  
  ptr5 = (int *)0x0;
  if (*(int *)((intptr_t)self + 0x22c) == 0) {
    uvalue1 = (uint32_t)arg2 >> 0x10;
    local_8.x = (LONG)(short)arg3;
    local_8.y = (LONG)(short)((uint32_t)arg3 >> 0x10);
    ScreenToClient(*(HWND *)((intptr_t)self + 0x8320),&local_8);
    LVar3 = local_8.y;
    LVar2 = local_8.x;
    _DAT_005841d8 = local_8.x;
    _DAT_005841dc = local_8.y;
    _DAT_005841e8 = 0;
    _DAT_005841ec = 0;
    value6 = *(int *)((intptr_t)self + 0x23c) + -1;
    if (-1 < value6) {
      uptr7 = (uint32_t *)((intptr_t)self + value6 * 4 + 0x14);
      do {
        this_00 = (void *)*uptr7;
        if (((((this_00 != (void *)0x0) && (*(int *)((intptr_t)this_00 + 0x4c) != 0)) &&
             ((*(void **)((intptr_t)self + 0x228) == (void *)0x0 ||
              (*(void **)((intptr_t)self + 0x228) == this_00)))) &&
            (ptr4 = UI_FindNearestWindow(this_00,LVar2,LVar3,&arg2), ptr4 != (int *)0x0)) &&
           ((ptr5 == (int *)0x0 || (arg2 < arg3)))) {
          ptr5 = ptr4;
          arg3 = arg2;
        }
        value6 = value6 + -1;
        uptr7 = uptr7 + -1;
      } while (-1 < value6);
      if (ptr5 != (int *)0x0) {
        (**(code **)(*ptr5 + 0xc))(0x2f,0 < (short)uvalue1,0);
      }
    }
  }
  return;
}
