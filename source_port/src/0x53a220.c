// Sprite_InitFormat: ported from Pizza Connection 2 at 0x53a220.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53a220
#include "pc2_port.h"

void __thiscall
Sprite_InitFormat(void *self,short arg1,uint16_t arg2,uint32_t arg3,int arg4,
                 uint8_t arg5,uint16_t arg6,uint16_t arg7)

{
  short svalue1;
  
  *(uint16_t *)((intptr_t)self + 10) = arg6;
  *(char *)((intptr_t)self + 5) = (char)arg4;
  *(uint16_t *)((intptr_t)self + 0xc) = arg7;
  *(uint32_t *)((intptr_t)self + 0x18) = 0;
  svalue1 = (short)(arg4 >> 3) * arg1;
  *(uint8_t *)((intptr_t)self + 4) = arg5;
  *(uint32_t *)((intptr_t)self + 0x1c) = arg3;
  *(uint16_t *)((intptr_t)self + 8) = arg2;
  *(uint16_t *)((intptr_t)self + 0x14) = arg2;
  *(short *)((intptr_t)self + 6) = svalue1;
  *(short *)((intptr_t)self + 0x12) = svalue1;
  return;
}
