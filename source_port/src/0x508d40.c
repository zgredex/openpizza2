// Object_ApplyPendingType: ported from Pizza Connection 2 at 0x508d40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x508d40
#include "pc2_port.h"

void __thiscall Object_ApplyPendingType(void *self,int arg1)

{
  if (arg1 != 0x23) {
    *(uint32_t *)((intptr_t)self + 0x30) = *(uint32_t *)((intptr_t)self + 0x78);
  }
  return;
}
