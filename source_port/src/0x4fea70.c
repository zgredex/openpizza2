// Player_AcquireBranch: ported from Pizza Connection 2 at 0x4fea70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fea70
#include "pc2_port.h"

uint32_t __thiscall Player_AcquireBranch(void *self,void *arg1,float arg2)

{
  short svalue1;
  float fVar2;
  int value3;
  int value4;
  int value5;
  uint32_t uvalue6;
  
                    /* Takes ownership of an unowned branch after a fee and limit check. */
  fVar2 = arg2;
  value3 = Game_GetLevelReward(arg1,(intptr_t)arg2);
  value4 = *(int *)((intptr_t)arg1 + 0x4c);
  if (arg2 == 4.06377e-44) {
    svalue1 = *(short *)((intptr_t)self + value4 * 0x168 + 0x130);
joined_r0x004feae2:
    value4 = ((intptr_t)svalue1 >> 5) + 4;
  }
  else {
    if (arg2 == 4.2039e-44) {
      svalue1 = *(short *)((intptr_t)self + value4 * 0x168 + 0x130);
      goto joined_r0x004feae2;
    }
    if (arg2 != 4.34403e-44) goto LAB_004feae6;
    value4 = ((intptr_t)*(short *)((intptr_t)self + value4 * 0x168 + 0x130) >> 5) + 2;
  }
  if (value4 <= value3) {
    value3 = value4;
  }
LAB_004feae6:
  value4 = Game_CountActiveObjectsByType(arg1,(intptr_t)arg2);
  if (value3 <= value4 + 1) {
    return 0;
  }
  value4 = Game_GetPlayerCity((intptr_t)arg1);
  if (arg2 == 4.06377e-44) {
    arg2 = 20000.0;
  }
  else if (arg2 == 4.2039e-44) {
    arg2 = 10000.0;
  }
  else {
    if (arg2 != 4.34403e-44) {
      return 0;
    }
    arg2 = 5000.0;
  }
  value3 = *(int *)(value4 + 0x58);
  value4 = *(int *)(value4 + 0x40);
  value5 = Game_FindFreeObjectByOwner(DAT_0057c670,(intptr_t)fVar2,'\x01');
  if (value5 == 0) {
    return 0;
  }
  uvalue6 = Game_CanAffordWithCurrency
                    (arg1,0x17,(float)(((10 - value3) - value4) * 10) * arg2 * 0.01,'\x01',
                     0xffffffff);
  if ((char)uvalue6 != '\0') {
    Company_AddStaffMember(arg1,*(int *)(value5 + 0x164),(intptr_t)fVar2);
  }
  return 1;
}
