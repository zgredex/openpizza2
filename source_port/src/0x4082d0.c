// Object_UpdateSupplyBuilding: ported from Pizza Connection 2 at 0x4082d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4082d0
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall Object_UpdateSupplyBuilding(void *self,int arg1,void *arg2)

{
  uint8_t uvalue1;
  uint32_t extraout_var;
  void *pvVar2;
  uint32_t uvalue3;
  char *this_00;
  int value4;
  
                    /* Updates a supply building and spawns delivery trucks. */
  uvalue1 = Object_IsVisibleThisFrame((intptr_t)arg2);
  pvVar2 = *(void **)((intptr_t)arg2 + 0xc4);
  if (CONCAT31(extraout_var,uvalue1) != 0) {
    switch(*(uint32_t *)((intptr_t)arg2 + 0x38)) {
    case 8:
      Person_ProcessMoveEvent(arg2);
      return;
    case 0x12:
      value4 = Person_ProcessMoveEvent(arg2);
      if ((value4 == 0) &&
         (value4 = *(int *)((intptr_t)arg2 + 0x94) + -1, *(int *)((intptr_t)arg2 + 0x94) = value4,
         value4 == 0)) {
        Object_SetFrame5(arg2,-1);
        UI_DetachChildRecord((intptr_t)arg2);
        Object_SetState(arg2,5);
        return;
      }
      break;
    case 0x2b:
      value4 = Person_ProcessMoveEvent(arg2);
      if (value4 != 0) {
        return;
      }
      value4 = *(int *)((intptr_t)arg2 + 0x94) + -1;
      *(int *)((intptr_t)arg2 + 0x94) = value4;
      if (value4 != 0) {
        return;
      }
      UI_DetachChildRecord((intptr_t)arg2);
      Object_SetFrame5(arg2,-1);
      *(uint8_t *)((intptr_t)arg2 + 0x81) = 1;
    case 0x16:
      Person_ProcessMoveEvent(arg2);
      break;
    case 0x39:
      UI_DetachChildRecord((intptr_t)arg2);
      Object_SetChildField2C(arg2,0x10);
      Object_SetState(arg2,6);
      return;
    }
    return;
  }
  switch(*(uint32_t *)((intptr_t)arg2 + 0x38)) {
  case 5:
    MissionGoal_HandleEvent
              (*(void **)(*(int *)((intptr_t)self + 0x224) + 0xa8),4,*(int *)((intptr_t)arg2 + 0x164),-1);
    if (*(int *)((intptr_t)arg2 + 0xa4) == 1) {
      value4 = Map_PickRandomSpawnCell(pvVar2,1);
      if (value4 == 0) goto switchD_00408305_caseD_14;
    }
    else {
      if (*(int *)((intptr_t)arg2 + 0xa4) != 2) break;
      value4 = Map_PickRandomSpawnCell(pvVar2,2);
      if (value4 == 0) {
        value4 = UI_RandomChildEffect((intptr_t)arg2);
        Person_AdvanceRoute(arg2,value4);
        Object_SetState(arg2,0x14);
        return;
      }
    }
    _DAT_0057c610 = Person_WalkToCellOrAbort(arg2,value4);
    return;
  case 6:
    value4 = Array_GetRandomRecord28((intptr_t)pvVar2);
    if (value4 == 0) {
      return;
    }
    Person_AdvanceRoute(arg2,value4);
    Object_SetState(arg2,7);
    return;
  case 7:
    *(uint32_t *)((intptr_t)arg2 + 0x110) = 0xffffffff;
    Object_SetFieldA4Locked(arg2,0xffffffff);
    Person_LeaveBuildingAndReset(arg2);
    return;
  case 8:
    if (*(int *)((intptr_t)arg2 + 0xa4) == 1) {
      UI_SetChildRecordVariant(arg2,0x20);
      Object_SetState(arg2,0x12);
      Object_SetFrame5(arg2,0xf);
      Sound_HandleEvent(DAT_0057ba0c,arg1,0x2a);
      return;
    }
    if (*(int *)((intptr_t)arg2 + 0xa4) == 2) {
      UI_SetChildRecordVariant(arg2,0x31);
      Object_SetState(arg2,0x16);
      pvVar2 = (void *)IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),(int *)0x0);
      uvalue3 = Random_RangeFast(0x2b,0x2c);
      this_00 = City_CreateBranchObject(pvVar2,uvalue3,arg1);
      if (*(int *)((intptr_t)arg2 + 200) == 0) {
        value4 = 0;
      }
      else {
        value4 = *(int *)(*(int *)((intptr_t)arg2 + 200) + 0x20);
      }
      UI_SetChildTracking(this_00,1,value4);
      Object_SetState(this_00,0x18);
      *(uint32_t *)(this_00 + 0x10c) = *(uint32_t *)((intptr_t)arg2 + 0x164);
      return;
    }
    break;
  case 0x14:
switchD_00408305_caseD_14:
    Object_SetState(arg2,6);
    return;
  case 0x2a:
    UI_SetChildRecordVariant(arg2,*(int *)((intptr_t)arg2 + 0x88) + 0x28);
    Object_SetFrame5(arg2,1);
    Object_SetState(arg2,0x2b);
    return;
  case 0x38:
    UI_SetChildRecordVariant(arg2,*(int *)((intptr_t)arg2 + 0x88) + 0x28);
    return;
  }
  Person_ResumeRouteOrDetach(arg2);
  return;
}
