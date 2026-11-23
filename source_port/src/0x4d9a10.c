// City_RecordBuildingCompletion: ported from Pizza Connection 2 at 0x4d9a10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d9a10
#include "pc2_port.h"

void __thiscall
City_RecordBuildingCompletion(void *self,int arg1,void *arg2,int arg3,int arg4)

{
  int value1;
  int *ptr2;
  int value3;
  int value4;
  int value5;
  int value6;
  uint32_t uvalue7;
  
  value3 = arg4;
  value5 = *(int *)((intptr_t)arg2 + 0x30);
  value6 = 0;
  if (arg4 != -1) {
    value4 = Game_GetPlayerBySlot(DAT_0057c670,arg4);
    value4 = Game_GetPlayerCity(value4);
    arg4 = *(int *)(value4 + 0x54) + *(int *)(value4 + 0x3c);
  }
  if (-1 < arg3) {
    Game_AdjustPlayerPercentByKey(*(void **)((intptr_t)DAT_0057c670 + 0x90),value5);
  }
  if (arg1 == 0) {
    value4 = Game_GetConstructionPriority((intptr_t)arg2);
    value6 = 1;
  }
  else if (arg1 == 1) {
    value4 = Game_GetBuildingConditionCode(arg2);
    value6 = 0;
  }
  else if (arg1 == 2) {
    value4 = Stats_HasCurrentSales((intptr_t)arg2);
    value6 = 2;
  }
  else {
    value4 = arg3;
  }
  *(int *)((intptr_t)self + value6 * 0xc + 0xd88) = *(int *)((intptr_t)self + value6 * 0xc + 0xd88) + 1;
  if (-1 < arg3) {
    value1 = value6 * 3 + 0x363;
    *(int *)((intptr_t)self + value1 * 4) = *(int *)((intptr_t)self + value1 * 4) + 1;
  }
  if (value4 == 0) {
    if ((arg3 == 2) && (value3 != -1)) {
      ptr2 = (int *)((intptr_t)self + (arg1 + value3 * 4) * 4 + 0xc38);
      value5 = (*ptr2 * 0x12) / 10;
      *ptr2 = value5;
      if (100 < value5) {
        *ptr2 = 100;
      }
    }
    if (arg2 != *(void **)((intptr_t)DAT_0057c670 + 0x9c)) {
      return;
    }
    uvalue7 = 0xc;
  }
  else {
    *(int *)((intptr_t)self + value6 * 0xc + 0xd90) = *(int *)((intptr_t)self + value6 * 0xc + 0xd90) + 1;
    value6 = Game_GetCurrentPlayerCompanyName((intptr_t)DAT_0057c670);
    if (value5 == value6) {
      ptr2 = (int *)((intptr_t)self + value4 * 8 + 0xd50);
      *ptr2 = *ptr2 + 1;
    }
    *(int *)((intptr_t)self + value4 * 8 + 0xd54) = *(int *)((intptr_t)self + value4 * 8 + 0xd54) + 1;
    value5 = Game_GetPlayerBySlot(DAT_0057c670,value5);
    Game_ScalePlayerStat80(value5);
    if ((arg3 == 2) && (value3 != -1)) {
      value5 = arg1 + value3 * 4;
      ptr2 = (int *)((intptr_t)self + value5 * 4 + 0xc38);
      value5 = arg4 * 3 + (*(int *)((intptr_t)self + value5 * 4 + 0xc38) * 5) / 10;
      *ptr2 = value5;
      if (value5 < 0) {
        *ptr2 = 0;
      }
    }
    if (arg2 != *(void **)((intptr_t)DAT_0057c670 + 0x9c)) {
      return;
    }
    uvalue7 = 0xb;
  }
  Sound_ProcessEvent(DAT_0057ba0c,10,uvalue7,'\x01');
  return;
}
