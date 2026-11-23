// Unwind@00559070: ported from Pizza Connection 2 at 0x559070.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559070
#include "pc2_port.h"

void Unwind_00559070(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
