// Unwind@005583c0: ported from Pizza Connection 2 at 0x5583c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5583c0
#include "pc2_port.h"

void Unwind_005583c0(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x50));
  return;
}
