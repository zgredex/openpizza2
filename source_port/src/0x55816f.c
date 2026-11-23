// Unwind@0055816f: ported from Pizza Connection 2 at 0x55816f.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55816f
#include "pc2_port.h"

void Unwind_0055816f(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
