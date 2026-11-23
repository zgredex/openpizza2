// Stats_GetAverage8: ported from Pizza Connection 2 at 0x4787f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4787f0
#include "pc2_port.h"

int __thiscall Stats_GetAverage8(void *self,int arg1)

{
  int value1;
  int *ptr2;
  int value3;
  int value4;
  
  value3 = 0;
  if (arg1 == -1) {
    ptr2 = (int *)((intptr_t)self + 0x17bc);
    value4 = 8;
    do {
      value1 = *ptr2;
      ptr2 = ptr2 + 1;
      value3 = value3 + value1;
      value4 = value4 + -1;
    } while (value4 != 0);
    arg1 = value3 >> 3;
  }
  else {
    arg1 = *(int *)((intptr_t)self + arg1 * 4 + 0x17bc);
  }
  value3 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + 0x30));
  value3 = Game_GetPlayerCity(value3);
  arg1 = (((*(int *)(value3 + 0x5c) + *(int *)(value3 + 0x44)) * -3 + 100) * arg1) / 100;
  Clamp_0_100(&arg1);
  return arg1;
}
