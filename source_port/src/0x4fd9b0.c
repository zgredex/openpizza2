// AI_Annoy_HireHarasser: ported from Pizza Connection 2 at 0x4fd9b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fd9b0
#include "pc2_port.h"

uint32_t __thiscall AI_Annoy_HireHarasser(void *self,void *arg1,int arg2,uint32_t arg3)

{
  int value1;
  int *ptr2;
  void *this_00;
  uint32_t uvalue3;
  void *pvVar4;
  void *pvVar5;
  
                    /* Hires a specialist for a selected harassment activity. */
  value1 = Game_CountActiveObjectsByType(arg1,0x1f);
  if (value1 < 2) {
    Player_AcquireBranch(self,arg1,4.34403e-44);
  }
  ptr2 = Game_FindFreeStaffRecord(arg1,0x1f);
  if (ptr2 == (int *)0x0) {
    return 3;
  }
  this_00 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x3c),*ptr2,(int *)0x0);
  if (this_00 == (void *)0x0) {
    return 3;
  }
  switch(arg3) {
  case 0x1a:
    pvVar5 = (void *)0x1388;
    pvVar4 = (void *)0x3;
    break;
  case 0x1b:
    pvVar5 = (void *)0x2710;
    pvVar4 = (void *)0x7;
    break;
  case 0x1c:
    pvVar5 = (void *)0x2710;
    pvVar4 = (void *)0x9;
    break;
  default:
    pvVar4 = arg1;
    pvVar5 = arg1;
    break;
  case 0x2d:
    pvVar5 = (void *)0x1388;
    pvVar4 = (void *)0xd;
  }
  value1 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(arg2 + 0x30));
  value1 = Game_GetPlayerCity(value1);
  uvalue3 = Game_CanAffordWithCurrency
                    (arg1,0x17,
                     (float)((((*(int *)(value1 + 0x68) + *(int *)(value1 + 0x50)) * 0x1e + 100) *
                             (intptr_t)pvVar5) / 100),'\x01',0xffffffff);
  if ((char)uvalue3 == '\0') {
    return 3;
  }
  Person_SendToBranchWithCarryMode(this_00,arg2,pvVar4);
  *(int *)((intptr_t)arg1 + 0x70) = *(int *)((intptr_t)arg1 + 0x70) + 1;
  return 1;
}
