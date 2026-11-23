// Object_UpdateBranchOpenClose: ported from Pizza Connection 2 at 0x408a70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x408a70
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall Object_UpdateBranchOpenClose(void *self,char *arg1,void *arg2)

{
  uint8_t uvalue1;
  uint32_t extraout_var;
  int value2;
  void *pvVar3;
  int value4;
  uint8_t unaff_SI;
  uint32_t unaff_EDI;
  
                    /* Handles branch opening/closing and occupant spawning. */
  uvalue1 = Object_IsVisibleThisFrame((intptr_t)arg2);
  if (CONCAT31(extraout_var,uvalue1) == 0) {
    switch(*(uint32_t *)((intptr_t)arg2 + 0x38)) {
    case 5:
      switch(*(uint32_t *)((intptr_t)arg2 + 0xa4)) {
      default:
        goto switchD_00408aa5_caseD_9;
      case 3:
      case 7:
      case 9:
      case 0xd:
      case 0x11:
        Game_AdjustPlayerObjectPercent(*(void **)((intptr_t)self + 0x90),*(int *)(arg1 + 0x30),5);
        value2 = AI_ComputePath(0,0,0,unaff_EDI,unaff_SI);
        if (value2 == 0) {
          value2 = UI_RandomChildEffect((intptr_t)arg2);
          Person_AdvanceRoute(arg2,value2);
          Object_SetState(arg2,0x14);
          return;
        }
        _DAT_0057c610 = Person_WalkToCellOrAbort(arg2,value2);
        return;
      case 0xffffffff:
        goto switchD_00408aa5_caseD_14;
      }
    case 6:
      value2 = Array_GetRandomRecord28(*(int *)((intptr_t)arg2 + 0xc4));
      if (value2 != 0) {
        Person_AdvanceRoute(arg2,value2);
        Object_SetState(arg2,7);
        return;
      }
      break;
    case 7:
      Object_SetFieldA4Locked(arg2,0xffffffff);
      Person_LeaveBuildingAndReset(arg2);
      return;
    case 8:
      switch(*(uint32_t *)((intptr_t)arg2 + 0xa4)) {
      case 3:
      case 7:
      case 9:
      case 0xd:
      case 0x11:
        UI_SetChildRecordVariant(arg2,0x19);
        Object_SetState(arg2,0x17);
        Object_SetFrame5(arg2,2);
        return;
      }
    default:
switchD_00408aa5_caseD_9:
      Person_ResumeRouteOrDetach(arg2);
      return;
    case 0x14:
switchD_00408aa5_caseD_14:
      Object_SetState(arg2,6);
      return;
    case 0x2a:
      UI_SetChildRecordVariant(arg2,*(int *)((intptr_t)arg2 + 0x88) + 0x40);
      Object_SetFrame5(arg2,1);
      Object_SetState(arg2,0x2b);
      return;
    case 0x38:
      UI_SetChildRecordVariant(arg2,*(int *)((intptr_t)arg2 + 0x88) + 0x40);
      return;
    }
  }
  else {
    switch(*(uint32_t *)((intptr_t)arg2 + 0x38)) {
    case 8:
      Person_ProcessMoveEvent(arg2);
      return;
    case 0x17:
      value2 = Person_ProcessMoveEvent(arg2);
      if (value2 == 0) {
        switch(*(uint32_t *)((intptr_t)arg2 + 0xa4)) {
        case 3:
        case 7:
        case 9:
        case 0xd:
        case 0x11:
          value2 = *(int *)((intptr_t)arg2 + 0x94) + -1;
          *(int *)((intptr_t)arg2 + 0x94) = value2;
          if (value2 == 0) {
            Object_SetFrame5(arg2,-1);
            UI_DetachChildRecord((intptr_t)arg2);
            Object_SetChildField2C(arg2,0);
            Object_SetState(arg2,6);
            UI_SetChildState(arg2,0xffff);
            switch(*(uint32_t *)((intptr_t)arg2 + 0xa4)) {
            case 3:
              pvVar3 = (void *)IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),
                                            (int *)0x0);
              arg1 = City_CreateBranchObject(pvVar3,0x1a,(intptr_t)arg1);
              value2 = *(int *)((intptr_t)arg2 + 0x110);
              value4 = Game_GetCurrentPlayerCompanyName((intptr_t)self);
              if (value2 == value4) {
                Array_SetSlot(*(void **)(*(int *)((intptr_t)self + 0x224) + 0xac),1,1);
              }
              break;
            default:
              break;
            case 7:
              pvVar3 = (void *)IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),
                                            (int *)0x0);
              arg1 = City_CreateBranchObject(pvVar3,0x1b,(intptr_t)arg1);
              MissionGoal_HandleEvent
                        (*(void **)(*(int *)((intptr_t)self + 0x224) + 0xa8),5,
                         *(int *)((intptr_t)arg2 + 0x164),-1);
              break;
            case 9:
              pvVar3 = (void *)IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),
                                            (int *)0x0);
              arg1 = City_CreateBranchObject(pvVar3,0x1c,(intptr_t)arg1);
              MissionGoal_HandleEvent
                        (*(void **)(*(int *)((intptr_t)self + 0x224) + 0xa8),3,
                         *(int *)((intptr_t)arg2 + 0x164),-1);
              break;
            case 0xd:
              pvVar3 = (void *)IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),
                                            (int *)0x0);
              arg1 = City_CreateBranchObject(pvVar3,0x2d,(intptr_t)arg1);
              break;
            case 0x11:
              pvVar3 = (void *)IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),
                                            (int *)0x0);
              arg1 = City_CreateBranchObject(pvVar3,0x2f,(intptr_t)arg1);
              value2 = Game_GetPlayerBySlot(self,*(int *)((intptr_t)arg2 + 0x110));
              *(int *)(value2 + 0x88) = *(int *)(value2 + 0x88) + 1;
              value2 = *(int *)((intptr_t)arg2 + 0x110);
              value4 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
              if (value2 == value4) {
                value2 = *(int *)((intptr_t)arg2 + 0x164);
                Array_SearchSet(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xac),0x12);
                MissionGoal_HandleEvent
                          (*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),9,value2,-1);
              }
              value2 = IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),(int *)0x0);
              *(int *)(value2 + 0x10b8) = *(int *)(value2 + 0x10b8) + 1;
              Game_AbortOrdersTargetingObject(*(int *)((intptr_t)arg2 + 0xfc),1,arg2);
            }
            if (*(int *)((intptr_t)arg2 + 200) == 0) {
              value2 = 0;
            }
            else {
              value2 = *(int *)(*(int *)((intptr_t)arg2 + 200) + 0x20);
            }
            UI_SetChildTracking(arg1,1,value2);
            Object_SetState(arg1,0x18);
            Object_SetFieldA4Locked(arg2,0xffffffff);
          }
        }
      }
      break;
    case 0x2b:
      value2 = Person_ProcessMoveEvent(arg2);
      if ((value2 == 0) &&
         (value2 = *(int *)((intptr_t)arg2 + 0x94) + -1, *(int *)((intptr_t)arg2 + 0x94) = value2,
         value2 == 0)) {
        UI_DetachChildRecord((intptr_t)arg2);
        Object_SetFrame5(arg2,-1);
        *(uint8_t *)((intptr_t)arg2 + 0x81) = 1;
        Person_ProcessMoveEvent(arg2);
        return;
      }
      break;
    case 0x39:
      UI_DetachChildRecord((intptr_t)arg2);
      Object_SetChildField2C(arg2,0x20);
      Object_SetState(arg2,6);
      return;
    }
  }
  return;
}
