// Unwind@005582a2: ported from Pizza Connection 2 at 0x5582a2.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5582a2
#include "pc2_port.h"

void Unwind_005582a2(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
