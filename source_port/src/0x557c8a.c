// Unwind@00557c8a: ported from Pizza Connection 2 at 0x557c8a.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557c8a
#include "pc2_port.h"

void Unwind_00557c8a(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x134));
  return;
}
