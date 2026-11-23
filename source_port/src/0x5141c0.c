// StaffList_AddId: ported from Pizza Connection 2 at 0x5141c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5141c0
#include "pc2_port.h"

uint32_t __thiscall StaffList_AddId(void *self,int arg1)

{
  int value1;
  int *ptr2;
  
  value1 = Array_FindPair(self,arg1);
  if (value1 == -1) {
    value1 = 0;
    ptr2 = (int *)((intptr_t)self + 0x60);
    do {
      if (*ptr2 == 0) {
        *(int *)((intptr_t)self + value1 * 0xc + 100) = arg1;
        *(uint32_t *)((intptr_t)self + (value1 * 3 + 0x18) * 4) = 1;
        *(uint32_t *)((intptr_t)self + value1 * 0xc + 0x68) = 0;
        return 1;
      }
      value1 = value1 + 1;
      ptr2 = ptr2 + 3;
    } while (value1 < 0x14);
  }
  return 0;
}
