// Game_ContainsObjectPointer: ported from Pizza Connection 2 at 0x480bf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x480bf0
#include "pc2_port.h"

uint32_t __thiscall Game_ContainsObjectPointer(void *self,int arg1)

{
  int value1;
  uint32_t uvalue2;
  int value3;
  
  uvalue2 = *(uint32_t *)((intptr_t)self + 0x170c);
  value3 = 0;
  if (0 < (intptr_t)uvalue2) {
    do {
      value1 = IDMap_Lookup((void *)((intptr_t)self + 0x16f8),value3,(int *)0x0);
      if (arg1 == value1) {
        return CONCAT31((int3)((uint32_t)value1 >> 8),1);
      }
      uvalue2 = *(uint32_t *)((intptr_t)self + 0x170c);
      value3 = value3 + 1;
    } while (value3 < (intptr_t)uvalue2);
  }
  return uvalue2 & 0xffffff00;
}
