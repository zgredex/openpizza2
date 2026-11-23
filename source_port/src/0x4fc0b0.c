// IDMap_FreeValuesAndDestroy: ported from Pizza Connection 2 at 0x4fc0b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fc0b0
#include "pc2_port.h"

void IDMap_FreeValuesAndDestroy(uint32_t *arg1)

{
  int value1;
  LPVOID pvVar2;
  int value3;
  
  value3 = 0;
  value1 = arg1[5];
  if (0 < value1) {
    do {
      pvVar2 = (LPVOID)IDMap_Lookup(arg1,value3,(int *)0x0);
      Mem_Free(pvVar2);
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  if (arg1 != (uint32_t *)0x0) {
    (**(code **)*arg1)(1);
  }
  return;
}
