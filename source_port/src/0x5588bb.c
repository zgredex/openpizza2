// Unwind@005588bb: ported from Pizza Connection 2 at 0x5588bb.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5588bb
#include "pc2_port.h"

void Unwind_005588bb(void)

{
  int unaff_EBP;
  
  Mem_Free(*(LPVOID *)(unaff_EBP + 0x10));
  return;
}
