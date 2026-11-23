// Game_CountObjectsByType: ported from Pizza Connection 2 at 0x47aac0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47aac0
#include "pc2_port.h"

int __thiscall Game_CountObjectsByType(void *self,uint32_t arg1)

{
  int *ptr1;
  int value2;
  int value3;
  int local_4;
  
  value3 = 0;
  local_4 = 0;
  value2 = 0;
  if (0 < *(int *)((intptr_t)self + 0x1514)) {
    do {
      ptr1 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1500),value3,(int *)0x0);
      if ((arg1 == *(uint8_t *)(*ptr1 + 0x824)) || (arg1 == 0xffffffff)) {
        local_4 = local_4 + 1;
      }
      value3 = value3 + 1;
    } while (value3 < *(int *)((intptr_t)self + 0x1514));
    value2 = local_4;
  }
  return value2;
}
