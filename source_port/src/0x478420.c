// Branch_GetPriceComparisonRating: ported from Pizza Connection 2 at 0x478420.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x478420
#include "pc2_port.h"

int __thiscall Branch_GetPriceComparisonRating(void *self,int arg1,uint32_t *arg2)

{
  void *this_00;
  void *this_01;
  int value1;
  int value2;
  
  this_00 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + 0x30));
  this_01 = (void *)Player_FindRecordType2ByKey(this_00,*(int *)((intptr_t)self + 0x3c));
  if (this_01 == (void *)0x0) {
    *arg2 = 0;
    return 0;
  }
  if (*(int *)((intptr_t)this_01 + 4) == 0) {
    *arg2 = 0;
    return 0;
  }
  *arg2 = 1;
  if (arg1 == -1) {
    value1 = GamePlan_ComputeAverageEffect(this_01,*(int *)((intptr_t)self + 0x30));
  }
  else {
    value1 = GamePlan_ComputeCategoryEffect(this_01,*(int *)((intptr_t)self + 0x30),arg1);
  }
  value2 = Game_GetPlayerCity((intptr_t)this_00);
  value1 = (((*(int *)(value2 + 0x5c) + *(int *)(value2 + 0x44)) * -3 + 100) * value1) / 100;
  if (100 < value1) {
    return 100;
  }
  if (value1 < 0) {
    value1 = 0;
  }
  return value1;
}
