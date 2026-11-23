// Unwind@0055ac79: ported from Pizza Connection 2 at 0x55ac79.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55ac79
#include "pc2_port.h"

void Unwind_0055ac79(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x3b0));
  return;
}
