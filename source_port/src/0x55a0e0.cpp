// Unwind@0055a0e0: ported from Pizza Connection 2 at 0x55a0e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55a0e0
#include "pc2_port.h"

void Unwind_0055a0e0(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 0xc));
  return;
}
