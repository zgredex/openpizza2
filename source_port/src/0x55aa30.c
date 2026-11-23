// Unwind@0055aa30: ported from Pizza Connection 2 at 0x55aa30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55aa30
#include "pc2_port.h"

void Unwind_0055aa30(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
