// Game_RecomputeCompanyMenuSales: ported from Pizza Connection 2 at 0x4fc470.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fc470
#include "pc2_port.h"

uint32_t __thiscall Game_RecomputeCompanyMenuSales(void *self,int arg1)

{
  void *this_00;
  bool flag1;
  int value2;
  uint32_t *this_01;
  int value3;
  uint32_t uvalue4;
  int64_t lvalue5;
  
  this_00 = *(void **)((intptr_t)self + arg1 * 0x168 + 0x70);
  Game_ResetRecordTurnCounters((intptr_t)this_00);
  value3 = 0;
  uvalue4 = (uint32_t)*(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  value2 = Game_CountActiveCompanies((intptr_t)this_00);
  if (0 < value2) {
    do {
      value2 = Game_GetActiveCompanyById(this_00,value3);
      if (99 < uvalue4) {
        uvalue4 = 99;
      }
      Stats_SumMaskedMapFloats(value2,uvalue4 - 1,0,-1);
      lvalue5 = __ftol();
      value3 = value3 + 1;
      *(int *)(value2 + 0x30c) = *(int *)(value2 + 0x30c) + (intptr_t)lvalue5;
      value2 = Game_CountActiveCompanies((intptr_t)this_00);
    } while (value3 < value2);
  }
  if ((*(uint8_t *)((intptr_t)self + arg1 * 0x168 + 0x12a) & 0x10) != 0) {
    this_01 = Company_CollectUnprofitableBranches((intptr_t)this_00);
    value2 = 0;
    if (0 < (intptr_t)this_01[5]) {
      do {
        value3 = IDMap_Lookup(this_01,value2,(int *)0x0);
        flag1 = Game_IsRecordLinked(this_00,value3);
        if (flag1) {
          Recipe_SetOnMenu(this_00,value3,0);
        }
        value2 = value2 + 1;
      } while (value2 < (intptr_t)this_01[5]);
    }
    if (this_01 != (uint32_t *)0x0) {
      (**(code **)*this_01)(1);
    }
  }
  return 1;
}
