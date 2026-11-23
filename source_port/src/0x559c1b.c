// Unwind@00559c1b: ported from Pizza Connection 2 at 0x559c1b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559c1b
#include "pc2_port.h"

void Unwind_00559c1b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
