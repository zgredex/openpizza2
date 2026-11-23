// Object_ActionSpawnBranch: ported from Pizza Connection 2 at 0x50a3c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50a3c0
#include "pc2_port.h"


void __fastcall Object_ActionSpawnBranch(void *arg1,uint32_t arg2)

{
  void *pvVar1;
  int value2;
  uint32_t uvalue3;
  void *pvVar4;
  int value5;
  int value6;
  uint32_t uvalue7;
  uint32_t *self;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Spawns and attaches a new branch object to a building. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a2fb;
  local_c = ExceptionList;
  if (*(int *)(*(int *)((intptr_t)arg1 + 0xfc) + 0x94) != 0) {
    ExceptionList = &local_c;
    Person_CancelVisitAtOccupiedBuilding(arg1,arg2,0);
    ExceptionList = local_c;
    return;
  }
  ExceptionList = &local_c;
  value2 = State_IsMenuState((intptr_t)arg1);
  if (value2 != 0) {
    Object_Reset108((intptr_t)arg1);
  }
  if (*(int *)((intptr_t)arg1 + 0x108) != 1) goto LAB_0050a547;
  pvVar1 = *(void **)((intptr_t)arg1 + 0xfc);
  value2 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x20),*(int *)((intptr_t)arg1 + 0x50),(int *)0x0);
  if (value2 == 0) {
    uvalue3 = 0xffffffff;
  }
  else {
    Object_SetState(arg1,0x2e);
    uvalue3 = (uint32_t)*(uint8_t *)(value2 + 0x824);
  }
  if (uvalue3 == 0) {
LAB_0050a490:
    value2 = 0x1e;
    uvalue7 = DAT_00580de0;
  }
  else if (uvalue3 == 1) {
    value2 = 0x1d;
    uvalue7 = DAT_00580dc8;
  }
  else {
    if (uvalue3 == 2) goto LAB_0050a490;
    value2 = 0x1f;
    uvalue7 = DAT_00580b00;
  }
  pvVar4 = operator_new(0x16c);
  self = (uint32_t *)0x0;
  local_4 = 0;
  if (pvVar4 != (void *)0x0) {
    self = Object_Construct(pvVar4,value2,*(int *)((intptr_t)arg1 + 0x28),0,0,-1);
  }
  local_4 = 0xffffffff;
  Game_FormatObjectName(DAT_0057ba10,0,(uint8_t *)(self + 1),uvalue7);
  Game_AddObjectToRegistry(DAT_0057c670,self);
  pvVar4 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)pvVar1 + 8));
  value5 = Game_GetLevelReward(pvVar4,value2);
  value6 = Game_CountActiveObjectsByType(pvVar4,value2);
  if (value6 + 1 < value5) {
    Object_AttachToParent(self,pvVar1,1);
    Company_AddStaffMember(pvVar4,self[0x59],value2);
    self[0x33] = pvVar1;
  }
LAB_0050a547:
  Object_SetFieldA4Locked(arg1,0xffffffff);
  Object_Activate(arg1,*(void **)((intptr_t)arg1 + 0xfc));
  ExceptionList = local_c;
  return;
}
