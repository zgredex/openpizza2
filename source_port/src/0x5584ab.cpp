// Unwind@005584ab: ported from Pizza Connection 2 at 0x5584ab.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5584ab
#include "pc2_port.h"

void Unwind_005584ab(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
