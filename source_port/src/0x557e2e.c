// Unwind@00557e2e: ported from Pizza Connection 2 at 0x557e2e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557e2e
#include "pc2_port.h"

void Unwind_00557e2e(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 8));
  return;
}
