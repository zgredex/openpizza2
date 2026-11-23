// ThreadSync_Clear: ported from Pizza Connection 2 at 0x4dd4e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dd4e0
#include "pc2_port.h"

void __fastcall ThreadSync_Clear(int arg1)

{
  *(uint32_t *)(arg1 + 0x1c) = 0;
  return;
}
