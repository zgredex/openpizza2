// Object_UpdateConstructionWorker: ported from Pizza Connection 2 at 0x40a760.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x40a760
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall Object_UpdateConstructionWorker(void *self,void *arg1,void *arg2)

{
  void *this_00;
  uint32_t uvalue1;
  uint8_t uvalue2;
  int value3;
  uint32_t extraout_var;
  int *ptr4;
  uint32_t uvalue5;
  int value6;
  int value7;
  uint8_t unaff_SI;
  uint32_t unaff_EDI;
  double fVar8;
  
                    /* Updates a construction worker's plot and work state. */
  *(short *)((intptr_t)arg1 + 0x16ea) = *(short *)((intptr_t)arg1 + 0x16ea) + 1;
  value3 = IDMap_Lookup((void *)((intptr_t)self + 0x20),*(int *)((intptr_t)arg2 + 0x50),(int *)0x0);
  uvalue2 = Object_IsVisibleThisFrame((intptr_t)arg2);
  this_00 = *(void **)((intptr_t)arg2 + 0xc4);
  if (CONCAT31(extraout_var,uvalue2) == 0) {
    switch(*(uint32_t *)((intptr_t)arg2 + 0x38)) {
    case 5:
      goto switchD_0040a7ba_caseD_5;
    case 6:
      value3 = Array_GetRandomRecord28((intptr_t)this_00);
      if (value3 != 0) {
        Person_AdvanceRoute(arg2,value3);
      }
      Object_SetState(arg2,7);
      return;
    case 7:
      Person_LeaveBuildingAndReset(arg2);
      return;
    case 8:
      if (*(int *)((intptr_t)arg2 + 0xa4) != 4) {
        UI_SetChildRecordVariant(arg2,10);
        Object_SetState(arg2,10);
        Object_SetFrame5(arg2,0xf);
        return;
      }
      uvalue1 = *(uint32_t *)((intptr_t)arg2 + 0x88);
      ptr4 = (int *)RecordMap_Lookup1998(arg1,uvalue1);
      Object_SetChildField2C(arg2,0);
      if ((ptr4 == (int *)0x0) || (*ptr4 < 1)) {
        value3 = 10;
      }
      else {
        uvalue5 = uvalue1 & 0x80000001;
        if ((intptr_t)uvalue5 < 0) {
          uvalue5 = (uvalue5 - 1 | 0xfffffffe) + 1;
        }
        value3 = (-(uint32_t)(uvalue5 != 0) & 0xfffffffc) + 0xe;
      }
      UI_SetChildRecordVariant(arg2,value3);
      Object_SetState(arg2,10);
      Object_SetFrame5(arg2,0xf);
      if ((ptr4 != (int *)0x0) && (0 < *ptr4)) {
        Branch_StartConstructionOnPlot(arg1,uvalue1);
        Sound_HandleEvent(DAT_0057ba0c,(intptr_t)arg1,0x30);
      }
      Object_SetFieldA4Locked(arg2,0xffffffff);
      return;
    default:
      Person_ResumeRouteOrDetach(arg2);
      return;
    case 0x25:
      Object_SetState(arg2,6);
      UI_SetChildState(arg2,0x1d);
      return;
    case 0x30:
      UI_SetChildRecordVariant(arg2,10);
      Object_SetState(arg2,10);
      if (*(int *)((intptr_t)arg2 + 0x128) < 1) {
        return;
      }
      value3 = 0;
      if (*(int *)((intptr_t)arg2 + 0x128) < 1) {
        return;
      }
      do {
        value6 = IDMap_Lookup((void *)((intptr_t)arg2 + 0x114),value3,(int *)0x0);
        value6 = IDMap_Lookup((void *)((intptr_t)self + 0x3c),value6,(int *)0x0);
        if (*(int *)(value6 + 0x38) == 0x1a) {
          Game_AddObjectToStateList(arg1,value6);
        }
        value3 = value3 + 1;
      } while (value3 < *(int *)((intptr_t)arg2 + 0x128));
      return;
    }
  }
  switch(*(uint32_t *)((intptr_t)arg2 + 0x38)) {
  case 8:
    value3 = Game_CountAvailableBusinessBuildings((intptr_t)arg1);
    if (0 < value3) {
      Person_ProcessMoveEvent(arg2);
      return;
    }
    break;
  case 10:
    value6 = Person_ProcessMoveEvent(arg2);
    if (value6 == 0) {
      if (*(char *)(value3 + 0x825) == '\x01') {
        if (0 < *(int *)((intptr_t)arg1 + 0x1774)) {
          List_Node_Reset((intptr_t)arg2 + 0x114);
          value6 = IDMap_Lookup((void *)((intptr_t)arg1 + 0x1760),0,(int *)0x0);
          value6 = IDMap_Lookup((void *)((intptr_t)self + 0x3c),value6,(int *)0x0);
          IDMap_RemoveRecursive((void *)((intptr_t)arg1 + 0x1760),0);
          if ((value6 != 0) && (*(int *)(value6 + 0x38) == 0x1a)) {
            Object_SetState(arg2,6);
            Object_SetFieldA4Locked(arg2,8);
            UI_DetachChildRecord((intptr_t)arg2);
            *(uint32_t *)((intptr_t)arg2 + 0x10c) = *(uint32_t *)(value6 + 0x164);
            Object_SetChildField2C(arg2,0x20);
            return;
          }
        }
        if ((*(int *)((intptr_t)arg2 + 0x128) == 0) &&
           (value6 = Object_FindNearbyCustomer(arg2,arg1), value6 != 0)) {
          ptr4 = Map_LinkNeighbors(this_00,arg1);
          value7 = Array_GetRecord28(this_00,1,
                                    (intptr_t)*(short *)(*(int *)(*(int *)((intptr_t)this_00 + 0x4c) + 8 +
                                                            *ptr4 * 0xc) + 0x24));
          if (value7 != 0) {
            Screen_AddRecordToPanel(arg2,value6);
            Object_SetState(arg2,0x30);
            _DAT_0057c610 = Person_AdvanceRoute(arg2,value7);
            return;
          }
        }
      }
      if ((*(char *)(value3 + 0x825) == '\x02') &&
         (value3 = Game_PickFreeConstructionPlot((intptr_t)arg1), value3 != -1)) {
        *(int *)((intptr_t)arg2 + 0x88) = value3;
        Object_SetFieldA4Locked(arg2,4);
        Object_SetFrame5(arg2,-1);
        UI_DetachChildRecord((intptr_t)arg2);
        Object_SetState(arg2,6);
        return;
      }
      *(short *)((intptr_t)arg1 + 0x16e2) = *(short *)((intptr_t)arg1 + 0x16e2) + 1;
      value3 = *(int *)((intptr_t)arg2 + 0x94) + -1;
      *(int *)((intptr_t)arg2 + 0x94) = value3;
      if (value3 == 0) {
        Object_SetFrame5(arg2,-1);
        UI_DetachChildRecord((intptr_t)arg2);
        Object_SetState(arg2,5);
      }
    }
    break;
  case 0x25:
    Person_TruncatePathToCurrentStep((intptr_t)arg2);
    return;
  case 0x30:
    value3 = Person_CanContinuePath((intptr_t)arg2);
    if (value3 == 0) {
      Person_ProcessMoveEvent(arg2);
      return;
    }
  }
  return;
switchD_0040a7ba_caseD_5:
  if (*(int *)((intptr_t)arg2 + 0xa4) == 4) {
    ptr4 = (int *)RecordMap_Lookup1998(arg1,*(int *)((intptr_t)arg2 + 0x88));
    if ((ptr4 != (int *)0x0) && (0 < *ptr4)) {
      value6 = AI_StepToNeighborCell(arg1,(intptr_t)ptr4);
      if (value6 == 0) {
        NoOp_Stub();
        return;
      }
      value3 = Rating_AdjustA(value3);
      fVar8 = Game_GetRatingMultiplier((intptr_t)arg1);
      UI_SetChildScale(arg2,(double)(fVar8 * (double)value3));
      _DAT_0057c610 = Person_WalkToCellOrAbort(arg2,value6);
      return;
    }
  }
  else if (*(char *)(value3 + 0x825) == '\x01') {
    ptr4 = Map_LinkNeighbors(this_00,arg1);
    value3 = Array_GetRecord28(this_00,1,
                              (intptr_t)*(short *)(*(int *)(*(int *)((intptr_t)this_00 + 0x4c) + 8 +
                                                      *ptr4 * 0xc) + 0x24));
    if (value3 == 0) {
      NoOp_Stub();
      return;
    }
    goto LAB_0040a8c5;
  }
  value3 = Map_PickRandomType355Cell(unaff_EDI,unaff_SI);
  if (value3 == 0) {
    Object_SetState(arg2,6);
    return;
  }
LAB_0040a8c5:
  _DAT_0057c610 = Person_WalkToCellOrAbort(arg2,value3);
  return;
}
