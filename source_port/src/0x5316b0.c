// UI_ShowChildByID: ported from Pizza Connection 2 at 0x5316b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5316b0
#include "pc2_port.h"

uint32_t __thiscall UI_ShowChildByID(void *self,int arg1)

{
  int value1;
  
                    /* Finds a child by id and activates it. */
  value1 = BinarySearch8(self,arg1,'\0');
  if (value1 == -1) {
    return 0;
  }
  UI_Child_Activate(*(int *)(*(int *)((intptr_t)self + 0xe8) + value1 * 8));
  return 1;
}
