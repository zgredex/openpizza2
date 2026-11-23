// UI_FindWindowByID: ported from Pizza Connection 2 at 0x528040.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x528040
#include "pc2_port.h"

int __thiscall UI_FindWindowByID(void *self,int arg1,int *arg2)

{
  int value1;
  int *ptr2;
  int value3;
  
  value3 = 0;
  if (0 < *(int *)((intptr_t)self + 0x23c)) {
    ptr2 = (int *)((intptr_t)self + 0x14);
    do {
      value1 = *ptr2;
      if ((value1 != 0) && (*(int *)(value1 + 4) == arg1)) {
        if (arg2 == (int *)0x0) {
          return value1;
        }
        *arg2 = value3;
        return value1;
      }
      value3 = value3 + 1;
      ptr2 = ptr2 + 1;
    } while (value3 < *(int *)((intptr_t)self + 0x23c));
  }
  if (arg2 != (int *)0x0) {
    *arg2 = -1;
  }
  return 0;
}
