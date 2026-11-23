// Surface_BlitRectRetry: ported from Pizza Connection 2 at 0x538da0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x538da0
#include "pc2_port.h"

uint32_t __thiscall
Surface_BlitRectRetry
          (void *self,int arg1,int arg2,int arg3,int arg4,int arg5,int arg6)

{
  int value1;
  int *ptr2;
  int local_28;
  int local_20;
  int local_1c;
  uint32_t local_18;
  uint32_t local_14;
  tagRECT local_10;
  
  local_28 = 0;
  local_20 = arg1;
  local_1c = arg2;
  if (arg2 < 0) {
    local_1c = 0;
  }
  if (arg1 < 0) {
    local_20 = 0;
  }
  local_18 = arg1 + arg3;
  if ((intptr_t)(uint32_t)*(uint16_t *)((intptr_t)self + 0x1a) < arg1 + arg3) {
    local_18 = (uint32_t)*(uint16_t *)((intptr_t)self + 0x1a);
  }
  local_14 = arg2 + arg4;
  if ((intptr_t)(uint32_t)*(uint16_t *)((intptr_t)self + 0x1c) < arg2 + arg4) {
    local_14 = (uint32_t)*(uint16_t *)((intptr_t)self + 0x1c);
  }
  if (((intptr_t)(local_18 - local_20) < 1) || ((intptr_t)(local_14 - local_1c) < 1)) {
    return 1;
  }
  if (arg6 == 0) {
    if (arg5 == 0) {
      arg6 = *(int *)(*(int *)((intptr_t)self + 0x40) + 8);
    }
    else {
      arg6 = *(int *)(*(int *)((intptr_t)self + 0x40) + 4);
    }
  }
  while( true ) {
    if (DAT_005844fc != 0) {
      return 0;
    }
    if (*(int *)((intptr_t)self + 0x94) == 0) {
      if (arg5 == 0) {
        ptr2 = *(int **)(*(int *)((intptr_t)self + 0x40) + 4);
      }
      else {
        ptr2 = *(int **)(*(int *)((intptr_t)self + 0x40) + 8);
      }
      value1 = (**(code **)(*ptr2 + 0x1c))(ptr2,local_20,local_1c,arg6,&local_20,0x10);
    }
    else {
      SetRect(&local_10,*(int *)((intptr_t)self + 0x84) + local_20,*(int *)((intptr_t)self + 0x88) + local_1c,
              *(int *)((intptr_t)self + 0x84) + local_18,local_14 + *(int *)((intptr_t)self + 0x88));
      if (arg5 == 0) {
        ptr2 = *(int **)(*(int *)((intptr_t)self + 0x40) + 4);
      }
      else {
        ptr2 = *(int **)(*(int *)((intptr_t)self + 0x40) + 8);
      }
      value1 = (**(code **)(*ptr2 + 0x14))(ptr2,&local_10,arg6,&local_20,0x1000000,0);
    }
    if (value1 == 0) break;
    if ((((-0x7789ff6a < value1) && (value1 < -0x7789fde3)) && (value1 != -0x7789fde4)) &&
       ((value1 != -0x7789fe52 && (value1 == -0x7789fe3e)))) {
      Thread_WaitForExit((intptr_t)self);
    }
    Sleep(10);
    local_28 = local_28 + 1;
    if (200 < local_28) {
      return 0;
    }
  }
  return 1;
}
