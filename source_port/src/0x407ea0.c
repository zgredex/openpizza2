// Customer_UpdateMovement: ported from Pizza Connection 2 at 0x407ea0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x407ea0
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall Customer_UpdateMovement(void *self,void *arg1,void *arg2)

{
  void *this_00;
  uint8_t uvalue1;
  uint32_t extraout_var;
  int value2;
  void *local_4;
  
                    /* Updates a store customer's movement states. */
  this_00 = arg2;
  local_4 = self;
  uvalue1 = Object_IsVisibleThisFrame((intptr_t)arg2);
  value2 = *(int *)((intptr_t)this_00 + 0x38);
  if (CONCAT31(extraout_var,uvalue1) == 0) {
    switch(value2) {
    case 5:
      while( true ) {
        if (*(int *)((intptr_t)this_00 + 200) == 0) {
          value2 = 0;
        }
        else {
          value2 = *(int *)(*(int *)((intptr_t)this_00 + 200) + 0x20);
        }
        value2 = Game_FindNearestRecordAndAngle(arg1,value2,(int *)&local_4,(uint32_t *)&arg2);
        if (value2 == 0) break;
        *(int *)((intptr_t)this_00 + 0x88) = (intptr_t)arg2 + 0x10;
        *(void **)((intptr_t)this_00 + 0x8c) = local_4;
        _DAT_0057c610 = Person_WalkToCellOrAbort(this_00,value2);
        if (_DAT_0057c610 != 0) {
          Object_SetState(this_00,8);
          *(uint8_t *)((intptr_t)this_00 + 0x81) = 0;
          return;
        }
        value2 = UI_FindObjectByField20(arg1,*(int *)((intptr_t)this_00 + 0x8c));
        if (value2 != 0) {
          Game_RemoveMapObjectAtPoint(arg1,value2);
        }
      }
      if (*(void **)((intptr_t)self + 0x9c) == arg1) {
        Sound_ProcessEvent(DAT_0057ba0c,0xe,0xf,'\x01');
      }
      Object_SetState(this_00,6);
      _DAT_0057c610 = 0;
      Object_SetState(this_00,6);
      *(uint8_t *)((intptr_t)this_00 + 0x81) = 1;
      return;
    case 6:
      value2 = Array_GetRandomRecord28(*(int *)((intptr_t)this_00 + 0xc4));
      if (value2 != 0) {
        Person_AdvanceRoute(this_00,value2);
        Object_SetState(this_00,7);
        return;
      }
      break;
    case 7:
      UI_ShiftChildRect((intptr_t)this_00);
      Object_SetState(this_00,0x2e);
      *(uint32_t *)((intptr_t)self + 0x368) = 1;
      return;
    case 8:
      value2 = *(int *)((intptr_t)this_00 + 0x88);
      Object_SetState(this_00,0x33);
      Object_SetFrame5(this_00,6);
      UI_SetChildRecordVariant(this_00,value2);
      Sound_HandleEvent(DAT_0057ba0c,(intptr_t)arg1,0x2f);
      return;
    default:
      Person_ResumeRouteOrDetach(this_00);
      return;
    case 0x14:
      Object_SetState(this_00,6);
      return;
    }
  }
  else if (value2 == 8) {
    Person_ProcessMoveEvent(this_00);
  }
  else if (((value2 == 0x33) && (value2 = Person_ProcessMoveEvent(this_00), value2 == 0)) &&
          (value2 = *(int *)((intptr_t)this_00 + 0x94) + -1, *(int *)((intptr_t)this_00 + 0x94) = value2,
          value2 == 0)) {
    value2 = UI_FindObjectByField20(arg1,*(int *)((intptr_t)this_00 + 0x8c));
    if (value2 != 0) {
      Game_RemoveMapObjectAtPoint(arg1,value2);
    }
    Object_SetFrame5(this_00,-1);
    UI_DetachChildRecord((intptr_t)this_00);
    Object_SetState(this_00,5);
    return;
  }
  return;
}
