// Unwind@00559530: ported from Pizza Connection 2 at 0x559530.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559530
#include "pc2_port.h"

void Unwind_00559530(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x14));
  return;
}
