// Unwind@005599a5: ported from Pizza Connection 2 at 0x5599a5.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5599a5
#include "pc2_port.h"

void Unwind_005599a5(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
