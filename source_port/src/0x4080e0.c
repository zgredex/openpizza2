// Game_UpdateVisitorObjectState: ported from Pizza Connection 2 at 0x4080e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4080e0
#include "pc2_port.h"

void __thiscall Game_UpdateVisitorObjectState(void *self,void *arg1,void *arg2)

{
  int value1;
  uint8_t uvalue2;
  uint32_t extraout_var;
  void *this_00;
  uint32_t uvalue3;
  int value4;
  
                    /* Updates visitor/shop object states and detaches on timeout. */
  uvalue2 = Object_IsVisibleThisFrame((intptr_t)arg2);
  value1 = *(int *)((intptr_t)arg2 + 0x38);
  if (value1 != 0x1f) {
    if (CONCAT31(extraout_var,uvalue2) == 0) {
      if (value1 == 0x18) {
        switch(*(uint32_t *)((intptr_t)arg2 + 0x30)) {
        case 0x2b:
          UI_SetChildRecordVariant(arg2,0);
          Sound_HandleEvent(DAT_0057ba0c,(intptr_t)arg1,0x2b);
          Object_SetState(arg2,0x31);
          return;
        case 0x2c:
          UI_SetChildRecordVariant(arg2,1);
          Sound_HandleEvent(DAT_0057ba0c,(intptr_t)arg1,0x2b);
          Object_SetState(arg2,0x31);
          return;
        case 0x2d:
          UI_SetChildRecordVariant(arg2,0);
          Sound_HandleEvent(DAT_0057ba0c,(intptr_t)arg1,0x2d);
          Object_SetState(arg2,0x31);
          uvalue3 = Game_GetDateField0C((intptr_t)self);
          *(uint32_t *)((intptr_t)arg2 + 0x98) = uvalue3;
          return;
        case 0x2f:
          UI_SetChildRecordVariant(arg2,0);
          Sound_HandleEvent(DAT_0057ba0c,(intptr_t)arg1,0x1c);
          Object_SetState(arg2,0x31);
          uvalue3 = Game_GetDateField0C((intptr_t)self);
          *(uint32_t *)((intptr_t)arg2 + 0x98) = uvalue3;
          Game_MarkAllObjectsDirty(arg1,7);
          return;
        }
      }
      else if (((value1 == 0x31) && (value1 = *(int *)((intptr_t)arg2 + 0x30), 0x2a < value1)) &&
              (value1 < 0x2d)) {
        this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x3c),*(int *)((intptr_t)arg2 + 0x10c),
                                       (int *)0x0);
        if (this_00 != (void *)0x0) {
          Game_ApplyDiminishingObjectBonus((intptr_t)arg1);
          UI_DetachChildRecord((intptr_t)this_00);
          Object_SetState(this_00,6);
          Object_SetFieldA4Locked(this_00,0xffffffff);
        }
        Object_SetState(arg2,0x32);
        UI_SetChildRecordVariant(arg2,(value1 != 0x2b) + 2);
        return;
      }
    }
    else if ((value1 == 0x31) && (*(int *)((intptr_t)arg2 + 0x30) == 0x2d)) {
      value1 = *(int *)((intptr_t)arg2 + 0x98);
      value4 = Game_GetDateField0C((intptr_t)self);
      if (5 < value4 - value1) {
        UI_DetachChildRecord((intptr_t)arg2);
        Object_SetFrame5(arg2,-1);
        UI_ShiftChildRect((intptr_t)arg2);
        Object_SetState(arg2,0x1f);
        return;
      }
      Game_ApplyAreaObjectEvent(arg2,(intptr_t)arg1);
    }
  }
  return;
}
