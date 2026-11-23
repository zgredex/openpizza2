// Game_FindNearestObjectByPosition: ported from Pizza Connection 2 at 0x4e3550.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e3550
#include "pc2_port.h"

int __thiscall Game_FindNearestObjectByPosition(void *self,int arg1)

{
  int value1;
  int value2;
  int value3;
  int value4;
  int value5;
  int value6;
  int value7;
  int local_8;
  
  local_8 = 0;
  value6 = 999999999;
  value1 = Game_GetObjectCenterY(arg1);
  value2 = Game_GetObjectBottom(arg1);
  value7 = 0;
  if (*(int *)((intptr_t)self + 0x15c) < 1) {
    return 0;
  }
  do {
    value3 = IDMap_Lookup((void *)((intptr_t)self + 0x148),value7,(int *)0x0);
    value4 = Game_GetObjectCenterY(*(int *)(value3 + 0x16f0));
    value5 = Game_GetObjectBottom(*(int *)(value3 + 0x16f0));
    value4 = (value1 - value4) * (value1 - value4) + (value2 - value5) * (value2 - value5);
    if (value4 < value6) {
      value6 = value4;
      local_8 = value3;
    }
    value7 = value7 + 1;
  } while (value7 < *(int *)((intptr_t)self + 0x15c));
  return local_8;
}
