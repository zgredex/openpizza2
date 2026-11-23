// Unwind@0055ab4b: ported from Pizza Connection 2 at 0x55ab4b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55ab4b
#include "pc2_port.h"

void Unwind_0055ab4b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x20));
  return;
}
