// Game_CountObjectsByType2: ported from Pizza Connection 2 at 0x4d6ba0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d6ba0
#include "pc2_port.h"

int __thiscall Game_CountObjectsByType2(void *self,uint32_t arg1)

{
  int value1;
  int *ptr2;
  int value3;
  int value4;
  int local_4;
  
  value1 = *(int *)((intptr_t)self + 0xfdc);
  value4 = 0;
  local_4 = 0;
  value3 = 0;
  if (0 < value1) {
    do {
      ptr2 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0xfc8),value4,(int *)0x0);
      if ((arg1 == *(uint8_t *)(*ptr2 + 0x824)) || (arg1 == 0xffffffff)) {
        local_4 = local_4 + 1;
      }
      value4 = value4 + 1;
    } while (value4 < value1);
    value3 = local_4;
  }
  return value3;
}
