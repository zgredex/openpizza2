// Clear_Field228: ported from Pizza Connection 2 at 0x526d00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x526d00
#include "pc2_port.h"

void __fastcall Clear_Field228(int arg1)

{
  *(uint32_t *)(arg1 + 0x228) = 0;
  return;
}
