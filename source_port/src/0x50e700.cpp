// Set_Field168: ported from Pizza Connection 2 at 0x50e700.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50e700
#include "pc2_port.h"

void __thiscall Set_Field168(void *self,uint32_t arg1)

{
  *(uint32_t *)((intptr_t)self + 0x168) = arg1;
  return;
}
