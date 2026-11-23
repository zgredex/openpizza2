// Unwind@005588e7: ported from Pizza Connection 2 at 0x5588e7.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5588e7
#include "pc2_port.h"

void Unwind_005588e7(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 0x10));
  return;
}
