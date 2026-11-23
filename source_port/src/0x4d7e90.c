// Array_FindIndexByPtr: ported from Pizza Connection 2 at 0x4d7e90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d7e90
#include "pc2_port.h"

int __thiscall Array_FindIndexByPtr(void *self,int arg1)

{
  int value1;
  int value2;
  int value3;
  
  value1 = *(int *)((intptr_t)self + 0xfc0);
  value3 = 0;
  if (0 < value1) {
    do {
      value2 = IDMap_Lookup((void *)((intptr_t)self + 0xfac),value3,(int *)0x0);
      if (arg1 == value2) {
        return value3;
      }
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  return -1;
}
