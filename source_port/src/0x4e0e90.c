// Game_SelectLeastUsedCategory: ported from Pizza Connection 2 at 0x4e0e90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e0e90
#include "pc2_port.h"

int __thiscall Game_SelectLeastUsedCategory(void *self,int arg1)

{
  int value1;
  int value2;
  int *ptr3;
  int local_20 [8];
  
  ptr3 = local_20;
  for (value2 = 8; value2 != 0; value2 = value2 + -1) {
    *ptr3 = 0;
    ptr3 = ptr3 + 1;
  }
  value2 = 0;
  if (0 < *(int *)((intptr_t)self + 0x124)) {
    do {
      value1 = IDMap_Lookup((void *)((intptr_t)self + 0x110),value2,(int *)0x0);
      value2 = value2 + 1;
      local_20[*(int *)(value1 + 0x308)] = local_20[*(int *)(value1 + 0x308)] + 1;
    } while (value2 < *(int *)((intptr_t)self + 0x124));
  }
  value2 = -1;
  value1 = 0;
  ptr3 = local_20;
  do {
    if (*ptr3 < arg1) {
      value2 = value1;
      arg1 = *ptr3;
    }
    value1 = value1 + 1;
    ptr3 = ptr3 + 1;
  } while (value1 < 8);
  return value2;
}
