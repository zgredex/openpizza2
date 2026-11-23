// Unwind@00559ca7: ported from Pizza Connection 2 at 0x559ca7.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559ca7
#include "pc2_port.h"

void Unwind_00559ca7(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
