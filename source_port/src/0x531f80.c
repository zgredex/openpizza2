// UI_ReleaseChildBufferByKey: ported from Pizza Connection 2 at 0x531f80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x531f80
#include "pc2_port.h"

void __thiscall UI_ReleaseChildBufferByKey(void *self,int arg1)

{
  int value1;
  
  value1 = BinarySearch8(self,arg1,'\0');
  if (value1 != -1) {
    Buffer_ReleaseField0C(*(int *)(*(int *)((intptr_t)self + 0xe8) + value1 * 8));
  }
  return;
}
