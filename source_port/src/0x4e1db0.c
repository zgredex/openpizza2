// AI_CountActiveTargetsByState: ported from Pizza Connection 2 at 0x4e1db0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e1db0
#include "pc2_port.h"

int __thiscall AI_CountActiveTargetsByState(void *self,int arg1)

{
  int value1;
  int *ptr2;
  int value3;
  int value4;
  int local_8;
  
  value1 = *(int *)((intptr_t)self + 0x1cc);
  value4 = 0;
  local_8 = 0;
  value3 = 0;
  if (0 < value1) {
    do {
      ptr2 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1b8),value4,(int *)0x0);
      value3 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),*ptr2,(int *)0x0);
      if ((((arg1 == -1) || (*(int *)(value3 + 0x30) == arg1)) &&
          (*(char *)(value3 + 0x104) == '\x01')) &&
         (*(int *)(value3 + 0xfc) != *(int *)((intptr_t)self + 0x1d8))) {
        value3 = State_Is2DOr2E(value3);
        if (value3 == 0) {
          local_8 = local_8 + 1;
        }
      }
      value4 = value4 + 1;
    } while (value4 < value1);
    value3 = local_8;
  }
  return value3;
}
