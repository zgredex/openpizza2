// Unwind@005592ed: ported from Pizza Connection 2 at 0x5592ed.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5592ed
#include "pc2_port.h"

void Unwind_005592ed(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
