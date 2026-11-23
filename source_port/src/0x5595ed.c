// Unwind@005595ed: ported from Pizza Connection 2 at 0x5595ed.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5595ed
#include "pc2_port.h"

void Unwind_005595ed(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
