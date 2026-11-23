// UI_RemoveObjectByKey: ported from Pizza Connection 2 at 0x531740.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x531740
#include "pc2_port.h"

uint32_t __thiscall UI_RemoveObjectByKey(void *self,int arg1)

{
  int value1;
  
  value1 = BinarySearch8(self,arg1,'\0');
  if (value1 == -1) {
    return 0;
  }
  UI_ClearPendingClipFlag(*(int *)(*(int *)((intptr_t)self + 0xe8) + value1 * 8));
  *(uint32_t *)((intptr_t)self + 0xe0) = 1;
  return 1;
}
