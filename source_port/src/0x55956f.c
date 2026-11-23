// Unwind@0055956f: ported from Pizza Connection 2 at 0x55956f.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55956f
#include "pc2_port.h"

void Unwind_0055956f(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
