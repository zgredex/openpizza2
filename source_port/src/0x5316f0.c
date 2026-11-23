// UI_SetChildVisibleByID: ported from Pizza Connection 2 at 0x5316f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5316f0
#include "pc2_port.h"

uint32_t __thiscall UI_SetChildVisibleByID(void *self,int arg1,int arg2)

{
  int value1;
  
                    /* Shows or hides a child element by id. */
  value1 = BinarySearch8(self,arg1,'\0');
  if (value1 == -1) {
    return 0;
  }
  if (arg2 == 0) {
    UI_ClearPendingClipFlag(*(int *)(*(int *)((intptr_t)self + 0xe8) + value1 * 8));
    return 1;
  }
  UI_Child_Activate(*(int *)(*(int *)((intptr_t)self + 0xe8) + value1 * 8));
  return 1;
}
