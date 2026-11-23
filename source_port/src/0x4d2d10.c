// Map_SetObjectFlags: ported from Pizza Connection 2 at 0x4d2d10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d2d10
#include "pc2_port.h"

void __thiscall Map_SetObjectFlags(void *self,void *arg1,uint32_t arg2)

{
  uint32_t *uptr1;
  
  CS_Enter(*(int *)(DAT_0057c670 + 0x240));
  uptr1 = (uint32_t *)(*(int *)((intptr_t)arg1 + 0x4c) + *(int *)((intptr_t)self + 0x24) * 0xc);
  if (uptr1 != (uint32_t *)0x0) {
    if (*(int *)(uptr1[2] + 0x1c) == -1) {
      *(uint32_t *)(uptr1[2] + 0x1c) = 0;
    }
    *(uint32_t *)(uptr1[2] + 0x1c) = *(uint32_t *)(uptr1[2] + 0x1c) | arg2;
    if (arg2 == 1) {
      *(uint8_t *)(uptr1[2] + 0x2c) = 0;
    }
    Map_RenderObject(arg1,uptr1,1);
  }
  CS_Leave(*(int *)(DAT_0057c670 + 0x240));
  return;
}
