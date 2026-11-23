// Game_FindBestPlayerRecordPair: ported from Pizza Connection 2 at 0x47cd80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47cd80
#include "pc2_port.h"

void __thiscall Game_FindBestPlayerRecordPair(void *self,uint32_t arg1,int *arg2,int *arg3)

{
  int value1;
  uint8_t flag2;
  int value3;
  int value4;
  int value5;
  int value6;
  int local_8;
  int local_4;
  
  value5 = -1;
  value6 = -1;
  local_4 = -1;
  local_8 = 0;
  if (*(int *)((intptr_t)self + 0x170c) < 1) {
    *arg2 = -1;
    *arg3 = -1;
    return;
  }
  do {
    value3 = IDMap_Lookup((void *)((intptr_t)self + 0x16f8),local_8,(int *)0x0);
    if ((value3 != 0) && (flag2 = Game_GetPlayerByte8(value3), flag2 == arg1)) {
      value1 = *(int *)(value3 + 4);
      value3 = *(int *)(value3 + 8);
      if (((value1 != value5) || (value3 != local_4)) &&
         (value4 = Game_CountRecordsByPair(self,value1,value3), value6 < value4)) {
        value5 = value1;
        value6 = value4;
        local_4 = value3;
      }
    }
    local_8 = local_8 + 1;
  } while (local_8 < *(int *)((intptr_t)self + 0x170c));
  *arg2 = value5;
  *arg3 = local_4;
  return;
}
