// Surface_ConfigureFromOwner: ported from Pizza Connection 2 at 0x5377d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5377d0
#include "pc2_port.h"

void __thiscall Surface_ConfigureFromOwner(void *self,void *arg1)

{
  Surface_Configure(arg1,*(uint32_t *)((intptr_t)self + 0x18),(uint16_t)*(int *)((intptr_t)self + 4),
                    (uint16_t)*(uint32_t *)((intptr_t)self + 8),*(int *)((intptr_t)self + 4) * 2);
  return;
}
