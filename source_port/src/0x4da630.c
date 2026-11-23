// Array_GetStride60: ported from Pizza Connection 2 at 0x4da630.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4da630
#include "pc2_port.h"

int __thiscall Array_GetStride60(void *self,int arg1)

{
  if (arg1 < 0) {
    return 0;
  }
  return arg1 * 0x60 + 0xdc8 + (intptr_t)self;
}
