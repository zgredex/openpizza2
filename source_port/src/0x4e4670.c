// Value_Approach: ported from Pizza Connection 2 at 0x4e4670.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e4670
#include "pc2_port.h"

void __thiscall Value_Approach(void *self,double arg1,double arg2)

{
  double dVar1;
  
  if (arg2 <= 0.0) {
    if (0.0 <= arg2) {
      return;
    }
    if (*(double *)((intptr_t)self + 0x10) <= arg2) {
      return;
    }
    dVar1 = arg1 + *(double *)((intptr_t)self + 0x10);
    *(double *)((intptr_t)self + 0x10) = dVar1;
    if (dVar1 < arg2) {
      *(double *)((intptr_t)self + 0x10) = arg2;
      *(uint8_t *)((intptr_t)self + 0x1c) = 1;
      return;
    }
  }
  else {
    if (arg2 <= *(double *)((intptr_t)self + 0x10)) {
      return;
    }
    dVar1 = arg1 + *(double *)((intptr_t)self + 0x10);
    *(double *)((intptr_t)self + 0x10) = dVar1;
    if (arg2 < dVar1) {
      *(double *)((intptr_t)self + 0x10) = arg2;
      *(uint8_t *)((intptr_t)self + 0x1c) = 1;
      return;
    }
  }
  *(uint8_t *)((intptr_t)self + 0x1c) = 1;
  return;
}
