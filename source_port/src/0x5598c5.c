// Unwind@005598c5: ported from Pizza Connection 2 at 0x5598c5.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5598c5
#include "pc2_port.h"

void Unwind_005598c5(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
