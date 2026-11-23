// Game_InitStatBaselines: ported from Pizza Connection 2 at 0x479ef0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x479ef0
#include "pc2_port.h"

void __thiscall Game_InitStatBaselines(void *self,int arg1,char arg2)

{
  int value1;
  int value2;
  int *ptr3;
  int *ptr4;
  int aiStack_40 [8];
  int aiStack_20 [8];
  
  value2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((intptr_t)self + 0x34),(int *)0x0);
  value1 = *(int *)((intptr_t)self + 0x14d8);
  if (value1 == -1) {
    ptr3 = aiStack_20 + arg1;
    *ptr3 = 0;
  }
  else {
    ptr3 = aiStack_20 + arg1;
    if (value1 == 8) {
      *ptr3 = *(int *)(value2 + 0x1e0 + arg1 * 4);
    }
    else {
      *ptr3 = *(int *)(value2 + (arg1 + 0x38 + value1 * 8) * 4);
    }
    Clamp_0_100(ptr3);
  }
  if ((arg1 < 0) || ((3 < arg1 && (arg1 != 7)))) {
    value1 = *(int *)((intptr_t)self + 0x186c);
    if (3 < value1) {
      ptr4 = aiStack_40 + arg1;
      *ptr4 = 0;
      goto LAB_00479fbb;
    }
    if (value1 != 3) {
      if (value1 == 2) {
        ptr4 = aiStack_40 + arg1;
        *ptr4 = 0x46;
        goto LAB_00479fbb;
      }
      goto LAB_00479fb1;
    }
    ptr4 = aiStack_40 + arg1;
  }
  else {
    if (1 < *(int *)((intptr_t)self + 0x186c)) {
LAB_00479fb1:
      ptr4 = aiStack_40 + arg1;
      *ptr4 = 100;
      goto LAB_00479fbb;
    }
    ptr4 = aiStack_40 + arg1;
    if (*(int *)((intptr_t)self + 0x186c) == 1) {
      *ptr4 = 0x46;
      goto LAB_00479fbb;
    }
  }
  *ptr4 = 0x1e;
LAB_00479fbb:
  Clamp_0_100(ptr4);
  if (arg2 == '\0') {
    *(int *)((intptr_t)self + arg1 * 4 + 0x181c) = (*ptr4 + *ptr3) / 2;
    return;
  }
  *(int *)((intptr_t)self + arg1 * 4 + 0x181c) = *ptr3;
  return;
}
