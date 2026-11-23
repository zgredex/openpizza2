// Unwind@005598b7: ported from Pizza Connection 2 at 0x5598b7.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5598b7
#include "pc2_port.h"

void Unwind_005598b7(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
