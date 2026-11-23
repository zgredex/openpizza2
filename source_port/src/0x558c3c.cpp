// Unwind@00558c3c: ported from Pizza Connection 2 at 0x558c3c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558c3c
#include "pc2_port.h"

void Unwind_00558c3c(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
