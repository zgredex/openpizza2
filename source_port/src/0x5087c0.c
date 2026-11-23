// Person_LeaveBuildingAndReset: ported from Pizza Connection 2 at 0x5087c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5087c0
#include "pc2_port.h"

void __fastcall Person_LeaveBuildingAndReset(void *arg1)

{
  void *pvVar1;
  int value2;
  void *self;
  void *this_00;
  uint32_t extraout_EDX;
  uint32_t extraout_EDX_00;
  uint32_t uvalue3;
  
                    /* Unlinks a person from its building and restores idle state. */
  pvVar1 = (void *)Game_GetPlayerSubmapValue
                             (DAT_0057c670,*(int *)(*(int *)((intptr_t)arg1 + 0xf4) + 8),
                              *(int *)(*(int *)((intptr_t)arg1 + 0xf4) + 0x2c));
  *(uint32_t *)((intptr_t)arg1 + 0x74) = 0;
  Game_RemoveObjectFromList(*(void **)((intptr_t)arg1 + 0xf4),arg1,0);
  Object_SetFlag104(arg1,0);
  Sound_CheckSpeechState(DAT_0057ba0c,(intptr_t)pvVar1);
  UI_SetChildState(arg1,0xffff);
  Game_GetTimeByMode(arg1,0);
  *(uint32_t *)((intptr_t)arg1 + 0x4c) = 0;
  *(uint32_t *)((intptr_t)arg1 + 0x54) = 0;
  Object_SetState(arg1,2);
  UI_ShiftChildRect((intptr_t)arg1);
  value2 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),
                       *(int *)(*(int *)((intptr_t)arg1 + 0xf4) + 0x28),(int *)0x0);
  Object_RebindRenderList(arg1,0,*(uint32_t *)(value2 + 0xfa8));
  self = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)arg1 + 0x28),
                              (int *)0x0);
  value2 = State_IsMenuState((intptr_t)arg1);
  if (value2 != 0) {
    Object_SetChildShort((intptr_t)arg1);
  }
  switch(*(uint32_t *)((intptr_t)arg1 + 0x30)) {
  case 10:
    value2 = *(int *)((intptr_t)arg1 + 0x10c);
    if (value2 == 0) {
      UI_SetChildState(arg1,0x17);
    }
    else if (value2 == 1) {
      UI_SetChildState(arg1,0x18);
    }
    else if (value2 == 2) {
      UI_SetChildState(arg1,0x19);
    }
    break;
  case 0xd:
    value2 = Object_GetClampedLevel((intptr_t)arg1);
    goto LAB_005088dd;
  case 0x20:
    Game_HideBuildingOverlay(pvVar1,1);
  case 0x17:
  case 0x1d:
    value2 = -1;
LAB_005088dd:
    Object_GetPlayerValue(arg1,value2);
  }
  value2 = *(int *)((intptr_t)arg1 + 0x108);
  if (value2 == 10) {
    Person_SetRandomResidentialTarget(arg1);
    *(uint32_t *)((intptr_t)arg1 + 0xf4) = 0;
    return;
  }
  if (value2 != 6) {
    if (value2 == 1) {
      if (*(int *)((intptr_t)arg1 + 0x30) == 0x14) {
        List_Node_Reset((intptr_t)arg1 + 0x114);
        Object_ClearAssignedRecord(arg1,pvVar1);
        Object_SetChildField2C(arg1,0);
      }
      value2 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x3c),*(int *)((intptr_t)arg1 + 0x10c),
                           (int *)0x0);
      value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(value2 + 0x110));
      Object_SetDestinationAndTarget(arg1,2,*(int *)(value2 + 0x1d8));
      UI_SetChildState(arg1,0x1d);
      *(uint32_t *)((intptr_t)arg1 + 0xf4) = 0;
      return;
    }
    if ((*(char *)((intptr_t)arg1 + 0x80) == '\0') && (*(char *)((intptr_t)arg1 + 0x81) == '\0')) {
      switch(*(uint32_t *)((intptr_t)arg1 + 0x30)) {
      default:
        Person_ReturnToHomeBase(arg1);
        *(uint32_t *)((intptr_t)arg1 + 0xf4) = 0;
        return;
      case 0x14:
        goto switchD_005089e3_caseD_14;
      }
    }
    if (*(int *)((intptr_t)arg1 + 0x30) == 0x14) {
      List_Node_Reset((intptr_t)arg1 + 0x114);
      Person_SetAtWork((intptr_t)arg1,extraout_EDX_00,(intptr_t)pvVar1,'\x01');
    }
    if (*(int *)((intptr_t)arg1 + 0xa4) == 0x13) {
      value2 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                           (int *)0x0);
      value2 = IDMap_Lookup((void *)(value2 + 0xfac),0x22,(int *)0x0);
      uvalue3 = 7;
    }
    else {
      if (*(int *)((intptr_t)arg1 + 0xa0) != 0) {
        Object_SetDestinationAndTarget
                  (arg1,6,*(int *)((intptr_t)arg1 + *(int *)((intptr_t)arg1 + 0x3c) * 4 + 0xd4));
        uvalue3 = *(uint32_t *)((intptr_t)arg1 + *(int *)((intptr_t)arg1 + 0x3c) * 4 + 0xd4);
        *(uint8_t *)((intptr_t)arg1 + 0x81) = 0;
        *(uint32_t *)((intptr_t)arg1 + 0xd0) = uvalue3;
        *(uint32_t *)((intptr_t)arg1 + 0xf4) = 0;
        return;
      }
      value2 = *(int *)((intptr_t)arg1 + 0xcc);
      uvalue3 = 3;
    }
    Object_SetDestinationAndTarget(arg1,uvalue3,value2);
    *(uint8_t *)((intptr_t)arg1 + 0x81) = 0;
