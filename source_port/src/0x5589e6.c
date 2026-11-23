// Unwind@005589e6: ported from Pizza Connection 2 at 0x5589e6.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5589e6
#include "pc2_port.h"

void Unwind_005589e6(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
