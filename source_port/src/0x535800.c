// Text_DrawCharAdvance: ported from Pizza Connection 2 at 0x535800.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x535800
#include "pc2_port.h"

void __thiscall Text_DrawCharAdvance(void *self,void *arg1,char arg2)

{
  uint8_t *bptr1;
  uint32_t local_4;
  
  if ((arg2 == '\n') || (arg2 == '\r')) {
    *(uint32_t *)((intptr_t)self + 0x9a0) = 0;
    *(int *)((intptr_t)self + 0x9a4) = *(int *)((intptr_t)self + 0x9a4) + *(int *)((intptr_t)self + 0x9b0);
    return;
  }
  local_4 = (uint32_t)(uint8_t)(arg2 - 0x20);
  if ((local_4 < 0xe0) &&
     (bptr1 = *(uint8_t **)((intptr_t)self + local_4 * 4 + 0x460), bptr1 != (uint8_t *)0x0)) {
    Font_DrawGlyphClipped
              (self,arg1,bptr1,(uint32_t)*(uint8_t *)(local_4 + (intptr_t)self),
               (uint32_t)*(uint8_t *)(local_4 + 0xe0 + (intptr_t)self),
               (uint32_t)*(uint8_t *)(local_4 + 0x2a0 + (intptr_t)self),
               (uint32_t)*(uint8_t *)(local_4 + 0x380 + (intptr_t)self));
    *(uint32_t *)((intptr_t)self + 0x9a0) =
         *(int *)((intptr_t)self + 0x9a0) + (uint32_t)*(uint8_t *)(local_4 + 0x1c0 + (intptr_t)self);
    return;
  }
  *(uint32_t *)((intptr_t)self + 0x9a0) = *(int *)((intptr_t)self + 0x9a0) + (uint32_t)*(uint8_t *)((intptr_t)self + 0x1c0);
  return;
}
