// Font_GetCharWidth: ported from Pizza Connection 2 at 0x535650.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x535650
#include "pc2_port.h"

uint8_t __thiscall Font_GetCharWidth(void *self,uint32_t arg1)

{
  int value1;
  
  value1 = (arg1 & 0xff) - 0x20;
  if (((value1 < 0) || (0xdf < value1)) || (*(int *)((intptr_t)self + value1 * 4 + 0x460) == 0)) {
    return 0;
  }
  return *(uint8_t *)((arg1 & 0xff) + 0x1a0 + (intptr_t)self);
}
