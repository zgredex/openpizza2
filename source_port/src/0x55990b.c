// Unwind@0055990b: ported from Pizza Connection 2 at 0x55990b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55990b
#include "pc2_port.h"

void Unwind_0055990b(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
