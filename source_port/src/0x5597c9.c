// Unwind@005597c9: ported from Pizza Connection 2 at 0x5597c9.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5597c9
#include "pc2_port.h"

void Unwind_005597c9(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
