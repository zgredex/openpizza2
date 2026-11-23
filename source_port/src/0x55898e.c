// Unwind@0055898e: ported from Pizza Connection 2 at 0x55898e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55898e
#include "pc2_port.h"

void Unwind_0055898e(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x110));
  return;
}
