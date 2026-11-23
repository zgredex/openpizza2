// UI_SetObjectRangeByKey: ported from Pizza Connection 2 at 0x531400.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x531400
#include "pc2_port.h"

uint32_t __thiscall UI_SetObjectRangeByKey(void *self,int arg1,int arg2,int arg3)

{
  int value1;
  
  CS_Enter(*(int *)(*(int *)((intptr_t)self + 0x134) + 0x1c8));
  value1 = BinarySearch8(self,arg1,'\0');
  if (value1 == -1) {
    CS_Leave(*(int *)(*(int *)((intptr_t)self + 0x134) + 0x1c8));
    return 0;
  }
  UI_MoveChildToPosition(*(void **)(*(int *)((intptr_t)self + 0xe8) + value1 * 8),arg2,arg3);
  CS_Leave(*(int *)(*(int *)((intptr_t)self + 0x134) + 0x1c8));
  return 1;
}
