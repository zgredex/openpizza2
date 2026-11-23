// Unwind@005597ad: ported from Pizza Connection 2 at 0x5597ad.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5597ad
#include "pc2_port.h"

void Unwind_005597ad(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
