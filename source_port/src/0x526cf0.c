// Set_Field228: ported from Pizza Connection 2 at 0x526cf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x526cf0
#include "pc2_port.h"

void __thiscall Set_Field228(void *self,uint32_t arg1)

{
  *(uint32_t *)((intptr_t)self + 0x228) = arg1;
  return;
}
