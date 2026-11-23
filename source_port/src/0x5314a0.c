// Array_GetPairByKey: ported from Pizza Connection 2 at 0x5314a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5314a0
#include "pc2_port.h"

uint32_t __thiscall
Array_GetPairByKey(void *self,int arg1,uint32_t *arg2,uint32_t *arg3)

{
  int value1;
  
  value1 = BinarySearch8(self,arg1,'\0');
  if (value1 == -1) {
    return 0;
  }
  *arg2 = *(uint32_t *)(*(int *)(*(int *)((intptr_t)self + 0xe8) + value1 * 8) + 0x38);
  *arg3 = *(uint32_t *)(*(int *)(*(int *)((intptr_t)self + 0xe8) + value1 * 8) + 0x3c);
  return 1;
}
