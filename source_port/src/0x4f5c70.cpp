// Object_SetShort28: ported from Pizza Connection 2 at 0x4f5c70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f5c70
#include "pc2_port.h"

void __thiscall Object_SetShort28(void *self,uint16_t arg1)

{
  *(uint16_t *)((intptr_t)self + 0x28) = arg1;
  return;
}
