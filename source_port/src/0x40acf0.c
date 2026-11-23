// Object_UpdateFallback: ported from Pizza Connection 2 at 0x40acf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x40acf0
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall Object_UpdateFallback(void *self,void *arg1,void *arg2)

{
  int *ptr1;
  void *this_00;
  uint8_t uvalue2;
  bool flag3;
  uint32_t extraout_var;
  uint32_t extraout_var_00;
  uint32_t extraout_var_01;
  uint32_t uvalue4;
  int value5;
  void *pvVar6;
  int value7;
  int local_18;
  int local_14 [5];
  
                    /* Runs fallback behavior for object types without a handler. */
  this_00 = arg2;
  local_14[1] = 2;
  local_14[2] = 3;
  local_14[3] = 0;
  local_14[4] = 1;
  uvalue2 = Object_IsVisibleThisFrame((intptr_t)arg2);
  pvVar6 = *(void **)((intptr_t)this_00 + 0xc4);
  if (CONCAT31(extraout_var,uvalue2) == 0) {
    switch(*(uint32_t *)((intptr_t)this_00 + 0x38)) {
    case 5:
      Game_IncrementVisitCounter(arg1,*(int *)((intptr_t)this_00 + 0x34));
      value5 = Building_IsSpecialType((intptr_t)this_00);
      if ((value5 != 0) &&
         (value5 = Game_CountFilteredObjects2(self,1,0x16,*(int *)((intptr_t)arg1 + 0x16f0),-1),
         value5 != 0)) {
        value5 = UI_RandomChildEffect((intptr_t)this_00);
        Person_AdvanceRoute(this_00,value5);
        Object_SetState(this_00,0x13);
        return;
      }
      uvalue2 = Game_GetHourlyValue(arg1,0x3c);
      if (CONCAT31(extraout_var_00,uvalue2) == 0) {
        value5 = UI_RandomChildEffect((intptr_t)this_00);
        Person_AdvanceRoute(this_00,value5);
        Object_SetState(this_00,0x15);
        *(short *)((intptr_t)arg1 + 0x16d8) = *(short *)((intptr_t)arg1 + 0x16d8) + 1;
        return;
      }
      flag3 = Game_IsRatingBelowThreshold(arg1,*(int *)((intptr_t)this_00 + 0x34));
      if (CONCAT31(extraout_var_01,flag3) == 0) {
        value5 = UI_RandomChildEffect((intptr_t)this_00);
        Person_AdvanceRoute(this_00,value5);
        Object_SetState(this_00,0x3d);
        *(short *)((intptr_t)arg1 + 0x16d8) = *(short *)((intptr_t)arg1 + 0x16d8) + 1;
        return;
      }
      value5 = Game_UpdatePlayerObject(this_00,local_14);
      if (value5 == 0) {
        *(short *)((intptr_t)arg1 + 0x16d6) = *(short *)((intptr_t)arg1 + 0x16d6) + 1;
        value5 = UI_RandomChildEffect((intptr_t)this_00);
        Person_AdvanceRoute(this_00,value5);
        Object_SetState(this_00,0x14);
        return;
      }
      _DAT_0057c610 = Person_WalkToCellOrAbort(this_00,value5);
      if ((_DAT_0057c610 != 0) &&
         (Sound_CheckSpeechState(DAT_0057ba0c,(intptr_t)arg1), *(int *)((intptr_t)this_00 + 0x30) == 0xb))
      {
        uvalue4 = Game_GetDateField0C((intptr_t)self);
        *(uint32_t *)((intptr_t)this_00 + 0x98) = uvalue4;
        return;
      }
      break;
    case 6:
      value5 = Array_GetRandomRecord28((intptr_t)pvVar6);
      if (value5 != 0) {
        Person_AdvanceRoute(this_00,value5);
      }
      Object_SetState(this_00,7);
      Map_DetachObjectFromTile((intptr_t)this_00);
      return;
    case 7:
      UI_SetChildState(this_00,0xffff);
      Person_LeaveBuildingAndReset(this_00);
      return;
    case 8:
      value5 = Person_ProcessMoveEvent(this_00);
      if (value5 == 0) {
        value5 = *(int *)((intptr_t)this_00 + 0x84);
        UI_ComputeCenteredRect
                  (pvVar6,(int *)(*(int *)((intptr_t)pvVar6 + 0x4c) + *(int *)((intptr_t)this_00 + 0x88) * 0xc
                                 ),&local_18,(int *)&arg2);
        ptr1 = *(int **)((intptr_t)this_00 + 200);
        if (ptr1 == (int *)0x0) {
          value7 = -1;
          pvVar6 = (void *)0x0;
        }
        else {
          value7 = *ptr1;
          pvVar6 = (void *)ptr1[0x16];
        }
        Record_SetDoubles48(pvVar6,value7,local_18 + -0xa0,(intptr_t)arg2 + -0xd0);
        UI_SetChildRecordVariant(this_00,value5 + 0x10);
        UI_SetChildState(this_00,2);
        Game_GetTimeByMode(this_00,3);
        Object_SetState(this_00,0xd);
        return;
      }
      break;
    case 9:
      Game_RemoveTrackedRecord(arg1,(intptr_t)this_00);
      value5 = local_14[*(int *)((intptr_t)this_00 + 0x84) + 1];
      UI_ComputeCenteredRect
                (pvVar6,(int *)(*(int *)((intptr_t)pvVar6 + 0x4c) + *(int *)((intptr_t)this_00 + 0x8c) * 0xc),
                 &local_18,(int *)&arg2);
      ptr1 = *(int **)((intptr_t)this_00 + 200);
      if (ptr1 == (int *)0x0) {
        value7 = -1;
        pvVar6 = (void *)0x0;
      }
      else {
        value7 = *ptr1;
        pvVar6 = (void *)ptr1[0x16];
      }
      Record_SetDoubles48(pvVar6,value7,local_18 + -0xa0,(intptr_t)arg2 + -0xd0);
      UI_SetChildRecordVariant(this_00,value5 + 8);
      UI_DetachChildRecord((intptr_t)this_00);
      Object_SetState(this_00,6);
      return;
    default:
      Person_ResumeRouteOrDetach(this_00);
      return;
    case 0x13:
      UI_SetChildState(this_00,0xc);
      Game_GetTimeByMode(this_00,7);
      Object_SetState(this_00,6);
      return;
    case 0x14:
      UI_SetChildState(this_00,0xf);
      Game_GetTimeByMode(this_00,7);
      Object_SetState(this_00,6);
      return;
    case 0x15:
      UI_SetChildState(this_00,0x23);
      Game_GetTimeByMode(this_00,7);
      Object_SetState(this_00,6);
      return;
    case 0x3d:
      UI_SetChildState(this_00,0x1f);
      Game_GetTimeByMode(this_00,7);
      Object_SetState(this_00,6);
      return;
    }
  }
  else {
    Person_ProcessMoveEvent(this_00);
  }
  return;
}
