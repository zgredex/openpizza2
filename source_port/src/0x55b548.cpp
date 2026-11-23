// Unwind@0055b548: ported from Pizza Connection 2 at 0x55b548.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55b548
#include "pc2_port.h"

void Unwind_0055b548(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 8));
  return;
}
