// Branch_CloseMonth: ported from Pizza Connection 2 at 0x477850.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x477850
#include "pc2_port.h"


void __thiscall Branch_CloseMonth(void *self,int arg1)

{
  uint16_t uvalue1;
  void *pvVar2;
  uint32_t *uptr3;
  int value4;
  int value5;
  int *ptr6;
  int *ptr7;
  uint32_t unaff_EDI;
  int *ptr8;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00557f2b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar2 = operator_new(0x35c);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    uptr3 = (uint32_t *)0x0;
  }
  else {
    uptr3 = Stats_Report_ConstructEmpty
                       (pvVar2,(uint32_t)*(uint16_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 10),
                        (uint32_t)*(uint16_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 4));
  }
  local_4 = 0xffffffff;
  List_Add((void *)((intptr_t)self + 0x14e4),uptr3);
  if (arg1 != 0) {
    value5 = *(int *)((intptr_t)self + 0x30);
    value4 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    if (value5 == value4) {
      pvVar2 = (void *)Game_GetPlayerBySlot(DAT_0057c670,value5);
      value5 = Game_GetPlayerFieldC20((intptr_t)pvVar2);
      if (1 < value5) {
        value5 = Game_CountObjectsForOwner(pvVar2,(intptr_t)self,0x17);
        if (value5 == 0) {
          value5 = Game_HasQueuedEventType(DAT_0057c670,5);
          if (value5 == 0) {
            value5 = UI_Briefing_Printf((intptr_t)DAT_0057c670,-1,5,4,10,*(int *)((intptr_t)self + 0x16f0),
                                       DAT_005811a8,DAT_00581280,unaff_EDI);
            Game_SetMessageField34(DAT_0057c670,value5,5);
          }
        }
      }
    }
  }
  uvalue1 = *(uint16_t *)(*(int *)((intptr_t)DAT_0057c670 + 0x94) + 10);
  Game_GetPenaltyValues(self);
  uptr3 = (uint32_t *)((intptr_t)self + 0x430);
  value5 = 8;
  do {
    *uptr3 = uptr3[-1];
    uptr3[-0xa2] = uptr3[-0xa3];
    uptr3 = uptr3 + 9;
    value5 = value5 + -1;
  } while (value5 != 0);
  ptr7 = (int *)((intptr_t)self + (uvalue1 - 1) * 4 + 0x554);
  ptr8 = (int *)((intptr_t)self + 0x44);
  value5 = 8;
  do {
    value4 = 8;
    ptr6 = ptr8;
    do {
      *ptr7 = *ptr7 + *ptr6;
      ptr6[0x51] = *ptr6;
      ptr6[0xf3] = ptr6[0xa2];
      value4 = value4 + -1;
      ptr6 = ptr6 + 1;
    } while (value4 != 0);
    ptr7 = ptr7 + 100;
    ptr8 = ptr8 + 9;
    value5 = value5 + -1;
  } while (value5 != 0);
  *(uint32_t *)((intptr_t)self + 0x13cc) = *(uint32_t *)((intptr_t)self + 0x13c8);
  *(uint32_t *)((intptr_t)self + 0x1414) = *(uint32_t *)((intptr_t)self + 0x1410);
  *(uint32_t *)((intptr_t)self + 0x145c) = *(uint32_t *)((intptr_t)self + 0x1458);
  *(uint32_t *)((intptr_t)self + 0x14a4) = *(uint32_t *)((intptr_t)self + 0x14a0);
  uptr3 = (uint32_t *)((intptr_t)self + 5000);
  value5 = 8;
  do {
    uptr3[9] = *uptr3;
    *uptr3 = 0;
    uptr3[0x1b] = uptr3[0x12];
    uptr3[0x12] = 0;
    uptr3[0x2d] = uptr3[0x24];
    uptr3[0x24] = 0;
    uptr3[0x3f] = uptr3[0x36];
    uptr3[0x36] = 0;
    uptr3 = uptr3 + 1;
    value5 = value5 + -1;
  } while (value5 != 0);
  Game_CanAfford(self,1,(float)*(int *)((intptr_t)self + 0x14b0),'\0',-1);
  uptr3 = (uint32_t *)((intptr_t)self + 0x44);
  for (value5 = 0x51; value5 != 0; value5 = value5 + -1) {
    *uptr3 = 0;
    uptr3 = uptr3 + 1;
  }
  uptr3 = (uint32_t *)((intptr_t)self + 0x1364);
  for (value5 = 9; value5 != 0; value5 = value5 + -1) {
    *uptr3 = 0;
    uptr3 = uptr3 + 1;
  }
  uptr3 = (uint32_t *)((intptr_t)self + 0x2cc);
  for (value5 = 0x51; value5 != 0; value5 = value5 + -1) {
    *uptr3 = 0;
    uptr3 = uptr3 + 1;
  }
  ExceptionList = local_c;
  return;
}
