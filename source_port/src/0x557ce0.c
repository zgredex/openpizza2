// Unwind@00557ce0: ported from Pizza Connection 2 at 0x557ce0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557ce0
#include "pc2_port.h"

void Unwind_00557ce0(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x134));
  return;
}
