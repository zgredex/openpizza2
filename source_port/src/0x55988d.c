// Unwind@0055988d: ported from Pizza Connection 2 at 0x55988d.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55988d
#include "pc2_port.h"

void Unwind_0055988d(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
