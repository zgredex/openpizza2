// Array_ToggleObjectActive: ported from Pizza Connection 2 at 0x531620.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x531620
#include "pc2_port.h"

uint32_t __thiscall Array_ToggleObjectActive(void *self,int arg1,int arg2)

{
  int value1;
  
  value1 = BinarySearch8(self,arg1,'\0');
  if (value1 == -1) {
    return 0;
  }
  if (arg2 == 0) {
    UI_ClearPendingCommand(*(int **)(*(int *)((intptr_t)self + 0xe8) + value1 * 8));
    return 1;
  }
  Object_EnsureInit(*(int **)(*(int *)((intptr_t)self + 0xe8) + value1 * 8));
  return 1;
}
