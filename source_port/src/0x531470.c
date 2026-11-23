// Array_SetField14ByKey: ported from Pizza Connection 2 at 0x531470.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x531470
#include "pc2_port.h"

void __thiscall Array_SetField14ByKey(void *self,int arg1,uint32_t arg2)

{
  int value1;
  
  value1 = BinarySearch8(self,arg1,'\0');
  if (value1 != -1) {
    *(uint32_t *)(*(int *)(*(int *)((intptr_t)self + 0xe8) + value1 * 8) + 0x14) = arg2;
  }
  return;
}
