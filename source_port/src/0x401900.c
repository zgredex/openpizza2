// Map_FindIndex: ported from Pizza Connection 2 at 0x401900.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x401900
#include "pc2_port.h"

int __thiscall Map_FindIndex(void *self,int arg1)

{
  int value1;
  int *ptr2;
  
  value1 = 0;
  if (0 < *(int *)((intptr_t)self + 0xc)) {
    ptr2 = *(int **)((intptr_t)self + 4);
    do {
      if (*ptr2 == arg1) {
        return value1;
      }
      value1 = value1 + 1;
      ptr2 = ptr2 + 1;
    } while (value1 < *(int *)((intptr_t)self + 0xc));
  }
  return -1;
}
