// Memory_FreeField4: ported from Pizza Connection 2 at 0x54c7d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54c7d0
#include "pc2_port.h"

void __fastcall Memory_FreeField4(int arg1)

{
  Memory_FreeAndClear((uint32_t *)(arg1 + 4));
  return;
}
