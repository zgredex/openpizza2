// Unwind@0055a3fb: ported from Pizza Connection 2 at 0x55a3fb.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55a3fb
#include "pc2_port.h"

void Unwind_0055a3fb(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 8));
  return;
}
