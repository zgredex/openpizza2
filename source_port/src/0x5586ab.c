// Unwind@005586ab: ported from Pizza Connection 2 at 0x5586ab.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5586ab
#include "pc2_port.h"

void Unwind_005586ab(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}
