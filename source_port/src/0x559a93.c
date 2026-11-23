// Unwind@00559a93: ported from Pizza Connection 2 at 0x559a93.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559a93
#include "pc2_port.h"

void Unwind_00559a93(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
