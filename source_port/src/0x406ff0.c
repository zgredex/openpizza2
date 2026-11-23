// Object_UpdateBranchOps: ported from Pizza Connection 2 at 0x406ff0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x406ff0
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall Object_UpdateBranchOps(void *self,void *arg1,void *arg2)

{
  int *ptr1;
  void *this_00;
  uint8_t uvalue2;
  char cVar3;
  uint32_t extraout_var;
  void *pvVar4;
  int value5;
  float fVar6;
  void *pvVar7;
  uint32_t uvalue8;
  int value9;
  uint32_t uvalue10;
  int value11;
  uint32_t extraout_var_00;
  uint8_t unaff_SI;
  uint32_t unaff_EDI;
  bool flag12;
  uint64_t uvalue13;
  uint32_t local_28;
  int local_24 [9];
  
                    /* Runs the branch/site object behavior state machine. */
  this_00 = arg2;
  local_24[1] = 0x10;
  local_24[2] = 0x12;
  local_24[3] = 0x14;
  local_24[4] = 0x16;
  local_24[5] = 0x11;
  local_24[6] = 0x13;
  local_24[7] = 0x15;
  local_24[8] = 0x17;
  uvalue2 = Object_IsVisibleThisFrame((intptr_t)arg2);
  local_24[0] = CONCAT31(extraout_var,uvalue2);
  pvVar7 = *(void **)((intptr_t)this_00 + 0xc4);
  flag12 = local_24[0] == 0;
  if (((*(int *)((intptr_t)this_00 + 0x30) == 0x1d) && (*(int *)((intptr_t)this_00 + 0xa4) == 0x10)) ||
     (*(int *)((intptr_t)this_00 + 0x30) == 0x1e)) {
    pvVar4 = (void *)IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),(int *)0x0);
    City_SendPoliceToDistrictWithSiren(pvVar4,arg1);
  }
  pvVar4 = arg1;
  if (*(int *)((intptr_t)this_00 + 0x38) == 0x2d) {
    if (flag12) {
      value5 = Object_SetState(this_00,0x2e);
      *(uint32_t *)((intptr_t)self + 0x368) = 1;
      return value5;
    }
    value5 = *(int *)((intptr_t)this_00 + 0x30);
    if ((value5 != 0x17) && (value5 != 0xd)) {
      return value5;
    }
    ptr1 = *(int **)((intptr_t)this_00 + 200);
    if (ptr1 == (int *)0x0) {
      value5 = -1;
      pvVar7 = (void *)0x0;
    }
    else {
      value5 = *ptr1;
      pvVar7 = (void *)ptr1[0x16];
    }
    uvalue13 = Record_GetTwoFloats48(pvVar7,value5,local_24,&arg1);
    if ((intptr_t)arg1 < 0x15e) {
      UI_DetachChildRecord((intptr_t)this_00);
      Object_SetState(this_00,0x2e);
      *(uint32_t *)((intptr_t)self + 0x368) = 1;
      return (intptr_t)self;
    }
    return (intptr_t)uvalue13;
  }
  if (!flag12) goto LAB_004078a4;
  switch(*(int *)((intptr_t)this_00 + 0x38)) {
  case 5:
    value5 = *(int *)((intptr_t)this_00 + 0xa4);
    switch(value5) {
    default:
      goto switchD_00407151_caseD_9;
    case 0xe:
      value5 = Map_PickRandomSpawnCell(pvVar7,1);
      if (value5 == 0) {
        Object_SetState(this_00,6);
      }
      else {
LAB_00407216:
        Person_AdvanceRoute(this_00,value5);
        Object_SetState(this_00,8);
      }
      break;
    case 0xf:
      value5 = Person_ProcessMoveEvent(this_00);
      if (value5 != 0) {
        return value5;
      }
      value5 = AI_ChooseWalkTarget(pvVar7,(intptr_t)this_00,arg1,&local_28,&arg2);
      if (value5 == 0) goto LAB_004077e2;
      _DAT_0057c610 = Person_WalkToCellOrAbort(this_00,value5);
      if (_DAT_0057c610 != 0) {
        *(uint32_t *)((intptr_t)this_00 + 0x8c) = local_28;
        *(int *)((intptr_t)this_00 + 0x88) = local_24[(intptr_t)arg2 + 1];
      }
      break;
    case 0x10:
    case 0x19:
    case 0x1a:
      if ((value5 == 0x1a) && (uvalue8 = Random_RangeFast(1,100), (intptr_t)uvalue8 < 5)) {
        Map_PickRandomSpawnCell(pvVar7,1);
      }
      else {
        AI_ComputePath(0,0,0,unaff_EDI,unaff_SI);
      }
LAB_004072d7:
      value5 = AI_ComputePath(0,0,0,unaff_EDI,unaff_SI);
      if (value5 == 0) {
        Object_AbortOrderAndReturnHome(this_00);
        Object_SetState(this_00,6);
      }
      else {
LAB_00407499:
        _DAT_0057c610 = Person_WalkToCellOrAbort(this_00,value5);
      }
      break;
    case 0x12:
      *(uint32_t *)((intptr_t)this_00 + 0x84) = 0xffffffff;
      *(uint32_t *)((intptr_t)this_00 + 0x8c) = 0xffffffff;
      uvalue8 = Random_RangeFast(1,100);
      if ((intptr_t)uvalue8 < 5) {
        value5 = Map_PickRandomSpawnCell(pvVar7,1);
      }
      else {
        value5 = AI_ComputePath(0,0,0,unaff_EDI,unaff_SI);
      }
      if (value5 != 0) goto LAB_00407499;
      Object_AbortOrderAndReturnHome(this_00);
      Object_SetState(this_00,6);
      break;
    case 0x16:
    case 0x17:
      value5 = Game_CountGoalTargets(arg1,value5);
      if (value5 != 0) {
        *(uint32_t *)((intptr_t)this_00 + 0x84) = 0xffffffff;
        *(uint32_t *)((intptr_t)this_00 + 0x8c) = 0xffffffff;
        goto LAB_004072d7;
      }
LAB_004072a7:
      value5 = UI_RandomChildEffect((intptr_t)this_00);
      Person_AdvanceRoute(this_00,value5);
      Object_SetState(this_00,0x36);
      Game_UpdateBuildingStates((intptr_t)this_00);
      break;
    case 0x1b:
      value5 = Game_CountGoalTargets(arg1,value5);
      if ((value5 == 0) && (value5 = Game_ComputeRecordMapPercent((intptr_t)pvVar4), value5 == 0))
      goto LAB_004072a7;
LAB_00407280:
      *(uint32_t *)((intptr_t)this_00 + 0x84) = 0xffffffff;
      *(uint32_t *)((intptr_t)this_00 + 0x8c) = 0xffffffff;
      Person_ChooseWanderTarget(this_00,pvVar4);
      break;
    case 0x1c:
      value5 = Person_ProcessMoveEvent(this_00);
      if (value5 != 0) {
        return value5;
      }
      value5 = IDMap_Lookup((void *)((intptr_t)self + 0x3c),*(int *)((intptr_t)this_00 + 0xac),(int *)0x0);
      if ((((value5 == 0) || (*(int *)(value5 + 0x74) == 0)) ||
          (*(int *)(value5 + 0xf4) != *(int *)((intptr_t)arg1 + 0x16f0))) ||
         (value5 = Person_FindFreeNeighborCell
                            (this_00,arg1,*(int *)((intptr_t)this_00 + 0xac),&arg2), value5 == 0)) {
LAB_00407201:
        Object_AbortOrderAndReturnHome(this_00);
        goto switchD_00407151_caseD_36;
      }
      Person_AdvanceRoute(this_00,value5);
      _DAT_0057c610 = Person_WalkToCellOrAbort(this_00,value5);
      if (_DAT_0057c610 != 0) {
        *(int *)((intptr_t)this_00 + 0x88) = local_24[(intptr_t)arg2 + 1];
      }
      break;
    case -1:
      if (*(int *)((intptr_t)this_00 + 0x30) != 0x17) goto switchD_00407151_caseD_9;
      Object_SetFieldA4Locked(this_00,0x12);
    }
    break;
  case 6:
    value5 = Array_GetRandomRecord28((intptr_t)pvVar7);
    if (value5 != 0) {
      Person_AdvanceRoute(this_00,value5);
      Object_SetState(this_00,7);
    }
    break;
  case 7:
    value5 = *(int *)((intptr_t)this_00 + 0x164);
    value11 = *(int *)((intptr_t)this_00 + 0x110);
    value9 = Game_GetCurrentPlayerCompanyName(DAT_0057c670);
    if (value11 == value9) {
      MissionGoal_HandleEvent(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),8,value5,-1);
    }
    Person_LeaveBuildingAndReset(this_00);
    Object_SetFieldA4Locked(this_00,0xffffffff);
    break;
  case 8:
    switch(*(uint32_t *)((intptr_t)this_00 + 0xa4)) {
    default:
      goto switchD_00407151_caseD_9;
    case 0xe:
      value5 = Person_TryDeliverCustomerOrder(this_00,arg1);
      if (value5 == 0) {
        value5 = Object_GetChildField2C((intptr_t)this_00);
        UI_SetChildRecordVariant(this_00,value5 + 0x18);
        Object_SetState(this_00,10);
        Object_SetFrame5(this_00,10);
      }
      else {
        Object_SetState(this_00,6);
      }
      break;
    case 0xf:
      value5 = Game_FindRecordByField20(arg1,*(int *)((intptr_t)this_00 + 0x8c));
      if ((value5 == 0) || (*(int *)(value5 + 0xc) < 1)) {
LAB_0040716c:
        Object_SetState(this_00,5);
      }
      else {
        UI_SetChildRecordVariant(this_00,*(int *)((intptr_t)this_00 + 0x88));
        Object_SetState(this_00,0x27);
      }
      break;
    case 0x10:
      value5 = Game_UpdateFreeBuildingCount((intptr_t)arg1);
      if (value5 != 0) goto LAB_0040716c;
      uvalue8 = Random_RangeFast(0x30,0x37);
      value5 = Object_GetChildField2C((intptr_t)this_00);
      Object_SetState(this_00,0x26);
      UI_SetChildRecordVariant(this_00,uvalue8 + value5);
      break;
    case 0x19:
    case 0x1a:
      value5 = Object_GetChildField2C((intptr_t)this_00);
      UI_SetChildRecordVariant(this_00,value5 + 0x18);
      value5 = 0x3e;
      goto LAB_00407681;
    case 0x1b:
      value5 = Game_CountGoalTargets(arg1,0x1b);
      if ((value5 == 0) && (*(int *)((intptr_t)this_00 + 0x8c) != -1)) {
        Branch_PayConstructionOrder(pvVar4,*(int *)((intptr_t)this_00 + 0x8c));
      }
    case 0x16:
    case 0x17:
      value5 = Object_GetChildField2C((intptr_t)this_00);
LAB_00407678:
      UI_SetChildRecordVariant(this_00,value5 + 0x18);
      value5 = 0x29;
LAB_00407681:
      Object_SetState(this_00,value5);
      Object_SetFrame5(this_00,1);
      break;
    case 0x1c:
      value5 = Person_ProcessMoveEvent(this_00);
      if (value5 != 0) {
        return value5;
      }
      fVar6 = (float)IDMap_Lookup((void *)((intptr_t)self + 0x3c),*(int *)((intptr_t)this_00 + 0xac),
                                  (int *)0x0);
      if (((fVar6 == 0.0) || (*(int *)((intptr_t)fVar6 + 0x74) == 0)) ||
         (*(int *)((intptr_t)arg1 + 0x16f0) != *(int *)((intptr_t)fVar6 + 0xf4))) goto LAB_0040775c;
      pvVar7 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x20),*(int *)((intptr_t)fVar6 + 0x50),
                                    (int *)0x0);
      value5 = *(int *)((intptr_t)pvVar7 + 0x10) / 2;
      if (value5 < 1) {
        value5 = 1;
      }
      Person_SetHealth(pvVar7,value5);
      fVar6 = Game_ComputeObjectValue(this_00,fVar6);
      UI_SetChildRecordVariant(this_00,(intptr_t)fVar6);
      Object_SetState(this_00,0x3f);
      break;
    case 0xffffffff:
    case 0x12:
      value5 = *(int *)((intptr_t)this_00 + 0x88);
      goto LAB_00407678;
    }
    break;
  case 0x26:
    Branch_InitCityObjects(arg1,0x1e);
