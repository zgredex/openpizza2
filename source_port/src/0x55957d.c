// Unwind@0055957d: ported from Pizza Connection 2 at 0x55957d.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55957d
#include "pc2_port.h"

void Unwind_0055957d(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
