// Game_ApplyPercentChange: ported from Pizza Connection 2 at 0x48c2c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48c2c0
#include "pc2_port.h"

int __thiscall Game_ApplyPercentChange(void *self,int arg1,int arg2,int arg3)

{
  int value1;
  int value2;
  int value3;
  int value4;
  
  value2 = *(int *)((intptr_t)self + 0x50);
  value4 = 0;
  if (0 < value2) {
    value3 = arg1;
    do {
      value1 = IDMap_Lookup((void *)((intptr_t)self + 0x3c),value4,(int *)0x0);
      value2 = 0;
      if (*(int *)(value1 + 0xa0) != 0) {
        if ((arg3 == -1) || (*(int *)(value1 + 0x34) == arg3)) {
          value3 = *(int *)(value1 + 0x5c + arg1 * 4);
        }
        value3 = (arg2 + 100) * value3;
        value2 = value3 * 0x51eb851f;
        value3 = value3 / 100;
        *(int *)(value1 + 0x5c + arg1 * 4) = value3;
      }
      value4 = value4 + 1;
    } while (value4 < *(int *)((intptr_t)self + 0x50));
  }
  return value2;
}
