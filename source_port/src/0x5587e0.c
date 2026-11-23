// Unwind@005587e0: ported from Pizza Connection 2 at 0x5587e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5587e0
#include "pc2_port.h"

void Unwind_005587e0(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
