// Object_Reset108: ported from Pizza Connection 2 at 0x50e840.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50e840
#include "pc2_port.h"

void __fastcall Object_Reset108(int arg1)

{
  *(uint32_t *)(arg1 + 0x108) = 0xffffffff;
  *(uint32_t *)(arg1 + 0x8c) = 0xffffffff;
  return;
}
