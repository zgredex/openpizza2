// Unwind@00559d5d: ported from Pizza Connection 2 at 0x559d5d.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559d5d
#include "pc2_port.h"

void Unwind_00559d5d(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
