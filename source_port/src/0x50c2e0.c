// Person_ResolveGroupFight: ported from Pizza Connection 2 at 0x50c2e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50c2e0
#include "pc2_port.h"

char __thiscall Person_ResolveGroupFight(void *self,void *arg1,int arg2)

{
  int *ptr1;
  void *this_00;
  int value2;
  void *this_01;
  int value3;
  uint32_t uvalue4;
  char cVar5;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
                    /* Resolves a group brawl and updates crime counters. */
  ptr1 = *(int **)((intptr_t)self + 200);
  cVar5 = '\0';
  if (ptr1 == (int *)0x0) {
    return '\x01';
  }
  Record_GetTwoFloats48((void *)ptr1[0x16],*ptr1,&local_c,&local_4);
  this_00 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x3c),arg2,(int *)0x0);
  if (this_00 == (void *)0x0) {
    return '\x01';
  }
  if (*(int *)((intptr_t)this_00 + 0x74) == 0) {
    return '\x01';
  }
  value2 = State_Is2DOr2E((intptr_t)this_00);
  if (value2 != 0) {
    return '\x01';
  }
  if (((*(int *)((intptr_t)self + 0x30) == 0x17) || (*(int *)((intptr_t)self + 0x30) == 0x1d)) &&
     (*(int *)((intptr_t)this_00 + 0xa4) == -1)) {
    return '\x01';
  }
  if (*(int *)((intptr_t)this_00 + 0x38) == 0x38) {
    return '\x01';
  }
  ptr1 = *(int **)((intptr_t)this_00 + 200);
  if (ptr1 == (int *)0x0) {
    value2 = -1;
    this_01 = (void *)0x0;
  }
  else {
    value2 = *ptr1;
    this_01 = (void *)ptr1[0x16];
  }
  Record_GetTwoFloats48(this_01,value2,&local_10,&local_8);
  if (((local_10 - local_c) * (local_10 - local_c) + (local_8 - local_4) * (local_8 - local_4) * 4 <
       0xe10) && (*(int *)((intptr_t)this_00 + 0xa4) != -1)) {
    if ((*(int *)((intptr_t)self + 0x30) == 0x17) || (*(int *)((intptr_t)self + 0x30) == 0x1d)) {
      value2 = Game_CountObjectsType1DSub19((intptr_t)arg1);
      value3 = Game_UpdateFreeBuildingCount((intptr_t)arg1);
      value2 = value2 + value3;
    }
    else {
      value2 = Game_CountFreeBuildingsTypeD((intptr_t)arg1);
    }
    value3 = Game_CountAvailableBusinessBuildings((intptr_t)arg1);
    if (value3 < value2) {
      cVar5 = '\x01';
    }
    else if (value2 < value3) {
      cVar5 = '\x02';
    }
    else {
      uvalue4 = Random_RangeFast(1,100);
      cVar5 = ((intptr_t)uvalue4 < 0x32) + '\x01';
    }
    if (*(short *)(*(int *)((intptr_t)this_00 + 200) + 0x28) == -1) {
      UI_DetachChildRecord((intptr_t)this_00);
    }
    else {
      Person_TruncatePathToCurrentStep((intptr_t)this_00);
    }
    if (cVar5 == '\x01') {
      if (*(int *)((intptr_t)self + 0x30) == 0xd) {
        if (*(int *)((intptr_t)this_00 + 0x110) != -1) {
          value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)this_00 + 0x110));
          *(int *)(value2 + 0x84) = *(int *)(value2 + 0x84) + 1;
        }
        value2 = 0x38;
      }
      else {
        value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + 0x110));
        if (value2 != 0) {
          value2 = Game_GetPlayerCity(value2);
          *(int *)(value2 + 0x38) = *(int *)(value2 + 0x38) + 1;
        }
        value2 = 0x2a;
      }
      Object_SetState(this_00,value2);
      uvalue4 = UI_HitTestChildPoint(self,(float)(intptr_t)(self));
      *(uint32_t *)((intptr_t)this_00 + 0x88) = uvalue4;
      Object_SetFieldA4Locked(this_00,0xffffffff);
      return '\x01';
    }
    Object_SetState(this_00,0x2c);
    *(uint32_t *)((intptr_t)this_00 + 0x8c) = *(uint32_t *)((intptr_t)self + 0x164);
    Branch_InitCityObjects(arg1,0x1e);
  }
  return cVar5;
}
