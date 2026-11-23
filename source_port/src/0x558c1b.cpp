// Unwind@00558c1b: ported from Pizza Connection 2 at 0x558c1b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558c1b
#include "pc2_port.h"

void Unwind_00558c1b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
