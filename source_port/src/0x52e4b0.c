// Tooltip_Construct: ported from Pizza Connection 2 at 0x52e4b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52e4b0
#include "pc2_port.h"

uint32_t * __thiscall Tooltip_Construct(void *self,void *arg1,uint32_t arg2)

{
  uint32_t *uptr1;
  
  *(uint32_t *)((intptr_t)self + 0xc) = 10;
  *(uint32_t *)((intptr_t)self + 0x10) = 10;
  *(uint8_t ***)self = &PTR_UI_Tooltip_Delete_0055c804;
  *(uint32_t *)((intptr_t)self + 0x38) = arg2;
  *(uint32_t *)((intptr_t)self + 0x18) = 0;
  *(uint32_t *)((intptr_t)self + 4) = 0x50;
  *(uint32_t *)((intptr_t)self + 8) = 200;
  *(uint32_t *)((intptr_t)self + 0x14) = 0;
  *(uint32_t *)((intptr_t)self + 0x20) = 0;
  *(uint32_t *)((intptr_t)self + 0x24) = 0;
  *(uint32_t *)((intptr_t)self + 0x28) = 0xe0ffff;
  *(uint32_t *)((intptr_t)self + 0x2c) = 0;
  *(uint32_t *)((intptr_t)self + 0x30) = 0;
  *(uint32_t *)((intptr_t)self + 0x3c) = 0;
  uptr1 = Renderer_CreateChild(arg1);
  *(uint32_t **)((intptr_t)self + 0x1c) = uptr1;
  return self;
}
