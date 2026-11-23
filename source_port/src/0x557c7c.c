// Unwind@00557c7c: ported from Pizza Connection 2 at 0x557c7c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557c7c
#include "pc2_port.h"

void Unwind_00557c7c(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x134));
  return;
}
