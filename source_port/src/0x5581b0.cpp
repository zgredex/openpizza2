// Unwind@005581b0: ported from Pizza Connection 2 at 0x5581b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5581b0
#include "pc2_port.h"

void Unwind_005581b0(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x48));
  return;
}
