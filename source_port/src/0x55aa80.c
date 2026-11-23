// Unwind@0055aa80: ported from Pizza Connection 2 at 0x55aa80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55aa80
#include "pc2_port.h"

void Unwind_0055aa80(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
