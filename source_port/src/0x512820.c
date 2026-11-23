// IDMap_FindIndexByPointer: ported from Pizza Connection 2 at 0x512820.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x512820
#include "pc2_port.h"

int IDMap_FindIndexByPointer(void *arg1,int arg2)

{
  int value1;
  int value2;
  
  value2 = 0;
  if (0 < *(int *)((intptr_t)arg1 + 0x14)) {
    do {
      value1 = IDMap_Lookup(arg1,value2,(int *)0x0);
      if (arg2 == value1) {
        return value2;
      }
      value2 = value2 + 1;
    } while (value2 < *(int *)((intptr_t)arg1 + 0x14));
  }
  return -1;
}
