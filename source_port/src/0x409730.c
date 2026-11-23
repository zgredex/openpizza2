// Object_UpdateCitizen: ported from Pizza Connection 2 at 0x409730.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x409730
#include "pc2_port.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Object_UpdateCitizen(void *arg1,void *arg2)

{
  uint8_t uvalue1;
  uint32_t extraout_var;
  void *self;
  int value2;
  uint32_t uvalue3;
  uint8_t unaff_SI;
  uint32_t unaff_EDI;
  uint32_t local_30;
  int local_2c;
  uint32_t local_28 [5];
  int local_14;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Updates a citizen's residential/service target and timers. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557d98;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  List_Construct(local_28,0);
  local_4 = 0;
  uvalue1 = Object_IsVisibleThisFrame((intptr_t)arg2);
  if (CONCAT31(extraout_var,uvalue1) == 0) {
    switch(*(uint32_t *)((intptr_t)arg2 + 0x38)) {
    case 5:
      if (*(int *)((intptr_t)arg2 + 0xa4) == 2) {
        value2 = Game_CountFreeResidentialBuildings((intptr_t)arg1);
        if ((0 < value2) &&
           (value2 = Game_FindNearestServiceBuilding(arg1,(intptr_t)arg2), value2 != 0)) {
          value2 = *(int *)(value2 + 0x164);
          *(int *)((intptr_t)arg2 + 0x8c) = value2;
          value2 = Person_FindFreeNeighborCell(arg2,arg1,value2,&local_30);
          if (value2 != 0) {
            _DAT_0057c610 = Person_WalkToCellOrAbort(arg2,value2);
            goto LAB_00409aa5;
          }
        }
      }
      else {
        value2 = AI_ComputePath(0,0,0,unaff_EDI,unaff_SI);
        if (value2 != 0) {
          _DAT_0057c610 = Person_WalkToCellOrAbort(arg2,value2);
          break;
        }
      }
      Object_SetState(arg2,6);
      break;
    case 6:
      value2 = Array_GetRandomRecord28(*(int *)((intptr_t)arg2 + 0xc4));
      if (value2 != 0) {
        Person_AdvanceRoute(arg2,value2);
        Object_SetState(arg2,7);
      }
      break;
    case 7:
      Object_SetFieldA4Locked(arg2,0xffffffff);
      Person_LeaveBuildingAndReset(arg2);
      break;
    case 8:
      UI_SetChildRecordVariant(arg2,*(int *)((intptr_t)arg2 + 0x88) + 8);
      Object_SetState(arg2,0x21);
      Object_SetFrame5(arg2,1);
      break;
    default:
      Person_ResumeRouteOrDetach(arg2);
      break;
    case 0x20:
      UI_SetChildRecordVariant(arg2,*(int *)((intptr_t)arg2 + 0x88) + 0x10);
      Sound_HandleEvent(DAT_0057ba0c,(intptr_t)arg1,0x33);
      Object_PickByCursorDirection(arg2,arg1,&local_30,local_28);
      value2 = 0;
      if (0 < local_14) {
        do {
          self = (void *)IDMap_Lookup(local_28,value2,(int *)0x0);
          Object_SetState(self,0x23);
          value2 = value2 + 1;
        } while (value2 < local_14);
      }
      break;
    case 0x22:
      Object_SetState(arg2,5);
    }
  }
  if (CONCAT31(extraout_var,uvalue1) != 0) {
    value2 = *(int *)((intptr_t)arg2 + 0x38);
    if (value2 == 8) {
      value2 = Person_ProcessMoveEvent(arg2);
      if (value2 == 0) {
        value2 = Game_CountFreeResidentialBuildings((intptr_t)arg1);
        if (value2 == 0) {
          UI_DetachChildRecord((intptr_t)arg2);
          Object_SetState(arg2,6);
          if (*(void **)(local_2c + 0x9c) == arg1) {
            Sound_ProcessEvent(DAT_0057ba0c,0x20,0xf,'\x01');
          }
        }
        else {
          if (*(int *)((intptr_t)arg2 + 200) == 0) {
            uvalue3 = 0xffffffff;
          }
          else {
            uvalue3 = *(uint32_t *)(*(int *)((intptr_t)arg2 + 200) + 0xc);
          }
          *(uint32_t *)((intptr_t)arg2 + 0x88) = uvalue3;
          value2 = Object_PickByCursorDirection(arg2,arg1,&local_30,(void *)0x0);
          if (value2 == 0) {
            if ((*(int *)((intptr_t)arg2 + 0xa4) == 2) &&
               (value2 = Game_FindNearestServiceBuilding(arg1,(intptr_t)arg2), value2 != 0)) {
              value2 = *(int *)(value2 + 0x164);
              *(int *)((intptr_t)arg2 + 0x8c) = value2;
              value2 = Person_FindFreeNeighborCell(arg2,arg1,value2,&local_30);
              if (value2 != 0) {
                Person_AdvanceRoute(arg2,value2);
              }
            }
          }
          else {
            *(uint32_t *)((intptr_t)arg2 + 0x88) = local_30;
            Person_TruncatePathToCurrentStep((intptr_t)arg2);
            Object_SetState(arg2,0x20);
          }
        }
      }
    }
    else if (value2 == 0x20) {
      value2 = Object_PickByCursorDirection(arg2,arg1,&local_30,(void *)0x0);
      if (value2 == 0) {
        Object_SetState(arg2,0x22);
        MapObject_SetRecordFrame(arg2,*(int *)((intptr_t)arg2 + 0x88) + 0x10);
      }
      else if (*(uint32_t *)((intptr_t)arg2 + 0x88) != local_30) {
        *(uint32_t *)((intptr_t)arg2 + 0x88) = local_30;
        UI_SetChildRecordVariant(arg2,local_30 + 0x10);
      }
    }
    else if (value2 == 0x21) {
      value2 = Object_PickByCursorDirection(arg2,arg1,&local_30,(void *)0x0);
      if (value2 == 0) {
        value2 = *(int *)((intptr_t)arg2 + 0x94) + -1;
        *(int *)((intptr_t)arg2 + 0x94) = value2;
        if (value2 == 0) {
          Object_SetFrame5(arg2,-1);
          UI_DetachChildRecord((intptr_t)arg2);
          Object_SetState(arg2,5);
        }
      }
      else {
        *(uint32_t *)((intptr_t)arg2 + 0x88) = local_30;
        Object_SetFrame5(arg2,-1);
        UI_DetachChildRecord((intptr_t)arg2);
        Object_SetState(arg2,0x20);
      }
    }
  }
LAB_00409aa5:
  local_4 = 0xffffffff;
  List_Node_Destroy(local_28);
  ExceptionList = local_c;
  return;
}
