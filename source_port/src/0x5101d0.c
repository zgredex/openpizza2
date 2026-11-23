// AI_CountPlanSteps: ported from Pizza Connection 2 at 0x5101d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5101d0
#include "pc2_port.h"

int __thiscall AI_CountPlanSteps(void *self,int arg1,int arg2,int arg3)

{
  int value1;
  int *ptr2;
  int value3;
  int *ptr4;
  int value5;
  int value6;
  int local_2c;
  int local_20 [8];
  
  value6 = 0;
  local_2c = 0;
  if (*(int *)((intptr_t)self + 0x304) == 0) {
    return 0;
  }
  value1 = *(int *)(*(int *)((intptr_t)self + 0x304) + 0x14);
  if (arg2 == 0) {
    value6 = 0;
    if (0 < value1) {
      do {
        ptr2 = (int *)IDMap_Lookup(*(void **)((intptr_t)self + 0x304),value6,(int *)0x0);
        if (((ptr2[4] == arg1) || (arg1 == -1)) &&
           ((arg3 == -1 || (ptr2[5] == arg3)))) {
          local_2c = local_2c + *ptr2;
        }
        value6 = value6 + 1;
      } while (value6 < value1);
      return local_2c;
    }
  }
  else {
    value5 = 0;
    value3 = 0;
    ptr2 = local_20;
    do {
      if (*(char *)(value3 + arg2) == '\x01') {
        *ptr2 = value3;
        value5 = value5 + 1;
        ptr2 = ptr2 + 1;
      }
      value3 = value3 + 1;
    } while (value3 < 8);
    if (0 < value1) {
      do {
        ptr2 = (int *)IDMap_Lookup(*(void **)((intptr_t)self + 0x304),value6,(int *)0x0);
        if (((ptr2[4] == arg1) || (arg1 == -1)) && (0 < value5)) {
          ptr4 = local_20;
          value3 = value5;
          do {
            if ((*ptr4 == ptr2[6]) && ((arg3 == -1 || (ptr2[5] == arg3)))) {
              local_2c = local_2c + *ptr2;
            }
            ptr4 = ptr4 + 1;
            value3 = value3 + -1;
          } while (value3 != 0);
        }
        value6 = value6 + 1;
      } while (value6 < value1);
    }
  }
  return local_2c;
}
