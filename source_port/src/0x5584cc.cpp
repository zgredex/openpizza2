// Unwind@005584cc: ported from Pizza Connection 2 at 0x5584cc.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5584cc
#include "pc2_port.h"

void Unwind_005584cc(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 4));
  return;
}
