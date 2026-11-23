// Object_SetFieldA4Locked: ported from Pizza Connection 2 at 0x50e850.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50e850
#include "pc2_port.h"

void __thiscall Object_SetFieldA4Locked(void *self,uint32_t arg1)

{
  CS_Enter(*(int *)(DAT_0057c670 + 0x240));
  *(uint32_t *)((intptr_t)self + 0xa4) = arg1;
  CS_Leave(*(int *)(DAT_0057c670 + 0x240));
  return;
}
