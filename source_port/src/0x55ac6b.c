// Unwind@0055ac6b: ported from Pizza Connection 2 at 0x55ac6b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55ac6b
#include "pc2_port.h"

void Unwind_0055ac6b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x3b0));
  return;
}
