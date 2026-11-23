// Map_ClearObjectFlags: ported from Pizza Connection 2 at 0x4d2d80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d2d80
#include "pc2_port.h"

void __thiscall Map_ClearObjectFlags(void *self,void *arg1,uint32_t arg2)

{
  uint32_t *uptr1;
  uint32_t uvalue2;
  
  CS_Enter(*(int *)(DAT_0057c670 + 0x240));
  uptr1 = (uint32_t *)(*(int *)((intptr_t)arg1 + 0x4c) + *(int *)((intptr_t)self + 0x24) * 0xc);
  if (uptr1 != (uint32_t *)0x0) {
    uvalue2 = *(uint32_t *)(uptr1[2] + 0x1c);
    if (uvalue2 == 0xffffffff) {
      CS_Leave(*(int *)(DAT_0057c670 + 0x240));
      return;
    }
    *(uint32_t *)(uptr1[2] + 0x1c) = ~arg2 & uvalue2;
    if (*(int *)(uptr1[2] + 0x1c) == 0) {
      *(uint32_t *)(uptr1[2] + 0x1c) = 0xffffffff;
    }
    Map_RenderObject(arg1,uptr1,1);
  }
  CS_Leave(*(int *)(DAT_0057c670 + 0x240));
  return;
}
