// Unwind@0055845b: ported from Pizza Connection 2 at 0x55845b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55845b
#include "pc2_port.h"

void Unwind_0055845b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
