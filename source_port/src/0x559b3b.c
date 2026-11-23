// Unwind@00559b3b: ported from Pizza Connection 2 at 0x559b3b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559b3b
#include "pc2_port.h"

void Unwind_00559b3b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
