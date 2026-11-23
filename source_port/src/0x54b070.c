// MessageList_FindFreeSlot: ported from Pizza Connection 2 at 0x54b070.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54b070
#include "pc2_port.h"

int __thiscall MessageList_FindFreeSlot(void *self,int *arg1)

{
  int value1;
  int *ptr2;
  int value3;
  int value4;
  int value5;
  int local_24 [9];
  
  ptr2 = local_24;
  for (value3 = 9; value3 != 0; value3 = value3 + -1) {
    *ptr2 = 0;
    ptr2 = ptr2 + 1;
  }
  value5 = 0;
  *arg1 = *(int *)((intptr_t)self + 0x20);
  value3 = *(int *)((intptr_t)self + 0x18);
  if (0 < value3) {
    do {
      value1 = IDMap_Lookup((void *)((intptr_t)self + 4),value5,(int *)0x0);
      if (*(int *)(value1 + 8) != -1) {
        value4 = *(int *)(value1 + 8) - *(int *)((intptr_t)self + 0x2c);
        if ((-1 < value4) && (value4 < 9)) {
          local_24[value4] = 1;
        }
        value1 = *(int *)(value1 + 0xc) + *(int *)((intptr_t)self + 0x28);
        if (*arg1 < value1) {
          *arg1 = value1;
        }
      }
      value5 = value5 + 1;
    } while (value5 < value3);
  }
  value3 = 0;
  ptr2 = local_24;
  do {
    if (*ptr2 == 0) {
      return *(int *)((intptr_t)self + 0x2c) + value3;
    }
    value3 = value3 + 1;
    ptr2 = ptr2 + 1;
  } while (value3 < 9);
  return -1;
}
