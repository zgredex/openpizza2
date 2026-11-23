// Array_GetRecordByKey: ported from Pizza Connection 2 at 0x5313d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5313d0
#include "pc2_port.h"

uint32_t __thiscall Array_GetRecordByKey(void *self,int arg1)

{
  int value1;
  
  value1 = BinarySearch8(self,arg1,'\0');
  if (value1 == -1) {
    return 0;
  }
  return *(uint32_t *)(*(int *)((intptr_t)self + 0xe8) + value1 * 8);
}
