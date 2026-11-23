// Array_AreBothCountsPositive: ported from Pizza Connection 2 at 0x512700.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x512700
#include "pc2_port.h"

uint32_t __thiscall Array_AreBothCountsPositive(void *self,uint32_t arg1,uint32_t arg2)

{
  if ((*(int *)((intptr_t)self + (arg1 & 0xff) * 4 + 100) < 1) ||
     (*(int *)((intptr_t)self + (arg2 & 0xff) * 4 + 100) < 1)) {
    return 0;
  }
  return 1;
}
