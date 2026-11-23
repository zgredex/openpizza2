// Company_DeactivatePlanEntry: ported from Pizza Connection 2 at 0x4e3ab0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e3ab0
#include "pc2_port.h"

void __thiscall Company_DeactivatePlanEntry(void *self,uint32_t *arg1,int arg2)

{
  int value1;
  void *this_00;
  void *pvVar2;
  
                    /* Deactivates a company plan and removes or restyles its target. */
  if (arg1[1] != 0) {
    this_00 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),
                                   (int *)0x0);
    if (arg1[2] == 3) {
      pvVar2 = (void *)Game_FindRecordByField24(this_00,arg1[0xb]);
      value1 = *(int *)((intptr_t)pvVar2 + 0x74);
      *(uint32_t *)(value1 + 0x10) = 0;
      *(uint32_t *)(value1 + 0x18) = 0;
      *(uint32_t *)(value1 + 8) = 0;
      *(uint32_t *)(value1 + 0x14) = 0;
      Game_PlaceObjectInPlayerCity(this_00,pvVar2,-1);
      Object_SetFacadeAndLogoVariant(this_00,0,(intptr_t)pvVar2,(intptr_t)self);
    }
    if (arg1[2] == 2) {
      Branch_ExpelCustomers(*(int *)(DAT_0057c670 + 0x9c));
    }
    GamePlan_SetActiveEffect(arg1,0,*(int *)((intptr_t)self + 0x48));
  }
  if ((arg2 != 0) || (arg1[2] == 3)) {
    IDMap_RemoveByKey((void *)((intptr_t)self + 300),(intptr_t)arg1);
    if (arg1 != (uint32_t *)0x0) {
      (**(code **)*arg1)(1);
    }
  }
  return;
}
