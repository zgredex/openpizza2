// IDMap_FindIndexByValue: ported from Pizza Connection 2 at 0x47c370.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47c370
#include "pc2_port.h"

int __thiscall IDMap_FindIndexByValue(void *self,int arg1)

{
  int value1;
  int value2;
  int *ptr3;
  int value4;
  
  value2 = arg1;
  if (arg1 != 0) {
    value1 = *(int *)((intptr_t)self + 0x1514);
    value4 = 0;
    if (0 < value1) {
      do {
        ptr3 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1500),value4,&arg1);
        if (value2 == *ptr3) {
          return arg1;
        }
        value4 = value4 + 1;
      } while (value4 < value1);
    }
  }
  return -1;
}
