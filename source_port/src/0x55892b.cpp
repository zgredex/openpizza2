// Unwind@0055892b: ported from Pizza Connection 2 at 0x55892b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55892b
#include "pc2_port.h"

void Unwind_0055892b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 0x10));
  return;
}
