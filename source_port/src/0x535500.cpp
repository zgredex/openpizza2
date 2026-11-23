// Set_Field9B8: ported from Pizza Connection 2 at 0x535500.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x535500
#include "pc2_port.h"

void __thiscall Set_Field9B8(void *self,uint32_t arg1)

{
  *(uint32_t *)((intptr_t)self + 0x9b8) = arg1;
  return;
}
