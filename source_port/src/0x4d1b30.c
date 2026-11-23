// RecipeTopping_StreamConstruct: ported from Pizza Connection 2 at 0x4d1b30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d1b30
#include "pc2_port.h"

uint32_t * __thiscall RecipeTopping_StreamConstruct(void *self,void *arg1)

{
  *(uint8_t ***)self = &PTR_RecipeTopping_Delete_0055c4e8;
  if (arg1 == (void *)0x0) {
    *(uint32_t *)((intptr_t)self + 8) = 0xffffffff;
    *(uint32_t *)((intptr_t)self + 0xc) = 0xffffffff;
    *(uint32_t *)((intptr_t)self + 0x14) = 0xffffffff;
    *(uint32_t *)((intptr_t)self + 0x18) = 0xffffffff;
    *(uint8_t *)((intptr_t)self + 4) = 0xff;
    *(uint8_t *)((intptr_t)self + 5) = 0xff;
    *(uint8_t *)((intptr_t)self + 6) = 0xff;
    *(uint8_t *)((intptr_t)self + 0x10) = 0xff;
    *(uint8_t *)((intptr_t)self + 0x11) = 0;
    return self;
  }
  RecipeTopping_Load(self,arg1);
  return self;
}
