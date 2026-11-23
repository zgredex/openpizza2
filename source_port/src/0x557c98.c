// Unwind@00557c98: ported from Pizza Connection 2 at 0x557c98.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557c98
#include "pc2_port.h"

void Unwind_00557c98(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x134));
  return;
}
