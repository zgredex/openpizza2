// Unwind@0055826b: ported from Pizza Connection 2 at 0x55826b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55826b
#include "pc2_port.h"

void Unwind_0055826b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
