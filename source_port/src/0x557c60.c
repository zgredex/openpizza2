// Unwind@00557c60: ported from Pizza Connection 2 at 0x557c60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557c60
#include "pc2_port.h"

void Unwind_00557c60(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x134));
  return;
}
