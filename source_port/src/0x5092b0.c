// Game_ComputeObjectDetails: ported from Pizza Connection 2 at 0x5092b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5092b0
#include "pc2_port.h"

void __thiscall
Game_ComputeObjectDetails
          (void *self,int arg1,uint32_t *arg2,int arg3,int *arg4,int *arg5,
          int *arg6,int *arg7)

{
  int value1;
  void *this_00;
  int value2;
  uint32_t *uptr3;
  int extraout_EDX;
  int value4;
  int unaff_EDI;
  void *this_01;
  int64_t lvalue5;
  uint32_t local_14;
  int local_10;
  void *local_c;
  int local_8;
  int local_4;
  
  value1 = *(int *)(arg1 + 0x2c);
  value2 = *(int *)(arg1 + 8);
  Game_GetPlayerBySlot(DAT_0057c670,value2);
  value1 = Game_GetPlayerSubmapValue(DAT_0057c670,value2,value1);
  value4 = 0;
  local_4 = value1;
  this_00 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)self + 0x28),
                                 (int *)0x0);
  this_01 = (void *)*arg2;
  local_c = this_01;
  value2 = Game_GetSkillRating(this_01,value1,(float)arg2[1],*(int *)((intptr_t)self + 0x34));
  if (arg4 != (int *)0x0) {
    *arg4 = value2;
  }
  local_8 = Player_ComputeProductQualityScore
                      (value1,extraout_EDX,this_01,*(int *)((intptr_t)self + 0x34),unaff_EDI);
  if (arg5 != (int *)0x0) {
    *arg5 = local_8;
  }
  uptr3 = (uint32_t *)0x0;
  arg4 = (int *)0x0;
  arg2 = (uint32_t *)0x0;
  arg1 = 0;
  value1 = 0xa8;
  do {
    if (0 < *(int *)((intptr_t)this_01 + value1 + -0x44)) {
      value2 = *(int *)(value1 + (intptr_t)DAT_0057c670);
      Market_ComputeValueAdjustment
                (this_00,'\0',*(uint32_t *)((intptr_t)self + 0x34),value2,&local_14,&local_10);
      if (value1 != 0xa8) {
        value2 = Market_GetPriceModifier
                          (this_00,*(int *)((intptr_t)self + 0x34),(uint32_t)*(uint8_t *)(value2 + 0xa8));
        arg4 = (int *)((intptr_t)arg4 + value2);
        value4 = value4 + local_14;
        arg1 = arg1 + 1;
      }
      uptr3 = (uint32_t *)((intptr_t)arg2 + local_10);
      this_01 = local_c;
      arg2 = uptr3;
    }
    value1 = value1 + 4;
  } while (value1 < 0x200);
  if (arg1 < 1) {
    value1 = -0x28;
  }
  else {
    value1 = (intptr_t)uptr3 + value4 / arg1 + (intptr_t)arg4 / arg1;
  }
  if (arg6 != (int *)0x0) {
    *arg6 = value1;
  }
  lvalue5 = __ftol();
  value1 = (intptr_t)lvalue5;
  if (value1 < 0x65) {
    if (value1 < 0) {
      value1 = 0;
    }
  }
  else {
    value1 = 100;
  }
  if (arg7 != (int *)0x0) {
    *arg7 = value1;
  }
  return;
}
