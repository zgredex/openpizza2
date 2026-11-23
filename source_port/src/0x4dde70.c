// Game_FindCompanyIndex: ported from Pizza Connection 2 at 0x4dde70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dde70
#include "pc2_port.h"

int __thiscall Game_FindCompanyIndex(void *self,int arg1)

{
  int value1;
  int value2;
  int value3;
  
  value1 = *(int *)((intptr_t)self + 0x124);
  value3 = 0;
  if (0 < value1) {
    do {
      value2 = IDMap_Lookup((void *)((intptr_t)self + 0x110),value3,(int *)0x0);
      if (arg1 == value2) {
        return value3;
      }
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  return -1;
}
