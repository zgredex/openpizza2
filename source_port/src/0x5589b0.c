// Unwind@005589b0: ported from Pizza Connection 2 at 0x5589b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5589b0
#include "pc2_port.h"

void Unwind_005589b0(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
