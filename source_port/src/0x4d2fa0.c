// Map_SetObjectMode: ported from Pizza Connection 2 at 0x4d2fa0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d2fa0
#include "pc2_port.h"

void __thiscall Map_SetObjectMode(void *self,void *arg1,uint8_t arg2)

{
  uint32_t *uptr1;
  
  uptr1 = (uint32_t *)(*(int *)((intptr_t)arg1 + 0x4c) + *(int *)((intptr_t)self + 0x24) * 0xc);
  if (uptr1 != (uint32_t *)0x0) {
    *(uint8_t *)(uptr1[2] + 0x2c) = arg2;
    Map_RenderObject(arg1,uptr1,1);
  }
  return;
}
