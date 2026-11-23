// Unwind@0055819b: ported from Pizza Connection 2 at 0x55819b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55819b
#include "pc2_port.h"

void Unwind_0055819b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
