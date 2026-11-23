// Array_GetField20ByKey: ported from Pizza Connection 2 at 0x531780.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x531780
#include "pc2_port.h"

uint32_t __thiscall Array_GetField20ByKey(void *self,int arg1)

{
  int value1;
  
  value1 = BinarySearch8(self,arg1,'\0');
  if (value1 == -1) {
    return 0;
  }
  return *(uint32_t *)(*(int *)(*(int *)((intptr_t)self + 0xe8) + value1 * 8) + 0x20);
}
