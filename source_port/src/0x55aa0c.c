// Unwind@0055aa0c: ported from Pizza Connection 2 at 0x55aa0c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55aa0c
#include "pc2_port.h"

void Unwind_0055aa0c(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 0x14));
  return;
}
