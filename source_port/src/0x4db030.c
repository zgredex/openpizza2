// Game_ComputeCompanyValue: ported from Pizza Connection 2 at 0x4db030.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4db030
#include "pc2_port.h"

int __thiscall Game_ComputeCompanyValue(void *self,int *arg1,int *arg2,int *arg3)

{
  int *ptr1;
  int value2;
  int value3;
  int value4;
  int value5;
  int value6;
  
  value3 = 0;
  ptr1 = (int *)((intptr_t)self + 0xcb0);
  value6 = 6;
  do {
    value2 = *ptr1;
    ptr1 = ptr1 + 1;
    value3 = value3 + value2;
    value6 = value6 + -1;
  } while (value6 != 0);
  value6 = *(int *)((intptr_t)self + 0x10c4);
  value3 = value3 + value6 * -1000;
  if (value3 < 0) {
    value3 = 0;
  }
  if (value6 == 0) {
    return 0;
  }
  value4 = 0;
  value5 = 0;
  value2 = Game_GetPlayerCount((intptr_t)DAT_0057c670);
  if (0 < value2) {
    do {
      value2 = Game_GetPlayerBySlot(DAT_0057c670,value5);
      value4 = value4 + *(int *)(value2 + 0xf0);
      value5 = value5 + 1;
      value2 = Game_GetPlayerCount((intptr_t)DAT_0057c670);
    } while (value5 < value2);
  }
  value2 = Game_GetPlayerCount((intptr_t)DAT_0057c670);
  value2 = 100 - value4 / value2;
  value4 = (value3 / value6) / 1000 + 1 + value2 / 10;
  value3 = value3 / value6 + (value2 * 10000) / 0x14;
  if (10 < value4) {
    value4 = 10;
  }
  value6 = value3 / 10000;
  value3 = value3 / 15000;
  value2 = value4 - value3;
  *arg3 = value3;
  if (value2 < 1) {
    value2 = 0;
    *arg3 = value4;
  }
  value2 = value2 - value6;
  *arg2 = value6;
  if (value2 < 0) {
    value6 = value6 + value2;
    value2 = 0;
    *arg2 = value6;
  }
  *arg1 = value2;
  return value4;
}
