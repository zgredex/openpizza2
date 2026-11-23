// Unwind@005599c1: ported from Pizza Connection 2 at 0x5599c1.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5599c1
#include "pc2_port.h"

void Unwind_005599c1(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
