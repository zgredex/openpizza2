// Map_Get2DTableValue: ported from Pizza Connection 2 at 0x4ead90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ead90
#include "pc2_port.h"

uint32_t __thiscall Map_Get2DTableValue(void *self,int arg1,int arg2,int arg3)

{
  if (arg1 == 0) {
    return *(uint32_t *)((intptr_t)self + (arg2 * 0x30 + arg3) * 4 + 0x2bf4c);
  }
  if (arg1 == 1) {
    return *(uint32_t *)((intptr_t)self + (arg2 * 0x30 + arg3) * 4 + 0x2c234);
  }
  return 0;
}
