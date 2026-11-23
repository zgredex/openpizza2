// Unwind@00557c40: ported from Pizza Connection 2 at 0x557c40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557c40
#include "pc2_port.h"

void Unwind_00557c40(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
