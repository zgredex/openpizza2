// AI_TestActionChance: ported from Pizza Connection 2 at 0x50d5e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50d5e0
#include "pc2_port.h"

bool __thiscall AI_TestActionChance(void *self,int arg1,int arg2)

{
  int value1;
  uint32_t uvalue2;
  int value3;
  int local_14 [5];
  
  value3 = 0x32;
  local_14[2] = 0x32;
  local_14[3] = 0x55;
  local_14[4] = 0x46;
  local_14[1] = 0x32;
  if (*(int *)((intptr_t)self + 0x30) == 0xd) {
    value1 = arg1;
  }
  else {
    value1 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + 0x110));
    if (value1 == 0) {
      return false;
    }
  }
  switch(*(uint32_t *)((intptr_t)self + 0x30)) {
  case 0xd:
    value1 = Object_GetClampedLevel((intptr_t)self);
    break;
  default:
    value1 = arg1;
    break;
  case 0x17:
    value1 = *(int *)(value1 + 100);
    break;
  case 0x1d:
    value1 = *(int *)(value1 + 0x6c);
    break;
  case 0x1e:
    value1 = *(int *)(value1 + 0x68);
    if (value1 == 1) {
      value3 = 0x28;
    }
    else if (value1 != 2) {
      if (value1 != 3) break;
      value3 = 0x3c;
    }
    goto LAB_0050d68f;
  }
  value3 = arg1;
LAB_0050d68f:
  if (*(int *)((intptr_t)self + 0x30) != 0x1e) {
    if (arg2 == 0) {
      if (*(short *)(*(int *)(arg1 + 200) + 0x28) != -1) {
        value3 = local_14[value1 + -2];
        goto LAB_0050d6cb;
      }
    }
    else if (*(int *)(arg1 + 0x108) == 5) {
      value3 = local_14[value1 + -2];
      goto LAB_0050d6cb;
    }
    value3 = local_14[value1 + 1];
  }
LAB_0050d6cb:
  uvalue2 = Random_RangeFast(1,100);
  return (intptr_t)uvalue2 <= value3;
}
