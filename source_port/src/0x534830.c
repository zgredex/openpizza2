// Record_GetPairPositions: ported from Pizza Connection 2 at 0x534830.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x534830
#include "pc2_port.h"

void __thiscall Record_GetPairPositions(void *self,int arg1,int *arg2,uint32_t *arg3)

{
  int value1;
  int value2;
  int *ptr3;
  
  if ((-1 < arg1) && (arg1 < *(int *)((intptr_t)self + 0x48))) {
    value2 = arg1 * 0x48;
    ptr3 = (int *)(*(int *)((intptr_t)self + 0x4c) + value2);
    if (*ptr3 != -1) {
      *arg2 = ptr3[6];
      arg2[1] = ptr3[7];
      value1 = *(int *)((intptr_t)self + 0x4c);
      *arg3 = *(uint32_t *)(value1 + 0x20 + value2);
      arg3[1] = *(uint32_t *)(value1 + 0x24 + value2);
    }
  }
  return;
}
