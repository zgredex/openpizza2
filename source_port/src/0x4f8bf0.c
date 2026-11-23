// Game_UpdateCompanyAdvancementScore: ported from Pizza Connection 2 at 0x4f8bf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f8bf0
#include "pc2_port.h"

uint32_t __thiscall Game_UpdateCompanyAdvancementScore(void *self,int arg1)

{
  void *pvVar1;
  void *this_00;
  int value2;
  int value3;
  uint32_t uvalue4;
  int value5;
  uint32_t uvalue6;
  int value7;
  int local_20;
  int local_1c;
  int local_18;
  void *local_14;
  int local_10 [4];
  
  local_18 = *(int *)((intptr_t)self + arg1 * 0x168 + 0x40);
  pvVar1 = (void *)((intptr_t)self + arg1 * 0x168);
  local_14 = pvVar1;
  this_00 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),
                                 (int *)0x0);
  value5 = 0;
  local_20 = 0;
  value7 = *(int *)(*(int *)((intptr_t)pvVar1 + 0x70) + 0x15c);
  if (0 < value7) {
    do {
      value2 = Game_GetPlayerSubrecord(self,arg1,value5,1);
      if ((value2 != 0) && (value2 = AI_ComputePlanScores(value2,&local_1c,local_10,4), 0 < value2)) {
        local_20 = local_20 + local_1c / value2;
      }
      value5 = value5 + 1;
    } while (value5 < value7);
    if (0 < local_20) {
      value7 = (local_20 * 0x11) / 100;
      goto LAB_004f8ca6;
    }
  }
  value7 = 0;
LAB_004f8ca6:
  value2 = local_18;
  value5 = *(int *)((intptr_t)this_00 + local_18 * 4 + 0xdac);
  if (value7 < value5) {
    Game_SetCompanyAdvancementScore(this_00,local_18,0);
    *(uint32_t *)((intptr_t)this_00 + value2 * 4 + 0xcc8) = 0;
  }
  else {
    value3 = Game_GetMostAdvancedCompany((intptr_t)this_00);
    if (value3 == value2) {
      return 1;
    }
    uvalue6 = value5 + 5000;
    if (((intptr_t)uvalue6 <= value7) &&
       (uvalue4 = Game_CanAffordWithCurrency
                          (*(void **)((intptr_t)local_14 + 0x70),0x14,5000.0,'\x01',0xffffffff),
       (char)uvalue4 != '\0')) {
      Game_SetCompanyAdvancementScore(this_00,value2,uvalue6);
      return 1;
    }
  }
  return 0;
}
