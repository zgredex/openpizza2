// Unwind@0055ad30: ported from Pizza Connection 2 at 0x55ad30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55ad30
#include "pc2_port.h"

void Unwind_0055ad30(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
