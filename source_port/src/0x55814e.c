// Unwind@0055814e: ported from Pizza Connection 2 at 0x55814e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55814e
#include "pc2_port.h"

void Unwind_0055814e(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
