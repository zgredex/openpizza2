// Unwind@00559dcd: ported from Pizza Connection 2 at 0x559dcd.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559dcd
#include "pc2_port.h"

void Unwind_00559dcd(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
