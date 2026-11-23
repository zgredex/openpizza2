// Game_CountActiveObjectsByType: ported from Pizza Connection 2 at 0x4e1d40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e1d40
#include "pc2_port.h"

int __thiscall Game_CountActiveObjectsByType(void *self,int arg1)

{
  int value1;
  int *ptr2;
  int value3;
  int value4;
  int value5;
  int local_4;
  
  value1 = *(int *)((intptr_t)self + 0x1cc);
  value5 = 0;
  local_4 = 0;
  value3 = 0;
  if (0 < value1) {
    do {
      ptr2 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1b8),value5,(int *)0x0);
      value3 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),*ptr2,(int *)0x0);
      value4 = State_Is2DOr2E(value3);
      if ((value4 == 0) && ((arg1 == -1 || (*(int *)(value3 + 0x30) == arg1)))) {
        local_4 = local_4 + 1;
      }
      value5 = value5 + 1;
    } while (value5 < value1);
    value3 = local_4;
  }
  return value3;
}
