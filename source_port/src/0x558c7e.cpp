// Unwind@00558c7e: ported from Pizza Connection 2 at 0x558c7e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x558c7e
#include "pc2_port.h"

void Unwind_00558c7e(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
