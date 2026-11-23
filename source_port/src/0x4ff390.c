// AI_OpenBranchesInCity: ported from Pizza Connection 2 at 0x4ff390.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ff390
#include "pc2_port.h"

int __thiscall AI_OpenBranchesInCity(void *self,void *arg1,int arg2)

{
  bool flag1;
  int value2;
  int value3;
  int value4;
  int value5;
  uint32_t extraout_var;
  
                    /* Opens a population-limited number of AI branches. */
  value5 = *(int *)((intptr_t)arg1 + 0x4c);
  value2 = AI_CountAvailableTargets(arg1,0x1d);
  value3 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(arg2 + 0x30));
  value3 = *(int *)(value3 + 100);
  value4 = Game_UpdateFreeBuildingCount(arg2);
  value5 = ((*(short *)((intptr_t)self + value5 * 0x168 + 0x130) + 0x32) * value4 * value3) / 100;
  if (value5 == 0) {
    return 1;
  }
  value3 = Game_CountFilteredObjects
                    (DAT_0057c670,0x10,0x1d,*(int *)(arg2 + 0x16f0),*(int *)((intptr_t)arg1 + 0x48)
                    );
  if (value3 != 0) {
    return 1;
  }
  value3 = 0;
  if ((((0 < value2) && (value5 = value5 / *(int *)((intptr_t)arg1 + 0x6c), value5 <= value2)) &&
      (flag1 = Math_CompareRounded(), CONCAT31(extraout_var,flag1) != 0)) && (0 < value5)) {
    do {
      value2 = AI_HireBranchWorker(arg1,arg2);
      if (value2 == 0) {
        if (value3 == 0) {
          return 0;
        }
        break;
      }
      value3 = 1;
      value5 = value5 + -1;
      *(int *)((intptr_t)arg1 + 0x74) = *(int *)((intptr_t)arg1 + 0x74) + 1;
    } while (0 < value5);
    value5 = *(int *)(arg2 + 0x30);
    value2 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    if (value5 == value2) {
      Sound_SetTimeout(DAT_0057ba0c);
    }
  }
  return value3;
}
