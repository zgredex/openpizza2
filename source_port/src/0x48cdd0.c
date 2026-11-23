// Game_CountProductUsageByCategory: ported from Pizza Connection 2 at 0x48cdd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48cdd0
#include "pc2_port.h"

int __thiscall Game_CountProductUsageByCategory(void *self,int arg1,uint32_t *arg2)

{
  int value1;
  int *ptr2;
  int value3;
  int *ptr4;
  uint32_t *uptr5;
  int local_8;
  
  uptr5 = arg2;
  for (value3 = 0x40; value3 != 0; value3 = value3 + -1) {
    *uptr5 = 0;
    uptr5 = uptr5 + 1;
  }
  value3 = 0;
  local_8 = 0;
  if (*(int *)((intptr_t)self + 0x50) < 1) {
    return 0;
  }
  do {
    value1 = IDMap_Lookup((void *)((intptr_t)self + 0x3c),value3,(int *)0x0);
    if (*(int *)(value1 + 0x30) < 8) {
      ptr4 = (int *)(value1 + 0xd4);
      ptr2 = arg2 + *(int *)(value1 + 0x30);
      value1 = 8;
      do {
        if (*ptr4 == arg1) {
          *ptr2 = *ptr2 + 1;
          local_8 = local_8 + 1;
        }
        ptr4 = ptr4 + 1;
        ptr2 = ptr2 + 8;
        value1 = value1 + -1;
      } while (value1 != 0);
    }
    value3 = value3 + 1;
  } while (value3 < *(int *)((intptr_t)self + 0x50));
  return local_8;
}
