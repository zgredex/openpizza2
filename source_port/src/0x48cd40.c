// Game_IsBuildingAssignedToOtherCompany: ported from Pizza Connection 2 at 0x48cd40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48cd40
#include "pc2_port.h"

uint32_t __thiscall Game_IsBuildingAssignedToOtherCompany(void *self,int arg1,int arg2)

{
  void *this_00;
  void *pvVar1;
  int value2;
  
  pvVar1 = (void *)Game_GetPlayerBySlot(self,arg2);
  this_00 = *(void **)((intptr_t)self + *(int *)((intptr_t)self + 0x2ec) * 4 + 0x200);
  if ((pvVar1 != this_00) && (pvVar1 != (void *)0x0)) {
    if (arg1 < 0x14) {
      value2 = IDMap_Lookup((void *)((intptr_t)pvVar1 + 0x148),arg1,(int *)0x0);
      pvVar1 = (void *)0x0;
      if (value2 == 0) goto LAB_0048cdc0;
      value2 = *(int *)(value2 + 0x16f0);
    }
    else if (arg1 < 0x28) {
      value2 = IDMap_Lookup((void *)((intptr_t)pvVar1 + 0x180),arg1 + -0x14,(int *)0x0);
      pvVar1 = (void *)0x0;
      if (value2 == 0) goto LAB_0048cdc0;
      value2 = *(int *)(value2 + 0x34);
    }
    else {
      value2 = *(int *)((intptr_t)pvVar1 + 0x1d8);
      pvVar1 = (void *)0x0;
      if (value2 == 0) goto LAB_0048cdc0;
    }
    pvVar1 = (void *)Game_IsValueAssignedToCompany(this_00,value2);
    if ((char)pvVar1 != '\0') {
      return CONCAT31((int3)((uint32_t)pvVar1 >> 8),1);
    }
  }
LAB_0048cdc0:
  return (uint32_t)pvVar1 & 0xffffff00;
}
