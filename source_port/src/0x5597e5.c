// Unwind@005597e5: ported from Pizza Connection 2 at 0x5597e5.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5597e5
#include "pc2_port.h"

void Unwind_005597e5(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
