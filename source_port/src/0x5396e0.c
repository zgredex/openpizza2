// Surface_Reset: ported from Pizza Connection 2 at 0x5396e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5396e0
#include "pc2_port.h"

void __fastcall Surface_Reset(int arg1)

{
  *(uint32_t *)(arg1 + 0xc) = 0;
  *(uint32_t *)(arg1 + 4) = 0;
  *(uint32_t *)(arg1 + 8) = (uint32_t)*(uint16_t *)(arg1 + 0x1a);
  *(uint32_t *)(arg1 + 0x10) = (uint32_t)*(uint16_t *)(arg1 + 0x1c);
  return;
}
