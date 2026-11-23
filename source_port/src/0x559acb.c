// Unwind@00559acb: ported from Pizza Connection 2 at 0x559acb.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559acb
#include "pc2_port.h"

void Unwind_00559acb(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
