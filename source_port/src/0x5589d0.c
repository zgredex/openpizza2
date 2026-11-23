// Unwind@005589d0: ported from Pizza Connection 2 at 0x5589d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5589d0
#include "pc2_port.h"

void Unwind_005589d0(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
