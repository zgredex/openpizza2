// Array_RemoveValueLocked: ported from Pizza Connection 2 at 0x523050.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x523050
#include "pc2_port.h"

uint32_t __thiscall Array_RemoveValueLocked(void *self,int arg1)

{
  int value1;
  int *ptr2;
  
  CS_Enter(0x584180);
  value1 = 0;
  if (0 < *(int *)((intptr_t)self + 8)) {
    ptr2 = *(int **)((intptr_t)self + 4);
    do {
      if (*ptr2 == arg1) {
        Array_RemoveAt(self,value1);
        CS_Leave(0x584180);
        return 1;
      }
      value1 = value1 + 1;
      ptr2 = ptr2 + 1;
    } while (value1 < *(int *)((intptr_t)self + 8));
  }
  CS_Leave(0x584180);
  return 0;
}
