// UI_FindNearestWindow: ported from Pizza Connection 2 at 0x532930.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x532930
#include "pc2_port.h"

int * __thiscall UI_FindNearestWindow(void *self,int arg1,int arg2,int *arg3)

{
  int value1;
  int *ptr2;
  int value3;
  int value4;
  int *ptr5;
  int value6;
  int local_8;
  
  value1 = *(int *)((intptr_t)self + 0x1c);
  ptr5 = (int *)0x0;
  value6 = arg1 - *(int *)((intptr_t)self + 0x18);
  local_8 = *(int *)((intptr_t)self + 0xf0) + -1;
  if (-1 < local_8) {
    do {
      ptr2 = *(int **)(*(int *)((intptr_t)self + 0xec) + local_8 * 8);
      if ((((ptr2[0x10] == 5) && (ptr2[8] != 0)) &&
          (value3 = (**(code **)(*ptr2 + 0xc))(0x2e,0,0), value3 == 0)) &&
         ((value3 = (**(code **)(*ptr2 + 0xc))(0x30,0,0), value3 != 0 &&
          ((value4 = (value6 - (ptr2[0xc] - ptr2[10]) / 2) - ptr2[10],
           value3 = ((arg2 - value1) - (ptr2[0xd] - ptr2[0xb]) / 2) - ptr2[0xb],
           value3 = value3 * value3 + value4 * value4, ptr5 == (int *)0x0 || (value3 < arg1)))))) {
        ptr5 = ptr2;
        arg1 = value3;
      }
      local_8 = local_8 + -1;
    } while (-1 < local_8);
    if (ptr5 != (int *)0x0) {
      *arg3 = arg1;
      return ptr5;
    }
  }
  *arg3 = 0;
  return (int *)0x0;
}
