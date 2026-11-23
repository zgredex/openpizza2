// ThreadSync_Signal: ported from Pizza Connection 2 at 0x4dd4d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dd4d0
#include "pc2_port.h"

void __fastcall ThreadSync_Signal(int arg1)

{
  *(uint32_t *)(arg1 + 0x1c) = 1;
  return;
}
