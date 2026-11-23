// AI_IsDirectionOnRoute: ported from Pizza Connection 2 at 0x477120.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x477120
#include "pc2_port.h"

uint32_t __thiscall AI_IsDirectionOnRoute(void *self,int *arg1,uint32_t arg2)

{
  int *ptr1;
  uint32_t uvalue2;
  int value3;
  int value4;
  
  value3 = *(int *)((intptr_t)self + 0x1514);
  value4 = 0;
  if (value3 < 1) {
    ptr1 = arg1;
  }
  else {
    do {
      ptr1 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1500),value4,(int *)0x0);
      if ((int *)*ptr1 == arg1) break;
      value4 = value4 + 1;
    } while (value4 < value3);
  }
  if (value4 == value3) {
    return 0;
  }
  uvalue2 = ptr1[1];
  value3 = 0;
  do {
    if (uvalue2 == arg2) {
      return 1;
    }
    uvalue2 = uvalue2 + 1 & 7;
    value3 = value3 + 1;
  } while (value3 < 3);
  return 0;
}
