// Unwind@0055931b: ported from Pizza Connection 2 at 0x55931b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55931b
#include "pc2_port.h"

void Unwind_0055931b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x14));
  return;
}
