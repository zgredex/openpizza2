// Dialog_InitBase: ported from Pizza Connection 2 at 0x52ee10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52ee10
#include "pc2_port.h"

void __thiscall Dialog_InitBase(void *self,void *arg1,uint32_t arg2,uint32_t arg3)

{
  uint32_t *uptr1;
  
  *(uint32_t *)((intptr_t)self + 4) = 0;
  *(uint32_t *)((intptr_t)self + 0x2c0) = 0;
  *(uint32_t *)((intptr_t)self + 0x29c) = 0;
  *(uint32_t *)((intptr_t)self + 0xd8) = 0;
  *(uint32_t *)((intptr_t)self + 700) = 0;
  *(uint32_t *)((intptr_t)self + 0x13c) = 0;
  *(uint32_t *)((intptr_t)self + 0xf8) = 0;
  *(uint32_t *)((intptr_t)self + 0x16c) = 0;
  *(uint32_t *)((intptr_t)self + 0x48) = arg3;
  *(uint32_t *)((intptr_t)self + 0xe4) = 1;
  *(uint32_t *)((intptr_t)self + 0x4c) = 0;
  *(uint32_t *)((intptr_t)self + 0x15c) = 0;
  *(uint32_t *)((intptr_t)self + 0x10c) = 0;
  *(uint32_t *)((intptr_t)self + 0x164) = 1;
  *(uint8_t *)((intptr_t)self + 0x178) = 0;
  *(uint32_t *)((intptr_t)self + 0x50) = 0;
  *(uint32_t *)((intptr_t)self + 0x94) = 0;
  *(uint8_t *)((intptr_t)self + 0x54) = 0;
  *(uint32_t *)((intptr_t)self + 0x160) = 0;
  *(uint32_t *)((intptr_t)self + 0xe0) = 1;
  *(uint32_t *)((intptr_t)self + 0xec) = 0;
  *(uint32_t *)((intptr_t)self + 0x170) = 0;
  *(uint32_t *)((intptr_t)self + 0x134) = arg2;
  *(uint32_t *)((intptr_t)self + 0x114) = 0;
  *(uint32_t *)((intptr_t)self + 0xf0) = 0;
  *(uint32_t *)((intptr_t)self + 0xf4) = 0;
  *(uint32_t *)((intptr_t)self + 0xe8) = 0;
  *(uint32_t *)((intptr_t)self + 0x27c) = 0;
  *(uint32_t *)((intptr_t)self + 0x284) = 0;
  *(uint32_t *)((intptr_t)self + 0x28c) = 0;
  *(uint32_t *)((intptr_t)self + 0x168) = 0;
  *(uint32_t *)((intptr_t)self + 0x174) = 0;
  uptr1 = Renderer_CreateChild(arg1);
  *(uint32_t **)((intptr_t)self + 0xdc) = uptr1;
  *(uint32_t *)((intptr_t)self + 0x138) = 0;
  *(uint32_t *)((intptr_t)self + 0x298) = 0;
  SetRect((LPRECT)((intptr_t)self + 0x38),-999,0,0,0);
  *(uint32_t *)((intptr_t)self + 0xfc) = 0xff000000;
  *(uint32_t *)((intptr_t)self + 0x100) = 0xff000000;
  *(uint32_t *)((intptr_t)self + 0x104) = 0xff000000;
  *(uint32_t *)((intptr_t)self + 0x108) = 0xff000000;
  return;
}
