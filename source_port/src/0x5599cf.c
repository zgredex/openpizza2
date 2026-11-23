// Unwind@005599cf: ported from Pizza Connection 2 at 0x5599cf.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5599cf
#include "pc2_port.h"

void Unwind_005599cf(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
