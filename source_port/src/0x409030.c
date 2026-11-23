// Person_EnterBuildingAndWork: ported from Pizza Connection 2 at 0x409030.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x409030
#include "pc2_port.h"

void Person_EnterBuildingAndWork(int arg1,void *arg2)

{
  uint8_t uvalue1;
  uint32_t extraout_var;
  int value2;
  uint8_t unaff_SI;
  uint32_t unaff_EDI;
  
                    /* Enters a building and performs work until finished. */
  uvalue1 = Object_IsVisibleThisFrame((intptr_t)arg2);
  value2 = *(int *)((intptr_t)arg2 + 0x38);
  if (value2 == 0x1f) {
    return;
  }
  if (CONCAT31(extraout_var,uvalue1) == 0) {
    switch(value2) {
    case 8:
      if (*(int *)((intptr_t)arg2 + 0x30) == 0x1a) {
        value2 = *(int *)((intptr_t)arg2 + 0x88) + 0x10;
        Sound_HandleEvent(DAT_0057ba0c,arg1,0x2c);
      }
      else if (*(int *)((intptr_t)arg2 + 0x30) == 0x1b) {
        value2 = *(int *)((intptr_t)arg2 + 0x88);
        Sound_HandleEvent(DAT_0057ba0c,arg1,0x22);
        value2 = value2 + 8;
      }
      else {
        value2 = arg1;
      }
      Object_SetState(arg2,0x19);
      Object_SetFrame5(arg2,10);
      UI_SetChildRecordVariant(arg2,value2);
      Game_ApplyAreaObjectEvent(arg2,arg1);
      return;
    case 0x18:
      value2 = AI_ComputePath(0,0,0,unaff_EDI,unaff_SI);
      if (value2 != 0) {
        Person_AdvanceRoute(arg2,value2);
        Object_SetState(arg2,8);
        return;
      }
      break;
    case 0x23:
    case 0x24:
      value2 = Object_HasNearbyType20Object((intptr_t)arg2);
      if (value2 == 0) {
        UI_SetListEntryHalfScale((intptr_t)arg2);
        Object_SetState(arg2,0x18);
        return;
      }
      if (*(int *)((intptr_t)arg2 + 0x30) == 0x1a) {
        value2 = *(int *)((intptr_t)arg2 + 0xa8) + -0x14;
        *(int *)((intptr_t)arg2 + 0xa8) = value2;
      }
      else {
        value2 = *(int *)((intptr_t)arg2 + 0xa8) + -7;
        *(int *)((intptr_t)arg2 + 0xa8) = value2;
      }
joined_r0x0040925e:
      if (value2 < 0) {
        *(uint32_t *)((intptr_t)arg2 + 0xa8) = 0;
      }
      UI_SetChildHeightFromValue((intptr_t)arg2);
      if (*(int *)((intptr_t)arg2 + 0xa8) == 0) {
        UI_ShiftChildRect((intptr_t)arg2);
        Object_SetState(arg2,0x1f);
        return;
      }
    }
  }
  else {
    switch(value2) {
    case 8:
      if (*(int *)((intptr_t)arg2 + 200) == 0) {
        *(uint32_t *)((intptr_t)arg2 + 0x88) = 0xffffffff;
        return;
      }
      *(uint32_t *)((intptr_t)arg2 + 0x88) = *(uint32_t *)(*(int *)((intptr_t)arg2 + 200) + 0xc);
      return;
    case 0x19:
      value2 = *(int *)((intptr_t)arg2 + 0x94) + -1;
      *(int *)((intptr_t)arg2 + 0x94) = value2;
      if (value2 == 0) {
        Object_SetFrame5(arg2,-1);
        UI_DetachChildRecord((intptr_t)arg2);
        Object_SetState(arg2,0x18);
      }
      break;
    case 0x23:
      value2 = Object_HasNearbyType20Object((intptr_t)arg2);
      if (value2 != 0) {
        value2 = Person_CanContinuePath((intptr_t)arg2);
        if (value2 == 0) {
          UI_DetachChildRecord((intptr_t)arg2);
        }
        if (*(int *)((intptr_t)arg2 + 0x30) == 0x1a) {
          value2 = *(int *)((intptr_t)arg2 + 0xa8) + -0x14;
          *(int *)((intptr_t)arg2 + 0xa8) = value2;
        }
        else {
          value2 = *(int *)((intptr_t)arg2 + 0xa8) + -7;
          *(int *)((intptr_t)arg2 + 0xa8) = value2;
        }
        if (value2 < 0) {
          *(uint32_t *)((intptr_t)arg2 + 0xa8) = 0;
        }
        UI_SetChildHeightFromValue((intptr_t)arg2);
        if (*(int *)((intptr_t)arg2 + 0xa8) == 0) {
          UI_ShiftChildRect((intptr_t)arg2);
          Object_SetState(arg2,0x1f);
          return;
        }
        Record_DoublePositionValue((intptr_t)arg2);
        value2 = AI_ComputePath(0,0,0,unaff_EDI,unaff_SI);
        if (value2 != 0) {
          Person_AdvanceRoute(arg2,value2);
          Object_SetState(arg2,0x24);
          return;
        }
      }
      break;
    case 0x24:
      value2 = Object_HasNearbyType20Object((intptr_t)arg2);
      if (value2 == 0) {
        return;
      }
      if (*(int *)((intptr_t)arg2 + 0x30) == 0x1a) {
        value2 = *(int *)((intptr_t)arg2 + 0xa8) + -0x14;
        *(int *)((intptr_t)arg2 + 0xa8) = value2;
      }
      else {
        value2 = *(int *)((intptr_t)arg2 + 0xa8) + -7;
        *(int *)((intptr_t)arg2 + 0xa8) = value2;
      }
      goto joined_r0x0040925e;
    }
  }
  return;
}
