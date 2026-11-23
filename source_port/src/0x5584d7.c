// Unwind@005584d7: ported from Pizza Connection 2 at 0x5584d7.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5584d7
#include "pc2_port.h"

void Unwind_005584d7(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
