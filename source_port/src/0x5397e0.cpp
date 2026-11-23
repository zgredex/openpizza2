// Color_RGBTo16: ported from Pizza Connection 2 at 0x5397e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5397e0
#include "pc2_port.h"

uint32_t __thiscall Color_RGBTo16(void *self,uint8_t arg1,uint8_t arg2,uint32_t arg3)

{
  if (*(char *)((intptr_t)self + 0x18) == '\0') {
    return ((arg1 & 0xf8) << 5 | arg2 & 0xf8) << 2 | (arg3 & 0xff) >> 3;
  }
  return ((arg1 & 0xf8) << 5 | arg2 & 0xf8) << 3 | (arg3 & 0xff) >> 3;
}
