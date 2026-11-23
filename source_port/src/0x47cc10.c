// Game_CountPlayersByByte: ported from Pizza Connection 2 at 0x47cc10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47cc10
#include "pc2_port.h"

int __thiscall Game_CountPlayersByByte(void *self,uint32_t arg1)

{
  uint8_t flag1;
  int value2;
  int value3;
  int local_4;
  
  value3 = 0;
  local_4 = 0;
  value2 = 0;
  if (0 < *(int *)((intptr_t)self + 0x170c)) {
    do {
      value2 = IDMap_Lookup((void *)((intptr_t)self + 0x16f8),value3,(int *)0x0);
      if (value2 != 0) {
        flag1 = Game_GetPlayerByte8(value2);
        if (flag1 == arg1) {
          local_4 = local_4 + 1;
        }
      }
      value3 = value3 + 1;
    } while (value3 < *(int *)((intptr_t)self + 0x170c));
    value2 = local_4;
  }
  return value2;
}
