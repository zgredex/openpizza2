// Game_ComputeTradeOffers: ported from Pizza Connection 2 at 0x4d5dd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d5dd0
#include "pc2_port.h"

int __thiscall
Game_ComputeTradeOffers
          (void *self,int arg1,int arg2,int *arg3,int *arg4,int arg5,int *arg6)

{
  bool flag1;
  bool flag2;
  int value3;
  int value4;
  int64_t lvalue5;
  int64_t lvalue6;
  int local_12c;
  int local_128;
  int local_124 [4];
  uint32_t local_114;
  uint32_t local_110;
  uint32_t local_10c;
  uint32_t local_108 [65];
  
  value4 = 0;
  flag2 = false;
  flag1 = false;
  local_124[1] = 0;
  local_124[2] = 0x3ff00000;
  local_114 = 200;
  local_110 = 400;
  local_10c = 800;
  if (arg6 != (int *)0x0) {
    *arg6 = 0;
  }
  *arg3 = 0;
  *arg4 = 0;
  switch(arg2) {
  case 1:
    value3 = IsSpecialIdRange(arg1);
    if (value3 != 0) {
      flag2 = true;
      goto switchD_004d5e4d_default;
    }
    value4 = 5000;
    break;
  case 2:
    value4 = 6000;
    break;
  case 3:
    value3 = Object_IsIdIn840Range(arg1);
    if (value3 != 0) {
      flag2 = true;
      goto switchD_004d5e4d_default;
    }
    value4 = 4000;
    break;
  case 4:
    value4 = 3000;
    break;
  default:
    goto switchD_004d5e4d_default;
  }
  flag1 = true;
switchD_004d5e4d_default:
  Map_CountNearbyObjects(self,arg1,&local_12c,local_124,&local_128);
  if (arg6 != (int *)0x0) {
    *arg6 = local_128;
  }
  if ((flag1) && (value3 = Game_CanShowObject(arg1), value3 != 0)) {
    if (arg2 == 2) {
      value4 = 0;
    }
    else {
      value4 = *(int *)(arg1 + 0x3c);
      value3 = Game_CountProductUsageByCategory(DAT_0057c670,arg1,local_108);
      value4 = ((value3 + 6) * value4) / 0x14;
    }
    lvalue5 = __ftol();
    *arg4 = value4 - (intptr_t)lvalue5;
    lvalue5 = __ftol();
    *arg4 = (intptr_t)lvalue5;
    lvalue6 = __ftol();
    value3 = (intptr_t)lvalue6 + (intptr_t)lvalue5;
    *arg4 = value3;
    lvalue5 = __ftol();
    value4 = (intptr_t)lvalue5;
    *arg4 = value3 + value4;
    value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    if (arg5 == value3) {
      lvalue5 = __ftol();
      *arg4 = (intptr_t)lvalue5;
      lvalue5 = __ftol();
      value4 = (intptr_t)lvalue5;
    }
  }
  if ((flag2) && (*(int *)(arg1 + 0x4c) != 0)) {
    lvalue5 = __ftol();
    *arg3 = (intptr_t)lvalue5;
    if (*(int *)(arg1 + 0x4c) != 0) {
      lvalue5 = __ftol();
      *arg3 = (intptr_t)lvalue5;
    }
    value3 = *arg3;
    lvalue5 = __ftol();
    *arg3 = (intptr_t)lvalue5 + value3;
    value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    if (arg5 == value3) {
      value3 = *(int *)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xa8);
      if (*(int *)(value3 + 0x10c) != 0) {
        *arg3 = 0;
        return value4;
      }
      if (*(int *)(value3 + 0xfc) != 0) {
        *arg3 = *arg3 / 2;
        return value4;
      }
      if (*(int *)(value3 + 0x1e0) != 0) {
        *arg3 = (*arg3 * 0xf) / 10;
      }
    }
  }
  return value4;
}