LAB_004077e2:
    Object_SetState(this_00,6);
    Object_AbortOrderAndReturnHome(this_00);
    break;
  case 0x27:
    value5 = Person_ProcessMoveEvent(this_00);
    pvVar7 = arg1;
    if (value5 != 0) {
      return value5;
    }
    Branch_InitCityObjects(arg1,0x1e);
    value5 = Game_GetPlayerEconomyModifier((intptr_t)this_00);
    pvVar4 = (void *)Game_FindRecordByField20(pvVar7,*(int *)((intptr_t)this_00 + 0x8c));
    if (pvVar4 != (void *)0x0) {
      value11 = *(int *)((intptr_t)pvVar4 + 0xc);
      if (value5 < value11) {
        Game_SetModeByte(pvVar4,CONCAT31((int3)((uint32_t)value11 >> 8),(char)value11 - (char)value5));
        UI_SetChildRecordVariant(this_00,*(int *)((intptr_t)this_00 + 0x88));
        value5 = Sound_HandleEvent(DAT_0057ba0c,(intptr_t)pvVar7,0x24);
        return value5;
      }
      Game_SetModeByte(pvVar4,0);
      Game_ApplyOwnerWideObjectEvent(pvVar7,(intptr_t)pvVar4);
      Game_UpdateObject(pvVar4,pvVar7);
      cVar3 = Game_GetPlayerByte8((intptr_t)pvVar4);
      if (cVar3 == '\x01') {
        value5 = 0x1d;
      }
      else {
        value5 = 0x1e;
      }
      Sound_HandleEvent(DAT_0057ba0c,(intptr_t)pvVar7,value5);
    }
    Object_SetState(this_00,5);
    break;
  case 0x28:
    value5 = *(int *)((intptr_t)this_00 + 0x30);
    if (value5 == 0xd) {
      value5 = Person_SelectFacingTarget(this_00,arg1);
    }
    else {
      if ((value5 != 0x17) && (value5 != 0x1d)) break;
      value5 = Person_SelectTargetInFacingArc(this_00,arg1);
    }
    if (value5 == -1) {
      Object_SetState(this_00,0x2f);
    }
    break;
  case 0x2a:
    if (*(int *)((intptr_t)this_00 + 0x30) == 0x1e) {
      UI_SetChildRecordVariant(this_00,*(int *)((intptr_t)this_00 + 0x88) + 0x20);
      Object_SetFrame5(this_00,1);
      Object_SetState(this_00,0x2b);
    }
    break;
  case 0x2c:
    value5 = Person_ProcessMoveEvent(this_00);
    if (value5 != 0) {
      return value5;
    }
    Person_UpdateSocialEncounter(this_00,(intptr_t)arg1);
    break;
  case 0x2f:
    if (*(int *)((intptr_t)this_00 + 0x30) != 0xd) goto LAB_0040716c;
    Object_SetState(this_00,0x37);
    break;
  case 0x36:
