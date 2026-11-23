// Unwind@005592e2: ported from Pizza Connection 2 at 0x5592e2.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5592e2
#include "pc2_port.h"

void Unwind_005592e2(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
