// AI_Annoy_SendThugsToHeadquarters: ported from Pizza Connection 2 at 0x4ff200.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ff200
#include "pc2_port.h"

uint32_t __thiscall AI_Annoy_SendThugsToHeadquarters(void *self,void *arg1,int arg2)

{
  bool flag1;
  uint32_t uvalue2;
  int value3;
  uint32_t extraout_var;
  int *ptr4;
  void *this_00;
  uint32_t uvalue5;
  int value6;
  
                    /* Sends hired thugs to a rival branch or headquarters. */
  uvalue2 = _rand();
  value3 = Game_CountActiveObjectsByType(arg1,0x1f);
  if (value3 < 2) {
    Player_AcquireBranch(self,arg1,4.34403e-44);
    return 1;
  }
  flag1 = Math_CompareRounded();
  if (CONCAT31(extraout_var,flag1) == 0) {
    return 2;
  }
  value3 = AI_OpenBranchesInCity(self,arg1,arg2);
  if (value3 != 0) {
    ptr4 = Game_FindFreeStaffRecord(arg1,0x1f);
    if (ptr4 == (int *)0x0) {
      return 3;
    }
    this_00 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x3c),*ptr4,(int *)0x0);
    if (this_00 == (void *)0x0) {
      return 3;
    }
    if ((uvalue2 & 1) == 0) {
      value3 = AI_HireBranchWorker(arg1,arg2);
      if (value3 == 0) {
        return 3;
      }
      value3 = AI_HireBranchWorker(arg1,arg2);
      if (value3 == 0) {
        return 3;
      }
      uvalue5 = Game_CanAffordWithCurrency(arg1,0x17,100000.0,'\x01',0xffffffff);
      if ((char)uvalue5 != '\0') {
        Person_SendToBranchWithCarryMode(this_00,arg2,0x11);
      }
      Object_AdjustShortPercent(self,*(int *)((intptr_t)arg1 + 0x4c),-0x14);
      return 1;
    }
    value3 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(arg2 + 0x30));
    value3 = *(int *)(value3 + 0x1d8);
    if (value3 != 0) {
      value6 = AI_SendGangsterForProtection(arg1,value3);
      if (value6 == 0) {
        return 3;
      }
      value6 = AI_SendGangsterForProtection(arg1,value3);
      if (value6 == 0) {
        return 3;
      }
      Courier_StartHeadquartersBombing(this_00,value3);
      Object_AdjustShortPercent(self,*(int *)((intptr_t)arg1 + 0x4c),-0x14);
    }
  }
  return 1;
}
