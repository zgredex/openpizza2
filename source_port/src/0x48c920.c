// Game_GetCategoryShare: ported from Pizza Connection 2 at 0x48c920.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48c920
#include "pc2_port.h"

int __thiscall Game_GetCategoryShare(void *self,int arg1,int arg2)

{
  int value1;
  int value2;
  int *ptr3;
  int *ptr4;
  int value5;
  int local_18 [6];
  
  ptr4 = local_18;
  for (value5 = 6; value5 != 0; value5 = value5 + -1) {
    *ptr4 = 0;
    ptr4 = ptr4 + 1;
  }
  if (arg1 == -1) {
    value5 = 0;
    if (0 < *(int *)((intptr_t)self + 0x50)) {
      do {
        value2 = IDMap_Lookup((void *)((intptr_t)self + 0x3c),value5,(int *)0x0);
        if (*(int *)(value2 + 0x30) < 8) {
          ptr4 = local_18;
          ptr3 = (int *)(value2 + 0x14c);
          value2 = 6;
          do {
            value1 = *ptr3;
            ptr3 = ptr3 + 1;
            *ptr4 = *ptr4 + value1;
            ptr4 = ptr4 + 1;
            value2 = value2 + -1;
          } while (value2 != 0);
        }
        value5 = value5 + 1;
      } while (value5 < *(int *)((intptr_t)self + 0x50));
    }
  }
  else {
    value5 = 0;
    if (0 < *(int *)((intptr_t)self + 0x50)) {
      do {
        value2 = IDMap_Lookup((void *)((intptr_t)self + 0x3c),value5,(int *)0x0);
        if (*(int *)(value2 + 0x30) == arg1) {
          ptr4 = local_18;
          ptr3 = (int *)(value2 + 0x14c);
          value2 = 6;
          do {
            value1 = *ptr3;
            ptr3 = ptr3 + 1;
            *ptr4 = *ptr4 + value1;
            ptr4 = ptr4 + 1;
            value2 = value2 + -1;
          } while (value2 != 0);
        }
        value5 = value5 + 1;
      } while (value5 < *(int *)((intptr_t)self + 0x50));
    }
  }
  value5 = 0;
  ptr4 = local_18;
  value2 = 6;
  do {
    value1 = *ptr4;
    ptr4 = ptr4 + 1;
    value5 = value5 + value1;
    value2 = value2 + -1;
  } while (value2 != 0);
  if ((value5 == 0) || (local_18[arg2] == 0)) {
    return 0;
  }
  return (local_18[arg2] * 100) / value5;
}
