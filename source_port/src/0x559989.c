// Unwind@00559989: ported from Pizza Connection 2 at 0x559989.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559989
#include "pc2_port.h"

void Unwind_00559989(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
