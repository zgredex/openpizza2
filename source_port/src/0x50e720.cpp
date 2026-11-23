// Object_SetFieldFC: ported from Pizza Connection 2 at 0x50e720.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50e720
#include "pc2_port.h"

void __thiscall Object_SetFieldFC(void *self,uint32_t arg1)

{
  *(uint32_t *)((intptr_t)self + 0xfc) = arg1;
  return;
}
