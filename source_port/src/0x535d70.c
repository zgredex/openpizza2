// Palette_Init: ported from Pizza Connection 2 at 0x535d70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x535d70
#include "pc2_port.h"

int * __thiscall Palette_Init(void *self,int arg1,uint32_t *arg2,int arg3)

{
  uint32_t *uptr1;
  int value2;
  uint32_t local_300 [192];
  
  *(uint16_t *)((intptr_t)self + 0x206) = 0xffff;
  *(uint8_t *)((intptr_t)self + 0x208) = 0;
  if (arg3 == 0) {
    uptr1 = operator_new(0x300);
    *(uint32_t **)self = uptr1;
    for (value2 = 0xc0; value2 != 0; value2 = value2 + -1) {
      *uptr1 = *arg2;
      arg2 = arg2 + 1;
      uptr1 = uptr1 + 1;
    }
    Palette_Convert256(self,arg1);
    return self;
  }
  *(uint32_t **)self = local_300;
  uptr1 = local_300;
  for (value2 = 0xc0; value2 != 0; value2 = value2 + -1) {
    *uptr1 = *arg2;
    arg2 = arg2 + 1;
    uptr1 = uptr1 + 1;
  }
  Palette_Convert256(self,arg1);
  *(uint32_t *)self = 0;
  return self;
}
