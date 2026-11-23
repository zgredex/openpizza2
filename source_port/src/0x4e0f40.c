// Game_HasRecordField14DC: ported from Pizza Connection 2 at 0x4e0f40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e0f40
#include "pc2_port.h"

uint32_t __thiscall Game_HasRecordField14DC(void *self,int arg1)

{
  int value1;
  uint32_t in_EAX;
  int value2;
  
  value1 = *(int *)((intptr_t)self + 0x15c);
  value2 = 0;
  if (0 < value1) {
    do {
      in_EAX = IDMap_Lookup((void *)((intptr_t)self + 0x148),value2,(int *)0x0);
      if (*(int *)(in_EAX + 0x14dc) == arg1) {
        return CONCAT31((int3)(in_EAX >> 8),1);
      }
      value2 = value2 + 1;
    } while (value2 < value1);
  }
  return in_EAX & 0xffffff00;
}
