// Unwind@0055941b: ported from Pizza Connection 2 at 0x55941b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55941b
#include "pc2_port.h"

void Unwind_0055941b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
