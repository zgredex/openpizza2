// Unwind@0055823e: ported from Pizza Connection 2 at 0x55823e.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55823e
#include "pc2_port.h"

void Unwind_0055823e(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x1c0));
  return;
}
