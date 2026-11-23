// Employee_NextSpriteVariant: ported from Pizza Connection 2 at 0x549930.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x549930
#include "pc2_port.h"

uint8_t * __thiscall Employee_NextSpriteVariant(void *self,int arg1,int arg2,int arg3)

{
  int value1;
  uint8_t *uptr2;
  
  value1 = *(int *)((intptr_t)self + arg1 * 4 + 0x1dc);
  if (arg2 < arg3) {
    if (value1 != arg3) {
      arg2 = value1 + 1;
    }
    *(int *)((intptr_t)self + arg1 * 4 + 0x1dc) = arg2;
  }
  if ((value1 == 1) || (uptr2 = &DAT_005762b4, value1 != 2)) {
    uptr2 = &DAT_005762b0;
  }
  return uptr2;
}
