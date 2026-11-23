// Unwind@00559b03: ported from Pizza Connection 2 at 0x559b03.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559b03
#include "pc2_port.h"

void Unwind_00559b03(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
