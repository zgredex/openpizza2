// Unwind@0055a1c0: ported from Pizza Connection 2 at 0x55a1c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55a1c0
#include "pc2_port.h"

void Unwind_0055a1c0(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 8));
  return;
}
