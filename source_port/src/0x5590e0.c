// Unwind@005590e0: ported from Pizza Connection 2 at 0x5590e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5590e0
#include "pc2_port.h"

void Unwind_005590e0(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x20));
  return;
}
