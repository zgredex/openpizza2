// Branch_AddAdvertisingPlan: ported from Pizza Connection 2 at 0x5001f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5001f0
#include "pc2_port.h"


uint32_t __thiscall
Branch_AddAdvertisingPlan(void *self,int arg1,void *arg2,uint32_t arg3)

{
  int value1;
  void *this_00;
  int value2;
  void *pvVar3;
  uint32_t *uptr4;
  uint32_t uvalue5;
  uint32_t *uptr6;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t *local_4;
  
                    /* Creates and starts an advertising plan for a branch. */
  local_4 = (uint32_t *)0xffffffff;
  puStack_8 = &LAB_0055a1cb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)arg2 + 0x28),(int *)0x0);
  value1 = *(int *)((intptr_t)arg2 + 8);
  this_00 = *(void **)((intptr_t)self + arg1 * 0x168 + 0x70);
  if (value1 != -1) {
    if (value1 == *(int *)((intptr_t)self + arg1 * 0x168 + 0x40)) {
      ExceptionList = local_c;
      return 1;
    }
    value2 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    if (value1 != value2) {
      ExceptionList = local_c;
      return 0;
    }
    pvVar3 = (void *)Game_GetPlayerBySlot(DAT_0057c670,value1);
    uptr4 = (uint32_t *)Game_FindPlanByTarget(pvVar3,(intptr_t)arg2);
    uvalue5 = Game_CanAffordWithCurrency(this_00,0x17,(float)(intptr_t)uptr4[8] * 10.0,'\x01',0xffffffff);
    if ((char)uvalue5 == '\0') {
      ExceptionList = local_c;
      return 0;
    }
    Object_AdjustShortPercent(self,arg1,0x14);
    Company_DeactivatePlanEntry(pvVar3,uptr4,0);
  }
  pvVar3 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)arg2 + 0x28),
                                (int *)0x0);
  uptr4 = (uint32_t *)Game_FindPlanByTarget(this_00,(intptr_t)arg2);
  if (uptr4 == (uint32_t *)0x0) {
    uptr6 = operator_new(0x30);
    if (uptr6 == (uint32_t *)0x0) {
      uptr4 = (uint32_t *)0x0;
    }
    else {
      local_4 = uptr4;
      uptr4 = (uint32_t *)GamePlan_Construct(uptr6);
    }
    local_4 = (uint32_t *)0xffffffff;
    Game_SetDifficulty(uptr4,3);
    uptr4[0xb] = *(uint32_t *)((intptr_t)arg2 + 0x24);
    uptr4[3] = arg3;
  }
  GamePlan_Optimize(self,arg1,uptr4);
  value1 = *(int *)((intptr_t)arg2 + 0x74);
  uptr4[8] = 0xdac;
  GamePlan_SetActiveEffect(uptr4,1,*(int *)((intptr_t)self + arg1 * 0x168 + 0x40));
  List_Add((void *)((intptr_t)this_00 + 300),uptr4);
  Game_PlaceObjectInPlayerCity(pvVar3,arg2,*(int *)((intptr_t)self + arg1 * 0x168 + 0x40));
  Object_SetFacadeAndLogoVariant(pvVar3,1,(intptr_t)arg2,(intptr_t)this_00);
  *(uint32_t *)(value1 + 8) = 0x4b;
  if ((*(void **)((intptr_t)DAT_0057c670 + 0x218) == arg2) &&
     (*(void **)((intptr_t)DAT_0057c670 + 0x25c) != (void *)0x0)) {
    UI_QueueControlCommand(*(void **)((intptr_t)DAT_0057c670 + 0x25c),-0x1868e,0x23,1);
  }
  ExceptionList = local_c;
  return 1;
}
