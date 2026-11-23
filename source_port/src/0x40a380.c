// Object_UpdateProductionWorker: ported from Pizza Connection 2 at 0x40a380.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x40a380
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall Object_UpdateProductionWorker(void *self,void *arg1,void *arg2)

{
  void *pvVar1;
  uint8_t uvalue2;
  int value3;
  uint32_t extraout_var;
  int *ptr4;
  int value5;
  void *this_00;
  uint32_t extraout_EDX;
  uint32_t unaff_EDI;
  double fVar6;
  int64_t lvalue7;
  
                    /* Updates a production worker's ingredients and work timer. */
  *(short *)((intptr_t)arg1 + 0x16e4) = *(short *)((intptr_t)arg1 + 0x16e4) + 1;
  value3 = IDMap_Lookup((void *)((intptr_t)self + 0x20),*(int *)((intptr_t)arg2 + 0x50),(int *)0x0);
  uvalue2 = Object_IsVisibleThisFrame((intptr_t)arg2);
  pvVar1 = *(void **)((intptr_t)arg2 + 0xc4);
  if (CONCAT31(extraout_var,uvalue2) == 0) {
    switch(*(uint32_t *)((intptr_t)arg2 + 0x38)) {
    case 5:
      ptr4 = Map_LinkNeighbors(pvVar1,arg1);
      value5 = Array_GetRecord28(pvVar1,1,(intptr_t)*(short *)(*(int *)(*(int *)((intptr_t)pvVar1 + 0x4c) + 8 +
                                                                 *ptr4 * 0xc) + 0x24));
      if (value5 == 0) {
        Object_SetState(arg2,6);
        return;
      }
      value3 = Rating_AdjustA(value3);
      fVar6 = Game_GetRatingMultiplier((intptr_t)arg1);
      UI_SetChildScale(arg2,(double)(fVar6 * (double)value3));
      _DAT_0057c610 = Person_WalkToCellOrAbort(arg2,value5);
      if (_DAT_0057c610 != 0) {
        *(int *)((intptr_t)arg2 + 0x88) = *ptr4;
        Object_SetState(arg2,8);
        return;
      }
      break;
    case 6:
      value3 = Array_GetRandomRecord28((intptr_t)pvVar1);
      if (value3 != 0) {
        Person_AdvanceRoute(arg2,value3);
        Object_SetState(arg2,7);
        return;
      }
      break;
    case 7:
      Person_LeaveBuildingAndReset(arg2);
      Person_SetAtWork((intptr_t)arg2,extraout_EDX,(intptr_t)arg1,'\x01');
      return;
    case 8:
switchD_0040a3d6_caseD_8:
      UI_SetChildRecordVariant(arg2,0x12);
      Object_SetState(arg2,10);
      break;
    default:
      Person_ResumeRouteOrDetach(arg2);
      return;
    case 0x25:
      Object_SetState(arg2,6);
      UI_SetChildState(arg2,0x1d);
      return;
    }
  }
  else {
    switch(*(uint32_t *)((intptr_t)arg2 + 0x38)) {
    case 8:
      Person_ProcessMoveEvent(arg2);
      return;
    case 10:
      value5 = Person_ProcessMoveEvent(arg2);
      if (value5 == 0) {
        if (*(int *)((intptr_t)arg1 + 0x173c) < 1) {
          *(short *)((intptr_t)arg1 + 0x16dc) = *(short *)((intptr_t)arg1 + 0x16dc) + 1;
          return;
        }
        pvVar1 = (void *)((intptr_t)arg1 + 0x1728);
        value5 = IDMap_Lookup(pvVar1,0,(int *)0x0);
        this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x3c),value5,(int *)0x0);
        if (this_00 == (void *)0x0) {
          IDMap_RemoveRecursive(pvVar1,0);
          return;
        }
        if (((*(int *)((intptr_t)this_00 + 0xc4) == *(int *)((intptr_t)arg1 + 0x14e0)) &&
            (*(int *)((intptr_t)this_00 + 0x38) == 0xb)) || (*(int *)((intptr_t)this_00 + 0x38) == 0x1a)) {
          if (*(int *)((intptr_t)arg1 + 0x1a24) != 0) {
            return;
          }
          value5 = Action_AddBestRecipeToBranchMenu(this_00,*(int *)((intptr_t)arg1 + 0x16f0));
          if (value5 == 0) {
            UI_SetChildState(arg2,10);
            Game_GetTimeByMode(arg2,7);
            DebugConsole_Printf(DAT_0057c1e0,0xff,(uint8_t *)s_Keine_Zutaten_00563cc0,unaff_EDI);
            *(uint32_t *)((intptr_t)arg1 + 0x1a24) = 1;
            return;
          }
          Branch_ComputeWorkDuration(arg1,value3);
          lvalue7 = __ftol();
          Object_SetFrame5(arg2,(intptr_t)lvalue7);
          Object_SetState(arg2,0xe);
          Sound_HandleEvent(DAT_0057ba0c,(intptr_t)arg1,0x32);
          *(uint32_t *)((intptr_t)arg2 + 0x10c) = *(uint32_t *)((intptr_t)this_00 + 0x164);
          UI_SetChildRecordVariant(arg2,10);
          UI_SetChildState(arg2,0xffff);
        }
        IDMap_RemoveRecursive(pvVar1,0);
        return;
      }
      break;
    case 0xe:
      value3 = *(int *)((intptr_t)arg2 + 0x94) + -1;
      *(int *)((intptr_t)arg2 + 0x94) = value3;
      if (value3 != 0) {
        return;
      }
      Object_SetFrame5(arg2,-1);
      value3 = IDMap_Lookup((void *)((intptr_t)self + 0x3c),*(int *)((intptr_t)arg2 + 0x10c),(int *)0x0);
      if (*(int *)(value3 + 0x38) == 0xb) {
        Screen_AddRecordToList(arg1,value3);
      }
      else if (*(int *)(value3 + 0x38) == 0x1a) {
        Game_QueueObjectTask(arg1,value3);
      }
      goto switchD_0040a3d6_caseD_8;
    case 0x25:
      Person_TruncatePathToCurrentStep((intptr_t)arg2);
      return;
    }
  }
  return;
}
