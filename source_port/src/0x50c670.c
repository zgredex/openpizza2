// MapObject_IsFacingTarget: ported from Pizza Connection 2 at 0x50c670.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50c670
#include "pc2_port.h"

bool __thiscall MapObject_IsFacingTarget(void *self,uint32_t arg1,void *arg2)

{
  int *ptr1;
  void *this_00;
  int value2;
  int value3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  uint32_t *uptr6;
  int local_8;
  int local_4;
  
  this_00 = arg2;
  if (*(int *)((intptr_t)self + 200) != 0) {
    if ((*(int *)((intptr_t)arg2 + 0xa4) == 0x17) && (*(int *)((intptr_t)self + 0xa4) == 1)) {
      return *(int *)((intptr_t)self + 0x38) == 0x12;
    }
    value2 = MapObject_ComputeBlitRect((intptr_t)self);
    local_4 = MapObject_ComputeBlitRect((intptr_t)this_00);
    value2 = IsMenuId34EOr350(*(int *)(*(int *)(value2 + 8) + 4));
    value3 = IsMenuId34EOr350(*(int *)(*(int *)(local_4 + 8) + 4));
    if (value2 == value3) {
      ptr1 = *(int **)((intptr_t)self + 200);
      if (ptr1 == (int *)0x0) {
        value2 = -1;
      }
      else {
        value2 = *ptr1;
      }
      Record_GetTwoFloats48((void *)ptr1[0x16],value2,&arg2,&local_8);
      arg2 = (void *)((intptr_t)arg2 + *(int *)(*(int *)((intptr_t)self + 0xc4) + 0xf8));
      local_8 = local_8 + *(int *)(*(int *)((intptr_t)self + 0xc4) + 0xfc);
      uvalue4 = UI_ComputeObjectDirection(this_00,(float)(intptr_t)(arg2),local_8);
      if (*(int *)((intptr_t)this_00 + 200) == 0) {
        uvalue5 = 0xffffffff;
      }
      else {
        uvalue5 = *(uint32_t *)(*(int *)((intptr_t)this_00 + 200) + 0xc);
      }
      uvalue5 = uvalue5 & 0x80000007;
      if ((intptr_t)uvalue5 < 0) {
        uvalue5 = (uvalue5 - 1 | 0xfffffff8) + 1;
      }
      value2 = 0;
      uptr6 = (uint32_t *)(&DAT_00572b0c + uvalue5 * 0x14);
      do {
        if (*uptr6 == uvalue4) {
          return true;
        }
        value2 = value2 + 1;
        uptr6 = uptr6 + 1;
      } while (value2 < 5);
    }
  }
  return false;
}
