// Unwind@005596f7: ported from Pizza Connection 2 at 0x5596f7.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5596f7
#include "pc2_port.h"

void Unwind_005596f7(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
