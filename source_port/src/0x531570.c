// Array_GetRectByKey: ported from Pizza Connection 2 at 0x531570.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x531570
#include "pc2_port.h"

uint32_t __thiscall Array_GetRectByKey(void *self,int arg1,int *arg2,int *arg3)

{
  int value1;
  int value2;
  
  value2 = BinarySearch8(self,arg1,'\0');
  if (value2 == -1) {
    return 0;
  }
  value1 = *(int *)(*(int *)((intptr_t)self + 0xe8) + value2 * 8);
  *arg2 = *(int *)(value1 + 0x30) - *(int *)(value1 + 0x28);
  value2 = *(int *)(*(int *)((intptr_t)self + 0xe8) + value2 * 8);
  *arg3 = *(int *)(value2 + 0x34) - *(int *)(value2 + 0x2c);
  return 1;
}
