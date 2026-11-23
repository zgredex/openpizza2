// Unwind@00559dbf: ported from Pizza Connection 2 at 0x559dbf.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559dbf
#include "pc2_port.h"

void Unwind_00559dbf(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
