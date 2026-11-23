// Array_GetBoundsByKey: ported from Pizza Connection 2 at 0x5314f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5314f0
#include "pc2_port.h"

uint32_t __thiscall Array_GetBoundsByKey(void *self,int arg1,int *arg2)

{
  int value1;
  int value2;
  
  value2 = BinarySearch8(self,arg1,'\0');
  if (value2 == -1) {
    return 0;
  }
  *arg2 = *(int *)(*(int *)(*(int *)((intptr_t)self + 0xe8) + value2 * 8) + 0x28);
  arg2[1] = *(int *)(*(int *)(*(int *)((intptr_t)self + 0xe8) + value2 * 8) + 0x2c);
  value1 = *(int *)(*(int *)((intptr_t)self + 0xe8) + value2 * 8);
  arg2[2] = (*(int *)(value1 + 0x30) - *(int *)(value1 + 0x28)) + *arg2;
  value2 = *(int *)(*(int *)((intptr_t)self + 0xe8) + value2 * 8);
  arg2[3] = (*(int *)(value2 + 0x34) - *(int *)(value2 + 0x2c)) + arg2[1];
  return 1;
}
