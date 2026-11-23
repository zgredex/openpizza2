// Unwind@005584fe: ported from Pizza Connection 2 at 0x5584fe.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5584fe
#include "pc2_port.h"

void Unwind_005584fe(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x110));
  return;
}
