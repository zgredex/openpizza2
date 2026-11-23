// UI_ClampScrollY: ported from Pizza Connection 2 at 0x4ed360.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ed360
#include "pc2_port.h"

bool __thiscall UI_ClampScrollY(void *self,int arg1)

{
  int value1;
  int value2;
  
  value1 = *(int *)((intptr_t)self + 0xe8);
  value2 = *(int *)((intptr_t)self + 0x1016c) + *(int *)((intptr_t)self + 0x2c);
  *(int *)((intptr_t)self + 0xe8) = arg1;
  if (arg1 < value2) {
    *(int *)((intptr_t)self + 0xe8) = value2;
  }
  value2 = *(int *)((intptr_t)self + 0x34) - *(int *)((intptr_t)self + 0x10168);
  if (value2 < *(int *)((intptr_t)self + 0xe8)) {
    *(int *)((intptr_t)self + 0xe8) = value2;
  }
  return value1 != *(int *)((intptr_t)self + 0xe8);
}
