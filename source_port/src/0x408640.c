// Object_UpdateCompanyBuilding: ported from Pizza Connection 2 at 0x408640.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x408640
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall Object_UpdateCompanyBuilding(void *self,void *arg1,void *arg2)

{
  int value1;
  uint8_t uvalue2;
  char cVar3;
  uint32_t extraout_var;
  void *this_00;
  int value4;
  int value5;
  uint32_t extraout_EDX;
  uint8_t unaff_SI;
  uint32_t unaff_EDI;
  bool flag6;
  int value7;
  
                    /* Updates a company building's completion/star/owner state. */
  uvalue2 = Object_IsVisibleThisFrame((intptr_t)arg2);
  if (CONCAT31(extraout_var,uvalue2) == 0) {
    switch(*(uint32_t *)((intptr_t)arg2 + 0x38)) {
    case 5:
      flag6 = *(int *)((intptr_t)arg2 + 0x30) == 0x12;
      value4 = AI_ComputePath(0,(uint32_t)flag6,(uint32_t)flag6,unaff_EDI,unaff_SI);
      if (value4 == 0) {
        value4 = UI_RandomChildEffect((intptr_t)arg2);
        Person_AdvanceRoute(arg2,value4);
        Object_SetState(arg2,0x14);
        return;
      }
      _DAT_0057c610 = Person_WalkToCellOrAbort(arg2,value4);
      return;
    case 6:
      value4 = Array_GetRandomRecord28(*(int *)((intptr_t)arg2 + 0xc4));
      if (value4 != 0) {
        Person_AdvanceRoute(arg2,value4);
        Object_SetState(arg2,7);
        return;
      }
      break;
    case 7:
      Object_SetFieldA4Locked(arg2,0xffffffff);
      if (*(int *)((intptr_t)arg2 + 0x30) == 10) {
        *(uint32_t *)((intptr_t)arg2 + 0x108) = 0xffffffff;
        *(uint8_t *)(*(int *)((intptr_t)arg2 + 0x10c) + 0x1880 + (intptr_t)arg1) = 0;
      }
      Person_LeaveBuildingAndReset(arg2);
      value4 = *(int *)((intptr_t)arg1 + 0x30);
      value5 = IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)self + 0x2f4),(int *)0x0);
      *(int *)(value5 + 0xce0 + value4 * 4) = *(int *)(value5 + 0xce0 + value4 * 4) + 1;
      if (*(int *)((intptr_t)arg2 + 0x30) == 0x12) {
        Person_SetAtWork((intptr_t)arg2,extraout_EDX,(intptr_t)arg1,'\x01');
        return;
      }
      break;
    case 8:
      value4 = *(int *)((intptr_t)arg2 + 0x30);
      if (value4 == 10) {
        value4 = *(int *)((intptr_t)arg2 + 0x8c);
        value5 = *(int *)((intptr_t)arg2 + 0x108);
        value7 = *(int *)((intptr_t)arg2 + 0x10c);
        value1 = *(int *)((intptr_t)arg2 + 0x88);
        this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 4),*(int *)((intptr_t)arg2 + 0x28),
                                       (int *)0x0);
        City_RecordBuildingCompletion(this_00,value7,arg1,value5,value4);
        Object_SetFrame5(arg2,0xc);
        UI_SetChildRecordVariant(arg2,value1 + 0x10);
        Object_SetState(arg2,0x1c);
        return;
      }
      if (value4 == 0x12) {
        value4 = *(int *)((intptr_t)arg2 + 0x88);
        Object_SetFrame5(arg2,0xc);
        UI_SetChildRecordVariant(arg2,value4 + 0x10);
        Object_SetState(arg2,0x1c);
        return;
      }
      if (value4 == 0x18) {
        Object_SetFrame5(arg2,5);
        UI_SetChildRecordVariant(arg2,9);
        Object_SetState(arg2,0x1c);
        return;
      }
      UI_SetChildRecordVariant(arg2,(intptr_t)arg1);
      Object_SetState(arg2,0x1c);
      return;
    default:
      Person_ResumeRouteOrDetach(arg2);
      return;
    case 0x14:
    case 0x1e:
switchD_00408676_caseD_14:
      Object_SetState(arg2,6);
      return;
    case 0x25:
      if (*(int *)((intptr_t)arg2 + 0x30) == 0x12) {
        Object_SetState(arg2,6);
        UI_SetChildState(arg2,0x1d);
        return;
      }
    }
  }
  else {
    switch(*(uint32_t *)((intptr_t)arg2 + 0x38)) {
    case 5:
      Person_ProcessMoveEvent(arg2);
      return;
    case 8:
      value4 = Person_ProcessMoveEvent(arg2);
      if (value4 == 0) {
        if (*(int *)((intptr_t)arg2 + 200) == 0) {
          *(uint32_t *)((intptr_t)arg2 + 0x88) = 0xffffffff;
          return;
        }
        *(uint32_t *)((intptr_t)arg2 + 0x88) = *(uint32_t *)(*(int *)((intptr_t)arg2 + 200) + 0xc);
        return;
      }
      break;
    case 0x1c:
      value4 = Person_ProcessMoveEvent(arg2);
      if (value4 == 0) {
        value4 = *(int *)((intptr_t)arg2 + 0x30);
        if (value4 == 10) {
          value4 = *(int *)((intptr_t)arg2 + 0x94) + -1;
          *(int *)((intptr_t)arg2 + 0x94) = value4;
          if (value4 != 0) {
            return;
          }
          Object_SetFrame5(arg2,-1);
          UI_DetachChildRecord((intptr_t)arg2);
          value4 = *(int *)((intptr_t)arg2 + 0x98) + -1;
          *(int *)((intptr_t)arg2 + 0x98) = value4;
          if (value4 == 0) goto switchD_00408676_caseD_14;
        }
        else {
          if (value4 != 0x12) {
            if (value4 != 0x18) {
              return;
            }
            value4 = *(int *)((intptr_t)arg2 + 0x94) + -1;
            *(int *)((intptr_t)arg2 + 0x94) = value4;
            if (value4 != 0) {
              return;
            }
            Object_SetFrame5(arg2,-1);
            UI_DetachChildRecord((intptr_t)arg2);
            cVar3 = Branch_StepStarRating(arg1);
            if (cVar3 == '\0') {
              Object_SetState(arg2,6);
            }
            else {
              Object_SetState(arg2,0x1e);
              UI_SetChildRecordVariant(arg2,0x19);
            }
            if (*(void **)((intptr_t)self + 0x25c) == (void *)0x0) {
              return;
            }
            UI_QueueControlCommand(*(void **)((intptr_t)self + 0x25c),-0x18614,0x23,0);
            return;
          }
          value4 = *(int *)((intptr_t)arg2 + 0x94) + -1;
          *(int *)((intptr_t)arg2 + 0x94) = value4;
          if (value4 != 0) {
            return;
          }
          Object_SetFrame5(arg2,-1);
          UI_DetachChildRecord((intptr_t)arg2);
          *(int *)((intptr_t)arg2 + 0x98) = *(int *)((intptr_t)arg2 + 0x98) + -1;
        }
        Object_SetState(arg2,5);
      }
      break;
    case 0x25:
      if (*(int *)((intptr_t)arg2 + 0x30) == 0x12) {
        Person_TruncatePathToCurrentStep((intptr_t)arg2);
        return;
      }
    }
  }
  return;
}
