// FileObject_InitBase: ported from Pizza Connection 2 at 0x552385.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x552385
#include "pc2_port.h"

void __cdecl FileObject_InitBase(int arg1)

{
  *(uint8_t **)(arg1 + 0x50) = &DAT_00577040;
  *(uint32_t *)(arg1 + 0x14) = 1;
  return;
}
