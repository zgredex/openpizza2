// Game_GetActiveCompanyById: ported from Pizza Connection 2 at 0x4dde30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dde30
#include "pc2_port.h"

int __thiscall Game_GetActiveCompanyById(void *self,int arg1)

{
  int value1;
  int value2;
  int value3;
  int value4;
  
  value1 = *(int *)((intptr_t)self + 0x124);
  value3 = 0;
  value4 = 0;
  if (0 < value1) {
    do {
      value2 = IDMap_Lookup((void *)((intptr_t)self + 0x110),value4,(int *)0x0);
      if (*(char *)(value2 + 0x1dc) == '\x01') {
        if (value3 == arg1) {
          return value2;
        }
        value3 = value3 + 1;
      }
      value4 = value4 + 1;
    } while (value4 < value1);
  }
  return 0;
}
