// Game_DecayProductValues: ported from Pizza Connection 2 at 0x513f50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x513f50
#include "pc2_port.h"

int __thiscall Game_DecayProductValues(void *self,int arg1)

{
  int value1;
  int value2;
  int value3;
  
  value1 = arg1 / 3;
  if (arg1 % 3 == 0) {
    value1 = *(int *)((intptr_t)self + 0x58);
    value3 = 0;
    if (0 < value1) {
      do {
        value2 = IDMap_Lookup((void *)((intptr_t)self + 0x44),value3,(int *)0x0);
        value1 = (*(int *)(value2 + 0xc) / 10 -
                *(int *)(&DAT_00573b08 + *(int *)((intptr_t)self + 0x2c) * 4)) + -10 +
                *(int *)(value2 + 4);
        if (value1 < 0) {
          value1 = 0;
        }
        *(int *)(value2 + 4) = value1;
        value1 = *(int *)((intptr_t)self + 0x58);
        value3 = value3 + 1;
      } while (value3 < value1);
    }
  }
  return value1;
}
