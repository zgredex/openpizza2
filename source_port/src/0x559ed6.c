// Unwind@00559ed6: ported from Pizza Connection 2 at 0x559ed6.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559ed6
#include "pc2_port.h"

void Unwind_00559ed6(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x110));
  return;
}
