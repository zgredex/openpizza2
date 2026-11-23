// Unwind@00559847: ported from Pizza Connection 2 at 0x559847.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559847
#include "pc2_port.h"

void Unwind_00559847(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
