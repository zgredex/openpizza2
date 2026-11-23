// AI_InitActionPlan: ported from Pizza Connection 2 at 0x502ce0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x502ce0
#include "pc2_port.h"

void __thiscall
AI_InitActionPlan(void *self,uint32_t arg1,uint32_t arg2,int arg3,int arg4,int arg5,
                 int arg6,int arg7)

{
  int *ptr1;
  uint32_t uvalue2;
  int value3;
  int value4;
  
  value4 = 0;
  value3 = 0xd;
  *(uint32_t *)((intptr_t)self + 0x84) = 0;
  ptr1 = (int *)((intptr_t)self + 0xc);
  do {
    if (*ptr1 == 1) {
      value4 = value4 + 1;
    }
    ptr1 = ptr1 + 1;
    value3 = value3 + -1;
  } while (value3 != 0);
  if (value4 == 0xd) {
    ptr1 = (int *)((intptr_t)self + 0xc);
    for (value3 = 0xd; value3 != 0; value3 = value3 + -1) {
      *ptr1 = 0;
      ptr1 = ptr1 + 1;
    }
  }
  if (arg1 == 0xffffffff) {
    arg1 = Random_RangeFast(0,0xc);
    do {
      arg1 = arg1 + 1;
      if (arg1 == 0xd) {
        arg1 = 0;
      }
    } while (*(int *)((intptr_t)self + arg1 * 4 + 0xc) != 0);
  }
  *(uint32_t *)((intptr_t)self + 8) = 0xffffffff;
  *(uint32_t *)((intptr_t)self + 0x58) = arg1;
  *(uint32_t *)((intptr_t)self + arg1 * 4 + 0xc) = 1;
  if (arg2 == 0xffffffff) {
    arg2 = Game_GetStatBandByIndex(self,arg1);
  }
  *(uint32_t *)((intptr_t)self + 0x44) = arg2;
  *(uint32_t *)((intptr_t)self + 0x40) = (&DAT_005726a8)[arg1];
  uvalue2 = AI_SelectActionForType((intptr_t)self);
  *(uint32_t *)((intptr_t)self + 0x48) = uvalue2;
  if (arg3 != -1) {
    *(int *)((intptr_t)self + 0x48) = arg3;
  }
  if ((arg4 != -1) && (arg3 != -1)) {
    if (arg3 < 0xc) {
      uvalue2 = *(uint32_t *)(&DAT_0057270c + (arg3 / 3 + (arg3 % 3) * 4) * 4);
    }
    else if (arg3 < 0x18) {
      uvalue2 = *(uint32_t *)
               (&DAT_0057276c + ((arg3 + -0xc) / 3 + ((arg3 + -0xc) % 3) * 4) * 4);
    }
    else {
      uvalue2 = *(uint32_t *)
               (&DAT_005727cc + ((arg3 + -0x18) / 3 + ((arg3 + -0x18) % 3) * 4) * 4);
    }
    *(uint32_t *)((intptr_t)self + 0x4c) = uvalue2;
  }
  if (arg5 != -1) {
    *(int *)((intptr_t)self + 0x84) = arg5;
  }
  if (arg4 == -1) {
    if (*(int *)((intptr_t)self + 0x40) == 6) goto LAB_00502e72;
    if (*(int *)((intptr_t)self + 0x40) < 3) {
      value3 = *(int *)((intptr_t)self + 0x4c) * 0xb;
    }
    else {
      value3 = *(int *)((intptr_t)self + 0x4c) * 9;
    }
  }
  else {
    value3 = *(int *)((intptr_t)self + 0x4c) * 6;
  }
  *(int *)((intptr_t)self + 0x4c) = value3 / 10;
LAB_00502e72:
  uvalue2 = Building_GetRandomResidentCount(self,*(int *)((intptr_t)self + 0x40));
  *(uint32_t *)((intptr_t)self + 0x50) = uvalue2;
  uvalue2 = Game_PickRandomTableValue(self,*(int *)((intptr_t)self + 0x40));
  *(uint32_t *)((intptr_t)self + 0x54) = uvalue2;
  if (arg6 != -1) {
    *(int *)((intptr_t)self + 0x50) = arg6;
  }
  if (arg7 != -1) {
    *(int *)((intptr_t)self + 0x54) = arg7;
  }
  return;
}
