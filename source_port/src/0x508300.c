// Object_ActionActivate: ported from Pizza Connection 2 at 0x508300.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x508300
#include "pc2_port.h"

void __fastcall Object_ActionActivate(void *arg1,uint32_t arg2)

{
  bool flag1;
  uint32_t extraout_var;
  int value2;
  int value3;
  int *ptr4;
  uint32_t extraout_EDX;
  uint32_t extraout_EDX_00;
  int *ptr5;
  uint16_t uvalue6;
  void *local_4;
  
                    /* Activates an object, rebinds its render list, and updates counters. */
  local_4 = (void *)0x0;
  value2 = *(int *)((intptr_t)arg1 + 0xf4);
  if (value2 != 0) {
    local_4 = (void *)Game_GetPlayerSubmapValue
                                (DAT_0057c670,*(int *)(value2 + 8),*(int *)(value2 + 0x2c));
    arg2 = extraout_EDX;
  }
  if ((((*(int *)((intptr_t)arg1 + 0xf4) == 0) || (local_4 == (void *)0x0)) ||
      (flag1 = City_IsIdle((intptr_t)local_4), arg2 = extraout_EDX_00,
      CONCAT31(extraout_var,flag1) != 0)) || (*(int *)((intptr_t)arg1 + 0x30) == 0x10)) {
    Person_CancelVisitAtOccupiedBuilding(arg1,arg2,1);
    return;
  }
  *(uint32_t *)((intptr_t)arg1 + 0x54) = 0;
  *(uint32_t *)((intptr_t)arg1 + 0x74) = 1;
  Object_SetFlag104(arg1,1);
  Game_AddObjectToList(*(void **)((intptr_t)arg1 + 0xf4),arg1);
  UI_ShiftChildRect((intptr_t)arg1);
  Object_RebindRenderList(arg1,1,*(uint32_t *)((intptr_t)local_4 + 0x14e0));
  value2 = State_IsMenuState((intptr_t)arg1);
  if (value2 != 0) {
    Object_Reset108((intptr_t)arg1);
    UI_SetChildHeightFromValue((intptr_t)arg1);
  }
  switch(*(uint32_t *)((intptr_t)arg1 + 0x30)) {
  case 0x16:
    *(int *)((intptr_t)local_4 + 0x1884) = *(int *)((intptr_t)local_4 + 0x1884) + 1;
    value2 = *(int *)((intptr_t)local_4 + 0x30);
    value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    if ((value2 == value3) && (*(int *)((intptr_t)arg1 + 0xa4) == 2)) {
      value2 = 3;
      ptr4 = *(int **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xac);
      ptr5 = ptr4;
      do {
        ptr5 = ptr5 + 1;
        if ((*ptr5 == 0xe) && (Array_SearchSet(ptr4,0xe), 3 < ptr4[0x12])) {
          Game_CompleteMissionStage();
        }
        value2 = value2 + -1;
      } while (value2 != 0);
    }
    break;
  case 0x1d:
    *(int *)((intptr_t)local_4 + 0x1890) = *(int *)((intptr_t)local_4 + 0x1890) + 1;
    break;
  case 0x1e:
    *(int *)((intptr_t)local_4 + 0x1888) = *(int *)((intptr_t)local_4 + 0x1888) + 1;
    break;
  case 0x1f:
    if (*(int *)((intptr_t)arg1 + 0xa4) < 0xe) {
      *(int *)((intptr_t)local_4 + 0x188c) = *(int *)((intptr_t)local_4 + 0x188c) + 1;
      value2 = *(int *)((intptr_t)local_4 + 0x30);
      value3 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
      if (value2 == value3) {
        value2 = 3;
        ptr4 = *(int **)(*(int *)((intptr_t)DAT_0057c670 + 0x224) + 0xac);
        ptr5 = ptr4;
        do {
          ptr5 = ptr5 + 1;
          if ((*ptr5 == 0xe) && (Array_SearchSet(ptr4,0xe), 3 < ptr4[0x12])) {
            Game_CompleteMissionStage();
          }
          value2 = value2 + -1;
        } while (value2 != 0);
      }
    }
  }
  switch(*(uint32_t *)((intptr_t)arg1 + 0x30)) {
  case 10:
    value3 = *(int *)((intptr_t)arg1 + 0x10c);
    value2 = 0xc;
    if (value3 == 0) {
      UI_SetChildState(arg1,0x1a);
    }
    else if (value3 == 1) {
      UI_SetChildState(arg1,0x1b);
    }
    else if (value3 == 2) {
      UI_SetChildState(arg1,0x1c);
    }
    break;
  default:
    goto switchD_005084d1_caseD_b;
  case 0xd:
    value2 = Object_GetClampedLevel((intptr_t)arg1);
    goto LAB_005084e4;
  case 0x11:
    value2 = 0x14;
    break;
  case 0x13:
    value2 = 0x34;
    break;
  case 0x14:
    value2 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x20),*(int *)((intptr_t)arg1 + 0x50),(int *)0x0
                        );
    if (*(char *)(value2 + 0x825) == '\x01') {
      uvalue6 = 0x11;
    }
    else {
      uvalue6 = 0x10;
    }
    UI_SetChildState(arg1,uvalue6);
    if (((*(int *)((intptr_t)arg1 + 0xa4) == 4) &&
        (ptr4 = (int *)RecordMap_Lookup1998(local_4,*(int *)((intptr_t)arg1 + 0x88)),
        ptr4 != (int *)0x0)) && (0 < *ptr4)) {
      Object_SetChildField2C(arg1,0x10);
      value2 = 0x1c;
      break;
    }
    goto LAB_005085d5;
  case 0x17:
  case 0x1d:
    value2 = -1;
LAB_005084e4:
    Object_GetPlayerValue(arg1,value2);
    value2 = Object_GetChildField2C((intptr_t)arg1);
    value2 = value2 + 0x1c;
    break;
  case 0x1f:
    if (*(int *)((intptr_t)arg1 + 0xa4) != -1) {
      Object_SetChildField2C(arg1,0x10);
      value2 = 0x1c;
      switch(*(uint32_t *)((intptr_t)arg1 + 0xa4)) {
      case 3:
      case 7:
      case 9:
      case 0xd:
        UI_SetChildState(arg1,0x15);
        break;
      case 0x11:
        UI_SetChildState(arg1,0x22);
      }
      break;
    }
LAB_005085d5:
    Object_SetChildField2C(arg1,0);
switchD_005084d1_caseD_b:
    value2 = 0xc;
    break;
  case 0x20:
    value2 = 0xc;
    Game_ShowBuildingOverlay(local_4,1);
  }
  UI_SetChildRecordVariant(arg1,value2);
  UI_DetachChildRecord((intptr_t)arg1);
  if ((*(char *)((intptr_t)local_4 + 0x16f5) == '\0') && (*(int *)((intptr_t)local_4 + 0x2c) == 0)) {
    Object_SetState(arg1,5);
    return;
  }
  Object_SetState(arg1,7);
  return;
}
