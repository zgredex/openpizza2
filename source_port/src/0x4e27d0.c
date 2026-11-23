// Game_CountPlayerObjectsByType: ported from Pizza Connection 2 at 0x4e27d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e27d0
#include "pc2_port.h"

int __thiscall Game_CountPlayerObjectsByType(void *self,int arg1,int arg2,int arg3)

{
  int *ptr1;
  int value2;
  int value3;
  int local_4;
  
  value3 = 0;
  local_4 = 0;
  value2 = 0;
  if (0 < *(int *)((intptr_t)self + 0x1cc)) {
    do {
      ptr1 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1b8),value3,(int *)0x0);
      if (ptr1[1] == arg2) {
        value2 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),*ptr1,(int *)0x0);
        if (((*(int *)(value2 + 0x74) != 0) && (*(int *)(value2 + 0xf4) == *(int *)(arg1 + 0x16f0))
            ) && ((*(int *)(value2 + 0xa4) == arg3 || (arg3 == -1)))) {
          local_4 = local_4 + 1;
        }
      }
      value3 = value3 + 1;
    } while (value3 < *(int *)((intptr_t)self + 0x1cc));
    value2 = local_4;
  }
  return value2;
}
