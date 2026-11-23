// Stats_GetOrSumSeries: ported from Pizza Connection 2 at 0x4d3940.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d3940
#include "pc2_port.h"

int __thiscall Stats_GetOrSumSeries(void *self,int arg1,int arg2)

{
  int value1;
  int value2;
  int *ptr3;
  int value4;
  
  value2 = 0;
  if (arg2 != -1) {
    return *(int *)((intptr_t)self + (arg2 + arg1 * 100) * 4 + 0x44);
  }
  ptr3 = (int *)(arg1 * 400 + 0x44 + (intptr_t)self);
  value4 = 100;
  do {
    value1 = *ptr3;
    ptr3 = ptr3 + 1;
    value2 = value2 + value1;
    value4 = value4 + -1;
  } while (value4 != 0);
  return value2;
}
