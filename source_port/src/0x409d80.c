// Object_UpdateCustomerQueue: ported from Pizza Connection 2 at 0x409d80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x409d80
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall Object_UpdateCustomerQueue(void *self,void *arg1,void *arg2)

{
  void *this_00;
  void *pvVar1;
  uint8_t uvalue2;
  int value3;
  uint32_t extraout_var;
  int *ptr4;
  int value5;
  int value6;
  void *pvVar7;
  uint32_t extraout_EDX;
  double fVar8;
  
                    /* Updates a customer-queue object's path and target. */
  pvVar1 = arg1;
  *(short *)((intptr_t)arg1 + 0x16e8) = *(short *)((intptr_t)arg1 + 0x16e8) + 1;
  value3 = IDMap_Lookup((void *)((intptr_t)self + 0x20),*(int *)((intptr_t)arg2 + 0x50),(int *)0x0);
  uvalue2 = Object_IsVisibleThisFrame((intptr_t)arg2);
  pvVar7 = *(void **)((intptr_t)arg2 + 0xc4);
  if (CONCAT31(extraout_var,uvalue2) != 0) {
    switch(*(uint32_t *)((intptr_t)arg2 + 0x38)) {
    case 8:
      Person_ProcessMoveEvent(arg2);
      return;
    default:
      return;
    case 10:
      value3 = Person_ProcessMoveEvent(arg2);
      if (value3 != 0) {
        return;
      }
      pvVar7 = *(void **)((intptr_t)arg1 + 0x1758);
      if (0 < (intptr_t)pvVar7) {
        if ((intptr_t)*(void **)((intptr_t)arg2 + 0x98) < (intptr_t)pvVar7) {
          pvVar7 = *(void **)((intptr_t)arg2 + 0x98);
        }
        if (0 < (intptr_t)pvVar7) {
          this_00 = (void *)((intptr_t)arg1 + 0x1744);
          arg1 = pvVar7;
          do {
            value3 = IDMap_Lookup(this_00,0,(int *)0x0);
            value3 = IDMap_Lookup((void *)((intptr_t)self + 0x3c),value3,(int *)0x0);
            if (value3 != 0) {
              Screen_AddRecordToPanel(arg2,value3);
            }
            IDMap_RemoveRecursive(this_00,0);
            arg1 = (void *)((intptr_t)arg1 + -1);
          } while (arg1 != (void *)0x0);
        }
      }
      value3 = AdCampaign_GoToNextQueuedBuilding(self,(intptr_t)pvVar1,arg2);
      if (value3 != 0) {
        return;
      }
      value3 = AdCampaign_GoToNearestOwnBuilding(pvVar1,arg2);
      if (value3 == 0) {
        *(short *)((intptr_t)pvVar1 + 0x16e0) = *(short *)((intptr_t)pvVar1 + 0x16e0) + 1;
        return;
      }
      return;
    case 0xc:
      if (*(int *)((intptr_t)arg2 + 0x94) != -1) {
        value3 = *(int *)((intptr_t)arg2 + 0x94) + -1;
        *(int *)((intptr_t)arg2 + 0x94) = value3;
        if (value3 == 0) {
          pvVar7 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x3c),*(int *)((intptr_t)arg2 + 0x10c),
                                        (int *)0x0);
          UI_SetChildState(pvVar7,5);
          Game_GetTimeByMode(pvVar7,4);
          Object_SetFrame5(arg2,-1);
          Screen_AddRecordToPanel(arg2,(intptr_t)pvVar7);
          Customer_ApproachBranchEntrance(arg1,arg2);
          return;
        }
        return;
      }
      value3 = IDMap_Lookup((void *)((intptr_t)self + 0x3c),*(int *)((intptr_t)arg2 + 0x10c),(int *)0x0);
      if (*(int *)(value3 + 0x38) == 0xb) {
        return;
      }
      break;
    case 0xf:
      value3 = IDMap_Lookup((void *)((intptr_t)self + 0x3c),*(int *)((intptr_t)arg2 + 0x10c),(int *)0x0);
      if (*(int *)(value3 + 0x38) == 0xb) {
        return;
      }
      Object_AdvanceToQueuedTarget(self,arg1,arg2);
      return;
    case 0x10:
      value3 = *(int *)((intptr_t)arg2 + 0x94) + -1;
      *(int *)((intptr_t)arg2 + 0x94) = value3;
      if (value3 != 0) {
        return;
      }
      IDMap_Lookup((void *)((intptr_t)self + 0x3c),*(int *)((intptr_t)arg2 + 0x10c),(int *)0x0);
      value3 = Game_FindRecordByField10(arg1,*(int *)((intptr_t)arg2 + 0x10c));
      if (value3 != 0) {
        Stats_AddRecordValue(arg1,*(int *)(value3 + 0x2c),*(float *)(value3 + 0x1c),-1);
      }
      pvVar7 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x3c),*(int *)((intptr_t)arg2 + 0x10c),
                                    (int *)0x0);
      UI_SetChildState(pvVar7,0xffff);
      Object_SetState(pvVar7,0x11);
      UI_SetChildRecordVariant(pvVar7,*(int *)((intptr_t)pvVar7 + 0x84) + 0x14);
      UI_SetChildState(pvVar7,9);
      Game_GetTimeByMode(pvVar7,6);
      value3 = *(int *)((intptr_t)arg1 + 0x30);
      value5 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
      if (value3 == value5) {
        if (*(int *)((intptr_t)pvVar7 + 0x30) == 0xf) {
          MissionGoal_HandleEvent(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),7,-1,-1);
          MissionGoal_HandleEvent(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),0x12,-1,-1);
        }
        UI_AppendCommandIfActive(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),0x15,1);
        MissionGoal_HandleEvent(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),0x15,-1,-1);
      }
      Object_SetFrame5(arg2,-1);
      UI_SetChildState(arg2,0xffff);
      Object_AdvanceToQueuedTarget(self,arg1,arg2);
      return;
    case 0x25:
      Person_TruncatePathToCurrentStep((intptr_t)arg2);
      return;
    }
    goto LAB_0040a11f;
  }
  switch(*(uint32_t *)((intptr_t)arg2 + 0x38)) {
  case 5:
    ptr4 = Map_LinkNeighbors(pvVar7,arg1);
    value5 = Array_GetRecord28(pvVar7,1,(intptr_t)*(short *)(*(int *)(*(int *)((intptr_t)pvVar7 + 0x4c) + 8 +
                                                               *ptr4 * 0xc) + 0x24));
    if (value5 == 0) {
      Object_SetState(arg2,6);
      return;
    }
    value6 = Rating_AdjustA(value3);
    fVar8 = Game_GetRatingMultiplier((intptr_t)arg1);
    UI_SetChildScale(arg2,(double)(fVar8 * (double)value6));
    value3 = Rating_GetComposite(value3);
    *(int *)((intptr_t)arg2 + 0x98) = (value3 >> 4) + 1;
    _DAT_0057c610 = Person_WalkToCellOrAbort(arg2,value5);
    if (_DAT_0057c610 != 0) {
      *(int *)((intptr_t)arg2 + 0x88) = *ptr4;
      Object_SetState(arg2,8);
      return;
    }
    break;
  case 6:
    value3 = Array_GetRandomRecord28((intptr_t)pvVar7);
    if (value3 != 0) {
      Person_AdvanceRoute(arg2,value3);
      Object_SetState(arg2,7);
      return;
    }
    break;
  case 7:
    List_Node_Reset((intptr_t)arg2 + 0x114);
    Person_LeaveBuildingAndReset(arg2);
    Person_SetAtWork((intptr_t)arg2,extraout_EDX,(intptr_t)arg1,'\x01');
    return;
  case 8:
    UI_SetChildRecordVariant(arg2,0x32);
    Object_SetState(arg2,10);
    Game_MoveTypeBObjectsToStateList(arg2,arg1);
    return;
  default:
    Person_ResumeRouteOrDetach(arg2);
    return;
  case 0xc:
    pvVar7 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x3c),*(int *)((intptr_t)arg2 + 0x10c),
                                  (int *)0x0);
    if (*(int *)((intptr_t)pvVar7 + 0x38) == 0xb) {
      value3 = Building_MapSubtypeToState(*(uint32_t *)((intptr_t)pvVar7 + 0x84));
      UI_SetChildRecordVariant(arg2,value3 + 0x18);
      UI_SetChildState(pvVar7,0xffff);
      Object_SetFrame5(arg2,5);
      return;
    }
    goto LAB_0040a11f;
  case 0xf:
    pvVar7 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x3c),*(int *)((intptr_t)arg2 + 0x10c),
                                  (int *)0x0);
    if (*(int *)((intptr_t)pvVar7 + 0x38) == 0xb) {
      Object_SetState(arg2,0x10);
      UI_SetChildState(pvVar7,7);
      UI_SetChildState(arg2,7);
      Object_SetFrame5(arg2,2);
      Sound_HandleEvent(DAT_0057ba0c,(intptr_t)arg1,0x31);
      if (*(int *)((intptr_t)arg2 + 0x128) < 1) {
        value3 = Building_MapSubtypeToState(*(uint32_t *)((intptr_t)pvVar7 + 0x84));
        UI_SetChildRecordVariant(arg2,value3 + 0x28);
        return;
      }
      value3 = Building_MapSubtypeToState(*(uint32_t *)((intptr_t)pvVar7 + 0x84));
      UI_SetChildRecordVariant(arg2,value3 + 0x20);
      return;
    }
LAB_0040a11f:
    Customer_ApproachBranchEntrance(arg1,arg2);
    return;
  case 0x25:
    Object_SetState(arg2,6);
    UI_SetChildState(arg2,0x1d);
    return;
  }
  return;
}
