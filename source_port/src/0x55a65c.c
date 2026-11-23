// Unwind@0055a65c: ported from Pizza Connection 2 at 0x55a65c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55a65c
#include "pc2_port.h"

void Unwind_0055a65c(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 8));
  return;
}
