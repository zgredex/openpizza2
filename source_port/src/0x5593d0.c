// Unwind@005593d0: ported from Pizza Connection 2 at 0x5593d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5593d0
#include "pc2_port.h"

void Unwind_005593d0(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
