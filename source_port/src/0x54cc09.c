// Stream_PutByte: ported from Pizza Connection 2 at 0x54cc09.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54cc09
#include "pc2_port.h"

uint32_t __thiscall Stream_PutByte(void *self,uint32_t arg1)

{
  uint32_t uvalue1;
  
  if (*(uint8_t **)((intptr_t)self + 0x1c) < *(uint8_t **)((intptr_t)self + 0x20)) {
    **(uint8_t **)((intptr_t)self + 0x1c) = (uint8_t)arg1;
    *(int *)((intptr_t)self + 0x1c) = *(int *)((intptr_t)self + 0x1c) + 1;
    uvalue1 = arg1 & 0xff;
  }
  else {
    uvalue1 = (**(code **)(*(int *)self + 0x1c))(arg1);
  }
  return uvalue1;
}
