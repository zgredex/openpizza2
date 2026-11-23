// Unwind@00557c6e: ported from Pizza Connection 2 at 0x557c6e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557c6e
#include "pc2_port.h"

void Unwind_00557c6e(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x134));
  return;
}
