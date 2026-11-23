// Person_SitAndEatPizza: ported from Pizza Connection 2 at 0x409350.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x409350
#include "pc2_port.h"

void Person_SitAndEatPizza(void *arg1,void *arg2)

{
  void *self;
  uint8_t uvalue1;
  char cVar2;
  uint32_t extraout_var;
  int value3;
  void *pvVar4;
  uint8_t unaff_SI;
  uint32_t unaff_EDI;
  uint32_t local_24;
  uint32_t local_20 [8];
  
                    /* Sits a person down and consumes a delivered pizza. */
  self = arg2;
  local_20[0] = 0x10;
  local_20[1] = 0x12;
  local_20[2] = 0x14;
  local_20[3] = 0x16;
  local_20[4] = 0x11;
  local_20[5] = 0x13;
  local_20[6] = 0x15;
  local_20[7] = 0x17;
  uvalue1 = Object_IsVisibleThisFrame((intptr_t)arg2);
  value3 = *(int *)((intptr_t)self + 0x38);
  if (value3 == 0x1f) {
    return;
  }
  if (CONCAT31(extraout_var,uvalue1) == 0) {
    switch(value3) {
    case 8:
      if (*(int *)((intptr_t)self + 0xa4) == 10) {
        value3 = *(int *)((intptr_t)self + 0x88);
        Object_SetState(self,0x1b);
        Object_SetFrame5(self,0x14);
        UI_SetChildRecordVariant(self,value3);
        Sound_HandleEvent(DAT_0057ba0c,(intptr_t)arg1,0x21);
        return;
      }
      if (*(int *)((intptr_t)self + 0xa4) == 0xb) {
        Object_SetState(self,0x18);
        return;
      }
      break;
    case 0x18:
      value3 = AI_ChooseWalkTarget(*(void **)((intptr_t)self + 0xc4),(intptr_t)self,arg1,&local_24,&arg2)
      ;
      if (value3 != 0) {
        *(uint32_t *)((intptr_t)self + 0x88) = local_20[(intptr_t)arg2];
        *(uint32_t *)((intptr_t)self + 0x8c) = local_24;
        Person_AdvanceRoute(self,value3);
        Object_SetState(self,8);
        Object_SetFieldA4Locked(self,10);
        return;
      }
      value3 = AI_ComputePath(0,0,0,unaff_EDI,unaff_SI);
      if (value3 != 0) {
        Person_AdvanceRoute(self,value3);
        Object_SetState(self,8);
        Object_SetFieldA4Locked(self,0xb);
        return;
      }
      break;
    case 0x23:
    case 0x24:
      value3 = Object_HasNearbyType20Object((intptr_t)self);
      if (value3 == 0) {
        UI_SetListEntryHalfScale((intptr_t)self);
        Object_SetState(self,0x18);
        return;
      }
      value3 = *(int *)((intptr_t)self + 0xa8) + -0x14;
      *(int *)((intptr_t)self + 0xa8) = value3;
      goto joined_r0x0040953e;
    }
  }
  else {
    if (value3 == 0x1b) {
      value3 = *(int *)((intptr_t)self + 0x94) + -1;
      *(int *)((intptr_t)self + 0x94) = value3;
      if (value3 == 0) {
        pvVar4 = (void *)Game_FindRecordByField20(arg1,*(int *)((intptr_t)self + 0x8c));
        if (pvVar4 != (void *)0x0) {
          value3 = *(int *)((intptr_t)pvVar4 + 0xc);
          if (value3 < 6) {
            Game_SetModeByte(pvVar4,0);
            Game_ApplyOwnerWideObjectEvent(arg1,(intptr_t)pvVar4);
            cVar2 = Game_GetPlayerByte8((intptr_t)pvVar4);
            if (cVar2 == '\x01') {
              value3 = 0x1d;
            }
            else {
              value3 = 0x1e;
            }
            Sound_HandleEvent(DAT_0057ba0c,(intptr_t)arg1,value3);
            Game_UpdateObject(pvVar4,arg1);
          }
          else {
            Game_SetModeByte(pvVar4,CONCAT31((int3)((uint32_t)value3 >> 8),(char)value3 + -5));
          }
        }
      }
      else {
        pvVar4 = (void *)Game_FindRecordByField20(arg1,*(int *)((intptr_t)self + 0x8c));
        if ((pvVar4 != (void *)0x0) && (value3 = *(int *)((intptr_t)pvVar4 + 0xc), 0 < value3)) {
          if (value3 < 6) {
            Game_SetModeByte(pvVar4,0);
            Game_ApplyOwnerWideObjectEvent(arg1,(intptr_t)pvVar4);
            Game_UpdateObject(pvVar4,arg1);
            return;
          }
          Game_SetModeByte(pvVar4,CONCAT31((int3)((uint32_t)value3 >> 8),(char)value3 + -5));
          return;
        }
      }
      Object_SetFrame5(self,-1);
      UI_DetachChildRecord((intptr_t)self);
      Object_SetState(self,0x18);
      return;
    }
    if (value3 == 0x23) {
      value3 = Object_HasNearbyType20Object((intptr_t)self);
      if (value3 == 0) {
        return;
      }
      value3 = Person_CanContinuePath((intptr_t)self);
      if (value3 == 0) {
        UI_DetachChildRecord((intptr_t)self);
      }
      value3 = *(int *)((intptr_t)self + 0xa8) + -0x14;
      *(int *)((intptr_t)self + 0xa8) = value3;
      if (value3 < 0) {
        *(uint32_t *)((intptr_t)self + 0xa8) = 0;
      }
      UI_SetChildHeightFromValue((intptr_t)self);
      if (*(int *)((intptr_t)self + 0xa8) == 0) {
        UI_ShiftChildRect((intptr_t)self);
        Object_SetState(self,0x1f);
        return;
      }
      Record_DoublePositionValue((intptr_t)self);
      value3 = AI_ComputePath(0,0,0,unaff_EDI,unaff_SI);
      if (value3 == 0) {
        return;
      }
      Person_AdvanceRoute(self,value3);
      Object_SetState(self,0x24);
      return;
    }
    if (value3 != 0x24) {
      return;
    }
    value3 = Object_HasNearbyType20Object((intptr_t)self);
    if (value3 == 0) {
      return;
    }
    value3 = *(int *)((intptr_t)self + 0xa8) + -0x14;
    *(int *)((intptr_t)self + 0xa8) = value3;
joined_r0x0040953e:
    if (value3 < 0) {
      *(uint32_t *)((intptr_t)self + 0xa8) = 0;
    }
    UI_SetChildHeightFromValue((intptr_t)self);
    if (*(int *)((intptr_t)self + 0xa8) == 0) {
      UI_ShiftChildRect((intptr_t)self);
      Object_SetState(self,0x1f);
      return;
    }
  }
  return;
}
