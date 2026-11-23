// Game_TryBuyCompletedHouse: ported from Pizza Connection 2 at 0x4fc7d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fc7d0
#include "pc2_port.h"

uint32_t __thiscall Game_TryBuyCompletedHouse(void *self,void *arg1,int arg2)

{
  void *this_00;
  int value1;
  void *this_01;
  short *psVar2;
  int value3;
  void *pvVar4;
  int64_t lvalue5;
  int local_24;
  int local_20 [8];
  
  this_00 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)arg1 + 0x30));
  if (*(int *)((intptr_t)self + *(int *)((intptr_t)this_00 + 0x4c) * 0x168 + 0x114) != 0) {
    value1 = Game_GetPlayerFieldC20((intptr_t)this_00);
    if ((((0 < value1) && (*(int *)((intptr_t)arg1 + 0x38) != 2)) &&
        (*(int *)(*(int *)((intptr_t)arg1 + 0x16f0) + 0x38) == 0)) &&
       (*(int *)((intptr_t)arg1 + 0x2c) == 0)) {
      value1 = *(int *)(*(int *)((intptr_t)arg1 + 0x16f0) + 0x74);
      if (value1 == 0) {
        value1 = -1;
      }
      else {
        value1 = Game_GetAdjustedValue(value1);
      }
      if ((*(int *)((intptr_t)arg1 + 0x38) == 0) || (*(int *)((intptr_t)arg1 + 0x38) == 1)) {
        pvVar4 = (void *)0xaa;
      }
      else {
        pvVar4 = arg1;
      }
      this_01 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),
                                     *(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
      Game_ComputeAreaAttraction(this_01,*(int *)((intptr_t)arg1 + 0x16f0),value1 + -10);
      value1 = Game_ComputeAreaAttraction(this_01,*(int *)((intptr_t)arg1 + 0x16f0),(intptr_t)pvVar4);
      lvalue5 = __ftol();
      if ((intptr_t)lvalue5 < value1) {
        lvalue5 = Stats_GetCombinedValue(1,*(int *)((intptr_t)arg1 + 0x38));
        Game_CanAffordWithCurrency(this_00,2,(float)(intptr_t)lvalue5,'\0',0xffffffff);
        Game_MarkObjectsDirtyForState(arg1,5);
        return 1;
      }
      if (arg2 != 0) {
        value1 = 0;
        psVar2 = (short *)(arg2 + 0x1a);
        value3 = 8;
        do {
          value1 = value1 + *psVar2;
          psVar2 = psVar2 + 0x1a;
          value3 = value3 + -1;
        } while (value3 != 0);
        if (8 < value1) {
          value1 = AI_ComputePlanScores((intptr_t)arg1,&local_24,local_20,2);
          if ((1 < value1) && (29999 < local_24)) {
            lvalue5 = Stats_GetCombinedValue(1,*(int *)((intptr_t)arg1 + 0x38));
            Game_CanAffordWithCurrency(this_00,2,(float)(intptr_t)lvalue5,'\0',0xffffffff);
            Game_MarkObjectsDirtyForState(arg1,5);
          }
        }
      }
    }
  }
  return 1;
}