switchD_00407151_caseD_36:
    Object_SetState(this_00,6);
    break;
  case 0x37:
    value5 = *(int *)((intptr_t)this_00 + 0xa4);
    if (0x15 < value5) {
      if (value5 < 0x18) {
        value5 = Game_CountGoalTargets(arg1,value5);
        if (value5 == 0) {
LAB_004071ca:
          Object_SetState(this_00,6);
          value5 = Game_UpdateBuildingStates((intptr_t)this_00);
          return value5;
        }
        *(uint32_t *)((intptr_t)this_00 + 0x84) = 0xffffffff;
        *(uint32_t *)((intptr_t)this_00 + 0x8c) = 0xffffffff;
        value5 = AI_ComputePath(0,0,0,unaff_EDI,unaff_SI);
        if (value5 == 0) goto LAB_00407201;
        goto LAB_00407216;
      }
      if (value5 == 0x1b) {
        value5 = Game_CountGoalTargets(arg1,0x1b);
        if ((value5 == 0) && (value5 = Game_ComputeRecordMapPercent((intptr_t)pvVar4), value5 == 0))
        goto LAB_004071ca;
        goto LAB_00407280;
      }
    }
  default:
switchD_00407151_caseD_9:
    Person_ResumeRouteOrDetach(this_00);
    break;
  case 0x38:
    UI_SetChildRecordVariant(this_00,*(int *)((intptr_t)this_00 + 0x88) + 0x20);
    break;
  case 0x3f:
    value5 = Person_ProcessMoveEvent(this_00);
    if (value5 != 0) {
      return value5;
    }
