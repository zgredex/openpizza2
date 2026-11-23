// AI_ManageGangsters: ported from Pizza Connection 2 at 0x4ff8b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ff8b0
#include "pc2_port.h"

uint32_t __thiscall AI_ManageGangsters(void *self,int arg1)

{
  void *this_00;
  uint32_t uvalue1;
  int value2;
  int value3;
  uint32_t uvalue4;
  float fVar5;
  
                    /* Adjusts gangster salaries or protection levels. */
  this_00 = *(void **)((intptr_t)self + arg1 * 0x168 + 0x70);
  Game_GetPlayerFieldC20((intptr_t)this_00);
  uvalue1 = _rand();
  if ((uvalue1 & 1) == 0) {
    value2 = Game_GetLevelReward(this_00,0x1e);
    value3 = Game_CountActiveObjectsByType(this_00,0x1e);
    if (value2 <= value3) goto LAB_004ff916;
    fVar5 = 4.2039e-44;
  }
  else {
    value2 = Game_GetLevelReward(this_00,0x1d);
    value3 = Game_CountActiveObjectsByType(this_00,0x1d);
    if (value2 <= value3) goto LAB_004ff916;
    fVar5 = 4.06377e-44;
  }
  Player_AcquireBranch(self,this_00,fVar5);
LAB_004ff916:
  value2 = Game_ComputePlayerSalary((intptr_t)this_00);
  if (value2 != -1) {
    if ((double)((100 - *(short *)((intptr_t)self + arg1 * 0x168 + 0x130)) * value2 * 6) <
        *(double *)((intptr_t)this_00 + 0x108)) {
      uvalue4 = Game_CanAffordWithCurrency(this_00,0x17,(float)value2,'\x01',0xffffffff);
      if ((char)uvalue4 != '\0') {
        Game_RefreshBuildingCondition((intptr_t)this_00);
      }
    }
  }
  value2 = Game_ComputePlayerTax((intptr_t)this_00);
  if (value2 != -1) {
    if ((double)((100 - *(short *)((intptr_t)self + arg1 * 0x168 + 0x130)) * value2 * 9) <
        *(double *)((intptr_t)this_00 + 0x108)) {
      uvalue4 = Game_CanAffordWithCurrency(this_00,0x17,(float)value2,'\x01',0xffffffff);
      if ((char)uvalue4 != '\0') {
        Game_ResetBuildingUtilization((intptr_t)this_00);
      }
    }
  }
  return 1;
}
