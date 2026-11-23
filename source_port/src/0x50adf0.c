// Person_ProcessMoveEvent: ported from Pizza Connection 2 at 0x50adf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50adf0
#include "pc2_port.h"

uint32_t __fastcall Person_ProcessMoveEvent(void *arg1)

{
  void *pvVar1;
  int value2;
  int *ptr3;
  
                    /* Processes a person's movement event and selects the next state. */
  if ((*(char *)((intptr_t)arg1 + 0x80) == '\0') && (*(char *)((intptr_t)arg1 + 0x81) == '\0')) {
    return 0;
  }
  switch(*(uint32_t *)((intptr_t)arg1 + 0x30)) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 0xb:
  case 0xf:
  case 0x21:
    if (*(char *)((intptr_t)arg1 + 0x81) != '\0') {
      value2 = *(int *)((intptr_t)arg1 + 0x38);
      if (((value2 == 0xb) || (value2 == 0xd)) || (value2 == 0x11)) {
        if ((*(short *)((intptr_t)arg1 + 0x40) == 9) &&
           (ptr3 = (int *)Game_ApplyObjectEvent((intptr_t)arg1), ptr3 != (int *)0x0)) {
          UI_DrawCenteredSelectionRect(*(void **)((intptr_t)arg1 + 0xc4),ptr3);
        }
        if (*(short *)((intptr_t)arg1 + 0x40) != 0xb) {
          UI_SetChildState(arg1,0xffff);
          Game_GetTimeByMode(arg1,0);
          *(uint32_t *)((intptr_t)arg1 + 0x4c) = 0;
          *(uint32_t *)((intptr_t)arg1 + 0x54) = 0;
        }
        UI_DetachChildRecord((intptr_t)arg1);
        Object_SetState(arg1,9);
      }
      else if ((value2 != 6) && (value2 != 7)) {
        value2 = Person_CanContinuePath((intptr_t)arg1);
        if (value2 == 0) {
          UI_DetachChildRecord((intptr_t)arg1);
        }
        else {
          Person_TruncatePathToCurrentStep((intptr_t)arg1);
        }
        Object_SetState(arg1,6);
        if (*(short *)((intptr_t)arg1 + 0x40) != 0xb) {
          UI_SetChildState(arg1,0xffff);
          *(uint8_t *)((intptr_t)arg1 + 0x81) = 0;
          return 1;
        }
      }
      *(uint8_t *)((intptr_t)arg1 + 0x81) = 0;
      return 1;
    }
    break;
  case 10:
  case 0xe:
  case 0x16:
  case 0x18:
  case 0x20:
    if (*(char *)((intptr_t)arg1 + 0x81) != '\0') {
      Object_SetFieldA4Locked(arg1,0xffffffff);
LAB_0050af4e:
      value2 = Person_CanContinuePath((intptr_t)arg1);
      if (value2 == 0) {
        UI_DetachChildRecord((intptr_t)arg1);
        Object_SetState(arg1,6);
        return 1;
      }
      Person_TruncatePathToCurrentStep((intptr_t)arg1);
      Object_SetState(arg1,6);
      return 1;
    }
    break;
  case 0x11:
  case 0x12:
    value2 = Person_CanContinuePath((intptr_t)arg1);
    if (value2 == 0) {
      UI_DetachChildRecord((intptr_t)arg1);
      Object_SetState(arg1,6);
    }
    else {
      Person_TruncatePathToCurrentStep((intptr_t)arg1);
      Object_SetState(arg1,6);
    }
    goto LAB_0050aee8;
  case 0x13:
    value2 = Person_CanContinuePath((intptr_t)arg1);
    if (value2 == 0) {
      UI_DetachChildRecord((intptr_t)arg1);
    }
    else {
      Person_TruncatePathToCurrentStep((intptr_t)arg1);
    }
    Object_SetState(arg1,6);
    Object_SetChildField2C(arg1,0x10);
    value2 = *(int *)((intptr_t)arg1 + 0xf4);
    if ((value2 != 0) &&
       (pvVar1 = (void *)Game_GetPlayerSubmapValue
                                   (DAT_0057c670,*(int *)(value2 + 8),*(int *)(value2 + 0x2c)),
       pvVar1 != (void *)0x0)) {
      Game_MoveTypeBObjectsToStateList(arg1,pvVar1);
    }
    goto LAB_0050aee8;
  case 0x14:
    Object_SetFieldA4Locked(arg1,0xffffffff);
    value2 = Person_CanContinuePath((intptr_t)arg1);
    if (value2 == 0) {
      UI_DetachChildRecord((intptr_t)arg1);
    }
    else {
      Person_TruncatePathToCurrentStep((intptr_t)arg1);
    }
    Object_SetState(arg1,6);
    Object_SetChildField2C(arg1,0);
LAB_0050aee8:
    if (*(char *)((intptr_t)arg1 + 0x80) == '\0') {
      return 1;
    }
    UI_SetChildState(arg1,0x12);
    Game_GetTimeByMode(arg1,7);
    return 1;
  case 0x17:
  case 0x1d:
  case 0x1e:
  case 0x1f:
    if (*(char *)((intptr_t)arg1 + 0x81) != '\0') {
      Object_AbortOrderAndReturnHome(arg1);
      goto LAB_0050af4e;
    }
  }
  return 0;
}
