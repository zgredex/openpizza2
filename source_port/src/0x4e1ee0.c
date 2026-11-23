// AI_CountAvailableTargets: ported from Pizza Connection 2 at 0x4e1ee0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e1ee0
#include "pc2_port.h"

int __thiscall AI_CountAvailableTargets(void *self,int arg1)

{
  int *ptr1;
  int value2;
  int value3;
  int local_8;
  
  value3 = 0;
  local_8 = 0;
  value2 = 0;
  if (0 < *(int *)((intptr_t)self + 0x1cc)) {
    do {
      ptr1 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1b8),value3,(int *)0x0);
      value2 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),*ptr1,(int *)0x0);
      if ((((ptr1[1] == arg1) && (*(int *)(value2 + 0xa4) == -1)) &&
          (*(int *)(value2 + 0xfc) != 0)) &&
         ((*(char *)(value2 + 0x104) != '\0' && (*(int *)(value2 + 0x74) == 0)))) {
        local_8 = local_8 + 1;
      }
      value3 = value3 + 1;
    } while (value3 < *(int *)((intptr_t)self + 0x1cc));
    value2 = local_8;
  }
  return value2;
}
