// UI_CenterChildVertically: ported from Pizza Connection 2 at 0x5315d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5315d0
#include "pc2_port.h"

uint32_t __thiscall UI_CenterChildVertically(void *self,int arg1,int arg2)

{
  void *this_00;
  int value1;
  
  value1 = BinarySearch8(self,arg1,'\0');
  if (value1 == -1) {
    return 0;
  }
  this_00 = *(void **)(*(int *)((intptr_t)self + 0xe8) + value1 * 8);
  UI_MoveChildToPosition
            (this_00,(((*(int *)((intptr_t)this_00 + 0x28) - *(int *)((intptr_t)this_00 + 0x30)) -
                      *(int *)((intptr_t)self + 0x18)) + *(int *)((intptr_t)self + 0x20)) / 2,arg2);
  return 1;
}