LAB_0040775c:
    Object_AbortOrderAndReturnHome(this_00);
    *(uint8_t *)((intptr_t)this_00 + 0x81) = 1;
  }
LAB_004078a4:
  if (local_24[0] == 0) {
    return 0;
  }
  value5 = *(int *)((intptr_t)this_00 + 0x38) + -8;
  switch(*(int *)((intptr_t)this_00 + 0x38)) {
  case 8:
    value5 = Person_ProcessMoveEvent(this_00);
    if (value5 == 0) {
      value5 = *(int *)((intptr_t)this_00 + 0x30) + -0xd;
      switch(*(int *)((intptr_t)this_00 + 0x30)) {
      case 0xd:
        if (*(int *)((intptr_t)this_00 + 200) == 0) {
          uvalue10 = 0xffffffff;
        }
        else {
          uvalue10 = *(uint32_t *)(*(int *)((intptr_t)this_00 + 200) + 0xc);
        }
        *(uint32_t *)((intptr_t)this_00 + 0x88) = uvalue10;
LAB_00407b87:
        value5 = Person_SelectFacingTarget(this_00,arg1);
        return value5;
      case 0x17:
        if (*(int *)((intptr_t)this_00 + 200) == 0) {
          uvalue10 = 0xffffffff;
        }
        else {
          uvalue10 = *(uint32_t *)(*(int *)((intptr_t)this_00 + 200) + 0xc);
        }
        *(uint32_t *)((intptr_t)this_00 + 0x88) = uvalue10;
        value5 = Person_SelectTargetInFacingArc(this_00,arg1);
        return value5;
      case 0x1d:
        value11 = *(int *)((intptr_t)this_00 + 0xa4);
        if (value11 == 0xe) {
          if (*(int *)((intptr_t)this_00 + 200) == 0) {
            uvalue10 = 0xffffffff;
          }
          else {
            uvalue10 = *(uint32_t *)(*(int *)((intptr_t)this_00 + 200) + 0xc);
          }
          *(uint32_t *)((intptr_t)this_00 + 0x88) = uvalue10;
          value11 = Person_TryDeliverCustomerOrder(this_00,arg1);
          value5 = 0;
          if (value11 != 0) {
            Person_TruncatePathToCurrentStep((intptr_t)this_00);
            value5 = Object_SetState(this_00,6);
            return value5;
          }
        }
        else {
          if (value11 == 0x19) {
            if (*(int *)((intptr_t)this_00 + 200) == 0) {
              uvalue10 = 0xffffffff;
            }
            else {
              uvalue10 = *(uint32_t *)(*(int *)((intptr_t)this_00 + 200) + 0xc);
            }
            *(uint32_t *)((intptr_t)this_00 + 0x88) = uvalue10;
            value5 = Person_SelectTargetInFacingArc(this_00,arg1);
            return value5;
          }
          value5 = 0;
          if (value11 != 0x1a) {
            value5 = Object_LinkWithFacingObject(this_00,arg1);
            return value5;
          }
        }
        break;
      case 0x1e:
        if (*(int *)((intptr_t)this_00 + 0xa4) == 0x1c) {
          value5 = IDMap_Lookup((void *)((intptr_t)self + 0x3c),*(int *)((intptr_t)this_00 + 0xac),(int *)0x0);
          pvVar7 = arg1;
          if (((value5 != 0) && (*(int *)(value5 + 0x74) != 0)) &&
             (*(int *)(value5 + 0xf4) == *(int *)((intptr_t)arg1 + 0x16f0))) {
            value5 = Object_IsWithinServiceRange(this_00,arg1,*(int *)((intptr_t)this_00 + 0xac));
            if (value5 != 0) {
              value5 = Person_TruncatePathToCurrentStep((intptr_t)this_00);
              return value5;
            }
            value5 = Person_FindFreeNeighborCell
                              (this_00,pvVar7,*(int *)((intptr_t)this_00 + 0xac),&arg2);
            if (value5 != 0) {
              *(int *)((intptr_t)this_00 + 0x88) = local_24[(intptr_t)arg2 + 1];
              value5 = Person_AdvanceRoute(this_00,value5);
              return value5;
            }
          }
          Object_AbortOrderAndReturnHome(this_00);
          value5 = Object_SetState(this_00,6);
          return value5;
        }
      }
    }
    break;
  case 10:
    value5 = Person_ProcessMoveEvent(this_00);
    pvVar7 = arg1;
    if (value5 != 0) {
      return value5;
    }
    flag12 = Object_IsCompanySiteChanged(this_00,(intptr_t)arg1);
    if (CONCAT31(extraout_var_00,flag12) != 0) {
      value5 = Object_AbortOrderAndReturnHome(this_00);
      *(uint8_t *)((intptr_t)this_00 + 0x81) = 1;
      return value5;
    }
    value5 = Person_TryDeliverCustomerOrder(this_00,pvVar7);
    if (value5 != 0) {
      UI_DetachChildRecord((intptr_t)this_00);
      value5 = Object_SetState(this_00,6);
      return value5;
    }
    goto LAB_00407c1b;
  case 0x28:
    value5 = Person_ProcessMoveEvent(this_00);
    if (value5 == 0) {
      value5 = *(int *)((intptr_t)this_00 + 0x30);
      if (value5 == 0xd) goto LAB_00407b87;
      if ((value5 == 0x17) || (value5 == 0x1d)) {
        value5 = Person_SelectTargetInFacingArc(this_00,arg1);
        return value5;
      }
    }
    break;
  case 0x29:
    value5 = Person_ProcessMoveEvent(this_00);
    if (value5 != 0) {
      return value5;
    }
    value5 = *(int *)((intptr_t)this_00 + 0x30);
    if (value5 == 0xd) {
      value5 = Person_SelectFacingTarget(this_00,arg1);
      if (value5 == -1) {
        value5 = *(int *)((intptr_t)this_00 + 0x94) + -1;
        *(int *)((intptr_t)this_00 + 0x94) = value5;
        if (value5 == 0) {
          Object_SetFrame5(this_00,-1);
          UI_DetachChildRecord((intptr_t)this_00);
          value5 = Object_SetState(this_00,0x37);
          return value5;
        }
        return value5;
      }
    }
    else {
      if (value5 != 0x17) {
        return value5;
      }
LAB_00407c7c:
      value5 = Person_SelectTargetInFacingArc(this_00,arg1);
      if (value5 == -1) {
        value5 = *(int *)((intptr_t)this_00 + 0x94) + -1;
        *(int *)((intptr_t)this_00 + 0x94) = value5;
        if (value5 == 0) {
          Object_SetFrame5(this_00,-1);
          UI_DetachChildRecord((intptr_t)this_00);
          value5 = Object_SetState(this_00,5);
          return value5;
        }
        return value5;
      }
    }
    value5 = Object_SetFrame5(this_00,-1);
    break;
  case 0x2b:
    value5 = Person_ProcessMoveEvent(this_00);
    if (value5 == 0) {
      value5 = *(int *)((intptr_t)this_00 + 0x94) + -1;
      *(int *)((intptr_t)this_00 + 0x94) = value5;
      if (value5 == 0) {
        UI_DetachChildRecord((intptr_t)this_00);
        Object_SetFrame5(this_00,-1);
        *(uint8_t *)((intptr_t)this_00 + 0x81) = 1;
        value5 = Person_ProcessMoveEvent(this_00);
        return value5;
      }
    }
    break;
  case 0x2c:
    value5 = Person_ProcessMoveEvent(this_00);
    if (value5 == 0) {
      value5 = Person_UpdateSocialEncounter(this_00,(intptr_t)arg1);
      return value5;
    }
    break;
  case 0x2f:
    Person_TruncatePathToCurrentStep((intptr_t)this_00);
    if (*(int *)((intptr_t)this_00 + 0x30) == 0xd) {
      value5 = Object_SetState(this_00,0x37);
      return value5;
    }
    goto LAB_00407c3d;
  case 0x39:
    UI_DetachChildRecord((intptr_t)this_00);
    Object_SetChildField2C(this_00,0x28);
    value5 = Object_SetState(this_00,6);
    return value5;
  case 0x3e:
    value5 = Person_ProcessMoveEvent(this_00);
    if (value5 != 0) {
      return value5;
    }
    if (*(int *)((intptr_t)this_00 + 0xa4) == 0x19) goto LAB_00407c7c;
    value5 = *(int *)((intptr_t)this_00 + 0xa4) + -0x1a;
    if (value5 != 0) {
      return value5;
    }
LAB_00407c1b:
    value5 = *(int *)((intptr_t)this_00 + 0x94) + -1;
    *(int *)((intptr_t)this_00 + 0x94) = value5;
    if (value5 == 0) {
      Object_SetFrame5(this_00,-1);
      UI_DetachChildRecord((intptr_t)this_00);
LAB_00407c3d:
      value5 = Object_SetState(this_00,5);
      return value5;
    }
  }
  return value5;
}
