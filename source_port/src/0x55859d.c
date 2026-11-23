// Unwind@0055859d: ported from Pizza Connection 2 at 0x55859d.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55859d
#include "pc2_port.h"

void Unwind_0055859d(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 0x10));
  return;
}
