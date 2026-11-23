// Unwind@005597bb: ported from Pizza Connection 2 at 0x5597bb.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5597bb
#include "pc2_port.h"

void Unwind_005597bb(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + -0x170));
  return;
}