LAB_00508bb6:
    *(uint32_t *)((intptr_t)arg1 + 0xf4) = 0;
    return;
  }
  value2 = *(int *)((intptr_t)arg1 + 0x30);
  if (value2 == 0x16) {
    uvalue3 = 0x10;
  }
  else if (value2 == 0x1e) {
    uvalue3 = 0x28;
  }
  else {
    if (value2 != 0x1f) goto LAB_00508927;
    uvalue3 = 0x20;
  }
  Object_SetChildField2C(arg1,uvalue3);
LAB_00508927:
  Object_SetDestinationAndTarget(arg1,3,*(int *)((intptr_t)arg1 + 0xcc));
  *(uint32_t *)((intptr_t)arg1 + 0xf4) = 0;
  return;
switchD_005089e3_caseD_14:
  if (*(int *)((intptr_t)arg1 + 0xa4) == 4) {
    value2 = Object_ClearAssignedRecord(arg1,pvVar1);
    if (value2 != 0) {
      Object_SetChildField2C(arg1,0);
      Person_SetAtWork((intptr_t)arg1,extraout_EDX,(intptr_t)pvVar1,'\x01');
      Object_SetDestinationAndTarget(arg1,3,*(int *)((intptr_t)arg1 + 0xcc));
      *(uint32_t *)((intptr_t)arg1 + 0xf4) = 0;
      return;
    }
    Object_SetChildField2C(arg1,0x30);
    this_00 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)pvVar1 + 0x30));
    if ((this_00 == (void *)0x0) ||
       (pvVar1 = Player_FindRecordByCityId(this_00,(intptr_t)pvVar1), pvVar1 == (void *)0x0)) {
      value2 = Game_FindNearestTransportBuilding(self,*(int *)((intptr_t)arg1 + 0xf4));
      Object_SetDestinationAndTarget(arg1,4,value2);
      *(uint32_t *)((intptr_t)arg1 + 0xf4) = 0;
      return;
    }
    Object_SetDestinationAndTarget(arg1,4,*(int *)((intptr_t)pvVar1 + 0x34));
    *(uint32_t *)((intptr_t)arg1 + 0xf4) = 0;
    return;
  }
  if (*(int *)((intptr_t)arg1 + 0xa4) == 8) {
    Object_SetChildField2C(arg1,0x30);
    value2 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x3c),*(int *)((intptr_t)arg1 + 0x10c),
                         (int *)0x0);
    if ((((value2 == 0) || (*(int *)(value2 + 0x38) != 0x1a)) || (*(char *)(value2 + 0x104) == '\0'))
       || (*(int *)(value2 + 0xfc) == 0)) {
      Object_SetDestinationAndTarget(arg1,1,*(int *)((intptr_t)pvVar1 + 0x16f0));
      *(uint32_t *)((intptr_t)arg1 + 0xf4) = 0;
      return;
    }
    Object_SetDestinationAndTarget(arg1,8,*(int *)(value2 + 0xfc));
    *(uint32_t *)((intptr_t)arg1 + 0xf4) = 0;
    return;
  }
  goto LAB_00508bb6;
}
