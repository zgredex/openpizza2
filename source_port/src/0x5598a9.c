// Unwind@005598a9: ported from Pizza Connection 2 at 0x5598a9.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5598a9
#include "pc2_port.h"

void Unwind_005598a9(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
