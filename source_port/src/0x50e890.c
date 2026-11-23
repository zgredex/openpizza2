// Object_SetState: ported from Pizza Connection 2 at 0x50e890.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50e890
#include "pc2_port.h"

void __thiscall Object_SetState(void *self,int arg1)

{
  CS_Enter(*(int *)(DAT_0057c670 + 0x240));
  *(int *)((intptr_t)self + 0x38) = arg1;
  if ((arg1 == 0x1f) || (arg1 == 0x2e)) {
    UI_DestroyChildObject((intptr_t)self);
    *(uint32_t *)((intptr_t)self + 0xc4) = 0;
  }
  CS_Leave(*(int *)(DAT_0057c670 + 0x240));
  return;
}
