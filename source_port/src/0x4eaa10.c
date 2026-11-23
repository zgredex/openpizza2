// Game_GetMapValue: ported from Pizza Connection 2 at 0x4eaa10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4eaa10
#include "pc2_port.h"

uint32_t __thiscall Game_GetMapValue(void *self,uint32_t arg1)

{
  if ((arg1 != 0xffffffff) && (arg1 != 0xfffffffe)) {
    if (-1 < (intptr_t)arg1) {
      return (uint32_t)*(uint16_t *)((intptr_t)self + arg1 * 2 + 0x2e4f4);
    }
    arg1 = 0xffffffff;
  }
  return arg1;
}
