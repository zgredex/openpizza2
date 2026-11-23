// Game_ShutdownWorld: ported from Pizza Connection 2 at 0x487310.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x487310
#include "pc2_port.h"

void __fastcall Game_ShutdownWorld(int arg1)

{
  uint32_t *uptr1;
  void *self;
  int value2;
  int value3;
  int *ptr4;
  int iStack_4;
  
  iStack_4 = arg1;
  CS_Enter(*(int *)(arg1 + 0x240));
  *(uint32_t *)(arg1 + 0x2fc) = 0;
  if (*(uint32_t **)(arg1 + 0x300) != (uint32_t *)0x0) {
    (**(code **)**(uint32_t **)(arg1 + 0x300))(1);
    *(uint32_t *)(arg1 + 0x300) = 0;
  }
  UI_ClearActiveRecordSlots(arg1);
  CS_Leave(*(int *)(arg1 + 0x240));
  UI_DestroyBriefingList((void *)(arg1 + 0x304));
  *(uint32_t *)(arg1 + 0x98) = 0;
  *(uint32_t *)(arg1 + 0x9c) = 0;
  *(uint32_t *)(arg1 + 0x360) = 0xffffffff;
  Game_DestroyEventWindow(arg1);
  DAT_0057cda0 = 0;
  ptr4 = (int *)(arg1 + 0x224);
  value2 = 6;
  do {
    if ((uint32_t *)*ptr4 != (uint32_t *)0x0) {
      (*(code *)**(uint32_t **)*ptr4)(1);
      *ptr4 = 0;
    }
    ptr4 = ptr4 + 1;
    value2 = value2 + -1;
  } while (value2 != 0);
  value2 = *(int *)(arg1 + 0x50);
  value3 = 0;
  if (0 < value2) {
    do {
      uptr1 = (uint32_t *)IDMap_Lookup((void *)(arg1 + 0x3c),value3,(int *)0x0);
      if (uptr1 != (uint32_t *)0x0) {
        (**(code **)*uptr1)(1);
      }
      value3 = value3 + 1;
    } while (value3 < value2);
  }
  List_Node_Reset(arg1 + 0x3c);
  ptr4 = (int *)(arg1 + 0x200);
  value2 = 6;
  do {
    if ((uint32_t *)*ptr4 != (uint32_t *)0x0) {
      (*(code *)**(uint32_t **)*ptr4)(1);
      *ptr4 = 0;
    }
    ptr4 = ptr4 + 1;
    value2 = value2 + -1;
  } while (value2 != 0);
  value2 = *(int *)(arg1 + 0x18);
  value3 = 0;
  if (0 < value2) {
    do {
      uptr1 = (uint32_t *)IDMap_Lookup((void *)(arg1 + 4),value3,(int *)0x0);
      if (uptr1 != (uint32_t *)0x0) {
        (**(code **)*uptr1)(1);
      }
      value3 = value3 + 1;
    } while (value3 < value2);
  }
  List_Node_Reset(arg1 + 4);
  value2 = *(int *)(arg1 + 0x6c);
  value3 = 0;
  if (0 < value2) {
    do {
      uptr1 = (uint32_t *)IDMap_Lookup((void *)(arg1 + 0x58),value3,(int *)0x0);
      if (uptr1 != (uint32_t *)0x0) {
        (**(code **)*uptr1)(1);
      }
      value3 = value3 + 1;
    } while (value3 < value2);
  }
  List_Node_Reset(arg1 + 0x58);
  value2 = *(int *)(arg1 + 0x34);
  value3 = 0;
  if (0 < value2) {
    do {
      uptr1 = (uint32_t *)IDMap_Lookup((void *)(arg1 + 0x20),value3,(int *)0x0);
      if (uptr1 != (uint32_t *)0x0) {
        (**(code **)*uptr1)(1);
      }
      value3 = value3 + 1;
    } while (value3 < value2);
  }
  List_Node_Reset(arg1 + 0x20);
  List_Node_Reset(DAT_0057c5cc + 0x2c3f8);
  self = (void *)UI_FindWindowByID(DAT_0057c5e0,*(int *)(arg1 + 0x2dac),(int *)0x0);
  if (self != (void *)0x0) {
    value2 = Get_FieldF0((intptr_t)self);
    while (value2 = value2 + -1, -1 < value2) {
      Array_GetPair8(self,value2,&iStack_4);
      if (iStack_4 != 99999) {
        UI_RemoveObject(self,iStack_4);
      }
    }
    value2 = UI_GetWindowObject(self,99999);
    if (value2 == 0) {
      return;
    }
    UI_RealizeSprite(value2);
    *(uint32_t *)((intptr_t)self + 0xe0) = 1;
  }
  *(uint32_t *)(arg1 + 0x1508) = 1;
  if (*(uint32_t **)(arg1 + 0x300) != (uint32_t *)0x0) {
    (**(code **)**(uint32_t **)(arg1 + 0x300))(1);
    *(uint32_t *)(arg1 + 0x300) = 0;
  }
  return;
}
