// Unwind@005586cb: ported from Pizza Connection 2 at 0x5586cb.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5586cb
#include "pc2_port.h"

void Unwind_005586cb(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
