// Character_OnArriveAtDestination: ported from Pizza Connection 2 at 0x50d930.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50d930
#include "pc2_port.h"

void __thiscall Character_OnArriveAtDestination(void *self,float arg1,uint32_t arg2)

{
  float fVar1;
  int value2;
  int value3;
  uint32_t uvalue4;
  void *pvVar5;
  int value6;
  
                    /* Handles a character arriving at its destination. */
  fVar1 = arg1;
  if ((arg1 != 0.0) && (*(int *)((intptr_t)arg1 + 0x30) == 0x17)) {
    value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)arg1 + 0x110));
    if (value2 != 0) {
      value3 = Game_GetPlayerCity(value2);
      *(int *)(value3 + 0x38) = *(int *)(value3 + 0x38) + 1;
      Object_AdjustShortPercent(*(void **)((intptr_t)DAT_0057c670 + 0x90),*(int *)(value2 + 0x4c),-5);
    }
  }
  if ((*(int *)((intptr_t)self + 0x110) != -1) &&
     ((*(int *)((intptr_t)self + 0x30) == 0x1d || (*(int *)((intptr_t)self + 0x30) == 0x1e)))) {
    value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + 0x110));
    if (value2 != 0) {
      *(int *)(value2 + 0x80) = *(int *)(value2 + 0x80) + 1;
    }
    value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)arg1 + 0x110));
    if (value2 != 0) {
      *(int *)(value2 + 0x8c) = *(int *)(value2 + 0x8c) + 1;
    }
  }
  value2 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)DAT_0057c670 + 0x2f4),
                       (int *)0x0);
  *(int *)(value2 + 0x10ac) = *(int *)(value2 + 0x10ac) + 1;
  if (arg2 == 0) {
    Object_SetChildShort((intptr_t)self);
    UI_ShiftChildRect((intptr_t)self);
    if (*(int *)((intptr_t)self + 200) == 0) {
      arg1 = 0.0;
      uvalue4 = UI_HitTestChildPoint(self,fVar1);
    }
    else {
      fVar1 = *(float *)(*(int *)((intptr_t)self + 200) + 0x20);
      uvalue4 = UI_HitTestChildPoint(self,arg1);
      arg1 = fVar1;
    }
  }
  else {
    uvalue4 = arg2;
  }
  if (*(int *)((intptr_t)self + 0x30) != 0xd) {
    pvVar5 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + 0x110));
    Game_UnlinkBuildingObject(pvVar5,*(int *)((intptr_t)self + 0x164));
  }
  if (arg2 == 0) {
    value2 = Game_GetPlayerSubmapValue
                      (DAT_0057c670,*(int *)(*(int *)((intptr_t)self + 0xf4) + 8),
                       *(int *)(*(int *)((intptr_t)self + 0xf4) + 0x2c));
    UI_DestroyChildObject((intptr_t)self);
    Object_SetState(self,0x2d);
    MapObject_InitRenderRecord(self,1,-1,-1);
    Sound_ProcessEventForSelectedObject(DAT_0057ba0c,value2,*(int *)((intptr_t)self + 0x30),9,'\x01');
    if ((*(int *)((intptr_t)self + 0x30) == 0x1d) || (*(int *)((intptr_t)self + 0x30) == 0x1e)) {
      Sound_HandleEvent(DAT_0057ba0c,value2,0x2e);
    }
    else {
      Sound_HandleEvent(DAT_0057ba0c,value2,0x1f);
    }
  }
  else {
    Object_SetState(self,0x2e);
    *(uint32_t *)((intptr_t)DAT_0057c670 + 0x368) = 1;
    Game_RemoveObjectFromList(*(void **)((intptr_t)self + 0xfc),self,0);
  }
  if (*(int *)((intptr_t)self + 0x30) == 0xd) {
    pvVar5 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),
                                  *(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
    value2 = *(int *)((intptr_t)self + 0x58);
    value3 = *(int *)((intptr_t)pvVar5 + value2 * 0x18 + 0x10d8);
    value6 = *(int *)((intptr_t)pvVar5 + value2 * 0x18 + 0x10dc) + 1;
    *(int *)((intptr_t)pvVar5 + value2 * 0x18 + 0x10dc) = value6;
    if (value6 == value3) {
      value2 = *(int *)((intptr_t)self + 0x58);
      value3 = 1;
    }
    else {
      if (*(int *)((intptr_t)pvVar5 + value2 * 0x18 + 0x10e0) + value6 != value3) goto LAB_0050db64;
      value2 = *(int *)((intptr_t)self + 0x58);
      value3 = 2;
    }
    City_ResetPoliceDistrictSlot(pvVar5,value3,value2);
  }
LAB_0050db64:
  if (arg2 == 0) {
    UI_SetChildTracking(self,1,(intptr_t)arg1);
    Object_SyncScreenY((intptr_t)self);
    UI_SetChildRecordVariant(self,uvalue4);
  }
  if ((self == *(void **)((intptr_t)DAT_0057c670 + 0x21c)) &&
     (*(void **)((intptr_t)DAT_0057c670 + 0x25c) != (void *)0x0)) {
    UI_QueueControlCommand(*(void **)((intptr_t)DAT_0057c670 + 0x25c),-0x18629,0x23,0);
    pvVar5 = DAT_0057c670;
    *(uint32_t *)((intptr_t)DAT_0057c670 + 0x21c) = 0;
    *(uint32_t *)((intptr_t)pvVar5 + 0x2da8) = 1;
  }
  return;
}
