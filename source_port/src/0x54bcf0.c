// Window_ClearState: ported from Pizza Connection 2 at 0x54bcf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54bcf0
#include "pc2_port.h"

void __fastcall Window_ClearState(int arg1)

{
  *(uint32_t *)(arg1 + 0x1a8) = 0;
  *(uint32_t *)(arg1 + 4) = 0;
  return;
}
