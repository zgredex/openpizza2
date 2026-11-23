// MapObject_IsTargetFacingMe: ported from Pizza Connection 2 at 0x50c7a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50c7a0
#include "pc2_port.h"

uint32_t __thiscall MapObject_IsTargetFacingMe(void *self,uint32_t arg1,int arg2)

{
  int *ptr1;
  int value2;
  int value3;
  uint32_t uvalue4;
  void *this_00;
  uint32_t uvalue5;
  uint32_t *uptr6;
  float local_8;
  int local_4;
  
  value2 = MapObject_ComputeBlitRect((intptr_t)self);
  value3 = MapObject_ComputeBlitRect(arg2);
  value3 = IsMenuId34EOr350(*(int *)(*(int *)(value3 + 8) + 4));
  value2 = IsMenuId34EOr350(*(int *)(*(int *)(value2 + 8) + 4));
  if (value2 == value3) {
    ptr1 = *(int **)(arg2 + 200);
    if (ptr1 == (int *)0x0) {
      value2 = -1;
      this_00 = (void *)0x0;
    }
    else {
      value2 = *ptr1;
      this_00 = (void *)ptr1[0x16];
    }
    Record_GetTwoFloats48(this_00,value2,&local_8,&local_4);
    local_8 = (float)((intptr_t)local_8 + *(int *)(*(int *)((intptr_t)self + 0xc4) + 0xf8));
    local_4 = local_4 + *(int *)(*(int *)((intptr_t)self + 0xc4) + 0xfc);
    uvalue4 = UI_ComputeObjectDirection(self,local_8,local_4);
    if (*(int *)((intptr_t)self + 200) == 0) {
      uvalue5 = 0xffffffff;
    }
    else {
      uvalue5 = *(uint32_t *)(*(int *)((intptr_t)self + 200) + 0xc);
    }
    uvalue5 = uvalue5 & 0x80000007;
    if ((intptr_t)uvalue5 < 0) {
      uvalue5 = (uvalue5 - 1 | 0xfffffff8) + 1;
    }
    value2 = 0;
    uptr6 = (uint32_t *)(&DAT_00572bac + uvalue5 * 0x14);
    do {
      if (*uptr6 == uvalue4) {
        return 1;
      }
      value2 = value2 + 1;
      uptr6 = uptr6 + 1;
    } while (value2 < 5);
  }
  return 0;
}
