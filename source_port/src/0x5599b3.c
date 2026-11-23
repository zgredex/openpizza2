// Unwind@005599b3: ported from Pizza Connection 2 at 0x5599b3.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5599b3
#include "pc2_port.h"

void Unwind_005599b3(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
