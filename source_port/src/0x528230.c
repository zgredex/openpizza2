// Screen_TransitionEffectTick: ported from Pizza Connection 2 at 0x528230.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x528230
#include "pc2_port.h"

int __fastcall Screen_TransitionEffectTick(void *arg1,uint32_t arg2,int arg3,int arg4)

{
  int value1;
  bool flag2;
  int value3;
  uint32_t extraout_var;
  int64_t lvalue4;
  
  if (*(int *)((intptr_t)arg1 + 0x18) == 0) {
    return 0;
  }
  if (*(int *)((intptr_t)arg1 + 0x10) == 0) {
    arg2 = *(uint32_t *)((intptr_t)arg1 + 0x14);
    value3 = arg3 - arg2;
    if (10000 < value3) {
      value3 = 0;
    }
  }
  else {
    value3 = 0;
    *(uint32_t *)((intptr_t)arg1 + 0x10) = 0;
  }
  *(int *)((intptr_t)arg1 + 0x14) = arg3;
  *(int *)((intptr_t)arg1 + 0x1c) = *(int *)((intptr_t)arg1 + 0x1c) - value3;
  value1 = *(int *)((intptr_t)arg1 + 4);
  if (value1 == 0) {
    arg4 = UI_FillFadeRect(arg1,arg4,value3);
  }
  else if (value1 == 1) {
    lvalue4 = Surface_ApplyWaterDistortion((intptr_t)arg1,arg2,arg4,value3);
    arg4 = (intptr_t)lvalue4;
  }
  else if (value1 == 2) {
    flag2 = UI_ScrollChildByVelocity(arg1,arg4,value3);
    arg4 = CONCAT31(extraout_var,flag2);
  }
  if (arg4 == 0) {
    *(uint32_t *)((intptr_t)arg1 + 0x18) = 0;
  }
  return arg4;
}
