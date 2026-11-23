// Unwind@00559e9e: ported from Pizza Connection 2 at 0x559e9e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x559e9e
#include "pc2_port.h"

void Unwind_00559e9e(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x120));
  return;
}
