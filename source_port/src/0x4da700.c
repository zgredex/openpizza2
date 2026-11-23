// Stats_GetPlayerSharePercent: ported from Pizza Connection 2 at 0x4da700.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4da700
#include "pc2_port.h"

int __thiscall Stats_GetPlayerSharePercent(void *self,int arg1)

{
  int value1;
  int value2;
  int value3;
  int *ptr4;
  
  value2 = 0;
  value3 = 0;
  ptr4 = (int *)((intptr_t)self + 0xd40);
  do {
    value1 = Game_GetPlayerBySlot(DAT_0057c670,value3);
    if (value1 != 0) {
      value2 = value2 + (0x65 - *ptr4);
    }
    value3 = value3 + 1;
    ptr4 = ptr4 + 1;
  } while (value3 < 6);
  return ((0x65 - *(int *)((intptr_t)self + arg1 * 4 + 0xd40)) * 100) / value2;
}
