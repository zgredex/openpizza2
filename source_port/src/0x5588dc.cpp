// Unwind@005588dc: ported from Pizza Connection 2 at 0x5588dc.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5588dc
#include "pc2_port.h"

void Unwind_005588dc(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 0x10));
  return;
}
