// Record_SetField2D0C: ported from Pizza Connection 2 at 0x4f5770.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f5770
#include "pc2_port.h"

void __thiscall Record_SetField2D0C(void *self,int arg1,uint8_t arg2)

{
  int value1;
  
  value1 = *(int *)((intptr_t)self + 0x4c) + arg1 * 0xc;
  if ((value1 != 0) && (value1 = *(int *)(value1 + 8), value1 != 0)) {
    *(uint8_t *)(value1 + 0x2d) = arg2;
  }
  return;
}
