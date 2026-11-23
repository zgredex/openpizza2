// Unwind@00558c5d: ported from Pizza Connection 2 at 0x558c5d.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558c5d
#include "pc2_port.h"

void Unwind_00558c5d(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
